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

#include "Testbed2NestedStruct3InterfaceImpl.spec.h"
#include "Testbed2/Implementation/Testbed2NestedStruct3Interface.h"
#include "Testbed2NestedStruct3InterfaceImplFixture.h"
#include "Testbed2/Tests/Testbed2TestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTestbed2NestedStruct3InterfaceImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplFixture = MakeUnique<FTestbed2NestedStruct3InterfaceImplFixture>();
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
		FTestbed2NestedStruct1 TestValue = FTestbed2NestedStruct1(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed2NestedStruct1 TestValue = FTestbed2NestedStruct1(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		UTestbed2NestedStruct3InterfaceSignals* Testbed2NestedStruct3InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed2NestedStruct3InterfaceSignals->OnProp1Changed.AddLambda([this, TestDone](const FTestbed2NestedStruct1& InProp1)
			{
			FTestbed2NestedStruct1 TestValue = FTestbed2NestedStruct1();
			// use different test value
			TestValue = createTestFTestbed2NestedStruct1();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed2NestedStruct1();
		ImplFixture->GetImplementation()->SetProp1(TestValue);
	});

	LatentIt("Property.Prop1.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed2NestedStruct1 TestValue = FTestbed2NestedStruct1(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		testDoneDelegate = TestDone;
		UTestbed2NestedStruct3InterfaceSignals* Testbed2NestedStruct3InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed2NestedStruct3InterfaceSignals->OnProp1ChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2NestedStruct3InterfaceImplHelper::Prop1PropertyCb);
		// use different test value
		TestValue = createTestFTestbed2NestedStruct1();
		ImplFixture->GetImplementation()->SetProp1(TestValue);
	});

	It("Property.Prop2.Default", [this]()
		{
		// Do implement test here
		FTestbed2NestedStruct2 TestValue = FTestbed2NestedStruct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
	});

	LatentIt("Property.Prop2.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed2NestedStruct2 TestValue = FTestbed2NestedStruct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);

		UTestbed2NestedStruct3InterfaceSignals* Testbed2NestedStruct3InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed2NestedStruct3InterfaceSignals->OnProp2Changed.AddLambda([this, TestDone](const FTestbed2NestedStruct2& InProp2)
			{
			FTestbed2NestedStruct2 TestValue = FTestbed2NestedStruct2();
			// use different test value
			TestValue = createTestFTestbed2NestedStruct2();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed2NestedStruct2();
		ImplFixture->GetImplementation()->SetProp2(TestValue);
	});

	LatentIt("Property.Prop2.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed2NestedStruct2 TestValue = FTestbed2NestedStruct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);

		testDoneDelegate = TestDone;
		UTestbed2NestedStruct3InterfaceSignals* Testbed2NestedStruct3InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed2NestedStruct3InterfaceSignals->OnProp2ChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2NestedStruct3InterfaceImplHelper::Prop2PropertyCb);
		// use different test value
		TestValue = createTestFTestbed2NestedStruct2();
		ImplFixture->GetImplementation()->SetProp2(TestValue);
	});

	It("Property.Prop3.Default", [this]()
		{
		// Do implement test here
		FTestbed2NestedStruct3 TestValue = FTestbed2NestedStruct3(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp3(), TestValue);
	});

	LatentIt("Property.Prop3.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed2NestedStruct3 TestValue = FTestbed2NestedStruct3(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp3(), TestValue);

		UTestbed2NestedStruct3InterfaceSignals* Testbed2NestedStruct3InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed2NestedStruct3InterfaceSignals->OnProp3Changed.AddLambda([this, TestDone](const FTestbed2NestedStruct3& InProp3)
			{
			FTestbed2NestedStruct3 TestValue = FTestbed2NestedStruct3();
			// use different test value
			TestValue = createTestFTestbed2NestedStruct3();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp3(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed2NestedStruct3();
		ImplFixture->GetImplementation()->SetProp3(TestValue);
	});

	LatentIt("Property.Prop3.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed2NestedStruct3 TestValue = FTestbed2NestedStruct3(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp3(), TestValue);

		testDoneDelegate = TestDone;
		UTestbed2NestedStruct3InterfaceSignals* Testbed2NestedStruct3InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed2NestedStruct3InterfaceSignals->OnProp3ChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2NestedStruct3InterfaceImplHelper::Prop3PropertyCb);
		// use different test value
		TestValue = createTestFTestbed2NestedStruct3();
		ImplFixture->GetImplementation()->SetProp3(TestValue);
	});

	It("Operation.Func1", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Func1(FTestbed2NestedStruct1());
	});

	It("Operation.Func2", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Func2(FTestbed2NestedStruct1(), FTestbed2NestedStruct2());
	});

	It("Operation.Func3", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Func3(FTestbed2NestedStruct1(), FTestbed2NestedStruct2(), FTestbed2NestedStruct3());
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed2NestedStruct3InterfaceSignals* Testbed2NestedStruct3InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed2NestedStruct3InterfaceSignals->OnSig1Signal.AddLambda([this, TestDone](const FTestbed2NestedStruct1& InParam1)
			{
			// known test value
			FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			TestDone.Execute();
		});

		// use different test value
		FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
		Testbed2NestedStruct3InterfaceSignals->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig1BP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTestbed2NestedStruct3InterfaceSignals* Testbed2NestedStruct3InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed2NestedStruct3InterfaceSignals->OnSig1SignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2NestedStruct3InterfaceImplHelper::Sig1SignalCb);

		// use different test value
		FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
		Testbed2NestedStruct3InterfaceSignals->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed2NestedStruct3InterfaceSignals* Testbed2NestedStruct3InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed2NestedStruct3InterfaceSignals->OnSig2Signal.AddLambda([this, TestDone](const FTestbed2NestedStruct1& InParam1, const FTestbed2NestedStruct2& InParam2)
			{
			// known test value
			FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			FTestbed2NestedStruct2 Param2TestValue = createTestFTestbed2NestedStruct2();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
			TestDone.Execute();
		});

		// use different test value
		FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
		FTestbed2NestedStruct2 Param2TestValue = createTestFTestbed2NestedStruct2();
		Testbed2NestedStruct3InterfaceSignals->BroadcastSig2Signal(Param1TestValue, Param2TestValue);
	});

	LatentIt("Signal.Sig2BP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTestbed2NestedStruct3InterfaceSignals* Testbed2NestedStruct3InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed2NestedStruct3InterfaceSignals->OnSig2SignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2NestedStruct3InterfaceImplHelper::Sig2SignalCb);

		// use different test value
		FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
		FTestbed2NestedStruct2 Param2TestValue = createTestFTestbed2NestedStruct2();
		Testbed2NestedStruct3InterfaceSignals->BroadcastSig2Signal(Param1TestValue, Param2TestValue);
	});

	LatentIt("Signal.Sig3", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed2NestedStruct3InterfaceSignals* Testbed2NestedStruct3InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed2NestedStruct3InterfaceSignals->OnSig3Signal.AddLambda([this, TestDone](const FTestbed2NestedStruct1& InParam1, const FTestbed2NestedStruct2& InParam2, const FTestbed2NestedStruct3& InParam3)
			{
			// known test value
			FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			FTestbed2NestedStruct2 Param2TestValue = createTestFTestbed2NestedStruct2();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
			FTestbed2NestedStruct3 Param3TestValue = createTestFTestbed2NestedStruct3();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam3, Param3TestValue);
			TestDone.Execute();
		});

		// use different test value
		FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
		FTestbed2NestedStruct2 Param2TestValue = createTestFTestbed2NestedStruct2();
		FTestbed2NestedStruct3 Param3TestValue = createTestFTestbed2NestedStruct3();
		Testbed2NestedStruct3InterfaceSignals->BroadcastSig3Signal(Param1TestValue, Param2TestValue, Param3TestValue);
	});

	LatentIt("Signal.Sig3BP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTestbed2NestedStruct3InterfaceSignals* Testbed2NestedStruct3InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed2NestedStruct3InterfaceSignals->OnSig3SignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2NestedStruct3InterfaceImplHelper::Sig3SignalCb);

		// use different test value
		FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
		FTestbed2NestedStruct2 Param2TestValue = createTestFTestbed2NestedStruct2();
		FTestbed2NestedStruct3 Param3TestValue = createTestFTestbed2NestedStruct3();
		Testbed2NestedStruct3InterfaceSignals->BroadcastSig3Signal(Param1TestValue, Param2TestValue, Param3TestValue);
	});
}

void UTestbed2NestedStruct3InterfaceImplSpec::Prop1PropertyCb(const FTestbed2NestedStruct1& InProp1)
{
	FTestbed2NestedStruct1 TestValue = FTestbed2NestedStruct1();
	// use different test value
	TestValue = createTestFTestbed2NestedStruct1();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
	testDoneDelegate.Execute();
}

void UTestbed2NestedStruct3InterfaceImplSpec::Prop2PropertyCb(const FTestbed2NestedStruct2& InProp2)
{
	FTestbed2NestedStruct2 TestValue = FTestbed2NestedStruct2();
	// use different test value
	TestValue = createTestFTestbed2NestedStruct2();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
	testDoneDelegate.Execute();
}

void UTestbed2NestedStruct3InterfaceImplSpec::Prop3PropertyCb(const FTestbed2NestedStruct3& InProp3)
{
	FTestbed2NestedStruct3 TestValue = FTestbed2NestedStruct3();
	// use different test value
	TestValue = createTestFTestbed2NestedStruct3();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp3(), TestValue);
	testDoneDelegate.Execute();
}

void UTestbed2NestedStruct3InterfaceImplSpec::Sig1SignalCb(const FTestbed2NestedStruct1& InParam1)
{
	// known test value
	FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	testDoneDelegate.Execute();
}

void UTestbed2NestedStruct3InterfaceImplSpec::Sig2SignalCb(const FTestbed2NestedStruct1& InParam1, const FTestbed2NestedStruct2& InParam2)
{
	// known test value
	FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	FTestbed2NestedStruct2 Param2TestValue = createTestFTestbed2NestedStruct2();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
	testDoneDelegate.Execute();
}

void UTestbed2NestedStruct3InterfaceImplSpec::Sig3SignalCb(const FTestbed2NestedStruct1& InParam1, const FTestbed2NestedStruct2& InParam2, const FTestbed2NestedStruct3& InParam3)
{
	// known test value
	FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	FTestbed2NestedStruct2 Param2TestValue = createTestFTestbed2NestedStruct2();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
	FTestbed2NestedStruct3 Param3TestValue = createTestFTestbed2NestedStruct3();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam3, Param3TestValue);
	testDoneDelegate.Execute();
}
#endif // WITH_DEV_AUTOMATION_TESTS
