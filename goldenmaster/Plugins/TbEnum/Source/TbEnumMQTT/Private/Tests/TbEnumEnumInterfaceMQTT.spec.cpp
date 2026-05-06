// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "TbEnum/Tests/TbEnumTestsCommon.h"
#include "TbEnum/Implementation/TbEnumEnumInterface.h"
#include "TbEnumEnumInterfaceMQTTFixture.h"
#include "TbEnum/Generated/MQTT/TbEnumEnumInterfaceMQTTClient.h"
#include "TbEnum/Generated/MQTT/TbEnumEnumInterfaceMQTTAdapter.h"
#include "ApiGearMQTTClient.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbEnum
{
namespace EnumInterface
{
namespace MQTT
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbEnumEnumInterfaceMQTTSpec, "TbEnum.EnumInterface.MQTT", TbEnumTestFilterMask);

TUniquePtr<FTbEnumEnumInterfaceMQTTFixture> ImplFixture;

END_DEFINE_SPEC(UTbEnumEnumInterfaceMQTTSpec);

void UTbEnumEnumInterfaceMQTTSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbEnumEnumInterfaceMQTTFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// setup client
		UTbEnumEnumInterfaceMQTTClient* MQTTClient = Cast<UTbEnumEnumInterfaceMQTTClient>(ImplFixture->GetImplementation().GetObject());
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

	It("Property.Prop0.Default", [this]()
		{
		// Do implement test here
		ETbEnumEnum0 TestValue = ETbEnumEnum0::TEE0_Value0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp0(), TestValue);
	});

	LatentIt("Property.Prop0.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum0 TestValue = ETbEnumEnum0::TEE0_Value0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp0(), TestValue);

		UTbEnumEnumInterfacePublisher* TbEnumEnumInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbEnumEnumInterfacePublisher->OnProp0Changed.AddLambda([this, TestDone](ETbEnumEnum0 InProp0)
			{
			ETbEnumEnum0 TestValue = ETbEnumEnum0::TEE0_Value0;
			// use different test value
			TestValue = ETbEnumEnum0::TEE0_Value1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp0, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp0(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = ETbEnumEnum0::TEE0_Value1;
		ImplFixture->GetImplementation()->SetProp0(TestValue);
	});

	It("Property.Prop1.Default", [this]()
		{
		// Do implement test here
		ETbEnumEnum1 TestValue = ETbEnumEnum1::TEE1_Value1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum1 TestValue = ETbEnumEnum1::TEE1_Value1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		UTbEnumEnumInterfacePublisher* TbEnumEnumInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbEnumEnumInterfacePublisher->OnProp1Changed.AddLambda([this, TestDone](ETbEnumEnum1 InProp1)
			{
			ETbEnumEnum1 TestValue = ETbEnumEnum1::TEE1_Value1;
			// use different test value
			TestValue = ETbEnumEnum1::TEE1_Value2;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = ETbEnumEnum1::TEE1_Value2;
		ImplFixture->GetImplementation()->SetProp1(TestValue);
	});

	It("Property.Prop2.Default", [this]()
		{
		// Do implement test here
		ETbEnumEnum2 TestValue = ETbEnumEnum2::TEE2_Value2; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
	});

	LatentIt("Property.Prop2.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum2 TestValue = ETbEnumEnum2::TEE2_Value2; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);

		UTbEnumEnumInterfacePublisher* TbEnumEnumInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbEnumEnumInterfacePublisher->OnProp2Changed.AddLambda([this, TestDone](ETbEnumEnum2 InProp2)
			{
			ETbEnumEnum2 TestValue = ETbEnumEnum2::TEE2_Value2;
			// use different test value
			TestValue = ETbEnumEnum2::TEE2_Value1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = ETbEnumEnum2::TEE2_Value1;
		ImplFixture->GetImplementation()->SetProp2(TestValue);
	});

	It("Property.Prop3.Default", [this]()
		{
		// Do implement test here
		ETbEnumEnum3 TestValue = ETbEnumEnum3::TEE3_Value3; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp3(), TestValue);
	});

	LatentIt("Property.Prop3.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbEnumEnum3 TestValue = ETbEnumEnum3::TEE3_Value3; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp3(), TestValue);

		UTbEnumEnumInterfacePublisher* TbEnumEnumInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbEnumEnumInterfacePublisher->OnProp3Changed.AddLambda([this, TestDone](ETbEnumEnum3 InProp3)
			{
			ETbEnumEnum3 TestValue = ETbEnumEnum3::TEE3_Value3;
			// use different test value
			TestValue = ETbEnumEnum3::TEE3_Value2;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp3(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = ETbEnumEnum3::TEE3_Value2;
		ImplFixture->GetImplementation()->SetProp3(TestValue);
	});

	LatentIt("Operation.Func0", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func0(ETbEnumEnum0::TEE0_Value0);
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func1(ETbEnumEnum1::TEE1_Value1);
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func2(ETbEnumEnum2::TEE2_Value2);
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func3", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func3(ETbEnumEnum3::TEE3_Value3);
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Signal.Sig0", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbEnumEnumInterfacePublisher* TbEnumEnumInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbEnumEnumInterfacePublisher->OnSig0Signal.AddLambda([this, TestDone](ETbEnumEnum0 InParam0)
			{
			// known test value
			ETbEnumEnum0 Param0TestValue = ETbEnumEnum0::TEE0_Value1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam0, Param0TestValue);
			TestDone.Execute();
		});

		// use different test value
		ETbEnumEnum0 Param0TestValue = ETbEnumEnum0::TEE0_Value1;
		TbEnumEnumInterfacePublisher->BroadcastSig0Signal(Param0TestValue);
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbEnumEnumInterfacePublisher* TbEnumEnumInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbEnumEnumInterfacePublisher->OnSig1Signal.AddLambda([this, TestDone](ETbEnumEnum1 InParam1)
			{
			// known test value
			ETbEnumEnum1 Param1TestValue = ETbEnumEnum1::TEE1_Value2;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			TestDone.Execute();
		});

		// use different test value
		ETbEnumEnum1 Param1TestValue = ETbEnumEnum1::TEE1_Value2;
		TbEnumEnumInterfacePublisher->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbEnumEnumInterfacePublisher* TbEnumEnumInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbEnumEnumInterfacePublisher->OnSig2Signal.AddLambda([this, TestDone](ETbEnumEnum2 InParam2)
			{
			// known test value
			ETbEnumEnum2 Param2TestValue = ETbEnumEnum2::TEE2_Value1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
			TestDone.Execute();
		});

		// use different test value
		ETbEnumEnum2 Param2TestValue = ETbEnumEnum2::TEE2_Value1;
		TbEnumEnumInterfacePublisher->BroadcastSig2Signal(Param2TestValue);
	});

	LatentIt("Signal.Sig3", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbEnumEnumInterfacePublisher* TbEnumEnumInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbEnumEnumInterfacePublisher->OnSig3Signal.AddLambda([this, TestDone](ETbEnumEnum3 InParam3)
			{
			// known test value
			ETbEnumEnum3 Param3TestValue = ETbEnumEnum3::TEE3_Value2;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam3, Param3TestValue);
			TestDone.Execute();
		});

		// use different test value
		ETbEnumEnum3 Param3TestValue = ETbEnumEnum3::TEE3_Value2;
		TbEnumEnumInterfacePublisher->BroadcastSig3Signal(Param3TestValue);
	});
}
} // namespace Tests
} // namespace MQTT
} // namespace EnumInterface
} // namespace TbEnum

#endif // WITH_DEV_AUTOMATION_TESTS
