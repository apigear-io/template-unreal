// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "TbSimple/Tests/TbSimpleTestsCommon.h"
#include "TbSimple/Implementation/TbSimpleEmptyInterface.h"
#include "TbSimpleEmptyInterfaceJniFixture.h"
#include "TbSimple/Generated/Jni/TbSimpleEmptyInterfaceJniClient.h"
#include "TbSimple/Generated/Jni/TbSimpleEmptyInterfaceJniAdapter.h"

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace EmptyInterface
{
namespace Jni
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbSimpleEmptyInterfaceJniSpec, "TbSimple.EmptyInterface.Jni", TbSimpleTestFilterMask);

TUniquePtr<FTbSimpleEmptyInterfaceJniFixture> ImplFixture;

END_DEFINE_SPEC(UTbSimpleEmptyInterfaceJniSpec);

void UTbSimpleEmptyInterfaceJniSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbSimpleEmptyInterfaceJniFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetClient() != nullptr);

		// set up service and adapter
		auto service = ImplFixture->GetLocalImplementation();
		ImplFixture->GetAdapter()->setBackendService(service);

		// setup client
		UTbSimpleEmptyInterfaceJniClient* JniClient = ImplFixture->GetClient();
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
		UTbSimpleEmptyInterfaceJniClient* JniClient = ImplFixture->GetClient();
#endif
		ImplFixture.Reset();
	});
}
} // namespace Tests
} // namespace Jni
} // namespace EmptyInterface
} // namespace TbSimple

#endif // WITH_DEV_AUTOMATION_TESTS
