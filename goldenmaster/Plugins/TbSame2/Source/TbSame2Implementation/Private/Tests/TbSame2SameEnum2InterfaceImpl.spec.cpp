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

#include "TbSame2/Implementation/TbSame2SameEnum2Interface.h"
#include "TbSame2SameEnum2InterfaceImplFixture.h"
#include "TbSame2/Tests/TbSame2TestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UTbSame2SameEnum2InterfaceImplSpec, "TbSame2.SameEnum2Interface.Impl", TbSame2TestFilterMask);

TSharedPtr<FTbSame2SameEnum2InterfaceImplFixture> ImplFixture;

END_DEFINE_SPEC(UTbSame2SameEnum2InterfaceImplSpec);

void UTbSame2SameEnum2InterfaceImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplFixture = MakeShared<FTbSame2SameEnum2InterfaceImplFixture>();
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
		ETbSame2Enum1 TestValue = ETbSame2Enum1::TS2E1_Value1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbSame2Enum1 TestValue = ETbSame2Enum1::TS2E1_Value1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		UTbSame2SameEnum2InterfacePublisher* TbSame2SameEnum2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSame2SameEnum2InterfacePublisher->OnProp1Changed.AddLambda([this, TestDone](ETbSame2Enum1 InProp1)
			{
			ETbSame2Enum1 TestValue = ETbSame2Enum1::TS2E1_Value1;
			// use different test value
			TestValue = ETbSame2Enum1::TS2E1_Value2;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = ETbSame2Enum1::TS2E1_Value2;
		ImplFixture->GetImplementation()->SetProp1(TestValue);
	});

	LatentIt("Property.Prop1.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbSame2Enum1 TestValue = ETbSame2Enum1::TS2E1_Value1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSame2SameEnum2InterfacePublisher* TbSame2SameEnum2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSame2SameEnum2InterfacePublisher->OnProp1ChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSame2SameEnum2InterfaceImplHelper::Prop1PropertyCb);
		// use different test value
		TestValue = ETbSame2Enum1::TS2E1_Value2;
		ImplFixture->GetImplementation()->SetProp1(TestValue);
	});

	It("Property.Prop2.Default", [this]()
		{
		// Do implement test here
		ETbSame2Enum2 TestValue = ETbSame2Enum2::TS2E2_Value1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
	});

	LatentIt("Property.Prop2.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbSame2Enum2 TestValue = ETbSame2Enum2::TS2E2_Value1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);

		UTbSame2SameEnum2InterfacePublisher* TbSame2SameEnum2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSame2SameEnum2InterfacePublisher->OnProp2Changed.AddLambda([this, TestDone](ETbSame2Enum2 InProp2)
			{
			ETbSame2Enum2 TestValue = ETbSame2Enum2::TS2E2_Value1;
			// use different test value
			TestValue = ETbSame2Enum2::TS2E2_Value2;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = ETbSame2Enum2::TS2E2_Value2;
		ImplFixture->GetImplementation()->SetProp2(TestValue);
	});

	LatentIt("Property.Prop2.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbSame2Enum2 TestValue = ETbSame2Enum2::TS2E2_Value1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSame2SameEnum2InterfacePublisher* TbSame2SameEnum2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSame2SameEnum2InterfacePublisher->OnProp2ChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSame2SameEnum2InterfaceImplHelper::Prop2PropertyCb);
		// use different test value
		TestValue = ETbSame2Enum2::TS2E2_Value2;
		ImplFixture->GetImplementation()->SetProp2(TestValue);
	});

	It("Operation.Func1", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Func1(ETbSame2Enum1::TS2E1_Value1);
	});

	LatentIt("Operation.Func1Async", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		TFuture<ETbSame2Enum1> Future = ImplFixture->GetImplementation()->Func1Async(ETbSame2Enum1::TS2E1_Value1);

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const ETbSame2Enum1& Result)
			{
			// Do implement test here
			Done.Execute();
		});
	});

	It("Operation.Func2", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Func2(ETbSame2Enum1::TS2E1_Value1, ETbSame2Enum2::TS2E2_Value1);
	});

	LatentIt("Operation.Func2Async", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		TFuture<ETbSame2Enum1> Future = ImplFixture->GetImplementation()->Func2Async(ETbSame2Enum1::TS2E1_Value1, ETbSame2Enum2::TS2E2_Value1);

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const ETbSame2Enum1& Result)
			{
			// Do implement test here
			Done.Execute();
		});
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSame2SameEnum2InterfacePublisher* TbSame2SameEnum2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSame2SameEnum2InterfacePublisher->OnSig1Signal.AddLambda([this, TestDone](ETbSame2Enum1 InParam1)
			{
			// known test value
			ETbSame2Enum1 Param1TestValue = ETbSame2Enum1::TS2E1_Value2;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			TestDone.Execute();
		});

		// use different test value
		ETbSame2Enum1 Param1TestValue = ETbSame2Enum1::TS2E1_Value2;
		TbSame2SameEnum2InterfacePublisher->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig1BP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSame2SameEnum2InterfacePublisher* TbSame2SameEnum2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSame2SameEnum2InterfacePublisher->OnSig1SignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSame2SameEnum2InterfaceImplHelper::Sig1SignalCb);

		// use different test value
		ETbSame2Enum1 Param1TestValue = ETbSame2Enum1::TS2E1_Value2;
		TbSame2SameEnum2InterfacePublisher->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSame2SameEnum2InterfacePublisher* TbSame2SameEnum2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSame2SameEnum2InterfacePublisher->OnSig2Signal.AddLambda([this, TestDone](ETbSame2Enum1 InParam1, ETbSame2Enum2 InParam2)
			{
			// known test value
			ETbSame2Enum1 Param1TestValue = ETbSame2Enum1::TS2E1_Value2;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			ETbSame2Enum2 Param2TestValue = ETbSame2Enum2::TS2E2_Value2;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
			TestDone.Execute();
		});

		// use different test value
		ETbSame2Enum1 Param1TestValue = ETbSame2Enum1::TS2E1_Value2;
		ETbSame2Enum2 Param2TestValue = ETbSame2Enum2::TS2E2_Value2;
		TbSame2SameEnum2InterfacePublisher->BroadcastSig2Signal(Param1TestValue, Param2TestValue);
	});

	LatentIt("Signal.Sig2BP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSame2SameEnum2InterfacePublisher* TbSame2SameEnum2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSame2SameEnum2InterfacePublisher->OnSig2SignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSame2SameEnum2InterfaceImplHelper::Sig2SignalCb);

		// use different test value
		ETbSame2Enum1 Param1TestValue = ETbSame2Enum1::TS2E1_Value2;
		ETbSame2Enum2 Param2TestValue = ETbSame2Enum2::TS2E2_Value2;
		TbSame2SameEnum2InterfacePublisher->BroadcastSig2Signal(Param1TestValue, Param2TestValue);
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS
