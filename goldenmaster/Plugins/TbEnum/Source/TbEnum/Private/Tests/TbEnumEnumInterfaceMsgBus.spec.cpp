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

#include "TbEnumTestsCommon.h"
#include "Implementation/TbEnumEnumInterface.h"
#include "TbEnumEnumInterfaceMsgBusFixture.h"
#include "Generated/MsgBus/TbEnumEnumInterfaceMsgBusClient.h"
#include "Generated/MsgBus/TbEnumEnumInterfaceMsgBusAdapter.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UTbEnumEnumInterfaceMsgBusSpec, "TbEnum.EnumInterface.MsgBus", TbEnumTestFilterMask);

TSharedPtr<FTbEnumEnumInterfaceMsgBusFixture> ImplFixture;

END_DEFINE_SPEC(UTbEnumEnumInterfaceMsgBusSpec);

void UTbEnumEnumInterfaceMsgBusSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeShared<FTbEnumEnumInterfaceMsgBusFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		// needed for callbacks
		ImplFixture->GetHelper()->SetSpec(this);
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		ImplFixture->GetHelper()->SetParentFixture(ImplFixture);

		// set up service and adapter
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbEnumEnumInterface>();
		ImplFixture->GetAdapter()->_setBackendService(service);
		ImplFixture->GetAdapter()->_StartListening();

		// setup client
		UTbEnumEnumInterfaceMsgBusClient* MsgBusClient = Cast<UTbEnumEnumInterfaceMsgBusClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid MsgBus client", MsgBusClient != nullptr);

		MsgBusClient->_ConnectionStatusChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceMsgBusHelper::_ConnectionStatusChangedCb);

		MsgBusClient->_Connect();
	});

	AfterEach([this]()
		{
		ImplFixture.Reset();
	});

	It("Property.Prop0.Default", [this]()
		{
		// Do implement test here
		ETbEnumEnum0 TestValue = ETbEnumEnum0::TEE0_VALUE0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp0(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.Prop0.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum0 TestValue = ETbEnumEnum0::TEE0_VALUE0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp0(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbEnumEnumInterfaceSignals->OnProp0Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceMsgBusHelper::Prop0PropertyCb);
		// use different test value
		TestValue = ETbEnumEnum0::TEE0_VALUE1;
		ImplFixture->GetImplementation()->Execute_SetProp0(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Property.Prop0.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum0 TestValue = ETbEnumEnum0::TEE0_VALUE0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp0(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbEnumEnumInterfaceSignals->OnProp0Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceMsgBusHelper::Prop0PropertyChangeLocalCheckRemoteCb);
		// use different test value
		TestValue = ETbEnumEnum0::TEE0_VALUE1;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbEnumEnumInterface>();
		service->Execute_SetProp0(service, TestValue);
	});

	LatentIt("Property.Prop0.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum0 TestValue = ETbEnumEnum0::TEE0_VALUE0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp0(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbEnumEnumInterfaceSignals->OnProp0Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceMsgBusHelper::Prop0PropertyChangeLocalChangeRemoteCb);
		// use different test value
		TestValue = ETbEnumEnum0::TEE0_VALUE1;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbEnumEnumInterface>();
		service->Execute_SetProp0(service, TestValue);
	});

	It("Property.Prop1.Default", [this]()
		{
		// Do implement test here
		ETbEnumEnum1 TestValue = ETbEnumEnum1::TEE1_VALUE1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp1(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum1 TestValue = ETbEnumEnum1::TEE1_VALUE1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp1(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbEnumEnumInterfaceSignals->OnProp1Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceMsgBusHelper::Prop1PropertyCb);
		// use different test value
		TestValue = ETbEnumEnum1::TEE1_VALUE2;
		ImplFixture->GetImplementation()->Execute_SetProp1(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Property.Prop1.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum1 TestValue = ETbEnumEnum1::TEE1_VALUE1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp1(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbEnumEnumInterfaceSignals->OnProp1Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceMsgBusHelper::Prop1PropertyChangeLocalCheckRemoteCb);
		// use different test value
		TestValue = ETbEnumEnum1::TEE1_VALUE2;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbEnumEnumInterface>();
		service->Execute_SetProp1(service, TestValue);
	});

	LatentIt("Property.Prop1.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum1 TestValue = ETbEnumEnum1::TEE1_VALUE1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp1(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbEnumEnumInterfaceSignals->OnProp1Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceMsgBusHelper::Prop1PropertyChangeLocalChangeRemoteCb);
		// use different test value
		TestValue = ETbEnumEnum1::TEE1_VALUE2;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbEnumEnumInterface>();
		service->Execute_SetProp1(service, TestValue);
	});

	It("Property.Prop2.Default", [this]()
		{
		// Do implement test here
		ETbEnumEnum2 TestValue = ETbEnumEnum2::TEE2_VALUE2; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp2(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.Prop2.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum2 TestValue = ETbEnumEnum2::TEE2_VALUE2; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp2(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbEnumEnumInterfaceSignals->OnProp2Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceMsgBusHelper::Prop2PropertyCb);
		// use different test value
		TestValue = ETbEnumEnum2::TEE2_VALUE1;
		ImplFixture->GetImplementation()->Execute_SetProp2(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Property.Prop2.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum2 TestValue = ETbEnumEnum2::TEE2_VALUE2; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp2(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbEnumEnumInterfaceSignals->OnProp2Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceMsgBusHelper::Prop2PropertyChangeLocalCheckRemoteCb);
		// use different test value
		TestValue = ETbEnumEnum2::TEE2_VALUE1;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbEnumEnumInterface>();
		service->Execute_SetProp2(service, TestValue);
	});

	LatentIt("Property.Prop2.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum2 TestValue = ETbEnumEnum2::TEE2_VALUE2; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp2(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbEnumEnumInterfaceSignals->OnProp2Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceMsgBusHelper::Prop2PropertyChangeLocalChangeRemoteCb);
		// use different test value
		TestValue = ETbEnumEnum2::TEE2_VALUE1;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbEnumEnumInterface>();
		service->Execute_SetProp2(service, TestValue);
	});

	It("Property.Prop3.Default", [this]()
		{
		// Do implement test here
		ETbEnumEnum3 TestValue = ETbEnumEnum3::TEE3_VALUE3; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp3(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.Prop3.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum3 TestValue = ETbEnumEnum3::TEE3_VALUE3; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp3(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbEnumEnumInterfaceSignals->OnProp3Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceMsgBusHelper::Prop3PropertyCb);
		// use different test value
		TestValue = ETbEnumEnum3::TEE3_VALUE2;
		ImplFixture->GetImplementation()->Execute_SetProp3(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Property.Prop3.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum3 TestValue = ETbEnumEnum3::TEE3_VALUE3; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp3(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbEnumEnumInterfaceSignals->OnProp3Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceMsgBusHelper::Prop3PropertyChangeLocalCheckRemoteCb);
		// use different test value
		TestValue = ETbEnumEnum3::TEE3_VALUE2;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbEnumEnumInterface>();
		service->Execute_SetProp3(service, TestValue);
	});

	LatentIt("Property.Prop3.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum3 TestValue = ETbEnumEnum3::TEE3_VALUE3; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp3(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbEnumEnumInterfaceSignals->OnProp3Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceMsgBusHelper::Prop3PropertyChangeLocalChangeRemoteCb);
		// use different test value
		TestValue = ETbEnumEnum3::TEE3_VALUE2;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbEnumEnumInterface>();
		service->Execute_SetProp3(service, TestValue);
	});

	LatentIt("Operation.Func0", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_Func0(ImplFixture->GetImplementation().GetObject(), ETbEnumEnum0::TEE0_VALUE0);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_Func1(ImplFixture->GetImplementation().GetObject(), ETbEnumEnum1::TEE1_VALUE1);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_Func2(ImplFixture->GetImplementation().GetObject(), ETbEnumEnum2::TEE2_VALUE2);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func3", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_Func3(ImplFixture->GetImplementation().GetObject(), ETbEnumEnum3::TEE3_VALUE3);
			TestDone.Execute();
		});
	});

	LatentIt("Signal.Sig0", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbEnumEnumInterfaceSignals->OnSig0Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceMsgBusHelper::Sig0SignalCb);

		// use different test value
		ETbEnumEnum0 Param0TestValue = ETbEnumEnum0::TEE0_VALUE1;
		TbEnumEnumInterfaceSignals->BroadcastSig0Signal(Param0TestValue);
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbEnumEnumInterfaceSignals->OnSig1Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceMsgBusHelper::Sig1SignalCb);

		// use different test value
		ETbEnumEnum1 Param1TestValue = ETbEnumEnum1::TEE1_VALUE2;
		TbEnumEnumInterfaceSignals->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbEnumEnumInterfaceSignals->OnSig2Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceMsgBusHelper::Sig2SignalCb);

		// use different test value
		ETbEnumEnum2 Param2TestValue = ETbEnumEnum2::TEE2_VALUE1;
		TbEnumEnumInterfaceSignals->BroadcastSig2Signal(Param2TestValue);
	});

	LatentIt("Signal.Sig3", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbEnumEnumInterfaceSignals->OnSig3Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceMsgBusHelper::Sig3SignalCb);

		// use different test value
		ETbEnumEnum3 Param3TestValue = ETbEnumEnum3::TEE3_VALUE2;
		TbEnumEnumInterfaceSignals->BroadcastSig3Signal(Param3TestValue);
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS
