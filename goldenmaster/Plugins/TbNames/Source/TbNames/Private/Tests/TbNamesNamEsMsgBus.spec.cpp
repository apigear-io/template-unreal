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

#include "TbNamesNamEsMsgBus.spec.h"
#include "Implementation/TbNamesNamEs.h"
#include "TbNamesNamEsMsgBusFixture.h"
#include "Generated/MsgBus/TbNamesNamEsMsgBusClient.h"
#include "Generated/MsgBus/TbNamesNamEsMsgBusAdapter.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbNamesNamEsMsgBusSpec::_ConnectionStatusChangedCb(bool bConnected)
{
	if (bConnected)
	{
		testDoneDelegate.Execute();
	}
}

void UTbNamesNamEsMsgBusSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbNamesNamEsMsgBusFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		// needed for callbacks
		ImplFixture->GetHelper()->SetSpec(this);

		// set up service and adapter
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbNamesNamEs>();
		ImplFixture->GetAdapter()->_setBackendService(service);
		ImplFixture->GetAdapter()->_StartListening();

		// setup client
		testDoneDelegate = TestDone;
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

		testDoneDelegate = TestDone;
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

		testDoneDelegate = TestDone;
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

		testDoneDelegate = TestDone;
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

		testDoneDelegate = TestDone;
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

		testDoneDelegate = TestDone;
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

		testDoneDelegate = TestDone;
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

		testDoneDelegate = TestDone;
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

		testDoneDelegate = TestDone;
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

		testDoneDelegate = TestDone;
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
		ETbNamesEnum_With_Under_scores TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FIRSTVALUE; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetEnumProperty(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.EnumProperty.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbNamesEnum_With_Under_scores TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FIRSTVALUE; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetEnumProperty(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnEnumPropertyChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsMsgBusHelper::EnumPropertyPropertyCb);
		// use different test value
		TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_SECONDVALUE;
		ImplFixture->GetImplementation()->Execute_SetEnumProperty(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Property.EnumProperty.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbNamesEnum_With_Under_scores TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FIRSTVALUE; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetEnumProperty(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnEnumPropertyChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsMsgBusHelper::EnumPropertyPropertyChangeLocalCheckRemoteCb);
		// use different test value
		TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_SECONDVALUE;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbNamesNamEs>();
		service->Execute_SetEnumProperty(service, TestValue);
	});

	LatentIt("Property.EnumProperty.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbNamesEnum_With_Under_scores TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FIRSTVALUE; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetEnumProperty(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnEnumPropertyChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsMsgBusHelper::EnumPropertyPropertyChangeLocalChangeRemoteCb);
		// use different test value
		TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_SECONDVALUE;
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
		testDoneDelegate = TestDone;
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnSomeSignalSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsMsgBusHelper::SomeSignalSignalCb);

		// use different test value
		bool bSomeParamTestValue = true;
		TbNamesNamEsSignals->BroadcastSomeSignalSignal(bSomeParamTestValue);
	});

	LatentIt("Signal.SomeSignal2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbNamesNamEsSignals->OnSomeSignal2Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsMsgBusHelper::SomeSignal2SignalCb);

		// use different test value
		bool bSomeParamTestValue = true;
		TbNamesNamEsSignals->BroadcastSomeSignal2Signal(bSomeParamTestValue);
	});
}

void UTbNamesNamEsMsgBusSpec::SwitchPropertyCb(bool bInSwitch)
{
	bool TestValue = false;
	// use different test value
	TestValue = true;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInSwitch, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetSwitch(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbNamesNamEsMsgBusSpec::SwitchPropertyChangeLocalCheckRemoteCb(bool bInSwitch)
{
	bool TestValue = false;
	// use different test value
	TestValue = true;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInSwitch, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetSwitch(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbNamesNamEsMsgBusSpec::SwitchPropertyChangeLocalChangeRemoteCb(bool bInSwitch)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		bool TestValue = false;
		// use different test value
		TestValue = true;
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInSwitch, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetSwitch(ImplFixture->GetImplementation().GetObject()), TestValue);

		// now set it to the default value
		TestValue = false; // default value
		ImplFixture->GetImplementation()->Execute_SetSwitch(ImplFixture->GetImplementation().GetObject(), TestValue);
	}
	else
	{
		bool TestValue = false; // default value
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), bInSwitch, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetSwitch(ImplFixture->GetImplementation().GetObject()), TestValue);
		testDoneDelegate.Execute();
	}
}

void UTbNamesNamEsMsgBusSpec::SomePropertyPropertyCb(int32 InSomeProperty)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomeProperty, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetSomeProperty(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbNamesNamEsMsgBusSpec::SomePropertyPropertyChangeLocalCheckRemoteCb(int32 InSomeProperty)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomeProperty, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetSomeProperty(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbNamesNamEsMsgBusSpec::SomePropertyPropertyChangeLocalChangeRemoteCb(int32 InSomeProperty)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		int32 TestValue = 0;
		// use different test value
		TestValue = 1;
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomeProperty, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetSomeProperty(ImplFixture->GetImplementation().GetObject()), TestValue);

		// now set it to the default value
		TestValue = 0; // default value
		ImplFixture->GetImplementation()->Execute_SetSomeProperty(ImplFixture->GetImplementation().GetObject(), TestValue);
	}
	else
	{
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomeProperty, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetSomeProperty(ImplFixture->GetImplementation().GetObject()), TestValue);
		testDoneDelegate.Execute();
	}
}

void UTbNamesNamEsMsgBusSpec::SomePoperty2PropertyCb(int32 InSomePoperty2)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomePoperty2, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetSomePoperty2(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbNamesNamEsMsgBusSpec::SomePoperty2PropertyChangeLocalCheckRemoteCb(int32 InSomePoperty2)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomePoperty2, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetSomePoperty2(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbNamesNamEsMsgBusSpec::SomePoperty2PropertyChangeLocalChangeRemoteCb(int32 InSomePoperty2)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		int32 TestValue = 0;
		// use different test value
		TestValue = 1;
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomePoperty2, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetSomePoperty2(ImplFixture->GetImplementation().GetObject()), TestValue);

		// now set it to the default value
		TestValue = 0; // default value
		ImplFixture->GetImplementation()->Execute_SetSomePoperty2(ImplFixture->GetImplementation().GetObject(), TestValue);
	}
	else
	{
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomePoperty2, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetSomePoperty2(ImplFixture->GetImplementation().GetObject()), TestValue);
		testDoneDelegate.Execute();
	}
}

void UTbNamesNamEsMsgBusSpec::EnumPropertyPropertyCb(ETbNamesEnum_With_Under_scores InEnumProperty)
{
	ETbNamesEnum_With_Under_scores TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FIRSTVALUE;
	// use different test value
	TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_SECONDVALUE;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InEnumProperty, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetEnumProperty(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbNamesNamEsMsgBusSpec::EnumPropertyPropertyChangeLocalCheckRemoteCb(ETbNamesEnum_With_Under_scores InEnumProperty)
{
	ETbNamesEnum_With_Under_scores TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FIRSTVALUE;
	// use different test value
	TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_SECONDVALUE;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InEnumProperty, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetEnumProperty(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbNamesNamEsMsgBusSpec::EnumPropertyPropertyChangeLocalChangeRemoteCb(ETbNamesEnum_With_Under_scores InEnumProperty)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		ETbNamesEnum_With_Under_scores TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FIRSTVALUE;
		// use different test value
		TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_SECONDVALUE;
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InEnumProperty, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetEnumProperty(ImplFixture->GetImplementation().GetObject()), TestValue);

		// now set it to the default value
		TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FIRSTVALUE; // default value
		ImplFixture->GetImplementation()->Execute_SetEnumProperty(ImplFixture->GetImplementation().GetObject(), TestValue);
	}
	else
	{
		ETbNamesEnum_With_Under_scores TestValue = ETbNamesEnum_With_Under_scores::TNEWUS_FIRSTVALUE; // default value
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InEnumProperty, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetEnumProperty(ImplFixture->GetImplementation().GetObject()), TestValue);
		testDoneDelegate.Execute();
	}
}

void UTbNamesNamEsMsgBusSpec::SomeSignalSignalCb(bool bInSomeParam)
{
	// known test value
	bool bSomeParamTestValue = true;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), bInSomeParam, bSomeParamTestValue);
	testDoneDelegate.Execute();
}

void UTbNamesNamEsMsgBusSpec::SomeSignal2SignalCb(bool bInSomeParam)
{
	// known test value
	bool bSomeParamTestValue = true;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), bInSomeParam, bSomeParamTestValue);
	testDoneDelegate.Execute();
}
#endif // WITH_DEV_AUTOMATION_TESTS
