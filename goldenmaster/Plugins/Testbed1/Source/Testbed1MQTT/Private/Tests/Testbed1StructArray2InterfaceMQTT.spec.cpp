// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "Testbed1/Tests/Testbed1TestsCommon.h"
#include "Testbed1/Implementation/Testbed1StructArray2Interface.h"
#include "Testbed1StructArray2InterfaceMQTTFixture.h"
#include "Testbed1/Generated/MQTT/Testbed1StructArray2InterfaceMQTTClient.h"
#include "Testbed1/Generated/MQTT/Testbed1StructArray2InterfaceMQTTAdapter.h"
#include "ApiGearMQTTClient.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed1
{
namespace StructArray2Interface
{
namespace MQTT
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTestbed1StructArray2InterfaceMQTTSpec, "Testbed1.StructArray2Interface.MQTT", Testbed1TestFilterMask);

TUniquePtr<FTestbed1StructArray2InterfaceMQTTFixture> ImplFixture;

END_DEFINE_SPEC(UTestbed1StructArray2InterfaceMQTTSpec);

void UTestbed1StructArray2InterfaceMQTTSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTestbed1StructArray2InterfaceMQTTFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// setup client
		UTestbed1StructArray2InterfaceMQTTClient* MQTTClient = Cast<UTestbed1StructArray2InterfaceMQTTClient>(ImplFixture->GetImplementation().GetObject());
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

	It("Property.PropBool.Default", [this]()
		{
		// Do implement test here
		FTestbed1StructBoolWithArray TestValue = FTestbed1StructBoolWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);
	});

	LatentIt("Property.PropBool.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructBoolWithArray TestValue = FTestbed1StructBoolWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);

		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnPropBoolChanged.AddLambda([this, TestDone](const FTestbed1StructBoolWithArray& InPropBool)
			{
			FTestbed1StructBoolWithArray TestValue = FTestbed1StructBoolWithArray();
			// use different test value
			TestValue = createTestFTestbed1StructBoolWithArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructBoolWithArray();
		ImplFixture->GetImplementation()->SetPropBool(TestValue);
	});

	It("Property.PropInt.Default", [this]()
		{
		// Do implement test here
		FTestbed1StructIntWithArray TestValue = FTestbed1StructIntWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);
	});

	LatentIt("Property.PropInt.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructIntWithArray TestValue = FTestbed1StructIntWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);

		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnPropIntChanged.AddLambda([this, TestDone](const FTestbed1StructIntWithArray& InPropInt)
			{
			FTestbed1StructIntWithArray TestValue = FTestbed1StructIntWithArray();
			// use different test value
			TestValue = createTestFTestbed1StructIntWithArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructIntWithArray();
		ImplFixture->GetImplementation()->SetPropInt(TestValue);
	});

	It("Property.PropFloat.Default", [this]()
		{
		// Do implement test here
		FTestbed1StructFloatWithArray TestValue = FTestbed1StructFloatWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);
	});

	LatentIt("Property.PropFloat.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructFloatWithArray TestValue = FTestbed1StructFloatWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);

		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnPropFloatChanged.AddLambda([this, TestDone](const FTestbed1StructFloatWithArray& InPropFloat)
			{
			FTestbed1StructFloatWithArray TestValue = FTestbed1StructFloatWithArray();
			// use different test value
			TestValue = createTestFTestbed1StructFloatWithArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructFloatWithArray();
		ImplFixture->GetImplementation()->SetPropFloat(TestValue);
	});

	It("Property.PropString.Default", [this]()
		{
		// Do implement test here
		FTestbed1StructStringWithArray TestValue = FTestbed1StructStringWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropString(), TestValue);
	});

	LatentIt("Property.PropString.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructStringWithArray TestValue = FTestbed1StructStringWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropString(), TestValue);

		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnPropStringChanged.AddLambda([this, TestDone](const FTestbed1StructStringWithArray& InPropString)
			{
			FTestbed1StructStringWithArray TestValue = FTestbed1StructStringWithArray();
			// use different test value
			TestValue = createTestFTestbed1StructStringWithArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropString(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructStringWithArray();
		ImplFixture->GetImplementation()->SetPropString(TestValue);
	});

	It("Property.PropEnum.Default", [this]()
		{
		// Do implement test here
		FTestbed1StructEnumWithArray TestValue = FTestbed1StructEnumWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropEnum(), TestValue);
	});

	LatentIt("Property.PropEnum.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructEnumWithArray TestValue = FTestbed1StructEnumWithArray(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropEnum(), TestValue);

		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnPropEnumChanged.AddLambda([this, TestDone](const FTestbed1StructEnumWithArray& InPropEnum)
			{
			FTestbed1StructEnumWithArray TestValue = FTestbed1StructEnumWithArray();
			// use different test value
			TestValue = createTestFTestbed1StructEnumWithArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnum, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropEnum(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructEnumWithArray();
		ImplFixture->GetImplementation()->SetPropEnum(TestValue);
	});

	LatentIt("Operation.FuncBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncBool(FTestbed1StructBoolWithArray());
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncInt(FTestbed1StructIntWithArray());
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncFloat(FTestbed1StructFloatWithArray());
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncString(FTestbed1StructStringWithArray());
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncEnum", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncEnum(FTestbed1StructEnumWithArray());
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Signal.SigBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnSigBoolSignal.AddLambda([this, TestDone](const FTestbed1StructBoolWithArray& InParamBool)
			{
			// known test value
			FTestbed1StructBoolWithArray ParamBoolTestValue = createTestFTestbed1StructBoolWithArray();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamBool, ParamBoolTestValue);
			TestDone.Execute();
		});

		// use different test value
		FTestbed1StructBoolWithArray ParamBoolTestValue = createTestFTestbed1StructBoolWithArray();
		Testbed1StructArray2InterfacePublisher->BroadcastSigBoolSignal(ParamBoolTestValue);
	});

	LatentIt("Signal.SigInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnSigIntSignal.AddLambda([this, TestDone](const FTestbed1StructIntWithArray& InParamInt)
			{
			// known test value
			FTestbed1StructIntWithArray ParamIntTestValue = createTestFTestbed1StructIntWithArray();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt, ParamIntTestValue);
			TestDone.Execute();
		});

		// use different test value
		FTestbed1StructIntWithArray ParamIntTestValue = createTestFTestbed1StructIntWithArray();
		Testbed1StructArray2InterfacePublisher->BroadcastSigIntSignal(ParamIntTestValue);
	});

	LatentIt("Signal.SigFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnSigFloatSignal.AddLambda([this, TestDone](const FTestbed1StructFloatWithArray& InParamFloat)
			{
			// known test value
			FTestbed1StructFloatWithArray ParamFloatTestValue = createTestFTestbed1StructFloatWithArray();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat, ParamFloatTestValue);
			TestDone.Execute();
		});

		// use different test value
		FTestbed1StructFloatWithArray ParamFloatTestValue = createTestFTestbed1StructFloatWithArray();
		Testbed1StructArray2InterfacePublisher->BroadcastSigFloatSignal(ParamFloatTestValue);
	});

	LatentIt("Signal.SigString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructArray2InterfacePublisher* Testbed1StructArray2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed1StructArray2InterfacePublisher->OnSigStringSignal.AddLambda([this, TestDone](const FTestbed1StructStringWithArray& InParamString)
			{
			// known test value
			FTestbed1StructStringWithArray ParamStringTestValue = createTestFTestbed1StructStringWithArray();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamString, ParamStringTestValue);
			TestDone.Execute();
		});

		// use different test value
		FTestbed1StructStringWithArray ParamStringTestValue = createTestFTestbed1StructStringWithArray();
		Testbed1StructArray2InterfacePublisher->BroadcastSigStringSignal(ParamStringTestValue);
	});
}
} // namespace Tests
} // namespace MQTT
} // namespace StructArray2Interface
} // namespace Testbed1

#endif // WITH_DEV_AUTOMATION_TESTS
