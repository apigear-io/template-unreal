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

#include "TbSame1SameStruct2InterfaceOLink.spec.h"
#include "OLinkCommon.h"
#include "Implementation/TbSame1SameStruct2Interface.h"
#include "TbSame1SameStruct2InterfaceOLinkFixture.h"
#include "Generated/OLink/TbSame1SameStruct2InterfaceOLinkClient.h"
#include "Generated/OLink/TbSame1SameStruct2InterfaceOLinkAdapter.h"
#include "HAL/Platform.h"

#if !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
#include "OLinkHost.h"
#include "OLinkClientConnection.h" // for olink factory
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSame1SameStruct2InterfaceOLinkSpec::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	// ImplFixture->testDoneDelegate.Execute();
	// InTestDoneDelegate.Execute();
	if (bSubscribed)
	{
		testDoneDelegate.Execute();
	}
}

void UTbSame1SameStruct2InterfaceOLinkSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbSame1SameStruct2InterfaceOLinkFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		// needed for callbacks
		ImplFixture->GetHelper()->SetSpec(this);

		// set up service and adapter
		ImplFixture->GetHost()->Stop();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSame1SameStruct2Interface>();
		ImplFixture->GetAdapter()->setBackendService(service);
		ImplFixture->GetAdapter()->setOLinkHost(ImplFixture->GetHost());
		ImplFixture->GetHost()->Start(8666);

		// setup client
		testDoneDelegate = TestDone;
		UTbSame1SameStruct2InterfaceOLinkClient* OLinkClient = Cast<UTbSame1SameStruct2InterfaceOLinkClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid OLink client", OLinkClient != nullptr);

		OLinkClient->_SubscriptionStatusChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSame1SameStruct2InterfaceOLinkHelper::_SubscriptionStatusChangedCb);

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
		FTbSame1Struct2 TestValue = FTbSame1Struct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp1(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbSame1Struct2 TestValue = FTbSame1Struct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp1(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSame1SameStruct2InterfaceSignals* TbSame1SameStruct2InterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSame1SameStruct2InterfaceSignals->OnProp1Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSame1SameStruct2InterfaceOLinkHelper::Prop1PropertyCb);
		// use different test value
		TestValue = createTestFTbSame1Struct2();
		ImplFixture->GetImplementation()->Execute_SetProp1(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Property.Prop1.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbSame1Struct2 TestValue = FTbSame1Struct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp1(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSame1SameStruct2InterfaceSignals* TbSame1SameStruct2InterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSame1SameStruct2InterfaceSignals->OnProp1Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSame1SameStruct2InterfaceOLinkHelper::Prop1PropertyChangeLocalCheckRemoteCb);
		// use different test value
		TestValue = createTestFTbSame1Struct2();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSame1SameStruct2Interface>();
		service->Execute_SetProp1(service, TestValue);
	});

	LatentIt("Property.Prop1.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbSame1Struct2 TestValue = FTbSame1Struct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp1(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSame1SameStruct2InterfaceSignals* TbSame1SameStruct2InterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSame1SameStruct2InterfaceSignals->OnProp1Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSame1SameStruct2InterfaceOLinkHelper::Prop1PropertyChangeLocalChangeRemoteCb);
		// use different test value
		TestValue = createTestFTbSame1Struct2();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSame1SameStruct2Interface>();
		service->Execute_SetProp1(service, TestValue);
	});

	It("Property.Prop2.Default", [this]()
		{
		// Do implement test here
		FTbSame1Struct2 TestValue = FTbSame1Struct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp2(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.Prop2.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbSame1Struct2 TestValue = FTbSame1Struct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp2(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSame1SameStruct2InterfaceSignals* TbSame1SameStruct2InterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSame1SameStruct2InterfaceSignals->OnProp2Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSame1SameStruct2InterfaceOLinkHelper::Prop2PropertyCb);
		// use different test value
		TestValue = createTestFTbSame1Struct2();
		ImplFixture->GetImplementation()->Execute_SetProp2(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Property.Prop2.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbSame1Struct2 TestValue = FTbSame1Struct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp2(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSame1SameStruct2InterfaceSignals* TbSame1SameStruct2InterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSame1SameStruct2InterfaceSignals->OnProp2Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSame1SameStruct2InterfaceOLinkHelper::Prop2PropertyChangeLocalCheckRemoteCb);
		// use different test value
		TestValue = createTestFTbSame1Struct2();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSame1SameStruct2Interface>();
		service->Execute_SetProp2(service, TestValue);
	});

	LatentIt("Property.Prop2.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbSame1Struct2 TestValue = FTbSame1Struct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp2(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbSame1SameStruct2InterfaceSignals* TbSame1SameStruct2InterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSame1SameStruct2InterfaceSignals->OnProp2Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSame1SameStruct2InterfaceOLinkHelper::Prop2PropertyChangeLocalChangeRemoteCb);
		// use different test value
		TestValue = createTestFTbSame1Struct2();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSame1SameStruct2Interface>();
		service->Execute_SetProp2(service, TestValue);
	});

	LatentIt("Operation.Func1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_Func1(ImplFixture->GetImplementation().GetObject(), FTbSame1Struct1());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_Func2(ImplFixture->GetImplementation().GetObject(), FTbSame1Struct1(), FTbSame1Struct2());
			TestDone.Execute();
		});
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSame1SameStruct2InterfaceSignals* TbSame1SameStruct2InterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSame1SameStruct2InterfaceSignals->OnSig1Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSame1SameStruct2InterfaceOLinkHelper::Sig1SignalCb);

		// use different test value
		FTbSame1Struct1 Param1TestValue = createTestFTbSame1Struct1();
		TbSame1SameStruct2InterfaceSignals->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSame1SameStruct2InterfaceSignals* TbSame1SameStruct2InterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSame1SameStruct2InterfaceSignals->OnSig2Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSame1SameStruct2InterfaceOLinkHelper::Sig2SignalCb);

		// use different test value
		FTbSame1Struct1 Param1TestValue = createTestFTbSame1Struct1();
		FTbSame1Struct2 Param2TestValue = createTestFTbSame1Struct2();
		TbSame1SameStruct2InterfaceSignals->BroadcastSig2Signal(Param1TestValue, Param2TestValue);
	});
}

void UTbSame1SameStruct2InterfaceOLinkSpec::Prop1PropertyCb(const FTbSame1Struct2& InProp1)
{
	FTbSame1Struct2 TestValue = FTbSame1Struct2();
	// use different test value
	TestValue = createTestFTbSame1Struct2();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetProp1(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSame1SameStruct2InterfaceOLinkSpec::Prop1PropertyChangeLocalCheckRemoteCb(const FTbSame1Struct2& InProp1)
{
	FTbSame1Struct2 TestValue = FTbSame1Struct2();
	// use different test value
	TestValue = createTestFTbSame1Struct2();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetProp1(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSame1SameStruct2InterfaceOLinkSpec::Prop1PropertyChangeLocalChangeRemoteCb(const FTbSame1Struct2& InProp1)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		FTbSame1Struct2 TestValue = FTbSame1Struct2();
		// use different test value
		TestValue = createTestFTbSame1Struct2();
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetProp1(ImplFixture->GetImplementation().GetObject()), TestValue);

		// now set it to the default value
		TestValue = FTbSame1Struct2(); // default value
		ImplFixture->GetImplementation()->Execute_SetProp1(ImplFixture->GetImplementation().GetObject(), TestValue);
	}
	else
	{
		FTbSame1Struct2 TestValue = FTbSame1Struct2(); // default value
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetProp1(ImplFixture->GetImplementation().GetObject()), TestValue);
		testDoneDelegate.Execute();
	}
}

void UTbSame1SameStruct2InterfaceOLinkSpec::Prop2PropertyCb(const FTbSame1Struct2& InProp2)
{
	FTbSame1Struct2 TestValue = FTbSame1Struct2();
	// use different test value
	TestValue = createTestFTbSame1Struct2();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetProp2(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSame1SameStruct2InterfaceOLinkSpec::Prop2PropertyChangeLocalCheckRemoteCb(const FTbSame1Struct2& InProp2)
{
	FTbSame1Struct2 TestValue = FTbSame1Struct2();
	// use different test value
	TestValue = createTestFTbSame1Struct2();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetProp2(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbSame1SameStruct2InterfaceOLinkSpec::Prop2PropertyChangeLocalChangeRemoteCb(const FTbSame1Struct2& InProp2)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		FTbSame1Struct2 TestValue = FTbSame1Struct2();
		// use different test value
		TestValue = createTestFTbSame1Struct2();
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetProp2(ImplFixture->GetImplementation().GetObject()), TestValue);

		// now set it to the default value
		TestValue = FTbSame1Struct2(); // default value
		ImplFixture->GetImplementation()->Execute_SetProp2(ImplFixture->GetImplementation().GetObject(), TestValue);
	}
	else
	{
		FTbSame1Struct2 TestValue = FTbSame1Struct2(); // default value
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetProp2(ImplFixture->GetImplementation().GetObject()), TestValue);
		testDoneDelegate.Execute();
	}
}

void UTbSame1SameStruct2InterfaceOLinkSpec::Sig1SignalCb(const FTbSame1Struct1& InParam1)
{
	// known test value
	FTbSame1Struct1 Param1TestValue = createTestFTbSame1Struct1();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	testDoneDelegate.Execute();
}

void UTbSame1SameStruct2InterfaceOLinkSpec::Sig2SignalCb(const FTbSame1Struct1& InParam1, const FTbSame1Struct2& InParam2)
{
	// known test value
	FTbSame1Struct1 Param1TestValue = createTestFTbSame1Struct1();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	FTbSame1Struct2 Param2TestValue = createTestFTbSame1Struct2();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
	testDoneDelegate.Execute();
}
#endif // WITH_DEV_AUTOMATION_TESTS
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
