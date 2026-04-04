// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "TbStructArray/Implementation/TbStructArrayStructArrayFieldInterface.h"
#include "TbStructArrayStructArrayFieldInterfaceImplFixture.h"
#include "TbStructArray/Tests/TbStructArrayTestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UTbStructArrayStructArrayFieldInterfaceImplSpec, "TbStructArray.StructArrayFieldInterface.Impl", TbStructArrayTestFilterMask);

TSharedPtr<FTbStructArrayStructArrayFieldInterfaceImplFixture> ImplFixture;

END_DEFINE_SPEC(UTbStructArrayStructArrayFieldInterfaceImplSpec);

void UTbStructArrayStructArrayFieldInterfaceImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplFixture = MakeShared<FTbStructArrayStructArrayFieldInterfaceImplFixture>();
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

	It("Property.PropStructArray.Default", [this]()
		{
		// Do implement test here
		FTbStructArrayStructWithArrayOfStructs TestValue = FTbStructArrayStructWithArrayOfStructs(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropStructArray(), TestValue);
	});

	LatentIt("Property.PropStructArray.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbStructArrayStructWithArrayOfStructs TestValue = FTbStructArrayStructWithArrayOfStructs(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropStructArray(), TestValue);

		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbStructArrayStructArrayFieldInterfacePublisher->OnPropStructArrayChanged.AddLambda([this, TestDone](const FTbStructArrayStructWithArrayOfStructs& InPropStructArray)
			{
			FTbStructArrayStructWithArrayOfStructs TestValue = FTbStructArrayStructWithArrayOfStructs();
			// use different test value
			TestValue = createTestFTbStructArrayStructWithArrayOfStructs();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropStructArray, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropStructArray(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTbStructArrayStructWithArrayOfStructs();
		ImplFixture->GetImplementation()->SetPropStructArray(TestValue);
	});

	LatentIt("Property.PropStructArray.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbStructArrayStructWithArrayOfStructs TestValue = FTbStructArrayStructWithArrayOfStructs(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropStructArray(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbStructArrayStructArrayFieldInterfacePublisher->OnPropStructArrayChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbStructArrayStructArrayFieldInterfaceImplHelper::PropStructArrayPropertyCb);
		// use different test value
		TestValue = createTestFTbStructArrayStructWithArrayOfStructs();
		ImplFixture->GetImplementation()->SetPropStructArray(TestValue);
	});

	It("Property.PropEnumArray.Default", [this]()
		{
		// Do implement test here
		FTbStructArrayStructWithArrayOfEnums TestValue = FTbStructArrayStructWithArrayOfEnums(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropEnumArray(), TestValue);
	});

	LatentIt("Property.PropEnumArray.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbStructArrayStructWithArrayOfEnums TestValue = FTbStructArrayStructWithArrayOfEnums(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropEnumArray(), TestValue);

		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbStructArrayStructArrayFieldInterfacePublisher->OnPropEnumArrayChanged.AddLambda([this, TestDone](const FTbStructArrayStructWithArrayOfEnums& InPropEnumArray)
			{
			FTbStructArrayStructWithArrayOfEnums TestValue = FTbStructArrayStructWithArrayOfEnums();
			// use different test value
			TestValue = createTestFTbStructArrayStructWithArrayOfEnums();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnumArray, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropEnumArray(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTbStructArrayStructWithArrayOfEnums();
		ImplFixture->GetImplementation()->SetPropEnumArray(TestValue);
	});

	LatentIt("Property.PropEnumArray.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbStructArrayStructWithArrayOfEnums TestValue = FTbStructArrayStructWithArrayOfEnums(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropEnumArray(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbStructArrayStructArrayFieldInterfacePublisher->OnPropEnumArrayChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbStructArrayStructArrayFieldInterfaceImplHelper::PropEnumArrayPropertyCb);
		// use different test value
		TestValue = createTestFTbStructArrayStructWithArrayOfEnums();
		ImplFixture->GetImplementation()->SetPropEnumArray(TestValue);
	});

	It("Property.PropIntArray.Default", [this]()
		{
		// Do implement test here
		FTbStructArrayStructWithArrayOfInts TestValue = FTbStructArrayStructWithArrayOfInts(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropIntArray(), TestValue);
	});

	LatentIt("Property.PropIntArray.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbStructArrayStructWithArrayOfInts TestValue = FTbStructArrayStructWithArrayOfInts(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropIntArray(), TestValue);

		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbStructArrayStructArrayFieldInterfacePublisher->OnPropIntArrayChanged.AddLambda([this, TestDone](const FTbStructArrayStructWithArrayOfInts& InPropIntArray)
			{
			FTbStructArrayStructWithArrayOfInts TestValue = FTbStructArrayStructWithArrayOfInts();
			// use different test value
			TestValue = createTestFTbStructArrayStructWithArrayOfInts();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropIntArray, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropIntArray(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTbStructArrayStructWithArrayOfInts();
		ImplFixture->GetImplementation()->SetPropIntArray(TestValue);
	});

	LatentIt("Property.PropIntArray.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbStructArrayStructWithArrayOfInts TestValue = FTbStructArrayStructWithArrayOfInts(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropIntArray(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbStructArrayStructArrayFieldInterfacePublisher->OnPropIntArrayChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbStructArrayStructArrayFieldInterfaceImplHelper::PropIntArrayPropertyCb);
		// use different test value
		TestValue = createTestFTbStructArrayStructWithArrayOfInts();
		ImplFixture->GetImplementation()->SetPropIntArray(TestValue);
	});

	It("Property.PropMixed.Default", [this]()
		{
		// Do implement test here
		FTbStructArrayMixedStruct TestValue = FTbStructArrayMixedStruct(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropMixed(), TestValue);
	});

	LatentIt("Property.PropMixed.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbStructArrayMixedStruct TestValue = FTbStructArrayMixedStruct(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropMixed(), TestValue);

		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbStructArrayStructArrayFieldInterfacePublisher->OnPropMixedChanged.AddLambda([this, TestDone](const FTbStructArrayMixedStruct& InPropMixed)
			{
			FTbStructArrayMixedStruct TestValue = FTbStructArrayMixedStruct();
			// use different test value
			TestValue = createTestFTbStructArrayMixedStruct();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropMixed, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropMixed(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTbStructArrayMixedStruct();
		ImplFixture->GetImplementation()->SetPropMixed(TestValue);
	});

	LatentIt("Property.PropMixed.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbStructArrayMixedStruct TestValue = FTbStructArrayMixedStruct(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropMixed(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbStructArrayStructArrayFieldInterfacePublisher->OnPropMixedChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbStructArrayStructArrayFieldInterfaceImplHelper::PropMixedPropertyCb);
		// use different test value
		TestValue = createTestFTbStructArrayMixedStruct();
		ImplFixture->GetImplementation()->SetPropMixed(TestValue);
	});

	It("Operation.FuncMixed", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->FuncMixed(FTbStructArrayMixedStruct());
	});

	LatentIt("Operation.FuncMixedAsync", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		TFuture<FTbStructArrayMixedStruct> Future = ImplFixture->GetImplementation()->FuncMixedAsync(FTbStructArrayMixedStruct());

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const FTbStructArrayMixedStruct& Result)
			{
			// Do implement test here
			Done.Execute();
		});
	});

	It("Operation.FuncStructArray", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->FuncStructArray(FTbStructArrayStructWithArrayOfStructs());
	});

	LatentIt("Operation.FuncStructArrayAsync", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		TFuture<FTbStructArrayStructWithArrayOfStructs> Future = ImplFixture->GetImplementation()->FuncStructArrayAsync(FTbStructArrayStructWithArrayOfStructs());

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const FTbStructArrayStructWithArrayOfStructs& Result)
			{
			// Do implement test here
			Done.Execute();
		});
	});

	LatentIt("Signal.SigMixed", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbStructArrayStructArrayFieldInterfacePublisher->OnSigMixedSignal.AddLambda([this, TestDone](const FTbStructArrayMixedStruct& InParamMixed)
			{
			// known test value
			FTbStructArrayMixedStruct ParamMixedTestValue = createTestFTbStructArrayMixedStruct();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamMixed, ParamMixedTestValue);
			TestDone.Execute();
		});

		// use different test value
		FTbStructArrayMixedStruct ParamMixedTestValue = createTestFTbStructArrayMixedStruct();
		TbStructArrayStructArrayFieldInterfacePublisher->BroadcastSigMixedSignal(ParamMixedTestValue);
	});

	LatentIt("Signal.SigMixedBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbStructArrayStructArrayFieldInterfacePublisher->OnSigMixedSignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbStructArrayStructArrayFieldInterfaceImplHelper::SigMixedSignalCb);

		// use different test value
		FTbStructArrayMixedStruct ParamMixedTestValue = createTestFTbStructArrayMixedStruct();
		TbStructArrayStructArrayFieldInterfacePublisher->BroadcastSigMixedSignal(ParamMixedTestValue);
	});

	LatentIt("Signal.SigStructArray", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbStructArrayStructArrayFieldInterfacePublisher->OnSigStructArraySignal.AddLambda([this, TestDone](const FTbStructArrayStructWithArrayOfStructs& InParamPoints)
			{
			// known test value
			FTbStructArrayStructWithArrayOfStructs ParamPointsTestValue = createTestFTbStructArrayStructWithArrayOfStructs();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamPoints, ParamPointsTestValue);
			TestDone.Execute();
		});

		// use different test value
		FTbStructArrayStructWithArrayOfStructs ParamPointsTestValue = createTestFTbStructArrayStructWithArrayOfStructs();
		TbStructArrayStructArrayFieldInterfacePublisher->BroadcastSigStructArraySignal(ParamPointsTestValue);
	});

	LatentIt("Signal.SigStructArrayBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbStructArrayStructArrayFieldInterfacePublisher->OnSigStructArraySignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbStructArrayStructArrayFieldInterfaceImplHelper::SigStructArraySignalCb);

		// use different test value
		FTbStructArrayStructWithArrayOfStructs ParamPointsTestValue = createTestFTbStructArrayStructWithArrayOfStructs();
		TbStructArrayStructArrayFieldInterfacePublisher->BroadcastSigStructArraySignal(ParamPointsTestValue);
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS
