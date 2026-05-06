// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "TbStructArray/Tests/TbStructArrayTestsCommon.h"
#include "TbStructArray/Implementation/TbStructArrayStructArrayFieldInterface.h"
#include "TbStructArrayStructArrayFieldInterfaceMQTTFixture.h"
#include "TbStructArray/Generated/MQTT/TbStructArrayStructArrayFieldInterfaceMQTTClient.h"
#include "TbStructArray/Generated/MQTT/TbStructArrayStructArrayFieldInterfaceMQTTAdapter.h"
#include "ApiGearMQTTClient.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbStructArray
{
namespace StructArrayFieldInterface
{
namespace MQTT
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbStructArrayStructArrayFieldInterfaceMQTTSpec, "TbStructArray.StructArrayFieldInterface.MQTT", TbStructArrayTestFilterMask);

TUniquePtr<FTbStructArrayStructArrayFieldInterfaceMQTTFixture> ImplFixture;

END_DEFINE_SPEC(UTbStructArrayStructArrayFieldInterfaceMQTTSpec);

void UTbStructArrayStructArrayFieldInterfaceMQTTSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbStructArrayStructArrayFieldInterfaceMQTTFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// setup client
		UTbStructArrayStructArrayFieldInterfaceMQTTClient* MQTTClient = Cast<UTbStructArrayStructArrayFieldInterfaceMQTTClient>(ImplFixture->GetImplementation().GetObject());
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

	It("Property.PropStructArray.Default", [this]()
		{
		// Do implement test here
		FTbStructArrayStructWithArrayOfStructs TestValue = FTbStructArrayStructWithArrayOfStructs(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropStructArray(), TestValue);
	});

	LatentIt("Property.PropStructArray.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbStructArrayStructWithArrayOfStructs TestValue = FTbStructArrayStructWithArrayOfStructs(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropStructArray(), TestValue);

		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbStructArrayStructArrayFieldInterfacePublisher->OnPropStructArrayChanged.AddLambda([this, TestDone](const FTbStructArrayStructWithArrayOfStructs& InPropStructArray)
			{
			FTbStructArrayStructWithArrayOfStructs TestValue = FTbStructArrayStructWithArrayOfStructs();
			// use different test value
			TestValue = createTestFTbStructArrayStructWithArrayOfStructs();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropStructArray, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropStructArray(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTbStructArrayStructWithArrayOfStructs();
		ImplFixture->GetImplementation()->SetPropStructArray(TestValue);
	});

	It("Property.PropEnumArray.Default", [this]()
		{
		// Do implement test here
		FTbStructArrayStructWithArrayOfEnums TestValue = FTbStructArrayStructWithArrayOfEnums(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropEnumArray(), TestValue);
	});

	LatentIt("Property.PropEnumArray.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbStructArrayStructWithArrayOfEnums TestValue = FTbStructArrayStructWithArrayOfEnums(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropEnumArray(), TestValue);

		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbStructArrayStructArrayFieldInterfacePublisher->OnPropEnumArrayChanged.AddLambda([this, TestDone](const FTbStructArrayStructWithArrayOfEnums& InPropEnumArray)
			{
			FTbStructArrayStructWithArrayOfEnums TestValue = FTbStructArrayStructWithArrayOfEnums();
			// use different test value
			TestValue = createTestFTbStructArrayStructWithArrayOfEnums();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnumArray, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropEnumArray(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTbStructArrayStructWithArrayOfEnums();
		ImplFixture->GetImplementation()->SetPropEnumArray(TestValue);
	});

	It("Property.PropIntArray.Default", [this]()
		{
		// Do implement test here
		FTbStructArrayStructWithArrayOfInts TestValue = FTbStructArrayStructWithArrayOfInts(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropIntArray(), TestValue);
	});

	LatentIt("Property.PropIntArray.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbStructArrayStructWithArrayOfInts TestValue = FTbStructArrayStructWithArrayOfInts(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropIntArray(), TestValue);

		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbStructArrayStructArrayFieldInterfacePublisher->OnPropIntArrayChanged.AddLambda([this, TestDone](const FTbStructArrayStructWithArrayOfInts& InPropIntArray)
			{
			FTbStructArrayStructWithArrayOfInts TestValue = FTbStructArrayStructWithArrayOfInts();
			// use different test value
			TestValue = createTestFTbStructArrayStructWithArrayOfInts();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropIntArray, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropIntArray(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTbStructArrayStructWithArrayOfInts();
		ImplFixture->GetImplementation()->SetPropIntArray(TestValue);
	});

	It("Property.PropMixed.Default", [this]()
		{
		// Do implement test here
		FTbStructArrayMixedStruct TestValue = FTbStructArrayMixedStruct(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropMixed(), TestValue);
	});

	LatentIt("Property.PropMixed.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbStructArrayMixedStruct TestValue = FTbStructArrayMixedStruct(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropMixed(), TestValue);

		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbStructArrayStructArrayFieldInterfacePublisher->OnPropMixedChanged.AddLambda([this, TestDone](const FTbStructArrayMixedStruct& InPropMixed)
			{
			FTbStructArrayMixedStruct TestValue = FTbStructArrayMixedStruct();
			// use different test value
			TestValue = createTestFTbStructArrayMixedStruct();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropMixed, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropMixed(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTbStructArrayMixedStruct();
		ImplFixture->GetImplementation()->SetPropMixed(TestValue);
	});

	LatentIt("Operation.FuncMixed", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncMixed(FTbStructArrayMixedStruct());
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncStructArray", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncStructArray(FTbStructArrayStructWithArrayOfStructs());
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Signal.SigMixed", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbStructArrayStructArrayFieldInterfacePublisher->OnSigMixedSignal.AddLambda([this, TestDone](const FTbStructArrayMixedStruct& InParamMixed)
			{
			// known test value
			FTbStructArrayMixedStruct ParamMixedTestValue = createTestFTbStructArrayMixedStruct();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamMixed, ParamMixedTestValue);
			TestDone.Execute();
		});

		// use different test value
		FTbStructArrayMixedStruct ParamMixedTestValue = createTestFTbStructArrayMixedStruct();
		TbStructArrayStructArrayFieldInterfacePublisher->BroadcastSigMixedSignal(ParamMixedTestValue);
	});

	LatentIt("Signal.SigStructArray", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbStructArrayStructArrayFieldInterfacePublisher->OnSigStructArraySignal.AddLambda([this, TestDone](const FTbStructArrayStructWithArrayOfStructs& InParamPoints)
			{
			// known test value
			FTbStructArrayStructWithArrayOfStructs ParamPointsTestValue = createTestFTbStructArrayStructWithArrayOfStructs();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamPoints, ParamPointsTestValue);
			TestDone.Execute();
		});

		// use different test value
		FTbStructArrayStructWithArrayOfStructs ParamPointsTestValue = createTestFTbStructArrayStructWithArrayOfStructs();
		TbStructArrayStructArrayFieldInterfacePublisher->BroadcastSigStructArraySignal(ParamPointsTestValue);
	});
}
} // namespace Tests
} // namespace MQTT
} // namespace StructArrayFieldInterface
} // namespace TbStructArray

#endif // WITH_DEV_AUTOMATION_TESTS
