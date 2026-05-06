// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "Counter/Tests/CounterTestsCommon.h"
#include "Counter/Implementation/CounterCounter.h"
#include "CounterCounterMQTTFixture.h"
#include "Counter/Generated/MQTT/CounterCounterMQTTClient.h"
#include "Counter/Generated/MQTT/CounterCounterMQTTAdapter.h"
#include "ApiGearMQTTClient.h"
#include "CustomTypes/Tests/CustomTypesTestsCommon.h"
#include "ExternTypes/Tests/ExternTypesTestsCommon.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Counter
{
namespace Counter
{
namespace MQTT
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UCounterCounterMQTTSpec, "Counter.Counter.MQTT", CounterTestFilterMask);

TUniquePtr<FCounterCounterMQTTFixture> ImplFixture;

END_DEFINE_SPEC(UCounterCounterMQTTSpec);

void UCounterCounterMQTTSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FCounterCounterMQTTFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// setup client
		UCounterCounterMQTTClient* MQTTClient = Cast<UCounterCounterMQTTClient>(ImplFixture->GetImplementation().GetObject());
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

	It("Property.Vector.Default", [this]()
		{
		// Do implement test here
		FCustomTypesVector3D TestValue = FCustomTypesVector3D(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetVector(), TestValue);
	});

	LatentIt("Property.Vector.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FCustomTypesVector3D TestValue = FCustomTypesVector3D(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetVector(), TestValue);

		UCounterCounterPublisher* CounterCounterPublisher = ImplFixture->GetImplementation()->_GetPublisher();
		CounterCounterPublisher->OnVectorChanged.AddLambda([this, TestDone](const FCustomTypesVector3D& InVector)
			{
			FCustomTypesVector3D TestValue = FCustomTypesVector3D();
			// use different test value
			TestValue = createTestFCustomTypesVector3D();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InVector, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetVector(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFCustomTypesVector3D();
		ImplFixture->GetImplementation()->SetVector(TestValue);
	});

	It("Property.ExternVector.Default", [this]()
		{
		// Do implement test here
		FVector TestValue = FVector(0.f, 0.f, 0.f); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetExternVector(), TestValue);
	});

	It("Property.VectorArray.Default", [this]()
		{
		// Do implement test here
		TArray<FCustomTypesVector3D> TestValue = TArray<FCustomTypesVector3D>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetVectorArray(), TestValue);
	});

	LatentIt("Property.VectorArray.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FCustomTypesVector3D> TestValue = TArray<FCustomTypesVector3D>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetVectorArray(), TestValue);

		UCounterCounterPublisher* CounterCounterPublisher = ImplFixture->GetImplementation()->_GetPublisher();
		CounterCounterPublisher->OnVectorArrayChanged.AddLambda([this, TestDone](const TArray<FCustomTypesVector3D>& InVectorArray)
			{
			TArray<FCustomTypesVector3D> TestValue = TArray<FCustomTypesVector3D>();
			// use different test value
			TestValue = createTestFCustomTypesVector3DArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InVectorArray, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetVectorArray(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFCustomTypesVector3DArray();
		ImplFixture->GetImplementation()->SetVectorArray(TestValue);
	});

	It("Property.ExternVectorArray.Default", [this]()
		{
		// Do implement test here
		TArray<FVector> TestValue = TArray<FVector>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetExternVectorArray(), TestValue);
	});

	// Please implement serialization for FVector before enabling the test.
	xLatentIt("Operation.Increment", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Please implement serialization for FVector before testing.
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Increment(FVector(0.f, 0.f, 0.f));
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	// Please implement serialization for TArray<FVector> before enabling the test.
	xLatentIt("Operation.IncrementArray", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Please implement serialization for TArray<FVector> before testing.
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->IncrementArray(TArray<FVector>());
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Decrement", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Decrement(FCustomTypesVector3D());
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Operation.DecrementArray", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->DecrementArray(TArray<FCustomTypesVector3D>());
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Signal.ValueChanged", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UCounterCounterPublisher* CounterCounterPublisher = ImplFixture->GetImplementation()->_GetPublisher();
		CounterCounterPublisher->OnValueChangedSignal.AddLambda([this, TestDone](const FCustomTypesVector3D& InVector, const FVector& InExternVector, const TArray<FCustomTypesVector3D>& InVectorArray, const TArray<FVector>& InExternVectorArray)
			{
			// known test value
			FCustomTypesVector3D VectorTestValue = createTestFCustomTypesVector3D();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InVector, VectorTestValue);
			TArray<FCustomTypesVector3D> VectorArrayTestValue = createTestFCustomTypesVector3DArray();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InVectorArray, VectorArrayTestValue);
			TestDone.Execute();
		});

		// use different test value
		FCustomTypesVector3D VectorTestValue = createTestFCustomTypesVector3D();
		FVector ExternVectorTestValue = FVector(0.f, 0.f, 0.f);
		TArray<FCustomTypesVector3D> VectorArrayTestValue = createTestFCustomTypesVector3DArray();
		TArray<FVector> ExternVectorArrayTestValue = TArray<FVector>();
		CounterCounterPublisher->BroadcastValueChangedSignal(VectorTestValue, ExternVectorTestValue, VectorArrayTestValue, ExternVectorArrayTestValue);
	});
}
} // namespace Tests
} // namespace MQTT
} // namespace Counter
} // namespace Counter

#endif // WITH_DEV_AUTOMATION_TESTS
