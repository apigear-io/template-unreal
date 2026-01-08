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

#include "Testbed1/Tests/Testbed1TestsCommon.h"
#include "Testbed1/Implementation/Testbed1StructInterface.h"
#include "Testbed1StructInterfaceJniFixture.h"
#include "Testbed1/Generated/Jni/Testbed1StructInterfaceJniClient.h"
#include "Testbed1/Generated/Jni/Testbed1StructInterfaceJniAdapter.h"

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed1
{
namespace StructInterface
{
namespace Jni
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTestbed1StructInterfaceJniSpec, "Testbed1.StructInterface.Jni", Testbed1TestFilterMask);

TUniquePtr<FTestbed1StructInterfaceJniFixture> ImplFixture;

END_DEFINE_SPEC(UTestbed1StructInterfaceJniSpec);

void UTestbed1StructInterfaceJniSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTestbed1StructInterfaceJniFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetClient() != nullptr);

		// set up service and adapter
		auto service = ImplFixture->GetLocalImplementation();
		ImplFixture->GetAdapter()->setBackendService(service);

		// setup client
		UTestbed1StructInterfaceJniClient* JniClient = ImplFixture->GetClient();
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
		UTestbed1StructInterfaceJniClient* JniClient = ImplFixture->GetClient();
#endif
		ImplFixture.Reset();
	});

	It("Property.PropBool.Default", [this]()
		{
		// Do implement test here
		FTestbed1StructBool TestValue = FTestbed1StructBool(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropBool(), TestValue);
	});

	LatentIt("Property.PropBool.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructBool TestValue = FTestbed1StructBool(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropBool(), TestValue);

		UTestbed1StructInterfacePublisher* Testbed1StructInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		Testbed1StructInterfacePublisher->OnPropBoolChanged.AddLambda([this, TestDone](const FTestbed1StructBool& InPropBool)
			{
			FTestbed1StructBool TestValue = FTestbed1StructBool();
			// use different test value
			TestValue = createTestFTestbed1StructBool();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropBool(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructBool();
		ImplFixture->GetClient()->SetPropBool(TestValue);
#if !(PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
#endif
	});

	LatentIt("Property.PropBool.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructBool DefaultValue = FTestbed1StructBool(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropBool(), DefaultValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructInterfacePublisher* Testbed1StructInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTestbed1StructInterfacePublisher* Testbed1StructInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		Testbed1StructInterfacePublisher->OnPropBoolChanged.AddLambda([this, DefaultValue, TestDone](const FTestbed1StructBool& InPropBool)
			{
			FTestbed1StructBool TestValue = FTestbed1StructBool();
			// use different test value
			TestValue = createTestFTestbed1StructBool();
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
		FTestbed1StructBool TestValue = DefaultValue;
		TestValue = createTestFTestbed1StructBool();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropBool(TestValue);
	});

	LatentIt("Property.PropBool.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructBool StartValue = ImplFixture->GetLocalImplementation()->GetPropBool();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropBool(), StartValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructInterfacePublisher* Testbed1StructInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		Testbed1StructInterfacePublisher->OnPropBoolChanged.AddLambda([this, TestDone](const FTestbed1StructBool& InPropBool)
#else
		UTestbed1StructInterfacePublisher* Testbed1StructInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		Testbed1StructInterfacePublisher->OnPropBoolChanged.AddLambda([this, TestDone, StartValue](const FTestbed1StructBool& InPropBool)
#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				FTestbed1StructBool TestValue = FTestbed1StructBool();
				// use different test value
				TestValue = createTestFTestbed1StructBool();
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropBool(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropBool(), TestValue);
#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropBool(), StartValue);
#endif
				// now set it to the default value
				TestValue = FTestbed1StructBool(); // default value
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetPropBool(TestValue);
#else
				ImplFixture->GetLocalImplementation()->SetPropBool(TestValue);
#endif
			}
			else
			{
				FTestbed1StructBool TestValue = FTestbed1StructBool(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropBool(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropBool(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		FTestbed1StructBool TestValue = StartValue;
		TestValue = createTestFTestbed1StructBool();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropBool(TestValue);
	});

	It("Property.PropInt.Default", [this]()
		{
		// Do implement test here
		FTestbed1StructInt TestValue = FTestbed1StructInt(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropInt(), TestValue);
	});

	LatentIt("Property.PropInt.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructInt TestValue = FTestbed1StructInt(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropInt(), TestValue);

		UTestbed1StructInterfacePublisher* Testbed1StructInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		Testbed1StructInterfacePublisher->OnPropIntChanged.AddLambda([this, TestDone](const FTestbed1StructInt& InPropInt)
			{
			FTestbed1StructInt TestValue = FTestbed1StructInt();
			// use different test value
			TestValue = createTestFTestbed1StructInt();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructInt();
		ImplFixture->GetClient()->SetPropInt(TestValue);
#if !(PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
#endif
	});

	LatentIt("Property.PropInt.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructInt DefaultValue = FTestbed1StructInt(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropInt(), DefaultValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructInterfacePublisher* Testbed1StructInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTestbed1StructInterfacePublisher* Testbed1StructInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		Testbed1StructInterfacePublisher->OnPropIntChanged.AddLambda([this, DefaultValue, TestDone](const FTestbed1StructInt& InPropInt)
			{
			FTestbed1StructInt TestValue = FTestbed1StructInt();
			// use different test value
			TestValue = createTestFTestbed1StructInt();
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
		FTestbed1StructInt TestValue = DefaultValue;
		TestValue = createTestFTestbed1StructInt();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropInt(TestValue);
	});

	LatentIt("Property.PropInt.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructInt StartValue = ImplFixture->GetLocalImplementation()->GetPropInt();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropInt(), StartValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructInterfacePublisher* Testbed1StructInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		Testbed1StructInterfacePublisher->OnPropIntChanged.AddLambda([this, TestDone](const FTestbed1StructInt& InPropInt)
#else
		UTestbed1StructInterfacePublisher* Testbed1StructInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		Testbed1StructInterfacePublisher->OnPropIntChanged.AddLambda([this, TestDone, StartValue](const FTestbed1StructInt& InPropInt)
#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				FTestbed1StructInt TestValue = FTestbed1StructInt();
				// use different test value
				TestValue = createTestFTestbed1StructInt();
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropInt(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt(), TestValue);
#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt(), StartValue);
#endif
				// now set it to the default value
				TestValue = FTestbed1StructInt(); // default value
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetPropInt(TestValue);
#else
				ImplFixture->GetLocalImplementation()->SetPropInt(TestValue);
#endif
			}
			else
			{
				FTestbed1StructInt TestValue = FTestbed1StructInt(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropInt(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		FTestbed1StructInt TestValue = StartValue;
		TestValue = createTestFTestbed1StructInt();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropInt(TestValue);
	});

	It("Property.PropFloat.Default", [this]()
		{
		// Do implement test here
		FTestbed1StructFloat TestValue = FTestbed1StructFloat(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropFloat(), TestValue);
	});

	LatentIt("Property.PropFloat.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructFloat TestValue = FTestbed1StructFloat(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropFloat(), TestValue);

		UTestbed1StructInterfacePublisher* Testbed1StructInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		Testbed1StructInterfacePublisher->OnPropFloatChanged.AddLambda([this, TestDone](const FTestbed1StructFloat& InPropFloat)
			{
			FTestbed1StructFloat TestValue = FTestbed1StructFloat();
			// use different test value
			TestValue = createTestFTestbed1StructFloat();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructFloat();
		ImplFixture->GetClient()->SetPropFloat(TestValue);
#if !(PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
#endif
	});

	LatentIt("Property.PropFloat.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructFloat DefaultValue = FTestbed1StructFloat(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropFloat(), DefaultValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructInterfacePublisher* Testbed1StructInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTestbed1StructInterfacePublisher* Testbed1StructInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		Testbed1StructInterfacePublisher->OnPropFloatChanged.AddLambda([this, DefaultValue, TestDone](const FTestbed1StructFloat& InPropFloat)
			{
			FTestbed1StructFloat TestValue = FTestbed1StructFloat();
			// use different test value
			TestValue = createTestFTestbed1StructFloat();
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
		FTestbed1StructFloat TestValue = DefaultValue;
		TestValue = createTestFTestbed1StructFloat();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropFloat(TestValue);
	});

	LatentIt("Property.PropFloat.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructFloat StartValue = ImplFixture->GetLocalImplementation()->GetPropFloat();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropFloat(), StartValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructInterfacePublisher* Testbed1StructInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		Testbed1StructInterfacePublisher->OnPropFloatChanged.AddLambda([this, TestDone](const FTestbed1StructFloat& InPropFloat)
#else
		UTestbed1StructInterfacePublisher* Testbed1StructInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		Testbed1StructInterfacePublisher->OnPropFloatChanged.AddLambda([this, TestDone, StartValue](const FTestbed1StructFloat& InPropFloat)
#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				FTestbed1StructFloat TestValue = FTestbed1StructFloat();
				// use different test value
				TestValue = createTestFTestbed1StructFloat();
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropFloat(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat(), TestValue);
#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat(), StartValue);
#endif
				// now set it to the default value
				TestValue = FTestbed1StructFloat(); // default value
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetPropFloat(TestValue);
#else
				ImplFixture->GetLocalImplementation()->SetPropFloat(TestValue);
#endif
			}
			else
			{
				FTestbed1StructFloat TestValue = FTestbed1StructFloat(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropFloat(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		FTestbed1StructFloat TestValue = StartValue;
		TestValue = createTestFTestbed1StructFloat();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropFloat(TestValue);
	});

	It("Property.PropString.Default", [this]()
		{
		// Do implement test here
		FTestbed1StructString TestValue = FTestbed1StructString(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropString(), TestValue);
	});

	LatentIt("Property.PropString.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructString TestValue = FTestbed1StructString(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropString(), TestValue);

		UTestbed1StructInterfacePublisher* Testbed1StructInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		Testbed1StructInterfacePublisher->OnPropStringChanged.AddLambda([this, TestDone](const FTestbed1StructString& InPropString)
			{
			FTestbed1StructString TestValue = FTestbed1StructString();
			// use different test value
			TestValue = createTestFTestbed1StructString();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropString(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructString();
		ImplFixture->GetClient()->SetPropString(TestValue);
#if !(PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
#endif
	});

	LatentIt("Property.PropString.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructString DefaultValue = FTestbed1StructString(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropString(), DefaultValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructInterfacePublisher* Testbed1StructInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTestbed1StructInterfacePublisher* Testbed1StructInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		Testbed1StructInterfacePublisher->OnPropStringChanged.AddLambda([this, DefaultValue, TestDone](const FTestbed1StructString& InPropString)
			{
			FTestbed1StructString TestValue = FTestbed1StructString();
			// use different test value
			TestValue = createTestFTestbed1StructString();
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
		FTestbed1StructString TestValue = DefaultValue;
		TestValue = createTestFTestbed1StructString();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropString(TestValue);
	});

	LatentIt("Property.PropString.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructString StartValue = ImplFixture->GetLocalImplementation()->GetPropString();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropString(), StartValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructInterfacePublisher* Testbed1StructInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		Testbed1StructInterfacePublisher->OnPropStringChanged.AddLambda([this, TestDone](const FTestbed1StructString& InPropString)
#else
		UTestbed1StructInterfacePublisher* Testbed1StructInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		Testbed1StructInterfacePublisher->OnPropStringChanged.AddLambda([this, TestDone, StartValue](const FTestbed1StructString& InPropString)
#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				FTestbed1StructString TestValue = FTestbed1StructString();
				// use different test value
				TestValue = createTestFTestbed1StructString();
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropString(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropString(), TestValue);
#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropString(), StartValue);
#endif
				// now set it to the default value
				TestValue = FTestbed1StructString(); // default value
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetPropString(TestValue);
#else
				ImplFixture->GetLocalImplementation()->SetPropString(TestValue);
#endif
			}
			else
			{
				FTestbed1StructString TestValue = FTestbed1StructString(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropString(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropString(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		FTestbed1StructString TestValue = StartValue;
		TestValue = createTestFTestbed1StructString();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropString(TestValue);
	});

	LatentIt("Operation.FuncBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->FuncBool(FTestbed1StructBool());
			// Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->FuncInt(FTestbed1StructInt());
			// Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->FuncFloat(FTestbed1StructFloat());
			// Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->FuncString(FTestbed1StructString());
			// Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Signal.SigBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructInterfacePublisher* SourceTestbed1StructInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructInterfacePublisher* Testbed1StructInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTestbed1StructInterfacePublisher* Testbed1StructInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		Testbed1StructInterfacePublisher->OnSigBoolSignal.AddLambda([this, TestDone](const FTestbed1StructBool& InParamBool)
			{
			// known test value
			FTestbed1StructBool ParamBoolTestValue = createTestFTestbed1StructBool();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamBool, ParamBoolTestValue);
			TestDone.Execute();
		});

		// use different test value
		FTestbed1StructBool ParamBoolTestValue = createTestFTestbed1StructBool();
		SourceTestbed1StructInterfacePublisher->BroadcastSigBoolSignal(ParamBoolTestValue);
	});

	LatentIt("Signal.SigInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructInterfacePublisher* SourceTestbed1StructInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructInterfacePublisher* Testbed1StructInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTestbed1StructInterfacePublisher* Testbed1StructInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		Testbed1StructInterfacePublisher->OnSigIntSignal.AddLambda([this, TestDone](const FTestbed1StructInt& InParamInt)
			{
			// known test value
			FTestbed1StructInt ParamIntTestValue = createTestFTestbed1StructInt();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt, ParamIntTestValue);
			TestDone.Execute();
		});

		// use different test value
		FTestbed1StructInt ParamIntTestValue = createTestFTestbed1StructInt();
		SourceTestbed1StructInterfacePublisher->BroadcastSigIntSignal(ParamIntTestValue);
	});

	LatentIt("Signal.SigFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructInterfacePublisher* SourceTestbed1StructInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructInterfacePublisher* Testbed1StructInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTestbed1StructInterfacePublisher* Testbed1StructInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		Testbed1StructInterfacePublisher->OnSigFloatSignal.AddLambda([this, TestDone](const FTestbed1StructFloat& InParamFloat)
			{
			// known test value
			FTestbed1StructFloat ParamFloatTestValue = createTestFTestbed1StructFloat();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat, ParamFloatTestValue);
			TestDone.Execute();
		});

		// use different test value
		FTestbed1StructFloat ParamFloatTestValue = createTestFTestbed1StructFloat();
		SourceTestbed1StructInterfacePublisher->BroadcastSigFloatSignal(ParamFloatTestValue);
	});

	LatentIt("Signal.SigString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructInterfacePublisher* SourceTestbed1StructInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructInterfacePublisher* Testbed1StructInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTestbed1StructInterfacePublisher* Testbed1StructInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		Testbed1StructInterfacePublisher->OnSigStringSignal.AddLambda([this, TestDone](const FTestbed1StructString& InParamString)
			{
			// known test value
			FTestbed1StructString ParamStringTestValue = createTestFTestbed1StructString();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamString, ParamStringTestValue);
			TestDone.Execute();
		});

		// use different test value
		FTestbed1StructString ParamStringTestValue = createTestFTestbed1StructString();
		SourceTestbed1StructInterfacePublisher->BroadcastSigStringSignal(ParamStringTestValue);
	});
}
} // namespace Tests
} // namespace Jni
} // namespace StructInterface
} // namespace Testbed1

#endif // WITH_DEV_AUTOMATION_TESTS
