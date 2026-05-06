// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "TbSame1/Tests/TbSame1TestsCommon.h"
#include "TbSame1/Implementation/TbSame1SameEnum1Interface.h"
#include "TbSame1SameEnum1InterfaceMQTTFixture.h"
#include "TbSame1/Generated/MQTT/TbSame1SameEnum1InterfaceMQTTClient.h"
#include "TbSame1/Generated/MQTT/TbSame1SameEnum1InterfaceMQTTAdapter.h"
#include "ApiGearMQTTClient.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame1
{
namespace SameEnum1Interface
{
namespace MQTT
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbSame1SameEnum1InterfaceMQTTSpec, "TbSame1.SameEnum1Interface.MQTT", TbSame1TestFilterMask);

TUniquePtr<FTbSame1SameEnum1InterfaceMQTTFixture> ImplFixture;

END_DEFINE_SPEC(UTbSame1SameEnum1InterfaceMQTTSpec);

void UTbSame1SameEnum1InterfaceMQTTSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbSame1SameEnum1InterfaceMQTTFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// setup client
		UTbSame1SameEnum1InterfaceMQTTClient* MQTTClient = Cast<UTbSame1SameEnum1InterfaceMQTTClient>(ImplFixture->GetImplementation().GetObject());
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
		ETbSame1Enum1 TestValue = ETbSame1Enum1::TS1E1_Value1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbSame1Enum1 TestValue = ETbSame1Enum1::TS1E1_Value1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		UTbSame1SameEnum1InterfacePublisher* TbSame1SameEnum1InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSame1SameEnum1InterfacePublisher->OnProp1Changed.AddLambda([this, TestDone](ETbSame1Enum1 InProp1)
			{
			ETbSame1Enum1 TestValue = ETbSame1Enum1::TS1E1_Value1;
			// use different test value
			TestValue = ETbSame1Enum1::TS1E1_Value2;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = ETbSame1Enum1::TS1E1_Value2;
		ImplFixture->GetImplementation()->SetProp1(TestValue);
	});

	LatentIt("Operation.Func1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func1(ETbSame1Enum1::TS1E1_Value1);
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSame1SameEnum1InterfacePublisher* TbSame1SameEnum1InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSame1SameEnum1InterfacePublisher->OnSig1Signal.AddLambda([this, TestDone](ETbSame1Enum1 InParam1)
			{
			// known test value
			ETbSame1Enum1 Param1TestValue = ETbSame1Enum1::TS1E1_Value2;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			TestDone.Execute();
		});

		// use different test value
		ETbSame1Enum1 Param1TestValue = ETbSame1Enum1::TS1E1_Value2;
		TbSame1SameEnum1InterfacePublisher->BroadcastSig1Signal(Param1TestValue);
	});
}
} // namespace Tests
} // namespace MQTT
} // namespace SameEnum1Interface
} // namespace TbSame1

#endif // WITH_DEV_AUTOMATION_TESTS
