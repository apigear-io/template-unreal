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
#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "CounterCounterOLinkFixture.h"
#include "Counter/Implementation/CounterCounter.h"
#include "Counter/Generated/OLink/CounterCounterOLinkClient.h"
#include "Counter/Generated/OLink/CounterCounterOLinkAdapter.h"

#include "OLinkHost.h"
#include "OLinkClientConnection.h" // for olink factory
#include "Counter/Tests/CounterTestsCommon.h"
#include "CustomTypes/Tests/CustomTypesTestsCommon.h"
#include "ExternTypes/Tests/ExternTypesTestsCommon.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Counter
{
namespace Counter
{
namespace OLink
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UCounterCounterOLinkSpec, "Counter.Counter.OLink", CounterTestFilterMask);

TUniquePtr<FCounterCounterOLinkFixture> ImplFixture;

END_DEFINE_SPEC(UCounterCounterOLinkSpec);

void UCounterCounterOLinkSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FCounterCounterOLinkFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// set up service and adapter
		ImplFixture->GetHost()->Stop();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UCounterCounter>();
		ImplFixture->GetAdapter()->setBackendService(service);
		ImplFixture->GetAdapter()->setOLinkHost(ImplFixture->GetHost());
		ImplFixture->GetHost()->Start(8666);

		// setup client
		UCounterCounterOLinkClient* OLinkClient = Cast<UCounterCounterOLinkClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid OLink client", OLinkClient != nullptr);

		OLinkClient->_SubscriptionStatusChanged.AddLambda([this, TestDone](bool bSubscribed)
			{
			if (bSubscribed)
			{
				TestDone.Execute();
			}
		});

		ImplFixture->Connection = OLinkFactory::Create(OLinkClient, "TestingConnection");
		ImplFixture->Connection->Configure("ws://127.0.0.1:8666/ws", false);

		OLinkClient->UseConnection(ImplFixture->Connection);
		ImplFixture->Connection->Connect();
	});

	AfterEach([this]()
		{
		ImplFixture->Connection->Disconnect();
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

		UCounterCounterSignals* CounterCounterSignals = ImplFixture->GetImplementation()->_GetSignals();
		CounterCounterSignals->OnVectorChanged.AddLambda([this, TestDone](const FCustomTypesVector3D& InVector)
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

		UCounterCounterSignals* CounterCounterSignals = ImplFixture->GetImplementation()->_GetSignals();
		CounterCounterSignals->OnVectorArrayChanged.AddLambda([this, TestDone](const TArray<FCustomTypesVector3D>& InVectorArray)
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
		UCounterCounterSignals* CounterCounterSignals = ImplFixture->GetImplementation()->_GetSignals();
		CounterCounterSignals->OnValueChangedSignal.AddLambda([this, TestDone](const FCustomTypesVector3D& InVector, const FVector& InExternVector, const TArray<FCustomTypesVector3D>& InVectorArray, const TArray<FVector>& InExternVectorArray)
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
		CounterCounterSignals->BroadcastValueChangedSignal(VectorTestValue, ExternVectorTestValue, VectorArrayTestValue, ExternVectorArrayTestValue);
	});
}
} // namespace Tests
} // namespace OLink
} // namespace Counter
} // namespace Counter

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
