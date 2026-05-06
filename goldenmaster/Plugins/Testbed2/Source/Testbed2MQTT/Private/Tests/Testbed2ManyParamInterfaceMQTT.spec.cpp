// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "Testbed2/Tests/Testbed2TestsCommon.h"
#include "Testbed2/Implementation/Testbed2ManyParamInterface.h"
#include "Testbed2ManyParamInterfaceMQTTFixture.h"
#include "Testbed2/Generated/MQTT/Testbed2ManyParamInterfaceMQTTClient.h"
#include "Testbed2/Generated/MQTT/Testbed2ManyParamInterfaceMQTTAdapter.h"
#include "ApiGearMQTTClient.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed2
{
namespace ManyParamInterface
{
namespace MQTT
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTestbed2ManyParamInterfaceMQTTSpec, "Testbed2.ManyParamInterface.MQTT", Testbed2TestFilterMask);

TUniquePtr<FTestbed2ManyParamInterfaceMQTTFixture> ImplFixture;

END_DEFINE_SPEC(UTestbed2ManyParamInterfaceMQTTSpec);

void UTestbed2ManyParamInterfaceMQTTSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTestbed2ManyParamInterfaceMQTTFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// setup client
		UTestbed2ManyParamInterfaceMQTTClient* MQTTClient = Cast<UTestbed2ManyParamInterfaceMQTTClient>(ImplFixture->GetImplementation().GetObject());
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
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnProp1Changed.AddLambda([this, TestDone](int32 InProp1)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->SetProp1(TestValue);
	});

	It("Property.Prop2.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
	});

	LatentIt("Property.Prop2.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);

		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnProp2Changed.AddLambda([this, TestDone](int32 InProp2)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->SetProp2(TestValue);
	});

	It("Property.Prop3.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp3(), TestValue);
	});

	LatentIt("Property.Prop3.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp3(), TestValue);

		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnProp3Changed.AddLambda([this, TestDone](int32 InProp3)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp3(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->SetProp3(TestValue);
	});

	It("Property.Prop4.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp4(), TestValue);
	});

	LatentIt("Property.Prop4.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp4(), TestValue);

		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnProp4Changed.AddLambda([this, TestDone](int32 InProp4)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp4, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp4(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->SetProp4(TestValue);
	});

	LatentIt("Operation.Func1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func1(0);
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func2(0, 0);
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func3", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func3(0, 0, 0);
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func4", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func4(0, 0, 0, 0);
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnSig1Signal.AddLambda([this, TestDone](int32 InParam1)
			{
			// known test value
			int32 Param1TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			TestDone.Execute();
		});

		// use different test value
		int32 Param1TestValue = 1;
		Testbed2ManyParamInterfacePublisher->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnSig2Signal.AddLambda([this, TestDone](int32 InParam1, int32 InParam2)
			{
			// known test value
			int32 Param1TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			int32 Param2TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
			TestDone.Execute();
		});

		// use different test value
		int32 Param1TestValue = 1;
		int32 Param2TestValue = 1;
		Testbed2ManyParamInterfacePublisher->BroadcastSig2Signal(Param1TestValue, Param2TestValue);
	});

	LatentIt("Signal.Sig3", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnSig3Signal.AddLambda([this, TestDone](int32 InParam1, int32 InParam2, int32 InParam3)
			{
			// known test value
			int32 Param1TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			int32 Param2TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
			int32 Param3TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam3, Param3TestValue);
			TestDone.Execute();
		});

		// use different test value
		int32 Param1TestValue = 1;
		int32 Param2TestValue = 1;
		int32 Param3TestValue = 1;
		Testbed2ManyParamInterfacePublisher->BroadcastSig3Signal(Param1TestValue, Param2TestValue, Param3TestValue);
	});

	LatentIt("Signal.Sig4", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnSig4Signal.AddLambda([this, TestDone](int32 InParam1, int32 InParam2, int32 InParam3, int32 InParam4)
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
			TestDone.Execute();
		});

		// use different test value
		int32 Param1TestValue = 1;
		int32 Param2TestValue = 1;
		int32 Param3TestValue = 1;
		int32 Param4TestValue = 1;
		Testbed2ManyParamInterfacePublisher->BroadcastSig4Signal(Param1TestValue, Param2TestValue, Param3TestValue, Param4TestValue);
	});
}
} // namespace Tests
} // namespace MQTT
} // namespace ManyParamInterface
} // namespace Testbed2

#endif // WITH_DEV_AUTOMATION_TESTS
