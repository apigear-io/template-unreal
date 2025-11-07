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
#include "TbRefIfaces/Implementation/TbRefIfacesParentIf.h"
#include "TbRefIfacesParentIfJniFixture.h"
#include "TbRefIfaces/Generated/Jni/TbRefIfacesParentIfJniClient.h"
#include "TbRefIfaces/Generated/Jni/TbRefIfacesParentIfJniAdapter.h"
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
namespace ParentIf
{
namespace Jni
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbRefIfacesParentIfJniSpec, "TbRefIfaces.ParentIf.Jni", TbRefIfacesTestFilterMask);

TUniquePtr<FTbRefIfacesParentIfJniFixture> ImplFixture;

END_DEFINE_SPEC(UTbRefIfacesParentIfJniSpec);

void UTbRefIfacesParentIfJniSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbRefIfacesParentIfJniFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetClient() != nullptr);

		// set up service and adapter
		auto service = ImplFixture->GetLocalImplementation();
		ImplFixture->GetAdapter()->setBackendService(service);

		// setup client
		UTbRefIfacesParentIfJniClient* JniClient = ImplFixture->GetClient();
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
		UTbRefIfacesParentIfJniClient* JniClient = ImplFixture->GetClient();
#endif
		ImplFixture.Reset();
	});

	It("Property.LocalIf.Default", [this]()
		{
		// Do implement test here
		TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> TestValue = TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetLocalIf(), TestValue);
	});

	It("Property.LocalIfList.Default", [this]()
		{
		// Do implement test here
		TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> TestValue = TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetLocalIfList(), TestValue);
	});

	It("Property.ImportedIf.Default", [this]()
		{
		// Do implement test here
		TScriptInterface<ITbIfaceimportEmptyIfInterface> TestValue = TScriptInterface<ITbIfaceimportEmptyIfInterface>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetImportedIf(), TestValue);
	});

	It("Property.ImportedIfList.Default", [this]()
		{
		// Do implement test here
		TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> TestValue = TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetImportedIfList(), TestValue);
	});

	LatentIt("Operation.LocalIfMethod", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->LocalIfMethod(TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>());
			// Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.LocalIfMethodList", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->LocalIfMethodList(TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>());
			// Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.ImportedIfMethod", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->ImportedIfMethod(TScriptInterface<ITbIfaceimportEmptyIfInterface>());
			// Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.ImportedIfMethodList", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->ImportedIfMethodList(TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>());
			// Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Signal.LocalIfSignal", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbRefIfacesParentIfPublisher* SourceTbRefIfacesParentIfPublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbRefIfacesParentIfPublisher* TbRefIfacesParentIfPublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbRefIfacesParentIfPublisher* TbRefIfacesParentIfPublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbRefIfacesParentIfPublisher->OnLocalIfSignalSignal.AddLambda([this, TestDone](const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InParam)
			{
			// known test value
			TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> ParamTestValue = TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam, ParamTestValue);
			TestDone.Execute();
		});

		// use different test value
		TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> ParamTestValue = TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>();
		SourceTbRefIfacesParentIfPublisher->BroadcastLocalIfSignalSignal(ParamTestValue);
	});

	LatentIt("Signal.LocalIfSignalList", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbRefIfacesParentIfPublisher* SourceTbRefIfacesParentIfPublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbRefIfacesParentIfPublisher* TbRefIfacesParentIfPublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbRefIfacesParentIfPublisher* TbRefIfacesParentIfPublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbRefIfacesParentIfPublisher->OnLocalIfSignalListSignal.AddLambda([this, TestDone](const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& InParam)
			{
			// known test value
			TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> ParamTestValue = TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>(); // default value
			ParamTestValue.Add(TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>());
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam, ParamTestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> ParamTestValue = TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>(); // default value
		ParamTestValue.Add(TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>());
		SourceTbRefIfacesParentIfPublisher->BroadcastLocalIfSignalListSignal(ParamTestValue);
	});

	LatentIt("Signal.ImportedIfSignal", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbRefIfacesParentIfPublisher* SourceTbRefIfacesParentIfPublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbRefIfacesParentIfPublisher* TbRefIfacesParentIfPublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbRefIfacesParentIfPublisher* TbRefIfacesParentIfPublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbRefIfacesParentIfPublisher->OnImportedIfSignalSignal.AddLambda([this, TestDone](const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InParam)
			{
			// known test value
			TScriptInterface<ITbIfaceimportEmptyIfInterface> ParamTestValue = TScriptInterface<ITbIfaceimportEmptyIfInterface>();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam, ParamTestValue);
			TestDone.Execute();
		});

		// use different test value
		TScriptInterface<ITbIfaceimportEmptyIfInterface> ParamTestValue = TScriptInterface<ITbIfaceimportEmptyIfInterface>();
		SourceTbRefIfacesParentIfPublisher->BroadcastImportedIfSignalSignal(ParamTestValue);
	});

	LatentIt("Signal.ImportedIfSignalList", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbRefIfacesParentIfPublisher* SourceTbRefIfacesParentIfPublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbRefIfacesParentIfPublisher* TbRefIfacesParentIfPublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbRefIfacesParentIfPublisher* TbRefIfacesParentIfPublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbRefIfacesParentIfPublisher->OnImportedIfSignalListSignal.AddLambda([this, TestDone](const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& InParam)
			{
			// known test value
			TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> ParamTestValue = TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>(); // default value
			ParamTestValue.Add(TScriptInterface<ITbIfaceimportEmptyIfInterface>());
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam, ParamTestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> ParamTestValue = TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>(); // default value
		ParamTestValue.Add(TScriptInterface<ITbIfaceimportEmptyIfInterface>());
		SourceTbRefIfacesParentIfPublisher->BroadcastImportedIfSignalListSignal(ParamTestValue);
	});
}
} // namespace Tests
} // namespace Jni
} // namespace ParentIf
} // namespace TbRefIfaces

#endif // WITH_DEV_AUTOMATION_TESTS
