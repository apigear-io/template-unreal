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

#include "TbSame2/Tests/TbSame2TestsCommon.h"
#include "TbSame2/Implementation/TbSame2SameEnum2Interface.h"
#include "TbSame2SameEnum2InterfaceJniFixture.h"
#include "TbSame2/Generated/Jni/TbSame2SameEnum2InterfaceJniClient.h"
#include "TbSame2/Generated/Jni/TbSame2SameEnum2InterfaceJniAdapter.h"


#if PLATFORM_ANDROID

#include "Engine/Engine.h"
 #include "Android/AndroidJNI.h"
 #include "Android/AndroidApplication.h"

 #if USE_ANDROID_JNI
 #include <jni.h>
 #endif
#endif

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame2
{
namespace SameEnum2Interface
{
namespace Jni
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbSame2SameEnum2InterfaceJniSpec, "TbSame2.SameEnum2Interface.Jni", TbSame2TestFilterMask);

TUniquePtr<FTbSame2SameEnum2InterfaceJniFixture> ImplFixture;

END_DEFINE_SPEC(UTbSame2SameEnum2InterfaceJniSpec);

void UTbSame2SameEnum2InterfaceJniSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbSame2SameEnum2InterfaceJniFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetClient() != nullptr);

		// set up service and adapter
		auto service =ImplFixture->GetLocalImplementation();
		ImplFixture->GetAdapter()->setBackendService(service);

		// setup client
		UTbSame2SameEnum2InterfaceJniClient* JniClient = ImplFixture->GetClient();
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
			UTbSame2SameEnum2InterfaceJniClient* JniClient =ImplFixture->GetClient();
			#endif
			ImplFixture.Reset();
	});

	It("Property.Prop1.Default", [this]()
		{
		// Do implement test here
		ETbSame2Enum1 TestValue = ETbSame2Enum1::TS2E1_Value1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp1(), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbSame2Enum1 TestValue = ETbSame2Enum1::TS2E1_Value1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp1(), TestValue);

		UTbSame2SameEnum2InterfacePublisher* TbSame2SameEnum2InterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSame2SameEnum2InterfacePublisher->OnProp1Changed.AddLambda([this, TestDone](ETbSame2Enum1 InProp1)
			{
			ETbSame2Enum1 TestValue = ETbSame2Enum1::TS2E1_Value1;
			// use different test value
			TestValue = ETbSame2Enum1::TS2E1_Value2;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp1(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = ETbSame2Enum1::TS2E1_Value2;
		ImplFixture->GetClient()->SetProp1(TestValue);
		#if ! (PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
		#endif
	});

	LatentIt("Property.Prop1.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbSame2Enum1 DefaultValue = ETbSame2Enum1::TS2E1_Value1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp1(), DefaultValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSame2SameEnum2InterfacePublisher* TbSame2SameEnum2InterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UTbSame2SameEnum2InterfacePublisher* TbSame2SameEnum2InterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		TbSame2SameEnum2InterfacePublisher->OnProp1Changed.AddLambda([this, DefaultValue, TestDone](ETbSame2Enum1 InProp1)
			{
			ETbSame2Enum1 TestValue = ETbSame2Enum1::TS2E1_Value1;
			// use different test value
			TestValue = ETbSame2Enum1::TS2E1_Value2;
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
		ETbSame2Enum1 TestValue = DefaultValue;
		TestValue = ETbSame2Enum1::TS2E1_Value2;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetProp1(TestValue);
	});

	LatentIt("Property.Prop1.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbSame2Enum1 StartValue =  ImplFixture->GetLocalImplementation()->GetProp1();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp1(), StartValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSame2SameEnum2InterfacePublisher* TbSame2SameEnum2InterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSame2SameEnum2InterfacePublisher->OnProp1Changed.AddLambda([this, TestDone](ETbSame2Enum1 InProp1)
		#else
		UTbSame2SameEnum2InterfacePublisher* TbSame2SameEnum2InterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		TbSame2SameEnum2InterfacePublisher->OnProp1Changed.AddLambda([this, TestDone, StartValue](ETbSame2Enum1 InProp1)
		#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				ETbSame2Enum1 TestValue = ETbSame2Enum1::TS2E1_Value1;
				// use different test value
				TestValue = ETbSame2Enum1::TS2E1_Value2;
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetProp1(), TestValue);
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp1(), TestValue);
				#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp1(), StartValue);
				#endif
				// now set it to the default value
				TestValue = ETbSame2Enum1::TS2E1_Value1; // default value
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetProp1(TestValue);
				#else
				ImplFixture->GetLocalImplementation()->SetProp1(TestValue);
				#endif
			}
			else
			{
				ETbSame2Enum1 TestValue = ETbSame2Enum1::TS2E1_Value1; // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetProp1(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp1(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		ETbSame2Enum1 TestValue = StartValue;
		TestValue = ETbSame2Enum1::TS2E1_Value2;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetProp1(TestValue);
	});

	It("Property.Prop2.Default", [this]()
		{
		// Do implement test here
		ETbSame2Enum2 TestValue = ETbSame2Enum2::TS2E2_Value1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp2(), TestValue);
	});

	LatentIt("Property.Prop2.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbSame2Enum2 TestValue = ETbSame2Enum2::TS2E2_Value1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp2(), TestValue);

		UTbSame2SameEnum2InterfacePublisher* TbSame2SameEnum2InterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSame2SameEnum2InterfacePublisher->OnProp2Changed.AddLambda([this, TestDone](ETbSame2Enum2 InProp2)
			{
			ETbSame2Enum2 TestValue = ETbSame2Enum2::TS2E2_Value1;
			// use different test value
			TestValue = ETbSame2Enum2::TS2E2_Value2;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp2(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = ETbSame2Enum2::TS2E2_Value2;
		ImplFixture->GetClient()->SetProp2(TestValue);
		#if ! (PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
		#endif
	});

	LatentIt("Property.Prop2.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbSame2Enum2 DefaultValue = ETbSame2Enum2::TS2E2_Value1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp2(), DefaultValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSame2SameEnum2InterfacePublisher* TbSame2SameEnum2InterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UTbSame2SameEnum2InterfacePublisher* TbSame2SameEnum2InterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		TbSame2SameEnum2InterfacePublisher->OnProp2Changed.AddLambda([this, DefaultValue, TestDone](ETbSame2Enum2 InProp2)
			{
			ETbSame2Enum2 TestValue = ETbSame2Enum2::TS2E2_Value1;
			// use different test value
			TestValue = ETbSame2Enum2::TS2E2_Value2;
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
		ETbSame2Enum2 TestValue = DefaultValue;
		TestValue = ETbSame2Enum2::TS2E2_Value2;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetProp2(TestValue);
	});

	LatentIt("Property.Prop2.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbSame2Enum2 StartValue =  ImplFixture->GetLocalImplementation()->GetProp2();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetProp2(), StartValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSame2SameEnum2InterfacePublisher* TbSame2SameEnum2InterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbSame2SameEnum2InterfacePublisher->OnProp2Changed.AddLambda([this, TestDone](ETbSame2Enum2 InProp2)
		#else
		UTbSame2SameEnum2InterfacePublisher* TbSame2SameEnum2InterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		TbSame2SameEnum2InterfacePublisher->OnProp2Changed.AddLambda([this, TestDone, StartValue](ETbSame2Enum2 InProp2)
		#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				ETbSame2Enum2 TestValue = ETbSame2Enum2::TS2E2_Value1;
				// use different test value
				TestValue = ETbSame2Enum2::TS2E2_Value2;
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetProp2(), TestValue);
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp2(), TestValue);
				#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp2(), StartValue);
				#endif
				// now set it to the default value
				TestValue = ETbSame2Enum2::TS2E2_Value1; // default value
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetProp2(TestValue);
				#else
				ImplFixture->GetLocalImplementation()->SetProp2(TestValue);
				#endif
			}
			else
			{
				ETbSame2Enum2 TestValue = ETbSame2Enum2::TS2E2_Value1; // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetProp2(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetProp2(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		ETbSame2Enum2 TestValue = StartValue;
		TestValue = ETbSame2Enum2::TS2E2_Value2;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetProp2(TestValue);
	});

	LatentIt("Operation.Func1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->Func1(ETbSame2Enum1::TS2E1_Value1);
			//Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->Func2(ETbSame2Enum1::TS2E1_Value1, ETbSame2Enum2::TS2E2_Value1);
			//Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{

		UTbSame2SameEnum2InterfacePublisher* SourceTbSame2SameEnum2InterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSame2SameEnum2InterfacePublisher* TbSame2SameEnum2InterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UTbSame2SameEnum2InterfacePublisher* TbSame2SameEnum2InterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		TbSame2SameEnum2InterfacePublisher->OnSig1Signal.AddLambda([this, TestDone](ETbSame2Enum1 InParam1)
			{
			// known test value
			ETbSame2Enum1 Param1TestValue = ETbSame2Enum1::TS2E1_Value2;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			TestDone.Execute();
		});

		// use different test value
		ETbSame2Enum1 Param1TestValue = ETbSame2Enum1::TS2E1_Value2;
		SourceTbSame2SameEnum2InterfacePublisher->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{

		UTbSame2SameEnum2InterfacePublisher* SourceTbSame2SameEnum2InterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbSame2SameEnum2InterfacePublisher* TbSame2SameEnum2InterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UTbSame2SameEnum2InterfacePublisher* TbSame2SameEnum2InterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		TbSame2SameEnum2InterfacePublisher->OnSig2Signal.AddLambda([this, TestDone](ETbSame2Enum1 InParam1, ETbSame2Enum2 InParam2)
			{
			// known test value
			ETbSame2Enum1 Param1TestValue = ETbSame2Enum1::TS2E1_Value2;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			ETbSame2Enum2 Param2TestValue = ETbSame2Enum2::TS2E2_Value2;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
			TestDone.Execute();
		});

		// use different test value
		ETbSame2Enum1 Param1TestValue = ETbSame2Enum1::TS2E1_Value2;
		ETbSame2Enum2 Param2TestValue = ETbSame2Enum2::TS2E2_Value2;
		SourceTbSame2SameEnum2InterfacePublisher->BroadcastSig2Signal(Param1TestValue, Param2TestValue);
	});
}
} // namespace Tests
} // namespace Jni
} // namespace SameEnum2Interface
} // namespace TbSame2

#endif // WITH_DEV_AUTOMATION_TESTS
