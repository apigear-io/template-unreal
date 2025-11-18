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

#include "TbEnum/Tests/TbEnumTestsCommon.h"
#include "TbEnum/Implementation/TbEnumEnumInterface.h"
#include "TbEnumEnumInterfaceJniFixture.h"
#include "TbEnum/Generated/Jni/TbEnumEnumInterfaceJniClient.h"
#include "TbEnum/Generated/Jni/TbEnumEnumInterfaceJniAdapter.h"

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbEnum
{
namespace EnumInterface
{
namespace Jni
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbEnumEnumInterfaceJniSpec, "TbEnum.EnumInterface.Jni", TbEnumTestFilterMask);

TUniquePtr<FTbEnumEnumInterfaceJniFixture> ImplFixture;

END_DEFINE_SPEC(UTbEnumEnumInterfaceJniSpec);

void UTbEnumEnumInterfaceJniSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbEnumEnumInterfaceJniFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetClient() != nullptr);

		// set up service and adapter
		auto service = ImplFixture->GetLocalImplementation();
		ImplFixture->GetAdapter()->setBackendService(service);

		// setup client
		UTbEnumEnumInterfaceJniClient* JniClient = ImplFixture->GetClient();
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
		UTbEnumEnumInterfaceJniClient* JniClient = ImplFixture->GetClient();
#endif
		ImplFixture.Reset();
	});

	It("Property.Prop0.Default", [this]()
		{
		// Do implement test here
		ETbEnumEnum0 TestValue = ETbEnumEnum0::TEE0_Value0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp0(), TestValue);
	});

	LatentIt("Property.Prop0.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum0 TestValue = ETbEnumEnum0::TEE0_Value0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp0(), TestValue);

		UTbEnumEnumInterfacePublisher* TbEnumEnumInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbEnumEnumInterfacePublisher->OnProp0Changed.AddLambda([this, TestDone](ETbEnumEnum0 InProp0)
			{
			ETbEnumEnum0 TestValue = ETbEnumEnum0::TEE0_Value0;
			// use different test value
			TestValue = ETbEnumEnum0::TEE0_Value1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp0, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp0(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = ETbEnumEnum0::TEE0_Value1;
		ImplFixture->GetClient()->SetProp0(TestValue);
#if !(PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
#endif
	});

	LatentIt("Property.Prop0.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum0 DefaultValue = ETbEnumEnum0::TEE0_Value0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp0(), DefaultValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbEnumEnumInterfacePublisher* TbEnumEnumInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbEnumEnumInterfacePublisher* TbEnumEnumInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbEnumEnumInterfacePublisher->OnProp0Changed.AddLambda([this, DefaultValue, TestDone](ETbEnumEnum0 InProp0)
			{
			ETbEnumEnum0 TestValue = ETbEnumEnum0::TEE0_Value0;
			// use different test value
			TestValue = ETbEnumEnum0::TEE0_Value1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp0, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetProp0(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp0(), TestValue);
#else
			TestEqual(TEXT("No connection, client has same value as at the start"), ImplFixture->GetClient()->GetProp0(), DefaultValue);
#endif
			TestDone.Execute();
		});
		// use different test value, but init it first.
		ETbEnumEnum0 TestValue = DefaultValue;
		TestValue = ETbEnumEnum0::TEE0_Value1;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetProp0(TestValue);
	});

	LatentIt("Property.Prop0.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum0 StartValue = ImplFixture->GetLocalImplementation()->GetProp0();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp0(), StartValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbEnumEnumInterfacePublisher* TbEnumEnumInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbEnumEnumInterfacePublisher->OnProp0Changed.AddLambda([this, TestDone](ETbEnumEnum0 InProp0)
#else
		UTbEnumEnumInterfacePublisher* TbEnumEnumInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		TbEnumEnumInterfacePublisher->OnProp0Changed.AddLambda([this, TestDone, StartValue](ETbEnumEnum0 InProp0)
#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				ETbEnumEnum0 TestValue = ETbEnumEnum0::TEE0_Value0;
				// use different test value
				TestValue = ETbEnumEnum0::TEE0_Value1;
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp0, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetProp0(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp0(), TestValue);
#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp0(), StartValue);
#endif
				// now set it to the default value
				TestValue = ETbEnumEnum0::TEE0_Value0; // default value
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetProp0(TestValue);
#else
				ImplFixture->GetLocalImplementation()->SetProp0(TestValue);
#endif
			}
			else
			{
				ETbEnumEnum0 TestValue = ETbEnumEnum0::TEE0_Value0; // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp0, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetProp0(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp0(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		ETbEnumEnum0 TestValue = StartValue;
		TestValue = ETbEnumEnum0::TEE0_Value1;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetProp0(TestValue);
	});

	It("Property.Prop1.Default", [this]()
		{
		// Do implement test here
		ETbEnumEnum1 TestValue = ETbEnumEnum1::TEE1_Value1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp1(), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum1 TestValue = ETbEnumEnum1::TEE1_Value1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp1(), TestValue);

		UTbEnumEnumInterfacePublisher* TbEnumEnumInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbEnumEnumInterfacePublisher->OnProp1Changed.AddLambda([this, TestDone](ETbEnumEnum1 InProp1)
			{
			ETbEnumEnum1 TestValue = ETbEnumEnum1::TEE1_Value1;
			// use different test value
			TestValue = ETbEnumEnum1::TEE1_Value2;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp1(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = ETbEnumEnum1::TEE1_Value2;
		ImplFixture->GetClient()->SetProp1(TestValue);
#if !(PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
#endif
	});

	LatentIt("Property.Prop1.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum1 DefaultValue = ETbEnumEnum1::TEE1_Value1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp1(), DefaultValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbEnumEnumInterfacePublisher* TbEnumEnumInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbEnumEnumInterfacePublisher* TbEnumEnumInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbEnumEnumInterfacePublisher->OnProp1Changed.AddLambda([this, DefaultValue, TestDone](ETbEnumEnum1 InProp1)
			{
			ETbEnumEnum1 TestValue = ETbEnumEnum1::TEE1_Value1;
			// use different test value
			TestValue = ETbEnumEnum1::TEE1_Value2;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetProp1(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp1(), TestValue);
#else
			TestEqual(TEXT("No connection, client has same value as at the start"), ImplFixture->GetClient()->GetProp1(), DefaultValue);
#endif
			TestDone.Execute();
		});
		// use different test value, but init it first.
		ETbEnumEnum1 TestValue = DefaultValue;
		TestValue = ETbEnumEnum1::TEE1_Value2;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetProp1(TestValue);
	});

	LatentIt("Property.Prop1.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum1 StartValue = ImplFixture->GetLocalImplementation()->GetProp1();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp1(), StartValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbEnumEnumInterfacePublisher* TbEnumEnumInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbEnumEnumInterfacePublisher->OnProp1Changed.AddLambda([this, TestDone](ETbEnumEnum1 InProp1)
#else
		UTbEnumEnumInterfacePublisher* TbEnumEnumInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		TbEnumEnumInterfacePublisher->OnProp1Changed.AddLambda([this, TestDone, StartValue](ETbEnumEnum1 InProp1)
#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				ETbEnumEnum1 TestValue = ETbEnumEnum1::TEE1_Value1;
				// use different test value
				TestValue = ETbEnumEnum1::TEE1_Value2;
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetProp1(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp1(), TestValue);
#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp1(), StartValue);
#endif
				// now set it to the default value
				TestValue = ETbEnumEnum1::TEE1_Value1; // default value
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetProp1(TestValue);
#else
				ImplFixture->GetLocalImplementation()->SetProp1(TestValue);
#endif
			}
			else
			{
				ETbEnumEnum1 TestValue = ETbEnumEnum1::TEE1_Value1; // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetProp1(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp1(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		ETbEnumEnum1 TestValue = StartValue;
		TestValue = ETbEnumEnum1::TEE1_Value2;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetProp1(TestValue);
	});

	It("Property.Prop2.Default", [this]()
		{
		// Do implement test here
		ETbEnumEnum2 TestValue = ETbEnumEnum2::TEE2_Value2; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp2(), TestValue);
	});

	LatentIt("Property.Prop2.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum2 TestValue = ETbEnumEnum2::TEE2_Value2; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp2(), TestValue);

		UTbEnumEnumInterfacePublisher* TbEnumEnumInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbEnumEnumInterfacePublisher->OnProp2Changed.AddLambda([this, TestDone](ETbEnumEnum2 InProp2)
			{
			ETbEnumEnum2 TestValue = ETbEnumEnum2::TEE2_Value2;
			// use different test value
			TestValue = ETbEnumEnum2::TEE2_Value1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp2(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = ETbEnumEnum2::TEE2_Value1;
		ImplFixture->GetClient()->SetProp2(TestValue);
#if !(PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
#endif
	});

	LatentIt("Property.Prop2.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum2 DefaultValue = ETbEnumEnum2::TEE2_Value2; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp2(), DefaultValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbEnumEnumInterfacePublisher* TbEnumEnumInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbEnumEnumInterfacePublisher* TbEnumEnumInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbEnumEnumInterfacePublisher->OnProp2Changed.AddLambda([this, DefaultValue, TestDone](ETbEnumEnum2 InProp2)
			{
			ETbEnumEnum2 TestValue = ETbEnumEnum2::TEE2_Value2;
			// use different test value
			TestValue = ETbEnumEnum2::TEE2_Value1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetProp2(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp2(), TestValue);
#else
			TestEqual(TEXT("No connection, client has same value as at the start"), ImplFixture->GetClient()->GetProp2(), DefaultValue);
#endif
			TestDone.Execute();
		});
		// use different test value, but init it first.
		ETbEnumEnum2 TestValue = DefaultValue;
		TestValue = ETbEnumEnum2::TEE2_Value1;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetProp2(TestValue);
	});

	LatentIt("Property.Prop2.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum2 StartValue = ImplFixture->GetLocalImplementation()->GetProp2();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp2(), StartValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbEnumEnumInterfacePublisher* TbEnumEnumInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbEnumEnumInterfacePublisher->OnProp2Changed.AddLambda([this, TestDone](ETbEnumEnum2 InProp2)
#else
		UTbEnumEnumInterfacePublisher* TbEnumEnumInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		TbEnumEnumInterfacePublisher->OnProp2Changed.AddLambda([this, TestDone, StartValue](ETbEnumEnum2 InProp2)
#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				ETbEnumEnum2 TestValue = ETbEnumEnum2::TEE2_Value2;
				// use different test value
				TestValue = ETbEnumEnum2::TEE2_Value1;
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetProp2(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp2(), TestValue);
#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp2(), StartValue);
#endif
				// now set it to the default value
				TestValue = ETbEnumEnum2::TEE2_Value2; // default value
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetProp2(TestValue);
#else
				ImplFixture->GetLocalImplementation()->SetProp2(TestValue);
#endif
			}
			else
			{
				ETbEnumEnum2 TestValue = ETbEnumEnum2::TEE2_Value2; // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetProp2(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp2(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		ETbEnumEnum2 TestValue = StartValue;
		TestValue = ETbEnumEnum2::TEE2_Value1;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetProp2(TestValue);
	});

	It("Property.Prop3.Default", [this]()
		{
		// Do implement test here
		ETbEnumEnum3 TestValue = ETbEnumEnum3::TEE3_Value3; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp3(), TestValue);
	});

	LatentIt("Property.Prop3.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum3 TestValue = ETbEnumEnum3::TEE3_Value3; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp3(), TestValue);

		UTbEnumEnumInterfacePublisher* TbEnumEnumInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbEnumEnumInterfacePublisher->OnProp3Changed.AddLambda([this, TestDone](ETbEnumEnum3 InProp3)
			{
			ETbEnumEnum3 TestValue = ETbEnumEnum3::TEE3_Value3;
			// use different test value
			TestValue = ETbEnumEnum3::TEE3_Value2;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp3(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = ETbEnumEnum3::TEE3_Value2;
		ImplFixture->GetClient()->SetProp3(TestValue);
#if !(PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
#endif
	});

	LatentIt("Property.Prop3.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum3 DefaultValue = ETbEnumEnum3::TEE3_Value3; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp3(), DefaultValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbEnumEnumInterfacePublisher* TbEnumEnumInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbEnumEnumInterfacePublisher* TbEnumEnumInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbEnumEnumInterfacePublisher->OnProp3Changed.AddLambda([this, DefaultValue, TestDone](ETbEnumEnum3 InProp3)
			{
			ETbEnumEnum3 TestValue = ETbEnumEnum3::TEE3_Value3;
			// use different test value
			TestValue = ETbEnumEnum3::TEE3_Value2;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetProp3(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp3(), TestValue);
#else
			TestEqual(TEXT("No connection, client has same value as at the start"), ImplFixture->GetClient()->GetProp3(), DefaultValue);
#endif
			TestDone.Execute();
		});
		// use different test value, but init it first.
		ETbEnumEnum3 TestValue = DefaultValue;
		TestValue = ETbEnumEnum3::TEE3_Value2;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetProp3(TestValue);
	});

	LatentIt("Property.Prop3.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum3 StartValue = ImplFixture->GetLocalImplementation()->GetProp3();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp3(), StartValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbEnumEnumInterfacePublisher* TbEnumEnumInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbEnumEnumInterfacePublisher->OnProp3Changed.AddLambda([this, TestDone](ETbEnumEnum3 InProp3)
#else
		UTbEnumEnumInterfacePublisher* TbEnumEnumInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		TbEnumEnumInterfacePublisher->OnProp3Changed.AddLambda([this, TestDone, StartValue](ETbEnumEnum3 InProp3)
#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				ETbEnumEnum3 TestValue = ETbEnumEnum3::TEE3_Value3;
				// use different test value
				TestValue = ETbEnumEnum3::TEE3_Value2;
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetProp3(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp3(), TestValue);
#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp3(), StartValue);
#endif
				// now set it to the default value
				TestValue = ETbEnumEnum3::TEE3_Value3; // default value
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetProp3(TestValue);
#else
				ImplFixture->GetLocalImplementation()->SetProp3(TestValue);
#endif
			}
			else
			{
				ETbEnumEnum3 TestValue = ETbEnumEnum3::TEE3_Value3; // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetProp3(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp3(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		ETbEnumEnum3 TestValue = StartValue;
		TestValue = ETbEnumEnum3::TEE3_Value2;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetProp3(TestValue);
	});

	LatentIt("Operation.Func0", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->Func0(ETbEnumEnum0::TEE0_Value0);
			// Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->Func1(ETbEnumEnum1::TEE1_Value1);
			// Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->Func2(ETbEnumEnum2::TEE2_Value2);
			// Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func3", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->Func3(ETbEnumEnum3::TEE3_Value3);
			// Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Signal.Sig0", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbEnumEnumInterfacePublisher* SourceTbEnumEnumInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbEnumEnumInterfacePublisher* TbEnumEnumInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbEnumEnumInterfacePublisher* TbEnumEnumInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbEnumEnumInterfacePublisher->OnSig0Signal.AddLambda([this, TestDone](ETbEnumEnum0 InParam0)
			{
			// known test value
			ETbEnumEnum0 Param0TestValue = ETbEnumEnum0::TEE0_Value1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam0, Param0TestValue);
			TestDone.Execute();
		});

		// use different test value
		ETbEnumEnum0 Param0TestValue = ETbEnumEnum0::TEE0_Value1;
		SourceTbEnumEnumInterfacePublisher->BroadcastSig0Signal(Param0TestValue);
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbEnumEnumInterfacePublisher* SourceTbEnumEnumInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbEnumEnumInterfacePublisher* TbEnumEnumInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbEnumEnumInterfacePublisher* TbEnumEnumInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbEnumEnumInterfacePublisher->OnSig1Signal.AddLambda([this, TestDone](ETbEnumEnum1 InParam1)
			{
			// known test value
			ETbEnumEnum1 Param1TestValue = ETbEnumEnum1::TEE1_Value2;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			TestDone.Execute();
		});

		// use different test value
		ETbEnumEnum1 Param1TestValue = ETbEnumEnum1::TEE1_Value2;
		SourceTbEnumEnumInterfacePublisher->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbEnumEnumInterfacePublisher* SourceTbEnumEnumInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbEnumEnumInterfacePublisher* TbEnumEnumInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbEnumEnumInterfacePublisher* TbEnumEnumInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbEnumEnumInterfacePublisher->OnSig2Signal.AddLambda([this, TestDone](ETbEnumEnum2 InParam2)
			{
			// known test value
			ETbEnumEnum2 Param2TestValue = ETbEnumEnum2::TEE2_Value1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
			TestDone.Execute();
		});

		// use different test value
		ETbEnumEnum2 Param2TestValue = ETbEnumEnum2::TEE2_Value1;
		SourceTbEnumEnumInterfacePublisher->BroadcastSig2Signal(Param2TestValue);
	});

	LatentIt("Signal.Sig3", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbEnumEnumInterfacePublisher* SourceTbEnumEnumInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbEnumEnumInterfacePublisher* TbEnumEnumInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbEnumEnumInterfacePublisher* TbEnumEnumInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbEnumEnumInterfacePublisher->OnSig3Signal.AddLambda([this, TestDone](ETbEnumEnum3 InParam3)
			{
			// known test value
			ETbEnumEnum3 Param3TestValue = ETbEnumEnum3::TEE3_Value2;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam3, Param3TestValue);
			TestDone.Execute();
		});

		// use different test value
		ETbEnumEnum3 Param3TestValue = ETbEnumEnum3::TEE3_Value2;
		SourceTbEnumEnumInterfacePublisher->BroadcastSig3Signal(Param3TestValue);
	});
}
} // namespace Tests
} // namespace Jni
} // namespace EnumInterface
} // namespace TbEnum

#endif // WITH_DEV_AUTOMATION_TESTS
