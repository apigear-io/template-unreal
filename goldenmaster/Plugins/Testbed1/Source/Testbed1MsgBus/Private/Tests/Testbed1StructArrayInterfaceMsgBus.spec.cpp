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

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"

#if !(PLATFORM_IOS || PLATFORM_ANDROID)
#if WITH_DEV_AUTOMATION_TESTS

#include "Testbed1/Tests/Testbed1TestsCommon.h"
#include "Testbed1/Implementation/Testbed1StructArrayInterface.h"
#include "Testbed1StructArrayInterfaceMsgBusFixture.h"
#include "Testbed1/Generated/MsgBus/Testbed1StructArrayInterfaceMsgBusClient.h"
#include "Testbed1/Generated/MsgBus/Testbed1StructArrayInterfaceMsgBusAdapter.h"

BEGIN_DEFINE_SPEC(UTestbed1StructArrayInterfaceMsgBusSpec, "Testbed1.StructArrayInterface.MsgBus", Testbed1TestFilterMask);

TUniquePtr<FTestbed1StructArrayInterfaceMsgBusFixture> ImplFixture;

END_DEFINE_SPEC(UTestbed1StructArrayInterfaceMsgBusSpec);

void UTestbed1StructArrayInterfaceMsgBusSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTestbed1StructArrayInterfaceMsgBusFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// set up service and adapter
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterface>();
		ImplFixture->GetAdapter()->_setBackendService(service);
		ImplFixture->GetAdapter()->_StartListening();

		// setup client
		UTestbed1StructArrayInterfaceMsgBusClient* MsgBusClient = Cast<UTestbed1StructArrayInterfaceMsgBusClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid MsgBus client", MsgBusClient != nullptr);

		MsgBusClient->_ConnectionStatusChanged.AddLambda([this, TestDone](bool bConnected)
			{
			if (bConnected)
			{
				TestDone.Execute();
			}
		});

		MsgBusClient->_Connect();
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

	LatentIt("Operation.FuncBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncBool(TArray<FTestbed1StructBool>());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncInt(TArray<FTestbed1StructInt>());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncFloat(TArray<FTestbed1StructFloat>());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncString(TArray<FTestbed1StructString>());
			TestDone.Execute();
		});
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
}

#endif // WITH_DEV_AUTOMATION_TESTS
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID)
