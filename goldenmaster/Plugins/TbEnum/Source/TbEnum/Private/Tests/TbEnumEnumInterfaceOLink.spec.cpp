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

#include "TbEnumEnumInterfaceOLink.spec.h"
#include "Implementation/TbEnumEnumInterface.h"
#include "TbEnumEnumInterfaceOLinkFixture.h"
#include "Generated/OLink/TbEnumEnumInterfaceOLinkClient.h"
#include "Generated/OLink/TbEnumEnumInterfaceOLinkAdapter.h"
#include "OLinkHost.h"
#include "OLinkClientConnection.h" // for olink factory
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbEnumEnumInterfaceOLinkSpec::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	// ImplFixture->testDoneDelegate.Execute();
	// InTestDoneDelegate.Execute();
	if (bSubscribed)
	{
		testDoneDelegate.Execute();
	}
}

void UTbEnumEnumInterfaceOLinkSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbEnumEnumInterfaceOLinkFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		// needed for callbacks
		ImplFixture->GetHelper()->SetSpec(this);

		// set up service and adapter
		ImplFixture->GetHost()->Stop();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbEnumEnumInterface>();
		ImplFixture->GetAdapter()->setBackendService(service);
		ImplFixture->GetAdapter()->setOLinkHost(ImplFixture->GetHost());
		ImplFixture->GetHost()->Start(8666);

		// setup client
		testDoneDelegate = TestDone;
		UTbEnumEnumInterfaceOLinkClient* OLinkClient = Cast<UTbEnumEnumInterfaceOLinkClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid OLink client", OLinkClient != nullptr);

		OLinkClient->_SubscriptionStatusChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceOLinkHelper::_SubscriptionStatusChangedCb);

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

	It("Property.Prop0.Default", [this]()
		{
		// Do implement test here
		ETbEnumEnum0 TestValue = ETbEnumEnum0::TEE0_VALUE0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp0(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.Prop0.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum0 TestValue = ETbEnumEnum0::TEE0_VALUE0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp0(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbEnumEnumInterfaceSignals->OnProp0Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceOLinkHelper::Prop0PropertyCb);
		// use different test value
		TestValue = ETbEnumEnum0::TEE0_VALUE1;
		ImplFixture->GetImplementation()->Execute_SetProp0(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Property.Prop1.Default", [this]()
		{
		// Do implement test here
		ETbEnumEnum1 TestValue = ETbEnumEnum1::TEE1_VALUE1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp1(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum1 TestValue = ETbEnumEnum1::TEE1_VALUE1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp1(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbEnumEnumInterfaceSignals->OnProp1Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceOLinkHelper::Prop1PropertyCb);
		// use different test value
		TestValue = ETbEnumEnum1::TEE1_VALUE2;
		ImplFixture->GetImplementation()->Execute_SetProp1(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Property.Prop2.Default", [this]()
		{
		// Do implement test here
		ETbEnumEnum2 TestValue = ETbEnumEnum2::TEE2_VALUE2; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp2(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.Prop2.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum2 TestValue = ETbEnumEnum2::TEE2_VALUE2; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp2(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbEnumEnumInterfaceSignals->OnProp2Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceOLinkHelper::Prop2PropertyCb);
		// use different test value
		TestValue = ETbEnumEnum2::TEE2_VALUE1;
		ImplFixture->GetImplementation()->Execute_SetProp2(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Property.Prop3.Default", [this]()
		{
		// Do implement test here
		ETbEnumEnum3 TestValue = ETbEnumEnum3::TEE3_VALUE3; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp3(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.Prop3.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum3 TestValue = ETbEnumEnum3::TEE3_VALUE3; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetProp3(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbEnumEnumInterfaceSignals->OnProp3Changed.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceOLinkHelper::Prop3PropertyCb);
		// use different test value
		TestValue = ETbEnumEnum3::TEE3_VALUE2;
		ImplFixture->GetImplementation()->Execute_SetProp3(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Operation.Func0", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_Func0(ImplFixture->GetImplementation().GetObject(), ETbEnumEnum0::TEE0_VALUE0);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_Func1(ImplFixture->GetImplementation().GetObject(), ETbEnumEnum1::TEE1_VALUE1);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_Func2(ImplFixture->GetImplementation().GetObject(), ETbEnumEnum2::TEE2_VALUE2);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func3", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_Func3(ImplFixture->GetImplementation().GetObject(), ETbEnumEnum3::TEE3_VALUE3);
			TestDone.Execute();
		});
	});

	LatentIt("Signal.Sig0", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbEnumEnumInterfaceSignals->OnSig0Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceOLinkHelper::Sig0SignalCb);

		// use different test value
		ETbEnumEnum0 Param0TestValue = ETbEnumEnum0::TEE0_VALUE1;
		TbEnumEnumInterfaceSignals->BroadcastSig0Signal(Param0TestValue);
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbEnumEnumInterfaceSignals->OnSig1Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceOLinkHelper::Sig1SignalCb);

		// use different test value
		ETbEnumEnum1 Param1TestValue = ETbEnumEnum1::TEE1_VALUE2;
		TbEnumEnumInterfaceSignals->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbEnumEnumInterfaceSignals->OnSig2Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceOLinkHelper::Sig2SignalCb);

		// use different test value
		ETbEnumEnum2 Param2TestValue = ETbEnumEnum2::TEE2_VALUE1;
		TbEnumEnumInterfaceSignals->BroadcastSig2Signal(Param2TestValue);
	});

	LatentIt("Signal.Sig3", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbEnumEnumInterfaceSignals* TbEnumEnumInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbEnumEnumInterfaceSignals->OnSig3Signal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbEnumEnumInterfaceOLinkHelper::Sig3SignalCb);

		// use different test value
		ETbEnumEnum3 Param3TestValue = ETbEnumEnum3::TEE3_VALUE2;
		TbEnumEnumInterfaceSignals->BroadcastSig3Signal(Param3TestValue);
	});
}

void UTbEnumEnumInterfaceOLinkSpec::Prop0PropertyCb(ETbEnumEnum0 InProp0)
{
	ETbEnumEnum0 TestValue = ETbEnumEnum0::TEE0_VALUE0;
	// use different test value
	TestValue = ETbEnumEnum0::TEE0_VALUE1;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp0, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetProp0(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbEnumEnumInterfaceOLinkSpec::Prop1PropertyCb(ETbEnumEnum1 InProp1)
{
	ETbEnumEnum1 TestValue = ETbEnumEnum1::TEE1_VALUE1;
	// use different test value
	TestValue = ETbEnumEnum1::TEE1_VALUE2;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetProp1(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbEnumEnumInterfaceOLinkSpec::Prop2PropertyCb(ETbEnumEnum2 InProp2)
{
	ETbEnumEnum2 TestValue = ETbEnumEnum2::TEE2_VALUE2;
	// use different test value
	TestValue = ETbEnumEnum2::TEE2_VALUE1;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetProp2(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbEnumEnumInterfaceOLinkSpec::Prop3PropertyCb(ETbEnumEnum3 InProp3)
{
	ETbEnumEnum3 TestValue = ETbEnumEnum3::TEE3_VALUE3;
	// use different test value
	TestValue = ETbEnumEnum3::TEE3_VALUE2;
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetProp3(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UTbEnumEnumInterfaceOLinkSpec::Sig0SignalCb(ETbEnumEnum0 InParam0)
{
	// known test value
	ETbEnumEnum0 Param0TestValue = ETbEnumEnum0::TEE0_VALUE1;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam0, Param0TestValue);
	testDoneDelegate.Execute();
}

void UTbEnumEnumInterfaceOLinkSpec::Sig1SignalCb(ETbEnumEnum1 InParam1)
{
	// known test value
	ETbEnumEnum1 Param1TestValue = ETbEnumEnum1::TEE1_VALUE2;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
	testDoneDelegate.Execute();
}

void UTbEnumEnumInterfaceOLinkSpec::Sig2SignalCb(ETbEnumEnum2 InParam2)
{
	// known test value
	ETbEnumEnum2 Param2TestValue = ETbEnumEnum2::TEE2_VALUE1;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
	testDoneDelegate.Execute();
}

void UTbEnumEnumInterfaceOLinkSpec::Sig3SignalCb(ETbEnumEnum3 InParam3)
{
	// known test value
	ETbEnumEnum3 Param3TestValue = ETbEnumEnum3::TEE3_VALUE2;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam3, Param3TestValue);
	testDoneDelegate.Execute();
}
#endif // WITH_DEV_AUTOMATION_TESTS
