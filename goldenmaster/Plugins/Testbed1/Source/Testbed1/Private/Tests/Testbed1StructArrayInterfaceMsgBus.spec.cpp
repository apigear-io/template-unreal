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

#include "Testbed1StructArrayInterfaceMsgBus.spec.h"
#include "Implementation/Testbed1StructArrayInterface.h"
#include "Testbed1StructArrayInterfaceMsgBusFixture.h"
#include "Generated/MsgBus/Testbed1StructArrayInterfaceMsgBusClient.h"
#include "Generated/MsgBus/Testbed1StructArrayInterfaceMsgBusAdapter.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTestbed1StructArrayInterfaceMsgBusSpec::_ConnectionStatusChangedCb(bool bConnected)
{
	if (bConnected)
	{
		testDoneDelegate.Execute();
	}
}

void UTestbed1StructArrayInterfaceMsgBusSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTestbed1StructArrayInterfaceMsgBusFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		// needed for callbacks
		ImplFixture->GetHelper()->SetSpec(this);

		// set up service and adapter
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterface>();
		ImplFixture->GetAdapter()->_setBackendService(service);
		ImplFixture->GetAdapter()->_StartListening();

		// setup client
		testDoneDelegate = TestDone;
		UTestbed1StructArrayInterfaceMsgBusClient* MsgBusClient = Cast<UTestbed1StructArrayInterfaceMsgBusClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid MsgBus client", MsgBusClient != nullptr);

		MsgBusClient->_ConnectionStatusChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArrayInterfaceMsgBusHelper::_ConnectionStatusChangedCb);

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
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropBool(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropBool.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropBool(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed1StructArrayInterfaceSignals->OnPropBoolChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArrayInterfaceMsgBusHelper::PropBoolPropertyCb);
		// use different test value
		TestValue = createTestFTestbed1StructBoolArray();
		ImplFixture->GetImplementation()->Execute_SetPropBool(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Property.PropBool.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropBool(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed1StructArrayInterfaceSignals->OnPropBoolChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArrayInterfaceMsgBusHelper::PropBoolPropertyChangeLocalCheckRemoteCb);
		// use different test value
		TestValue = createTestFTestbed1StructBoolArray();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterface>();
		service->Execute_SetPropBool(service, TestValue);
	});

	LatentIt("Property.PropBool.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropBool(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed1StructArrayInterfaceSignals->OnPropBoolChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArrayInterfaceMsgBusHelper::PropBoolPropertyChangeLocalChangeRemoteCb);
		// use different test value
		TestValue = createTestFTestbed1StructBoolArray();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterface>();
		service->Execute_SetPropBool(service, TestValue);
	});

	It("Property.PropInt.Default", [this]()
		{
		// Do implement test here
		TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropInt(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropInt.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropInt(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed1StructArrayInterfaceSignals->OnPropIntChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArrayInterfaceMsgBusHelper::PropIntPropertyCb);
		// use different test value
		TestValue = createTestFTestbed1StructIntArray();
		ImplFixture->GetImplementation()->Execute_SetPropInt(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Property.PropInt.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropInt(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed1StructArrayInterfaceSignals->OnPropIntChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArrayInterfaceMsgBusHelper::PropIntPropertyChangeLocalCheckRemoteCb);
		// use different test value
		TestValue = createTestFTestbed1StructIntArray();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterface>();
		service->Execute_SetPropInt(service, TestValue);
	});

	LatentIt("Property.PropInt.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropInt(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed1StructArrayInterfaceSignals->OnPropIntChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArrayInterfaceMsgBusHelper::PropIntPropertyChangeLocalChangeRemoteCb);
		// use different test value
		TestValue = createTestFTestbed1StructIntArray();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterface>();
		service->Execute_SetPropInt(service, TestValue);
	});

	It("Property.PropFloat.Default", [this]()
		{
		// Do implement test here
		TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropFloat(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropFloat.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropFloat(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed1StructArrayInterfaceSignals->OnPropFloatChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArrayInterfaceMsgBusHelper::PropFloatPropertyCb);
		// use different test value
		TestValue = createTestFTestbed1StructFloatArray();
		ImplFixture->GetImplementation()->Execute_SetPropFloat(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Property.PropFloat.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropFloat(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed1StructArrayInterfaceSignals->OnPropFloatChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArrayInterfaceMsgBusHelper::PropFloatPropertyChangeLocalCheckRemoteCb);
		// use different test value
		TestValue = createTestFTestbed1StructFloatArray();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterface>();
		service->Execute_SetPropFloat(service, TestValue);
	});

	LatentIt("Property.PropFloat.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropFloat(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed1StructArrayInterfaceSignals->OnPropFloatChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArrayInterfaceMsgBusHelper::PropFloatPropertyChangeLocalChangeRemoteCb);
		// use different test value
		TestValue = createTestFTestbed1StructFloatArray();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterface>();
		service->Execute_SetPropFloat(service, TestValue);
	});

	It("Property.PropString.Default", [this]()
		{
		// Do implement test here
		TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropString(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropString.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropString(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed1StructArrayInterfaceSignals->OnPropStringChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArrayInterfaceMsgBusHelper::PropStringPropertyCb);
		// use different test value
		TestValue = createTestFTestbed1StructStringArray();
		ImplFixture->GetImplementation()->Execute_SetPropString(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Property.PropString.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropString(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed1StructArrayInterfaceSignals->OnPropStringChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArrayInterfaceMsgBusHelper::PropStringPropertyChangeLocalCheckRemoteCb);
		// use different test value
		TestValue = createTestFTestbed1StructStringArray();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterface>();
		service->Execute_SetPropString(service, TestValue);
	});

	LatentIt("Property.PropString.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropString(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed1StructArrayInterfaceSignals->OnPropStringChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArrayInterfaceMsgBusHelper::PropStringPropertyChangeLocalChangeRemoteCb);
		// use different test value
		TestValue = createTestFTestbed1StructStringArray();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterface>();
		service->Execute_SetPropString(service, TestValue);
	});

	It("Property.PropEnum.Default", [this]()
		{
		// Do implement test here
		TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropEnum(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropEnum.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropEnum(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed1StructArrayInterfaceSignals->OnPropEnumChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArrayInterfaceMsgBusHelper::PropEnumPropertyCb);
		// use different test value
		TestValue.Add(ETestbed1Enum0::T1E0_VALUE1);
		ImplFixture->GetImplementation()->Execute_SetPropEnum(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Property.PropEnum.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropEnum(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed1StructArrayInterfaceSignals->OnPropEnumChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArrayInterfaceMsgBusHelper::PropEnumPropertyChangeLocalCheckRemoteCb);
		// use different test value
		TestValue.Add(ETestbed1Enum0::T1E0_VALUE1);
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterface>();
		service->Execute_SetPropEnum(service, TestValue);
	});

	LatentIt("Property.PropEnum.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropEnum(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed1StructArrayInterfaceSignals->OnPropEnumChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArrayInterfaceMsgBusHelper::PropEnumPropertyChangeLocalChangeRemoteCb);
		// use different test value
		TestValue.Add(ETestbed1Enum0::T1E0_VALUE1);
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterface>();
		service->Execute_SetPropEnum(service, TestValue);
	});

	LatentIt("Operation.FuncBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_FuncBool(ImplFixture->GetImplementation().GetObject(), TArray<FTestbed1StructBool>());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_FuncInt(ImplFixture->GetImplementation().GetObject(), TArray<FTestbed1StructInt>());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_FuncFloat(ImplFixture->GetImplementation().GetObject(), TArray<FTestbed1StructFloat>());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_FuncString(ImplFixture->GetImplementation().GetObject(), TArray<FTestbed1StructString>());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncEnum", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_FuncEnum(ImplFixture->GetImplementation().GetObject(), TArray<ETestbed1Enum0>());
			TestDone.Execute();
		});
	});

	LatentIt("Signal.SigBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed1StructArrayInterfaceSignals->OnSigBoolSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArrayInterfaceMsgBusHelper::SigBoolSignalCb);

		// use different test value
		TArray<FTestbed1StructBool> ParamBoolTestValue = createTestFTestbed1StructBoolArray();
		Testbed1StructArrayInterfaceSignals->BroadcastSigBoolSignal(ParamBoolTestValue);
	});

	LatentIt("Signal.SigInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed1StructArrayInterfaceSignals->OnSigIntSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArrayInterfaceMsgBusHelper::SigIntSignalCb);

		// use different test value
		TArray<FTestbed1StructInt> ParamIntTestValue = createTestFTestbed1StructIntArray();
		Testbed1StructArrayInterfaceSignals->BroadcastSigIntSignal(ParamIntTestValue);
	});

	LatentIt("Signal.SigFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed1StructArrayInterfaceSignals->OnSigFloatSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArrayInterfaceMsgBusHelper::SigFloatSignalCb);

		// use different test value
		TArray<FTestbed1StructFloat> ParamFloatTestValue = createTestFTestbed1StructFloatArray();
		Testbed1StructArrayInterfaceSignals->BroadcastSigFloatSignal(ParamFloatTestValue);
	});

	LatentIt("Signal.SigString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed1StructArrayInterfaceSignals->OnSigStringSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArrayInterfaceMsgBusHelper::SigStringSignalCb);

		// use different test value
		TArray<FTestbed1StructString> ParamStringTestValue = createTestFTestbed1StructStringArray();
		Testbed1StructArrayInterfaceSignals->BroadcastSigStringSignal(ParamStringTestValue);
	});

	LatentIt("Signal.SigEnum", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTestbed1StructArrayInterfaceSignals* Testbed1StructArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed1StructArrayInterfaceSignals->OnSigEnumSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed1StructArrayInterfaceMsgBusHelper::SigEnumSignalCb);

		// use different test value
		TArray<ETestbed1Enum0> ParamEnumTestValue = TArray<ETestbed1Enum0>(); // default value
		ParamEnumTestValue.Add(ETestbed1Enum0::T1E0_VALUE1);
		Testbed1StructArrayInterfaceSignals->BroadcastSigEnumSignal(ParamEnumTestValue);
	});
}

void UTestbed1StructArrayInterfaceMsgBusSpec::PropBoolPropertyCb(const TArray<FTestbed1StructBool>& InPropBool)
{
	TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>();
	// use different test value
	TestValue = createTestFTestbed1StructBoolArray();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropBool(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceMsgBusSpec::PropBoolPropertyChangeLocalCheckRemoteCb(const TArray<FTestbed1StructBool>& InPropBool)
{
	TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>();
	// use different test value
	TestValue = createTestFTestbed1StructBoolArray();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropBool(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceMsgBusSpec::PropBoolPropertyChangeLocalChangeRemoteCb(const TArray<FTestbed1StructBool>& InPropBool)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>();
		// use different test value
		TestValue = createTestFTestbed1StructBoolArray();
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropBool(ImplFixture->GetImplementation().GetObject()), TestValue);

		// now set it to the default value
		TestValue = TArray<FTestbed1StructBool>(); // default value
		ImplFixture->GetImplementation()->Execute_SetPropBool(ImplFixture->GetImplementation().GetObject(), TestValue);
	}
	else
	{
		TArray<FTestbed1StructBool> TestValue = TArray<FTestbed1StructBool>(); // default value
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropBool(ImplFixture->GetImplementation().GetObject()), TestValue);
		testDoneDelegate.Execute();
	}
}

void UTestbed1StructArrayInterfaceMsgBusSpec::PropIntPropertyCb(const TArray<FTestbed1StructInt>& InPropInt)
{
	TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>();
	// use different test value
	TestValue = createTestFTestbed1StructIntArray();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropInt(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceMsgBusSpec::PropIntPropertyChangeLocalCheckRemoteCb(const TArray<FTestbed1StructInt>& InPropInt)
{
	TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>();
	// use different test value
	TestValue = createTestFTestbed1StructIntArray();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropInt(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceMsgBusSpec::PropIntPropertyChangeLocalChangeRemoteCb(const TArray<FTestbed1StructInt>& InPropInt)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>();
		// use different test value
		TestValue = createTestFTestbed1StructIntArray();
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropInt(ImplFixture->GetImplementation().GetObject()), TestValue);

		// now set it to the default value
		TestValue = TArray<FTestbed1StructInt>(); // default value
		ImplFixture->GetImplementation()->Execute_SetPropInt(ImplFixture->GetImplementation().GetObject(), TestValue);
	}
	else
	{
		TArray<FTestbed1StructInt> TestValue = TArray<FTestbed1StructInt>(); // default value
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropInt(ImplFixture->GetImplementation().GetObject()), TestValue);
		testDoneDelegate.Execute();
	}
}

void UTestbed1StructArrayInterfaceMsgBusSpec::PropFloatPropertyCb(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>();
	// use different test value
	TestValue = createTestFTestbed1StructFloatArray();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropFloat(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceMsgBusSpec::PropFloatPropertyChangeLocalCheckRemoteCb(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>();
	// use different test value
	TestValue = createTestFTestbed1StructFloatArray();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropFloat(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceMsgBusSpec::PropFloatPropertyChangeLocalChangeRemoteCb(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>();
		// use different test value
		TestValue = createTestFTestbed1StructFloatArray();
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropFloat(ImplFixture->GetImplementation().GetObject()), TestValue);

		// now set it to the default value
		TestValue = TArray<FTestbed1StructFloat>(); // default value
		ImplFixture->GetImplementation()->Execute_SetPropFloat(ImplFixture->GetImplementation().GetObject(), TestValue);
	}
	else
	{
		TArray<FTestbed1StructFloat> TestValue = TArray<FTestbed1StructFloat>(); // default value
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropFloat(ImplFixture->GetImplementation().GetObject()), TestValue);
		testDoneDelegate.Execute();
	}
}

void UTestbed1StructArrayInterfaceMsgBusSpec::PropStringPropertyCb(const TArray<FTestbed1StructString>& InPropString)
{
	TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>();
	// use different test value
	TestValue = createTestFTestbed1StructStringArray();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropString(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceMsgBusSpec::PropStringPropertyChangeLocalCheckRemoteCb(const TArray<FTestbed1StructString>& InPropString)
{
	TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>();
	// use different test value
	TestValue = createTestFTestbed1StructStringArray();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropString(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceMsgBusSpec::PropStringPropertyChangeLocalChangeRemoteCb(const TArray<FTestbed1StructString>& InPropString)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>();
		// use different test value
		TestValue = createTestFTestbed1StructStringArray();
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropString(ImplFixture->GetImplementation().GetObject()), TestValue);

		// now set it to the default value
		TestValue = TArray<FTestbed1StructString>(); // default value
		ImplFixture->GetImplementation()->Execute_SetPropString(ImplFixture->GetImplementation().GetObject(), TestValue);
	}
	else
	{
		TArray<FTestbed1StructString> TestValue = TArray<FTestbed1StructString>(); // default value
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropString(ImplFixture->GetImplementation().GetObject()), TestValue);
		testDoneDelegate.Execute();
	}
}

void UTestbed1StructArrayInterfaceMsgBusSpec::PropEnumPropertyCb(const TArray<ETestbed1Enum0>& InPropEnum)
{
	TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>();
	// use different test value
	TestValue.Add(ETestbed1Enum0::T1E0_VALUE1);
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropEnum(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceMsgBusSpec::PropEnumPropertyChangeLocalCheckRemoteCb(const TArray<ETestbed1Enum0>& InPropEnum)
{
	TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>();
	// use different test value
	TestValue.Add(ETestbed1Enum0::T1E0_VALUE1);
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropEnum(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceMsgBusSpec::PropEnumPropertyChangeLocalChangeRemoteCb(const TArray<ETestbed1Enum0>& InPropEnum)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>();
		// use different test value
		TestValue.Add(ETestbed1Enum0::T1E0_VALUE1);
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropEnum(ImplFixture->GetImplementation().GetObject()), TestValue);

		// now set it to the default value
		TestValue = TArray<ETestbed1Enum0>(); // default value
		ImplFixture->GetImplementation()->Execute_SetPropEnum(ImplFixture->GetImplementation().GetObject(), TestValue);
	}
	else
	{
		TArray<ETestbed1Enum0> TestValue = TArray<ETestbed1Enum0>(); // default value
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropEnum(ImplFixture->GetImplementation().GetObject()), TestValue);
		testDoneDelegate.Execute();
	}
}

void UTestbed1StructArrayInterfaceMsgBusSpec::SigBoolSignalCb(const TArray<FTestbed1StructBool>& InParamBool)
{
	// known test value
	TArray<FTestbed1StructBool> ParamBoolTestValue = createTestFTestbed1StructBoolArray();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamBool, ParamBoolTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceMsgBusSpec::SigIntSignalCb(const TArray<FTestbed1StructInt>& InParamInt)
{
	// known test value
	TArray<FTestbed1StructInt> ParamIntTestValue = createTestFTestbed1StructIntArray();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt, ParamIntTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceMsgBusSpec::SigFloatSignalCb(const TArray<FTestbed1StructFloat>& InParamFloat)
{
	// known test value
	TArray<FTestbed1StructFloat> ParamFloatTestValue = createTestFTestbed1StructFloatArray();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat, ParamFloatTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceMsgBusSpec::SigStringSignalCb(const TArray<FTestbed1StructString>& InParamString)
{
	// known test value
	TArray<FTestbed1StructString> ParamStringTestValue = createTestFTestbed1StructStringArray();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamString, ParamStringTestValue);
	testDoneDelegate.Execute();
}

void UTestbed1StructArrayInterfaceMsgBusSpec::SigEnumSignalCb(const TArray<ETestbed1Enum0>& InParamEnum)
{
	// known test value
	TArray<ETestbed1Enum0> ParamEnumTestValue = TArray<ETestbed1Enum0>(); // default value
	ParamEnumTestValue.Add(ETestbed1Enum0::T1E0_VALUE1);
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamEnum, ParamEnumTestValue);
	testDoneDelegate.Execute();
}
#endif // WITH_DEV_AUTOMATION_TESTS
