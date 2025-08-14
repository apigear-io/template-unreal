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
#include "TbRefIfacesParentIfMsgBusFixture.h"
#include "TbRefIfaces/Generated/MsgBus/TbRefIfacesParentIfMsgBusClient.h"
#include "TbRefIfaces/Generated/MsgBus/TbRefIfacesParentIfMsgBusAdapter.h"
#include "TbIfaceimport/Tests/TbIfaceimportTestsCommon.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbRefIfaces
{
namespace ParentIf
{
namespace MsgBus
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbRefIfacesParentIfMsgBusSpec, "TbRefIfaces.ParentIf.MsgBus", TbRefIfacesTestFilterMask);

TUniquePtr<FTbRefIfacesParentIfMsgBusFixture> ImplFixture;

END_DEFINE_SPEC(UTbRefIfacesParentIfMsgBusSpec);

void UTbRefIfacesParentIfMsgBusSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbRefIfacesParentIfMsgBusFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// set up service and adapter
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbRefIfacesParentIfImplementation>();
		ImplFixture->GetAdapter()->_setBackendService(service);
		ImplFixture->GetAdapter()->_StartListening();

		// setup client
		UTbRefIfacesParentIfMsgBusClient* MsgBusClient = Cast<UTbRefIfacesParentIfMsgBusClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid MsgBus client", MsgBusClient != nullptr);

		MsgBusClient->_ConnectionStatusChanged.AddLambda([this, TestDone](bool bConnected)
			{
			if (bConnected)
			{
				TestDone.Execute();
			}
		});

		MsgBusClient->_Connect();
	});

	AfterEach([this]()
		{
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

	LatentIt("Operation.LocalIfMethod", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->LocalIfMethod(TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.LocalIfMethodList", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->LocalIfMethodList(TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.ImportedIfMethod", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->ImportedIfMethod(TScriptInterface<ITbIfaceimportEmptyIfInterface>());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.ImportedIfMethodList", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->ImportedIfMethodList(TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>());
			TestDone.Execute();
		});
	});

	LatentIt("Signal.LocalIfSignal", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbRefIfacesParentIfSignals* TbRefIfacesParentIfSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbRefIfacesParentIfSignals->OnLocalIfSignalSignal.AddLambda([this, TestDone](const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& InParam)
			{
			// known test value
			TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> ParamTestValue = TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam, ParamTestValue);
			TestDone.Execute();
		});

		// use different test value
		TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> ParamTestValue = TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>();
		TbRefIfacesParentIfSignals->BroadcastLocalIfSignalSignal(ParamTestValue);
	});

	LatentIt("Signal.LocalIfSignalList", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbRefIfacesParentIfSignals* TbRefIfacesParentIfSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbRefIfacesParentIfSignals->OnLocalIfSignalListSignal.AddLambda([this, TestDone](const TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>& InParam)
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
		TbRefIfacesParentIfSignals->BroadcastLocalIfSignalListSignal(ParamTestValue);
	});

	LatentIt("Signal.ImportedIfSignal", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbRefIfacesParentIfSignals* TbRefIfacesParentIfSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbRefIfacesParentIfSignals->OnImportedIfSignalSignal.AddLambda([this, TestDone](const TScriptInterface<ITbIfaceimportEmptyIfInterface>& InParam)
			{
			// known test value
			TScriptInterface<ITbIfaceimportEmptyIfInterface> ParamTestValue = TScriptInterface<ITbIfaceimportEmptyIfInterface>();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam, ParamTestValue);
			TestDone.Execute();
		});

		// use different test value
		TScriptInterface<ITbIfaceimportEmptyIfInterface> ParamTestValue = TScriptInterface<ITbIfaceimportEmptyIfInterface>();
		TbRefIfacesParentIfSignals->BroadcastImportedIfSignalSignal(ParamTestValue);
	});

	LatentIt("Signal.ImportedIfSignalList", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbRefIfacesParentIfSignals* TbRefIfacesParentIfSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbRefIfacesParentIfSignals->OnImportedIfSignalListSignal.AddLambda([this, TestDone](const TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>& InParam)
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
		TbRefIfacesParentIfSignals->BroadcastImportedIfSignalListSignal(ParamTestValue);
	});
}
} // namespace Tests
} // namespace MsgBus
} // namespace ParentIf
} // namespace TbRefIfaces

#endif // WITH_DEV_AUTOMATION_TESTS
