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

#include "TbSimpleSimpleArrayInterfaceOLink.spec.h"
#include "TbSimpleSimpleArrayInterfaceOLinkFixture.h"
#include "TbSimple/Implementation/TbSimpleSimpleArrayInterface.h"
#include "TbSimple/Generated/OLink/TbSimpleSimpleArrayInterfaceOLinkClient.h"
#include "TbSimple/Generated/OLink/TbSimpleSimpleArrayInterfaceOLinkAdapter.h"
#include "HAL/Platform.h"

#if !(PLATFORM_IOS || PLATFORM_ANDROID)
#include "OLinkHost.h"
#include "OLinkClientConnection.h" // for olink factory
#include "TbSimple/Tests/TbSimpleTestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSimpleSimpleArrayInterfaceOLinkSpec::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	// ImplFixture->testDoneDelegate.Execute();
	// InTestDoneDelegate.Execute();
	if (bSubscribed)
	{
		testDoneDelegate.Execute();
	}
}

void UTbSimpleSimpleArrayInterfaceOLinkSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbSimpleSimpleArrayInterfaceOLinkFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		// needed for callbacks
		ImplFixture->GetHelper()->SetSpec(this);

		// set up service and adapter
		ImplFixture->GetHost()->Stop();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterface>();
		ImplFixture->GetAdapter()->setBackendService(service);
		ImplFixture->GetAdapter()->setOLinkHost(ImplFixture->GetHost());
		ImplFixture->GetHost()->Start(8666);

		// setup client
		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceOLinkClient* OLinkClient = Cast<UTbSimpleSimpleArrayInterfaceOLinkClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid OLink client", OLinkClient != nullptr);

		OLinkClient->_SubscriptionStatusChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceOLinkHelper::_SubscriptionStatusChangedCb);

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
		TArray<bool> TestValue = TArray<bool>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);
	});

	LatentIt("Property.PropBool.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<bool> TestValue = TArray<bool>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleSimpleArrayInterfaceSignals->OnPropBoolChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceOLinkHelper::PropBoolPropertyCb);
		// use different test value
		TestValue.Add(true);
		ImplFixture->GetImplementation()->SetPropBool(TestValue);
	});

	It("Property.PropInt.Default", [this]()
		{
		// Do implement test here
		TArray<int32> TestValue = TArray<int32>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);
	});

	LatentIt("Property.PropInt.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<int32> TestValue = TArray<int32>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleSimpleArrayInterfaceSignals->OnPropIntChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceOLinkHelper::PropIntPropertyCb);
		// use different test value
		TestValue.Add(1);
		ImplFixture->GetImplementation()->SetPropInt(TestValue);
	});

	It("Property.PropInt32.Default", [this]()
		{
		// Do implement test here
		TArray<int32> TestValue = TArray<int32>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt32(), TestValue);
	});

	LatentIt("Property.PropInt32.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<int32> TestValue = TArray<int32>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt32(), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleSimpleArrayInterfaceSignals->OnPropInt32Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceOLinkHelper::PropInt32PropertyCb);
		// use different test value
		TestValue.Add(1);
		ImplFixture->GetImplementation()->SetPropInt32(TestValue);
	});

	It("Property.PropInt64.Default", [this]()
		{
		// Do implement test here
		TArray<int64> TestValue = TArray<int64>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt64(), TestValue);
	});

	LatentIt("Property.PropInt64.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<int64> TestValue = TArray<int64>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt64(), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleSimpleArrayInterfaceSignals->OnPropInt64Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceOLinkHelper::PropInt64PropertyCb);
		// use different test value
		TestValue.Add(1LL);
		ImplFixture->GetImplementation()->SetPropInt64(TestValue);
	});

	It("Property.PropFloat.Default", [this]()
		{
		// Do implement test here
		TArray<float> TestValue = TArray<float>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);
	});

	LatentIt("Property.PropFloat.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<float> TestValue = TArray<float>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleSimpleArrayInterfaceSignals->OnPropFloatChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceOLinkHelper::PropFloatPropertyCb);
		// use different test value
		TestValue.Add(1.0f);
		ImplFixture->GetImplementation()->SetPropFloat(TestValue);
	});

	It("Property.PropFloat32.Default", [this]()
		{
		// Do implement test here
		TArray<float> TestValue = TArray<float>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat32(), TestValue);
	});

	LatentIt("Property.PropFloat32.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<float> TestValue = TArray<float>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat32(), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleSimpleArrayInterfaceSignals->OnPropFloat32Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceOLinkHelper::PropFloat32PropertyCb);
		// use different test value
		TestValue.Add(1.0f);
		ImplFixture->GetImplementation()->SetPropFloat32(TestValue);
	});

	It("Property.PropFloat64.Default", [this]()
		{
		// Do implement test here
		TArray<double> TestValue = TArray<double>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat64(), TestValue);
	});

	LatentIt("Property.PropFloat64.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<double> TestValue = TArray<double>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat64(), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleSimpleArrayInterfaceSignals->OnPropFloat64Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceOLinkHelper::PropFloat64PropertyCb);
		// use different test value
		TestValue.Add(1.0);
		ImplFixture->GetImplementation()->SetPropFloat64(TestValue);
	});

	It("Property.PropString.Default", [this]()
		{
		// Do implement test here
		TArray<FString> TestValue = TArray<FString>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropString(), TestValue);
	});

	LatentIt("Property.PropString.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FString> TestValue = TArray<FString>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropString(), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleSimpleArrayInterfaceSignals->OnPropStringChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceOLinkHelper::PropStringPropertyCb);
		// use different test value
		TestValue.Add(FString("xyz"));
		ImplFixture->GetImplementation()->SetPropString(TestValue);
	});

	It("Property.PropReadOnlyString.Default", [this]()
		{
		// Do implement test here
		FString TestValue = FString(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropReadOnlyString(), FString());
	});

	LatentIt("Operation.FuncBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncBool(TArray<bool>());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncInt(TArray<int32>());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncInt32", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncInt32(TArray<int32>());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncInt64", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncInt64(TArray<int64>());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncFloat(TArray<float>());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncFloat32", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncFloat32(TArray<float>());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncFloat64", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncFloat64(TArray<double>());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncString(TArray<FString>());
			TestDone.Execute();
		});
	});

	LatentIt("Signal.SigBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleSimpleArrayInterfaceSignals->OnSigBoolSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceOLinkHelper::SigBoolSignalCb);

		// use different test value
		TArray<bool> ParamBoolTestValue = TArray<bool>(); // default value
		ParamBoolTestValue.Add(true);
		TbSimpleSimpleArrayInterfaceSignals->BroadcastSigBoolSignal(ParamBoolTestValue);
	});

	LatentIt("Signal.SigInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleSimpleArrayInterfaceSignals->OnSigIntSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceOLinkHelper::SigIntSignalCb);

		// use different test value
		TArray<int32> ParamIntTestValue = TArray<int32>(); // default value
		ParamIntTestValue.Add(1);
		TbSimpleSimpleArrayInterfaceSignals->BroadcastSigIntSignal(ParamIntTestValue);
	});

	LatentIt("Signal.SigInt32", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleSimpleArrayInterfaceSignals->OnSigInt32Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceOLinkHelper::SigInt32SignalCb);

		// use different test value
		TArray<int32> ParamInt32TestValue = TArray<int32>(); // default value
		ParamInt32TestValue.Add(1);
		TbSimpleSimpleArrayInterfaceSignals->BroadcastSigInt32Signal(ParamInt32TestValue);
	});

	LatentIt("Signal.SigInt64", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleSimpleArrayInterfaceSignals->OnSigInt64Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceOLinkHelper::SigInt64SignalCb);

		// use different test value
		TArray<int64> ParamInt64TestValue = TArray<int64>(); // default value
		ParamInt64TestValue.Add(1LL);
		TbSimpleSimpleArrayInterfaceSignals->BroadcastSigInt64Signal(ParamInt64TestValue);
	});

	LatentIt("Signal.SigFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleSimpleArrayInterfaceSignals->OnSigFloatSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceOLinkHelper::SigFloatSignalCb);

		// use different test value
		TArray<float> ParamFloatTestValue = TArray<float>(); // default value
		ParamFloatTestValue.Add(1.0f);
		TbSimpleSimpleArrayInterfaceSignals->BroadcastSigFloatSignal(ParamFloatTestValue);
	});

	LatentIt("Signal.SigFloat32", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleSimpleArrayInterfaceSignals->OnSigFloat32Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceOLinkHelper::SigFloat32SignalCb);

		// use different test value
		TArray<float> ParamFloa32TestValue = TArray<float>(); // default value
		ParamFloa32TestValue.Add(1.0f);
		TbSimpleSimpleArrayInterfaceSignals->BroadcastSigFloat32Signal(ParamFloa32TestValue);
	});

	LatentIt("Signal.SigFloat64", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleSimpleArrayInterfaceSignals->OnSigFloat64Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceOLinkHelper::SigFloat64SignalCb);

		// use different test value
		TArray<double> ParamFloat64TestValue = TArray<double>(); // default value
		ParamFloat64TestValue.Add(1.0);
		TbSimpleSimpleArrayInterfaceSignals->BroadcastSigFloat64Signal(ParamFloat64TestValue);
	});

	LatentIt("Signal.SigString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleSimpleArrayInterfaceSignals->OnSigStringSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceOLinkHelper::SigStringSignalCb);

		// use different test value
		TArray<FString> ParamStringTestValue = TArray<FString>(); // default value
		ParamStringTestValue.Add(FString("xyz"));
		TbSimpleSimpleArrayInterfaceSignals->BroadcastSigStringSignal(ParamStringTestValue);
	});
}

void UTbSimpleSimpleArrayInterfaceOLinkSpec::PropBoolPropertyCb(const TArray<bool>& InPropBool)
{
	TArray<bool> TestValue = TArray<bool>();
	// use different test value
	TestValue.Add(true);
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkSpec::PropIntPropertyCb(const TArray<int32>& InPropInt)
{
	TArray<int32> TestValue = TArray<int32>();
	// use different test value
	TestValue.Add(1);
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkSpec::PropInt32PropertyCb(const TArray<int32>& InPropInt32)
{
	TArray<int32> TestValue = TArray<int32>();
	// use different test value
	TestValue.Add(1);
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt32, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropInt32(), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkSpec::PropInt64PropertyCb(const TArray<int64>& InPropInt64)
{
	TArray<int64> TestValue = TArray<int64>();
	// use different test value
	TestValue.Add(1LL);
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt64, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropInt64(), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkSpec::PropFloatPropertyCb(const TArray<float>& InPropFloat)
{
	TArray<float> TestValue = TArray<float>();
	// use different test value
	TestValue.Add(1.0f);
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkSpec::PropFloat32PropertyCb(const TArray<float>& InPropFloat32)
{
	TArray<float> TestValue = TArray<float>();
	// use different test value
	TestValue.Add(1.0f);
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat32, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropFloat32(), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkSpec::PropFloat64PropertyCb(const TArray<double>& InPropFloat64)
{
	TArray<double> TestValue = TArray<double>();
	// use different test value
	TestValue.Add(1.0);
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat64, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropFloat64(), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkSpec::PropStringPropertyCb(const TArray<FString>& InPropString)
{
	TArray<FString> TestValue = TArray<FString>();
	// use different test value
	TestValue.Add(FString("xyz"));
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropString(), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkSpec::SigBoolSignalCb(const TArray<bool>& InParamBool)
{
	// known test value
	TArray<bool> ParamBoolTestValue = TArray<bool>(); // default value
	ParamBoolTestValue.Add(true);
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamBool, ParamBoolTestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkSpec::SigIntSignalCb(const TArray<int32>& InParamInt)
{
	// known test value
	TArray<int32> ParamIntTestValue = TArray<int32>(); // default value
	ParamIntTestValue.Add(1);
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt, ParamIntTestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkSpec::SigInt32SignalCb(const TArray<int32>& InParamInt32)
{
	// known test value
	TArray<int32> ParamInt32TestValue = TArray<int32>(); // default value
	ParamInt32TestValue.Add(1);
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt32, ParamInt32TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkSpec::SigInt64SignalCb(const TArray<int64>& InParamInt64)
{
	// known test value
	TArray<int64> ParamInt64TestValue = TArray<int64>(); // default value
	ParamInt64TestValue.Add(1LL);
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt64, ParamInt64TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkSpec::SigFloatSignalCb(const TArray<float>& InParamFloat)
{
	// known test value
	TArray<float> ParamFloatTestValue = TArray<float>(); // default value
	ParamFloatTestValue.Add(1.0f);
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat, ParamFloatTestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkSpec::SigFloat32SignalCb(const TArray<float>& InParamFloa32)
{
	// known test value
	TArray<float> ParamFloa32TestValue = TArray<float>(); // default value
	ParamFloa32TestValue.Add(1.0f);
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloa32, ParamFloa32TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkSpec::SigFloat64SignalCb(const TArray<double>& InParamFloat64)
{
	// known test value
	TArray<double> ParamFloat64TestValue = TArray<double>(); // default value
	ParamFloat64TestValue.Add(1.0);
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat64, ParamFloat64TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceOLinkSpec::SigStringSignalCb(const TArray<FString>& InParamString)
{
	// known test value
	TArray<FString> ParamStringTestValue = TArray<FString>(); // default value
	ParamStringTestValue.Add(FString("xyz"));
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamString, ParamStringTestValue);
	testDoneDelegate.Execute();
}
#endif // WITH_DEV_AUTOMATION_TESTS
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID)
