// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "TbSimple/Tests/TbSimpleTestsCommon.h"
#include "TbSimple/Implementation/TbSimpleVoidInterface.h"
#include "TbSimpleVoidInterfaceJniFixture.h"
#include "TbSimple/Generated/Jni/TbSimpleVoidInterfaceJniClient.h"
#include "TbSimple/Generated/Jni/TbSimpleVoidInterfaceJniAdapter.h"

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
namespace VoidInterface
{
namespace Jni
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbSimpleVoidInterfaceJniSpec, "TbSimple.VoidInterface.Jni", TbSimpleTestFilterMask);

TUniquePtr<FTbSimpleVoidInterfaceJniFixture> ImplFixture;

END_DEFINE_SPEC(UTbSimpleVoidInterfaceJniSpec);

void UTbSimpleVoidInterfaceJniSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbSimpleVoidInterfaceJniFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetClient() != nullptr);

		// set up service and adapter
		auto service = ImplFixture->GetLocalImplementation();
		ImplFixture->GetAdapter()->setBackendService(service);

		// setup client
		UTbSimpleVoidInterfaceJniClient* JniClient = ImplFixture->GetClient();
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
		UTbSimpleVoidInterfaceJniClient* JniClient = ImplFixture->GetClient();
#endif
		ImplFixture.Reset();
	});

	LatentIt("Operation.FuncVoid", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->FuncVoid();
			// Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Signal.SigVoid", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleVoidInterfacePublisher* SourceTbSimpleVoidInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleVoidInterfacePublisher* TbSimpleVoidInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbSimpleVoidInterfacePublisher* TbSimpleVoidInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbSimpleVoidInterfacePublisher->OnSigVoidSignal.AddLambda([this, TestDone]()
			{
			// known test value
			TestDone.Execute();
		});

		// use different test value
		SourceTbSimpleVoidInterfacePublisher->BroadcastSigVoidSignal();
	});
}
} // namespace Tests
} // namespace Jni
} // namespace VoidInterface
} // namespace TbSimple

#endif // WITH_DEV_AUTOMATION_TESTS
