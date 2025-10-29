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

#include "TbNames/Tests/TbNamesTestsCommon.h"
#include "TbNames/Implementation/TbNamesNamEs.h"
#include "TbNamesNamEsJniFixture.h"
#include "TbNames/Generated/Jni/TbNamesNamEsJniClient.h"
#include "TbNames/Generated/Jni/TbNamesNamEsJniAdapter.h"


#if PLATFORM_ANDROID

#include "Engine/Engine.h"
 #include "Android/AndroidJNI.h"
 #include "Android/AndroidApplication.h"

 #if USE_ANDROID_JNI
 #include <jni.h>
 #endif
#endif

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbNames
{
namespace NamEs
{
namespace Jni
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbNamesNamEsJniSpec, "TbNames.NamEs.Jni", TbNamesTestFilterMask);

TUniquePtr<FTbNamesNamEsJniFixture> ImplFixture;

END_DEFINE_SPEC(UTbNamesNamEsJniSpec);

void UTbNamesNamEsJniSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbNamesNamEsJniFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetClient() != nullptr);

		// set up service and adapter
		auto service =ImplFixture->GetLocalImplementation();
		ImplFixture->GetAdapter()->setBackendService(service);

		// setup client
		UTbNamesNamEsJniClient* JniClient = ImplFixture->GetClient();
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
			UTbNamesNamEsJniClient* JniClient =ImplFixture->GetClient();
			#endif
			ImplFixture.Reset();
	});

	It("Property.Switch.Default", [this]()
		{
		// Do implement test here
		bool TestValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetSwitch(), TestValue);
	});

	LatentIt("Property.Switch.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		bool TestValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetSwitch(), TestValue);

		UTbNamesNamEsPublisher* TbNamesNamEsPublisher = ImplFixture->GetClient()->_GetPublisher();
		TbNamesNamEsPublisher->OnSwitchChanged.AddLambda([this, TestDone](bool bInSwitch)
			{
			bool TestValue = false;
			// use different test value
			TestValue = true;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInSwitch, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetSwitch(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = true;
		ImplFixture->GetClient()->SetSwitch(TestValue);
		#if ! (PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
		#endif
	});

	LatentIt("Property.Switch.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		bool DefaultValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetSwitch(), DefaultValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbNamesNamEsPublisher* TbNamesNamEsPublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UTbNamesNamEsPublisher* TbNamesNamEsPublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		TbNamesNamEsPublisher->OnSwitchChanged.AddLambda([this, DefaultValue, TestDone](bool bInSwitch)
			{
			bool TestValue = false;
			// use different test value
			TestValue = true;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInSwitch, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetSwitch(), TestValue);
			#if PLATFORM_ANDROID && USE_ANDROID_JNI
			//TODO CHANGE THE IMPLEMENTATION TO CLIENT this is confusing
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetSwitch(), TestValue);
			#else
			TestEqual(TEXT("No connection, client has same value as at the start"), ImplFixture->GetClient()->GetSwitch(), DefaultValue);
			#endif
			TestDone.Execute();
		});
		// use different test value, but init it first.
		bool TestValue = DefaultValue;
		TestValue = true;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetSwitch(TestValue);
	});

	LatentIt("Property.Switch.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		bool StartValue =  ImplFixture->GetLocalImplementation()->GetSwitch();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetSwitch(), StartValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbNamesNamEsPublisher* TbNamesNamEsPublisher = ImplFixture->GetClient()->_GetPublisher();
		TbNamesNamEsPublisher->OnSwitchChanged.AddLambda([this, TestDone](bool bInSwitch)
		#else
		UTbNamesNamEsPublisher* TbNamesNamEsPublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		TbNamesNamEsPublisher->OnSwitchChanged.AddLambda([this, TestDone, StartValue](bool bInSwitch)
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
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInSwitch, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetSwitch(), TestValue);
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetSwitch(), TestValue);
				#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetSwitch(), StartValue);
				#endif
				// now set it to the default value
				TestValue = false; // default value
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetSwitch(TestValue);
				#else
				ImplFixture->GetLocalImplementation()->SetSwitch(TestValue);
				#endif
			}
			else
			{
				bool TestValue = false; // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInSwitch, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetSwitch(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetSwitch(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		bool TestValue = StartValue;
		TestValue = true;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetSwitch(TestValue);
	});

	It("Property.SomeProperty.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetSomeProperty(), TestValue);
	});

	LatentIt("Property.SomeProperty.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetSomeProperty(), TestValue);

		UTbNamesNamEsPublisher* TbNamesNamEsPublisher = ImplFixture->GetClient()->_GetPublisher();
		TbNamesNamEsPublisher->OnSomePropertyChanged.AddLambda([this, TestDone](int32 InSomeProperty)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomeProperty, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetSomeProperty(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1;
		ImplFixture->GetClient()->SetSomeProperty(TestValue);
		#if ! (PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
		#endif
	});

	LatentIt("Property.SomeProperty.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 DefaultValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetSomeProperty(), DefaultValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbNamesNamEsPublisher* TbNamesNamEsPublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UTbNamesNamEsPublisher* TbNamesNamEsPublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		TbNamesNamEsPublisher->OnSomePropertyChanged.AddLambda([this, DefaultValue, TestDone](int32 InSomeProperty)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomeProperty, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetSomeProperty(), TestValue);
			#if PLATFORM_ANDROID && USE_ANDROID_JNI
			//TODO CHANGE THE IMPLEMENTATION TO CLIENT this is confusing
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetSomeProperty(), TestValue);
			#else
			TestEqual(TEXT("No connection, client has same value as at the start"), ImplFixture->GetClient()->GetSomeProperty(), DefaultValue);
			#endif
			TestDone.Execute();
		});
		// use different test value, but init it first.
		int32 TestValue = DefaultValue;
		TestValue = 1;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetSomeProperty(TestValue);
	});

	LatentIt("Property.SomeProperty.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 StartValue =  ImplFixture->GetLocalImplementation()->GetSomeProperty();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetSomeProperty(), StartValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbNamesNamEsPublisher* TbNamesNamEsPublisher = ImplFixture->GetClient()->_GetPublisher();
		TbNamesNamEsPublisher->OnSomePropertyChanged.AddLambda([this, TestDone](int32 InSomeProperty)
		#else
		UTbNamesNamEsPublisher* TbNamesNamEsPublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		TbNamesNamEsPublisher->OnSomePropertyChanged.AddLambda([this, TestDone, StartValue](int32 InSomeProperty)
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
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomeProperty, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetSomeProperty(), TestValue);
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetSomeProperty(), TestValue);
				#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetSomeProperty(), StartValue);
				#endif
				// now set it to the default value
				TestValue = 0; // default value
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetSomeProperty(TestValue);
				#else
				ImplFixture->GetLocalImplementation()->SetSomeProperty(TestValue);
				#endif
			}
			else
			{
				int32 TestValue = 0; // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomeProperty, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetSomeProperty(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetSomeProperty(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		int32 TestValue = StartValue;
		TestValue = 1;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetSomeProperty(TestValue);
	});

	It("Property.SomePoperty2.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetSomePoperty2(), TestValue);
	});

	LatentIt("Property.SomePoperty2.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetSomePoperty2(), TestValue);

		UTbNamesNamEsPublisher* TbNamesNamEsPublisher = ImplFixture->GetClient()->_GetPublisher();
		TbNamesNamEsPublisher->OnSomePoperty2Changed.AddLambda([this, TestDone](int32 InSomePoperty2)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomePoperty2, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetSomePoperty2(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1;
		ImplFixture->GetClient()->SetSomePoperty2(TestValue);
		#if ! (PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
		#endif
	});

	LatentIt("Property.SomePoperty2.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 DefaultValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetSomePoperty2(), DefaultValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbNamesNamEsPublisher* TbNamesNamEsPublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UTbNamesNamEsPublisher* TbNamesNamEsPublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		TbNamesNamEsPublisher->OnSomePoperty2Changed.AddLambda([this, DefaultValue, TestDone](int32 InSomePoperty2)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomePoperty2, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetSomePoperty2(), TestValue);
			#if PLATFORM_ANDROID && USE_ANDROID_JNI
			//TODO CHANGE THE IMPLEMENTATION TO CLIENT this is confusing
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetSomePoperty2(), TestValue);
			#else
			TestEqual(TEXT("No connection, client has same value as at the start"), ImplFixture->GetClient()->GetSomePoperty2(), DefaultValue);
			#endif
			TestDone.Execute();
		});
		// use different test value, but init it first.
		int32 TestValue = DefaultValue;
		TestValue = 1;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetSomePoperty2(TestValue);
	});

	LatentIt("Property.SomePoperty2.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 StartValue =  ImplFixture->GetLocalImplementation()->GetSomePoperty2();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetSomePoperty2(), StartValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbNamesNamEsPublisher* TbNamesNamEsPublisher = ImplFixture->GetClient()->_GetPublisher();
		TbNamesNamEsPublisher->OnSomePoperty2Changed.AddLambda([this, TestDone](int32 InSomePoperty2)
		#else
		UTbNamesNamEsPublisher* TbNamesNamEsPublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		TbNamesNamEsPublisher->OnSomePoperty2Changed.AddLambda([this, TestDone, StartValue](int32 InSomePoperty2)
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
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomePoperty2, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetSomePoperty2(), TestValue);
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetSomePoperty2(), TestValue);
				#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetSomePoperty2(), StartValue);
				#endif
				// now set it to the default value
				TestValue = 0; // default value
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetSomePoperty2(TestValue);
				#else
				ImplFixture->GetLocalImplementation()->SetSomePoperty2(TestValue);
				#endif
			}
			else
			{
				int32 TestValue = 0; // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomePoperty2, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetSomePoperty2(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetSomePoperty2(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		int32 TestValue = StartValue;
		TestValue = 1;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetSomePoperty2(TestValue);
	});

	It("Property.EnumProperty.Default", [this]()
		{
		// Do implement test here
		ETbNamesEnum_With_Under_scores TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetEnumProperty(), TestValue);
	});

	LatentIt("Property.EnumProperty.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbNamesEnum_With_Under_scores TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetEnumProperty(), TestValue);

		UTbNamesNamEsPublisher* TbNamesNamEsPublisher = ImplFixture->GetClient()->_GetPublisher();
		TbNamesNamEsPublisher->OnEnumPropertyChanged.AddLambda([this, TestDone](ETbNamesEnum_With_Under_scores InEnumProperty)
			{
			ETbNamesEnum_With_Under_scores TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue;
			// use different test value
			TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_SecondValue;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InEnumProperty, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetEnumProperty(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_SecondValue;
		ImplFixture->GetClient()->SetEnumProperty(TestValue);
		#if ! (PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
		#endif
	});

	LatentIt("Property.EnumProperty.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbNamesEnum_With_Under_scores DefaultValue = ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetEnumProperty(), DefaultValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbNamesNamEsPublisher* TbNamesNamEsPublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UTbNamesNamEsPublisher* TbNamesNamEsPublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		TbNamesNamEsPublisher->OnEnumPropertyChanged.AddLambda([this, DefaultValue, TestDone](ETbNamesEnum_With_Under_scores InEnumProperty)
			{
			ETbNamesEnum_With_Under_scores TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue;
			// use different test value
			TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_SecondValue;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InEnumProperty, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetEnumProperty(), TestValue);
			#if PLATFORM_ANDROID && USE_ANDROID_JNI
			//TODO CHANGE THE IMPLEMENTATION TO CLIENT this is confusing
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetEnumProperty(), TestValue);
			#else
			TestEqual(TEXT("No connection, client has same value as at the start"), ImplFixture->GetClient()->GetEnumProperty(), DefaultValue);
			#endif
			TestDone.Execute();
		});
		// use different test value, but init it first.
		ETbNamesEnum_With_Under_scores TestValue = DefaultValue;
		TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_SecondValue;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetEnumProperty(TestValue);
	});

	LatentIt("Property.EnumProperty.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbNamesEnum_With_Under_scores StartValue =  ImplFixture->GetLocalImplementation()->GetEnumProperty();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetEnumProperty(), StartValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbNamesNamEsPublisher* TbNamesNamEsPublisher = ImplFixture->GetClient()->_GetPublisher();
		TbNamesNamEsPublisher->OnEnumPropertyChanged.AddLambda([this, TestDone](ETbNamesEnum_With_Under_scores InEnumProperty)
		#else
		UTbNamesNamEsPublisher* TbNamesNamEsPublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		TbNamesNamEsPublisher->OnEnumPropertyChanged.AddLambda([this, TestDone, StartValue](ETbNamesEnum_With_Under_scores InEnumProperty)
		#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				ETbNamesEnum_With_Under_scores TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue;
				// use different test value
				TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_SecondValue;
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InEnumProperty, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetEnumProperty(), TestValue);
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetEnumProperty(), TestValue);
				#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetEnumProperty(), StartValue);
				#endif
				// now set it to the default value
				TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue; // default value
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetEnumProperty(TestValue);
				#else
				ImplFixture->GetLocalImplementation()->SetEnumProperty(TestValue);
				#endif
			}
			else
			{
				ETbNamesEnum_With_Under_scores TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue; // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InEnumProperty, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetEnumProperty(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetEnumProperty(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		ETbNamesEnum_With_Under_scores TestValue = StartValue;
		TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_SecondValue;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetEnumProperty(TestValue);
	});

	LatentIt("Operation.SomeFunction", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->SomeFunction(false);
			//Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.SomeFunction2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->SomeFunction2(false);
			//Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Signal.SomeSignal", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{

		UTbNamesNamEsPublisher* SourceTbNamesNamEsPublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbNamesNamEsPublisher* TbNamesNamEsPublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UTbNamesNamEsPublisher* TbNamesNamEsPublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		TbNamesNamEsPublisher->OnSomeSignalSignal.AddLambda([this, TestDone](bool bInSomeParam)
			{
			// known test value
			bool bSomeParamTestValue = true;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), bInSomeParam, bSomeParamTestValue);
			TestDone.Execute();
		});

		// use different test value
		bool bSomeParamTestValue = true;
		SourceTbNamesNamEsPublisher->BroadcastSomeSignalSignal(bSomeParamTestValue);
	});

	LatentIt("Signal.SomeSignal2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{

		UTbNamesNamEsPublisher* SourceTbNamesNamEsPublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbNamesNamEsPublisher* TbNamesNamEsPublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UTbNamesNamEsPublisher* TbNamesNamEsPublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		TbNamesNamEsPublisher->OnSomeSignal2Signal.AddLambda([this, TestDone](bool bInSomeParam)
			{
			// known test value
			bool bSomeParamTestValue = true;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), bInSomeParam, bSomeParamTestValue);
			TestDone.Execute();
		});

		// use different test value
		bool bSomeParamTestValue = true;
		SourceTbNamesNamEsPublisher->BroadcastSomeSignal2Signal(bSomeParamTestValue);
	});
}
} // namespace Tests
} // namespace Jni
} // namespace NamEs
} // namespace TbNames

#endif // WITH_DEV_AUTOMATION_TESTS
