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
#include "TbSimple/Implementation/TbSimpleSimpleInterface.h"
#include "TbSimpleSimpleInterfaceJniFixture.h"
#include "TbSimple/Generated/Jni/TbSimpleSimpleInterfaceJniClient.h"
#include "TbSimple/Generated/Jni/TbSimpleSimpleInterfaceJniAdapter.h"

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
namespace SimpleInterface
{
namespace Jni
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbSimpleSimpleInterfaceJniSpec, "TbSimple.SimpleInterface.Jni", TbSimpleTestFilterMask);

TUniquePtr<FTbSimpleSimpleInterfaceJniFixture> ImplFixture;

END_DEFINE_SPEC(UTbSimpleSimpleInterfaceJniSpec);

void UTbSimpleSimpleInterfaceJniSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbSimpleSimpleInterfaceJniFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetClient() != nullptr);

		// set up service and adapter
		auto service = ImplFixture->GetLocalImplementation();
		ImplFixture->GetAdapter()->setBackendService(service);

		// setup client
		UTbSimpleSimpleInterfaceJniClient* JniClient = ImplFixture->GetClient();
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
		UTbSimpleSimpleInterfaceJniClient* JniClient = ImplFixture->GetClient();
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

		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSimpleSimpleInterfacePublisher->OnPropBoolChanged.AddLambda([this, TestDone](bool bInPropBool)
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
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbSimpleSimpleInterfacePublisher->OnPropBoolChanged.AddLambda([this, DefaultValue, TestDone](bool bInPropBool)
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
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSimpleSimpleInterfacePublisher->OnPropBoolChanged.AddLambda([this, TestDone](bool bInPropBool)
#else
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		TbSimpleSimpleInterfacePublisher->OnPropBoolChanged.AddLambda([this, TestDone, StartValue](bool bInPropBool)
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

		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSimpleSimpleInterfacePublisher->OnPropIntChanged.AddLambda([this, TestDone](int32 InPropInt)
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
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbSimpleSimpleInterfacePublisher->OnPropIntChanged.AddLambda([this, DefaultValue, TestDone](int32 InPropInt)
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
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSimpleSimpleInterfacePublisher->OnPropIntChanged.AddLambda([this, TestDone](int32 InPropInt)
#else
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		TbSimpleSimpleInterfacePublisher->OnPropIntChanged.AddLambda([this, TestDone, StartValue](int32 InPropInt)
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

	It("Property.PropInt32.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropInt32(), TestValue);
	});

	LatentIt("Property.PropInt32.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropInt32(), TestValue);

		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSimpleSimpleInterfacePublisher->OnPropInt32Changed.AddLambda([this, TestDone](int32 InPropInt32)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt32, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt32(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1;
		ImplFixture->GetClient()->SetPropInt32(TestValue);
#if !(PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
#endif
	});

	LatentIt("Property.PropInt32.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 DefaultValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropInt32(), DefaultValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbSimpleSimpleInterfacePublisher->OnPropInt32Changed.AddLambda([this, DefaultValue, TestDone](int32 InPropInt32)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt32, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropInt32(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt32(), TestValue);
#else
			TestEqual(TEXT("No connection, client has same value as at the start"), ImplFixture->GetClient()->GetPropInt32(), DefaultValue);
#endif
			TestDone.Execute();
		});
		// use different test value, but init it first.
		int32 TestValue = DefaultValue;
		TestValue = 1;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropInt32(TestValue);
	});

	LatentIt("Property.PropInt32.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 StartValue = ImplFixture->GetLocalImplementation()->GetPropInt32();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropInt32(), StartValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSimpleSimpleInterfacePublisher->OnPropInt32Changed.AddLambda([this, TestDone](int32 InPropInt32)
#else
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		TbSimpleSimpleInterfacePublisher->OnPropInt32Changed.AddLambda([this, TestDone, StartValue](int32 InPropInt32)
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
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt32, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropInt32(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt32(), TestValue);
#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt32(), StartValue);
#endif
				// now set it to the default value
				TestValue = 0; // default value
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetPropInt32(TestValue);
#else
				ImplFixture->GetLocalImplementation()->SetPropInt32(TestValue);
#endif
			}
			else
			{
				int32 TestValue = 0; // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt32, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropInt32(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt32(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		int32 TestValue = StartValue;
		TestValue = 1;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropInt32(TestValue);
	});

	It("Property.PropInt64.Default", [this]()
		{
		// Do implement test here
		int64 TestValue = 0LL; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropInt64(), TestValue);
	});

	LatentIt("Property.PropInt64.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int64 TestValue = 0LL; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropInt64(), TestValue);

		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSimpleSimpleInterfacePublisher->OnPropInt64Changed.AddLambda([this, TestDone](int64 InPropInt64)
			{
			int64 TestValue = 0LL;
			// use different test value
			TestValue = 1LL;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt64, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt64(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1LL;
		ImplFixture->GetClient()->SetPropInt64(TestValue);
#if !(PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
#endif
	});

	LatentIt("Property.PropInt64.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int64 DefaultValue = 0LL; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropInt64(), DefaultValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbSimpleSimpleInterfacePublisher->OnPropInt64Changed.AddLambda([this, DefaultValue, TestDone](int64 InPropInt64)
			{
			int64 TestValue = 0LL;
			// use different test value
			TestValue = 1LL;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt64, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropInt64(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt64(), TestValue);
#else
			TestEqual(TEXT("No connection, client has same value as at the start"), ImplFixture->GetClient()->GetPropInt64(), DefaultValue);
#endif
			TestDone.Execute();
		});
		// use different test value, but init it first.
		int64 TestValue = DefaultValue;
		TestValue = 1LL;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropInt64(TestValue);
	});

	LatentIt("Property.PropInt64.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int64 StartValue = ImplFixture->GetLocalImplementation()->GetPropInt64();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropInt64(), StartValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSimpleSimpleInterfacePublisher->OnPropInt64Changed.AddLambda([this, TestDone](int64 InPropInt64)
#else
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		TbSimpleSimpleInterfacePublisher->OnPropInt64Changed.AddLambda([this, TestDone, StartValue](int64 InPropInt64)
#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				int64 TestValue = 0LL;
				// use different test value
				TestValue = 1LL;
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt64, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropInt64(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt64(), TestValue);
#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt64(), StartValue);
#endif
				// now set it to the default value
				TestValue = 0LL; // default value
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetPropInt64(TestValue);
#else
				ImplFixture->GetLocalImplementation()->SetPropInt64(TestValue);
#endif
			}
			else
			{
				int64 TestValue = 0LL; // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt64, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropInt64(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt64(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		int64 TestValue = StartValue;
		TestValue = 1LL;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropInt64(TestValue);
	});

	It("Property.PropFloat.Default", [this]()
		{
		// Do implement test here
		float TestValue = 0.0f; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropFloat(), TestValue);
	});

	LatentIt("Property.PropFloat.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		float TestValue = 0.0f; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropFloat(), TestValue);

		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSimpleSimpleInterfacePublisher->OnPropFloatChanged.AddLambda([this, TestDone](float InPropFloat)
			{
			float TestValue = 0.0f;
			// use different test value
			TestValue = 1.0f;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1.0f;
		ImplFixture->GetClient()->SetPropFloat(TestValue);
#if !(PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
#endif
	});

	LatentIt("Property.PropFloat.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		float DefaultValue = 0.0f; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropFloat(), DefaultValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbSimpleSimpleInterfacePublisher->OnPropFloatChanged.AddLambda([this, DefaultValue, TestDone](float InPropFloat)
			{
			float TestValue = 0.0f;
			// use different test value
			TestValue = 1.0f;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropFloat(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat(), TestValue);
#else
			TestEqual(TEXT("No connection, client has same value as at the start"), ImplFixture->GetClient()->GetPropFloat(), DefaultValue);
#endif
			TestDone.Execute();
		});
		// use different test value, but init it first.
		float TestValue = DefaultValue;
		TestValue = 1.0f;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropFloat(TestValue);
	});

	LatentIt("Property.PropFloat.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		float StartValue = ImplFixture->GetLocalImplementation()->GetPropFloat();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropFloat(), StartValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSimpleSimpleInterfacePublisher->OnPropFloatChanged.AddLambda([this, TestDone](float InPropFloat)
#else
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		TbSimpleSimpleInterfacePublisher->OnPropFloatChanged.AddLambda([this, TestDone, StartValue](float InPropFloat)
#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				float TestValue = 0.0f;
				// use different test value
				TestValue = 1.0f;
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropFloat(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat(), TestValue);
#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat(), StartValue);
#endif
				// now set it to the default value
				TestValue = 0.0f; // default value
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetPropFloat(TestValue);
#else
				ImplFixture->GetLocalImplementation()->SetPropFloat(TestValue);
#endif
			}
			else
			{
				float TestValue = 0.0f; // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropFloat(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		float TestValue = StartValue;
		TestValue = 1.0f;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropFloat(TestValue);
	});

	It("Property.PropFloat32.Default", [this]()
		{
		// Do implement test here
		float TestValue = 0.0f; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropFloat32(), TestValue);
	});

	LatentIt("Property.PropFloat32.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		float TestValue = 0.0f; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropFloat32(), TestValue);

		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSimpleSimpleInterfacePublisher->OnPropFloat32Changed.AddLambda([this, TestDone](float InPropFloat32)
			{
			float TestValue = 0.0f;
			// use different test value
			TestValue = 1.0f;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat32, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat32(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1.0f;
		ImplFixture->GetClient()->SetPropFloat32(TestValue);
#if !(PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
#endif
	});

	LatentIt("Property.PropFloat32.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		float DefaultValue = 0.0f; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropFloat32(), DefaultValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbSimpleSimpleInterfacePublisher->OnPropFloat32Changed.AddLambda([this, DefaultValue, TestDone](float InPropFloat32)
			{
			float TestValue = 0.0f;
			// use different test value
			TestValue = 1.0f;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat32, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropFloat32(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat32(), TestValue);
#else
			TestEqual(TEXT("No connection, client has same value as at the start"), ImplFixture->GetClient()->GetPropFloat32(), DefaultValue);
#endif
			TestDone.Execute();
		});
		// use different test value, but init it first.
		float TestValue = DefaultValue;
		TestValue = 1.0f;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropFloat32(TestValue);
	});

	LatentIt("Property.PropFloat32.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		float StartValue = ImplFixture->GetLocalImplementation()->GetPropFloat32();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropFloat32(), StartValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSimpleSimpleInterfacePublisher->OnPropFloat32Changed.AddLambda([this, TestDone](float InPropFloat32)
#else
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		TbSimpleSimpleInterfacePublisher->OnPropFloat32Changed.AddLambda([this, TestDone, StartValue](float InPropFloat32)
#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				float TestValue = 0.0f;
				// use different test value
				TestValue = 1.0f;
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat32, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropFloat32(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat32(), TestValue);
#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat32(), StartValue);
#endif
				// now set it to the default value
				TestValue = 0.0f; // default value
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetPropFloat32(TestValue);
#else
				ImplFixture->GetLocalImplementation()->SetPropFloat32(TestValue);
#endif
			}
			else
			{
				float TestValue = 0.0f; // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat32, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropFloat32(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat32(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		float TestValue = StartValue;
		TestValue = 1.0f;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropFloat32(TestValue);
	});

	It("Property.PropFloat64.Default", [this]()
		{
		// Do implement test here
		double TestValue = 0.0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropFloat64(), TestValue);
	});

	LatentIt("Property.PropFloat64.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		double TestValue = 0.0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropFloat64(), TestValue);

		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSimpleSimpleInterfacePublisher->OnPropFloat64Changed.AddLambda([this, TestDone](double InPropFloat64)
			{
			double TestValue = 0.0;
			// use different test value
			TestValue = 1.0;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat64, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat64(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1.0;
		ImplFixture->GetClient()->SetPropFloat64(TestValue);
#if !(PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
#endif
	});

	LatentIt("Property.PropFloat64.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		double DefaultValue = 0.0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropFloat64(), DefaultValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbSimpleSimpleInterfacePublisher->OnPropFloat64Changed.AddLambda([this, DefaultValue, TestDone](double InPropFloat64)
			{
			double TestValue = 0.0;
			// use different test value
			TestValue = 1.0;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat64, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropFloat64(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat64(), TestValue);
#else
			TestEqual(TEXT("No connection, client has same value as at the start"), ImplFixture->GetClient()->GetPropFloat64(), DefaultValue);
#endif
			TestDone.Execute();
		});
		// use different test value, but init it first.
		double TestValue = DefaultValue;
		TestValue = 1.0;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropFloat64(TestValue);
	});

	LatentIt("Property.PropFloat64.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		double StartValue = ImplFixture->GetLocalImplementation()->GetPropFloat64();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropFloat64(), StartValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSimpleSimpleInterfacePublisher->OnPropFloat64Changed.AddLambda([this, TestDone](double InPropFloat64)
#else
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		TbSimpleSimpleInterfacePublisher->OnPropFloat64Changed.AddLambda([this, TestDone, StartValue](double InPropFloat64)
#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				double TestValue = 0.0;
				// use different test value
				TestValue = 1.0;
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat64, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropFloat64(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat64(), TestValue);
#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat64(), StartValue);
#endif
				// now set it to the default value
				TestValue = 0.0; // default value
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetPropFloat64(TestValue);
#else
				ImplFixture->GetLocalImplementation()->SetPropFloat64(TestValue);
#endif
			}
			else
			{
				double TestValue = 0.0; // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat64, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropFloat64(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat64(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		double TestValue = StartValue;
		TestValue = 1.0;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropFloat64(TestValue);
	});

	It("Property.PropString.Default", [this]()
		{
		// Do implement test here
		FString TestValue = FString(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropString(), TestValue);
	});

	LatentIt("Property.PropString.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FString TestValue = FString(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropString(), TestValue);

		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSimpleSimpleInterfacePublisher->OnPropStringChanged.AddLambda([this, TestDone](const FString& InPropString)
			{
			FString TestValue = FString();
			// use different test value
			TestValue = FString("xyz");
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropString(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = FString("xyz");
		ImplFixture->GetClient()->SetPropString(TestValue);
#if !(PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
#endif
	});

	LatentIt("Property.PropString.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FString DefaultValue = FString(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropString(), DefaultValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbSimpleSimpleInterfacePublisher->OnPropStringChanged.AddLambda([this, DefaultValue, TestDone](const FString& InPropString)
			{
			FString TestValue = FString();
			// use different test value
			TestValue = FString("xyz");
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropString(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropString(), TestValue);
#else
			TestEqual(TEXT("No connection, client has same value as at the start"), ImplFixture->GetClient()->GetPropString(), DefaultValue);
#endif
			TestDone.Execute();
		});
		// use different test value, but init it first.
		FString TestValue = DefaultValue;
		TestValue = FString("xyz");
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropString(TestValue);
	});

	LatentIt("Property.PropString.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FString StartValue = ImplFixture->GetLocalImplementation()->GetPropString();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropString(), StartValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSimpleSimpleInterfacePublisher->OnPropStringChanged.AddLambda([this, TestDone](const FString& InPropString)
#else
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		TbSimpleSimpleInterfacePublisher->OnPropStringChanged.AddLambda([this, TestDone, StartValue](const FString& InPropString)
#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				FString TestValue = FString();
				// use different test value
				TestValue = FString("xyz");
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropString(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropString(), TestValue);
#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropString(), StartValue);
#endif
				// now set it to the default value
				TestValue = FString(); // default value
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetPropString(TestValue);
#else
				ImplFixture->GetLocalImplementation()->SetPropString(TestValue);
#endif
			}
			else
			{
				FString TestValue = FString(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropString(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropString(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		FString TestValue = StartValue;
		TestValue = FString("xyz");
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropString(TestValue);
	});

	LatentIt("Operation.FuncNoReturnValue", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->FuncNoReturnValue(false);
			// Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncNoParams", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->FuncNoParams();
			// Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->FuncBool(false);
			// Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->FuncInt(0);
			// Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncInt32", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->FuncInt32(0);
			// Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncInt64", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->FuncInt64(0LL);
			// Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->FuncFloat(0.0f);
			// Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncFloat32", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->FuncFloat32(0.0f);
			// Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncFloat64", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->FuncFloat64(0.0);
			// Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->FuncString(FString());
			// Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Signal.SigBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleSimpleInterfacePublisher* SourceTbSimpleSimpleInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbSimpleSimpleInterfacePublisher->OnSigBoolSignal.AddLambda([this, TestDone](bool bInParamBool)
			{
			// known test value
			bool bParamBoolTestValue = true;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), bInParamBool, bParamBoolTestValue);
			TestDone.Execute();
		});

		// use different test value
		bool bParamBoolTestValue = true;
		SourceTbSimpleSimpleInterfacePublisher->BroadcastSigBoolSignal(bParamBoolTestValue);
	});

	LatentIt("Signal.SigInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleSimpleInterfacePublisher* SourceTbSimpleSimpleInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbSimpleSimpleInterfacePublisher->OnSigIntSignal.AddLambda([this, TestDone](int32 InParamInt)
			{
			// known test value
			int32 ParamIntTestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt, ParamIntTestValue);
			TestDone.Execute();
		});

		// use different test value
		int32 ParamIntTestValue = 1;
		SourceTbSimpleSimpleInterfacePublisher->BroadcastSigIntSignal(ParamIntTestValue);
	});

	LatentIt("Signal.SigInt32", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleSimpleInterfacePublisher* SourceTbSimpleSimpleInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbSimpleSimpleInterfacePublisher->OnSigInt32Signal.AddLambda([this, TestDone](int32 InParamInt32)
			{
			// known test value
			int32 ParamInt32TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt32, ParamInt32TestValue);
			TestDone.Execute();
		});

		// use different test value
		int32 ParamInt32TestValue = 1;
		SourceTbSimpleSimpleInterfacePublisher->BroadcastSigInt32Signal(ParamInt32TestValue);
	});

	LatentIt("Signal.SigInt64", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleSimpleInterfacePublisher* SourceTbSimpleSimpleInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbSimpleSimpleInterfacePublisher->OnSigInt64Signal.AddLambda([this, TestDone](int64 InParamInt64)
			{
			// known test value
			int64 ParamInt64TestValue = 1LL;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt64, ParamInt64TestValue);
			TestDone.Execute();
		});

		// use different test value
		int64 ParamInt64TestValue = 1LL;
		SourceTbSimpleSimpleInterfacePublisher->BroadcastSigInt64Signal(ParamInt64TestValue);
	});

	LatentIt("Signal.SigFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleSimpleInterfacePublisher* SourceTbSimpleSimpleInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbSimpleSimpleInterfacePublisher->OnSigFloatSignal.AddLambda([this, TestDone](float InParamFloat)
			{
			// known test value
			float ParamFloatTestValue = 1.0f;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat, ParamFloatTestValue);
			TestDone.Execute();
		});

		// use different test value
		float ParamFloatTestValue = 1.0f;
		SourceTbSimpleSimpleInterfacePublisher->BroadcastSigFloatSignal(ParamFloatTestValue);
	});

	LatentIt("Signal.SigFloat32", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleSimpleInterfacePublisher* SourceTbSimpleSimpleInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbSimpleSimpleInterfacePublisher->OnSigFloat32Signal.AddLambda([this, TestDone](float InParamFloat32)
			{
			// known test value
			float ParamFloat32TestValue = 1.0f;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat32, ParamFloat32TestValue);
			TestDone.Execute();
		});

		// use different test value
		float ParamFloat32TestValue = 1.0f;
		SourceTbSimpleSimpleInterfacePublisher->BroadcastSigFloat32Signal(ParamFloat32TestValue);
	});

	LatentIt("Signal.SigFloat64", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleSimpleInterfacePublisher* SourceTbSimpleSimpleInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbSimpleSimpleInterfacePublisher->OnSigFloat64Signal.AddLambda([this, TestDone](double InParamFloat64)
			{
			// known test value
			double ParamFloat64TestValue = 1.0;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat64, ParamFloat64TestValue);
			TestDone.Execute();
		});

		// use different test value
		double ParamFloat64TestValue = 1.0;
		SourceTbSimpleSimpleInterfacePublisher->BroadcastSigFloat64Signal(ParamFloat64TestValue);
	});

	LatentIt("Signal.SigString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleSimpleInterfacePublisher* SourceTbSimpleSimpleInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbSimpleSimpleInterfacePublisher* TbSimpleSimpleInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbSimpleSimpleInterfacePublisher->OnSigStringSignal.AddLambda([this, TestDone](const FString& InParamString)
			{
			// known test value
			FString ParamStringTestValue = FString("xyz");
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamString, ParamStringTestValue);
			TestDone.Execute();
		});

		// use different test value
		FString ParamStringTestValue = FString("xyz");
		SourceTbSimpleSimpleInterfacePublisher->BroadcastSigStringSignal(ParamStringTestValue);
	});
}
} // namespace Tests
} // namespace Jni
} // namespace SimpleInterface
} // namespace TbSimple

#endif // WITH_DEV_AUTOMATION_TESTS
