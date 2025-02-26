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

#include "Testbed2ManyParamInterfaceMsgBus.spec.h"
#include "Testbed2/Implementation/Testbed2ManyParamInterface.h"
#include "Testbed2ManyParamInterfaceMsgBusFixture.h"
#include "Testbed2/Generated/MsgBus/Testbed2ManyParamInterfaceMsgBusClient.h"
#include "Testbed2/Generated/MsgBus/Testbed2ManyParamInterfaceMsgBusAdapter.h"
#include "HAL/Platform.h"

#if !(PLATFORM_IOS || PLATFORM_ANDROID)
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTestbed2ManyParamInterfaceMsgBusSpec::_ConnectionStatusChangedCb(bool bConnected)
{
	if (bConnected)
	{
		testDoneDelegate.Execute();
	}
}

void UTestbed2ManyParamInterfaceMsgBusSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTestbed2ManyParamInterfaceMsgBusFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		// needed for callbacks
		ImplFixture->GetHelper()->SetSpec(this);

		// set up service and adapter
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed2ManyParamInterface>();
		ImplFixture->GetAdapter()->_setBackendService(service);
		ImplFixture->GetAdapter()->_StartListening();

		// setup client
		testDoneDelegate = TestDone;
		UTestbed2ManyParamInterfaceMsgBusClient* MsgBusClient = Cast<UTestbed2ManyParamInterfaceMsgBusClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid MsgBus client", MsgBusClient != nullptr);

		MsgBusClient->_ConnectionStatusChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2ManyParamInterfaceMsgBusHelper::_ConnectionStatusChangedCb);

		MsgBusClient->_Connect();
	});

	AfterEach([this]()
		{
		ImplFixture.Reset();
	});

	It("Property.Prop1.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp1(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp1(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTestbed2ManyParamInterfaceSignals* Testbed2ManyParamInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed2ManyParamInterfaceSignals->OnProp1Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2ManyParamInterfaceMsgBusHelper::Prop1PropertyCb);
		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->Execute_SetProp1(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Property.Prop2.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp2(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.Prop2.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp2(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTestbed2ManyParamInterfaceSignals* Testbed2ManyParamInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed2ManyParamInterfaceSignals->OnProp2Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2ManyParamInterfaceMsgBusHelper::Prop2PropertyCb);
		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->Execute_SetProp2(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Property.Prop3.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp3(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.Prop3.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp3(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTestbed2ManyParamInterfaceSignals* Testbed2ManyParamInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed2ManyParamInterfaceSignals->OnProp3Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2ManyParamInterfaceMsgBusHelper::Prop3PropertyCb);
		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->Execute_SetProp3(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Property.Prop4.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp4(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.Prop4.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp4(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTestbed2ManyParamInterfaceSignals* Testbed2ManyParamInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed2ManyParamInterfaceSignals->OnProp4Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2ManyParamInterfaceMsgBusHelper::Prop4PropertyCb);
		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->Execute_SetProp4(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Operation.Func1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_Func1(ImplFixture->GetImplementation().GetObject(), 0);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_Func2(ImplFixture->GetImplementation().GetObject(), 0, 0);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func3", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_Func3(ImplFixture->GetImplementation().GetObject(), 0, 0, 0);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func4", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_Func4(ImplFixture->GetImplementation().GetObject(), 0, 0, 0, 0);
			TestDone.Execute();
		});
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTestbed2ManyParamInterfaceSignals* Testbed2ManyParamInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed2ManyParamInterfaceSignals->OnSig1Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2ManyParamInterfaceMsgBusHelper::Sig1SignalCb);

		// use different test value
		int32 Param1TestValue = 1;
		Testbed2ManyParamInterfaceSignals->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTestbed2ManyParamInterfaceSignals* Testbed2ManyParamInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed2ManyParamInterfaceSignals->OnSig2Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2ManyParamInterfaceMsgBusHelper::Sig2SignalCb);

		// use different test value
		int32 Param1TestValue = 1;
		int32 Param2TestValue = 1;
		Testbed2ManyParamInterfaceSignals->BroadcastSig2Signal(Param1TestValue, Param2TestValue);
	});

	LatentIt("Signal.Sig3", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTestbed2ManyParamInterfaceSignals* Testbed2ManyParamInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed2ManyParamInterfaceSignals->OnSig3Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2ManyParamInterfaceMsgBusHelper::Sig3SignalCb);

		// use different test value
		int32 Param1TestValue = 1;
		int32 Param2TestValue = 1;
		int32 Param3TestValue = 1;
		Testbed2ManyParamInterfaceSignals->BroadcastSig3Signal(Param1TestValue, Param2TestValue, Param3TestValue);
	});

	LatentIt("Signal.Sig4", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTestbed2ManyParamInterfaceSignals* Testbed2ManyParamInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed2ManyParamInterfaceSignals->OnSig4Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2ManyParamInterfaceMsgBusHelper::Sig4SignalCb);

		// use different test value
		int32 Param1TestValue = 1;
		int32 Param2TestValue = 1;
		int32 Param3TestValue = 1;
		int32 Param4TestValue = 1;
		Testbed2ManyParamInterfaceSignals->BroadcastSig4Signal(Param1TestValue, Param2TestValue, Param3TestValue, Param4TestValue);
	});
}

void UTestbed2ManyParamInterfaceMsgBusSpec::Prop1PropertyCb(int32 InProp1)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetProp1(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTestbed2ManyParamInterfaceMsgBusSpec::Prop2PropertyCb(int32 InProp2)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetProp2(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTestbed2ManyParamInterfaceMsgBusSpec::Prop3PropertyCb(int32 InProp3)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetProp3(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTestbed2ManyParamInterfaceMsgBusSpec::Prop4PropertyCb(int32 InProp4)
{
	int32 TestValue = 0;
	// use different test value
	TestValue = 1;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp4, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetProp4(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTestbed2ManyParamInterfaceMsgBusSpec::Sig1SignalCb(int32 InParam1)
{
	// known test value
	int32 Param1TestValue = 1;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	testDoneDelegate.Execute();
}

void UTestbed2ManyParamInterfaceMsgBusSpec::Sig2SignalCb(int32 InParam1, int32 InParam2)
{
	// known test value
	int32 Param1TestValue = 1;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	int32 Param2TestValue = 1;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
	testDoneDelegate.Execute();
}

void UTestbed2ManyParamInterfaceMsgBusSpec::Sig3SignalCb(int32 InParam1, int32 InParam2, int32 InParam3)
{
	// known test value
	int32 Param1TestValue = 1;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	int32 Param2TestValue = 1;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
	int32 Param3TestValue = 1;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam3, Param3TestValue);
	testDoneDelegate.Execute();
}

void UTestbed2ManyParamInterfaceMsgBusSpec::Sig4SignalCb(int32 InParam1, int32 InParam2, int32 InParam3, int32 InParam4)
{
	// known test value
	int32 Param1TestValue = 1;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	int32 Param2TestValue = 1;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
	int32 Param3TestValue = 1;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam3, Param3TestValue);
	int32 Param4TestValue = 1;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam4, Param4TestValue);
	testDoneDelegate.Execute();
}
#endif // WITH_DEV_AUTOMATION_TESTS
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID)
