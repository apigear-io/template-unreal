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

#include "TbRefIfaces/Tests/TbRefIfacesTestsCommon.h"
#include "TbRefIfaces/Implementation/TbRefIfacesSimpleLocalIf.h"
#include "TbRefIfacesSimpleLocalIfJniFixture.h"
#include "TbRefIfaces/Generated/Jni/TbRefIfacesSimpleLocalIfJniClient.h"
#include "TbRefIfaces/Generated/Jni/TbRefIfacesSimpleLocalIfJniAdapter.h"
#include "TbIfaceimport/Tests/TbIfaceimportTestsCommon.h"

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbRefIfaces
{
namespace SimpleLocalIf
{
namespace Jni
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbRefIfacesSimpleLocalIfJniSpec, "TbRefIfaces.SimpleLocalIf.Jni", TbRefIfacesTestFilterMask);

TUniquePtr<FTbRefIfacesSimpleLocalIfJniFixture> ImplFixture;

END_DEFINE_SPEC(UTbRefIfacesSimpleLocalIfJniSpec);

void UTbRefIfacesSimpleLocalIfJniSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbRefIfacesSimpleLocalIfJniFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetClient() != nullptr);

		// set up service and adapter
		auto service = ImplFixture->GetLocalImplementation();
		ImplFixture->GetAdapter()->setBackendService(service);

		// setup client
		UTbRefIfacesSimpleLocalIfJniClient* JniClient = ImplFixture->GetClient();
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
		UTbRefIfacesSimpleLocalIfJniClient* JniClient = ImplFixture->GetClient();
#endif
		ImplFixture.Reset();
	});

	It("Property.IntProperty.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetIntProperty(), TestValue);
	});

	LatentIt("Property.IntProperty.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetIntProperty(), TestValue);

		UTbRefIfacesSimpleLocalIfPublisher* TbRefIfacesSimpleLocalIfPublisher = ImplFixture->GetClient()->_GetPublisher();
		TbRefIfacesSimpleLocalIfPublisher->OnIntPropertyChanged.AddLambda([this, TestDone](int32 InIntProperty)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InIntProperty, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetIntProperty(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1;
		ImplFixture->GetClient()->SetIntProperty(TestValue);
#if !(PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
#endif
	});

	LatentIt("Property.IntProperty.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 DefaultValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetIntProperty(), DefaultValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbRefIfacesSimpleLocalIfPublisher* TbRefIfacesSimpleLocalIfPublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbRefIfacesSimpleLocalIfPublisher* TbRefIfacesSimpleLocalIfPublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbRefIfacesSimpleLocalIfPublisher->OnIntPropertyChanged.AddLambda([this, DefaultValue, TestDone](int32 InIntProperty)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InIntProperty, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetIntProperty(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetIntProperty(), TestValue);
#else
			TestEqual(TEXT("No connection, client has same value as at the start"), ImplFixture->GetClient()->GetIntProperty(), DefaultValue);
#endif
			TestDone.Execute();
		});
		// use different test value, but init it first.
		int32 TestValue = DefaultValue;
		TestValue = 1;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetIntProperty(TestValue);
	});

	LatentIt("Property.IntProperty.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 StartValue = ImplFixture->GetLocalImplementation()->GetIntProperty();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetIntProperty(), StartValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbRefIfacesSimpleLocalIfPublisher* TbRefIfacesSimpleLocalIfPublisher = ImplFixture->GetClient()->_GetPublisher();
		TbRefIfacesSimpleLocalIfPublisher->OnIntPropertyChanged.AddLambda([this, TestDone](int32 InIntProperty)
#else
		UTbRefIfacesSimpleLocalIfPublisher* TbRefIfacesSimpleLocalIfPublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		TbRefIfacesSimpleLocalIfPublisher->OnIntPropertyChanged.AddLambda([this, TestDone, StartValue](int32 InIntProperty)
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
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InIntProperty, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetIntProperty(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetIntProperty(), TestValue);
#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetIntProperty(), StartValue);
#endif
				// now set it to the default value
				TestValue = 0; // default value
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetIntProperty(TestValue);
#else
				ImplFixture->GetLocalImplementation()->SetIntProperty(TestValue);
#endif
			}
			else
			{
				int32 TestValue = 0; // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InIntProperty, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetIntProperty(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetIntProperty(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		int32 TestValue = StartValue;
		TestValue = 1;
		auto service = ImplFixture->GetLocalImplementation();
		service->SetIntProperty(TestValue);
	});

	LatentIt("Operation.IntMethod", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->IntMethod(0);
			// Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Signal.IntSignal", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbRefIfacesSimpleLocalIfPublisher* SourceTbRefIfacesSimpleLocalIfPublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbRefIfacesSimpleLocalIfPublisher* TbRefIfacesSimpleLocalIfPublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbRefIfacesSimpleLocalIfPublisher* TbRefIfacesSimpleLocalIfPublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbRefIfacesSimpleLocalIfPublisher->OnIntSignalSignal.AddLambda([this, TestDone](int32 InParam)
			{
			// known test value
			int32 ParamTestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam, ParamTestValue);
			TestDone.Execute();
		});

		// use different test value
		int32 ParamTestValue = 1;
		SourceTbRefIfacesSimpleLocalIfPublisher->BroadcastIntSignalSignal(ParamTestValue);
	});
}
} // namespace Tests
} // namespace Jni
} // namespace SimpleLocalIf
} // namespace TbRefIfaces

#endif // WITH_DEV_AUTOMATION_TESTS
