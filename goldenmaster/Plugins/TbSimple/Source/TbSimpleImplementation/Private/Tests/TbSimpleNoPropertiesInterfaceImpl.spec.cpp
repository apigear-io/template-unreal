// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "TbSimple/Implementation/TbSimpleNoPropertiesInterface.h"
#include "TbSimpleNoPropertiesInterfaceImplFixture.h"
#include "TbSimple/Tests/TbSimpleTestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UTbSimpleNoPropertiesInterfaceImplSpec, "TbSimple.NoPropertiesInterface.Impl", TbSimpleTestFilterMask);

TSharedPtr<FTbSimpleNoPropertiesInterfaceImplFixture> ImplFixture;

END_DEFINE_SPEC(UTbSimpleNoPropertiesInterfaceImplSpec);

void UTbSimpleNoPropertiesInterfaceImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplFixture = MakeShared<FTbSimpleNoPropertiesInterfaceImplFixture>();
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

	LatentIt("Signal.SigVoid", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleNoPropertiesInterfacePublisher* TbSimpleNoPropertiesInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleNoPropertiesInterfacePublisher->OnSigVoidSignal.AddLambda([this, TestDone]()
			{
			// known test value
			TestDone.Execute();
		});

		// use different test value
		TbSimpleNoPropertiesInterfacePublisher->BroadcastSigVoidSignal();
	});

	LatentIt("Signal.SigVoidBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSimpleNoPropertiesInterfacePublisher* TbSimpleNoPropertiesInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleNoPropertiesInterfacePublisher->OnSigVoidSignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleNoPropertiesInterfaceImplHelper::SigVoidSignalCb);

		// use different test value
		TbSimpleNoPropertiesInterfacePublisher->BroadcastSigVoidSignal();
	});

	LatentIt("Signal.SigBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleNoPropertiesInterfacePublisher* TbSimpleNoPropertiesInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleNoPropertiesInterfacePublisher->OnSigBoolSignal.AddLambda([this, TestDone](bool bInParamBool)
			{
			// known test value
			bool bParamBoolTestValue = true;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), bInParamBool, bParamBoolTestValue);
			TestDone.Execute();
		});

		// use different test value
		bool bParamBoolTestValue = true;
		TbSimpleNoPropertiesInterfacePublisher->BroadcastSigBoolSignal(bParamBoolTestValue);
	});

	LatentIt("Signal.SigBoolBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSimpleNoPropertiesInterfacePublisher* TbSimpleNoPropertiesInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleNoPropertiesInterfacePublisher->OnSigBoolSignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleNoPropertiesInterfaceImplHelper::SigBoolSignalCb);

		// use different test value
		bool bParamBoolTestValue = true;
		TbSimpleNoPropertiesInterfacePublisher->BroadcastSigBoolSignal(bParamBoolTestValue);
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS
