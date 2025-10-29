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
#include "Testbed1/Implementation/Testbed1StructArrayInterface.h"
#include "Testbed1StructArrayInterfaceJniFixture.h"
#include "Testbed1/Generated/Jni/Testbed1StructArrayInterfaceJniClient.h"
#include "Testbed1/Generated/Jni/Testbed1StructArrayInterfaceJniAdapter.h"


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
namespace StructArrayInterface
{
namespace Jni
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTestbed1StructArrayInterfaceJniSpec, "Testbed1.StructArrayInterface.Jni", Testbed1TestFilterMask);

TUniquePtr<FTestbed1StructArrayInterfaceJniFixture> ImplFixture;

END_DEFINE_SPEC(UTestbed1StructArrayInterfaceJniSpec);

void UTestbed1StructArrayInterfaceJniSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTestbed1StructArrayInterfaceJniFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetClient() != nullptr);

		// set up service and adapter
		auto service =ImplFixture->GetLocalImplementation();
		ImplFixture->GetAdapter()->setBackendService(service);

		// setup client
		UTestbed1StructArrayInterfaceJniClient* JniClient = ImplFixture->GetClient();
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
			UTestbed1StructArrayInterfaceJniClient* JniClient =ImplFixture->GetClient();
			#endif
			ImplFixture.Reset();
	});

	It("Property.PropBool.Default", [this]()
		{
		// Do implement test here
		TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropBool(), TestValue);
	});

	LatentIt("Property.PropBool.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropBool(), TestValue);

		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		Testbed1StructArrayInterfacePublisher->OnPropBoolChanged.AddLambda([this, TestDone](const TArray<FTestbed1StructBool>& InPropBool)
			{
			TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>();
			// use different test value
			TestValue = createTestFTestbed1StructBoolArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropBool(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructBoolArray();
		ImplFixture->GetClient()->SetPropBool(TestValue);
		#if ! (PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
		#endif
	});

	LatentIt("Property.PropBool.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructBool> DefaultValue = TArray<FTestbed1StructBool>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropBool(), DefaultValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		Testbed1StructArrayInterfacePublisher->OnPropBoolChanged.AddLambda([this, DefaultValue, TestDone](const TArray<FTestbed1StructBool>& InPropBool)
			{
			TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>();
			// use different test value
			TestValue = createTestFTestbed1StructBoolArray();
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
		TArray<FTestbed1StructBool> TestValue = DefaultValue;
		TestValue = createTestFTestbed1StructBoolArray();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropBool(TestValue);
	});

	LatentIt("Property.PropBool.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructBool> StartValue =  ImplFixture->GetLocalImplementation()->GetPropBool();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropBool(), StartValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		Testbed1StructArrayInterfacePublisher->OnPropBoolChanged.AddLambda([this, TestDone](const TArray<FTestbed1StructBool>& InPropBool)
		#else
		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		Testbed1StructArrayInterfacePublisher->OnPropBoolChanged.AddLambda([this, TestDone, StartValue](const TArray<FTestbed1StructBool>& InPropBool)
		#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>();
				// use different test value
				TestValue = createTestFTestbed1StructBoolArray();
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropBool(), TestValue);
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropBool(), TestValue);
				#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropBool(), StartValue);
				#endif
				// now set it to the default value
				TestValue = TArray<FTestbed1StructBool>(); // default value
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetPropBool(TestValue);
				#else
				ImplFixture->GetLocalImplementation()->SetPropBool(TestValue);
				#endif
			}
			else
			{
				TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropBool(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropBool(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TArray<FTestbed1StructBool> TestValue = StartValue;
		TestValue = createTestFTestbed1StructBoolArray();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropBool(TestValue);
	});

	It("Property.PropInt.Default", [this]()
		{
		// Do implement test here
		TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropInt(), TestValue);
	});

	LatentIt("Property.PropInt.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropInt(), TestValue);

		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		Testbed1StructArrayInterfacePublisher->OnPropIntChanged.AddLambda([this, TestDone](const TArray<FTestbed1StructInt>& InPropInt)
			{
			TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>();
			// use different test value
			TestValue = createTestFTestbed1StructIntArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructIntArray();
		ImplFixture->GetClient()->SetPropInt(TestValue);
		#if ! (PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
		#endif
	});

	LatentIt("Property.PropInt.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructInt> DefaultValue = TArray<FTestbed1StructInt>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropInt(), DefaultValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		Testbed1StructArrayInterfacePublisher->OnPropIntChanged.AddLambda([this, DefaultValue, TestDone](const TArray<FTestbed1StructInt>& InPropInt)
			{
			TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>();
			// use different test value
			TestValue = createTestFTestbed1StructIntArray();
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
		TArray<FTestbed1StructInt> TestValue = DefaultValue;
		TestValue = createTestFTestbed1StructIntArray();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropInt(TestValue);
	});

	LatentIt("Property.PropInt.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructInt> StartValue =  ImplFixture->GetLocalImplementation()->GetPropInt();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropInt(), StartValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		Testbed1StructArrayInterfacePublisher->OnPropIntChanged.AddLambda([this, TestDone](const TArray<FTestbed1StructInt>& InPropInt)
		#else
		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		Testbed1StructArrayInterfacePublisher->OnPropIntChanged.AddLambda([this, TestDone, StartValue](const TArray<FTestbed1StructInt>& InPropInt)
		#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>();
				// use different test value
				TestValue = createTestFTestbed1StructIntArray();
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropInt(), TestValue);
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt(), TestValue);
				#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt(), StartValue);
				#endif
				// now set it to the default value
				TestValue = TArray<FTestbed1StructInt>(); // default value
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetPropInt(TestValue);
				#else
				ImplFixture->GetLocalImplementation()->SetPropInt(TestValue);
				#endif
			}
			else
			{
				TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropInt(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropInt(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TArray<FTestbed1StructInt> TestValue = StartValue;
		TestValue = createTestFTestbed1StructIntArray();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropInt(TestValue);
	});

	It("Property.PropFloat.Default", [this]()
		{
		// Do implement test here
		TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropFloat(), TestValue);
	});

	LatentIt("Property.PropFloat.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropFloat(), TestValue);

		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		Testbed1StructArrayInterfacePublisher->OnPropFloatChanged.AddLambda([this, TestDone](const TArray<FTestbed1StructFloat>& InPropFloat)
			{
			TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>();
			// use different test value
			TestValue = createTestFTestbed1StructFloatArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructFloatArray();
		ImplFixture->GetClient()->SetPropFloat(TestValue);
		#if ! (PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
		#endif
	});

	LatentIt("Property.PropFloat.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructFloat> DefaultValue = TArray<FTestbed1StructFloat>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropFloat(), DefaultValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		Testbed1StructArrayInterfacePublisher->OnPropFloatChanged.AddLambda([this, DefaultValue, TestDone](const TArray<FTestbed1StructFloat>& InPropFloat)
			{
			TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>();
			// use different test value
			TestValue = createTestFTestbed1StructFloatArray();
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
		TArray<FTestbed1StructFloat> TestValue = DefaultValue;
		TestValue = createTestFTestbed1StructFloatArray();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropFloat(TestValue);
	});

	LatentIt("Property.PropFloat.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructFloat> StartValue =  ImplFixture->GetLocalImplementation()->GetPropFloat();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropFloat(), StartValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		Testbed1StructArrayInterfacePublisher->OnPropFloatChanged.AddLambda([this, TestDone](const TArray<FTestbed1StructFloat>& InPropFloat)
		#else
		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		Testbed1StructArrayInterfacePublisher->OnPropFloatChanged.AddLambda([this, TestDone, StartValue](const TArray<FTestbed1StructFloat>& InPropFloat)
		#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>();
				// use different test value
				TestValue = createTestFTestbed1StructFloatArray();
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropFloat(), TestValue);
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat(), TestValue);
				#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat(), StartValue);
				#endif
				// now set it to the default value
				TestValue = TArray<FTestbed1StructFloat>(); // default value
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetPropFloat(TestValue);
				#else
				ImplFixture->GetLocalImplementation()->SetPropFloat(TestValue);
				#endif
			}
			else
			{
				TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropFloat(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropFloat(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TArray<FTestbed1StructFloat> TestValue = StartValue;
		TestValue = createTestFTestbed1StructFloatArray();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropFloat(TestValue);
	});

	It("Property.PropString.Default", [this]()
		{
		// Do implement test here
		TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropString(), TestValue);
	});

	LatentIt("Property.PropString.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropString(), TestValue);

		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		Testbed1StructArrayInterfacePublisher->OnPropStringChanged.AddLambda([this, TestDone](const TArray<FTestbed1StructString>& InPropString)
			{
			TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>();
			// use different test value
			TestValue = createTestFTestbed1StructStringArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropString(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructStringArray();
		ImplFixture->GetClient()->SetPropString(TestValue);
		#if ! (PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
		#endif
	});

	LatentIt("Property.PropString.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructString> DefaultValue = TArray<FTestbed1StructString>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropString(), DefaultValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		Testbed1StructArrayInterfacePublisher->OnPropStringChanged.AddLambda([this, DefaultValue, TestDone](const TArray<FTestbed1StructString>& InPropString)
			{
			TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>();
			// use different test value
			TestValue = createTestFTestbed1StructStringArray();
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
		TArray<FTestbed1StructString> TestValue = DefaultValue;
		TestValue = createTestFTestbed1StructStringArray();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropString(TestValue);
	});

	LatentIt("Property.PropString.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructString> StartValue =  ImplFixture->GetLocalImplementation()->GetPropString();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropString(), StartValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		Testbed1StructArrayInterfacePublisher->OnPropStringChanged.AddLambda([this, TestDone](const TArray<FTestbed1StructString>& InPropString)
		#else
		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		Testbed1StructArrayInterfacePublisher->OnPropStringChanged.AddLambda([this, TestDone, StartValue](const TArray<FTestbed1StructString>& InPropString)
		#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>();
				// use different test value
				TestValue = createTestFTestbed1StructStringArray();
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropString(), TestValue);
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropString(), TestValue);
				#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropString(), StartValue);
				#endif
				// now set it to the default value
				TestValue = TArray<FTestbed1StructString>(); // default value
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetPropString(TestValue);
				#else
				ImplFixture->GetLocalImplementation()->SetPropString(TestValue);
				#endif
			}
			else
			{
				TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropString(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropString(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TArray<FTestbed1StructString> TestValue = StartValue;
		TestValue = createTestFTestbed1StructStringArray();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropString(TestValue);
	});

	It("Property.PropEnum.Default", [this]()
		{
		// Do implement test here
		TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropEnum(), TestValue);
	});

	LatentIt("Property.PropEnum.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropEnum(), TestValue);

		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		Testbed1StructArrayInterfacePublisher->OnPropEnumChanged.AddLambda([this, TestDone](const TArray<ETestbed1Enum0>& InPropEnum)
			{
			TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>();
			// use different test value
			TestValue.Add(ETestbed1Enum0::T1E0_Value1);
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropEnum(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue.Add(ETestbed1Enum0::T1E0_Value1);
		ImplFixture->GetClient()->SetPropEnum(TestValue);
		#if ! (PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
		#endif
	});

	LatentIt("Property.PropEnum.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<ETestbed1Enum0> DefaultValue = TArray<ETestbed1Enum0>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropEnum(), DefaultValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		Testbed1StructArrayInterfacePublisher->OnPropEnumChanged.AddLambda([this, DefaultValue, TestDone](const TArray<ETestbed1Enum0>& InPropEnum)
			{
			TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>();
			// use different test value
			TestValue.Add(ETestbed1Enum0::T1E0_Value1);
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
		TArray<ETestbed1Enum0> TestValue = DefaultValue;
		TestValue.Add(ETestbed1Enum0::T1E0_Value1);
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropEnum(TestValue);
	});

	LatentIt("Property.PropEnum.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<ETestbed1Enum0> StartValue =  ImplFixture->GetLocalImplementation()->GetPropEnum();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropEnum(), StartValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		Testbed1StructArrayInterfacePublisher->OnPropEnumChanged.AddLambda([this, TestDone](const TArray<ETestbed1Enum0>& InPropEnum)
		#else
		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		Testbed1StructArrayInterfacePublisher->OnPropEnumChanged.AddLambda([this, TestDone, StartValue](const TArray<ETestbed1Enum0>& InPropEnum)
		#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>();
				// use different test value
				TestValue.Add(ETestbed1Enum0::T1E0_Value1);
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropEnum(), TestValue);
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropEnum(), TestValue);
				#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropEnum(), StartValue);
				#endif
				// now set it to the default value
				TestValue = TArray<ETestbed1Enum0>(); // default value
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetPropEnum(TestValue);
				#else
				ImplFixture->GetLocalImplementation()->SetPropEnum(TestValue);
				#endif
			}
			else
			{
				TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropEnum(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropEnum(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TArray<ETestbed1Enum0> TestValue = StartValue;
		TestValue.Add(ETestbed1Enum0::T1E0_Value1);
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropEnum(TestValue);
	});

	LatentIt("Operation.FuncBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->FuncBool(TArray<FTestbed1StructBool>());
			//Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->FuncInt(TArray<FTestbed1StructInt>());
			//Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->FuncFloat(TArray<FTestbed1StructFloat>());
			//Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->FuncString(TArray<FTestbed1StructString>());
			//Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncEnum", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->FuncEnum(TArray<ETestbed1Enum0>());
			//Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Signal.SigBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{

		UTestbed1StructArrayInterfacePublisher* SourceTestbed1StructArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		Testbed1StructArrayInterfacePublisher->OnSigBoolSignal.AddLambda([this, TestDone](const TArray<FTestbed1StructBool>& InParamBool)
			{
			// known test value
			TArray<FTestbed1StructBool> ParamBoolTestValue = createTestFTestbed1StructBoolArray();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamBool, ParamBoolTestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<FTestbed1StructBool> ParamBoolTestValue = createTestFTestbed1StructBoolArray();
		SourceTestbed1StructArrayInterfacePublisher->BroadcastSigBoolSignal(ParamBoolTestValue);
	});

	LatentIt("Signal.SigInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{

		UTestbed1StructArrayInterfacePublisher* SourceTestbed1StructArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		Testbed1StructArrayInterfacePublisher->OnSigIntSignal.AddLambda([this, TestDone](const TArray<FTestbed1StructInt>& InParamInt)
			{
			// known test value
			TArray<FTestbed1StructInt> ParamIntTestValue = createTestFTestbed1StructIntArray();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt, ParamIntTestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<FTestbed1StructInt> ParamIntTestValue = createTestFTestbed1StructIntArray();
		SourceTestbed1StructArrayInterfacePublisher->BroadcastSigIntSignal(ParamIntTestValue);
	});

	LatentIt("Signal.SigFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{

		UTestbed1StructArrayInterfacePublisher* SourceTestbed1StructArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		Testbed1StructArrayInterfacePublisher->OnSigFloatSignal.AddLambda([this, TestDone](const TArray<FTestbed1StructFloat>& InParamFloat)
			{
			// known test value
			TArray<FTestbed1StructFloat> ParamFloatTestValue = createTestFTestbed1StructFloatArray();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat, ParamFloatTestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<FTestbed1StructFloat> ParamFloatTestValue = createTestFTestbed1StructFloatArray();
		SourceTestbed1StructArrayInterfacePublisher->BroadcastSigFloatSignal(ParamFloatTestValue);
	});

	LatentIt("Signal.SigString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{

		UTestbed1StructArrayInterfacePublisher* SourceTestbed1StructArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		Testbed1StructArrayInterfacePublisher->OnSigStringSignal.AddLambda([this, TestDone](const TArray<FTestbed1StructString>& InParamString)
			{
			// known test value
			TArray<FTestbed1StructString> ParamStringTestValue = createTestFTestbed1StructStringArray();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamString, ParamStringTestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<FTestbed1StructString> ParamStringTestValue = createTestFTestbed1StructStringArray();
		SourceTestbed1StructArrayInterfacePublisher->BroadcastSigStringSignal(ParamStringTestValue);
	});

	LatentIt("Signal.SigEnum", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{

		UTestbed1StructArrayInterfacePublisher* SourceTestbed1StructArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UTestbed1StructArrayInterfacePublisher* Testbed1StructArrayInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		Testbed1StructArrayInterfacePublisher->OnSigEnumSignal.AddLambda([this, TestDone](const TArray<ETestbed1Enum0>& InParamEnum)
			{
			// known test value
			TArray<ETestbed1Enum0> ParamEnumTestValue = TArray<ETestbed1Enum0>(); // default value
			ParamEnumTestValue.Add(ETestbed1Enum0::T1E0_Value1);
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamEnum, ParamEnumTestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<ETestbed1Enum0> ParamEnumTestValue = TArray<ETestbed1Enum0>(); // default value
		ParamEnumTestValue.Add(ETestbed1Enum0::T1E0_Value1);
		SourceTestbed1StructArrayInterfacePublisher->BroadcastSigEnumSignal(ParamEnumTestValue);
	});
}
} // namespace Tests
} // namespace Jni
} // namespace StructArrayInterface
} // namespace Testbed1

#endif // WITH_DEV_AUTOMATION_TESTS
