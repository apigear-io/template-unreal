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

#include "TbNamesTestsCommon.h"
#include "Implementation/TbNamesNamEs.h"
#include "TbNamesNamEsMsgBusFixture.h"
#include "Generated/MsgBus/TbNamesNamEsMsgBusClient.h"
#include "Generated/MsgBus/TbNamesNamEsMsgBusAdapter.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UTbNamesNamEsMsgBusSpec, "TbNames.NamEs.MsgBus", TbNamesTestFilterMask);

TSharedPtr<FTbNamesNamEsMsgBusFixture> ImplFixture;

END_DEFINE_SPEC(UTbNamesNamEsMsgBusSpec);

void UTbNamesNamEsMsgBusSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeShared<FTbNamesNamEsMsgBusFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		// needed for callbacks
		ImplFixture->GetHelper()->SetSpec(this);
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		ImplFixture->GetHelper()->SetParentFixture(ImplFixture);

		// set up service and adapter
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbNamesNamEs>();
		ImplFixture->GetAdapter()->_setBackendService(service);
		ImplFixture->GetAdapter()->_StartListening();

		// setup client
		UTbNamesNamEsMsgBusClient* MsgBusClient = Cast<UTbNamesNamEsMsgBusClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid MsgBus client", MsgBusClient != nullptr);

		MsgBusClient->_ConnectionStatusChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsMsgBusHelper::_ConnectionStatusChangedCb);

		MsgBusClient->_Connect();
	});

	AfterEach([this]()
		{
		ImplFixture.Reset();
	});

	It("Property.Switch.Default", [this]()
		{
		// Do implement test here
		bool TestValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetSwitch(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.Switch.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		bool TestValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetSwitch(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnSwitchChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsMsgBusHelper::SwitchPropertyCb);
		// use different test value
		TestValue = true;
		ImplFixture->GetImplementation()->Execute_SetSwitch(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Property.Switch.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		bool TestValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetSwitch(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnSwitchChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsMsgBusHelper::SwitchPropertyChangeLocalCheckRemoteCb);
		// use different test value
		TestValue = true;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbNamesNamEs>();
		service->Execute_SetSwitch(service, TestValue);
	});

	LatentIt("Property.Switch.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		bool TestValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetSwitch(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnSwitchChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsMsgBusHelper::SwitchPropertyChangeLocalChangeRemoteCb);
		// use different test value
		TestValue = true;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbNamesNamEs>();
		service->Execute_SetSwitch(service, TestValue);
	});

	It("Property.SomeProperty.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetSomeProperty(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.SomeProperty.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetSomeProperty(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnSomePropertyChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsMsgBusHelper::SomePropertyPropertyCb);
		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->Execute_SetSomeProperty(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Property.SomeProperty.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetSomeProperty(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnSomePropertyChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsMsgBusHelper::SomePropertyPropertyChangeLocalCheckRemoteCb);
		// use different test value
		TestValue = 1;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbNamesNamEs>();
		service->Execute_SetSomeProperty(service, TestValue);
	});

	LatentIt("Property.SomeProperty.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetSomeProperty(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnSomePropertyChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsMsgBusHelper::SomePropertyPropertyChangeLocalChangeRemoteCb);
		// use different test value
		TestValue = 1;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbNamesNamEs>();
		service->Execute_SetSomeProperty(service, TestValue);
	});

	It("Property.SomePoperty2.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetSomePoperty2(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.SomePoperty2.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetSomePoperty2(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnSomePoperty2Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsMsgBusHelper::SomePoperty2PropertyCb);
		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->Execute_SetSomePoperty2(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Property.SomePoperty2.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetSomePoperty2(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnSomePoperty2Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsMsgBusHelper::SomePoperty2PropertyChangeLocalCheckRemoteCb);
		// use different test value
		TestValue = 1;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbNamesNamEs>();
		service->Execute_SetSomePoperty2(service, TestValue);
	});

	LatentIt("Property.SomePoperty2.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetSomePoperty2(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnSomePoperty2Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsMsgBusHelper::SomePoperty2PropertyChangeLocalChangeRemoteCb);
		// use different test value
		TestValue = 1;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbNamesNamEs>();
		service->Execute_SetSomePoperty2(service, TestValue);
	});

	It("Property.EnumProperty.Default", [this]()
		{
		// Do implement test here
		ETbNamesEnum_With_Under_scores TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetEnumProperty(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.EnumProperty.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbNamesEnum_With_Under_scores TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetEnumProperty(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnEnumPropertyChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsMsgBusHelper::EnumPropertyPropertyCb);
		// use different test value
		TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_SecondValue;
		ImplFixture->GetImplementation()->Execute_SetEnumProperty(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Property.EnumProperty.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbNamesEnum_With_Under_scores TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetEnumProperty(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnEnumPropertyChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsMsgBusHelper::EnumPropertyPropertyChangeLocalCheckRemoteCb);
		// use different test value
		TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_SecondValue;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbNamesNamEs>();
		service->Execute_SetEnumProperty(service, TestValue);
	});

	LatentIt("Property.EnumProperty.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbNamesEnum_With_Under_scores TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetEnumProperty(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnEnumPropertyChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsMsgBusHelper::EnumPropertyPropertyChangeLocalChangeRemoteCb);
		// use different test value
		TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_SecondValue;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbNamesNamEs>();
		service->Execute_SetEnumProperty(service, TestValue);
	});

	LatentIt("Operation.SomeFunction", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_SomeFunction(ImplFixture->GetImplementation().GetObject(), false);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.SomeFunction2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_SomeFunction2(ImplFixture->GetImplementation().GetObject(), false);
			TestDone.Execute();
		});
	});

	LatentIt("Signal.SomeSignal", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnSomeSignalSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsMsgBusHelper::SomeSignalSignalCb);

		// use different test value
		bool bSomeParamTestValue = true;
		TbNamesNamEsSignals->BroadcastSomeSignalSignal(bSomeParamTestValue);
	});

	LatentIt("Signal.SomeSignal2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnSomeSignal2Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsMsgBusHelper::SomeSignal2SignalCb);

		// use different test value
		bool bSomeParamTestValue = true;
		TbNamesNamEsSignals->BroadcastSomeSignal2Signal(bSomeParamTestValue);
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS
