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

#include "TbNames/Implementation/TbNamesNamEs.h"
#include "TbNamesNamEsImplFixture.h"
#include "TbNames/Tests/TbNamesTestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UTbNamesNamEsImplSpec, "TbNames.NamEs.Impl", TbNamesTestFilterMask);

TSharedPtr<FTbNamesNamEsImplFixture> ImplFixture;

END_DEFINE_SPEC(UTbNamesNamEsImplSpec);

void UTbNamesNamEsImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplFixture = MakeShared<FTbNamesNamEsImplFixture>();
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

	It("Property.Switch.Default", [this]()
		{
		// Do implement test here
		bool TestValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetSwitch(), TestValue);
	});

	LatentIt("Property.Switch.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		bool TestValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetSwitch(), TestValue);

		UTbNamesNamEsPublisher* TbNamesNamEsPublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbNamesNamEsPublisher->OnSwitchChanged.AddLambda([this, TestDone](bool bInSwitch)
			{
			bool TestValue = false;
			// use different test value
			TestValue = true;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInSwitch, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetSwitch(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = true;
		ImplFixture->GetImplementation()->SetSwitch(TestValue);
	});

	LatentIt("Property.Switch.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		bool TestValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetSwitch(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbNamesNamEsPublisher* TbNamesNamEsPublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbNamesNamEsPublisher->OnSwitchChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsImplHelper::SwitchPropertyCb);
		// use different test value
		TestValue = true;
		ImplFixture->GetImplementation()->SetSwitch(TestValue);
	});

	It("Property.SomeProperty.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetSomeProperty(), TestValue);
	});

	LatentIt("Property.SomeProperty.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetSomeProperty(), TestValue);

		UTbNamesNamEsPublisher* TbNamesNamEsPublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbNamesNamEsPublisher->OnSomePropertyChanged.AddLambda([this, TestDone](int32 InSomeProperty)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomeProperty, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetSomeProperty(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->SetSomeProperty(TestValue);
	});

	LatentIt("Property.SomeProperty.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetSomeProperty(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbNamesNamEsPublisher* TbNamesNamEsPublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbNamesNamEsPublisher->OnSomePropertyChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsImplHelper::SomePropertyPropertyCb);
		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->SetSomeProperty(TestValue);
	});

	It("Property.SomePoperty2.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetSomePoperty2(), TestValue);
	});

	LatentIt("Property.SomePoperty2.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetSomePoperty2(), TestValue);

		UTbNamesNamEsPublisher* TbNamesNamEsPublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbNamesNamEsPublisher->OnSomePoperty2Changed.AddLambda([this, TestDone](int32 InSomePoperty2)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomePoperty2, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetSomePoperty2(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->SetSomePoperty2(TestValue);
	});

	LatentIt("Property.SomePoperty2.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetSomePoperty2(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbNamesNamEsPublisher* TbNamesNamEsPublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbNamesNamEsPublisher->OnSomePoperty2ChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsImplHelper::SomePoperty2PropertyCb);
		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->SetSomePoperty2(TestValue);
	});

	It("Property.EnumProperty.Default", [this]()
		{
		// Do implement test here
		ETbNamesEnum_With_Under_scores TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetEnumProperty(), TestValue);
	});

	LatentIt("Property.EnumProperty.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbNamesEnum_With_Under_scores TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetEnumProperty(), TestValue);

		UTbNamesNamEsPublisher* TbNamesNamEsPublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbNamesNamEsPublisher->OnEnumPropertyChanged.AddLambda([this, TestDone](ETbNamesEnum_With_Under_scores InEnumProperty)
			{
			ETbNamesEnum_With_Under_scores TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue;
			// use different test value
			TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_SecondValue;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InEnumProperty, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetEnumProperty(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_SecondValue;
		ImplFixture->GetImplementation()->SetEnumProperty(TestValue);
	});

	LatentIt("Property.EnumProperty.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbNamesEnum_With_Under_scores TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetEnumProperty(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbNamesNamEsPublisher* TbNamesNamEsPublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbNamesNamEsPublisher->OnEnumPropertyChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsImplHelper::EnumPropertyPropertyCb);
		// use different test value
		TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_SecondValue;
		ImplFixture->GetImplementation()->SetEnumProperty(TestValue);
	});

	It("Operation.SomeFunction", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->SomeFunction(false);
	});

	It("Operation.SomeFunction2", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->SomeFunction2(false);
	});

	LatentIt("Signal.SomeSignal", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbNamesNamEsPublisher* TbNamesNamEsPublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbNamesNamEsPublisher->OnSomeSignalSignal.AddLambda([this, TestDone](bool bInSomeParam)
			{
			// known test value
			bool bSomeParamTestValue = true;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), bInSomeParam, bSomeParamTestValue);
			TestDone.Execute();
		});

		// use different test value
		bool bSomeParamTestValue = true;
		TbNamesNamEsPublisher->BroadcastSomeSignalSignal(bSomeParamTestValue);
	});

	LatentIt("Signal.SomeSignalBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbNamesNamEsPublisher* TbNamesNamEsPublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbNamesNamEsPublisher->OnSomeSignalSignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsImplHelper::SomeSignalSignalCb);

		// use different test value
		bool bSomeParamTestValue = true;
		TbNamesNamEsPublisher->BroadcastSomeSignalSignal(bSomeParamTestValue);
	});

	LatentIt("Signal.SomeSignal2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbNamesNamEsPublisher* TbNamesNamEsPublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbNamesNamEsPublisher->OnSomeSignal2Signal.AddLambda([this, TestDone](bool bInSomeParam)
			{
			// known test value
			bool bSomeParamTestValue = true;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), bInSomeParam, bSomeParamTestValue);
			TestDone.Execute();
		});

		// use different test value
		bool bSomeParamTestValue = true;
		TbNamesNamEsPublisher->BroadcastSomeSignal2Signal(bSomeParamTestValue);
	});

	LatentIt("Signal.SomeSignal2BP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbNamesNamEsPublisher* TbNamesNamEsPublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbNamesNamEsPublisher->OnSomeSignal2SignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsImplHelper::SomeSignal2SignalCb);

		// use different test value
		bool bSomeParamTestValue = true;
		TbNamesNamEsPublisher->BroadcastSomeSignal2Signal(bSomeParamTestValue);
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS
