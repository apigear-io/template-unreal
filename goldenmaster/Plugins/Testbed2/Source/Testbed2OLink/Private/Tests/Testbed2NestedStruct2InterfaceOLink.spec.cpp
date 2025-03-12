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
#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Testbed2NestedStruct2InterfaceOLinkFixture.h"
#include "Testbed2/Implementation/Testbed2NestedStruct2Interface.h"
#include "Testbed2/Generated/OLink/Testbed2NestedStruct2InterfaceOLinkClient.h"
#include "Testbed2/Generated/OLink/Testbed2NestedStruct2InterfaceOLinkAdapter.h"

#include "OLinkHost.h"
#include "OLinkClientConnection.h" // for olink factory
#include "Testbed2/Tests/Testbed2TestsCommon.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed2
{
namespace NestedStruct2Interface
{
namespace OLink
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTestbed2NestedStruct2InterfaceOLinkSpec, "Testbed2.NestedStruct2Interface.OLink", Testbed2TestFilterMask);

TUniquePtr<FTestbed2NestedStruct2InterfaceOLinkFixture> ImplFixture;

END_DEFINE_SPEC(UTestbed2NestedStruct2InterfaceOLinkSpec);

void UTestbed2NestedStruct2InterfaceOLinkSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTestbed2NestedStruct2InterfaceOLinkFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// set up service and adapter
		ImplFixture->GetHost()->Stop();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed2NestedStruct2Interface>();
		ImplFixture->GetAdapter()->setBackendService(service);
		ImplFixture->GetAdapter()->setOLinkHost(ImplFixture->GetHost());
		ImplFixture->GetHost()->Start(8666);

		// setup client
		UTestbed2NestedStruct2InterfaceOLinkClient* OLinkClient = Cast<UTestbed2NestedStruct2InterfaceOLinkClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid OLink client", OLinkClient != nullptr);

		OLinkClient->_SubscriptionStatusChanged.AddLambda([this, TestDone](bool bSubscribed)
			{
			if (bSubscribed)
			{
				TestDone.Execute();
			}
		});

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
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed2NestedStruct1 TestValue = FTestbed2NestedStruct1(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		UTestbed2NestedStruct2InterfaceSignals* Testbed2NestedStruct2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed2NestedStruct2InterfaceSignals->OnProp1Changed.AddLambda([this, TestDone](const FTestbed2NestedStruct1& InProp1)
			{
			FTestbed2NestedStruct1 TestValue = FTestbed2NestedStruct1();
			// use different test value
			TestValue = createTestFTestbed2NestedStruct1();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed2NestedStruct1();
		ImplFixture->GetImplementation()->SetProp1(TestValue);
	});

	It("Property.Prop2.Default", [this]()
		{
		// Do implement test here
		FTestbed2NestedStruct2 TestValue = FTestbed2NestedStruct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
	});

	LatentIt("Property.Prop2.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed2NestedStruct2 TestValue = FTestbed2NestedStruct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);

		UTestbed2NestedStruct2InterfaceSignals* Testbed2NestedStruct2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed2NestedStruct2InterfaceSignals->OnProp2Changed.AddLambda([this, TestDone](const FTestbed2NestedStruct2& InProp2)
			{
			FTestbed2NestedStruct2 TestValue = FTestbed2NestedStruct2();
			// use different test value
			TestValue = createTestFTestbed2NestedStruct2();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed2NestedStruct2();
		ImplFixture->GetImplementation()->SetProp2(TestValue);
	});

	LatentIt("Operation.Func1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func1(FTestbed2NestedStruct1());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func2(FTestbed2NestedStruct1(), FTestbed2NestedStruct2());
			TestDone.Execute();
		});
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed2NestedStruct2InterfaceSignals* Testbed2NestedStruct2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed2NestedStruct2InterfaceSignals->OnSig1Signal.AddLambda([this, TestDone](const FTestbed2NestedStruct1& InParam1)
			{
			// known test value
			FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			TestDone.Execute();
		});

		// use different test value
		FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
		Testbed2NestedStruct2InterfaceSignals->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed2NestedStruct2InterfaceSignals* Testbed2NestedStruct2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed2NestedStruct2InterfaceSignals->OnSig2Signal.AddLambda([this, TestDone](const FTestbed2NestedStruct1& InParam1, const FTestbed2NestedStruct2& InParam2)
			{
			// known test value
			FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			FTestbed2NestedStruct2 Param2TestValue = createTestFTestbed2NestedStruct2();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
			TestDone.Execute();
		});

		// use different test value
		FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
		FTestbed2NestedStruct2 Param2TestValue = createTestFTestbed2NestedStruct2();
		Testbed2NestedStruct2InterfaceSignals->BroadcastSig2Signal(Param1TestValue, Param2TestValue);
	});
}
} // namespace Tests
} // namespace OLink
} // namespace NestedStruct2Interface
} // namespace Testbed2

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
