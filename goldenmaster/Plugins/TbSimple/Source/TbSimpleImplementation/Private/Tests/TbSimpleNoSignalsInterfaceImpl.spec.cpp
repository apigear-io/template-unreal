// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "TbSimple/Implementation/TbSimpleNoSignalsInterface.h"
#include "TbSimpleNoSignalsInterfaceImplFixture.h"
#include "TbSimple/Tests/TbSimpleTestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UTbSimpleNoSignalsInterfaceImplSpec, "TbSimple.NoSignalsInterface.Impl", TbSimpleTestFilterMask);

TSharedPtr<FTbSimpleNoSignalsInterfaceImplFixture> ImplFixture;

END_DEFINE_SPEC(UTbSimpleNoSignalsInterfaceImplSpec);

void UTbSimpleNoSignalsInterfaceImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplFixture = MakeShared<FTbSimpleNoSignalsInterfaceImplFixture>();
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

	It("Property.PropBool.Default", [this]()
		{
		// Do implement test here
		bool TestValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);
	});

	LatentIt("Property.PropBool.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		bool TestValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);

		UTbSimpleNoSignalsInterfacePublisher* TbSimpleNoSignalsInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleNoSignalsInterfacePublisher->OnPropBoolChanged.AddLambda([this, TestDone](bool bInPropBool)
			{
			bool TestValue = false;
			// use different test value
			TestValue = true;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInPropBool, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = true;
		ImplFixture->GetImplementation()->SetPropBool(TestValue);
	});

	LatentIt("Property.PropBool.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		bool TestValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSimpleNoSignalsInterfacePublisher* TbSimpleNoSignalsInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleNoSignalsInterfacePublisher->OnPropBoolChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleNoSignalsInterfaceImplHelper::PropBoolPropertyCb);
		// use different test value
		TestValue = true;
		ImplFixture->GetImplementation()->SetPropBool(TestValue);
	});

	It("Property.PropInt.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);
	});

	LatentIt("Property.PropInt.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);

		UTbSimpleNoSignalsInterfacePublisher* TbSimpleNoSignalsInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleNoSignalsInterfacePublisher->OnPropIntChanged.AddLambda([this, TestDone](int32 InPropInt)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->SetPropInt(TestValue);
	});

	LatentIt("Property.PropInt.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSimpleNoSignalsInterfacePublisher* TbSimpleNoSignalsInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleNoSignalsInterfacePublisher->OnPropIntChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleNoSignalsInterfaceImplHelper::PropIntPropertyCb);
		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->SetPropInt(TestValue);
	});

	It("Operation.FuncVoid", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->FuncVoid();
	});

	It("Operation.FuncBool", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->FuncBool(false);
	});

	LatentIt("Operation.FuncBoolAsync", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		TFuture<bool> Future = ImplFixture->GetImplementation()->FuncBoolAsync(false);

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const bool& Result)
			{
			// Do implement test here
			Done.Execute();
		});
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS
