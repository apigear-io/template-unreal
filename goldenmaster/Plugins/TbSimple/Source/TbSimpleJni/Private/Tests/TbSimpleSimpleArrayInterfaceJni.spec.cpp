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
#include "TbSimple/Implementation/TbSimpleSimpleArrayInterface.h"
#include "TbSimpleSimpleArrayInterfaceJniFixture.h"
#include "TbSimple/Generated/Jni/TbSimpleSimpleArrayInterfaceJniClient.h"
#include "TbSimple/Generated/Jni/TbSimpleSimpleArrayInterfaceJniAdapter.h"

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
namespace SimpleArrayInterface
{
namespace Jni
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbSimpleSimpleArrayInterfaceJniSpec, "TbSimple.SimpleArrayInterface.Jni", TbSimpleTestFilterMask);

TUniquePtr<FTbSimpleSimpleArrayInterfaceJniFixture> ImplFixture;

END_DEFINE_SPEC(UTbSimpleSimpleArrayInterfaceJniSpec);

void UTbSimpleSimpleArrayInterfaceJniSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbSimpleSimpleArrayInterfaceJniFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetClient() != nullptr);

		// set up service and adapter
		auto service = ImplFixture->GetLocalImplementation();
		ImplFixture->GetAdapter()->setBackendService(service);

		// setup client
		UTbSimpleSimpleArrayInterfaceJniClient* JniClient = ImplFixture->GetClient();
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
		UTbSimpleSimpleArrayInterfaceJniClient* JniClient = ImplFixture->GetClient();
#endif
		ImplFixture.Reset();
	});

	It("Property.PropBool.Default", [this]()
		{
		// Do implement test here
		TArray<bool> TestValue = TArray<bool>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropBool(), TestValue);
	});

	LatentIt("Property.PropBool.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<bool> TestValue = TArray<bool>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropBool(), TestValue);

		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropBoolChanged.AddLambda([this, TestDone](const TArray<bool>& InPropBool)
			{
			TArray<bool> TestValue = TArray<bool>();
			// use different test value
			TestValue.Add(true);
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropBool(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue.Add(true);
		ImplFixture->GetClient()->SetPropBool(TestValue);
#if !(PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
#endif
	});

	LatentIt("Property.PropBool.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<bool> DefaultValue = TArray<bool>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropBool(), DefaultValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbSimpleSimpleArrayInterfacePublisher->OnPropBoolChanged.AddLambda([this, DefaultValue, TestDone](const TArray<bool>& InPropBool)
			{
			TArray<bool> TestValue = TArray<bool>();
			// use different test value
			TestValue.Add(true);
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropBool(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropBool(), TestValue);
#else
			TestEqual(TEXT("No connection, client has same value as at the start"), ImplFixture->GetClient()->GetPropBool(), DefaultValue);
#endif
			TestDone.Execute();
		});
		// use different test value, but init it first.
		TArray<bool> TestValue = DefaultValue;
		TestValue.Add(true);
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropBool(TestValue);
	});

	LatentIt("Property.PropBool.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<bool> StartValue = ImplFixture->GetLocalImplementation()->GetPropBool();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropBool(), StartValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropBoolChanged.AddLambda([this, TestDone](const TArray<bool>& InPropBool)
#else
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropBoolChanged.AddLambda([this, TestDone, StartValue](const TArray<bool>& InPropBool)
#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				TArray<bool> TestValue = TArray<bool>();
				// use different test value
				TestValue.Add(true);
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropBool(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropBool(), TestValue);
#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropBool(), StartValue);
#endif
				// now set it to the default value
				TestValue = TArray<bool>(); // default value
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetPropBool(TestValue);
#else
				ImplFixture->GetLocalImplementation()->SetPropBool(TestValue);
#endif
			}
			else
			{
				TArray<bool> TestValue = TArray<bool>(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropBool(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropBool(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TArray<bool> TestValue = StartValue;
		TestValue.Add(true);
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropBool(TestValue);
	});

	It("Property.PropInt.Default", [this]()
		{
		// Do implement test here
		TArray<int32> TestValue = TArray<int32>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropInt(), TestValue);
	});

	LatentIt("Property.PropInt.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<int32> TestValue = TArray<int32>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropInt(), TestValue);

		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropIntChanged.AddLambda([this, TestDone](const TArray<int32>& InPropInt)
			{
			TArray<int32> TestValue = TArray<int32>();
			// use different test value
			TestValue.Add(1);
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue.Add(1);
		ImplFixture->GetClient()->SetPropInt(TestValue);
#if !(PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
#endif
	});

	LatentIt("Property.PropInt.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<int32> DefaultValue = TArray<int32>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropInt(), DefaultValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbSimpleSimpleArrayInterfacePublisher->OnPropIntChanged.AddLambda([this, DefaultValue, TestDone](const TArray<int32>& InPropInt)
			{
			TArray<int32> TestValue = TArray<int32>();
			// use different test value
			TestValue.Add(1);
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
		TArray<int32> TestValue = DefaultValue;
		TestValue.Add(1);
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropInt(TestValue);
	});

	LatentIt("Property.PropInt.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<int32> StartValue = ImplFixture->GetLocalImplementation()->GetPropInt();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropInt(), StartValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropIntChanged.AddLambda([this, TestDone](const TArray<int32>& InPropInt)
#else
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropIntChanged.AddLambda([this, TestDone, StartValue](const TArray<int32>& InPropInt)
#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				TArray<int32> TestValue = TArray<int32>();
				// use different test value
				TestValue.Add(1);
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropInt(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt(), TestValue);
#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt(), StartValue);
#endif
				// now set it to the default value
				TestValue = TArray<int32>(); // default value
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetPropInt(TestValue);
#else
				ImplFixture->GetLocalImplementation()->SetPropInt(TestValue);
#endif
			}
			else
			{
				TArray<int32> TestValue = TArray<int32>(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropInt(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TArray<int32> TestValue = StartValue;
		TestValue.Add(1);
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropInt(TestValue);
	});

	It("Property.PropInt32.Default", [this]()
		{
		// Do implement test here
		TArray<int32> TestValue = TArray<int32>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropInt32(), TestValue);
	});

	LatentIt("Property.PropInt32.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<int32> TestValue = TArray<int32>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropInt32(), TestValue);

		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropInt32Changed.AddLambda([this, TestDone](const TArray<int32>& InPropInt32)
			{
			TArray<int32> TestValue = TArray<int32>();
			// use different test value
			TestValue.Add(1);
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt32, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt32(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue.Add(1);
		ImplFixture->GetClient()->SetPropInt32(TestValue);
#if !(PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
#endif
	});

	LatentIt("Property.PropInt32.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<int32> DefaultValue = TArray<int32>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropInt32(), DefaultValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbSimpleSimpleArrayInterfacePublisher->OnPropInt32Changed.AddLambda([this, DefaultValue, TestDone](const TArray<int32>& InPropInt32)
			{
			TArray<int32> TestValue = TArray<int32>();
			// use different test value
			TestValue.Add(1);
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
		TArray<int32> TestValue = DefaultValue;
		TestValue.Add(1);
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropInt32(TestValue);
	});

	LatentIt("Property.PropInt32.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<int32> StartValue = ImplFixture->GetLocalImplementation()->GetPropInt32();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropInt32(), StartValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropInt32Changed.AddLambda([this, TestDone](const TArray<int32>& InPropInt32)
#else
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropInt32Changed.AddLambda([this, TestDone, StartValue](const TArray<int32>& InPropInt32)
#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				TArray<int32> TestValue = TArray<int32>();
				// use different test value
				TestValue.Add(1);
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt32, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropInt32(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt32(), TestValue);
#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt32(), StartValue);
#endif
				// now set it to the default value
				TestValue = TArray<int32>(); // default value
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetPropInt32(TestValue);
#else
				ImplFixture->GetLocalImplementation()->SetPropInt32(TestValue);
#endif
			}
			else
			{
				TArray<int32> TestValue = TArray<int32>(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt32, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropInt32(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt32(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TArray<int32> TestValue = StartValue;
		TestValue.Add(1);
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropInt32(TestValue);
	});

	It("Property.PropInt64.Default", [this]()
		{
		// Do implement test here
		TArray<int64> TestValue = TArray<int64>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropInt64(), TestValue);
	});

	LatentIt("Property.PropInt64.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<int64> TestValue = TArray<int64>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropInt64(), TestValue);

		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropInt64Changed.AddLambda([this, TestDone](const TArray<int64>& InPropInt64)
			{
			TArray<int64> TestValue = TArray<int64>();
			// use different test value
			TestValue.Add(1LL);
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt64, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt64(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue.Add(1LL);
		ImplFixture->GetClient()->SetPropInt64(TestValue);
#if !(PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
#endif
	});

	LatentIt("Property.PropInt64.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<int64> DefaultValue = TArray<int64>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropInt64(), DefaultValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbSimpleSimpleArrayInterfacePublisher->OnPropInt64Changed.AddLambda([this, DefaultValue, TestDone](const TArray<int64>& InPropInt64)
			{
			TArray<int64> TestValue = TArray<int64>();
			// use different test value
			TestValue.Add(1LL);
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
		TArray<int64> TestValue = DefaultValue;
		TestValue.Add(1LL);
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropInt64(TestValue);
	});

	LatentIt("Property.PropInt64.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<int64> StartValue = ImplFixture->GetLocalImplementation()->GetPropInt64();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropInt64(), StartValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropInt64Changed.AddLambda([this, TestDone](const TArray<int64>& InPropInt64)
#else
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropInt64Changed.AddLambda([this, TestDone, StartValue](const TArray<int64>& InPropInt64)
#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				TArray<int64> TestValue = TArray<int64>();
				// use different test value
				TestValue.Add(1LL);
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt64, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropInt64(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt64(), TestValue);
#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt64(), StartValue);
#endif
				// now set it to the default value
				TestValue = TArray<int64>(); // default value
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetPropInt64(TestValue);
#else
				ImplFixture->GetLocalImplementation()->SetPropInt64(TestValue);
#endif
			}
			else
			{
				TArray<int64> TestValue = TArray<int64>(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt64, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropInt64(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt64(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TArray<int64> TestValue = StartValue;
		TestValue.Add(1LL);
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropInt64(TestValue);
	});

	It("Property.PropFloat.Default", [this]()
		{
		// Do implement test here
		TArray<float> TestValue = TArray<float>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropFloat(), TestValue);
	});

	LatentIt("Property.PropFloat.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<float> TestValue = TArray<float>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropFloat(), TestValue);

		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropFloatChanged.AddLambda([this, TestDone](const TArray<float>& InPropFloat)
			{
			TArray<float> TestValue = TArray<float>();
			// use different test value
			TestValue.Add(1.0f);
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue.Add(1.0f);
		ImplFixture->GetClient()->SetPropFloat(TestValue);
#if !(PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
#endif
	});

	LatentIt("Property.PropFloat.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<float> DefaultValue = TArray<float>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropFloat(), DefaultValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbSimpleSimpleArrayInterfacePublisher->OnPropFloatChanged.AddLambda([this, DefaultValue, TestDone](const TArray<float>& InPropFloat)
			{
			TArray<float> TestValue = TArray<float>();
			// use different test value
			TestValue.Add(1.0f);
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
		TArray<float> TestValue = DefaultValue;
		TestValue.Add(1.0f);
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropFloat(TestValue);
	});

	LatentIt("Property.PropFloat.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<float> StartValue = ImplFixture->GetLocalImplementation()->GetPropFloat();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropFloat(), StartValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropFloatChanged.AddLambda([this, TestDone](const TArray<float>& InPropFloat)
#else
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropFloatChanged.AddLambda([this, TestDone, StartValue](const TArray<float>& InPropFloat)
#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				TArray<float> TestValue = TArray<float>();
				// use different test value
				TestValue.Add(1.0f);
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropFloat(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat(), TestValue);
#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat(), StartValue);
#endif
				// now set it to the default value
				TestValue = TArray<float>(); // default value
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetPropFloat(TestValue);
#else
				ImplFixture->GetLocalImplementation()->SetPropFloat(TestValue);
#endif
			}
			else
			{
				TArray<float> TestValue = TArray<float>(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropFloat(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TArray<float> TestValue = StartValue;
		TestValue.Add(1.0f);
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropFloat(TestValue);
	});

	It("Property.PropFloat32.Default", [this]()
		{
		// Do implement test here
		TArray<float> TestValue = TArray<float>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropFloat32(), TestValue);
	});

	LatentIt("Property.PropFloat32.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<float> TestValue = TArray<float>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropFloat32(), TestValue);

		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropFloat32Changed.AddLambda([this, TestDone](const TArray<float>& InPropFloat32)
			{
			TArray<float> TestValue = TArray<float>();
			// use different test value
			TestValue.Add(1.0f);
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat32, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat32(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue.Add(1.0f);
		ImplFixture->GetClient()->SetPropFloat32(TestValue);
#if !(PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
#endif
	});

	LatentIt("Property.PropFloat32.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<float> DefaultValue = TArray<float>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropFloat32(), DefaultValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbSimpleSimpleArrayInterfacePublisher->OnPropFloat32Changed.AddLambda([this, DefaultValue, TestDone](const TArray<float>& InPropFloat32)
			{
			TArray<float> TestValue = TArray<float>();
			// use different test value
			TestValue.Add(1.0f);
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
		TArray<float> TestValue = DefaultValue;
		TestValue.Add(1.0f);
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropFloat32(TestValue);
	});

	LatentIt("Property.PropFloat32.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<float> StartValue = ImplFixture->GetLocalImplementation()->GetPropFloat32();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropFloat32(), StartValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropFloat32Changed.AddLambda([this, TestDone](const TArray<float>& InPropFloat32)
#else
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropFloat32Changed.AddLambda([this, TestDone, StartValue](const TArray<float>& InPropFloat32)
#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				TArray<float> TestValue = TArray<float>();
				// use different test value
				TestValue.Add(1.0f);
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat32, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropFloat32(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat32(), TestValue);
#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat32(), StartValue);
#endif
				// now set it to the default value
				TestValue = TArray<float>(); // default value
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetPropFloat32(TestValue);
#else
				ImplFixture->GetLocalImplementation()->SetPropFloat32(TestValue);
#endif
			}
			else
			{
				TArray<float> TestValue = TArray<float>(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat32, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropFloat32(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat32(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TArray<float> TestValue = StartValue;
		TestValue.Add(1.0f);
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropFloat32(TestValue);
	});

	It("Property.PropFloat64.Default", [this]()
		{
		// Do implement test here
		TArray<double> TestValue = TArray<double>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropFloat64(), TestValue);
	});

	LatentIt("Property.PropFloat64.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<double> TestValue = TArray<double>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropFloat64(), TestValue);

		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropFloat64Changed.AddLambda([this, TestDone](const TArray<double>& InPropFloat64)
			{
			TArray<double> TestValue = TArray<double>();
			// use different test value
			TestValue.Add(1.0);
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat64, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat64(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue.Add(1.0);
		ImplFixture->GetClient()->SetPropFloat64(TestValue);
#if !(PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
#endif
	});

	LatentIt("Property.PropFloat64.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<double> DefaultValue = TArray<double>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropFloat64(), DefaultValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbSimpleSimpleArrayInterfacePublisher->OnPropFloat64Changed.AddLambda([this, DefaultValue, TestDone](const TArray<double>& InPropFloat64)
			{
			TArray<double> TestValue = TArray<double>();
			// use different test value
			TestValue.Add(1.0);
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
		TArray<double> TestValue = DefaultValue;
		TestValue.Add(1.0);
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropFloat64(TestValue);
	});

	LatentIt("Property.PropFloat64.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<double> StartValue = ImplFixture->GetLocalImplementation()->GetPropFloat64();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropFloat64(), StartValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropFloat64Changed.AddLambda([this, TestDone](const TArray<double>& InPropFloat64)
#else
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropFloat64Changed.AddLambda([this, TestDone, StartValue](const TArray<double>& InPropFloat64)
#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				TArray<double> TestValue = TArray<double>();
				// use different test value
				TestValue.Add(1.0);
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat64, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropFloat64(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat64(), TestValue);
#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat64(), StartValue);
#endif
				// now set it to the default value
				TestValue = TArray<double>(); // default value
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetPropFloat64(TestValue);
#else
				ImplFixture->GetLocalImplementation()->SetPropFloat64(TestValue);
#endif
			}
			else
			{
				TArray<double> TestValue = TArray<double>(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat64, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropFloat64(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat64(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TArray<double> TestValue = StartValue;
		TestValue.Add(1.0);
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropFloat64(TestValue);
	});

	It("Property.PropString.Default", [this]()
		{
		// Do implement test here
		TArray<FString> TestValue = TArray<FString>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropString(), TestValue);
	});

	LatentIt("Property.PropString.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FString> TestValue = TArray<FString>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropString(), TestValue);

		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropStringChanged.AddLambda([this, TestDone](const TArray<FString>& InPropString)
			{
			TArray<FString> TestValue = TArray<FString>();
			// use different test value
			TestValue.Add(FString("xyz"));
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropString(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue.Add(FString("xyz"));
		ImplFixture->GetClient()->SetPropString(TestValue);
#if !(PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
#endif
	});

	LatentIt("Property.PropString.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FString> DefaultValue = TArray<FString>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropString(), DefaultValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbSimpleSimpleArrayInterfacePublisher->OnPropStringChanged.AddLambda([this, DefaultValue, TestDone](const TArray<FString>& InPropString)
			{
			TArray<FString> TestValue = TArray<FString>();
			// use different test value
			TestValue.Add(FString("xyz"));
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
		TArray<FString> TestValue = DefaultValue;
		TestValue.Add(FString("xyz"));
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropString(TestValue);
	});

	LatentIt("Property.PropString.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FString> StartValue = ImplFixture->GetLocalImplementation()->GetPropString();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropString(), StartValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropStringChanged.AddLambda([this, TestDone](const TArray<FString>& InPropString)
#else
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		TbSimpleSimpleArrayInterfacePublisher->OnPropStringChanged.AddLambda([this, TestDone, StartValue](const TArray<FString>& InPropString)
#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				TArray<FString> TestValue = TArray<FString>();
				// use different test value
				TestValue.Add(FString("xyz"));
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropString(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropString(), TestValue);
#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropString(), StartValue);
#endif
				// now set it to the default value
				TestValue = TArray<FString>(); // default value
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetPropString(TestValue);
#else
				ImplFixture->GetLocalImplementation()->SetPropString(TestValue);
#endif
			}
			else
			{
				TArray<FString> TestValue = TArray<FString>(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropString(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropString(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TArray<FString> TestValue = StartValue;
		TestValue.Add(FString("xyz"));
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropString(TestValue);
	});

	It("Property.PropReadOnlyString.Default", [this]()
		{
		// Do implement test here
		FString TestValue = FString(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropReadOnlyString(), FString());
	});

	LatentIt("Operation.FuncBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->FuncBool(TArray<bool>());
			// Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->FuncInt(TArray<int32>());
			// Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncInt32", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->FuncInt32(TArray<int32>());
			// Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncInt64", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->FuncInt64(TArray<int64>());
			// Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->FuncFloat(TArray<float>());
			// Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncFloat32", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->FuncFloat32(TArray<float>());
			// Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncFloat64", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->FuncFloat64(TArray<double>());
			// Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->FuncString(TArray<FString>());
			// Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Signal.SigBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleSimpleArrayInterfacePublisher* SourceTbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbSimpleSimpleArrayInterfacePublisher->OnSigBoolSignal.AddLambda([this, TestDone](const TArray<bool>& InParamBool)
			{
			// known test value
			TArray<bool> ParamBoolTestValue = TArray<bool>(); // default value
			ParamBoolTestValue.Add(true);
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamBool, ParamBoolTestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<bool> ParamBoolTestValue = TArray<bool>(); // default value
		ParamBoolTestValue.Add(true);
		SourceTbSimpleSimpleArrayInterfacePublisher->BroadcastSigBoolSignal(ParamBoolTestValue);
	});

	LatentIt("Signal.SigInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleSimpleArrayInterfacePublisher* SourceTbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbSimpleSimpleArrayInterfacePublisher->OnSigIntSignal.AddLambda([this, TestDone](const TArray<int32>& InParamInt)
			{
			// known test value
			TArray<int32> ParamIntTestValue = TArray<int32>(); // default value
			ParamIntTestValue.Add(1);
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt, ParamIntTestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<int32> ParamIntTestValue = TArray<int32>(); // default value
		ParamIntTestValue.Add(1);
		SourceTbSimpleSimpleArrayInterfacePublisher->BroadcastSigIntSignal(ParamIntTestValue);
	});

	LatentIt("Signal.SigInt32", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleSimpleArrayInterfacePublisher* SourceTbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbSimpleSimpleArrayInterfacePublisher->OnSigInt32Signal.AddLambda([this, TestDone](const TArray<int32>& InParamInt32)
			{
			// known test value
			TArray<int32> ParamInt32TestValue = TArray<int32>(); // default value
			ParamInt32TestValue.Add(1);
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt32, ParamInt32TestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<int32> ParamInt32TestValue = TArray<int32>(); // default value
		ParamInt32TestValue.Add(1);
		SourceTbSimpleSimpleArrayInterfacePublisher->BroadcastSigInt32Signal(ParamInt32TestValue);
	});

	LatentIt("Signal.SigInt64", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleSimpleArrayInterfacePublisher* SourceTbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbSimpleSimpleArrayInterfacePublisher->OnSigInt64Signal.AddLambda([this, TestDone](const TArray<int64>& InParamInt64)
			{
			// known test value
			TArray<int64> ParamInt64TestValue = TArray<int64>(); // default value
			ParamInt64TestValue.Add(1LL);
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt64, ParamInt64TestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<int64> ParamInt64TestValue = TArray<int64>(); // default value
		ParamInt64TestValue.Add(1LL);
		SourceTbSimpleSimpleArrayInterfacePublisher->BroadcastSigInt64Signal(ParamInt64TestValue);
	});

	LatentIt("Signal.SigFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleSimpleArrayInterfacePublisher* SourceTbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbSimpleSimpleArrayInterfacePublisher->OnSigFloatSignal.AddLambda([this, TestDone](const TArray<float>& InParamFloat)
			{
			// known test value
			TArray<float> ParamFloatTestValue = TArray<float>(); // default value
			ParamFloatTestValue.Add(1.0f);
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat, ParamFloatTestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<float> ParamFloatTestValue = TArray<float>(); // default value
		ParamFloatTestValue.Add(1.0f);
		SourceTbSimpleSimpleArrayInterfacePublisher->BroadcastSigFloatSignal(ParamFloatTestValue);
	});

	LatentIt("Signal.SigFloat32", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleSimpleArrayInterfacePublisher* SourceTbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbSimpleSimpleArrayInterfacePublisher->OnSigFloat32Signal.AddLambda([this, TestDone](const TArray<float>& InParamFloa32)
			{
			// known test value
			TArray<float> ParamFloa32TestValue = TArray<float>(); // default value
			ParamFloa32TestValue.Add(1.0f);
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloa32, ParamFloa32TestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<float> ParamFloa32TestValue = TArray<float>(); // default value
		ParamFloa32TestValue.Add(1.0f);
		SourceTbSimpleSimpleArrayInterfacePublisher->BroadcastSigFloat32Signal(ParamFloa32TestValue);
	});

	LatentIt("Signal.SigFloat64", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleSimpleArrayInterfacePublisher* SourceTbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbSimpleSimpleArrayInterfacePublisher->OnSigFloat64Signal.AddLambda([this, TestDone](const TArray<double>& InParamFloat64)
			{
			// known test value
			TArray<double> ParamFloat64TestValue = TArray<double>(); // default value
			ParamFloat64TestValue.Add(1.0);
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat64, ParamFloat64TestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<double> ParamFloat64TestValue = TArray<double>(); // default value
		ParamFloat64TestValue.Add(1.0);
		SourceTbSimpleSimpleArrayInterfacePublisher->BroadcastSigFloat64Signal(ParamFloat64TestValue);
	});

	LatentIt("Signal.SigString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleSimpleArrayInterfacePublisher* SourceTbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbSimpleSimpleArrayInterfacePublisher* TbSimpleSimpleArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbSimpleSimpleArrayInterfacePublisher->OnSigStringSignal.AddLambda([this, TestDone](const TArray<FString>& InParamString)
			{
			// known test value
			TArray<FString> ParamStringTestValue = TArray<FString>(); // default value
			ParamStringTestValue.Add(FString("xyz"));
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamString, ParamStringTestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<FString> ParamStringTestValue = TArray<FString>(); // default value
		ParamStringTestValue.Add(FString("xyz"));
		SourceTbSimpleSimpleArrayInterfacePublisher->BroadcastSigStringSignal(ParamStringTestValue);
	});
}
} // namespace Tests
} // namespace Jni
} // namespace SimpleArrayInterface
} // namespace TbSimple

#endif // WITH_DEV_AUTOMATION_TESTS
