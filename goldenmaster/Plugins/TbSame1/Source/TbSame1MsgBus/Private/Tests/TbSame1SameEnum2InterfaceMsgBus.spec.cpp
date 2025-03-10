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

#include "TbSame1SameEnum2InterfaceMsgBus.spec.h"
#include "TbSame1/Implementation/TbSame1SameEnum2Interface.h"
#include "TbSame1SameEnum2InterfaceMsgBusFixture.h"
#include "TbSame1/Generated/MsgBus/TbSame1SameEnum2InterfaceMsgBusClient.h"
#include "TbSame1/Generated/MsgBus/TbSame1SameEnum2InterfaceMsgBusAdapter.h"
#include "HAL/Platform.h"

#if !(PLATFORM_IOS || PLATFORM_ANDROID)
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSame1SameEnum2InterfaceMsgBusSpec::_ConnectionStatusChangedCb(bool bConnected)
{
	if (bConnected)
	{
		testDoneDelegate.Execute();
	}
}

void UTbSame1SameEnum2InterfaceMsgBusSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbSame1SameEnum2InterfaceMsgBusFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		// needed for callbacks
		ImplFixture->GetHelper()->SetSpec(this);

		// set up service and adapter
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSame1SameEnum2Interface>();
		ImplFixture->GetAdapter()->_setBackendService(service);
		ImplFixture->GetAdapter()->_StartListening();

		// setup client
		testDoneDelegate = TestDone;
		UTbSame1SameEnum2InterfaceMsgBusClient* MsgBusClient = Cast<UTbSame1SameEnum2InterfaceMsgBusClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid MsgBus client", MsgBusClient != nullptr);

		MsgBusClient->_ConnectionStatusChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSame1SameEnum2InterfaceMsgBusHelper::_ConnectionStatusChangedCb);

		MsgBusClient->_Connect();
	});

	AfterEach([this]()
		{
		ImplFixture.Reset();
	});

	It("Property.Prop1.Default", [this]()
		{
		// Do implement test here
		ETbSame1Enum1 TestValue = ETbSame1Enum1::TS1E1_VALUE1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbSame1Enum1 TestValue = ETbSame1Enum1::TS1E1_VALUE1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		testDoneDelegate = TestDone;
		UTbSame1SameEnum2InterfaceSignals* TbSame1SameEnum2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame1SameEnum2InterfaceSignals->OnProp1ChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSame1SameEnum2InterfaceMsgBusHelper::Prop1PropertyCb);
		// use different test value
		TestValue = ETbSame1Enum1::TS1E1_VALUE2;
		ImplFixture->GetImplementation()->SetProp1(TestValue);
	});

	It("Property.Prop2.Default", [this]()
		{
		// Do implement test here
		ETbSame1Enum2 TestValue = ETbSame1Enum2::TS1E2_VALUE1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
	});

	LatentIt("Property.Prop2.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbSame1Enum2 TestValue = ETbSame1Enum2::TS1E2_VALUE1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);

		testDoneDelegate = TestDone;
		UTbSame1SameEnum2InterfaceSignals* TbSame1SameEnum2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame1SameEnum2InterfaceSignals->OnProp2ChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSame1SameEnum2InterfaceMsgBusHelper::Prop2PropertyCb);
		// use different test value
		TestValue = ETbSame1Enum2::TS1E2_VALUE2;
		ImplFixture->GetImplementation()->SetProp2(TestValue);
	});

	LatentIt("Operation.Func1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func1(ETbSame1Enum1::TS1E1_VALUE1);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func2(ETbSame1Enum1::TS1E1_VALUE1, ETbSame1Enum2::TS1E2_VALUE1);
			TestDone.Execute();
		});
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSame1SameEnum2InterfaceSignals* TbSame1SameEnum2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame1SameEnum2InterfaceSignals->OnSig1SignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSame1SameEnum2InterfaceMsgBusHelper::Sig1SignalCb);

		// use different test value
		ETbSame1Enum1 Param1TestValue = ETbSame1Enum1::TS1E1_VALUE2;
		TbSame1SameEnum2InterfaceSignals->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSame1SameEnum2InterfaceSignals* TbSame1SameEnum2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame1SameEnum2InterfaceSignals->OnSig2SignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSame1SameEnum2InterfaceMsgBusHelper::Sig2SignalCb);

		// use different test value
		ETbSame1Enum1 Param1TestValue = ETbSame1Enum1::TS1E1_VALUE2;
		ETbSame1Enum2 Param2TestValue = ETbSame1Enum2::TS1E2_VALUE2;
		TbSame1SameEnum2InterfaceSignals->BroadcastSig2Signal(Param1TestValue, Param2TestValue);
	});
}

void UTbSame1SameEnum2InterfaceMsgBusSpec::Prop1PropertyCb(ETbSame1Enum1 InProp1)
{
	ETbSame1Enum1 TestValue = ETbSame1Enum1::TS1E1_VALUE1;
	// use different test value
	TestValue = ETbSame1Enum1::TS1E1_VALUE2;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
	testDoneDelegate.Execute();
}

void UTbSame1SameEnum2InterfaceMsgBusSpec::Prop2PropertyCb(ETbSame1Enum2 InProp2)
{
	ETbSame1Enum2 TestValue = ETbSame1Enum2::TS1E2_VALUE1;
	// use different test value
	TestValue = ETbSame1Enum2::TS1E2_VALUE2;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
	testDoneDelegate.Execute();
}

void UTbSame1SameEnum2InterfaceMsgBusSpec::Sig1SignalCb(ETbSame1Enum1 InParam1)
{
	// known test value
	ETbSame1Enum1 Param1TestValue = ETbSame1Enum1::TS1E1_VALUE2;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	testDoneDelegate.Execute();
}

void UTbSame1SameEnum2InterfaceMsgBusSpec::Sig2SignalCb(ETbSame1Enum1 InParam1, ETbSame1Enum2 InParam2)
{
	// known test value
	ETbSame1Enum1 Param1TestValue = ETbSame1Enum1::TS1E1_VALUE2;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	ETbSame1Enum2 Param2TestValue = ETbSame1Enum2::TS1E2_VALUE2;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
	testDoneDelegate.Execute();
}
#endif // WITH_DEV_AUTOMATION_TESTS
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID)
