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

#include "Testbed1StructArrayInterfaceImpl.spec.h"
#include "Testbed1/Implementation/Testbed1StructArrayInterface.h"
#include "Testbed1StructArrayInterfaceImplFixture.h"
#include "Testbed1/Tests/Testbed1TestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTestbed1StructArrayInterfaceImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplFixture = MakeUnique<FTestbed1StructArrayInterfaceImplFixture>();
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
		TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);
	});

	LatentIt("Property.PropBool.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);

		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnPropBoolChanged.AddLambda([this, TestDone](const TArray<FTestbed1StructBool>& InPropBool)
			{
			TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>();
			// use different test value
			TestValue = createTestFTestbed1StructBoolArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructBoolArray();
		ImplFixture->GetImplementation()->SetPropBool(TestValue);
	});

	LatentIt("Property.PropBool.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);

		testDoneDelegate = TestDone;
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnPropBoolChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArrayInterfaceImplHelper::PropBoolPropertyCb);
		// use different test value
		TestValue = createTestFTestbed1StructBoolArray();
		ImplFixture->GetImplementation()->SetPropBool(TestValue);
	});

	It("Property.PropInt.Default", [this]()
		{
		// Do implement test here
		TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);
	});

	LatentIt("Property.PropInt.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);

		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnPropIntChanged.AddLambda([this, TestDone](const TArray<FTestbed1StructInt>& InPropInt)
			{
			TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>();
			// use different test value
			TestValue = createTestFTestbed1StructIntArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructIntArray();
		ImplFixture->GetImplementation()->SetPropInt(TestValue);
	});

	LatentIt("Property.PropInt.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);

		testDoneDelegate = TestDone;
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnPropIntChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArrayInterfaceImplHelper::PropIntPropertyCb);
		// use different test value
		TestValue = createTestFTestbed1StructIntArray();
		ImplFixture->GetImplementation()->SetPropInt(TestValue);
	});

	It("Property.PropFloat.Default", [this]()
		{
		// Do implement test here
		TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);
	});

	LatentIt("Property.PropFloat.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);

		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnPropFloatChanged.AddLambda([this, TestDone](const TArray<FTestbed1StructFloat>& InPropFloat)
			{
			TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>();
			// use different test value
			TestValue = createTestFTestbed1StructFloatArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructFloatArray();
		ImplFixture->GetImplementation()->SetPropFloat(TestValue);
	});

	LatentIt("Property.PropFloat.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);

		testDoneDelegate = TestDone;
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnPropFloatChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArrayInterfaceImplHelper::PropFloatPropertyCb);
		// use different test value
		TestValue = createTestFTestbed1StructFloatArray();
		ImplFixture->GetImplementation()->SetPropFloat(TestValue);
	});

	It("Property.PropString.Default", [this]()
		{
		// Do implement test here
		TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropString(), TestValue);
	});

	LatentIt("Property.PropString.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropString(), TestValue);

		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnPropStringChanged.AddLambda([this, TestDone](const TArray<FTestbed1StructString>& InPropString)
			{
			TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>();
			// use different test value
			TestValue = createTestFTestbed1StructStringArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropString(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructStringArray();
		ImplFixture->GetImplementation()->SetPropString(TestValue);
	});

	LatentIt("Property.PropString.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropString(), TestValue);

		testDoneDelegate = TestDone;
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnPropStringChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArrayInterfaceImplHelper::PropStringPropertyCb);
		// use different test value
		TestValue = createTestFTestbed1StructStringArray();
		ImplFixture->GetImplementation()->SetPropString(TestValue);
	});

	It("Property.PropEnum.Default", [this]()
		{
		// Do implement test here
		TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropEnum(), TestValue);
	});

	LatentIt("Property.PropEnum.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropEnum(), TestValue);

		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnPropEnumChanged.AddLambda([this, TestDone](const TArray<ETestbed1Enum0>& InPropEnum)
			{
			TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>();
			// use different test value
			TestValue.Add(ETestbed1Enum0::T1E0_VALUE1);
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropEnum(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue.Add(ETestbed1Enum0::T1E0_VALUE1);
		ImplFixture->GetImplementation()->SetPropEnum(TestValue);
	});

	LatentIt("Property.PropEnum.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropEnum(), TestValue);

		testDoneDelegate = TestDone;
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnPropEnumChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArrayInterfaceImplHelper::PropEnumPropertyCb);
		// use different test value
		TestValue.Add(ETestbed1Enum0::T1E0_VALUE1);
		ImplFixture->GetImplementation()->SetPropEnum(TestValue);
	});

	It("Operation.FuncBool", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->FuncBool(TArray<FTestbed1StructBool>());
	});

	It("Operation.FuncInt", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->FuncInt(TArray<FTestbed1StructInt>());
	});

	It("Operation.FuncFloat", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->FuncFloat(TArray<FTestbed1StructFloat>());
	});

	It("Operation.FuncString", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->FuncString(TArray<FTestbed1StructString>());
	});

	It("Operation.FuncEnum", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->FuncEnum(TArray<ETestbed1Enum0>());
	});

	LatentIt("Signal.SigBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnSigBoolSignal.AddLambda([this, TestDone](const TArray<FTestbed1StructBool>& InParamBool)
			{
			// known test value
			TArray<FTestbed1StructBool> ParamBoolTestValue = createTestFTestbed1StructBoolArray();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamBool, ParamBoolTestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<FTestbed1StructBool> ParamBoolTestValue = createTestFTestbed1StructBoolArray();
		Testbed1StructArrayInterfaceSignals->BroadcastSigBoolSignal(ParamBoolTestValue);
	});

	LatentIt("Signal.SigBoolBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnSigBoolSignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArrayInterfaceImplHelper::SigBoolSignalCb);

		// use different test value
		TArray<FTestbed1StructBool> ParamBoolTestValue = createTestFTestbed1StructBoolArray();
		Testbed1StructArrayInterfaceSignals->BroadcastSigBoolSignal(ParamBoolTestValue);
	});

	LatentIt("Signal.SigInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnSigIntSignal.AddLambda([this, TestDone](const TArray<FTestbed1StructInt>& InParamInt)
			{
			// known test value
			TArray<FTestbed1StructInt> ParamIntTestValue = createTestFTestbed1StructIntArray();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt, ParamIntTestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<FTestbed1StructInt> ParamIntTestValue = createTestFTestbed1StructIntArray();
		Testbed1StructArrayInterfaceSignals->BroadcastSigIntSignal(ParamIntTestValue);
	});

	LatentIt("Signal.SigIntBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnSigIntSignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArrayInterfaceImplHelper::SigIntSignalCb);

		// use different test value
		TArray<FTestbed1StructInt> ParamIntTestValue = createTestFTestbed1StructIntArray();
		Testbed1StructArrayInterfaceSignals->BroadcastSigIntSignal(ParamIntTestValue);
	});

	LatentIt("Signal.SigFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnSigFloatSignal.AddLambda([this, TestDone](const TArray<FTestbed1StructFloat>& InParamFloat)
			{
			// known test value
			TArray<FTestbed1StructFloat> ParamFloatTestValue = createTestFTestbed1StructFloatArray();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat, ParamFloatTestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<FTestbed1StructFloat> ParamFloatTestValue = createTestFTestbed1StructFloatArray();
		Testbed1StructArrayInterfaceSignals->BroadcastSigFloatSignal(ParamFloatTestValue);
	});

	LatentIt("Signal.SigFloatBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnSigFloatSignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArrayInterfaceImplHelper::SigFloatSignalCb);

		// use different test value
		TArray<FTestbed1StructFloat> ParamFloatTestValue = createTestFTestbed1StructFloatArray();
		Testbed1StructArrayInterfaceSignals->BroadcastSigFloatSignal(ParamFloatTestValue);
	});

	LatentIt("Signal.SigString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnSigStringSignal.AddLambda([this, TestDone](const TArray<FTestbed1StructString>& InParamString)
			{
			// known test value
			TArray<FTestbed1StructString> ParamStringTestValue = createTestFTestbed1StructStringArray();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamString, ParamStringTestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<FTestbed1StructString> ParamStringTestValue = createTestFTestbed1StructStringArray();
		Testbed1StructArrayInterfaceSignals->BroadcastSigStringSignal(ParamStringTestValue);
	});

	LatentIt("Signal.SigStringBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnSigStringSignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArrayInterfaceImplHelper::SigStringSignalCb);

		// use different test value
		TArray<FTestbed1StructString> ParamStringTestValue = createTestFTestbed1StructStringArray();
		Testbed1StructArrayInterfaceSignals->BroadcastSigStringSignal(ParamStringTestValue);
	});

	LatentIt("Signal.SigEnum", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnSigEnumSignal.AddLambda([this, TestDone](const TArray<ETestbed1Enum0>& InParamEnum)
			{
			// known test value
			TArray<ETestbed1Enum0> ParamEnumTestValue = TArray<ETestbed1Enum0>(); // default value
			ParamEnumTestValue.Add(ETestbed1Enum0::T1E0_VALUE1);
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamEnum, ParamEnumTestValue);
			TestDone.Execute();
		});

		// use different test value
		TArray<ETestbed1Enum0> ParamEnumTestValue = TArray<ETestbed1Enum0>(); // default value
		ParamEnumTestValue.Add(ETestbed1Enum0::T1E0_VALUE1);
		Testbed1StructArrayInterfaceSignals->BroadcastSigEnumSignal(ParamEnumTestValue);
	});

	LatentIt("Signal.SigEnumBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArrayInterfaceSignals->OnSigEnumSignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArrayInterfaceImplHelper::SigEnumSignalCb);

		// use different test value
		TArray<ETestbed1Enum0> ParamEnumTestValue = TArray<ETestbed1Enum0>(); // default value
		ParamEnumTestValue.Add(ETestbed1Enum0::T1E0_VALUE1);
		Testbed1StructArrayInterfaceSignals->BroadcastSigEnumSignal(ParamEnumTestValue);
	});
}

void UTestbed1StructArrayInterfaceImplSpec::PropBoolPropertyCb(const TArray<FTestbed1StructBool>& InPropBool)
{
	TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>();
	// use different test value
	TestValue = createTestFTestbed1StructBoolArray();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceImplSpec::PropIntPropertyCb(const TArray<FTestbed1StructInt>& InPropInt)
{
	TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>();
	// use different test value
	TestValue = createTestFTestbed1StructIntArray();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceImplSpec::PropFloatPropertyCb(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>();
	// use different test value
	TestValue = createTestFTestbed1StructFloatArray();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceImplSpec::PropStringPropertyCb(const TArray<FTestbed1StructString>& InPropString)
{
	TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>();
	// use different test value
	TestValue = createTestFTestbed1StructStringArray();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropString(), TestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceImplSpec::PropEnumPropertyCb(const TArray<ETestbed1Enum0>& InPropEnum)
{
	TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>();
	// use different test value
	TestValue.Add(ETestbed1Enum0::T1E0_VALUE1);
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropEnum(), TestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceImplSpec::SigBoolSignalCb(const TArray<FTestbed1StructBool>& InParamBool)
{
	// known test value
	TArray<FTestbed1StructBool> ParamBoolTestValue = createTestFTestbed1StructBoolArray();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamBool, ParamBoolTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceImplSpec::SigIntSignalCb(const TArray<FTestbed1StructInt>& InParamInt)
{
	// known test value
	TArray<FTestbed1StructInt> ParamIntTestValue = createTestFTestbed1StructIntArray();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt, ParamIntTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceImplSpec::SigFloatSignalCb(const TArray<FTestbed1StructFloat>& InParamFloat)
{
	// known test value
	TArray<FTestbed1StructFloat> ParamFloatTestValue = createTestFTestbed1StructFloatArray();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat, ParamFloatTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceImplSpec::SigStringSignalCb(const TArray<FTestbed1StructString>& InParamString)
{
	// known test value
	TArray<FTestbed1StructString> ParamStringTestValue = createTestFTestbed1StructStringArray();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamString, ParamStringTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceImplSpec::SigEnumSignalCb(const TArray<ETestbed1Enum0>& InParamEnum)
{
	// known test value
	TArray<ETestbed1Enum0> ParamEnumTestValue = TArray<ETestbed1Enum0>(); // default value
	ParamEnumTestValue.Add(ETestbed1Enum0::T1E0_VALUE1);
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamEnum, ParamEnumTestValue);
	testDoneDelegate.Execute();
}
#endif // WITH_DEV_AUTOMATION_TESTS
