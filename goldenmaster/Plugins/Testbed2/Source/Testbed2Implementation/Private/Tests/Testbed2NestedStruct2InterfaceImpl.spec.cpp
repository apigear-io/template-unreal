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

#include "Testbed2/Implementation/Testbed2NestedStruct2Interface.h"
#include "Testbed2NestedStruct2InterfaceImplFixture.h"
#include "Testbed2/Tests/Testbed2TestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UTestbed2NestedStruct2InterfaceImplSpec, "Testbed2.NestedStruct2Interface.Impl", Testbed2TestFilterMask);

TSharedPtr<FTestbed2NestedStruct2InterfaceImplFixture> ImplFixture;

END_DEFINE_SPEC(UTestbed2NestedStruct2InterfaceImplSpec);

void UTestbed2NestedStruct2InterfaceImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplFixture = MakeShared<FTestbed2NestedStruct2InterfaceImplFixture>();
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
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed2NestedStruct1 TestValue = FTestbed2NestedStruct1(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		UTestbed2NestedStruct2InterfacePublisher* Testbed2NestedStruct2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2NestedStruct2InterfacePublisher->OnProp1Changed.AddLambda([this, TestDone](const FTestbed2NestedStruct1& InProp1)
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

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTestbed2NestedStruct2InterfacePublisher* Testbed2NestedStruct2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2NestedStruct2InterfacePublisher->OnProp1ChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2NestedStruct2InterfaceImplHelper::Prop1PropertyCb);
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

		UTestbed2NestedStruct2InterfacePublisher* Testbed2NestedStruct2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2NestedStruct2InterfacePublisher->OnProp2Changed.AddLambda([this, TestDone](const FTestbed2NestedStruct2& InProp2)
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

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTestbed2NestedStruct2InterfacePublisher* Testbed2NestedStruct2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2NestedStruct2InterfacePublisher->OnProp2ChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2NestedStruct2InterfaceImplHelper::Prop2PropertyCb);
		// use different test value
		TestValue = createTestFTestbed2NestedStruct2();
		ImplFixture->GetImplementation()->SetProp2(TestValue);
	});

	It("Operation.Func1", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Func1(FTestbed2NestedStruct1());
	});

	LatentIt("Operation.Func1Async", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		TFuture<FTestbed2NestedStruct1> Future = ImplFixture->GetImplementation()->Func1Async(FTestbed2NestedStruct1());

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const FTestbed2NestedStruct1& Result)
			{
			// Do implement test here
			Done.Execute();
		});
	});

	It("Operation.Func2", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Func2(FTestbed2NestedStruct1(), FTestbed2NestedStruct2());
	});

	LatentIt("Operation.Func2Async", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		TFuture<FTestbed2NestedStruct1> Future = ImplFixture->GetImplementation()->Func2Async(FTestbed2NestedStruct1(), FTestbed2NestedStruct2());

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const FTestbed2NestedStruct1& Result)
			{
			// Do implement test here
			Done.Execute();
		});
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed2NestedStruct2InterfacePublisher* Testbed2NestedStruct2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2NestedStruct2InterfacePublisher->OnSig1Signal.AddLambda([this, TestDone](const FTestbed2NestedStruct1& InParam1)
			{
			// known test value
			FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			TestDone.Execute();
		});

		// use different test value
		FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
		Testbed2NestedStruct2InterfacePublisher->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig1BP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTestbed2NestedStruct2InterfacePublisher* Testbed2NestedStruct2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2NestedStruct2InterfacePublisher->OnSig1SignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2NestedStruct2InterfaceImplHelper::Sig1SignalCb);

		// use different test value
		FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
		Testbed2NestedStruct2InterfacePublisher->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed2NestedStruct2InterfacePublisher* Testbed2NestedStruct2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2NestedStruct2InterfacePublisher->OnSig2Signal.AddLambda([this, TestDone](const FTestbed2NestedStruct1& InParam1, const FTestbed2NestedStruct2& InParam2)
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
		Testbed2NestedStruct2InterfacePublisher->BroadcastSig2Signal(Param1TestValue, Param2TestValue);
	});

	LatentIt("Signal.Sig2BP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTestbed2NestedStruct2InterfacePublisher* Testbed2NestedStruct2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2NestedStruct2InterfacePublisher->OnSig2SignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2NestedStruct2InterfaceImplHelper::Sig2SignalCb);

		// use different test value
		FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
		FTestbed2NestedStruct2 Param2TestValue = createTestFTestbed2NestedStruct2();
		Testbed2NestedStruct2InterfacePublisher->BroadcastSig2Signal(Param1TestValue, Param2TestValue);
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS
