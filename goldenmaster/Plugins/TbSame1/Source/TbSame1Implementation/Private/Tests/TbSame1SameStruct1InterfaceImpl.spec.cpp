// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "TbSame1/Implementation/TbSame1SameStruct1Interface.h"
#include "TbSame1SameStruct1InterfaceImplFixture.h"
#include "TbSame1/Tests/TbSame1TestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UTbSame1SameStruct1InterfaceImplSpec, "TbSame1.SameStruct1Interface.Impl", TbSame1TestFilterMask);

TSharedPtr<FTbSame1SameStruct1InterfaceImplFixture> ImplFixture;

END_DEFINE_SPEC(UTbSame1SameStruct1InterfaceImplSpec);

void UTbSame1SameStruct1InterfaceImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplFixture = MakeShared<FTbSame1SameStruct1InterfaceImplFixture>();
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
		FTbSame1Struct1 TestValue = FTbSame1Struct1(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbSame1Struct1 TestValue = FTbSame1Struct1(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		UTbSame1SameStruct1InterfacePublisher* TbSame1SameStruct1InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSame1SameStruct1InterfacePublisher->OnProp1Changed.AddLambda([this, TestDone](const FTbSame1Struct1& InProp1)
			{
			FTbSame1Struct1 TestValue = FTbSame1Struct1();
			// use different test value
			TestValue = createTestFTbSame1Struct1();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTbSame1Struct1();
		ImplFixture->GetImplementation()->SetProp1(TestValue);
	});

	LatentIt("Property.Prop1.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbSame1Struct1 TestValue = FTbSame1Struct1(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSame1SameStruct1InterfacePublisher* TbSame1SameStruct1InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSame1SameStruct1InterfacePublisher->OnProp1ChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSame1SameStruct1InterfaceImplHelper::Prop1PropertyCb);
		// use different test value
		TestValue = createTestFTbSame1Struct1();
		ImplFixture->GetImplementation()->SetProp1(TestValue);
	});

	It("Operation.Func1", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Func1(FTbSame1Struct1());
	});

	LatentIt("Operation.Func1Async", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		TFuture<FTbSame1Struct1> Future = ImplFixture->GetImplementation()->Func1Async(FTbSame1Struct1());

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const FTbSame1Struct1& Result)
			{
			// Do implement test here
			Done.Execute();
		});
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSame1SameStruct1InterfacePublisher* TbSame1SameStruct1InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSame1SameStruct1InterfacePublisher->OnSig1Signal.AddLambda([this, TestDone](const FTbSame1Struct1& InParam1)
			{
			// known test value
			FTbSame1Struct1 Param1TestValue = createTestFTbSame1Struct1();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			TestDone.Execute();
		});

		// use different test value
		FTbSame1Struct1 Param1TestValue = createTestFTbSame1Struct1();
		TbSame1SameStruct1InterfacePublisher->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig1BP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSame1SameStruct1InterfacePublisher* TbSame1SameStruct1InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSame1SameStruct1InterfacePublisher->OnSig1SignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSame1SameStruct1InterfaceImplHelper::Sig1SignalCb);

		// use different test value
		FTbSame1Struct1 Param1TestValue = createTestFTbSame1Struct1();
		TbSame1SameStruct1InterfacePublisher->BroadcastSig1Signal(Param1TestValue);
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS
