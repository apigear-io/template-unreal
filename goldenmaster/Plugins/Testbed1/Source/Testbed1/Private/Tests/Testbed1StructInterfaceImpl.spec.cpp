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

#include "Testbed1StructInterfaceImpl.spec.h"
#include "Implementation/Testbed1StructInterface.h"
#include "Testbed1StructInterfaceImplFixture.h"
#include "Testbed1TestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTestbed1StructInterfaceImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplFixture = MakeUnique<FTestbed1StructInterfaceImplFixture>();
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
		FTestbed1StructBool TestValue = FTestbed1StructBool(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropBool(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropBool.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructBool TestValue = FTestbed1StructBool(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropBool(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTestbed1StructInterfaceSignals* Testbed1StructInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed1StructInterfaceSignals->OnPropBoolChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructInterfaceImplHelper::PropBoolPropertyCb);
		// use different test value
		TestValue = createTestFTestbed1StructBool();
		ImplFixture->GetImplementation()->Execute_SetPropBool(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Property.PropInt.Default", [this]()
		{
		// Do implement test here
		FTestbed1StructInt TestValue = FTestbed1StructInt(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropInt(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropInt.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructInt TestValue = FTestbed1StructInt(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropInt(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTestbed1StructInterfaceSignals* Testbed1StructInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed1StructInterfaceSignals->OnPropIntChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructInterfaceImplHelper::PropIntPropertyCb);
		// use different test value
		TestValue = createTestFTestbed1StructInt();
		ImplFixture->GetImplementation()->Execute_SetPropInt(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Property.PropFloat.Default", [this]()
		{
		// Do implement test here
		FTestbed1StructFloat TestValue = FTestbed1StructFloat(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropFloat(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropFloat.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructFloat TestValue = FTestbed1StructFloat(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropFloat(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTestbed1StructInterfaceSignals* Testbed1StructInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed1StructInterfaceSignals->OnPropFloatChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructInterfaceImplHelper::PropFloatPropertyCb);
		// use different test value
		TestValue = createTestFTestbed1StructFloat();
		ImplFixture->GetImplementation()->Execute_SetPropFloat(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Property.PropString.Default", [this]()
		{
		// Do implement test here
		FTestbed1StructString TestValue = FTestbed1StructString(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropString(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropString.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructString TestValue = FTestbed1StructString(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropString(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTestbed1StructInterfaceSignals* Testbed1StructInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed1StructInterfaceSignals->OnPropStringChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructInterfaceImplHelper::PropStringPropertyCb);
		// use different test value
		TestValue = createTestFTestbed1StructString();
		ImplFixture->GetImplementation()->Execute_SetPropString(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Operation.FuncBool", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_FuncBool(ImplFixture->GetImplementation().GetObject(), FTestbed1StructBool());
	});

	It("Operation.FuncInt", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_FuncInt(ImplFixture->GetImplementation().GetObject(), FTestbed1StructInt());
	});

	It("Operation.FuncFloat", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_FuncFloat(ImplFixture->GetImplementation().GetObject(), FTestbed1StructFloat());
	});

	It("Operation.FuncString", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_FuncString(ImplFixture->GetImplementation().GetObject(), FTestbed1StructString());
	});

	LatentIt("Signal.SigBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTestbed1StructInterfaceSignals* Testbed1StructInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed1StructInterfaceSignals->OnSigBoolSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructInterfaceImplHelper::SigBoolSignalCb);

		// use different test value
		FTestbed1StructBool ParamBoolTestValue = createTestFTestbed1StructBool();
		Testbed1StructInterfaceSignals->BroadcastSigBoolSignal(ParamBoolTestValue);
	});

	LatentIt("Signal.SigInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTestbed1StructInterfaceSignals* Testbed1StructInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed1StructInterfaceSignals->OnSigIntSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructInterfaceImplHelper::SigIntSignalCb);

		// use different test value
		FTestbed1StructInt ParamIntTestValue = createTestFTestbed1StructInt();
		Testbed1StructInterfaceSignals->BroadcastSigIntSignal(ParamIntTestValue);
	});

	LatentIt("Signal.SigFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTestbed1StructInterfaceSignals* Testbed1StructInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed1StructInterfaceSignals->OnSigFloatSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructInterfaceImplHelper::SigFloatSignalCb);

		// use different test value
		FTestbed1StructFloat ParamFloatTestValue = createTestFTestbed1StructFloat();
		Testbed1StructInterfaceSignals->BroadcastSigFloatSignal(ParamFloatTestValue);
	});

	LatentIt("Signal.SigString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTestbed1StructInterfaceSignals* Testbed1StructInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed1StructInterfaceSignals->OnSigStringSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructInterfaceImplHelper::SigStringSignalCb);

		// use different test value
		FTestbed1StructString ParamStringTestValue = createTestFTestbed1StructString();
		Testbed1StructInterfaceSignals->BroadcastSigStringSignal(ParamStringTestValue);
	});
}

void UTestbed1StructInterfaceImplSpec::PropBoolPropertyCb(const FTestbed1StructBool& InPropBool)
{
	FTestbed1StructBool TestValue = FTestbed1StructBool();
	// use different test value
	TestValue = createTestFTestbed1StructBool();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropBool(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructInterfaceImplSpec::PropIntPropertyCb(const FTestbed1StructInt& InPropInt)
{
	FTestbed1StructInt TestValue = FTestbed1StructInt();
	// use different test value
	TestValue = createTestFTestbed1StructInt();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropInt(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructInterfaceImplSpec::PropFloatPropertyCb(const FTestbed1StructFloat& InPropFloat)
{
	FTestbed1StructFloat TestValue = FTestbed1StructFloat();
	// use different test value
	TestValue = createTestFTestbed1StructFloat();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropFloat(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructInterfaceImplSpec::PropStringPropertyCb(const FTestbed1StructString& InPropString)
{
	FTestbed1StructString TestValue = FTestbed1StructString();
	// use different test value
	TestValue = createTestFTestbed1StructString();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropString(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructInterfaceImplSpec::SigBoolSignalCb(const FTestbed1StructBool& InParamBool)
{
	// known test value
	FTestbed1StructBool ParamBoolTestValue = createTestFTestbed1StructBool();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamBool, ParamBoolTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructInterfaceImplSpec::SigIntSignalCb(const FTestbed1StructInt& InParamInt)
{
	// known test value
	FTestbed1StructInt ParamIntTestValue = createTestFTestbed1StructInt();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt, ParamIntTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructInterfaceImplSpec::SigFloatSignalCb(const FTestbed1StructFloat& InParamFloat)
{
	// known test value
	FTestbed1StructFloat ParamFloatTestValue = createTestFTestbed1StructFloat();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat, ParamFloatTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructInterfaceImplSpec::SigStringSignalCb(const FTestbed1StructString& InParamString)
{
	// known test value
	FTestbed1StructString ParamStringTestValue = createTestFTestbed1StructString();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamString, ParamStringTestValue);
	testDoneDelegate.Execute();
}
#endif // WITH_DEV_AUTOMATION_TESTS
