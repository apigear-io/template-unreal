// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "Testbed2/Tests/Testbed2TestsCommon.h"
#include "Testbed2/Implementation/Testbed2NestedStruct3Interface.h"
#include "Testbed2NestedStruct3InterfaceMQTTFixture.h"
#include "Testbed2/Generated/MQTT/Testbed2NestedStruct3InterfaceMQTTClient.h"
#include "Testbed2/Generated/MQTT/Testbed2NestedStruct3InterfaceMQTTAdapter.h"
#include "ApiGearMQTTClient.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed2
{
namespace NestedStruct3Interface
{
namespace MQTT
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTestbed2NestedStruct3InterfaceMQTTSpec, "Testbed2.NestedStruct3Interface.MQTT", Testbed2TestFilterMask);

TUniquePtr<FTestbed2NestedStruct3InterfaceMQTTFixture> ImplFixture;

END_DEFINE_SPEC(UTestbed2NestedStruct3InterfaceMQTTSpec);

void UTestbed2NestedStruct3InterfaceMQTTSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTestbed2NestedStruct3InterfaceMQTTFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// setup client
		UTestbed2NestedStruct3InterfaceMQTTClient* MQTTClient = Cast<UTestbed2NestedStruct3InterfaceMQTTClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid MQTT client", MQTTClient != nullptr);

		MQTTClient->_SubscriptionStatusChanged.AddLambda([this, TestDone](bool bSubscribed)
			{
			if (bSubscribed)
			{
				TestDone.Execute();
			}
		});

		MQTTClient->UseConnection(ImplFixture->Connection);
		ImplFixture->Connection->Connect();
	});

	AfterEach([this]()
		{
		if (ImplFixture->Connection && IsValid(ImplFixture->Connection.GetObject()))
		{
			ImplFixture->Connection->Disconnect();
			ImplFixture->Connection.GetObject()->RemoveFromRoot();
		}
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

		UTestbed2NestedStruct3InterfacePublisher* Testbed2NestedStruct3InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2NestedStruct3InterfacePublisher->OnProp1Changed.AddLambda([this, TestDone](const FTestbed2NestedStruct1& InProp1)
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

		UTestbed2NestedStruct3InterfacePublisher* Testbed2NestedStruct3InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2NestedStruct3InterfacePublisher->OnProp2Changed.AddLambda([this, TestDone](const FTestbed2NestedStruct2& InProp2)
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

	It("Property.Prop3.Default", [this]()
		{
		// Do implement test here
		FTestbed2NestedStruct3 TestValue = FTestbed2NestedStruct3(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp3(), TestValue);
	});

	LatentIt("Property.Prop3.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed2NestedStruct3 TestValue = FTestbed2NestedStruct3(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp3(), TestValue);

		UTestbed2NestedStruct3InterfacePublisher* Testbed2NestedStruct3InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2NestedStruct3InterfacePublisher->OnProp3Changed.AddLambda([this, TestDone](const FTestbed2NestedStruct3& InProp3)
			{
			FTestbed2NestedStruct3 TestValue = FTestbed2NestedStruct3();
			// use different test value
			TestValue = createTestFTestbed2NestedStruct3();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp3(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed2NestedStruct3();
		ImplFixture->GetImplementation()->SetProp3(TestValue);
	});

	LatentIt("Operation.Func1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func1(FTestbed2NestedStruct1());
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func2(FTestbed2NestedStruct1(), FTestbed2NestedStruct2());
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func3", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func3(FTestbed2NestedStruct1(), FTestbed2NestedStruct2(), FTestbed2NestedStruct3());
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed2NestedStruct3InterfacePublisher* Testbed2NestedStruct3InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2NestedStruct3InterfacePublisher->OnSig1Signal.AddLambda([this, TestDone](const FTestbed2NestedStruct1& InParam1)
			{
			// known test value
			FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			TestDone.Execute();
		});

		// use different test value
		FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
		Testbed2NestedStruct3InterfacePublisher->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed2NestedStruct3InterfacePublisher* Testbed2NestedStruct3InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2NestedStruct3InterfacePublisher->OnSig2Signal.AddLambda([this, TestDone](const FTestbed2NestedStruct1& InParam1, const FTestbed2NestedStruct2& InParam2)
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
		Testbed2NestedStruct3InterfacePublisher->BroadcastSig2Signal(Param1TestValue, Param2TestValue);
	});

	LatentIt("Signal.Sig3", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed2NestedStruct3InterfacePublisher* Testbed2NestedStruct3InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2NestedStruct3InterfacePublisher->OnSig3Signal.AddLambda([this, TestDone](const FTestbed2NestedStruct1& InParam1, const FTestbed2NestedStruct2& InParam2, const FTestbed2NestedStruct3& InParam3)
			{
			// known test value
			FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			FTestbed2NestedStruct2 Param2TestValue = createTestFTestbed2NestedStruct2();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
			FTestbed2NestedStruct3 Param3TestValue = createTestFTestbed2NestedStruct3();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam3, Param3TestValue);
			TestDone.Execute();
		});

		// use different test value
		FTestbed2NestedStruct1 Param1TestValue = createTestFTestbed2NestedStruct1();
		FTestbed2NestedStruct2 Param2TestValue = createTestFTestbed2NestedStruct2();
		FTestbed2NestedStruct3 Param3TestValue = createTestFTestbed2NestedStruct3();
		Testbed2NestedStruct3InterfacePublisher->BroadcastSig3Signal(Param1TestValue, Param2TestValue, Param3TestValue);
	});
}
} // namespace Tests
} // namespace MQTT
} // namespace NestedStruct3Interface
} // namespace Testbed2

#endif // WITH_DEV_AUTOMATION_TESTS
