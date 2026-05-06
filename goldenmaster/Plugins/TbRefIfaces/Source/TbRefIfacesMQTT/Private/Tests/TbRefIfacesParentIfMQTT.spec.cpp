// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "TbRefIfaces/Tests/TbRefIfacesTestsCommon.h"
#include "TbRefIfaces/Implementation/TbRefIfacesParentIf.h"
#include "TbRefIfacesParentIfMQTTFixture.h"
#include "TbRefIfaces/Generated/MQTT/TbRefIfacesParentIfMQTTClient.h"
#include "TbRefIfaces/Generated/MQTT/TbRefIfacesParentIfMQTTAdapter.h"
#include "ApiGearMQTTClient.h"
#include "TbIfaceimport/Tests/TbIfaceimportTestsCommon.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbRefIfaces
{
namespace ParentIf
{
namespace MQTT
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbRefIfacesParentIfMQTTSpec, "TbRefIfaces.ParentIf.MQTT", TbRefIfacesTestFilterMask);

TUniquePtr<FTbRefIfacesParentIfMQTTFixture> ImplFixture;

END_DEFINE_SPEC(UTbRefIfacesParentIfMQTTSpec);

void UTbRefIfacesParentIfMQTTSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbRefIfacesParentIfMQTTFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// setup client
		UTbRefIfacesParentIfMQTTClient* MQTTClient = Cast<UTbRefIfacesParentIfMQTTClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid MQTT client", MQTTClient != nullptr);

		MQTTClient->_SubscriptionStatusChanged.AddLambda([this, TestDone](bool bSubscribed)
			{
			if (bSubscribed)
			{
				TestDone.Execute();
			}
		});

		MQTTClient->UseConnection(ImplFixture->Connection);
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
} // namespace MQTT
} // namespace ParentIf
} // namespace TbRefIfaces

#endif // WITH_DEV_AUTOMATION_TESTS
