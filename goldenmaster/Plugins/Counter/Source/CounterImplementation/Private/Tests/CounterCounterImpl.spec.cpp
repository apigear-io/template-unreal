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

#include "Counter/Implementation/CounterCounter.h"
#include "CounterCounterImplFixture.h"
#include "Counter/Tests/CounterTestsCommon.h"
#include "CustomTypes/Tests/CustomTypesTestsCommon.h"
#include "ExternTypes/Tests/ExternTypesTestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UCounterCounterImplSpec, "Counter.Counter.Impl", CounterTestFilterMask);

TSharedPtr<FCounterCounterImplFixture> ImplFixture;

END_DEFINE_SPEC(UCounterCounterImplSpec);

void UCounterCounterImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplFixture = MakeShared<FCounterCounterImplFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		ImplFixture->GetHelper()->SetSpec(this);
		ImplFixture->GetHelper()->SetParentFixture(ImplFixture);
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

	LatentIt("Property.Vector.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FCustomTypesVector3D TestValue = FCustomTypesVector3D(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetVector(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UCounterCounterPublisher* CounterCounterPublisher = ImplFixture->GetImplementation()->_GetPublisher();
		CounterCounterPublisher->OnVectorChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UCounterCounterImplHelper::VectorPropertyCb);
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

	LatentIt("Property.VectorArray.ChangeBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FCustomTypesVector3D> TestValue = TArray<FCustomTypesVector3D>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetVectorArray(), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UCounterCounterPublisher* CounterCounterPublisher = ImplFixture->GetImplementation()->_GetPublisher();
		CounterCounterPublisher->OnVectorArrayChangedBP.AddDynamic(ImplFixture->GetHelper().Get(), &UCounterCounterImplHelper::VectorArrayPropertyCb);
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

	It("Operation.Increment", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Increment(FVector(0.f, 0.f, 0.f));
	});

	LatentIt("Operation.IncrementAsync", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		TFuture<FVector> Future = ImplFixture->GetImplementation()->IncrementAsync(FVector(0.f, 0.f, 0.f));

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const FVector& Result)
			{
			// Do implement test here
			Done.Execute();
		});
	});

	It("Operation.IncrementArray", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->IncrementArray(TArray<FVector>());
	});

	LatentIt("Operation.IncrementArrayAsync", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		TFuture<TArray<FVector>> Future = ImplFixture->GetImplementation()->IncrementArrayAsync(TArray<FVector>());

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const TArray<FVector>& Result)
			{
			// Do implement test here
			Done.Execute();
		});
	});

	It("Operation.Decrement", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Decrement(FCustomTypesVector3D());
	});

	LatentIt("Operation.DecrementAsync", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		TFuture<FCustomTypesVector3D> Future = ImplFixture->GetImplementation()->DecrementAsync(FCustomTypesVector3D());

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const FCustomTypesVector3D& Result)
			{
			// Do implement test here
			Done.Execute();
		});
	});

	It("Operation.DecrementArray", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->DecrementArray(TArray<FCustomTypesVector3D>());
	});

	LatentIt("Operation.DecrementArrayAsync", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		TFuture<TArray<FCustomTypesVector3D>> Future = ImplFixture->GetImplementation()->DecrementArrayAsync(TArray<FCustomTypesVector3D>());

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const TArray<FCustomTypesVector3D>& Result)
			{
			// Do implement test here
			Done.Execute();
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

	LatentIt("Signal.ValueChangedBP", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UCounterCounterPublisher* CounterCounterPublisher = ImplFixture->GetImplementation()->_GetPublisher();
		CounterCounterPublisher->OnValueChangedSignalBP.AddDynamic(ImplFixture->GetHelper().Get(), &UCounterCounterImplHelper::ValueChangedSignalCb);

		// use different test value
		FCustomTypesVector3D VectorTestValue = createTestFCustomTypesVector3D();
		FVector ExternVectorTestValue = FVector(0.f, 0.f, 0.f);
		TArray<FCustomTypesVector3D> VectorArrayTestValue = createTestFCustomTypesVector3DArray();
		TArray<FVector> ExternVectorArrayTestValue = TArray<FVector>();
		CounterCounterPublisher->BroadcastValueChangedSignal(VectorTestValue, ExternVectorTestValue, VectorArrayTestValue, ExternVectorArrayTestValue);
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS
