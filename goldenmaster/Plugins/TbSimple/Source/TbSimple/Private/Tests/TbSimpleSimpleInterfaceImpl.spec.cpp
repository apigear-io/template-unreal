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

#include "TbSimpleSimpleInterfaceImpl.spec.h"
#include "Implementation/TbSimpleSimpleInterface.h"
#include "TbSimpleSimpleInterfaceImplFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSimpleSimpleInterfaceImplSpec::Define()
{
	BeforeEach([this]()
	{
		ImplFixture = MakeUnique<FTbSimpleSimpleInterfaceImplFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		ImplFixture->GetHelper()->SetSpec(this);
	});

	AfterEach([this]()
	{
		ImplFixture.Reset();
	});

	It("Property.PropBool", [this]()
	{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_SetPropBool(ImplFixture->GetImplementation().GetObject(), false);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropBool(ImplFixture->GetImplementation().GetObject()), false);
	});

	It("Property.PropInt", [this]()
	{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_SetPropInt(ImplFixture->GetImplementation().GetObject(), 0);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropInt(ImplFixture->GetImplementation().GetObject()), 0);
	});

	It("Property.PropInt32", [this]()
	{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_SetPropInt32(ImplFixture->GetImplementation().GetObject(), 0);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropInt32(ImplFixture->GetImplementation().GetObject()), 0);
	});

	It("Property.PropInt64", [this]()
	{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_SetPropInt64(ImplFixture->GetImplementation().GetObject(), 0LL);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropInt64(ImplFixture->GetImplementation().GetObject()), 0LL);
	});

	It("Property.PropFloat", [this]()
	{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_SetPropFloat(ImplFixture->GetImplementation().GetObject(), 0.0f);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropFloat(ImplFixture->GetImplementation().GetObject()), 0.0f);
	});

	It("Property.PropFloat32", [this]()
	{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_SetPropFloat32(ImplFixture->GetImplementation().GetObject(), 0.0f);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropFloat32(ImplFixture->GetImplementation().GetObject()), 0.0f);
	});

	It("Property.PropFloat64", [this]()
	{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_SetPropFloat64(ImplFixture->GetImplementation().GetObject(), 0.0);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropFloat64(ImplFixture->GetImplementation().GetObject()), 0.0);
	});

	It("Property.PropString", [this]()
	{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_SetPropString(ImplFixture->GetImplementation().GetObject(), FString());
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropString(ImplFixture->GetImplementation().GetObject()), FString());
	});

	It("Property.PropReadOnlyString", [this]()
	{
		// Do implement test here
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropReadOnlyString(ImplFixture->GetImplementation().GetObject()), FString());
	});

	It("Operation.FuncVoid", [this]()
	{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_FuncVoid(ImplFixture->GetImplementation().GetObject());
	});

	It("Operation.FuncBool", [this]()
	{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_FuncBool(ImplFixture->GetImplementation().GetObject(), false);
	});

	It("Operation.FuncInt", [this]()
	{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_FuncInt(ImplFixture->GetImplementation().GetObject(), 0);
	});

	It("Operation.FuncInt32", [this]()
	{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_FuncInt32(ImplFixture->GetImplementation().GetObject(), 0);
	});

	It("Operation.FuncInt64", [this]()
	{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_FuncInt64(ImplFixture->GetImplementation().GetObject(), 0LL);
	});

	It("Operation.FuncFloat", [this]()
	{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_FuncFloat(ImplFixture->GetImplementation().GetObject(), 0.0f);
	});

	It("Operation.FuncFloat32", [this]()
	{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_FuncFloat32(ImplFixture->GetImplementation().GetObject(), 0.0f);
	});

	It("Operation.FuncFloat64", [this]()
	{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_FuncFloat64(ImplFixture->GetImplementation().GetObject(), 0.0);
	});

	It("Operation.FuncString", [this]()
	{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_FuncString(ImplFixture->GetImplementation().GetObject(), FString());
	});

	LatentIt("Signal.SigVoid", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
	{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleInterfaceSignals->OnSigVoidSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleInterfaceImplHelper::SigVoidSignalCb);

		// use different test value
		TbSimpleSimpleInterfaceSignals->BroadcastSigVoidSignal();
	});

	LatentIt("Signal.SigBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
	{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleInterfaceSignals->OnSigBoolSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleInterfaceImplHelper::SigBoolSignalCb);

		// use different test value
		bool bParamBoolTestValue = true;
		TbSimpleSimpleInterfaceSignals->BroadcastSigBoolSignal(bParamBoolTestValue);
	});

	LatentIt("Signal.SigInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
	{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleInterfaceSignals->OnSigIntSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleInterfaceImplHelper::SigIntSignalCb);

		// use different test value
		int32 ParamIntTestValue = 1;
		TbSimpleSimpleInterfaceSignals->BroadcastSigIntSignal(ParamIntTestValue);
	});

	LatentIt("Signal.SigInt32", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
	{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleInterfaceSignals->OnSigInt32Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleInterfaceImplHelper::SigInt32SignalCb);

		// use different test value
		int32 ParamInt32TestValue = 1;
		TbSimpleSimpleInterfaceSignals->BroadcastSigInt32Signal(ParamInt32TestValue);
	});

	LatentIt("Signal.SigInt64", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
	{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleInterfaceSignals->OnSigInt64Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleInterfaceImplHelper::SigInt64SignalCb);

		// use different test value
		int64 ParamInt64TestValue = 1LL;
		TbSimpleSimpleInterfaceSignals->BroadcastSigInt64Signal(ParamInt64TestValue);
	});

	LatentIt("Signal.SigFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
	{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleInterfaceSignals->OnSigFloatSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleInterfaceImplHelper::SigFloatSignalCb);

		// use different test value
		float ParamFloatTestValue = 1.0f;
		TbSimpleSimpleInterfaceSignals->BroadcastSigFloatSignal(ParamFloatTestValue);
	});

	LatentIt("Signal.SigFloat32", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
	{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleInterfaceSignals->OnSigFloat32Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleInterfaceImplHelper::SigFloat32SignalCb);

		// use different test value
		float ParamFloa32TestValue = 1.0f;
		TbSimpleSimpleInterfaceSignals->BroadcastSigFloat32Signal(ParamFloa32TestValue);
	});

	LatentIt("Signal.SigFloat64", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
	{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleInterfaceSignals->OnSigFloat64Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleInterfaceImplHelper::SigFloat64SignalCb);

		// use different test value
		double ParamFloat64TestValue = 1.0;
		TbSimpleSimpleInterfaceSignals->BroadcastSigFloat64Signal(ParamFloat64TestValue);
	});

	LatentIt("Signal.SigString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
	{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleInterfaceSignals->OnSigStringSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleInterfaceImplHelper::SigStringSignalCb);

		// use different test value
		FString ParamStringTestValue = FString("xyz");
		TbSimpleSimpleInterfaceSignals->BroadcastSigStringSignal(ParamStringTestValue);
	});
}

void UTbSimpleSimpleInterfaceImplSpec::SigVoidSignalCb()
{
	// known test value
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceImplSpec::SigBoolSignalCb(bool bInParamBool)
{
	// known test value
	bool bParamBoolTestValue = true;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), bInParamBool, bParamBoolTestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceImplSpec::SigIntSignalCb(int32 InParamInt)
{
	// known test value
	int32 ParamIntTestValue = 1;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt, ParamIntTestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceImplSpec::SigInt32SignalCb(int32 InParamInt32)
{
	// known test value
	int32 ParamInt32TestValue = 1;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt32, ParamInt32TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceImplSpec::SigInt64SignalCb(int64 InParamInt64)
{
	// known test value
	int64 ParamInt64TestValue = 1LL;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt64, ParamInt64TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceImplSpec::SigFloatSignalCb(float InParamFloat)
{
	// known test value
	float ParamFloatTestValue = 1.0f;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat, ParamFloatTestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceImplSpec::SigFloat32SignalCb(float InParamFloa32)
{
	// known test value
	float ParamFloa32TestValue = 1.0f;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloa32, ParamFloa32TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceImplSpec::SigFloat64SignalCb(double InParamFloat64)
{
	// known test value
	double ParamFloat64TestValue = 1.0;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat64, ParamFloat64TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceImplSpec::SigStringSignalCb(const FString& InParamString)
{
	// known test value
	FString ParamStringTestValue = FString("xyz");
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamString, ParamStringTestValue);
	testDoneDelegate.Execute();
}
#endif // WITH_DEV_AUTOMATION_TESTS
