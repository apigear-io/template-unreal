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

#include "TbRefIfaces/Implementation/TbRefIfacesParentIf.h"
#include "TbRefIfacesParentIfImplFixture.h"
#include "TbRefIfaces/Tests/TbRefIfacesTestsCommon.h"
#include "TbIfaceimport/Tests/TbIfaceimportTestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UTbRefIfacesParentIfImplSpec, "TbRefIfaces.ParentIf.Impl", TbRefIfacesTestFilterMask);

TSharedPtr<FTbRefIfacesParentIfImplFixture> ImplFixture;

END_DEFINE_SPEC(UTbRefIfacesParentIfImplSpec);

void UTbRefIfacesParentIfImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplFixture = MakeShared<FTbRefIfacesParentIfImplFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		ImplFixture->GetHelper()->SetSpec(this);
		ImplFixture->GetHelper()->SetParentFixture(ImplFixture);
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

	It("Operation.LocalIfMethod", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->LocalIfMethod(TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>());
	});

	It("Operation.LocalIfMethodList", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->LocalIfMethodList(TArray<TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>>());
	});

	It("Operation.ImportedIfMethod", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->ImportedIfMethod(TScriptInterface<ITbIfaceimportEmptyIfInterface>());
	});

	It("Operation.ImportedIfMethodList", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->ImportedIfMethodList(TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>());
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

	LatentIt("Signal.LocalIfSignalBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbRefIfacesParentIfSignals* TbRefIfacesParentIfSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbRefIfacesParentIfSignals->OnLocalIfSignalSignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbRefIfacesParentIfImplHelper::LocalIfSignalSignalCb);

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

	LatentIt("Signal.LocalIfSignalListBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbRefIfacesParentIfSignals* TbRefIfacesParentIfSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbRefIfacesParentIfSignals->OnLocalIfSignalListSignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbRefIfacesParentIfImplHelper::LocalIfSignalListSignalCb);

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

	LatentIt("Signal.ImportedIfSignalBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbRefIfacesParentIfSignals* TbRefIfacesParentIfSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbRefIfacesParentIfSignals->OnImportedIfSignalSignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbRefIfacesParentIfImplHelper::ImportedIfSignalSignalCb);

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

	LatentIt("Signal.ImportedIfSignalListBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbRefIfacesParentIfSignals* TbRefIfacesParentIfSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbRefIfacesParentIfSignals->OnImportedIfSignalListSignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbRefIfacesParentIfImplHelper::ImportedIfSignalListSignalCb);

		// use different test value
		TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>> ParamTestValue = TArray<TScriptInterface<ITbIfaceimportEmptyIfInterface>>(); // default value
		ParamTestValue.Add(TScriptInterface<ITbIfaceimportEmptyIfInterface>());
		TbRefIfacesParentIfSignals->BroadcastImportedIfSignalListSignal(ParamTestValue);
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS
