// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "TbSame2/Tests/TbSame2TestsCommon.h"
#include "TbSame2/Implementation/TbSame2SameEnum1Interface.h"
#include "TbSame2SameEnum1InterfaceMQTTFixture.h"
#include "TbSame2/Generated/MQTT/TbSame2SameEnum1InterfaceMQTTClient.h"
#include "TbSame2/Generated/MQTT/TbSame2SameEnum1InterfaceMQTTAdapter.h"
#include "ApiGearMQTTClient.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame2
{
namespace SameEnum1Interface
{
namespace MQTT
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbSame2SameEnum1InterfaceMQTTSpec, "TbSame2.SameEnum1Interface.MQTT", TbSame2TestFilterMask);

TUniquePtr<FTbSame2SameEnum1InterfaceMQTTFixture> ImplFixture;

END_DEFINE_SPEC(UTbSame2SameEnum1InterfaceMQTTSpec);

void UTbSame2SameEnum1InterfaceMQTTSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbSame2SameEnum1InterfaceMQTTFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// setup client
		UTbSame2SameEnum1InterfaceMQTTClient* MQTTClient = Cast<UTbSame2SameEnum1InterfaceMQTTClient>(ImplFixture->GetImplementation().GetObject());
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
		ETbSame2Enum1 TestValue = ETbSame2Enum1::TS2E1_Value1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbSame2Enum1 TestValue = ETbSame2Enum1::TS2E1_Value1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		UTbSame2SameEnum1InterfacePublisher* TbSame2SameEnum1InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSame2SameEnum1InterfacePublisher->OnProp1Changed.AddLambda([this, TestDone](ETbSame2Enum1 InProp1)
			{
			ETbSame2Enum1 TestValue = ETbSame2Enum1::TS2E1_Value1;
			// use different test value
			TestValue = ETbSame2Enum1::TS2E1_Value2;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = ETbSame2Enum1::TS2E1_Value2;
		ImplFixture->GetImplementation()->SetProp1(TestValue);
	});

	LatentIt("Operation.Func1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func1(ETbSame2Enum1::TS2E1_Value1);
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSame2SameEnum1InterfacePublisher* TbSame2SameEnum1InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSame2SameEnum1InterfacePublisher->OnSig1Signal.AddLambda([this, TestDone](ETbSame2Enum1 InParam1)
			{
			// known test value
			ETbSame2Enum1 Param1TestValue = ETbSame2Enum1::TS2E1_Value2;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			TestDone.Execute();
		});

		// use different test value
		ETbSame2Enum1 Param1TestValue = ETbSame2Enum1::TS2E1_Value2;
		TbSame2SameEnum1InterfacePublisher->BroadcastSig1Signal(Param1TestValue);
	});
}
} // namespace Tests
} // namespace MQTT
} // namespace SameEnum1Interface
} // namespace TbSame2

#endif // WITH_DEV_AUTOMATION_TESTS
