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

#include "TbEnumEnumInterfaceMsgBus.spec.h"
#include "TbEnum/Implementation/TbEnumEnumInterface.h"
#include "TbEnumEnumInterfaceMsgBusFixture.h"
#include "TbEnum/Generated/MsgBus/TbEnumEnumInterfaceMsgBusClient.h"
#include "TbEnum/Generated/MsgBus/TbEnumEnumInterfaceMsgBusAdapter.h"
#include "HAL/Platform.h"

#if !(PLATFORM_IOS || PLATFORM_ANDROID)
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbEnumEnumInterfaceMsgBusSpec::_ConnectionStatusChangedCb(bool bConnected)
{
	if (bConnected)
	{
		testDoneDelegate.Execute();
	}
}

void UTbEnumEnumInterfaceMsgBusSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbEnumEnumInterfaceMsgBusFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		// needed for callbacks
		ImplFixture->GetHelper()->SetSpec(this);

		// set up service and adapter
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbEnumEnumInterface>();
		ImplFixture->GetAdapter()->_setBackendService(service);
		ImplFixture->GetAdapter()->_StartListening();

		// setup client
		testDoneDelegate = TestDone;
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
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp0(), TestValue);
	});

	LatentIt("Property.Prop0.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum0 TestValue = ETbEnumEnum0::TEE0_VALUE0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp0(), TestValue);

		testDoneDelegate = TestDone;
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnProp0ChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceMsgBusHelper::Prop0PropertyCb);
		// use different test value
		TestValue = ETbEnumEnum0::TEE0_VALUE1;
		ImplFixture->GetImplementation()->SetProp0(TestValue);
	});

	It("Property.Prop1.Default", [this]()
		{
		// Do implement test here
		ETbEnumEnum1 TestValue = ETbEnumEnum1::TEE1_VALUE1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum1 TestValue = ETbEnumEnum1::TEE1_VALUE1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		testDoneDelegate = TestDone;
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnProp1ChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceMsgBusHelper::Prop1PropertyCb);
		// use different test value
		TestValue = ETbEnumEnum1::TEE1_VALUE2;
		ImplFixture->GetImplementation()->SetProp1(TestValue);
	});

	It("Property.Prop2.Default", [this]()
		{
		// Do implement test here
		ETbEnumEnum2 TestValue = ETbEnumEnum2::TEE2_VALUE2; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
	});

	LatentIt("Property.Prop2.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum2 TestValue = ETbEnumEnum2::TEE2_VALUE2; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);

		testDoneDelegate = TestDone;
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnProp2ChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceMsgBusHelper::Prop2PropertyCb);
		// use different test value
		TestValue = ETbEnumEnum2::TEE2_VALUE1;
		ImplFixture->GetImplementation()->SetProp2(TestValue);
	});

	It("Property.Prop3.Default", [this]()
		{
		// Do implement test here
		ETbEnumEnum3 TestValue = ETbEnumEnum3::TEE3_VALUE3; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp3(), TestValue);
	});

	LatentIt("Property.Prop3.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum3 TestValue = ETbEnumEnum3::TEE3_VALUE3; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp3(), TestValue);

		testDoneDelegate = TestDone;
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnProp3ChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceMsgBusHelper::Prop3PropertyCb);
		// use different test value
		TestValue = ETbEnumEnum3::TEE3_VALUE2;
		ImplFixture->GetImplementation()->SetProp3(TestValue);
	});

	LatentIt("Operation.Func0", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func0(ETbEnumEnum0::TEE0_VALUE0);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func1(ETbEnumEnum1::TEE1_VALUE1);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func2(ETbEnumEnum2::TEE2_VALUE2);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func3", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func3(ETbEnumEnum3::TEE3_VALUE3);
			TestDone.Execute();
		});
	});

	LatentIt("Signal.Sig0", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnSig0SignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceMsgBusHelper::Sig0SignalCb);

		// use different test value
		ETbEnumEnum0 Param0TestValue = ETbEnumEnum0::TEE0_VALUE1;
		TbEnumEnumInterfaceSignals->BroadcastSig0Signal(Param0TestValue);
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnSig1SignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceMsgBusHelper::Sig1SignalCb);

		// use different test value
		ETbEnumEnum1 Param1TestValue = ETbEnumEnum1::TEE1_VALUE2;
		TbEnumEnumInterfaceSignals->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnSig2SignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceMsgBusHelper::Sig2SignalCb);

		// use different test value
		ETbEnumEnum2 Param2TestValue = ETbEnumEnum2::TEE2_VALUE1;
		TbEnumEnumInterfaceSignals->BroadcastSig2Signal(Param2TestValue);
	});

	LatentIt("Signal.Sig3", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbEnumEnumInterfaceSignals->OnSig3SignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceMsgBusHelper::Sig3SignalCb);

		// use different test value
		ETbEnumEnum3 Param3TestValue = ETbEnumEnum3::TEE3_VALUE2;
		TbEnumEnumInterfaceSignals->BroadcastSig3Signal(Param3TestValue);
	});
}

void UTbEnumEnumInterfaceMsgBusSpec::Prop0PropertyCb(ETbEnumEnum0 InProp0)
{
	ETbEnumEnum0 TestValue = ETbEnumEnum0::TEE0_VALUE0;
	// use different test value
	TestValue = ETbEnumEnum0::TEE0_VALUE1;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp0, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp0(), TestValue);
	testDoneDelegate.Execute();
}

void UTbEnumEnumInterfaceMsgBusSpec::Prop1PropertyCb(ETbEnumEnum1 InProp1)
{
	ETbEnumEnum1 TestValue = ETbEnumEnum1::TEE1_VALUE1;
	// use different test value
	TestValue = ETbEnumEnum1::TEE1_VALUE2;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
	testDoneDelegate.Execute();
}

void UTbEnumEnumInterfaceMsgBusSpec::Prop2PropertyCb(ETbEnumEnum2 InProp2)
{
	ETbEnumEnum2 TestValue = ETbEnumEnum2::TEE2_VALUE2;
	// use different test value
	TestValue = ETbEnumEnum2::TEE2_VALUE1;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
	testDoneDelegate.Execute();
}

void UTbEnumEnumInterfaceMsgBusSpec::Prop3PropertyCb(ETbEnumEnum3 InProp3)
{
	ETbEnumEnum3 TestValue = ETbEnumEnum3::TEE3_VALUE3;
	// use different test value
	TestValue = ETbEnumEnum3::TEE3_VALUE2;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp3(), TestValue);
	testDoneDelegate.Execute();
}

void UTbEnumEnumInterfaceMsgBusSpec::Sig0SignalCb(ETbEnumEnum0 InParam0)
{
	// known test value
	ETbEnumEnum0 Param0TestValue = ETbEnumEnum0::TEE0_VALUE1;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam0, Param0TestValue);
	testDoneDelegate.Execute();
}

void UTbEnumEnumInterfaceMsgBusSpec::Sig1SignalCb(ETbEnumEnum1 InParam1)
{
	// known test value
	ETbEnumEnum1 Param1TestValue = ETbEnumEnum1::TEE1_VALUE2;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	testDoneDelegate.Execute();
}

void UTbEnumEnumInterfaceMsgBusSpec::Sig2SignalCb(ETbEnumEnum2 InParam2)
{
	// known test value
	ETbEnumEnum2 Param2TestValue = ETbEnumEnum2::TEE2_VALUE1;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
	testDoneDelegate.Execute();
}

void UTbEnumEnumInterfaceMsgBusSpec::Sig3SignalCb(ETbEnumEnum3 InParam3)
{
	// known test value
	ETbEnumEnum3 Param3TestValue = ETbEnumEnum3::TEE3_VALUE2;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam3, Param3TestValue);
	testDoneDelegate.Execute();
}
#endif // WITH_DEV_AUTOMATION_TESTS
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID)
