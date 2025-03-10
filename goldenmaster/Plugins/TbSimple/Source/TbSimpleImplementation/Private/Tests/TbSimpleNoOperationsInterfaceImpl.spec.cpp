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

#include "TbSimpleNoOperationsInterfaceImpl.spec.h"
#include "TbSimple/Implementation/TbSimpleNoOperationsInterface.h"
#include "TbSimpleNoOperationsInterfaceImplFixture.h"
#include "TbSimple/Tests/TbSimpleTestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSimpleNoOperationsInterfaceImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplFixture = MakeUnique<FTbSimpleNoOperationsInterfaceImplFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		ImplFixture->GetHelper()->SetSpec(this);
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

		testDoneDelegate = TestDone;
		UTbSimpleNoOperationsInterfaceSignals* TbSimpleNoOperationsInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleNoOperationsInterfaceSignals->OnPropBoolChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleNoOperationsInterfaceImplHelper::PropBoolPropertyCb);
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

		testDoneDelegate = TestDone;
		UTbSimpleNoOperationsInterfaceSignals* TbSimpleNoOperationsInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleNoOperationsInterfaceSignals->OnPropIntChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleNoOperationsInterfaceImplHelper::PropIntPropertyCb);
		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->SetPropInt(TestValue);
	});

	LatentIt("Signal.SigVoid", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleNoOperationsInterfaceSignals* TbSimpleNoOperationsInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleNoOperationsInterfaceSignals->OnSigVoidSignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleNoOperationsInterfaceImplHelper::SigVoidSignalCb);

		// use different test value
		TbSimpleNoOperationsInterfaceSignals->BroadcastSigVoidSignal();
	});

	LatentIt("Signal.SigBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleNoOperationsInterfaceSignals* TbSimpleNoOperationsInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleNoOperationsInterfaceSignals->OnSigBoolSignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleNoOperationsInterfaceImplHelper::SigBoolSignalCb);

		// use different test value
		bool bParamBoolTestValue = true;
		TbSimpleNoOperationsInterfaceSignals->BroadcastSigBoolSignal(bParamBoolTestValue);
	});
}

void UTbSimpleNoOperationsInterfaceImplSpec::PropBoolPropertyCb(bool bInPropBool)
{
	bool TestValue = false;
	// use different test value
	TestValue = true;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInPropBool, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleNoOperationsInterfaceImplSpec::PropIntPropertyCb(int32 InPropInt)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleNoOperationsInterfaceImplSpec::SigVoidSignalCb()
{
	// known test value
	testDoneDelegate.Execute();
}

void UTbSimpleNoOperationsInterfaceImplSpec::SigBoolSignalCb(bool bInParamBool)
{
	// known test value
	bool bParamBoolTestValue = true;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), bInParamBool, bParamBoolTestValue);
	testDoneDelegate.Execute();
}
#endif // WITH_DEV_AUTOMATION_TESTS
