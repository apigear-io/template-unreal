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

#include "TbSame2SameEnum1InterfaceImpl.spec.h"
#include "TbSame2/Implementation/TbSame2SameEnum1Interface.h"
#include "TbSame2SameEnum1InterfaceImplFixture.h"
#include "TbSame2/Tests/TbSame2TestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSame2SameEnum1InterfaceImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplFixture = MakeUnique<FTbSame2SameEnum1InterfaceImplFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		ImplFixture->GetHelper()->SetSpec(this);
	});

	AfterEach([this]()
		{
		ImplFixture.Reset();
	});

	It("Property.Prop1.Default", [this]()
		{
		// Do implement test here
		ETbSame2Enum1 TestValue = ETbSame2Enum1::TS2E1_VALUE1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbSame2Enum1 TestValue = ETbSame2Enum1::TS2E1_VALUE1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		testDoneDelegate = TestDone;
		UTbSame2SameEnum1InterfaceSignals* TbSame2SameEnum1InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame2SameEnum1InterfaceSignals->OnProp1Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSame2SameEnum1InterfaceImplHelper::Prop1PropertyCb);
		// use different test value
		TestValue = ETbSame2Enum1::TS2E1_VALUE2;
		ImplFixture->GetImplementation()->SetProp1(TestValue);
	});

	It("Operation.Func1", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Func1(ETbSame2Enum1::TS2E1_VALUE1);
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSame2SameEnum1InterfaceSignals* TbSame2SameEnum1InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame2SameEnum1InterfaceSignals->OnSig1Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSame2SameEnum1InterfaceImplHelper::Sig1SignalCb);

		// use different test value
		ETbSame2Enum1 Param1TestValue = ETbSame2Enum1::TS2E1_VALUE2;
		TbSame2SameEnum1InterfaceSignals->BroadcastSig1Signal(Param1TestValue);
	});
}

void UTbSame2SameEnum1InterfaceImplSpec::Prop1PropertyCb(ETbSame2Enum1 InProp1)
{
	ETbSame2Enum1 TestValue = ETbSame2Enum1::TS2E1_VALUE1;
	// use different test value
	TestValue = ETbSame2Enum1::TS2E1_VALUE2;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
	testDoneDelegate.Execute();
}

void UTbSame2SameEnum1InterfaceImplSpec::Sig1SignalCb(ETbSame2Enum1 InParam1)
{
	// known test value
	ETbSame2Enum1 Param1TestValue = ETbSame2Enum1::TS2E1_VALUE2;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	testDoneDelegate.Execute();
}
#endif // WITH_DEV_AUTOMATION_TESTS
