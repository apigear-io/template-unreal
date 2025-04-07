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

#include "Testbed1StructArray2InterfaceImpl.spec.h"
#include "Testbed1/Implementation/Testbed1StructArray2Interface.h"
#include "Testbed1StructArray2InterfaceImplFixture.h"
#include "Testbed1/Tests/Testbed1TestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTestbed1StructArray2InterfaceImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplFixture = MakeUnique<FTestbed1StructArray2InterfaceImplFixture>();
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
		FTestbed1StructBoolWithArray TestValue = FTestbed1StructBoolWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);
	});

	LatentIt("Property.PropBool.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructBoolWithArray TestValue = FTestbed1StructBoolWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);

		UTestbed1StructArray2InterfaceSignals* Testbed1StructArray2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArray2InterfaceSignals->OnPropBoolChanged.AddLambda([this, TestDone](const FTestbed1StructBoolWithArray& InPropBool)
			{
			FTestbed1StructBoolWithArray TestValue = FTestbed1StructBoolWithArray();
			// use different test value
			TestValue = createTestFTestbed1StructBoolWithArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructBoolWithArray();
		ImplFixture->GetImplementation()->SetPropBool(TestValue);
	});

	LatentIt("Property.PropBool.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructBoolWithArray TestValue = FTestbed1StructBoolWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);

		testDoneDelegate = TestDone;
		UTestbed1StructArray2InterfaceSignals* Testbed1StructArray2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArray2InterfaceSignals->OnPropBoolChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArray2InterfaceImplHelper::PropBoolPropertyCb);
		// use different test value
		TestValue = createTestFTestbed1StructBoolWithArray();
		ImplFixture->GetImplementation()->SetPropBool(TestValue);
	});

	It("Property.PropInt.Default", [this]()
		{
		// Do implement test here
		FTestbed1StructIntWithArray TestValue = FTestbed1StructIntWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);
	});

	LatentIt("Property.PropInt.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructIntWithArray TestValue = FTestbed1StructIntWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);

		UTestbed1StructArray2InterfaceSignals* Testbed1StructArray2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArray2InterfaceSignals->OnPropIntChanged.AddLambda([this, TestDone](const FTestbed1StructIntWithArray& InPropInt)
			{
			FTestbed1StructIntWithArray TestValue = FTestbed1StructIntWithArray();
			// use different test value
			TestValue = createTestFTestbed1StructIntWithArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructIntWithArray();
		ImplFixture->GetImplementation()->SetPropInt(TestValue);
	});

	LatentIt("Property.PropInt.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructIntWithArray TestValue = FTestbed1StructIntWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);

		testDoneDelegate = TestDone;
		UTestbed1StructArray2InterfaceSignals* Testbed1StructArray2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArray2InterfaceSignals->OnPropIntChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArray2InterfaceImplHelper::PropIntPropertyCb);
		// use different test value
		TestValue = createTestFTestbed1StructIntWithArray();
		ImplFixture->GetImplementation()->SetPropInt(TestValue);
	});

	It("Property.PropFloat.Default", [this]()
		{
		// Do implement test here
		FTestbed1StructFloatWithArray TestValue = FTestbed1StructFloatWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);
	});

	LatentIt("Property.PropFloat.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructFloatWithArray TestValue = FTestbed1StructFloatWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);

		UTestbed1StructArray2InterfaceSignals* Testbed1StructArray2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArray2InterfaceSignals->OnPropFloatChanged.AddLambda([this, TestDone](const FTestbed1StructFloatWithArray& InPropFloat)
			{
			FTestbed1StructFloatWithArray TestValue = FTestbed1StructFloatWithArray();
			// use different test value
			TestValue = createTestFTestbed1StructFloatWithArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructFloatWithArray();
		ImplFixture->GetImplementation()->SetPropFloat(TestValue);
	});

	LatentIt("Property.PropFloat.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructFloatWithArray TestValue = FTestbed1StructFloatWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);

		testDoneDelegate = TestDone;
		UTestbed1StructArray2InterfaceSignals* Testbed1StructArray2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArray2InterfaceSignals->OnPropFloatChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArray2InterfaceImplHelper::PropFloatPropertyCb);
		// use different test value
		TestValue = createTestFTestbed1StructFloatWithArray();
		ImplFixture->GetImplementation()->SetPropFloat(TestValue);
	});

	It("Property.PropString.Default", [this]()
		{
		// Do implement test here
		FTestbed1StructStringWithArray TestValue = FTestbed1StructStringWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropString(), TestValue);
	});

	LatentIt("Property.PropString.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructStringWithArray TestValue = FTestbed1StructStringWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropString(), TestValue);

		UTestbed1StructArray2InterfaceSignals* Testbed1StructArray2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArray2InterfaceSignals->OnPropStringChanged.AddLambda([this, TestDone](const FTestbed1StructStringWithArray& InPropString)
			{
			FTestbed1StructStringWithArray TestValue = FTestbed1StructStringWithArray();
			// use different test value
			TestValue = createTestFTestbed1StructStringWithArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropString(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructStringWithArray();
		ImplFixture->GetImplementation()->SetPropString(TestValue);
	});

	LatentIt("Property.PropString.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructStringWithArray TestValue = FTestbed1StructStringWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropString(), TestValue);

		testDoneDelegate = TestDone;
		UTestbed1StructArray2InterfaceSignals* Testbed1StructArray2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArray2InterfaceSignals->OnPropStringChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArray2InterfaceImplHelper::PropStringPropertyCb);
		// use different test value
		TestValue = createTestFTestbed1StructStringWithArray();
		ImplFixture->GetImplementation()->SetPropString(TestValue);
	});

	It("Property.PropEnum.Default", [this]()
		{
		// Do implement test here
		FTestbed1StructEnumWithArray TestValue = FTestbed1StructEnumWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropEnum(), TestValue);
	});

	LatentIt("Property.PropEnum.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructEnumWithArray TestValue = FTestbed1StructEnumWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropEnum(), TestValue);

		UTestbed1StructArray2InterfaceSignals* Testbed1StructArray2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArray2InterfaceSignals->OnPropEnumChanged.AddLambda([this, TestDone](const FTestbed1StructEnumWithArray& InPropEnum)
			{
			FTestbed1StructEnumWithArray TestValue = FTestbed1StructEnumWithArray();
			// use different test value
			TestValue = createTestFTestbed1StructEnumWithArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropEnum(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructEnumWithArray();
		ImplFixture->GetImplementation()->SetPropEnum(TestValue);
	});

	LatentIt("Property.PropEnum.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructEnumWithArray TestValue = FTestbed1StructEnumWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropEnum(), TestValue);

		testDoneDelegate = TestDone;
		UTestbed1StructArray2InterfaceSignals* Testbed1StructArray2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArray2InterfaceSignals->OnPropEnumChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArray2InterfaceImplHelper::PropEnumPropertyCb);
		// use different test value
		TestValue = createTestFTestbed1StructEnumWithArray();
		ImplFixture->GetImplementation()->SetPropEnum(TestValue);
	});

	It("Operation.FuncBool", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->FuncBool(FTestbed1StructBoolWithArray());
	});

	It("Operation.FuncInt", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->FuncInt(FTestbed1StructIntWithArray());
	});

	It("Operation.FuncFloat", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->FuncFloat(FTestbed1StructFloatWithArray());
	});

	It("Operation.FuncString", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->FuncString(FTestbed1StructStringWithArray());
	});

	It("Operation.FuncEnum", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->FuncEnum(FTestbed1StructEnumWithArray());
	});

	LatentIt("Signal.SigBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructArray2InterfaceSignals* Testbed1StructArray2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArray2InterfaceSignals->OnSigBoolSignal.AddLambda([this, TestDone](const FTestbed1StructBoolWithArray& InParamBool)
			{
			// known test value
			FTestbed1StructBoolWithArray ParamBoolTestValue = createTestFTestbed1StructBoolWithArray();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamBool, ParamBoolTestValue);
			TestDone.Execute();
		});

		// use different test value
		FTestbed1StructBoolWithArray ParamBoolTestValue = createTestFTestbed1StructBoolWithArray();
		Testbed1StructArray2InterfaceSignals->BroadcastSigBoolSignal(ParamBoolTestValue);
	});

	LatentIt("Signal.SigBoolBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTestbed1StructArray2InterfaceSignals* Testbed1StructArray2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArray2InterfaceSignals->OnSigBoolSignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArray2InterfaceImplHelper::SigBoolSignalCb);

		// use different test value
		FTestbed1StructBoolWithArray ParamBoolTestValue = createTestFTestbed1StructBoolWithArray();
		Testbed1StructArray2InterfaceSignals->BroadcastSigBoolSignal(ParamBoolTestValue);
	});

	LatentIt("Signal.SigInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructArray2InterfaceSignals* Testbed1StructArray2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArray2InterfaceSignals->OnSigIntSignal.AddLambda([this, TestDone](const FTestbed1StructIntWithArray& InParamInt)
			{
			// known test value
			FTestbed1StructIntWithArray ParamIntTestValue = createTestFTestbed1StructIntWithArray();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt, ParamIntTestValue);
			TestDone.Execute();
		});

		// use different test value
		FTestbed1StructIntWithArray ParamIntTestValue = createTestFTestbed1StructIntWithArray();
		Testbed1StructArray2InterfaceSignals->BroadcastSigIntSignal(ParamIntTestValue);
	});

	LatentIt("Signal.SigIntBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTestbed1StructArray2InterfaceSignals* Testbed1StructArray2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArray2InterfaceSignals->OnSigIntSignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArray2InterfaceImplHelper::SigIntSignalCb);

		// use different test value
		FTestbed1StructIntWithArray ParamIntTestValue = createTestFTestbed1StructIntWithArray();
		Testbed1StructArray2InterfaceSignals->BroadcastSigIntSignal(ParamIntTestValue);
	});

	LatentIt("Signal.SigFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructArray2InterfaceSignals* Testbed1StructArray2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArray2InterfaceSignals->OnSigFloatSignal.AddLambda([this, TestDone](const FTestbed1StructFloatWithArray& InParamFloat)
			{
			// known test value
			FTestbed1StructFloatWithArray ParamFloatTestValue = createTestFTestbed1StructFloatWithArray();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat, ParamFloatTestValue);
			TestDone.Execute();
		});

		// use different test value
		FTestbed1StructFloatWithArray ParamFloatTestValue = createTestFTestbed1StructFloatWithArray();
		Testbed1StructArray2InterfaceSignals->BroadcastSigFloatSignal(ParamFloatTestValue);
	});

	LatentIt("Signal.SigFloatBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTestbed1StructArray2InterfaceSignals* Testbed1StructArray2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArray2InterfaceSignals->OnSigFloatSignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArray2InterfaceImplHelper::SigFloatSignalCb);

		// use different test value
		FTestbed1StructFloatWithArray ParamFloatTestValue = createTestFTestbed1StructFloatWithArray();
		Testbed1StructArray2InterfaceSignals->BroadcastSigFloatSignal(ParamFloatTestValue);
	});

	LatentIt("Signal.SigString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructArray2InterfaceSignals* Testbed1StructArray2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArray2InterfaceSignals->OnSigStringSignal.AddLambda([this, TestDone](const FTestbed1StructStringWithArray& InParamString)
			{
			// known test value
			FTestbed1StructStringWithArray ParamStringTestValue = createTestFTestbed1StructStringWithArray();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamString, ParamStringTestValue);
			TestDone.Execute();
		});

		// use different test value
		FTestbed1StructStringWithArray ParamStringTestValue = createTestFTestbed1StructStringWithArray();
		Testbed1StructArray2InterfaceSignals->BroadcastSigStringSignal(ParamStringTestValue);
	});

	LatentIt("Signal.SigStringBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTestbed1StructArray2InterfaceSignals* Testbed1StructArray2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructArray2InterfaceSignals->OnSigStringSignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArray2InterfaceImplHelper::SigStringSignalCb);

		// use different test value
		FTestbed1StructStringWithArray ParamStringTestValue = createTestFTestbed1StructStringWithArray();
		Testbed1StructArray2InterfaceSignals->BroadcastSigStringSignal(ParamStringTestValue);
	});
}

void UTestbed1StructArray2InterfaceImplSpec::PropBoolPropertyCb(const FTestbed1StructBoolWithArray& InPropBool)
{
	FTestbed1StructBoolWithArray TestValue = FTestbed1StructBoolWithArray();
	// use different test value
	TestValue = createTestFTestbed1StructBoolWithArray();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceImplSpec::PropIntPropertyCb(const FTestbed1StructIntWithArray& InPropInt)
{
	FTestbed1StructIntWithArray TestValue = FTestbed1StructIntWithArray();
	// use different test value
	TestValue = createTestFTestbed1StructIntWithArray();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceImplSpec::PropFloatPropertyCb(const FTestbed1StructFloatWithArray& InPropFloat)
{
	FTestbed1StructFloatWithArray TestValue = FTestbed1StructFloatWithArray();
	// use different test value
	TestValue = createTestFTestbed1StructFloatWithArray();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceImplSpec::PropStringPropertyCb(const FTestbed1StructStringWithArray& InPropString)
{
	FTestbed1StructStringWithArray TestValue = FTestbed1StructStringWithArray();
	// use different test value
	TestValue = createTestFTestbed1StructStringWithArray();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropString(), TestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceImplSpec::PropEnumPropertyCb(const FTestbed1StructEnumWithArray& InPropEnum)
{
	FTestbed1StructEnumWithArray TestValue = FTestbed1StructEnumWithArray();
	// use different test value
	TestValue = createTestFTestbed1StructEnumWithArray();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropEnum(), TestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceImplSpec::SigBoolSignalCb(const FTestbed1StructBoolWithArray& InParamBool)
{
	// known test value
	FTestbed1StructBoolWithArray ParamBoolTestValue = createTestFTestbed1StructBoolWithArray();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamBool, ParamBoolTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceImplSpec::SigIntSignalCb(const FTestbed1StructIntWithArray& InParamInt)
{
	// known test value
	FTestbed1StructIntWithArray ParamIntTestValue = createTestFTestbed1StructIntWithArray();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt, ParamIntTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceImplSpec::SigFloatSignalCb(const FTestbed1StructFloatWithArray& InParamFloat)
{
	// known test value
	FTestbed1StructFloatWithArray ParamFloatTestValue = createTestFTestbed1StructFloatWithArray();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat, ParamFloatTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArray2InterfaceImplSpec::SigStringSignalCb(const FTestbed1StructStringWithArray& InParamString)
{
	// known test value
	FTestbed1StructStringWithArray ParamStringTestValue = createTestFTestbed1StructStringWithArray();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamString, ParamStringTestValue);
	testDoneDelegate.Execute();
}
#endif // WITH_DEV_AUTOMATION_TESTS
