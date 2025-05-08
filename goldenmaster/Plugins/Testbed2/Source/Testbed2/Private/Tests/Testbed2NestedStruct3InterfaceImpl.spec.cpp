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

#include "Implementation/Testbed2NestedStruct3Interface.h"
#include "Testbed2NestedStruct3InterfaceImplFixture.h"
#include "Testbed2TestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UTestbed2NestedStruct3InterfaceImplSpec, "Testbed2.NestedStruct3Interface.Impl", Testbed2TestFilterMask);

TSharedPtr<FTestbed2NestedStruct3InterfaceImplFixture> ImplFixture;

END_DEFINE_SPEC(UTestbed2NestedStruct3InterfaceImplSpec);

void UTestbed2NestedStruct3InterfaceImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplFixture = MakeShared<FTestbed2NestedStruct3InterfaceImplFixture>();
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

	It("Property.Prop1.Default", [this]()
		{
		// Do implement test here
		FTestbed2NestedStruct1 TestValue = FTestbed2NestedStruct1(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp1(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed2NestedStruct1 TestValue = FTestbed2NestedStruct1(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp1(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTestbed2NestedStruct3InterfaceSignals* Testbed2NestedStruct3InterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed2NestedStruct3InterfaceSignals->OnProp1Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2NestedStruct3InterfaceImplHelper::Prop1PropertyCb);
		// use different test value
		TestValue = createTestFTestbed2NestedStruct1();
		ImplFixture->GetImplementation()->Execute_SetProp1(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Property.Prop2.Default", [this]()
		{
		// Do implement test here
		FTestbed2NestedStruct2 TestValue = FTestbed2NestedStruct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp2(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.Prop2.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed2NestedStruct2 TestValue = FTestbed2NestedStruct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp2(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTestbed2NestedStruct3InterfaceSignals* Testbed2NestedStruct3InterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed2NestedStruct3InterfaceSignals->OnProp2Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2NestedStruct3InterfaceImplHelper::Prop2PropertyCb);
		// use different test value
		TestValue = createTestFTestbed2NestedStruct2();
		ImplFixture->GetImplementation()->Execute_SetProp2(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Property.Prop3.Default", [this]()
		{
		// Do implement test here
		FTestbed2NestedStruct3 TestValue = FTestbed2NestedStruct3(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp3(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.Prop3.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed2NestedStruct3 TestValue = FTestbed2NestedStruct3(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp3(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTestbed2NestedStruct3InterfaceSignals* Testbed2NestedStruct3InterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed2NestedStruct3InterfaceSignals->OnProp3Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2NestedStruct3InterfaceImplHelper::Prop3PropertyCb);
		// use different test value
		TestValue = createTestFTestbed2NestedStruct3();
		ImplFixture->GetImplementation()->Execute_SetProp3(ImplFixture->GetImplementation().GetObject(), TestValue);
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
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTestbed2NestedStruct3InterfaceSignals* Testbed2NestedStruct3InterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed2NestedStruct3InterfaceSignals->OnSig1Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2NestedStruct3InterfaceImplHelper::Sig1SignalCb);

		// use different test value
		FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
		Testbed2NestedStruct3InterfaceSignals->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTestbed2NestedStruct3InterfaceSignals* Testbed2NestedStruct3InterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed2NestedStruct3InterfaceSignals->OnSig2Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2NestedStruct3InterfaceImplHelper::Sig2SignalCb);

		// use different test value
		FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
		FTestbed2NestedStruct2 Param2TestValue = createTestFTestbed2NestedStruct2();
		Testbed2NestedStruct3InterfaceSignals->BroadcastSig2Signal(Param1TestValue, Param2TestValue);
	});

	LatentIt("Signal.Sig3", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTestbed2NestedStruct3InterfaceSignals* Testbed2NestedStruct3InterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed2NestedStruct3InterfaceSignals->OnSig3Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2NestedStruct3InterfaceImplHelper::Sig3SignalCb);

		// use different test value
		FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
		FTestbed2NestedStruct2 Param2TestValue = createTestFTestbed2NestedStruct2();
		FTestbed2NestedStruct3 Param3TestValue = createTestFTestbed2NestedStruct3();
		Testbed2NestedStruct3InterfaceSignals->BroadcastSig3Signal(Param1TestValue, Param2TestValue, Param3TestValue);
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS
