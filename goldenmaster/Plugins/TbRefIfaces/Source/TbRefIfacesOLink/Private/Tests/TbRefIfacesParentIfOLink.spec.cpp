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

#include "OLinkCommon.h"
#include "HAL/Platform.h"

#if !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
#include "TbRefIfacesParentIfOLinkFixture.h"
#include "TbRefIfaces/Implementation/TbRefIfacesParentIf.h"
#include "TbRefIfaces/Generated/OLink/TbRefIfacesParentIfOLinkClient.h"
#include "TbRefIfaces/Generated/OLink/TbRefIfacesParentIfOLinkAdapter.h"

#include "OLinkHost.h"
#include "OLinkClientConnection.h" // for olink factory
#include "TbRefIfaces/Tests/TbRefIfacesTestsCommon.h"
#include "TbIfaceimport/Tests/TbIfaceimportTestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbRefIfaces
{
namespace ParentIf
{
namespace OLink
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbRefIfacesParentIfOLinkSpec, "TbRefIfaces.ParentIf.OLink", TbRefIfacesTestFilterMask);

TUniquePtr<FTbRefIfacesParentIfOLinkFixture> ImplFixture;

END_DEFINE_SPEC(UTbRefIfacesParentIfOLinkSpec);

void UTbRefIfacesParentIfOLinkSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbRefIfacesParentIfOLinkFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// set up service and adapter
		ImplFixture->GetHost()->Stop();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbRefIfacesParentIfImplementation>();
		ImplFixture->GetAdapter()->setBackendService(service);
		ImplFixture->GetAdapter()->setOLinkHost(ImplFixture->GetHost());
		ImplFixture->GetHost()->Start(8666);

		// setup client
		UTbRefIfacesParentIfOLinkClient* OLinkClient = Cast<UTbRefIfacesParentIfOLinkClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid OLink client", OLinkClient != nullptr);

		OLinkClient->_SubscriptionStatusChanged.AddLambda([this, TestDone](bool bSubscribed)
			{
			if (bSubscribed)
			{
				TestDone.Execute();
			}
		});

		ImplFixture->Connection = OLinkFactory::Create(GetTransientPackage(), "TestingConnection");
		ImplFixture->Connection.GetObject()->AddToRoot();
		ImplFixture->Connection->Configure("ws://127.0.0.1:8666/ws", false);

		OLinkClient->UseConnection(ImplFixture->Connection);
		ImplFixture->Connection->Connect();
	});

	AfterEach([this]()
		{
		if (ImplFixture->Connection && IsValid(ImplFixture->Connection.GetObject()))
		{
			ImplFixture->Connection->Disconnect();
			ImplFixture->Connection.GetObject()->RemoveFromRoot();
		}
		ImplFixture.Reset();
	});

	It("Property.LocalIf.Default", [this]()
		{
		// Do implement test here
		TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> TestValue = TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetLocalIf(), TestValue);
	});

	It("Property.LocalIfList.Default", [this]()
		{
		// Do implement test here
		TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> TestValue = TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetLocalIfList(), TestValue);
	});

	It("Property.ImportedIf.Default", [this]()
		{
		// Do implement test here
		TScriptInterface<ITbIfaceimportEmptyIfInterface> TestValue = TScriptInterface<ITbIfaceimportEmptyIfInterface>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetImportedIf(), TestValue);
	});

	It("Property.ImportedIfList.Default", [this]()
		{
		// Do implement test here
		TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> TestValue = TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetImportedIfList(), TestValue);
	});

	// Please implement serialization for TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> before enabling the test.
	xLatentIt("Operation.LocalIfMethod", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Please implement serialization for TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> before testing.
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->LocalIfMethod(TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>());
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	// Please implement serialization for TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> before enabling the test.
	xLatentIt("Operation.LocalIfMethodAsync", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		// Please implement serialization for TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> before testing.
		// Test async operation through OLink (client -> network -> server -> network -> client callback)
		TFuture<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> Future = ImplFixture->GetImplementation()->LocalIfMethodAsync(TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>());

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Result)
			{
			// Verify values here based on service logic
			Done.Execute();
		});
	});

	// Please implement serialization for TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> before enabling the test.
	xLatentIt("Operation.LocalIfMethodList", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Please implement serialization for TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> before testing.
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->LocalIfMethodList(TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>());
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	// Please implement serialization for TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> before enabling the test.
	xLatentIt("Operation.LocalIfMethodListAsync", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		// Please implement serialization for TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>> before testing.
		// Test async operation through OLink (client -> network -> server -> network -> client callback)
		TFuture<TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>> Future = ImplFixture->GetImplementation()->LocalIfMethodListAsync(TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>());

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& Result)
			{
			// Verify values here based on service logic
			Done.Execute();
		});
	});

	// Please implement serialization for TScriptInterface<ITbIfaceimportEmptyIfInterface> before enabling the test.
	xLatentIt("Operation.ImportedIfMethod", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Please implement serialization for TScriptInterface<ITbIfaceimportEmptyIfInterface> before testing.
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->ImportedIfMethod(TScriptInterface<ITbIfaceimportEmptyIfInterface>());
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	// Please implement serialization for TScriptInterface<ITbIfaceimportEmptyIfInterface> before enabling the test.
	xLatentIt("Operation.ImportedIfMethodAsync", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		// Please implement serialization for TScriptInterface<ITbIfaceimportEmptyIfInterface> before testing.
		// Test async operation through OLink (client -> network -> server -> network -> client callback)
		TFuture<TScriptInterface<ITbIfaceimportEmptyIfInterface>> Future = ImplFixture->GetImplementation()->ImportedIfMethodAsync(TScriptInterface<ITbIfaceimportEmptyIfInterface>());

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Result)
			{
			// Verify values here based on service logic
			Done.Execute();
		});
	});

	// Please implement serialization for TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> before enabling the test.
	xLatentIt("Operation.ImportedIfMethodList", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Please implement serialization for TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> before testing.
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->ImportedIfMethodList(TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>());
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	// Please implement serialization for TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> before enabling the test.
	xLatentIt("Operation.ImportedIfMethodListAsync", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		// Please implement serialization for TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> before testing.
		// Test async operation through OLink (client -> network -> server -> network -> client callback)
		TFuture<TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>> Future = ImplFixture->GetImplementation()->ImportedIfMethodListAsync(TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>());

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& Result)
			{
			// Verify values here based on service logic
			Done.Execute();
		});
	});

	LatentIt("Signal.LocalIfSignal", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbRefIfacesParentIfPublisher* TbRefIfacesParentIfPublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbRefIfacesParentIfPublisher->OnLocalIfSignalSignal.AddLambda([this, TestDone](const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InParam)
			{
			// known test value
			TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> ParamTestValue = TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam, ParamTestValue);
			TestDone.Execute();
		});

		// use different test value
		TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> ParamTestValue = TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>();
		TbRefIfacesParentIfPublisher->BroadcastLocalIfSignalSignal(ParamTestValue);
	});

	LatentIt("Signal.LocalIfSignalList", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbRefIfacesParentIfPublisher* TbRefIfacesParentIfPublisher = ImplFixture->GetImplementation()->_GetPublisher();
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
		TbRefIfacesParentIfPublisher->BroadcastLocalIfSignalListSignal(ParamTestValue);
	});

	LatentIt("Signal.ImportedIfSignal", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbRefIfacesParentIfPublisher* TbRefIfacesParentIfPublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbRefIfacesParentIfPublisher->OnImportedIfSignalSignal.AddLambda([this, TestDone](const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InParam)
			{
			// known test value
			TScriptInterface<ITbIfaceimportEmptyIfInterface> ParamTestValue = TScriptInterface<ITbIfaceimportEmptyIfInterface>();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam, ParamTestValue);
			TestDone.Execute();
		});

		// use different test value
		TScriptInterface<ITbIfaceimportEmptyIfInterface> ParamTestValue = TScriptInterface<ITbIfaceimportEmptyIfInterface>();
		TbRefIfacesParentIfPublisher->BroadcastImportedIfSignalSignal(ParamTestValue);
	});

	LatentIt("Signal.ImportedIfSignalList", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbRefIfacesParentIfPublisher* TbRefIfacesParentIfPublisher = ImplFixture->GetImplementation()->_GetPublisher();
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
		TbRefIfacesParentIfPublisher->BroadcastImportedIfSignalListSignal(ParamTestValue);
	});
}
} // namespace Tests
} // namespace OLink
} // namespace ParentIf
} // namespace TbRefIfaces

#endif // WITH_DEV_AUTOMATION_TESTS
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
