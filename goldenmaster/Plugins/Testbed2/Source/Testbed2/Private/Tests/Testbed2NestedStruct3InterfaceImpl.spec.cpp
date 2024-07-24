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
#include "Implementation/Testbed2NestedStruct3Interface.h"
#include "Testbed2NestedStruct3InterfaceImplFixture.h"
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

	It("Property.Prop1", [this]()
	{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_SetProp1(ImplFixture->GetImplementation().GetObject(), FTestbed2NestedStruct1());
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetProp1(ImplFixture->GetImplementation().GetObject()), FTestbed2NestedStruct1());
	});

	It("Property.Prop2", [this]()
	{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_SetProp2(ImplFixture->GetImplementation().GetObject(), FTestbed2NestedStruct2());
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetProp2(ImplFixture->GetImplementation().GetObject()), FTestbed2NestedStruct2());
	});

	It("Property.Prop3", [this]()
	{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_SetProp3(ImplFixture->GetImplementation().GetObject(), FTestbed2NestedStruct3());
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetProp3(ImplFixture->GetImplementation().GetObject()), FTestbed2NestedStruct3());
	});

	It("Operation.Func1", [this]()
	{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_Func1(ImplFixture->GetImplementation().GetObject(), FTestbed2NestedStruct1());
	});

	It("Operation.Func2", [this]()
	{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_Func2(ImplFixture->GetImplementation().GetObject(), FTestbed2NestedStruct1(), FTestbed2NestedStruct2());
	});

	It("Operation.Func3", [this]()
	{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_Func3(ImplFixture->GetImplementation().GetObject(), FTestbed2NestedStruct1(), FTestbed2NestedStruct2(), FTestbed2NestedStruct3());
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
	{
		testDoneDelegate = TestDone;
		UTestbed2NestedStruct3InterfaceSignals* Testbed2NestedStruct3InterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed2NestedStruct3InterfaceSignals->OnSig1Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2NestedStruct3InterfaceImplHelper::Sig1SignalCb);

		// use different test value
		FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
		Testbed2NestedStruct3InterfaceSignals->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
	{
		testDoneDelegate = TestDone;
		UTestbed2NestedStruct3InterfaceSignals* Testbed2NestedStruct3InterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed2NestedStruct3InterfaceSignals->OnSig2Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2NestedStruct3InterfaceImplHelper::Sig2SignalCb);

		// use different test value
		FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
		FTestbed2NestedStruct2 Param2TestValue = createTestFTestbed2NestedStruct2();
		Testbed2NestedStruct3InterfaceSignals->BroadcastSig2Signal(Param1TestValue, Param2TestValue);
	});

	LatentIt("Signal.Sig3", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
	{
		testDoneDelegate = TestDone;
		UTestbed2NestedStruct3InterfaceSignals* Testbed2NestedStruct3InterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed2NestedStruct3InterfaceSignals->OnSig3Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2NestedStruct3InterfaceImplHelper::Sig3SignalCb);

		// use different test value
		FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
		FTestbed2NestedStruct2 Param2TestValue = createTestFTestbed2NestedStruct2();
		FTestbed2NestedStruct3 Param3TestValue = createTestFTestbed2NestedStruct3();
		Testbed2NestedStruct3InterfaceSignals->BroadcastSig3Signal(Param1TestValue, Param2TestValue, Param3TestValue);
	});
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
