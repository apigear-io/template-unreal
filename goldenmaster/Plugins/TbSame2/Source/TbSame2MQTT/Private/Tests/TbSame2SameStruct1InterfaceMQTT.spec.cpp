// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "TbSame2/Tests/TbSame2TestsCommon.h"
#include "TbSame2/Implementation/TbSame2SameStruct1Interface.h"
#include "TbSame2SameStruct1InterfaceMQTTFixture.h"
#include "TbSame2/Generated/MQTT/TbSame2SameStruct1InterfaceMQTTClient.h"
#include "TbSame2/Generated/MQTT/TbSame2SameStruct1InterfaceMQTTAdapter.h"
#include "ApiGearMQTTClient.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame2
{
namespace SameStruct1Interface
{
namespace MQTT
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbSame2SameStruct1InterfaceMQTTSpec, "TbSame2.SameStruct1Interface.MQTT", TbSame2TestFilterMask);

TUniquePtr<FTbSame2SameStruct1InterfaceMQTTFixture> ImplFixture;

END_DEFINE_SPEC(UTbSame2SameStruct1InterfaceMQTTSpec);

void UTbSame2SameStruct1InterfaceMQTTSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbSame2SameStruct1InterfaceMQTTFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// setup client
		UTbSame2SameStruct1InterfaceMQTTClient* MQTTClient = Cast<UTbSame2SameStruct1InterfaceMQTTClient>(ImplFixture->GetImplementation().GetObject());
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
		FTbSame2Struct1 TestValue = FTbSame2Struct1(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbSame2Struct1 TestValue = FTbSame2Struct1(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		UTbSame2SameStruct1InterfacePublisher* TbSame2SameStruct1InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSame2SameStruct1InterfacePublisher->OnProp1Changed.AddLambda([this, TestDone](const FTbSame2Struct1& InProp1)
			{
			FTbSame2Struct1 TestValue = FTbSame2Struct1();
			// use different test value
			TestValue = createTestFTbSame2Struct1();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTbSame2Struct1();
		ImplFixture->GetImplementation()->SetProp1(TestValue);
	});

	LatentIt("Operation.Func1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func1(FTbSame2Struct1());
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSame2SameStruct1InterfacePublisher* TbSame2SameStruct1InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSame2SameStruct1InterfacePublisher->OnSig1Signal.AddLambda([this, TestDone](const FTbSame2Struct1& InParam1)
			{
			// known test value
			FTbSame2Struct1 Param1TestValue = createTestFTbSame2Struct1();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			TestDone.Execute();
		});

		// use different test value
		FTbSame2Struct1 Param1TestValue = createTestFTbSame2Struct1();
		TbSame2SameStruct1InterfacePublisher->BroadcastSig1Signal(Param1TestValue);
	});
}
} // namespace Tests
} // namespace MQTT
} // namespace SameStruct1Interface
} // namespace TbSame2

#endif // WITH_DEV_AUTOMATION_TESTS
