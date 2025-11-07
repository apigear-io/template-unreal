/**// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT*/

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "TbIfaceimport/Tests/TbIfaceimportTestsCommon.h"
#include "TbIfaceimport/Implementation/TbIfaceimportEmptyIf.h"
#include "TbIfaceimportEmptyIfJniFixture.h"
#include "TbIfaceimport/Generated/Jni/TbIfaceimportEmptyIfJniClient.h"
#include "TbIfaceimport/Generated/Jni/TbIfaceimportEmptyIfJniAdapter.h"

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbIfaceimport
{
namespace EmptyIf
{
namespace Jni
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbIfaceimportEmptyIfJniSpec, "TbIfaceimport.EmptyIf.Jni", TbIfaceimportTestFilterMask);

TUniquePtr<FTbIfaceimportEmptyIfJniFixture> ImplFixture;

END_DEFINE_SPEC(UTbIfaceimportEmptyIfJniSpec);

void UTbIfaceimportEmptyIfJniSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbIfaceimportEmptyIfJniFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetClient() != nullptr);

		// set up service and adapter
		auto service = ImplFixture->GetLocalImplementation();
		ImplFixture->GetAdapter()->setBackendService(service);

		// setup client
		UTbIfaceimportEmptyIfJniClient* JniClient = ImplFixture->GetClient();
		TestTrue("Check for valid Jni client", JniClient != nullptr);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		JniClient->_ConnectionStatusChanged.AddLambda([this, TestDone](bool bConnected)
			{
			if (bConnected)
			{
				TestDone.Execute();
			}
		});
		// Test packge name should start with name of the  pacakge declared by the test application in e.g. defaultEngine.ini in [/Script/AndroidRuntimeSettings.AndroidRuntimeSettings] section.
		FString servicePackage = "com.goldenmaster";
		JniClient->_bindToService(servicePackage, "TestConnectionId");
#else
		TestDone.Execute();
#endif
	});

	AfterEach([this]()
		{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbIfaceimportEmptyIfJniClient* JniClient = ImplFixture->GetClient();
#endif
		ImplFixture.Reset();
	});
}
} // namespace Tests
} // namespace Jni
} // namespace EmptyIf
} // namespace TbIfaceimport

#endif // WITH_DEV_AUTOMATION_TESTS
