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

#include "Testbed2NestedStruct3InterfaceOLink.spec.h"
#include "Implementation/Testbed2NestedStruct3Interface.h"
#include "Testbed2NestedStruct3InterfaceOLinkFixture.h"
#include "Generated/OLink/Testbed2NestedStruct3InterfaceOLinkClient.h"
#include "Generated/OLink/Testbed2NestedStruct3InterfaceOLinkAdapter.h"
#include "OLinkHost.h"
#include "OLinkClientConnection.h" // for olink factory
#include "Testbed2TestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTestbed2NestedStruct3InterfaceOLinkSpec::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	// ImplFixture->testDoneDelegate.Execute();
	// InTestDoneDelegate.Execute();
	if (bSubscribed)
	{
		testDoneDelegate.Execute();
	}
}

void UTestbed2NestedStruct3InterfaceOLinkSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTestbed2NestedStruct3InterfaceOLinkFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		// needed for callbacks
		ImplFixture->GetHelper()->SetSpec(this);

		// set up service and adapter
		ImplFixture->GetHost()->Stop();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed2NestedStruct3Interface>();
		ImplFixture->GetAdapter()->setBackendService(service);
		ImplFixture->GetAdapter()->setOLinkHost(ImplFixture->GetHost());
		ImplFixture->GetHost()->Start(8666);

		// setup client
		testDoneDelegate = TestDone;
		UTestbed2NestedStruct3InterfaceOLinkClient* OLinkClient = Cast<UTestbed2NestedStruct3InterfaceOLinkClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid OLink client", OLinkClient != nullptr);

		OLinkClient->_SubscriptionStatusChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2NestedStruct3InterfaceOLinkHelper::_SubscriptionStatusChangedCb);

		ImplFixture->Connection = OLinkFactory::Create(OLinkClient, "TestingConnection");
		ImplFixture->Connection->Configure("ws://127.0.0.1:8666/ws", false);

		OLinkClient->UseConnection(ImplFixture->Connection);
		ImplFixture->Connection->Connect();
	});

	AfterEach([this]()
		{
		ImplFixture->Connection->Disconnect();
		ImplFixture.Reset();
	});

	It("Property.Prop1.Default", [this]()
		{
		// Do implement test here
		FTestbed2NestedStruct1 TestValue = FTestbed2NestedStruct1(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp1(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed2NestedStruct1 TestValue = FTestbed2NestedStruct1(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp1(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTestbed2NestedStruct3InterfaceSignals* Testbed2NestedStruct3InterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed2NestedStruct3InterfaceSignals->OnProp1Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2NestedStruct3InterfaceOLinkHelper::Prop1PropertyCb);
		// use different test value
		TestValue = createTestFTestbed2NestedStruct1();
		ImplFixture->GetImplementation()->Execute_SetProp1(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Property.Prop2.Default", [this]()
		{
		// Do implement test here
		FTestbed2NestedStruct2 TestValue = FTestbed2NestedStruct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp2(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.Prop2.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed2NestedStruct2 TestValue = FTestbed2NestedStruct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp2(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTestbed2NestedStruct3InterfaceSignals* Testbed2NestedStruct3InterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed2NestedStruct3InterfaceSignals->OnProp2Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2NestedStruct3InterfaceOLinkHelper::Prop2PropertyCb);
		// use different test value
		TestValue = createTestFTestbed2NestedStruct2();
		ImplFixture->GetImplementation()->Execute_SetProp2(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Property.Prop3.Default", [this]()
		{
		// Do implement test here
		FTestbed2NestedStruct3 TestValue = FTestbed2NestedStruct3(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp3(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.Prop3.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed2NestedStruct3 TestValue = FTestbed2NestedStruct3(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp3(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTestbed2NestedStruct3InterfaceSignals* Testbed2NestedStruct3InterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed2NestedStruct3InterfaceSignals->OnProp3Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2NestedStruct3InterfaceOLinkHelper::Prop3PropertyCb);
		// use different test value
		TestValue = createTestFTestbed2NestedStruct3();
		ImplFixture->GetImplementation()->Execute_SetProp3(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Operation.Func1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_Func1(ImplFixture->GetImplementation().GetObject(), FTestbed2NestedStruct1());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_Func2(ImplFixture->GetImplementation().GetObject(), FTestbed2NestedStruct1(), FTestbed2NestedStruct2());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func3", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_Func3(ImplFixture->GetImplementation().GetObject(), FTestbed2NestedStruct1(), FTestbed2NestedStruct2(), FTestbed2NestedStruct3());
			TestDone.Execute();
		});
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTestbed2NestedStruct3InterfaceSignals* Testbed2NestedStruct3InterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed2NestedStruct3InterfaceSignals->OnSig1Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2NestedStruct3InterfaceOLinkHelper::Sig1SignalCb);

		// use different test value
		FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
		Testbed2NestedStruct3InterfaceSignals->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTestbed2NestedStruct3InterfaceSignals* Testbed2NestedStruct3InterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed2NestedStruct3InterfaceSignals->OnSig2Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2NestedStruct3InterfaceOLinkHelper::Sig2SignalCb);

		// use different test value
		FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
		FTestbed2NestedStruct2 Param2TestValue = createTestFTestbed2NestedStruct2();
		Testbed2NestedStruct3InterfaceSignals->BroadcastSig2Signal(Param1TestValue, Param2TestValue);
	});

	LatentIt("Signal.Sig3", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTestbed2NestedStruct3InterfaceSignals* Testbed2NestedStruct3InterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		Testbed2NestedStruct3InterfaceSignals->OnSig3Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTestbed2NestedStruct3InterfaceOLinkHelper::Sig3SignalCb);

		// use different test value
		FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
		FTestbed2NestedStruct2 Param2TestValue = createTestFTestbed2NestedStruct2();
		FTestbed2NestedStruct3 Param3TestValue = createTestFTestbed2NestedStruct3();
		Testbed2NestedStruct3InterfaceSignals->BroadcastSig3Signal(Param1TestValue, Param2TestValue, Param3TestValue);
	});
}

void UTestbed2NestedStruct3InterfaceOLinkSpec::Prop1PropertyCb(const FTestbed2NestedStruct1& InProp1)
{
	FTestbed2NestedStruct1 TestValue = FTestbed2NestedStruct1();
	// use different test value
	TestValue = createTestFTestbed2NestedStruct1();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetProp1(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTestbed2NestedStruct3InterfaceOLinkSpec::Prop2PropertyCb(const FTestbed2NestedStruct2& InProp2)
{
	FTestbed2NestedStruct2 TestValue = FTestbed2NestedStruct2();
	// use different test value
	TestValue = createTestFTestbed2NestedStruct2();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetProp2(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTestbed2NestedStruct3InterfaceOLinkSpec::Prop3PropertyCb(const FTestbed2NestedStruct3& InProp3)
{
	FTestbed2NestedStruct3 TestValue = FTestbed2NestedStruct3();
	// use different test value
	TestValue = createTestFTestbed2NestedStruct3();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetProp3(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTestbed2NestedStruct3InterfaceOLinkSpec::Sig1SignalCb(const FTestbed2NestedStruct1& InParam1)
{
	// known test value
	FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	testDoneDelegate.Execute();
}

void UTestbed2NestedStruct3InterfaceOLinkSpec::Sig2SignalCb(const FTestbed2NestedStruct1& InParam1, const FTestbed2NestedStruct2& InParam2)
{
	// known test value
	FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	FTestbed2NestedStruct2 Param2TestValue = createTestFTestbed2NestedStruct2();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
	testDoneDelegate.Execute();
}

void UTestbed2NestedStruct3InterfaceOLinkSpec::Sig3SignalCb(const FTestbed2NestedStruct1& InParam1, const FTestbed2NestedStruct2& InParam2, const FTestbed2NestedStruct3& InParam3)
{
	// known test value
	FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	FTestbed2NestedStruct2 Param2TestValue = createTestFTestbed2NestedStruct2();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
	FTestbed2NestedStruct3 Param3TestValue = createTestFTestbed2NestedStruct3();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam3, Param3TestValue);
	testDoneDelegate.Execute();
}
#endif // WITH_DEV_AUTOMATION_TESTS
