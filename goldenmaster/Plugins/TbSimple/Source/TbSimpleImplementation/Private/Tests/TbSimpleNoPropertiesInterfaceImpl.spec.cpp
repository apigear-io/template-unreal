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

#include "TbSimpleNoPropertiesInterfaceImpl.spec.h"
#include "TbSimple/Implementation/TbSimpleNoPropertiesInterface.h"
#include "TbSimpleNoPropertiesInterfaceImplFixture.h"
#include "TbSimple/Tests/TbSimpleTestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSimpleNoPropertiesInterfaceImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplFixture = MakeUnique<FTbSimpleNoPropertiesInterfaceImplFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		ImplFixture->GetHelper()->SetSpec(this);
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

	LatentIt("Signal.SigVoid", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleNoPropertiesInterfaceSignals* TbSimpleNoPropertiesInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleNoPropertiesInterfaceSignals->OnSigVoidSignal.AddLambda([this, TestDone]()
			{
			// known test value
			TestDone.Execute();
		});

		// use different test value
		TbSimpleNoPropertiesInterfaceSignals->BroadcastSigVoidSignal();
	});

	LatentIt("Signal.SigVoidBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleNoPropertiesInterfaceSignals* TbSimpleNoPropertiesInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleNoPropertiesInterfaceSignals->OnSigVoidSignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleNoPropertiesInterfaceImplHelper::SigVoidSignalCb);

		// use different test value
		TbSimpleNoPropertiesInterfaceSignals->BroadcastSigVoidSignal();
	});

	LatentIt("Signal.SigBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleNoPropertiesInterfaceSignals* TbSimpleNoPropertiesInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleNoPropertiesInterfaceSignals->OnSigBoolSignal.AddLambda([this, TestDone](bool bInParamBool)
			{
			// known test value
			bool bParamBoolTestValue = true;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), bInParamBool, bParamBoolTestValue);
			TestDone.Execute();
		});

		// use different test value
		bool bParamBoolTestValue = true;
		TbSimpleNoPropertiesInterfaceSignals->BroadcastSigBoolSignal(bParamBoolTestValue);
	});

	LatentIt("Signal.SigBoolBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleNoPropertiesInterfaceSignals* TbSimpleNoPropertiesInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleNoPropertiesInterfaceSignals->OnSigBoolSignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleNoPropertiesInterfaceImplHelper::SigBoolSignalCb);

		// use different test value
		bool bParamBoolTestValue = true;
		TbSimpleNoPropertiesInterfaceSignals->BroadcastSigBoolSignal(bParamBoolTestValue);
	});
}

void UTbSimpleNoPropertiesInterfaceImplSpec::SigVoidSignalCb()
{
	// known test value
	testDoneDelegate.Execute();
}

void UTbSimpleNoPropertiesInterfaceImplSpec::SigBoolSignalCb(bool bInParamBool)
{
	// known test value
	bool bParamBoolTestValue = true;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), bInParamBool, bParamBoolTestValue);
	testDoneDelegate.Execute();
}
#endif // WITH_DEV_AUTOMATION_TESTS
