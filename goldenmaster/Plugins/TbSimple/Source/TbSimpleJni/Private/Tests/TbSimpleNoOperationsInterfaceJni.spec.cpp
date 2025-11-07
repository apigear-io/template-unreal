/**
Copyright 2021 ApiGear UG
Copyright 2021 Epic Games, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "TbSimple/Tests/TbSimpleTestsCommon.h"
#include "TbSimple/Implementation/TbSimpleNoOperationsInterface.h"
#include "TbSimpleNoOperationsInterfaceJniFixture.h"
#include "TbSimple/Generated/Jni/TbSimpleNoOperationsInterfaceJniClient.h"
#include "TbSimple/Generated/Jni/TbSimpleNoOperationsInterfaceJniAdapter.h"

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
namespace NoOperationsInterface
{
namespace Jni
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbSimpleNoOperationsInterfaceJniSpec, "TbSimple.NoOperationsInterface.Jni", TbSimpleTestFilterMask);

TUniquePtr<FTbSimpleNoOperationsInterfaceJniFixture> ImplFixture;

END_DEFINE_SPEC(UTbSimpleNoOperationsInterfaceJniSpec);

void UTbSimpleNoOperationsInterfaceJniSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbSimpleNoOperationsInterfaceJniFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetClient() != nullptr);

		// set up service and adapter
		auto service = ImplFixture->GetLocalImplementation();
		ImplFixture->GetAdapter()->setBackendService(service);

		// setup client
		UTbSimpleNoOperationsInterfaceJniClient* JniClient = ImplFixture->GetClient();
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
		UTbSimpleNoOperationsInterfaceJniClient* JniClient = ImplFixture->GetClient();
#endif
		ImplFixture.Reset();
	});

	It("Property.PropBool.Default", [this]()
		{
		// Do implement test here
		bool TestValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropBool(), TestValue);
	});

	LatentIt("Property.PropBool.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		bool TestValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropBool(), TestValue);

		UTbSimpleNoOperationsInterfacePublisher* TbSimpleNoOperationsInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSimpleNoOperationsInterfacePublisher->OnPropBoolChanged.AddLambda([this, TestDone](bool bInPropBool)
			{
			bool TestValue = false;
			// use different test value
			TestValue = true;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInPropBool, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropBool(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = true;
		ImplFixture->GetClient()->SetPropBool(TestValue);
#if !(PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
#endif
	});

	LatentIt("Property.PropBool.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		bool DefaultValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropBool(), DefaultValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleNoOperationsInterfacePublisher* TbSimpleNoOperationsInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbSimpleNoOperationsInterfacePublisher* TbSimpleNoOperationsInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbSimpleNoOperationsInterfacePublisher->OnPropBoolChanged.AddLambda([this, DefaultValue, TestDone](bool bInPropBool)
			{
			bool TestValue = false;
			// use different test value
			TestValue = true;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInPropBool, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropBool(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropBool(), TestValue);
#else
			TestEqual(TEXT("No connection, client has same value as at the start"), ImplFixture->GetClient()->GetPropBool(), DefaultValue);
#endif
			TestDone.Execute();
		});
		// use different test value, but init it first.
		bool TestValue = DefaultValue;
		TestValue = true;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropBool(TestValue);
	});

	LatentIt("Property.PropBool.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		bool StartValue = ImplFixture->GetLocalImplementation()->GetPropBool();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropBool(), StartValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleNoOperationsInterfacePublisher* TbSimpleNoOperationsInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSimpleNoOperationsInterfacePublisher->OnPropBoolChanged.AddLambda([this, TestDone](bool bInPropBool)
#else
		UTbSimpleNoOperationsInterfacePublisher* TbSimpleNoOperationsInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		TbSimpleNoOperationsInterfacePublisher->OnPropBoolChanged.AddLambda([this, TestDone, StartValue](bool bInPropBool)
#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				bool TestValue = false;
				// use different test value
				TestValue = true;
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInPropBool, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropBool(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropBool(), TestValue);
#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropBool(), StartValue);
#endif
				// now set it to the default value
				TestValue = false; // default value
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetPropBool(TestValue);
#else
				ImplFixture->GetLocalImplementation()->SetPropBool(TestValue);
#endif
			}
			else
			{
				bool TestValue = false; // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInPropBool, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropBool(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropBool(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		bool TestValue = StartValue;
		TestValue = true;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropBool(TestValue);
	});

	It("Property.PropInt.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropInt(), TestValue);
	});

	LatentIt("Property.PropInt.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropInt(), TestValue);

		UTbSimpleNoOperationsInterfacePublisher* TbSimpleNoOperationsInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSimpleNoOperationsInterfacePublisher->OnPropIntChanged.AddLambda([this, TestDone](int32 InPropInt)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1;
		ImplFixture->GetClient()->SetPropInt(TestValue);
#if !(PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
#endif
	});

	LatentIt("Property.PropInt.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 DefaultValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropInt(), DefaultValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleNoOperationsInterfacePublisher* TbSimpleNoOperationsInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbSimpleNoOperationsInterfacePublisher* TbSimpleNoOperationsInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbSimpleNoOperationsInterfacePublisher->OnPropIntChanged.AddLambda([this, DefaultValue, TestDone](int32 InPropInt)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropInt(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt(), TestValue);
#else
			TestEqual(TEXT("No connection, client has same value as at the start"), ImplFixture->GetClient()->GetPropInt(), DefaultValue);
#endif
			TestDone.Execute();
		});
		// use different test value, but init it first.
		int32 TestValue = DefaultValue;
		TestValue = 1;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropInt(TestValue);
	});

	LatentIt("Property.PropInt.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 StartValue = ImplFixture->GetLocalImplementation()->GetPropInt();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropInt(), StartValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleNoOperationsInterfacePublisher* TbSimpleNoOperationsInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSimpleNoOperationsInterfacePublisher->OnPropIntChanged.AddLambda([this, TestDone](int32 InPropInt)
#else
		UTbSimpleNoOperationsInterfacePublisher* TbSimpleNoOperationsInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		TbSimpleNoOperationsInterfacePublisher->OnPropIntChanged.AddLambda([this, TestDone, StartValue](int32 InPropInt)
#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				int32 TestValue = 0;
				// use different test value
				TestValue = 1;
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropInt(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt(), TestValue);
#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt(), StartValue);
#endif
				// now set it to the default value
				TestValue = 0; // default value
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetPropInt(TestValue);
#else
				ImplFixture->GetLocalImplementation()->SetPropInt(TestValue);
#endif
			}
			else
			{
				int32 TestValue = 0; // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropInt(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		int32 TestValue = StartValue;
		TestValue = 1;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropInt(TestValue);
	});

	LatentIt("Signal.SigVoid", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleNoOperationsInterfacePublisher* SourceTbSimpleNoOperationsInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleNoOperationsInterfacePublisher* TbSimpleNoOperationsInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbSimpleNoOperationsInterfacePublisher* TbSimpleNoOperationsInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbSimpleNoOperationsInterfacePublisher->OnSigVoidSignal.AddLambda([this, TestDone]()
			{
			// known test value
			TestDone.Execute();
		});

		// use different test value
		SourceTbSimpleNoOperationsInterfacePublisher->BroadcastSigVoidSignal();
	});

	LatentIt("Signal.SigBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleNoOperationsInterfacePublisher* SourceTbSimpleNoOperationsInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleNoOperationsInterfacePublisher* TbSimpleNoOperationsInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbSimpleNoOperationsInterfacePublisher* TbSimpleNoOperationsInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbSimpleNoOperationsInterfacePublisher->OnSigBoolSignal.AddLambda([this, TestDone](bool bInParamBool)
			{
			// known test value
			bool bParamBoolTestValue = true;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), bInParamBool, bParamBoolTestValue);
			TestDone.Execute();
		});

		// use different test value
		bool bParamBoolTestValue = true;
		SourceTbSimpleNoOperationsInterfacePublisher->BroadcastSigBoolSignal(bParamBoolTestValue);
	});
}
} // namespace Tests
} // namespace Jni
} // namespace NoOperationsInterface
} // namespace TbSimple

#endif // WITH_DEV_AUTOMATION_TESTS
