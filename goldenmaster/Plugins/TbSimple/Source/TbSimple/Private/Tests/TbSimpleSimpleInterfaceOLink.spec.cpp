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

#include "TbSimpleSimpleInterfaceOLink.spec.h"
#include "Implementation/TbSimpleSimpleInterface.h"
#include "TbSimpleSimpleInterfaceOLinkFixture.h"
#include "Generated/OLink/TbSimpleSimpleInterfaceOLinkClient.h"
#include "Generated/OLink/TbSimpleSimpleInterfaceOLinkAdapter.h"
#include "OLinkHost.h"
#include "OLinkClientConnection.h" // for olink factory
#include "TbSimpleTestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSimpleSimpleInterfaceOLinkSpec::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	// ImplFixture->testDoneDelegate.Execute();
	// InTestDoneDelegate.Execute();
	if (bSubscribed)
	{
		testDoneDelegate.Execute();
	}
}

void UTbSimpleSimpleInterfaceOLinkSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbSimpleSimpleInterfaceOLinkFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		// needed for callbacks
		ImplFixture->GetHelper()->SetSpec(this);

		// set up service and adapter
		ImplFixture->GetHost()->Stop();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSimpleSimpleInterface>();
		ImplFixture->GetAdapter()->setBackendService(service);
		ImplFixture->GetAdapter()->setOLinkHost(ImplFixture->GetHost());
		ImplFixture->GetHost()->Start(8666);

		// setup client
		testDoneDelegate = TestDone;
		UTbSimpleSimpleInterfaceOLinkClient* OLinkClient = Cast<UTbSimpleSimpleInterfaceOLinkClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid OLink client", OLinkClient != nullptr);

		OLinkClient->_SubscriptionStatusChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleInterfaceOLinkHelper::_SubscriptionStatusChangedCb);

		ImplFixture->Connection = OLinkFactory::Create(OLinkClient, "TestingConnection");
		ImplFixture->Connection->Configure("ws://127.0.0.1:8666/ws", false);

		OLinkClient->UseConnection(ImplFixture->Connection);
		ImplFixture->Connection->Connect();
	});

	AfterEach([this]()
		{
		ImplFixture->Connection->Disconnect();
		ImplFixture.Reset();
	});

	It("Property.PropBool.Default", [this]()
		{
		// Do implement test here
		bool TestValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropBool(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropBool.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		bool TestValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropBool(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleInterfaceSignals->OnPropBoolChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleInterfaceOLinkHelper::PropBoolPropertyCb);
		// use different test value
		TestValue = true;
		ImplFixture->GetImplementation()->Execute_SetPropBool(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Property.PropInt.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropInt(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropInt.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropInt(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleInterfaceSignals->OnPropIntChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleInterfaceOLinkHelper::PropIntPropertyCb);
		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->Execute_SetPropInt(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Property.PropInt32.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropInt32(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropInt32.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropInt32(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleInterfaceSignals->OnPropInt32Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleInterfaceOLinkHelper::PropInt32PropertyCb);
		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->Execute_SetPropInt32(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Property.PropInt64.Default", [this]()
		{
		// Do implement test here
		int64 TestValue = 0LL; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropInt64(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropInt64.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int64 TestValue = 0LL; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropInt64(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleInterfaceSignals->OnPropInt64Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleInterfaceOLinkHelper::PropInt64PropertyCb);
		// use different test value
		TestValue = 1LL;
		ImplFixture->GetImplementation()->Execute_SetPropInt64(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Property.PropFloat.Default", [this]()
		{
		// Do implement test here
		float TestValue = 0.0f; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropFloat(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropFloat.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		float TestValue = 0.0f; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropFloat(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleInterfaceSignals->OnPropFloatChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleInterfaceOLinkHelper::PropFloatPropertyCb);
		// use different test value
		TestValue = 1.0f;
		ImplFixture->GetImplementation()->Execute_SetPropFloat(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Property.PropFloat32.Default", [this]()
		{
		// Do implement test here
		float TestValue = 0.0f; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropFloat32(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropFloat32.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		float TestValue = 0.0f; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropFloat32(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleInterfaceSignals->OnPropFloat32Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleInterfaceOLinkHelper::PropFloat32PropertyCb);
		// use different test value
		TestValue = 1.0f;
		ImplFixture->GetImplementation()->Execute_SetPropFloat32(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Property.PropFloat64.Default", [this]()
		{
		// Do implement test here
		double TestValue = 0.0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropFloat64(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropFloat64.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		double TestValue = 0.0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropFloat64(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleInterfaceSignals->OnPropFloat64Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleInterfaceOLinkHelper::PropFloat64PropertyCb);
		// use different test value
		TestValue = 1.0;
		ImplFixture->GetImplementation()->Execute_SetPropFloat64(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Property.PropString.Default", [this]()
		{
		// Do implement test here
		FString TestValue = FString(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropString(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropString.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FString TestValue = FString(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropString(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleInterfaceSignals->OnPropStringChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleInterfaceOLinkHelper::PropStringPropertyCb);
		// use different test value
		TestValue = FString("xyz");
		ImplFixture->GetImplementation()->Execute_SetPropString(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Operation.FuncNoReturnValue", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_FuncNoReturnValue(ImplFixture->GetImplementation().GetObject(), false);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_FuncBool(ImplFixture->GetImplementation().GetObject(), false);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_FuncInt(ImplFixture->GetImplementation().GetObject(), 0);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncInt32", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_FuncInt32(ImplFixture->GetImplementation().GetObject(), 0);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncInt64", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_FuncInt64(ImplFixture->GetImplementation().GetObject(), 0LL);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_FuncFloat(ImplFixture->GetImplementation().GetObject(), 0.0f);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncFloat32", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_FuncFloat32(ImplFixture->GetImplementation().GetObject(), 0.0f);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncFloat64", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_FuncFloat64(ImplFixture->GetImplementation().GetObject(), 0.0);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_FuncString(ImplFixture->GetImplementation().GetObject(), FString());
			TestDone.Execute();
		});
	});

	LatentIt("Signal.SigBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleInterfaceSignals->OnSigBoolSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleInterfaceOLinkHelper::SigBoolSignalCb);

		// use different test value
		bool bParamBoolTestValue = true;
		TbSimpleSimpleInterfaceSignals->BroadcastSigBoolSignal(bParamBoolTestValue);
	});

	LatentIt("Signal.SigInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleInterfaceSignals->OnSigIntSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleInterfaceOLinkHelper::SigIntSignalCb);

		// use different test value
		int32 ParamIntTestValue = 1;
		TbSimpleSimpleInterfaceSignals->BroadcastSigIntSignal(ParamIntTestValue);
	});

	LatentIt("Signal.SigInt32", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleInterfaceSignals->OnSigInt32Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleInterfaceOLinkHelper::SigInt32SignalCb);

		// use different test value
		int32 ParamInt32TestValue = 1;
		TbSimpleSimpleInterfaceSignals->BroadcastSigInt32Signal(ParamInt32TestValue);
	});

	LatentIt("Signal.SigInt64", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleInterfaceSignals->OnSigInt64Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleInterfaceOLinkHelper::SigInt64SignalCb);

		// use different test value
		int64 ParamInt64TestValue = 1LL;
		TbSimpleSimpleInterfaceSignals->BroadcastSigInt64Signal(ParamInt64TestValue);
	});

	LatentIt("Signal.SigFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleInterfaceSignals->OnSigFloatSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleInterfaceOLinkHelper::SigFloatSignalCb);

		// use different test value
		float ParamFloatTestValue = 1.0f;
		TbSimpleSimpleInterfaceSignals->BroadcastSigFloatSignal(ParamFloatTestValue);
	});

	LatentIt("Signal.SigFloat32", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleInterfaceSignals->OnSigFloat32Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleInterfaceOLinkHelper::SigFloat32SignalCb);

		// use different test value
		float ParamFloat32TestValue = 1.0f;
		TbSimpleSimpleInterfaceSignals->BroadcastSigFloat32Signal(ParamFloat32TestValue);
	});

	LatentIt("Signal.SigFloat64", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleInterfaceSignals->OnSigFloat64Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleInterfaceOLinkHelper::SigFloat64SignalCb);

		// use different test value
		double ParamFloat64TestValue = 1.0;
		TbSimpleSimpleInterfaceSignals->BroadcastSigFloat64Signal(ParamFloat64TestValue);
	});

	LatentIt("Signal.SigString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleInterfaceSignals* TbSimpleSimpleInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleInterfaceSignals->OnSigStringSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleInterfaceOLinkHelper::SigStringSignalCb);

		// use different test value
		FString ParamStringTestValue = FString("xyz");
		TbSimpleSimpleInterfaceSignals->BroadcastSigStringSignal(ParamStringTestValue);
	});
}

void UTbSimpleSimpleInterfaceOLinkSpec::PropBoolPropertyCb(bool bInPropBool)
{
	bool TestValue = false;
	// use different test value
	TestValue = true;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInPropBool, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropBool(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkSpec::PropIntPropertyCb(int32 InPropInt)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropInt(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkSpec::PropInt32PropertyCb(int32 InPropInt32)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt32, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropInt32(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkSpec::PropInt64PropertyCb(int64 InPropInt64)
{
	int64 TestValue = 0LL;
	// use different test value
	TestValue = 1LL;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt64, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropInt64(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkSpec::PropFloatPropertyCb(float InPropFloat)
{
	float TestValue = 0.0f;
	// use different test value
	TestValue = 1.0f;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropFloat(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkSpec::PropFloat32PropertyCb(float InPropFloat32)
{
	float TestValue = 0.0f;
	// use different test value
	TestValue = 1.0f;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat32, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropFloat32(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkSpec::PropFloat64PropertyCb(double InPropFloat64)
{
	double TestValue = 0.0;
	// use different test value
	TestValue = 1.0;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat64, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropFloat64(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkSpec::PropStringPropertyCb(const FString& InPropString)
{
	FString TestValue = FString();
	// use different test value
	TestValue = FString("xyz");
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropString(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkSpec::SigBoolSignalCb(bool bInParamBool)
{
	// known test value
	bool bParamBoolTestValue = true;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), bInParamBool, bParamBoolTestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkSpec::SigIntSignalCb(int32 InParamInt)
{
	// known test value
	int32 ParamIntTestValue = 1;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt, ParamIntTestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkSpec::SigInt32SignalCb(int32 InParamInt32)
{
	// known test value
	int32 ParamInt32TestValue = 1;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt32, ParamInt32TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkSpec::SigInt64SignalCb(int64 InParamInt64)
{
	// known test value
	int64 ParamInt64TestValue = 1LL;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt64, ParamInt64TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkSpec::SigFloatSignalCb(float InParamFloat)
{
	// known test value
	float ParamFloatTestValue = 1.0f;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat, ParamFloatTestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkSpec::SigFloat32SignalCb(float InParamFloat32)
{
	// known test value
	float ParamFloat32TestValue = 1.0f;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat32, ParamFloat32TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkSpec::SigFloat64SignalCb(double InParamFloat64)
{
	// known test value
	double ParamFloat64TestValue = 1.0;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat64, ParamFloat64TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleInterfaceOLinkSpec::SigStringSignalCb(const FString& InParamString)
{
	// known test value
	FString ParamStringTestValue = FString("xyz");
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamString, ParamStringTestValue);
	testDoneDelegate.Execute();
}
#endif // WITH_DEV_AUTOMATION_TESTS
