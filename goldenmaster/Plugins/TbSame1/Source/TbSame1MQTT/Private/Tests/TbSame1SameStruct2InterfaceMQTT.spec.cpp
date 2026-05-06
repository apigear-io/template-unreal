// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "TbSame1/Tests/TbSame1TestsCommon.h"
#include "TbSame1/Implementation/TbSame1SameStruct2Interface.h"
#include "TbSame1SameStruct2InterfaceMQTTFixture.h"
#include "TbSame1/Generated/MQTT/TbSame1SameStruct2InterfaceMQTTClient.h"
#include "TbSame1/Generated/MQTT/TbSame1SameStruct2InterfaceMQTTAdapter.h"
#include "ApiGearMQTTClient.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame1
{
namespace SameStruct2Interface
{
namespace MQTT
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbSame1SameStruct2InterfaceMQTTSpec, "TbSame1.SameStruct2Interface.MQTT", TbSame1TestFilterMask);

TUniquePtr<FTbSame1SameStruct2InterfaceMQTTFixture> ImplFixture;

END_DEFINE_SPEC(UTbSame1SameStruct2InterfaceMQTTSpec);

void UTbSame1SameStruct2InterfaceMQTTSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbSame1SameStruct2InterfaceMQTTFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// setup client
		UTbSame1SameStruct2InterfaceMQTTClient* MQTTClient = Cast<UTbSame1SameStruct2InterfaceMQTTClient>(ImplFixture->GetImplementation().GetObject());
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
		FTbSame1Struct2 TestValue = FTbSame1Struct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbSame1Struct2 TestValue = FTbSame1Struct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		UTbSame1SameStruct2InterfacePublisher* TbSame1SameStruct2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSame1SameStruct2InterfacePublisher->OnProp1Changed.AddLambda([this, TestDone](const FTbSame1Struct2& InProp1)
			{
			FTbSame1Struct2 TestValue = FTbSame1Struct2();
			// use different test value
			TestValue = createTestFTbSame1Struct2();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTbSame1Struct2();
		ImplFixture->GetImplementation()->SetProp1(TestValue);
	});

	It("Property.Prop2.Default", [this]()
		{
		// Do implement test here
		FTbSame1Struct2 TestValue = FTbSame1Struct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
	});

	LatentIt("Property.Prop2.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbSame1Struct2 TestValue = FTbSame1Struct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);

		UTbSame1SameStruct2InterfacePublisher* TbSame1SameStruct2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSame1SameStruct2InterfacePublisher->OnProp2Changed.AddLambda([this, TestDone](const FTbSame1Struct2& InProp2)
			{
			FTbSame1Struct2 TestValue = FTbSame1Struct2();
			// use different test value
			TestValue = createTestFTbSame1Struct2();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTbSame1Struct2();
		ImplFixture->GetImplementation()->SetProp2(TestValue);
	});

	LatentIt("Operation.Func1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func1(FTbSame1Struct1());
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func2(FTbSame1Struct1(), FTbSame1Struct2());
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSame1SameStruct2InterfacePublisher* TbSame1SameStruct2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSame1SameStruct2InterfacePublisher->OnSig1Signal.AddLambda([this, TestDone](const FTbSame1Struct1& InParam1)
			{
			// known test value
			FTbSame1Struct1 Param1TestValue = createTestFTbSame1Struct1();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			TestDone.Execute();
		});

		// use different test value
		FTbSame1Struct1 Param1TestValue = createTestFTbSame1Struct1();
		TbSame1SameStruct2InterfacePublisher->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSame1SameStruct2InterfacePublisher* TbSame1SameStruct2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSame1SameStruct2InterfacePublisher->OnSig2Signal.AddLambda([this, TestDone](const FTbSame1Struct1& InParam1, const FTbSame1Struct2& InParam2)
			{
			// known test value
			FTbSame1Struct1 Param1TestValue = createTestFTbSame1Struct1();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			FTbSame1Struct2 Param2TestValue = createTestFTbSame1Struct2();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
			TestDone.Execute();
		});

		// use different test value
		FTbSame1Struct1 Param1TestValue = createTestFTbSame1Struct1();
		FTbSame1Struct2 Param2TestValue = createTestFTbSame1Struct2();
		TbSame1SameStruct2InterfacePublisher->BroadcastSig2Signal(Param1TestValue, Param2TestValue);
	});
}
} // namespace Tests
} // namespace MQTT
} // namespace SameStruct2Interface
} // namespace TbSame1

#endif // WITH_DEV_AUTOMATION_TESTS
