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

#include "TbSimpleSimpleArrayInterfaceMsgBus.spec.h"
#include "Implementation/TbSimpleSimpleArrayInterface.h"
#include "TbSimpleSimpleArrayInterfaceMsgBusFixture.h"
#include "Generated/MsgBus/TbSimpleSimpleArrayInterfaceMsgBusClient.h"
#include "Generated/MsgBus/TbSimpleSimpleArrayInterfaceMsgBusAdapter.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSimpleSimpleArrayInterfaceMsgBusSpec::_ConnectionStatusChangedCb(bool bConnected)
{
	if (bConnected)
	{
		testDoneDelegate.Execute();
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbSimpleSimpleArrayInterfaceMsgBusFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		// needed for callbacks
		ImplFixture->GetHelper()->SetSpec(this);

		// set up service and adapter
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterface>();
		ImplFixture->GetAdapter()->_setBackendService(service);
		ImplFixture->GetAdapter()->_StartListening();

		// setup client
		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceMsgBusClient* MsgBusClient = Cast<UTbSimpleSimpleArrayInterfaceMsgBusClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid MsgBus client", MsgBusClient != nullptr);

		MsgBusClient->_ConnectionStatusChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceMsgBusHelper::_ConnectionStatusChangedCb);

		MsgBusClient->_Connect();
	});

	AfterEach([this]()
		{
		ImplFixture.Reset();
	});

	It("Property.PropBool.Default", [this]()
		{
		// Do implement test here
		TArray<bool> TestValue = TArray<bool>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropBool(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropBool.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<bool> TestValue = TArray<bool>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropBool(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnPropBoolChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropBoolPropertyCb);
		// use different test value
		TestValue.Add(true);
		ImplFixture->GetImplementation()->Execute_SetPropBool(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Property.PropBool.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<bool> TestValue = TArray<bool>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropBool(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnPropBoolChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropBoolPropertyChangeLocalCheckRemoteCb);
		// use different test value
		TestValue.Add(true);
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterface>();
		service->Execute_SetPropBool(service, TestValue);
	});

	LatentIt("Property.PropBool.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<bool> TestValue = TArray<bool>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropBool(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnPropBoolChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropBoolPropertyChangeLocalChangeRemoteCb);
		// use different test value
		TestValue.Add(true);
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterface>();
		service->Execute_SetPropBool(service, TestValue);
	});

	It("Property.PropInt.Default", [this]()
		{
		// Do implement test here
		TArray<int32> TestValue = TArray<int32>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropInt(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropInt.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<int32> TestValue = TArray<int32>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropInt(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnPropIntChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropIntPropertyCb);
		// use different test value
		TestValue.Add(1);
		ImplFixture->GetImplementation()->Execute_SetPropInt(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Property.PropInt.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<int32> TestValue = TArray<int32>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropInt(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnPropIntChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropIntPropertyChangeLocalCheckRemoteCb);
		// use different test value
		TestValue.Add(1);
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterface>();
		service->Execute_SetPropInt(service, TestValue);
	});

	LatentIt("Property.PropInt.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<int32> TestValue = TArray<int32>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropInt(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnPropIntChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropIntPropertyChangeLocalChangeRemoteCb);
		// use different test value
		TestValue.Add(1);
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterface>();
		service->Execute_SetPropInt(service, TestValue);
	});

	It("Property.PropInt32.Default", [this]()
		{
		// Do implement test here
		TArray<int32> TestValue = TArray<int32>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropInt32(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropInt32.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<int32> TestValue = TArray<int32>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropInt32(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnPropInt32Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropInt32PropertyCb);
		// use different test value
		TestValue.Add(1);
		ImplFixture->GetImplementation()->Execute_SetPropInt32(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Property.PropInt32.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<int32> TestValue = TArray<int32>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropInt32(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnPropInt32Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropInt32PropertyChangeLocalCheckRemoteCb);
		// use different test value
		TestValue.Add(1);
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterface>();
		service->Execute_SetPropInt32(service, TestValue);
	});

	LatentIt("Property.PropInt32.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<int32> TestValue = TArray<int32>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropInt32(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnPropInt32Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropInt32PropertyChangeLocalChangeRemoteCb);
		// use different test value
		TestValue.Add(1);
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterface>();
		service->Execute_SetPropInt32(service, TestValue);
	});

	It("Property.PropInt64.Default", [this]()
		{
		// Do implement test here
		TArray<int64> TestValue = TArray<int64>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropInt64(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropInt64.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<int64> TestValue = TArray<int64>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropInt64(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnPropInt64Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropInt64PropertyCb);
		// use different test value
		TestValue.Add(1LL);
		ImplFixture->GetImplementation()->Execute_SetPropInt64(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Property.PropInt64.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<int64> TestValue = TArray<int64>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropInt64(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnPropInt64Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropInt64PropertyChangeLocalCheckRemoteCb);
		// use different test value
		TestValue.Add(1LL);
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterface>();
		service->Execute_SetPropInt64(service, TestValue);
	});

	LatentIt("Property.PropInt64.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<int64> TestValue = TArray<int64>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropInt64(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnPropInt64Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropInt64PropertyChangeLocalChangeRemoteCb);
		// use different test value
		TestValue.Add(1LL);
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterface>();
		service->Execute_SetPropInt64(service, TestValue);
	});

	It("Property.PropFloat.Default", [this]()
		{
		// Do implement test here
		TArray<float> TestValue = TArray<float>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropFloat(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropFloat.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<float> TestValue = TArray<float>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropFloat(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnPropFloatChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropFloatPropertyCb);
		// use different test value
		TestValue.Add(1.0f);
		ImplFixture->GetImplementation()->Execute_SetPropFloat(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Property.PropFloat.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<float> TestValue = TArray<float>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropFloat(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnPropFloatChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropFloatPropertyChangeLocalCheckRemoteCb);
		// use different test value
		TestValue.Add(1.0f);
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterface>();
		service->Execute_SetPropFloat(service, TestValue);
	});

	LatentIt("Property.PropFloat.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<float> TestValue = TArray<float>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropFloat(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnPropFloatChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropFloatPropertyChangeLocalChangeRemoteCb);
		// use different test value
		TestValue.Add(1.0f);
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterface>();
		service->Execute_SetPropFloat(service, TestValue);
	});

	It("Property.PropFloat32.Default", [this]()
		{
		// Do implement test here
		TArray<float> TestValue = TArray<float>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropFloat32(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropFloat32.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<float> TestValue = TArray<float>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropFloat32(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnPropFloat32Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropFloat32PropertyCb);
		// use different test value
		TestValue.Add(1.0f);
		ImplFixture->GetImplementation()->Execute_SetPropFloat32(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Property.PropFloat32.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<float> TestValue = TArray<float>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropFloat32(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnPropFloat32Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropFloat32PropertyChangeLocalCheckRemoteCb);
		// use different test value
		TestValue.Add(1.0f);
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterface>();
		service->Execute_SetPropFloat32(service, TestValue);
	});

	LatentIt("Property.PropFloat32.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<float> TestValue = TArray<float>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropFloat32(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnPropFloat32Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropFloat32PropertyChangeLocalChangeRemoteCb);
		// use different test value
		TestValue.Add(1.0f);
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterface>();
		service->Execute_SetPropFloat32(service, TestValue);
	});

	It("Property.PropFloat64.Default", [this]()
		{
		// Do implement test here
		TArray<double> TestValue = TArray<double>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropFloat64(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropFloat64.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<double> TestValue = TArray<double>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropFloat64(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnPropFloat64Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropFloat64PropertyCb);
		// use different test value
		TestValue.Add(1.0);
		ImplFixture->GetImplementation()->Execute_SetPropFloat64(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Property.PropFloat64.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<double> TestValue = TArray<double>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropFloat64(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnPropFloat64Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropFloat64PropertyChangeLocalCheckRemoteCb);
		// use different test value
		TestValue.Add(1.0);
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterface>();
		service->Execute_SetPropFloat64(service, TestValue);
	});

	LatentIt("Property.PropFloat64.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<double> TestValue = TArray<double>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropFloat64(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnPropFloat64Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropFloat64PropertyChangeLocalChangeRemoteCb);
		// use different test value
		TestValue.Add(1.0);
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterface>();
		service->Execute_SetPropFloat64(service, TestValue);
	});

	It("Property.PropString.Default", [this]()
		{
		// Do implement test here
		TArray<FString> TestValue = TArray<FString>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropString(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.PropString.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FString> TestValue = TArray<FString>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropString(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnPropStringChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropStringPropertyCb);
		// use different test value
		TestValue.Add(FString("xyz"));
		ImplFixture->GetImplementation()->Execute_SetPropString(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Property.PropString.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FString> TestValue = TArray<FString>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropString(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnPropStringChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropStringPropertyChangeLocalCheckRemoteCb);
		// use different test value
		TestValue.Add(FString("xyz"));
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterface>();
		service->Execute_SetPropString(service, TestValue);
	});

	LatentIt("Property.PropString.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FString> TestValue = TArray<FString>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropString(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnPropStringChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceMsgBusHelper::PropStringPropertyChangeLocalChangeRemoteCb);
		// use different test value
		TestValue.Add(FString("xyz"));
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterface>();
		service->Execute_SetPropString(service, TestValue);
	});

	It("Property.PropReadOnlyString.Default", [this]()
		{
		// Do implement test here
		FString TestValue = FString(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropReadOnlyString(ImplFixture->GetImplementation().GetObject()), FString());
	});

	LatentIt("Operation.FuncBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_FuncBool(ImplFixture->GetImplementation().GetObject(), TArray<bool>());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_FuncInt(ImplFixture->GetImplementation().GetObject(), TArray<int32>());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncInt32", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_FuncInt32(ImplFixture->GetImplementation().GetObject(), TArray<int32>());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncInt64", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_FuncInt64(ImplFixture->GetImplementation().GetObject(), TArray<int64>());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_FuncFloat(ImplFixture->GetImplementation().GetObject(), TArray<float>());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncFloat32", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_FuncFloat32(ImplFixture->GetImplementation().GetObject(), TArray<float>());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncFloat64", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_FuncFloat64(ImplFixture->GetImplementation().GetObject(), TArray<double>());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_FuncString(ImplFixture->GetImplementation().GetObject(), TArray<FString>());
			TestDone.Execute();
		});
	});

	LatentIt("Signal.SigBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnSigBoolSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigBoolSignalCb);

		// use different test value
		TArray<bool> ParamBoolTestValue = TArray<bool>(); // default value
		ParamBoolTestValue.Add(true);
		TbSimpleSimpleArrayInterfaceSignals->BroadcastSigBoolSignal(ParamBoolTestValue);
	});

	LatentIt("Signal.SigInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnSigIntSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigIntSignalCb);

		// use different test value
		TArray<int32> ParamIntTestValue = TArray<int32>(); // default value
		ParamIntTestValue.Add(1);
		TbSimpleSimpleArrayInterfaceSignals->BroadcastSigIntSignal(ParamIntTestValue);
	});

	LatentIt("Signal.SigInt32", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnSigInt32Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigInt32SignalCb);

		// use different test value
		TArray<int32> ParamInt32TestValue = TArray<int32>(); // default value
		ParamInt32TestValue.Add(1);
		TbSimpleSimpleArrayInterfaceSignals->BroadcastSigInt32Signal(ParamInt32TestValue);
	});

	LatentIt("Signal.SigInt64", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnSigInt64Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigInt64SignalCb);

		// use different test value
		TArray<int64> ParamInt64TestValue = TArray<int64>(); // default value
		ParamInt64TestValue.Add(1LL);
		TbSimpleSimpleArrayInterfaceSignals->BroadcastSigInt64Signal(ParamInt64TestValue);
	});

	LatentIt("Signal.SigFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnSigFloatSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigFloatSignalCb);

		// use different test value
		TArray<float> ParamFloatTestValue = TArray<float>(); // default value
		ParamFloatTestValue.Add(1.0f);
		TbSimpleSimpleArrayInterfaceSignals->BroadcastSigFloatSignal(ParamFloatTestValue);
	});

	LatentIt("Signal.SigFloat32", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnSigFloat32Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigFloat32SignalCb);

		// use different test value
		TArray<float> ParamFloa32TestValue = TArray<float>(); // default value
		ParamFloa32TestValue.Add(1.0f);
		TbSimpleSimpleArrayInterfaceSignals->BroadcastSigFloat32Signal(ParamFloa32TestValue);
	});

	LatentIt("Signal.SigFloat64", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnSigFloat64Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigFloat64SignalCb);

		// use different test value
		TArray<double> ParamFloat64TestValue = TArray<double>(); // default value
		ParamFloat64TestValue.Add(1.0);
		TbSimpleSimpleArrayInterfaceSignals->BroadcastSigFloat64Signal(ParamFloat64TestValue);
	});

	LatentIt("Signal.SigString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleSimpleArrayInterfaceSignals* TbSimpleSimpleArrayInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleSimpleArrayInterfaceSignals->OnSigStringSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleSimpleArrayInterfaceMsgBusHelper::SigStringSignalCb);

		// use different test value
		TArray<FString> ParamStringTestValue = TArray<FString>(); // default value
		ParamStringTestValue.Add(FString("xyz"));
		TbSimpleSimpleArrayInterfaceSignals->BroadcastSigStringSignal(ParamStringTestValue);
	});
}

void UTbSimpleSimpleArrayInterfaceMsgBusSpec::PropBoolPropertyCb(const TArray<bool>& InPropBool)
{
	TArray<bool> TestValue = TArray<bool>();
	// use different test value
	TestValue.Add(true);
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropBool(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusSpec::PropBoolPropertyChangeLocalCheckRemoteCb(const TArray<bool>& InPropBool)
{
	TArray<bool> TestValue = TArray<bool>();
	// use different test value
	TestValue.Add(true);
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropBool(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusSpec::PropBoolPropertyChangeLocalChangeRemoteCb(const TArray<bool>& InPropBool)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		TArray<bool> TestValue = TArray<bool>();
		// use different test value
		TestValue.Add(true);
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropBool(ImplFixture->GetImplementation().GetObject()), TestValue);

		// now set it to the default value
		TestValue = TArray<bool>(); // default value
		ImplFixture->GetImplementation()->Execute_SetPropBool(ImplFixture->GetImplementation().GetObject(), TestValue);
	}
	else
	{
		TArray<bool> TestValue = TArray<bool>(); // default value
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropBool(ImplFixture->GetImplementation().GetObject()), TestValue);
		testDoneDelegate.Execute();
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusSpec::PropIntPropertyCb(const TArray<int32>& InPropInt)
{
	TArray<int32> TestValue = TArray<int32>();
	// use different test value
	TestValue.Add(1);
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropInt(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusSpec::PropIntPropertyChangeLocalCheckRemoteCb(const TArray<int32>& InPropInt)
{
	TArray<int32> TestValue = TArray<int32>();
	// use different test value
	TestValue.Add(1);
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropInt(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusSpec::PropIntPropertyChangeLocalChangeRemoteCb(const TArray<int32>& InPropInt)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		TArray<int32> TestValue = TArray<int32>();
		// use different test value
		TestValue.Add(1);
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropInt(ImplFixture->GetImplementation().GetObject()), TestValue);

		// now set it to the default value
		TestValue = TArray<int32>(); // default value
		ImplFixture->GetImplementation()->Execute_SetPropInt(ImplFixture->GetImplementation().GetObject(), TestValue);
	}
	else
	{
		TArray<int32> TestValue = TArray<int32>(); // default value
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropInt(ImplFixture->GetImplementation().GetObject()), TestValue);
		testDoneDelegate.Execute();
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusSpec::PropInt32PropertyCb(const TArray<int32>& InPropInt32)
{
	TArray<int32> TestValue = TArray<int32>();
	// use different test value
	TestValue.Add(1);
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt32, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropInt32(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusSpec::PropInt32PropertyChangeLocalCheckRemoteCb(const TArray<int32>& InPropInt32)
{
	TArray<int32> TestValue = TArray<int32>();
	// use different test value
	TestValue.Add(1);
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt32, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropInt32(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusSpec::PropInt32PropertyChangeLocalChangeRemoteCb(const TArray<int32>& InPropInt32)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		TArray<int32> TestValue = TArray<int32>();
		// use different test value
		TestValue.Add(1);
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt32, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropInt32(ImplFixture->GetImplementation().GetObject()), TestValue);

		// now set it to the default value
		TestValue = TArray<int32>(); // default value
		ImplFixture->GetImplementation()->Execute_SetPropInt32(ImplFixture->GetImplementation().GetObject(), TestValue);
	}
	else
	{
		TArray<int32> TestValue = TArray<int32>(); // default value
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt32, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropInt32(ImplFixture->GetImplementation().GetObject()), TestValue);
		testDoneDelegate.Execute();
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusSpec::PropInt64PropertyCb(const TArray<int64>& InPropInt64)
{
	TArray<int64> TestValue = TArray<int64>();
	// use different test value
	TestValue.Add(1LL);
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt64, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropInt64(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusSpec::PropInt64PropertyChangeLocalCheckRemoteCb(const TArray<int64>& InPropInt64)
{
	TArray<int64> TestValue = TArray<int64>();
	// use different test value
	TestValue.Add(1LL);
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt64, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropInt64(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusSpec::PropInt64PropertyChangeLocalChangeRemoteCb(const TArray<int64>& InPropInt64)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		TArray<int64> TestValue = TArray<int64>();
		// use different test value
		TestValue.Add(1LL);
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt64, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropInt64(ImplFixture->GetImplementation().GetObject()), TestValue);

		// now set it to the default value
		TestValue = TArray<int64>(); // default value
		ImplFixture->GetImplementation()->Execute_SetPropInt64(ImplFixture->GetImplementation().GetObject(), TestValue);
	}
	else
	{
		TArray<int64> TestValue = TArray<int64>(); // default value
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt64, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropInt64(ImplFixture->GetImplementation().GetObject()), TestValue);
		testDoneDelegate.Execute();
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusSpec::PropFloatPropertyCb(const TArray<float>& InPropFloat)
{
	TArray<float> TestValue = TArray<float>();
	// use different test value
	TestValue.Add(1.0f);
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropFloat(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusSpec::PropFloatPropertyChangeLocalCheckRemoteCb(const TArray<float>& InPropFloat)
{
	TArray<float> TestValue = TArray<float>();
	// use different test value
	TestValue.Add(1.0f);
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropFloat(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusSpec::PropFloatPropertyChangeLocalChangeRemoteCb(const TArray<float>& InPropFloat)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		TArray<float> TestValue = TArray<float>();
		// use different test value
		TestValue.Add(1.0f);
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropFloat(ImplFixture->GetImplementation().GetObject()), TestValue);

		// now set it to the default value
		TestValue = TArray<float>(); // default value
		ImplFixture->GetImplementation()->Execute_SetPropFloat(ImplFixture->GetImplementation().GetObject(), TestValue);
	}
	else
	{
		TArray<float> TestValue = TArray<float>(); // default value
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropFloat(ImplFixture->GetImplementation().GetObject()), TestValue);
		testDoneDelegate.Execute();
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusSpec::PropFloat32PropertyCb(const TArray<float>& InPropFloat32)
{
	TArray<float> TestValue = TArray<float>();
	// use different test value
	TestValue.Add(1.0f);
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat32, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropFloat32(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusSpec::PropFloat32PropertyChangeLocalCheckRemoteCb(const TArray<float>& InPropFloat32)
{
	TArray<float> TestValue = TArray<float>();
	// use different test value
	TestValue.Add(1.0f);
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat32, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropFloat32(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusSpec::PropFloat32PropertyChangeLocalChangeRemoteCb(const TArray<float>& InPropFloat32)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		TArray<float> TestValue = TArray<float>();
		// use different test value
		TestValue.Add(1.0f);
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat32, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropFloat32(ImplFixture->GetImplementation().GetObject()), TestValue);

		// now set it to the default value
		TestValue = TArray<float>(); // default value
		ImplFixture->GetImplementation()->Execute_SetPropFloat32(ImplFixture->GetImplementation().GetObject(), TestValue);
	}
	else
	{
		TArray<float> TestValue = TArray<float>(); // default value
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat32, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropFloat32(ImplFixture->GetImplementation().GetObject()), TestValue);
		testDoneDelegate.Execute();
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusSpec::PropFloat64PropertyCb(const TArray<double>& InPropFloat64)
{
	TArray<double> TestValue = TArray<double>();
	// use different test value
	TestValue.Add(1.0);
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat64, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropFloat64(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusSpec::PropFloat64PropertyChangeLocalCheckRemoteCb(const TArray<double>& InPropFloat64)
{
	TArray<double> TestValue = TArray<double>();
	// use different test value
	TestValue.Add(1.0);
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat64, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropFloat64(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusSpec::PropFloat64PropertyChangeLocalChangeRemoteCb(const TArray<double>& InPropFloat64)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		TArray<double> TestValue = TArray<double>();
		// use different test value
		TestValue.Add(1.0);
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat64, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropFloat64(ImplFixture->GetImplementation().GetObject()), TestValue);

		// now set it to the default value
		TestValue = TArray<double>(); // default value
		ImplFixture->GetImplementation()->Execute_SetPropFloat64(ImplFixture->GetImplementation().GetObject(), TestValue);
	}
	else
	{
		TArray<double> TestValue = TArray<double>(); // default value
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat64, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropFloat64(ImplFixture->GetImplementation().GetObject()), TestValue);
		testDoneDelegate.Execute();
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusSpec::PropStringPropertyCb(const TArray<FString>& InPropString)
{
	TArray<FString> TestValue = TArray<FString>();
	// use different test value
	TestValue.Add(FString("xyz"));
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropString(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusSpec::PropStringPropertyChangeLocalCheckRemoteCb(const TArray<FString>& InPropString)
{
	TArray<FString> TestValue = TArray<FString>();
	// use different test value
	TestValue.Add(FString("xyz"));
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropString(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusSpec::PropStringPropertyChangeLocalChangeRemoteCb(const TArray<FString>& InPropString)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		TArray<FString> TestValue = TArray<FString>();
		// use different test value
		TestValue.Add(FString("xyz"));
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropString(ImplFixture->GetImplementation().GetObject()), TestValue);

		// now set it to the default value
		TestValue = TArray<FString>(); // default value
		ImplFixture->GetImplementation()->Execute_SetPropString(ImplFixture->GetImplementation().GetObject(), TestValue);
	}
	else
	{
		TArray<FString> TestValue = TArray<FString>(); // default value
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetPropString(ImplFixture->GetImplementation().GetObject()), TestValue);
		testDoneDelegate.Execute();
	}
}

void UTbSimpleSimpleArrayInterfaceMsgBusSpec::SigBoolSignalCb(const TArray<bool>& InParamBool)
{
	// known test value
	TArray<bool> ParamBoolTestValue = TArray<bool>(); // default value
	ParamBoolTestValue.Add(true);
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamBool, ParamBoolTestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusSpec::SigIntSignalCb(const TArray<int32>& InParamInt)
{
	// known test value
	TArray<int32> ParamIntTestValue = TArray<int32>(); // default value
	ParamIntTestValue.Add(1);
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt, ParamIntTestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusSpec::SigInt32SignalCb(const TArray<int32>& InParamInt32)
{
	// known test value
	TArray<int32> ParamInt32TestValue = TArray<int32>(); // default value
	ParamInt32TestValue.Add(1);
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt32, ParamInt32TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusSpec::SigInt64SignalCb(const TArray<int64>& InParamInt64)
{
	// known test value
	TArray<int64> ParamInt64TestValue = TArray<int64>(); // default value
	ParamInt64TestValue.Add(1LL);
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt64, ParamInt64TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusSpec::SigFloatSignalCb(const TArray<float>& InParamFloat)
{
	// known test value
	TArray<float> ParamFloatTestValue = TArray<float>(); // default value
	ParamFloatTestValue.Add(1.0f);
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat, ParamFloatTestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusSpec::SigFloat32SignalCb(const TArray<float>& InParamFloa32)
{
	// known test value
	TArray<float> ParamFloa32TestValue = TArray<float>(); // default value
	ParamFloa32TestValue.Add(1.0f);
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloa32, ParamFloa32TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusSpec::SigFloat64SignalCb(const TArray<double>& InParamFloat64)
{
	// known test value
	TArray<double> ParamFloat64TestValue = TArray<double>(); // default value
	ParamFloat64TestValue.Add(1.0);
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat64, ParamFloat64TestValue);
	testDoneDelegate.Execute();
}

void UTbSimpleSimpleArrayInterfaceMsgBusSpec::SigStringSignalCb(const TArray<FString>& InParamString)
{
	// known test value
	TArray<FString> ParamStringTestValue = TArray<FString>(); // default value
	ParamStringTestValue.Add(FString("xyz"));
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamString, ParamStringTestValue);
	testDoneDelegate.Execute();
}
#endif // WITH_DEV_AUTOMATION_TESTS
