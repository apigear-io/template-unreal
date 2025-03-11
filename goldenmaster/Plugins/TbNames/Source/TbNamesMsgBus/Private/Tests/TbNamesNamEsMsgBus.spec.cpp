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
#include "TbNames/Implementation/TbNamesNamEs.h"
#include "TbNamesNamEsMsgBusFixture.h"
#include "TbNames/Generated/MsgBus/TbNamesNamEsMsgBusClient.h"
#include "TbNames/Generated/MsgBus/TbNamesNamEsMsgBusAdapter.h"
#include "HAL/Platform.h"

#if !(PLATFORM_IOS || PLATFORM_ANDROID)
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

		MsgBusClient->_ConnectionStatusChanged.AddUObject(ImplFixture->GetHelper().Get(), &UTbNamesNamEsMsgBusHelper::_ConnectionStatusChangedCb);

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
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetSwitch(), TestValue);
	});

	LatentIt("Property.Switch.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		bool TestValue = false; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetSwitch(), TestValue);

		testDoneDelegate = TestDone;
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbNamesNamEsSignals->OnSwitchChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsMsgBusHelper::SwitchPropertyCb);
		// use different test value
		TestValue = true;
		ImplFixture->GetImplementation()->SetSwitch(TestValue);
	});

	It("Property.SomeProperty.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetSomeProperty(), TestValue);
	});

	LatentIt("Property.SomeProperty.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetSomeProperty(), TestValue);

		testDoneDelegate = TestDone;
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbNamesNamEsSignals->OnSomePropertyChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsMsgBusHelper::SomePropertyPropertyCb);
		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->SetSomeProperty(TestValue);
	});

	It("Property.SomePoperty2.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetSomePoperty2(), TestValue);
	});

	LatentIt("Property.SomePoperty2.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetSomePoperty2(), TestValue);

		testDoneDelegate = TestDone;
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbNamesNamEsSignals->OnSomePoperty2ChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsMsgBusHelper::SomePoperty2PropertyCb);
		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->SetSomePoperty2(TestValue);
	});

	LatentIt("Operation.SomeFunction", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->SomeFunction(false);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.SomeFunction2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->SomeFunction2(false);
			TestDone.Execute();
		});
	});

	LatentIt("Signal.SomeSignal", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbNamesNamEsSignals->OnSomeSignalSignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsMsgBusHelper::SomeSignalSignalCb);

		// use different test value
		bool bSomeParamTestValue = true;
		TbNamesNamEsSignals->BroadcastSomeSignalSignal(bSomeParamTestValue);
	});

	LatentIt("Signal.SomeSignal2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbNamesNamEsSignals* TbNamesNamEsSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbNamesNamEsSignals->OnSomeSignal2SignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbNamesNamEsMsgBusHelper::SomeSignal2SignalCb);

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
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetSwitch(), TestValue);
	testDoneDelegate.Execute();
}

void UTbNamesNamEsMsgBusSpec::SomePropertyPropertyCb(int32 InSomeProperty)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomeProperty, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetSomeProperty(), TestValue);
	testDoneDelegate.Execute();
}

void UTbNamesNamEsMsgBusSpec::SomePoperty2PropertyCb(int32 InSomePoperty2)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InSomePoperty2, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetSomePoperty2(), TestValue);
	testDoneDelegate.Execute();
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
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID)
