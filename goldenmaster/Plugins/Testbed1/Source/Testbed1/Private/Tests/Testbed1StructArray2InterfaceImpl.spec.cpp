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

#include "Implementation/Testbed1StructArray2Interface.h"
#include "Testbed1StructArray2InterfaceImplFixture.h"
#include "Testbed1TestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UTestbed1StructArray2InterfaceImplSpec, "Testbed1.StructArray2Interface.Impl", Testbed1TestFilterMask);

TSharedPtr<FTestbed1StructArray2InterfaceImplFixture> ImplFixture;

END_DEFINE_SPEC(UTestbed1StructArray2InterfaceImplSpec);

void UTestbed1StructArray2InterfaceImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplFixture = MakeShared<FTestbed1StructArray2InterfaceImplFixture>();
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
		FTestbed1StructBoolWithArray TestValue = FTestbed1StructBoolWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropBool(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropBool.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructBoolWithArray TestValue = FTestbed1StructBoolWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropBool(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTestbed1StructArray2InterfaceSignals* Testbed1StructArray2InterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed1StructArray2InterfaceSignals->OnPropBoolChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArray2InterfaceImplHelper::PropBoolPropertyCb);
		// use different test value
		TestValue = createTestFTestbed1StructBoolWithArray();
		ImplFixture->GetImplementation()->Execute_SetPropBool(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Property.PropInt.Default", [this]()
		{
		// Do implement test here
		FTestbed1StructIntWithArray TestValue = FTestbed1StructIntWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropInt(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropInt.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructIntWithArray TestValue = FTestbed1StructIntWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropInt(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTestbed1StructArray2InterfaceSignals* Testbed1StructArray2InterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed1StructArray2InterfaceSignals->OnPropIntChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArray2InterfaceImplHelper::PropIntPropertyCb);
		// use different test value
		TestValue = createTestFTestbed1StructIntWithArray();
		ImplFixture->GetImplementation()->Execute_SetPropInt(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Property.PropFloat.Default", [this]()
		{
		// Do implement test here
		FTestbed1StructFloatWithArray TestValue = FTestbed1StructFloatWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropFloat(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropFloat.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructFloatWithArray TestValue = FTestbed1StructFloatWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropFloat(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTestbed1StructArray2InterfaceSignals* Testbed1StructArray2InterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed1StructArray2InterfaceSignals->OnPropFloatChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArray2InterfaceImplHelper::PropFloatPropertyCb);
		// use different test value
		TestValue = createTestFTestbed1StructFloatWithArray();
		ImplFixture->GetImplementation()->Execute_SetPropFloat(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Property.PropString.Default", [this]()
		{
		// Do implement test here
		FTestbed1StructStringWithArray TestValue = FTestbed1StructStringWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropString(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropString.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructStringWithArray TestValue = FTestbed1StructStringWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropString(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTestbed1StructArray2InterfaceSignals* Testbed1StructArray2InterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed1StructArray2InterfaceSignals->OnPropStringChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArray2InterfaceImplHelper::PropStringPropertyCb);
		// use different test value
		TestValue = createTestFTestbed1StructStringWithArray();
		ImplFixture->GetImplementation()->Execute_SetPropString(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Property.PropEnum.Default", [this]()
		{
		// Do implement test here
		FTestbed1StructEnumWithArray TestValue = FTestbed1StructEnumWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropEnum(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropEnum.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructEnumWithArray TestValue = FTestbed1StructEnumWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropEnum(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTestbed1StructArray2InterfaceSignals* Testbed1StructArray2InterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed1StructArray2InterfaceSignals->OnPropEnumChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArray2InterfaceImplHelper::PropEnumPropertyCb);
		// use different test value
		TestValue = createTestFTestbed1StructEnumWithArray();
		ImplFixture->GetImplementation()->Execute_SetPropEnum(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Operation.FuncBool", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_FuncBool(ImplFixture->GetImplementation().GetObject(), FTestbed1StructBoolWithArray());
	});

	It("Operation.FuncInt", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_FuncInt(ImplFixture->GetImplementation().GetObject(), FTestbed1StructIntWithArray());
	});

	It("Operation.FuncFloat", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_FuncFloat(ImplFixture->GetImplementation().GetObject(), FTestbed1StructFloatWithArray());
	});

	It("Operation.FuncString", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_FuncString(ImplFixture->GetImplementation().GetObject(), FTestbed1StructStringWithArray());
	});

	It("Operation.FuncEnum", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_FuncEnum(ImplFixture->GetImplementation().GetObject(), FTestbed1StructEnumWithArray());
	});

	LatentIt("Signal.SigBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTestbed1StructArray2InterfaceSignals* Testbed1StructArray2InterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed1StructArray2InterfaceSignals->OnSigBoolSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArray2InterfaceImplHelper::SigBoolSignalCb);

		// use different test value
		FTestbed1StructBoolWithArray ParamBoolTestValue = createTestFTestbed1StructBoolWithArray();
		Testbed1StructArray2InterfaceSignals->BroadcastSigBoolSignal(ParamBoolTestValue);
	});

	LatentIt("Signal.SigInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTestbed1StructArray2InterfaceSignals* Testbed1StructArray2InterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed1StructArray2InterfaceSignals->OnSigIntSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArray2InterfaceImplHelper::SigIntSignalCb);

		// use different test value
		FTestbed1StructIntWithArray ParamIntTestValue = createTestFTestbed1StructIntWithArray();
		Testbed1StructArray2InterfaceSignals->BroadcastSigIntSignal(ParamIntTestValue);
	});

	LatentIt("Signal.SigFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTestbed1StructArray2InterfaceSignals* Testbed1StructArray2InterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed1StructArray2InterfaceSignals->OnSigFloatSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArray2InterfaceImplHelper::SigFloatSignalCb);

		// use different test value
		FTestbed1StructFloatWithArray ParamFloatTestValue = createTestFTestbed1StructFloatWithArray();
		Testbed1StructArray2InterfaceSignals->BroadcastSigFloatSignal(ParamFloatTestValue);
	});

	LatentIt("Signal.SigString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTestbed1StructArray2InterfaceSignals* Testbed1StructArray2InterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed1StructArray2InterfaceSignals->OnSigStringSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArray2InterfaceImplHelper::SigStringSignalCb);

		// use different test value
		FTestbed1StructStringWithArray ParamStringTestValue = createTestFTestbed1StructStringWithArray();
		Testbed1StructArray2InterfaceSignals->BroadcastSigStringSignal(ParamStringTestValue);
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS
