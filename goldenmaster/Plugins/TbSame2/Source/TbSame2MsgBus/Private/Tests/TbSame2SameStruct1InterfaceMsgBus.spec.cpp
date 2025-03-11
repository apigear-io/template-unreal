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

#include "TbSame2SameStruct1InterfaceMsgBus.spec.h"
#include "TbSame2/Implementation/TbSame2SameStruct1Interface.h"
#include "TbSame2SameStruct1InterfaceMsgBusFixture.h"
#include "TbSame2/Generated/MsgBus/TbSame2SameStruct1InterfaceMsgBusClient.h"
#include "TbSame2/Generated/MsgBus/TbSame2SameStruct1InterfaceMsgBusAdapter.h"
#include "HAL/Platform.h"

#if !(PLATFORM_IOS || PLATFORM_ANDROID)
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSame2SameStruct1InterfaceMsgBusSpec::_ConnectionStatusChangedCb(bool bConnected)
{
	if (bConnected)
	{
		testDoneDelegate.Execute();
	}
}

void UTbSame2SameStruct1InterfaceMsgBusSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbSame2SameStruct1InterfaceMsgBusFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		// needed for callbacks
		ImplFixture->GetHelper()->SetSpec(this);

		// set up service and adapter
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSame2SameStruct1Interface>();
		ImplFixture->GetAdapter()->_setBackendService(service);
		ImplFixture->GetAdapter()->_StartListening();

		// setup client
		testDoneDelegate = TestDone;
		UTbSame2SameStruct1InterfaceMsgBusClient* MsgBusClient = Cast<UTbSame2SameStruct1InterfaceMsgBusClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid MsgBus client", MsgBusClient != nullptr);

		MsgBusClient->_ConnectionStatusChanged.AddUObject(ImplFixture->GetHelper().Get(), &UTbSame2SameStruct1InterfaceMsgBusHelper::_ConnectionStatusChangedCb);

		MsgBusClient->_Connect();
	});

	AfterEach([this]()
		{
		ImplFixture.Reset();
	});

	It("Property.Prop1.Default", [this]()
		{
		// Do implement test here
		FTbSame2Struct1 TestValue = FTbSame2Struct1(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbSame2Struct1 TestValue = FTbSame2Struct1(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		testDoneDelegate = TestDone;
		UTbSame2SameStruct1InterfaceSignals* TbSame2SameStruct1InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame2SameStruct1InterfaceSignals->OnProp1ChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSame2SameStruct1InterfaceMsgBusHelper::Prop1PropertyCb);
		// use different test value
		TestValue = createTestFTbSame2Struct1();
		ImplFixture->GetImplementation()->SetProp1(TestValue);
	});

	LatentIt("Operation.Func1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func1(FTbSame2Struct1());
			TestDone.Execute();
		});
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSame2SameStruct1InterfaceSignals* TbSame2SameStruct1InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame2SameStruct1InterfaceSignals->OnSig1SignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSame2SameStruct1InterfaceMsgBusHelper::Sig1SignalCb);

		// use different test value
		FTbSame2Struct1 Param1TestValue = createTestFTbSame2Struct1();
		TbSame2SameStruct1InterfaceSignals->BroadcastSig1Signal(Param1TestValue);
	});
}

void UTbSame2SameStruct1InterfaceMsgBusSpec::Prop1PropertyCb(const FTbSame2Struct1& InProp1)
{
	FTbSame2Struct1 TestValue = FTbSame2Struct1();
	// use different test value
	TestValue = createTestFTbSame2Struct1();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
	testDoneDelegate.Execute();
}

void UTbSame2SameStruct1InterfaceMsgBusSpec::Sig1SignalCb(const FTbSame2Struct1& InParam1)
{
	// known test value
	FTbSame2Struct1 Param1TestValue = createTestFTbSame2Struct1();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	testDoneDelegate.Execute();
}
#endif // WITH_DEV_AUTOMATION_TESTS
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID)
