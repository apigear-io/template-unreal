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

#include "TbSame2SameStruct2InterfaceMsgBus.spec.h"
#include "TbSame2/Implementation/TbSame2SameStruct2Interface.h"
#include "TbSame2SameStruct2InterfaceMsgBusFixture.h"
#include "TbSame2/Generated/MsgBus/TbSame2SameStruct2InterfaceMsgBusClient.h"
#include "TbSame2/Generated/MsgBus/TbSame2SameStruct2InterfaceMsgBusAdapter.h"
#include "HAL/Platform.h"

#if !(PLATFORM_IOS || PLATFORM_ANDROID)
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSame2SameStruct2InterfaceMsgBusSpec::_ConnectionStatusChangedCb(bool bConnected)
{
	if (bConnected)
	{
		testDoneDelegate.Execute();
	}
}

void UTbSame2SameStruct2InterfaceMsgBusSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbSame2SameStruct2InterfaceMsgBusFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		// needed for callbacks
		ImplFixture->GetHelper()->SetSpec(this);

		// set up service and adapter
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSame2SameStruct2Interface>();
		ImplFixture->GetAdapter()->_setBackendService(service);
		ImplFixture->GetAdapter()->_StartListening();

		// setup client
		testDoneDelegate = TestDone;
		UTbSame2SameStruct2InterfaceMsgBusClient* MsgBusClient = Cast<UTbSame2SameStruct2InterfaceMsgBusClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid MsgBus client", MsgBusClient != nullptr);

		MsgBusClient->_ConnectionStatusChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSame2SameStruct2InterfaceMsgBusHelper::_ConnectionStatusChangedCb);

		MsgBusClient->_Connect();
	});

	AfterEach([this]()
		{
		ImplFixture.Reset();
	});

	It("Property.Prop1.Default", [this]()
		{
		// Do implement test here
		FTbSame2Struct2 TestValue = FTbSame2Struct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbSame2Struct2 TestValue = FTbSame2Struct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		testDoneDelegate = TestDone;
		UTbSame2SameStruct2InterfaceSignals* TbSame2SameStruct2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame2SameStruct2InterfaceSignals->OnProp1Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSame2SameStruct2InterfaceMsgBusHelper::Prop1PropertyCb);
		// use different test value
		TestValue = createTestFTbSame2Struct2();
		ImplFixture->GetImplementation()->SetProp1(TestValue);
	});

	It("Property.Prop2.Default", [this]()
		{
		// Do implement test here
		FTbSame2Struct2 TestValue = FTbSame2Struct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
	});

	LatentIt("Property.Prop2.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbSame2Struct2 TestValue = FTbSame2Struct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);

		testDoneDelegate = TestDone;
		UTbSame2SameStruct2InterfaceSignals* TbSame2SameStruct2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame2SameStruct2InterfaceSignals->OnProp2Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSame2SameStruct2InterfaceMsgBusHelper::Prop2PropertyCb);
		// use different test value
		TestValue = createTestFTbSame2Struct2();
		ImplFixture->GetImplementation()->SetProp2(TestValue);
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

	LatentIt("Operation.Func2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func2(FTbSame2Struct1(), FTbSame2Struct2());
			TestDone.Execute();
		});
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSame2SameStruct2InterfaceSignals* TbSame2SameStruct2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame2SameStruct2InterfaceSignals->OnSig1Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSame2SameStruct2InterfaceMsgBusHelper::Sig1SignalCb);

		// use different test value
		FTbSame2Struct1 Param1TestValue = createTestFTbSame2Struct1();
		TbSame2SameStruct2InterfaceSignals->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSame2SameStruct2InterfaceSignals* TbSame2SameStruct2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame2SameStruct2InterfaceSignals->OnSig2Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSame2SameStruct2InterfaceMsgBusHelper::Sig2SignalCb);

		// use different test value
		FTbSame2Struct1 Param1TestValue = createTestFTbSame2Struct1();
		FTbSame2Struct2 Param2TestValue = createTestFTbSame2Struct2();
		TbSame2SameStruct2InterfaceSignals->BroadcastSig2Signal(Param1TestValue, Param2TestValue);
	});
}

void UTbSame2SameStruct2InterfaceMsgBusSpec::Prop1PropertyCb(const FTbSame2Struct2& InProp1)
{
	FTbSame2Struct2 TestValue = FTbSame2Struct2();
	// use different test value
	TestValue = createTestFTbSame2Struct2();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
	testDoneDelegate.Execute();
}

void UTbSame2SameStruct2InterfaceMsgBusSpec::Prop2PropertyCb(const FTbSame2Struct2& InProp2)
{
	FTbSame2Struct2 TestValue = FTbSame2Struct2();
	// use different test value
	TestValue = createTestFTbSame2Struct2();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
	testDoneDelegate.Execute();
}

void UTbSame2SameStruct2InterfaceMsgBusSpec::Sig1SignalCb(const FTbSame2Struct1& InParam1)
{
	// known test value
	FTbSame2Struct1 Param1TestValue = createTestFTbSame2Struct1();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	testDoneDelegate.Execute();
}

void UTbSame2SameStruct2InterfaceMsgBusSpec::Sig2SignalCb(const FTbSame2Struct1& InParam1, const FTbSame2Struct2& InParam2)
{
	// known test value
	FTbSame2Struct1 Param1TestValue = createTestFTbSame2Struct1();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	FTbSame2Struct2 Param2TestValue = createTestFTbSame2Struct2();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
	testDoneDelegate.Execute();
}
#endif // WITH_DEV_AUTOMATION_TESTS
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID)
