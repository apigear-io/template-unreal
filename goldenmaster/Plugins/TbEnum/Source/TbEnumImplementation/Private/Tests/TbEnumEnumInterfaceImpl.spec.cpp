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

#include "TbEnum/Implementation/TbEnumEnumInterface.h"
#include "TbEnumEnumInterfaceImplFixture.h"
#include "TbEnum/Tests/TbEnumTestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UTbEnumEnumInterfaceImplSpec, "TbEnum.EnumInterface.Impl", TbEnumTestFilterMask);

TSharedPtr<FTbEnumEnumInterfaceImplFixture> ImplFixture;

END_DEFINE_SPEC(UTbEnumEnumInterfaceImplSpec);

void UTbEnumEnumInterfaceImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplFixture = MakeShared<FTbEnumEnumInterfaceImplFixture>();
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

	It("Property.Prop0.Default", [this]()
		{
		// Do implement test here
		ETbEnumEnum0 TestValue = ETbEnumEnum0::TEE0_Value0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp0(), TestValue);
	});

	LatentIt("Property.Prop0.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum0 TestValue = ETbEnumEnum0::TEE0_Value0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp0(), TestValue);

		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnProp0Changed.AddLambda([this, TestDone](ETbEnumEnum0 InProp0)
			{
			ETbEnumEnum0 TestValue = ETbEnumEnum0::TEE0_Value0;
			// use different test value
			TestValue = ETbEnumEnum0::TEE0_Value1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp0, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp0(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = ETbEnumEnum0::TEE0_Value1;
		ImplFixture->GetImplementation()->SetProp0(TestValue);
	});

	LatentIt("Property.Prop0.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum0 TestValue = ETbEnumEnum0::TEE0_Value0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp0(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnProp0ChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceImplHelper::Prop0PropertyCb);
		// use different test value
		TestValue = ETbEnumEnum0::TEE0_Value1;
		ImplFixture->GetImplementation()->SetProp0(TestValue);
	});

	It("Property.Prop1.Default", [this]()
		{
		// Do implement test here
		ETbEnumEnum1 TestValue = ETbEnumEnum1::TEE1_Value1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum1 TestValue = ETbEnumEnum1::TEE1_Value1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnProp1Changed.AddLambda([this, TestDone](ETbEnumEnum1 InProp1)
			{
			ETbEnumEnum1 TestValue = ETbEnumEnum1::TEE1_Value1;
			// use different test value
			TestValue = ETbEnumEnum1::TEE1_Value2;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = ETbEnumEnum1::TEE1_Value2;
		ImplFixture->GetImplementation()->SetProp1(TestValue);
	});

	LatentIt("Property.Prop1.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum1 TestValue = ETbEnumEnum1::TEE1_Value1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnProp1ChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceImplHelper::Prop1PropertyCb);
		// use different test value
		TestValue = ETbEnumEnum1::TEE1_Value2;
		ImplFixture->GetImplementation()->SetProp1(TestValue);
	});

	It("Property.Prop2.Default", [this]()
		{
		// Do implement test here
		ETbEnumEnum2 TestValue = ETbEnumEnum2::TEE2_Value2; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
	});

	LatentIt("Property.Prop2.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum2 TestValue = ETbEnumEnum2::TEE2_Value2; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);

		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnProp2Changed.AddLambda([this, TestDone](ETbEnumEnum2 InProp2)
			{
			ETbEnumEnum2 TestValue = ETbEnumEnum2::TEE2_Value2;
			// use different test value
			TestValue = ETbEnumEnum2::TEE2_Value1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = ETbEnumEnum2::TEE2_Value1;
		ImplFixture->GetImplementation()->SetProp2(TestValue);
	});

	LatentIt("Property.Prop2.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum2 TestValue = ETbEnumEnum2::TEE2_Value2; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnProp2ChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceImplHelper::Prop2PropertyCb);
		// use different test value
		TestValue = ETbEnumEnum2::TEE2_Value1;
		ImplFixture->GetImplementation()->SetProp2(TestValue);
	});

	It("Property.Prop3.Default", [this]()
		{
		// Do implement test here
		ETbEnumEnum3 TestValue = ETbEnumEnum3::TEE3_Value3; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp3(), TestValue);
	});

	LatentIt("Property.Prop3.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum3 TestValue = ETbEnumEnum3::TEE3_Value3; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp3(), TestValue);

		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnProp3Changed.AddLambda([this, TestDone](ETbEnumEnum3 InProp3)
			{
			ETbEnumEnum3 TestValue = ETbEnumEnum3::TEE3_Value3;
			// use different test value
			TestValue = ETbEnumEnum3::TEE3_Value2;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp3(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = ETbEnumEnum3::TEE3_Value2;
		ImplFixture->GetImplementation()->SetProp3(TestValue);
	});

	LatentIt("Property.Prop3.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum3 TestValue = ETbEnumEnum3::TEE3_Value3; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp3(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnProp3ChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceImplHelper::Prop3PropertyCb);
		// use different test value
		TestValue = ETbEnumEnum3::TEE3_Value2;
		ImplFixture->GetImplementation()->SetProp3(TestValue);
	});

	It("Operation.Func0", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Func0(ETbEnumEnum0::TEE0_Value0);
	});

	It("Operation.Func1", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Func1(ETbEnumEnum1::TEE1_Value1);
	});

	It("Operation.Func2", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Func2(ETbEnumEnum2::TEE2_Value2);
	});

	It("Operation.Func3", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Func3(ETbEnumEnum3::TEE3_Value3);
	});

	LatentIt("Signal.Sig0", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnSig0Signal.AddLambda([this, TestDone](ETbEnumEnum0 InParam0)
			{
			// known test value
			ETbEnumEnum0 Param0TestValue = ETbEnumEnum0::TEE0_Value1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam0, Param0TestValue);
			TestDone.Execute();
		});

		// use different test value
		ETbEnumEnum0 Param0TestValue = ETbEnumEnum0::TEE0_Value1;
		TbEnumEnumInterfaceSignals->BroadcastSig0Signal(Param0TestValue);
	});

	LatentIt("Signal.Sig0BP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnSig0SignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceImplHelper::Sig0SignalCb);

		// use different test value
		ETbEnumEnum0 Param0TestValue = ETbEnumEnum0::TEE0_Value1;
		TbEnumEnumInterfaceSignals->BroadcastSig0Signal(Param0TestValue);
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnSig1Signal.AddLambda([this, TestDone](ETbEnumEnum1 InParam1)
			{
			// known test value
			ETbEnumEnum1 Param1TestValue = ETbEnumEnum1::TEE1_Value2;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			TestDone.Execute();
		});

		// use different test value
		ETbEnumEnum1 Param1TestValue = ETbEnumEnum1::TEE1_Value2;
		TbEnumEnumInterfaceSignals->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig1BP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnSig1SignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceImplHelper::Sig1SignalCb);

		// use different test value
		ETbEnumEnum1 Param1TestValue = ETbEnumEnum1::TEE1_Value2;
		TbEnumEnumInterfaceSignals->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnSig2Signal.AddLambda([this, TestDone](ETbEnumEnum2 InParam2)
			{
			// known test value
			ETbEnumEnum2 Param2TestValue = ETbEnumEnum2::TEE2_Value1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
			TestDone.Execute();
		});

		// use different test value
		ETbEnumEnum2 Param2TestValue = ETbEnumEnum2::TEE2_Value1;
		TbEnumEnumInterfaceSignals->BroadcastSig2Signal(Param2TestValue);
	});

	LatentIt("Signal.Sig2BP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnSig2SignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceImplHelper::Sig2SignalCb);

		// use different test value
		ETbEnumEnum2 Param2TestValue = ETbEnumEnum2::TEE2_Value1;
		TbEnumEnumInterfaceSignals->BroadcastSig2Signal(Param2TestValue);
	});

	LatentIt("Signal.Sig3", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnSig3Signal.AddLambda([this, TestDone](ETbEnumEnum3 InParam3)
			{
			// known test value
			ETbEnumEnum3 Param3TestValue = ETbEnumEnum3::TEE3_Value2;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam3, Param3TestValue);
			TestDone.Execute();
		});

		// use different test value
		ETbEnumEnum3 Param3TestValue = ETbEnumEnum3::TEE3_Value2;
		TbEnumEnumInterfaceSignals->BroadcastSig3Signal(Param3TestValue);
	});

	LatentIt("Signal.Sig3BP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnSig3SignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceImplHelper::Sig3SignalCb);

		// use different test value
		ETbEnumEnum3 Param3TestValue = ETbEnumEnum3::TEE3_Value2;
		TbEnumEnumInterfaceSignals->BroadcastSig3Signal(Param3TestValue);
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS
