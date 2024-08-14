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

#include "CounterCounterImpl.spec.h"
#include "Implementation/CounterCounter.h"
#include "CounterCounterImplFixture.h"
#include "CounterTestsCommon.h"
#include "CustomTypes/Private/Tests/CustomTypesTestsCommon.h"
#include "ExternTypes/Private/Tests/ExternTypesTestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UCounterCounterImplSpec::Define()
{
	BeforeEach([this]()
		{
		ImplFixture = MakeUnique<FCounterCounterImplFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		ImplFixture->GetHelper()->SetSpec(this);
	});

	AfterEach([this]()
		{
		ImplFixture.Reset();
	});

	It("Property.Vector.Default", [this]()
		{
		// Do implement test here
		FCustomTypesVector3D TestValue = FCustomTypesVector3D(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetVector(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.Vector.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FCustomTypesVector3D TestValue = FCustomTypesVector3D(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetVector(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UCounterCounterSignals* CounterCounterSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		CounterCounterSignals->OnVectorChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UCounterCounterImplHelper::VectorPropertyCb);
		// use different test value
		TestValue = createTestFCustomTypesVector3D();
		ImplFixture->GetImplementation()->Execute_SetVector(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Property.ExternVector.Default", [this]()
		{
		// Do implement test here
		FVector TestValue = FVector(0.f, 0.f, 0.f); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetExternVector(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	It("Property.VectorArray.Default", [this]()
		{
		// Do implement test here
		TArray<FCustomTypesVector3D> TestValue = TArray<FCustomTypesVector3D>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetVectorArray(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.VectorArray.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FCustomTypesVector3D> TestValue = TArray<FCustomTypesVector3D>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetVectorArray(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UCounterCounterSignals* CounterCounterSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		CounterCounterSignals->OnVectorArrayChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UCounterCounterImplHelper::VectorArrayPropertyCb);
		// use different test value
		TestValue = createTestFCustomTypesVector3DArray();
		ImplFixture->GetImplementation()->Execute_SetVectorArray(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	It("Property.ExternVectorArray.Default", [this]()
		{
		// Do implement test here
		TArray<FVector> TestValue = TArray<FVector>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetExternVectorArray(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	It("Operation.Increment", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_Increment(ImplFixture->GetImplementation().GetObject(), FVector(0.f, 0.f, 0.f));
	});

	It("Operation.IncrementArray", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_IncrementArray(ImplFixture->GetImplementation().GetObject(), TArray<FVector>());
	});

	It("Operation.Decrement", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_Decrement(ImplFixture->GetImplementation().GetObject(), FCustomTypesVector3D());
	});

	It("Operation.DecrementArray", [this]()
		{
		// Do implement test here
		ImplFixture->GetImplementation()->Execute_DecrementArray(ImplFixture->GetImplementation().GetObject(), TArray<FCustomTypesVector3D>());
	});

	LatentIt("Signal.ValueChanged", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UCounterCounterSignals* CounterCounterSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		CounterCounterSignals->OnValueChangedSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UCounterCounterImplHelper::ValueChangedSignalCb);

		// use different test value
		FCustomTypesVector3D VectorTestValue = createTestFCustomTypesVector3D();
		FVector ExternVectorTestValue = FVector(0.f, 0.f, 0.f);
		TArray<FCustomTypesVector3D> VectorArrayTestValue = createTestFCustomTypesVector3DArray();
		TArray<FVector> ExternVectorArrayTestValue = TArray<FVector>();
		CounterCounterSignals->BroadcastValueChangedSignal(VectorTestValue, ExternVectorTestValue, VectorArrayTestValue, ExternVectorArrayTestValue);
	});
}

void UCounterCounterImplSpec::VectorPropertyCb(const FCustomTypesVector3D& InVector)
{
	FCustomTypesVector3D TestValue = FCustomTypesVector3D();
	// use different test value
	TestValue = createTestFCustomTypesVector3D();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InVector, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetVector(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UCounterCounterImplSpec::VectorArrayPropertyCb(const TArray<FCustomTypesVector3D>& InVectorArray)
{
	TArray<FCustomTypesVector3D> TestValue = TArray<FCustomTypesVector3D>();
	// use different test value
	TestValue = createTestFCustomTypesVector3DArray();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InVectorArray, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetVectorArray(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UCounterCounterImplSpec::ValueChangedSignalCb(const FCustomTypesVector3D& InVector, const FVector& InExternVector, const TArray<FCustomTypesVector3D>& InVectorArray, const TArray<FVector>& InExternVectorArray)
{
	// known test value
	FCustomTypesVector3D VectorTestValue = createTestFCustomTypesVector3D();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InVector, VectorTestValue);
	TArray<FCustomTypesVector3D> VectorArrayTestValue = createTestFCustomTypesVector3DArray();
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InVectorArray, VectorArrayTestValue);
	testDoneDelegate.Execute();
}
#endif // WITH_DEV_AUTOMATION_TESTS
