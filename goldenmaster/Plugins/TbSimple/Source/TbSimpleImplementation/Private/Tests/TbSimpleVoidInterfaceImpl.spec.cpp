// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "TbSimple/Implementation/TbSimpleVoidInterface.h"
#include "TbSimpleVoidInterfaceImplFixture.h"
#include "TbSimple/Tests/TbSimpleTestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UTbSimpleVoidInterfaceImplSpec, "TbSimple.VoidInterface.Impl", TbSimpleTestFilterMask);

TSharedPtr<FTbSimpleVoidInterfaceImplFixture> ImplFixture;

END_DEFINE_SPEC(UTbSimpleVoidInterfaceImplSpec);

void UTbSimpleVoidInterfaceImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplFixture = MakeShared<FTbSimpleVoidInterfaceImplFixture>();
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

	LatentIt("Signal.SigVoid", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleVoidInterfacePublisher* TbSimpleVoidInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleVoidInterfacePublisher->OnSigVoidSignal.AddLambda([this, TestDone]()
			{
			// known test value
			TestDone.Execute();
		});

		// use different test value
		TbSimpleVoidInterfacePublisher->BroadcastSigVoidSignal();
	});

	LatentIt("Signal.SigVoidBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSimpleVoidInterfacePublisher* TbSimpleVoidInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleVoidInterfacePublisher->OnSigVoidSignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleVoidInterfaceImplHelper::SigVoidSignalCb);

		// use different test value
		TbSimpleVoidInterfacePublisher->BroadcastSigVoidSignal();
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS
