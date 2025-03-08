/**
Copyright 2021 ApiGear UG
Copyright 2021 Epic Games, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "CounterCounterMsgBus.spec.h"
#include "Counter/Implementation/CounterCounter.h"
#include "CounterCounterMsgBusFixture.h"
#include "Counter/Generated/MsgBus/CounterCounterMsgBusClient.h"
#include "Counter/Generated/MsgBus/CounterCounterMsgBusAdapter.h"
#include "HAL/Platform.h"

#if !(PLATFORM_IOS || PLATFORM_ANDROID)
#include "CustomTypes/Tests/CustomTypesTestsCommon.h"
#include "ExternTypes/Tests/ExternTypesTestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UCounterCounterMsgBusSpec::_ConnectionStatusChangedCb(bool bConnected)
{
	if (bConnected)
	{
		testDoneDelegate.Execute();
	}
}

void UCounterCounterMsgBusSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FCounterCounterMsgBusFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		// needed for callbacks
		ImplFixture->GetHelper()->SetSpec(this);

		// set up service and adapter
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UCounterCounter>();
		ImplFixture->GetAdapter()->_setBackendService(service);
		ImplFixture->GetAdapter()->_StartListening();

		// setup client
		testDoneDelegate = TestDone;
		UCounterCounterMsgBusClient* MsgBusClient = Cast<UCounterCounterMsgBusClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid MsgBus client", MsgBusClient != nullptr);

		MsgBusClient->_ConnectionStatusChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UCounterCounterMsgBusHelper::_ConnectionStatusChangedCb);

		MsgBusClient->_Connect();
	});

	AfterEach([this]()
		{
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

		testDoneDelegate = TestDone;
		UCounterCounterSignals* CounterCounterSignals = ImplFixture->GetImplementation()->_GetSignals();
		CounterCounterSignals->OnVectorChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UCounterCounterMsgBusHelper::VectorPropertyCb);
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

		testDoneDelegate = TestDone;
		UCounterCounterSignals* CounterCounterSignals = ImplFixture->GetImplementation()->_GetSignals();
		CounterCounterSignals->OnVectorArrayChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UCounterCounterMsgBusHelper::VectorArrayPropertyCb);
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
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Decrement", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Decrement(FCustomTypesVector3D());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.DecrementArray", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->DecrementArray(TArray<FCustomTypesVector3D>());
			TestDone.Execute();
		});
	});

	LatentIt("Signal.ValueChanged", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UCounterCounterSignals* CounterCounterSignals = ImplFixture->GetImplementation()->_GetSignals();
		CounterCounterSignals->OnValueChangedSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UCounterCounterMsgBusHelper::ValueChangedSignalCb);

		// use different test value
		FCustomTypesVector3D VectorTestValue = createTestFCustomTypesVector3D();
		FVector ExternVectorTestValue = FVector(0.f, 0.f, 0.f);
		TArray<FCustomTypesVector3D> VectorArrayTestValue = createTestFCustomTypesVector3DArray();
		TArray<FVector> ExternVectorArrayTestValue = TArray<FVector>();
		CounterCounterSignals->BroadcastValueChangedSignal(VectorTestValue, ExternVectorTestValue, VectorArrayTestValue, ExternVectorArrayTestValue);
	});
}

void UCounterCounterMsgBusSpec::VectorPropertyCb(const FCustomTypesVector3D& InVector)
{
	FCustomTypesVector3D TestValue = FCustomTypesVector3D();
	// use different test value
	TestValue = createTestFCustomTypesVector3D();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InVector, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetVector(), TestValue);
	testDoneDelegate.Execute();
}

void UCounterCounterMsgBusSpec::VectorArrayPropertyCb(const TArray<FCustomTypesVector3D>& InVectorArray)
{
	TArray<FCustomTypesVector3D> TestValue = TArray<FCustomTypesVector3D>();
	// use different test value
	TestValue = createTestFCustomTypesVector3DArray();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InVectorArray, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetVectorArray(), TestValue);
	testDoneDelegate.Execute();
}

void UCounterCounterMsgBusSpec::ValueChangedSignalCb(const FCustomTypesVector3D& InVector, const FVector& InExternVector, const TArray<FCustomTypesVector3D>& InVectorArray, const TArray<FVector>& InExternVectorArray)
{
	// known test value
	FCustomTypesVector3D VectorTestValue = createTestFCustomTypesVector3D();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InVector, VectorTestValue);
	TArray<FCustomTypesVector3D> VectorArrayTestValue = createTestFCustomTypesVector3DArray();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InVectorArray, VectorArrayTestValue);
	testDoneDelegate.Execute();
}
#endif // WITH_DEV_AUTOMATION_TESTS
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID)
