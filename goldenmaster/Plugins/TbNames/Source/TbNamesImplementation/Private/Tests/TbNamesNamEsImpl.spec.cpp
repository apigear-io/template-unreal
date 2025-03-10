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

#include "TbNamesNamEsImpl.spec.h"
#include "TbNames/Implementation/TbNamesNamEs.h"
#include "TbNamesNamEsImplFixture.h"
#include "TbNames/Tests/TbNamesTestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbNamesNamEsImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplFixture = MakeUnique<FTbNamesNamEsImplFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		ImplFixture->GetHelper()->SetSpec(this);
	});

	AfterEach([this]()
		{
		ImplFixture.Reset();
	});

	It("Property.Switch.Default", [this]()
		{
		// Do implement test here
		bool TestValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetSwitch(), TestValue);
	});

	LatentIt("Property.Switch.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		bool TestValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetSwitch(), TestValue);

		testDoneDelegate = TestDone;
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbNamesNamEsSignals->OnSwitchChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsImplHelper::SwitchPropertyCb);
		// use different test value
		TestValue = true;
		ImplFixture->GetImplementation()->SetSwitch(TestValue);
	});

	It("Property.SomeProperty.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetSomeProperty(), TestValue);
	});

	LatentIt("Property.SomeProperty.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetSomeProperty(), TestValue);

		testDoneDelegate = TestDone;
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbNamesNamEsSignals->OnSomePropertyChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsImplHelper::SomePropertyPropertyCb);
		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->SetSomeProperty(TestValue);
	});

	It("Property.SomePoperty2.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetSomePoperty2(), TestValue);
	});

	LatentIt("Property.SomePoperty2.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetSomePoperty2(), TestValue);

		testDoneDelegate = TestDone;
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbNamesNamEsSignals->OnSomePoperty2ChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsImplHelper::SomePoperty2PropertyCb);
		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->SetSomePoperty2(TestValue);
	});

	It("Operation.SomeFunction", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->SomeFunction(false);
	});

	It("Operation.SomeFunction2", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->SomeFunction2(false);
	});

	LatentIt("Signal.SomeSignal", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbNamesNamEsSignals->OnSomeSignalSignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsImplHelper::SomeSignalSignalCb);

		// use different test value
		bool bSomeParamTestValue = true;
		TbNamesNamEsSignals->BroadcastSomeSignalSignal(bSomeParamTestValue);
	});

	LatentIt("Signal.SomeSignal2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbNamesNamEsSignals->OnSomeSignal2SignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsImplHelper::SomeSignal2SignalCb);

		// use different test value
		bool bSomeParamTestValue = true;
		TbNamesNamEsSignals->BroadcastSomeSignal2Signal(bSomeParamTestValue);
	});
}

void UTbNamesNamEsImplSpec::SwitchPropertyCb(bool bInSwitch)
{
	bool TestValue = false;
	// use different test value
	TestValue = true;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInSwitch, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetSwitch(), TestValue);
	testDoneDelegate.Execute();
}

void UTbNamesNamEsImplSpec::SomePropertyPropertyCb(int32 InSomeProperty)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomeProperty, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetSomeProperty(), TestValue);
	testDoneDelegate.Execute();
}

void UTbNamesNamEsImplSpec::SomePoperty2PropertyCb(int32 InSomePoperty2)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomePoperty2, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetSomePoperty2(), TestValue);
	testDoneDelegate.Execute();
}

void UTbNamesNamEsImplSpec::SomeSignalSignalCb(bool bInSomeParam)
{
	// known test value
	bool bSomeParamTestValue = true;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), bInSomeParam, bSomeParamTestValue);
	testDoneDelegate.Execute();
}

void UTbNamesNamEsImplSpec::SomeSignal2SignalCb(bool bInSomeParam)
{
	// known test value
	bool bSomeParamTestValue = true;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), bInSomeParam, bSomeParamTestValue);
	testDoneDelegate.Execute();
}
#endif // WITH_DEV_AUTOMATION_TESTS
