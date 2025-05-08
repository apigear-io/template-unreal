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

#include "TbSimpleTestsCommon.h"
#include "Implementation/TbSimpleNoOperationsInterface.h"
#include "TbSimpleNoOperationsInterfaceMsgBusFixture.h"
#include "Generated/MsgBus/TbSimpleNoOperationsInterfaceMsgBusClient.h"
#include "Generated/MsgBus/TbSimpleNoOperationsInterfaceMsgBusAdapter.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UTbSimpleNoOperationsInterfaceMsgBusSpec, "TbSimple.NoOperationsInterface.MsgBus", TbSimpleTestFilterMask);

TSharedPtr<FTbSimpleNoOperationsInterfaceMsgBusFixture> ImplFixture;

END_DEFINE_SPEC(UTbSimpleNoOperationsInterfaceMsgBusSpec);

void UTbSimpleNoOperationsInterfaceMsgBusSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeShared<FTbSimpleNoOperationsInterfaceMsgBusFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		// needed for callbacks
		ImplFixture->GetHelper()->SetSpec(this);
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		ImplFixture->GetHelper()->SetParentFixture(ImplFixture);

		// set up service and adapter
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSimpleNoOperationsInterface>();
		ImplFixture->GetAdapter()->_setBackendService(service);
		ImplFixture->GetAdapter()->_StartListening();

		// setup client
		UTbSimpleNoOperationsInterfaceMsgBusClient* MsgBusClient = Cast<UTbSimpleNoOperationsInterfaceMsgBusClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid MsgBus client", MsgBusClient != nullptr);

		MsgBusClient->_ConnectionStatusChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleNoOperationsInterfaceMsgBusHelper::_ConnectionStatusChangedCb);

		MsgBusClient->_Connect();
	});

	AfterEach([this]()
		{
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

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSimpleNoOperationsInterfaceSignals* TbSimpleNoOperationsInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleNoOperationsInterfaceSignals->OnPropBoolChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleNoOperationsInterfaceMsgBusHelper::PropBoolPropertyCb);
		// use different test value
		TestValue = true;
		ImplFixture->GetImplementation()->Execute_SetPropBool(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Property.PropBool.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		bool TestValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropBool(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSimpleNoOperationsInterfaceSignals* TbSimpleNoOperationsInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleNoOperationsInterfaceSignals->OnPropBoolChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleNoOperationsInterfaceMsgBusHelper::PropBoolPropertyChangeLocalCheckRemoteCb);
		// use different test value
		TestValue = true;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSimpleNoOperationsInterface>();
		service->Execute_SetPropBool(service, TestValue);
	});

	LatentIt("Property.PropBool.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		bool TestValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropBool(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSimpleNoOperationsInterfaceSignals* TbSimpleNoOperationsInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleNoOperationsInterfaceSignals->OnPropBoolChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleNoOperationsInterfaceMsgBusHelper::PropBoolPropertyChangeLocalChangeRemoteCb);
		// use different test value
		TestValue = true;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSimpleNoOperationsInterface>();
		service->Execute_SetPropBool(service, TestValue);
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

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSimpleNoOperationsInterfaceSignals* TbSimpleNoOperationsInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleNoOperationsInterfaceSignals->OnPropIntChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleNoOperationsInterfaceMsgBusHelper::PropIntPropertyCb);
		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->Execute_SetPropInt(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Property.PropInt.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropInt(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSimpleNoOperationsInterfaceSignals* TbSimpleNoOperationsInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleNoOperationsInterfaceSignals->OnPropIntChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleNoOperationsInterfaceMsgBusHelper::PropIntPropertyChangeLocalCheckRemoteCb);
		// use different test value
		TestValue = 1;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSimpleNoOperationsInterface>();
		service->Execute_SetPropInt(service, TestValue);
	});

	LatentIt("Property.PropInt.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetPropInt(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSimpleNoOperationsInterfaceSignals* TbSimpleNoOperationsInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleNoOperationsInterfaceSignals->OnPropIntChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleNoOperationsInterfaceMsgBusHelper::PropIntPropertyChangeLocalChangeRemoteCb);
		// use different test value
		TestValue = 1;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSimpleNoOperationsInterface>();
		service->Execute_SetPropInt(service, TestValue);
	});

	LatentIt("Signal.SigVoid", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSimpleNoOperationsInterfaceSignals* TbSimpleNoOperationsInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleNoOperationsInterfaceSignals->OnSigVoidSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleNoOperationsInterfaceMsgBusHelper::SigVoidSignalCb);

		// use different test value
		TbSimpleNoOperationsInterfaceSignals->BroadcastSigVoidSignal();
	});

	LatentIt("Signal.SigBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSimpleNoOperationsInterfaceSignals* TbSimpleNoOperationsInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleNoOperationsInterfaceSignals->OnSigBoolSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleNoOperationsInterfaceMsgBusHelper::SigBoolSignalCb);

		// use different test value
		bool bParamBoolTestValue = true;
		TbSimpleNoOperationsInterfaceSignals->BroadcastSigBoolSignal(bParamBoolTestValue);
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS
