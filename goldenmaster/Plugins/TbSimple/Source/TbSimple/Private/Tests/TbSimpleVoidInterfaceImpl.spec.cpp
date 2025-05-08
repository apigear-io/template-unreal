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

#include "Implementation/TbSimpleVoidInterface.h"
#include "TbSimpleVoidInterfaceImplFixture.h"
#include "TbSimpleTestsCommon.h"
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
		ImplFixture->GetImplementation()->Execute_FuncVoid(ImplFixture->GetImplementation().GetObject());
	});

	LatentIt("Signal.SigVoid", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSimpleVoidInterfaceSignals* TbSimpleVoidInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleVoidInterfaceSignals->OnSigVoidSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleVoidInterfaceImplHelper::SigVoidSignalCb);

		// use different test value
		TbSimpleVoidInterfaceSignals->BroadcastSigVoidSignal();
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS
