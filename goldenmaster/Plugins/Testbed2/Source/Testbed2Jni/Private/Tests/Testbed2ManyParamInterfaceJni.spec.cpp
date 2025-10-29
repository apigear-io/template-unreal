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

#include "Testbed2/Tests/Testbed2TestsCommon.h"
#include "Testbed2/Implementation/Testbed2ManyParamInterface.h"
#include "Testbed2ManyParamInterfaceJniFixture.h"
#include "Testbed2/Generated/Jni/Testbed2ManyParamInterfaceJniClient.h"
#include "Testbed2/Generated/Jni/Testbed2ManyParamInterfaceJniAdapter.h"


#if PLATFORM_ANDROID

#include "Engine/Engine.h"
 #include "Android/AndroidJNI.h"
 #include "Android/AndroidApplication.h"

 #if USE_ANDROID_JNI
 #include <jni.h>
 #endif
#endif

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed2
{
namespace ManyParamInterface
{
namespace Jni
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTestbed2ManyParamInterfaceJniSpec, "Testbed2.ManyParamInterface.Jni", Testbed2TestFilterMask);

TUniquePtr<FTestbed2ManyParamInterfaceJniFixture> ImplFixture;

END_DEFINE_SPEC(UTestbed2ManyParamInterfaceJniSpec);

void UTestbed2ManyParamInterfaceJniSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTestbed2ManyParamInterfaceJniFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetClient() != nullptr);

		// set up service and adapter
		auto service =ImplFixture->GetLocalImplementation();
		ImplFixture->GetAdapter()->setBackendService(service);

		// setup client
		UTestbed2ManyParamInterfaceJniClient* JniClient = ImplFixture->GetClient();
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
			UTestbed2ManyParamInterfaceJniClient* JniClient =ImplFixture->GetClient();
			#endif
			ImplFixture.Reset();
	});

	It("Property.Prop1.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp1(), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp1(), TestValue);

		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnProp1Changed.AddLambda([this, TestDone](int32 InProp1)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp1(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1;
		ImplFixture->GetClient()->SetProp1(TestValue);
		#if ! (PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
		#endif
	});

	LatentIt("Property.Prop1.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 DefaultValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp1(), DefaultValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		Testbed2ManyParamInterfacePublisher->OnProp1Changed.AddLambda([this, DefaultValue, TestDone](int32 InProp1)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetProp1(), TestValue);
			#if PLATFORM_ANDROID && USE_ANDROID_JNI
			//TODO CHANGE THE IMPLEMENTATION TO CLIENT this is confusing
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp1(), TestValue);
			#else
			TestEqual(TEXT("No connection, client has same value as at the start"), ImplFixture->GetClient()->GetProp1(), DefaultValue);
			#endif
			TestDone.Execute();
		});
		// use different test value, but init it first.
		int32 TestValue = DefaultValue;
		TestValue = 1;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetProp1(TestValue);
	});

	LatentIt("Property.Prop1.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 StartValue =  ImplFixture->GetLocalImplementation()->GetProp1();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp1(), StartValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnProp1Changed.AddLambda([this, TestDone](int32 InProp1)
		#else
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnProp1Changed.AddLambda([this, TestDone, StartValue](int32 InProp1)
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
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetProp1(), TestValue);
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp1(), TestValue);
				#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp1(), StartValue);
				#endif
				// now set it to the default value
				TestValue = 0; // default value
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetProp1(TestValue);
				#else
				ImplFixture->GetLocalImplementation()->SetProp1(TestValue);
				#endif
			}
			else
			{
				int32 TestValue = 0; // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetProp1(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp1(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		int32 TestValue = StartValue;
		TestValue = 1;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetProp1(TestValue);
	});

	It("Property.Prop2.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp2(), TestValue);
	});

	LatentIt("Property.Prop2.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp2(), TestValue);

		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnProp2Changed.AddLambda([this, TestDone](int32 InProp2)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp2(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1;
		ImplFixture->GetClient()->SetProp2(TestValue);
		#if ! (PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
		#endif
	});

	LatentIt("Property.Prop2.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 DefaultValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp2(), DefaultValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		Testbed2ManyParamInterfacePublisher->OnProp2Changed.AddLambda([this, DefaultValue, TestDone](int32 InProp2)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetProp2(), TestValue);
			#if PLATFORM_ANDROID && USE_ANDROID_JNI
			//TODO CHANGE THE IMPLEMENTATION TO CLIENT this is confusing
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp2(), TestValue);
			#else
			TestEqual(TEXT("No connection, client has same value as at the start"), ImplFixture->GetClient()->GetProp2(), DefaultValue);
			#endif
			TestDone.Execute();
		});
		// use different test value, but init it first.
		int32 TestValue = DefaultValue;
		TestValue = 1;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetProp2(TestValue);
	});

	LatentIt("Property.Prop2.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 StartValue =  ImplFixture->GetLocalImplementation()->GetProp2();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp2(), StartValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnProp2Changed.AddLambda([this, TestDone](int32 InProp2)
		#else
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnProp2Changed.AddLambda([this, TestDone, StartValue](int32 InProp2)
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
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetProp2(), TestValue);
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp2(), TestValue);
				#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp2(), StartValue);
				#endif
				// now set it to the default value
				TestValue = 0; // default value
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetProp2(TestValue);
				#else
				ImplFixture->GetLocalImplementation()->SetProp2(TestValue);
				#endif
			}
			else
			{
				int32 TestValue = 0; // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetProp2(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp2(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		int32 TestValue = StartValue;
		TestValue = 1;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetProp2(TestValue);
	});

	It("Property.Prop3.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp3(), TestValue);
	});

	LatentIt("Property.Prop3.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp3(), TestValue);

		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnProp3Changed.AddLambda([this, TestDone](int32 InProp3)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp3(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1;
		ImplFixture->GetClient()->SetProp3(TestValue);
		#if ! (PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
		#endif
	});

	LatentIt("Property.Prop3.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 DefaultValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp3(), DefaultValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		Testbed2ManyParamInterfacePublisher->OnProp3Changed.AddLambda([this, DefaultValue, TestDone](int32 InProp3)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetProp3(), TestValue);
			#if PLATFORM_ANDROID && USE_ANDROID_JNI
			//TODO CHANGE THE IMPLEMENTATION TO CLIENT this is confusing
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp3(), TestValue);
			#else
			TestEqual(TEXT("No connection, client has same value as at the start"), ImplFixture->GetClient()->GetProp3(), DefaultValue);
			#endif
			TestDone.Execute();
		});
		// use different test value, but init it first.
		int32 TestValue = DefaultValue;
		TestValue = 1;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetProp3(TestValue);
	});

	LatentIt("Property.Prop3.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 StartValue =  ImplFixture->GetLocalImplementation()->GetProp3();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp3(), StartValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnProp3Changed.AddLambda([this, TestDone](int32 InProp3)
		#else
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnProp3Changed.AddLambda([this, TestDone, StartValue](int32 InProp3)
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
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetProp3(), TestValue);
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp3(), TestValue);
				#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp3(), StartValue);
				#endif
				// now set it to the default value
				TestValue = 0; // default value
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetProp3(TestValue);
				#else
				ImplFixture->GetLocalImplementation()->SetProp3(TestValue);
				#endif
			}
			else
			{
				int32 TestValue = 0; // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetProp3(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp3(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		int32 TestValue = StartValue;
		TestValue = 1;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetProp3(TestValue);
	});

	It("Property.Prop4.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp4(), TestValue);
	});

	LatentIt("Property.Prop4.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp4(), TestValue);

		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnProp4Changed.AddLambda([this, TestDone](int32 InProp4)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp4, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp4(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1;
		ImplFixture->GetClient()->SetProp4(TestValue);
		#if ! (PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
		#endif
	});

	LatentIt("Property.Prop4.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 DefaultValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp4(), DefaultValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		Testbed2ManyParamInterfacePublisher->OnProp4Changed.AddLambda([this, DefaultValue, TestDone](int32 InProp4)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp4, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetProp4(), TestValue);
			#if PLATFORM_ANDROID && USE_ANDROID_JNI
			//TODO CHANGE THE IMPLEMENTATION TO CLIENT this is confusing
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp4(), TestValue);
			#else
			TestEqual(TEXT("No connection, client has same value as at the start"), ImplFixture->GetClient()->GetProp4(), DefaultValue);
			#endif
			TestDone.Execute();
		});
		// use different test value, but init it first.
		int32 TestValue = DefaultValue;
		TestValue = 1;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetProp4(TestValue);
	});

	LatentIt("Property.Prop4.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 StartValue =  ImplFixture->GetLocalImplementation()->GetProp4();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp4(), StartValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnProp4Changed.AddLambda([this, TestDone](int32 InProp4)
		#else
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnProp4Changed.AddLambda([this, TestDone, StartValue](int32 InProp4)
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
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp4, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetProp4(), TestValue);
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp4(), TestValue);
				#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp4(), StartValue);
				#endif
				// now set it to the default value
				TestValue = 0; // default value
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetProp4(TestValue);
				#else
				ImplFixture->GetLocalImplementation()->SetProp4(TestValue);
				#endif
			}
			else
			{
				int32 TestValue = 0; // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp4, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetProp4(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp4(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		int32 TestValue = StartValue;
		TestValue = 1;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetProp4(TestValue);
	});

	LatentIt("Operation.Func1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->Func1(0);
			//Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->Func2(0, 0);
			//Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func3", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->Func3(0, 0, 0);
			//Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func4", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->Func4(0, 0, 0, 0);
			//Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{

		UTestbed2ManyParamInterfacePublisher* SourceTestbed2ManyParamInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		Testbed2ManyParamInterfacePublisher->OnSig1Signal.AddLambda([this, TestDone](int32 InParam1)
			{
			// known test value
			int32 Param1TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			TestDone.Execute();
		});

		// use different test value
		int32 Param1TestValue = 1;
		SourceTestbed2ManyParamInterfacePublisher->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{

		UTestbed2ManyParamInterfacePublisher* SourceTestbed2ManyParamInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		Testbed2ManyParamInterfacePublisher->OnSig2Signal.AddLambda([this, TestDone](int32 InParam1, int32 InParam2)
			{
			// known test value
			int32 Param1TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			int32 Param2TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
			TestDone.Execute();
		});

		// use different test value
		int32 Param1TestValue = 1;
		int32 Param2TestValue = 1;
		SourceTestbed2ManyParamInterfacePublisher->BroadcastSig2Signal(Param1TestValue, Param2TestValue);
	});

	LatentIt("Signal.Sig3", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{

		UTestbed2ManyParamInterfacePublisher* SourceTestbed2ManyParamInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		Testbed2ManyParamInterfacePublisher->OnSig3Signal.AddLambda([this, TestDone](int32 InParam1, int32 InParam2, int32 InParam3)
			{
			// known test value
			int32 Param1TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			int32 Param2TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
			int32 Param3TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam3, Param3TestValue);
			TestDone.Execute();
		});

		// use different test value
		int32 Param1TestValue = 1;
		int32 Param2TestValue = 1;
		int32 Param3TestValue = 1;
		SourceTestbed2ManyParamInterfacePublisher->BroadcastSig3Signal(Param1TestValue, Param2TestValue, Param3TestValue);
	});

	LatentIt("Signal.Sig4", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{

		UTestbed2ManyParamInterfacePublisher* SourceTestbed2ManyParamInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		Testbed2ManyParamInterfacePublisher->OnSig4Signal.AddLambda([this, TestDone](int32 InParam1, int32 InParam2, int32 InParam3, int32 InParam4)
			{
			// known test value
			int32 Param1TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			int32 Param2TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
			int32 Param3TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam3, Param3TestValue);
			int32 Param4TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam4, Param4TestValue);
			TestDone.Execute();
		});

		// use different test value
		int32 Param1TestValue = 1;
		int32 Param2TestValue = 1;
		int32 Param3TestValue = 1;
		int32 Param4TestValue = 1;
		SourceTestbed2ManyParamInterfacePublisher->BroadcastSig4Signal(Param1TestValue, Param2TestValue, Param3TestValue, Param4TestValue);
	});
}
} // namespace Tests
} // namespace Jni
} // namespace ManyParamInterface
} // namespace Testbed2

#endif // WITH_DEV_AUTOMATION_TESTS
