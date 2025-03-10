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

#include "TbSame2SameEnum2InterfaceImpl.spec.h"
#include "TbSame2/Implementation/TbSame2SameEnum2Interface.h"
#include "TbSame2SameEnum2InterfaceImplFixture.h"
#include "TbSame2/Tests/TbSame2TestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSame2SameEnum2InterfaceImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplFixture = MakeUnique<FTbSame2SameEnum2InterfaceImplFixture>();
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

		UTbSame2SameEnum2InterfaceSignals* TbSame2SameEnum2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame2SameEnum2InterfaceSignals->OnProp1Changed.AddLambda([this, TestDone](ETbSame2Enum1 InProp1)
			{
			ETbSame2Enum1 TestValue = ETbSame2Enum1::TS2E1_VALUE1;
			// use different test value
			TestValue = ETbSame2Enum1::TS2E1_VALUE2;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = ETbSame2Enum1::TS2E1_VALUE2;
		ImplFixture->GetImplementation()->SetProp1(TestValue);
	});

	LatentIt("Property.Prop1.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbSame2Enum1 TestValue = ETbSame2Enum1::TS2E1_VALUE1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		testDoneDelegate = TestDone;
		UTbSame2SameEnum2InterfaceSignals* TbSame2SameEnum2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame2SameEnum2InterfaceSignals->OnProp1ChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSame2SameEnum2InterfaceImplHelper::Prop1PropertyCb);
		// use different test value
		TestValue = ETbSame2Enum1::TS2E1_VALUE2;
		ImplFixture->GetImplementation()->SetProp1(TestValue);
	});

	It("Property.Prop2.Default", [this]()
		{
		// Do implement test here
		ETbSame2Enum2 TestValue = ETbSame2Enum2::TS2E2_VALUE1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
	});

	LatentIt("Property.Prop2.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbSame2Enum2 TestValue = ETbSame2Enum2::TS2E2_VALUE1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);

		UTbSame2SameEnum2InterfaceSignals* TbSame2SameEnum2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame2SameEnum2InterfaceSignals->OnProp2Changed.AddLambda([this, TestDone](ETbSame2Enum2 InProp2)
			{
			ETbSame2Enum2 TestValue = ETbSame2Enum2::TS2E2_VALUE1;
			// use different test value
			TestValue = ETbSame2Enum2::TS2E2_VALUE2;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = ETbSame2Enum2::TS2E2_VALUE2;
		ImplFixture->GetImplementation()->SetProp2(TestValue);
	});

	LatentIt("Property.Prop2.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbSame2Enum2 TestValue = ETbSame2Enum2::TS2E2_VALUE1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);

		testDoneDelegate = TestDone;
		UTbSame2SameEnum2InterfaceSignals* TbSame2SameEnum2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame2SameEnum2InterfaceSignals->OnProp2ChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSame2SameEnum2InterfaceImplHelper::Prop2PropertyCb);
		// use different test value
		TestValue = ETbSame2Enum2::TS2E2_VALUE2;
		ImplFixture->GetImplementation()->SetProp2(TestValue);
	});

	It("Operation.Func1", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Func1(ETbSame2Enum1::TS2E1_VALUE1);
	});

	It("Operation.Func2", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Func2(ETbSame2Enum1::TS2E1_VALUE1, ETbSame2Enum2::TS2E2_VALUE1);
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSame2SameEnum2InterfaceSignals* TbSame2SameEnum2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame2SameEnum2InterfaceSignals->OnSig1Signal.AddLambda([this, TestDone](ETbSame2Enum1 InParam1)
			{
			// known test value
			ETbSame2Enum1 Param1TestValue = ETbSame2Enum1::TS2E1_VALUE2;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			TestDone.Execute();
		});

		// use different test value
		ETbSame2Enum1 Param1TestValue = ETbSame2Enum1::TS2E1_VALUE2;
		TbSame2SameEnum2InterfaceSignals->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig1BP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSame2SameEnum2InterfaceSignals* TbSame2SameEnum2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame2SameEnum2InterfaceSignals->OnSig1SignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSame2SameEnum2InterfaceImplHelper::Sig1SignalCb);

		// use different test value
		ETbSame2Enum1 Param1TestValue = ETbSame2Enum1::TS2E1_VALUE2;
		TbSame2SameEnum2InterfaceSignals->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSame2SameEnum2InterfaceSignals* TbSame2SameEnum2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame2SameEnum2InterfaceSignals->OnSig2Signal.AddLambda([this, TestDone](ETbSame2Enum1 InParam1, ETbSame2Enum2 InParam2)
			{
			// known test value
			ETbSame2Enum1 Param1TestValue = ETbSame2Enum1::TS2E1_VALUE2;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			ETbSame2Enum2 Param2TestValue = ETbSame2Enum2::TS2E2_VALUE2;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
			TestDone.Execute();
		});

		// use different test value
		ETbSame2Enum1 Param1TestValue = ETbSame2Enum1::TS2E1_VALUE2;
		ETbSame2Enum2 Param2TestValue = ETbSame2Enum2::TS2E2_VALUE2;
		TbSame2SameEnum2InterfaceSignals->BroadcastSig2Signal(Param1TestValue, Param2TestValue);
	});

	LatentIt("Signal.Sig2BP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSame2SameEnum2InterfaceSignals* TbSame2SameEnum2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame2SameEnum2InterfaceSignals->OnSig2SignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSame2SameEnum2InterfaceImplHelper::Sig2SignalCb);

		// use different test value
		ETbSame2Enum1 Param1TestValue = ETbSame2Enum1::TS2E1_VALUE2;
		ETbSame2Enum2 Param2TestValue = ETbSame2Enum2::TS2E2_VALUE2;
		TbSame2SameEnum2InterfaceSignals->BroadcastSig2Signal(Param1TestValue, Param2TestValue);
	});
}

void UTbSame2SameEnum2InterfaceImplSpec::Prop1PropertyCb(ETbSame2Enum1 InProp1)
{
	ETbSame2Enum1 TestValue = ETbSame2Enum1::TS2E1_VALUE1;
	// use different test value
	TestValue = ETbSame2Enum1::TS2E1_VALUE2;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
	testDoneDelegate.Execute();
}

void UTbSame2SameEnum2InterfaceImplSpec::Prop2PropertyCb(ETbSame2Enum2 InProp2)
{
	ETbSame2Enum2 TestValue = ETbSame2Enum2::TS2E2_VALUE1;
	// use different test value
	TestValue = ETbSame2Enum2::TS2E2_VALUE2;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
	testDoneDelegate.Execute();
}

void UTbSame2SameEnum2InterfaceImplSpec::Sig1SignalCb(ETbSame2Enum1 InParam1)
{
	// known test value
	ETbSame2Enum1 Param1TestValue = ETbSame2Enum1::TS2E1_VALUE2;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	testDoneDelegate.Execute();
}

void UTbSame2SameEnum2InterfaceImplSpec::Sig2SignalCb(ETbSame2Enum1 InParam1, ETbSame2Enum2 InParam2)
{
	// known test value
	ETbSame2Enum1 Param1TestValue = ETbSame2Enum1::TS2E1_VALUE2;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	ETbSame2Enum2 Param2TestValue = ETbSame2Enum2::TS2E2_VALUE2;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
	testDoneDelegate.Execute();
}
#endif // WITH_DEV_AUTOMATION_TESTS
