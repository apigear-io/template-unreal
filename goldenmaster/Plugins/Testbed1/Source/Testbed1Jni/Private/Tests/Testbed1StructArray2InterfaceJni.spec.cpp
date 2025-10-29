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
#include "Testbed1/Implementation/Testbed1StructArray2Interface.h"
#include "Testbed1StructArray2InterfaceJniFixture.h"
#include "Testbed1/Generated/Jni/Testbed1StructArray2InterfaceJniClient.h"
#include "Testbed1/Generated/Jni/Testbed1StructArray2InterfaceJniAdapter.h"


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
namespace StructArray2Interface
{
namespace Jni
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTestbed1StructArray2InterfaceJniSpec, "Testbed1.StructArray2Interface.Jni", Testbed1TestFilterMask);

TUniquePtr<FTestbed1StructArray2InterfaceJniFixture> ImplFixture;

END_DEFINE_SPEC(UTestbed1StructArray2InterfaceJniSpec);

void UTestbed1StructArray2InterfaceJniSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTestbed1StructArray2InterfaceJniFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetClient() != nullptr);

		// set up service and adapter
		auto service =ImplFixture->GetLocalImplementation();
		ImplFixture->GetAdapter()->setBackendService(service);

		// setup client
		UTestbed1StructArray2InterfaceJniClient* JniClient = ImplFixture->GetClient();
		TestTrue("Check for valid Jni client", JniClient != nullptr);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		JniClient->_ConnectionStatusChanged.AddLambda([this, TestDone](bool bConnected)
			{
			if (bConnected)
			{
				TestDone.Execute();
			}
		});
		//Test packge name should start with name of the  pacakge declared by the test application in e.g. defaultEngine.ini in [/Script/AndroidRuntimeSettings.AndroidRuntimeSettings] section. 
		FString servicePackage = "com.goldenmaster";
		JniClient->_bindToService(servicePackage, "TestConnectionId");
		#else
		TestDone.Execute();
		#endif
	});

	AfterEach([this]()
		{
			#if PLATFORM_ANDROID && USE_ANDROID_JNI
			UTestbed1StructArray2InterfaceJniClient* JniClient =ImplFixture->GetClient();
			#endif
			ImplFixture.Reset();
	});

	It("Property.PropBool.Default", [this]()
		{
		// Do implement test here
		FTestbed1StructBoolWithArray TestValue = FTestbed1StructBoolWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropBool(), TestValue);
	});

	LatentIt("Property.PropBool.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructBoolWithArray TestValue = FTestbed1StructBoolWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropBool(), TestValue);

		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnPropBoolChanged.AddLambda([this, TestDone](const FTestbed1StructBoolWithArray& InPropBool)
			{
			FTestbed1StructBoolWithArray TestValue = FTestbed1StructBoolWithArray();
			// use different test value
			TestValue = createTestFTestbed1StructBoolWithArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropBool(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructBoolWithArray();
		ImplFixture->GetClient()->SetPropBool(TestValue);
		#if ! (PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
		#endif
	});

	LatentIt("Property.PropBool.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructBoolWithArray DefaultValue = FTestbed1StructBoolWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropBool(), DefaultValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		Testbed1StructArray2InterfacePublisher->OnPropBoolChanged.AddLambda([this, DefaultValue, TestDone](const FTestbed1StructBoolWithArray& InPropBool)
			{
			FTestbed1StructBoolWithArray TestValue = FTestbed1StructBoolWithArray();
			// use different test value
			TestValue = createTestFTestbed1StructBoolWithArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropBool(), TestValue);
			#if PLATFORM_ANDROID && USE_ANDROID_JNI
			//TODO CHANGE THE IMPLEMENTATION TO CLIENT this is confusing
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropBool(), TestValue);
			#else
			TestEqual(TEXT("No connection, client has same value as at the start"), ImplFixture->GetClient()->GetPropBool(), DefaultValue);
			#endif
			TestDone.Execute();
		});
		// use different test value, but init it first.
		FTestbed1StructBoolWithArray TestValue = DefaultValue;
		TestValue = createTestFTestbed1StructBoolWithArray();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropBool(TestValue);
	});

	LatentIt("Property.PropBool.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructBoolWithArray StartValue =  ImplFixture->GetLocalImplementation()->GetPropBool();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropBool(), StartValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnPropBoolChanged.AddLambda([this, TestDone](const FTestbed1StructBoolWithArray& InPropBool)
		#else
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnPropBoolChanged.AddLambda([this, TestDone, StartValue](const FTestbed1StructBoolWithArray& InPropBool)
		#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				FTestbed1StructBoolWithArray TestValue = FTestbed1StructBoolWithArray();
				// use different test value
				TestValue = createTestFTestbed1StructBoolWithArray();
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropBool(), TestValue);
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropBool(), TestValue);
				#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropBool(), StartValue);
				#endif
				// now set it to the default value
				TestValue = FTestbed1StructBoolWithArray(); // default value
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetPropBool(TestValue);
				#else
				ImplFixture->GetLocalImplementation()->SetPropBool(TestValue);
				#endif
			}
			else
			{
				FTestbed1StructBoolWithArray TestValue = FTestbed1StructBoolWithArray(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropBool(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropBool(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		FTestbed1StructBoolWithArray TestValue = StartValue;
		TestValue = createTestFTestbed1StructBoolWithArray();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropBool(TestValue);
	});

	It("Property.PropInt.Default", [this]()
		{
		// Do implement test here
		FTestbed1StructIntWithArray TestValue = FTestbed1StructIntWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropInt(), TestValue);
	});

	LatentIt("Property.PropInt.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructIntWithArray TestValue = FTestbed1StructIntWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropInt(), TestValue);

		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnPropIntChanged.AddLambda([this, TestDone](const FTestbed1StructIntWithArray& InPropInt)
			{
			FTestbed1StructIntWithArray TestValue = FTestbed1StructIntWithArray();
			// use different test value
			TestValue = createTestFTestbed1StructIntWithArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructIntWithArray();
		ImplFixture->GetClient()->SetPropInt(TestValue);
		#if ! (PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
		#endif
	});

	LatentIt("Property.PropInt.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructIntWithArray DefaultValue = FTestbed1StructIntWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropInt(), DefaultValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		Testbed1StructArray2InterfacePublisher->OnPropIntChanged.AddLambda([this, DefaultValue, TestDone](const FTestbed1StructIntWithArray& InPropInt)
			{
			FTestbed1StructIntWithArray TestValue = FTestbed1StructIntWithArray();
			// use different test value
			TestValue = createTestFTestbed1StructIntWithArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropInt(), TestValue);
			#if PLATFORM_ANDROID && USE_ANDROID_JNI
			//TODO CHANGE THE IMPLEMENTATION TO CLIENT this is confusing
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt(), TestValue);
			#else
			TestEqual(TEXT("No connection, client has same value as at the start"), ImplFixture->GetClient()->GetPropInt(), DefaultValue);
			#endif
			TestDone.Execute();
		});
		// use different test value, but init it first.
		FTestbed1StructIntWithArray TestValue = DefaultValue;
		TestValue = createTestFTestbed1StructIntWithArray();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropInt(TestValue);
	});

	LatentIt("Property.PropInt.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructIntWithArray StartValue =  ImplFixture->GetLocalImplementation()->GetPropInt();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropInt(), StartValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnPropIntChanged.AddLambda([this, TestDone](const FTestbed1StructIntWithArray& InPropInt)
		#else
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnPropIntChanged.AddLambda([this, TestDone, StartValue](const FTestbed1StructIntWithArray& InPropInt)
		#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				FTestbed1StructIntWithArray TestValue = FTestbed1StructIntWithArray();
				// use different test value
				TestValue = createTestFTestbed1StructIntWithArray();
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropInt(), TestValue);
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt(), TestValue);
				#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt(), StartValue);
				#endif
				// now set it to the default value
				TestValue = FTestbed1StructIntWithArray(); // default value
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetPropInt(TestValue);
				#else
				ImplFixture->GetLocalImplementation()->SetPropInt(TestValue);
				#endif
			}
			else
			{
				FTestbed1StructIntWithArray TestValue = FTestbed1StructIntWithArray(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropInt(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		FTestbed1StructIntWithArray TestValue = StartValue;
		TestValue = createTestFTestbed1StructIntWithArray();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropInt(TestValue);
	});

	It("Property.PropFloat.Default", [this]()
		{
		// Do implement test here
		FTestbed1StructFloatWithArray TestValue = FTestbed1StructFloatWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropFloat(), TestValue);
	});

	LatentIt("Property.PropFloat.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructFloatWithArray TestValue = FTestbed1StructFloatWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropFloat(), TestValue);

		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnPropFloatChanged.AddLambda([this, TestDone](const FTestbed1StructFloatWithArray& InPropFloat)
			{
			FTestbed1StructFloatWithArray TestValue = FTestbed1StructFloatWithArray();
			// use different test value
			TestValue = createTestFTestbed1StructFloatWithArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructFloatWithArray();
		ImplFixture->GetClient()->SetPropFloat(TestValue);
		#if ! (PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
		#endif
	});

	LatentIt("Property.PropFloat.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructFloatWithArray DefaultValue = FTestbed1StructFloatWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropFloat(), DefaultValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		Testbed1StructArray2InterfacePublisher->OnPropFloatChanged.AddLambda([this, DefaultValue, TestDone](const FTestbed1StructFloatWithArray& InPropFloat)
			{
			FTestbed1StructFloatWithArray TestValue = FTestbed1StructFloatWithArray();
			// use different test value
			TestValue = createTestFTestbed1StructFloatWithArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropFloat(), TestValue);
			#if PLATFORM_ANDROID && USE_ANDROID_JNI
			//TODO CHANGE THE IMPLEMENTATION TO CLIENT this is confusing
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat(), TestValue);
			#else
			TestEqual(TEXT("No connection, client has same value as at the start"), ImplFixture->GetClient()->GetPropFloat(), DefaultValue);
			#endif
			TestDone.Execute();
		});
		// use different test value, but init it first.
		FTestbed1StructFloatWithArray TestValue = DefaultValue;
		TestValue = createTestFTestbed1StructFloatWithArray();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropFloat(TestValue);
	});

	LatentIt("Property.PropFloat.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructFloatWithArray StartValue =  ImplFixture->GetLocalImplementation()->GetPropFloat();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropFloat(), StartValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnPropFloatChanged.AddLambda([this, TestDone](const FTestbed1StructFloatWithArray& InPropFloat)
		#else
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnPropFloatChanged.AddLambda([this, TestDone, StartValue](const FTestbed1StructFloatWithArray& InPropFloat)
		#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				FTestbed1StructFloatWithArray TestValue = FTestbed1StructFloatWithArray();
				// use different test value
				TestValue = createTestFTestbed1StructFloatWithArray();
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropFloat(), TestValue);
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat(), TestValue);
				#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat(), StartValue);
				#endif
				// now set it to the default value
				TestValue = FTestbed1StructFloatWithArray(); // default value
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetPropFloat(TestValue);
				#else
				ImplFixture->GetLocalImplementation()->SetPropFloat(TestValue);
				#endif
			}
			else
			{
				FTestbed1StructFloatWithArray TestValue = FTestbed1StructFloatWithArray(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropFloat(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		FTestbed1StructFloatWithArray TestValue = StartValue;
		TestValue = createTestFTestbed1StructFloatWithArray();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropFloat(TestValue);
	});

	It("Property.PropString.Default", [this]()
		{
		// Do implement test here
		FTestbed1StructStringWithArray TestValue = FTestbed1StructStringWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropString(), TestValue);
	});

	LatentIt("Property.PropString.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructStringWithArray TestValue = FTestbed1StructStringWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropString(), TestValue);

		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnPropStringChanged.AddLambda([this, TestDone](const FTestbed1StructStringWithArray& InPropString)
			{
			FTestbed1StructStringWithArray TestValue = FTestbed1StructStringWithArray();
			// use different test value
			TestValue = createTestFTestbed1StructStringWithArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropString(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructStringWithArray();
		ImplFixture->GetClient()->SetPropString(TestValue);
		#if ! (PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
		#endif
	});

	LatentIt("Property.PropString.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructStringWithArray DefaultValue = FTestbed1StructStringWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropString(), DefaultValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		Testbed1StructArray2InterfacePublisher->OnPropStringChanged.AddLambda([this, DefaultValue, TestDone](const FTestbed1StructStringWithArray& InPropString)
			{
			FTestbed1StructStringWithArray TestValue = FTestbed1StructStringWithArray();
			// use different test value
			TestValue = createTestFTestbed1StructStringWithArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropString(), TestValue);
			#if PLATFORM_ANDROID && USE_ANDROID_JNI
			//TODO CHANGE THE IMPLEMENTATION TO CLIENT this is confusing
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropString(), TestValue);
			#else
			TestEqual(TEXT("No connection, client has same value as at the start"), ImplFixture->GetClient()->GetPropString(), DefaultValue);
			#endif
			TestDone.Execute();
		});
		// use different test value, but init it first.
		FTestbed1StructStringWithArray TestValue = DefaultValue;
		TestValue = createTestFTestbed1StructStringWithArray();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropString(TestValue);
	});

	LatentIt("Property.PropString.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructStringWithArray StartValue =  ImplFixture->GetLocalImplementation()->GetPropString();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropString(), StartValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnPropStringChanged.AddLambda([this, TestDone](const FTestbed1StructStringWithArray& InPropString)
		#else
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnPropStringChanged.AddLambda([this, TestDone, StartValue](const FTestbed1StructStringWithArray& InPropString)
		#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				FTestbed1StructStringWithArray TestValue = FTestbed1StructStringWithArray();
				// use different test value
				TestValue = createTestFTestbed1StructStringWithArray();
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropString(), TestValue);
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropString(), TestValue);
				#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropString(), StartValue);
				#endif
				// now set it to the default value
				TestValue = FTestbed1StructStringWithArray(); // default value
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetPropString(TestValue);
				#else
				ImplFixture->GetLocalImplementation()->SetPropString(TestValue);
				#endif
			}
			else
			{
				FTestbed1StructStringWithArray TestValue = FTestbed1StructStringWithArray(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropString(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropString(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		FTestbed1StructStringWithArray TestValue = StartValue;
		TestValue = createTestFTestbed1StructStringWithArray();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropString(TestValue);
	});

	It("Property.PropEnum.Default", [this]()
		{
		// Do implement test here
		FTestbed1StructEnumWithArray TestValue = FTestbed1StructEnumWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropEnum(), TestValue);
	});

	LatentIt("Property.PropEnum.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructEnumWithArray TestValue = FTestbed1StructEnumWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropEnum(), TestValue);

		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnPropEnumChanged.AddLambda([this, TestDone](const FTestbed1StructEnumWithArray& InPropEnum)
			{
			FTestbed1StructEnumWithArray TestValue = FTestbed1StructEnumWithArray();
			// use different test value
			TestValue = createTestFTestbed1StructEnumWithArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropEnum(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructEnumWithArray();
		ImplFixture->GetClient()->SetPropEnum(TestValue);
		#if ! (PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
		#endif
	});

	LatentIt("Property.PropEnum.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructEnumWithArray DefaultValue = FTestbed1StructEnumWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropEnum(), DefaultValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		Testbed1StructArray2InterfacePublisher->OnPropEnumChanged.AddLambda([this, DefaultValue, TestDone](const FTestbed1StructEnumWithArray& InPropEnum)
			{
			FTestbed1StructEnumWithArray TestValue = FTestbed1StructEnumWithArray();
			// use different test value
			TestValue = createTestFTestbed1StructEnumWithArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropEnum(), TestValue);
			#if PLATFORM_ANDROID && USE_ANDROID_JNI
			//TODO CHANGE THE IMPLEMENTATION TO CLIENT this is confusing
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropEnum(), TestValue);
			#else
			TestEqual(TEXT("No connection, client has same value as at the start"), ImplFixture->GetClient()->GetPropEnum(), DefaultValue);
			#endif
			TestDone.Execute();
		});
		// use different test value, but init it first.
		FTestbed1StructEnumWithArray TestValue = DefaultValue;
		TestValue = createTestFTestbed1StructEnumWithArray();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropEnum(TestValue);
	});

	LatentIt("Property.PropEnum.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructEnumWithArray StartValue =  ImplFixture->GetLocalImplementation()->GetPropEnum();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropEnum(), StartValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnPropEnumChanged.AddLambda([this, TestDone](const FTestbed1StructEnumWithArray& InPropEnum)
		#else
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnPropEnumChanged.AddLambda([this, TestDone, StartValue](const FTestbed1StructEnumWithArray& InPropEnum)
		#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				FTestbed1StructEnumWithArray TestValue = FTestbed1StructEnumWithArray();
				// use different test value
				TestValue = createTestFTestbed1StructEnumWithArray();
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropEnum(), TestValue);
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropEnum(), TestValue);
				#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropEnum(), StartValue);
				#endif
				// now set it to the default value
				TestValue = FTestbed1StructEnumWithArray(); // default value
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetPropEnum(TestValue);
				#else
				ImplFixture->GetLocalImplementation()->SetPropEnum(TestValue);
				#endif
			}
			else
			{
				FTestbed1StructEnumWithArray TestValue = FTestbed1StructEnumWithArray(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropEnum(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropEnum(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		FTestbed1StructEnumWithArray TestValue = StartValue;
		TestValue = createTestFTestbed1StructEnumWithArray();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropEnum(TestValue);
	});

	LatentIt("Operation.FuncBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->FuncBool(FTestbed1StructBoolWithArray());
			//Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->FuncInt(FTestbed1StructIntWithArray());
			//Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->FuncFloat(FTestbed1StructFloatWithArray());
			//Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->FuncString(FTestbed1StructStringWithArray());
			//Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncEnum", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->FuncEnum(FTestbed1StructEnumWithArray());
			//Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Signal.SigBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{

		UTestbed1StructArray2InterfacePublisher* SourceTestbed1StructArray2InterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		Testbed1StructArray2InterfacePublisher->OnSigBoolSignal.AddLambda([this, TestDone](const FTestbed1StructBoolWithArray& InParamBool)
			{
			// known test value
			FTestbed1StructBoolWithArray ParamBoolTestValue = createTestFTestbed1StructBoolWithArray();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamBool, ParamBoolTestValue);
			TestDone.Execute();
		});

		// use different test value
		FTestbed1StructBoolWithArray ParamBoolTestValue = createTestFTestbed1StructBoolWithArray();
		SourceTestbed1StructArray2InterfacePublisher->BroadcastSigBoolSignal(ParamBoolTestValue);
	});

	LatentIt("Signal.SigInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{

		UTestbed1StructArray2InterfacePublisher* SourceTestbed1StructArray2InterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		Testbed1StructArray2InterfacePublisher->OnSigIntSignal.AddLambda([this, TestDone](const FTestbed1StructIntWithArray& InParamInt)
			{
			// known test value
			FTestbed1StructIntWithArray ParamIntTestValue = createTestFTestbed1StructIntWithArray();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt, ParamIntTestValue);
			TestDone.Execute();
		});

		// use different test value
		FTestbed1StructIntWithArray ParamIntTestValue = createTestFTestbed1StructIntWithArray();
		SourceTestbed1StructArray2InterfacePublisher->BroadcastSigIntSignal(ParamIntTestValue);
	});

	LatentIt("Signal.SigFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{

		UTestbed1StructArray2InterfacePublisher* SourceTestbed1StructArray2InterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		Testbed1StructArray2InterfacePublisher->OnSigFloatSignal.AddLambda([this, TestDone](const FTestbed1StructFloatWithArray& InParamFloat)
			{
			// known test value
			FTestbed1StructFloatWithArray ParamFloatTestValue = createTestFTestbed1StructFloatWithArray();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat, ParamFloatTestValue);
			TestDone.Execute();
		});

		// use different test value
		FTestbed1StructFloatWithArray ParamFloatTestValue = createTestFTestbed1StructFloatWithArray();
		SourceTestbed1StructArray2InterfacePublisher->BroadcastSigFloatSignal(ParamFloatTestValue);
	});

	LatentIt("Signal.SigString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{

		UTestbed1StructArray2InterfacePublisher* SourceTestbed1StructArray2InterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		Testbed1StructArray2InterfacePublisher->OnSigStringSignal.AddLambda([this, TestDone](const FTestbed1StructStringWithArray& InParamString)
			{
			// known test value
			FTestbed1StructStringWithArray ParamStringTestValue = createTestFTestbed1StructStringWithArray();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamString, ParamStringTestValue);
			TestDone.Execute();
		});

		// use different test value
		FTestbed1StructStringWithArray ParamStringTestValue = createTestFTestbed1StructStringWithArray();
		SourceTestbed1StructArray2InterfacePublisher->BroadcastSigStringSignal(ParamStringTestValue);
	});
}
} // namespace Tests
} // namespace Jni
} // namespace StructArray2Interface
} // namespace Testbed1

#endif // WITH_DEV_AUTOMATION_TESTS
