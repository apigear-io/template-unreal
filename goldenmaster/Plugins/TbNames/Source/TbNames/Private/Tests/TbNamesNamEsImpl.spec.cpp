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
#include "Implementation/TbNamesNamEs.h"
#include "TbNamesNamEsImplFixture.h"
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
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetSwitch(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.Switch.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		bool TestValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetSwitch(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnSwitchChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsImplHelper::SwitchPropertyCb);
		// use different test value
		TestValue = true;
		ImplFixture->GetImplementation()->Execute_SetSwitch(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Property.SomeProperty.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetSomeProperty(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.SomeProperty.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetSomeProperty(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnSomePropertyChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsImplHelper::SomePropertyPropertyCb);
		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->Execute_SetSomeProperty(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Property.SomePoperty2.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetSomePoperty2(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.SomePoperty2.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetSomePoperty2(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnSomePoperty2Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsImplHelper::SomePoperty2PropertyCb);
		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->Execute_SetSomePoperty2(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Operation.SomeFunction", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_SomeFunction(ImplFixture->GetImplementation().GetObject(), false);
	});

	It("Operation.SomeFunction2", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_SomeFunction2(ImplFixture->GetImplementation().GetObject(), false);
	});

	LatentIt("Signal.SomeSignal", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnSomeSignalSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsImplHelper::SomeSignalSignalCb);

		// use different test value
		bool bSomeParamTestValue = true;
		TbNamesNamEsSignals->BroadcastSomeSignalSignal(bSomeParamTestValue);
	});

	LatentIt("Signal.SomeSignal2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnSomeSignal2Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsImplHelper::SomeSignal2SignalCb);

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
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetSwitch(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbNamesNamEsImplSpec::SomePropertyPropertyCb(int32 InSomeProperty)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomeProperty, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetSomeProperty(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbNamesNamEsImplSpec::SomePoperty2PropertyCb(int32 InSomePoperty2)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomePoperty2, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetSomePoperty2(ImplFixture->GetImplementation().GetObject()), TestValue);
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
