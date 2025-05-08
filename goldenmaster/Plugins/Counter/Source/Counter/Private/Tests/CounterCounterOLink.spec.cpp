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

#include "OLinkCommon.h"
#include "CounterTestsCommon.h"
#include "Implementation/CounterCounter.h"
#include "CounterCounterOLinkFixture.h"
#include "Generated/OLink/CounterCounterOLinkClient.h"
#include "Generated/OLink/CounterCounterOLinkAdapter.h"
#include "HAL/Platform.h"

#if !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
#include "OLinkHost.h"
#include "OLinkClientConnection.h" // for olink factory
#include "CustomTypes/Private/Tests/CustomTypesTestsCommon.h"
#include "ExternTypes/Private/Tests/ExternTypesTestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UCounterCounterOLinkSpec, "Counter.Counter.OLink", CounterTestFilterMask);

TSharedPtr<FCounterCounterOLinkFixture> ImplFixture;

END_DEFINE_SPEC(UCounterCounterOLinkSpec);

void UCounterCounterOLinkSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeShared<FCounterCounterOLinkFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		// needed for callbacks
		ImplFixture->GetHelper()->SetSpec(this);
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		ImplFixture->GetHelper()->SetParentFixture(ImplFixture);

		// set up service and adapter
		ImplFixture->GetHost()->Stop();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UCounterCounter>();
		ImplFixture->GetAdapter()->setBackendService(service);
		ImplFixture->GetAdapter()->setOLinkHost(ImplFixture->GetHost());
		ImplFixture->GetHost()->Start(8666);

		// setup client
		UCounterCounterOLinkClient* OLinkClient = Cast<UCounterCounterOLinkClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid OLink client", OLinkClient != nullptr);

		OLinkClient->_SubscriptionStatusChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UCounterCounterOLinkHelper::_SubscriptionStatusChangedCb);

		ImplFixture->Connection = OLinkFactory::Create(GetTransientPackage(), "TestingConnection");
		ImplFixture->Connection.GetObject()->AddToRoot();
		ImplFixture->Connection->Configure("ws://127.0.0.1:8666/ws", false);

		OLinkClient->UseConnection(ImplFixture->Connection);
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
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetVector(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.Vector.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FCustomTypesVector3D TestValue = FCustomTypesVector3D(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetVector(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UCounterCounterSignals* CounterCounterSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		CounterCounterSignals->OnVectorChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UCounterCounterOLinkHelper::VectorPropertyCb);
		// use different test value
		TestValue = createTestFCustomTypesVector3D();
		ImplFixture->GetImplementation()->Execute_SetVector(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Property.Vector.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FCustomTypesVector3D TestValue = FCustomTypesVector3D(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetVector(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UCounterCounterSignals* CounterCounterSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		CounterCounterSignals->OnVectorChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UCounterCounterOLinkHelper::VectorPropertyChangeLocalCheckRemoteCb);
		// use different test value
		TestValue = createTestFCustomTypesVector3D();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UCounterCounter>();
		service->Execute_SetVector(service, TestValue);
	});

	LatentIt("Property.Vector.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FCustomTypesVector3D TestValue = FCustomTypesVector3D(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetVector(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UCounterCounterSignals* CounterCounterSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		CounterCounterSignals->OnVectorChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UCounterCounterOLinkHelper::VectorPropertyChangeLocalChangeRemoteCb);
		// use different test value
		TestValue = createTestFCustomTypesVector3D();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UCounterCounter>();
		service->Execute_SetVector(service, TestValue);
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

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UCounterCounterSignals* CounterCounterSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		CounterCounterSignals->OnVectorArrayChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UCounterCounterOLinkHelper::VectorArrayPropertyCb);
		// use different test value
		TestValue = createTestFCustomTypesVector3DArray();
		ImplFixture->GetImplementation()->Execute_SetVectorArray(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Property.VectorArray.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FCustomTypesVector3D> TestValue = TArray<FCustomTypesVector3D>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetVectorArray(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UCounterCounterSignals* CounterCounterSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		CounterCounterSignals->OnVectorArrayChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UCounterCounterOLinkHelper::VectorArrayPropertyChangeLocalCheckRemoteCb);
		// use different test value
		TestValue = createTestFCustomTypesVector3DArray();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UCounterCounter>();
		service->Execute_SetVectorArray(service, TestValue);
	});

	LatentIt("Property.VectorArray.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FCustomTypesVector3D> TestValue = TArray<FCustomTypesVector3D>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetVectorArray(ImplFixture->GetImplementation().GetObject()), TestValue);

		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UCounterCounterSignals* CounterCounterSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		CounterCounterSignals->OnVectorArrayChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UCounterCounterOLinkHelper::VectorArrayPropertyChangeLocalChangeRemoteCb);
		// use different test value
		TestValue = createTestFCustomTypesVector3DArray();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UCounterCounter>();
		service->Execute_SetVectorArray(service, TestValue);
	});

	It("Property.ExternVectorArray.Default", [this]()
		{
		// Do implement test here
		TArray<FVector> TestValue = TArray<FVector>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetExternVectorArray(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	// Please implement serialization for FVector before enabling the test.
	xLatentIt("Operation.Increment", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Please implement serialization for FVector before testing.
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_Increment(ImplFixture->GetImplementation().GetObject(), FVector(0.f, 0.f, 0.f));
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
			ImplFixture->GetImplementation()->Execute_IncrementArray(ImplFixture->GetImplementation().GetObject(), TArray<FVector>());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Decrement", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_Decrement(ImplFixture->GetImplementation().GetObject(), FCustomTypesVector3D());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.DecrementArray", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_DecrementArray(ImplFixture->GetImplementation().GetObject(), TArray<FCustomTypesVector3D>());
			TestDone.Execute();
		});
	});

	LatentIt("Signal.ValueChanged", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UCounterCounterSignals* CounterCounterSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		CounterCounterSignals->OnValueChangedSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UCounterCounterOLinkHelper::ValueChangedSignalCb);

		// use different test value
		FCustomTypesVector3D VectorTestValue = createTestFCustomTypesVector3D();
		FVector ExternVectorTestValue = FVector(0.f, 0.f, 0.f);
		TArray<FCustomTypesVector3D> VectorArrayTestValue = createTestFCustomTypesVector3DArray();
		TArray<FVector> ExternVectorArrayTestValue = TArray<FVector>();
		CounterCounterSignals->BroadcastValueChangedSignal(VectorTestValue, ExternVectorTestValue, VectorArrayTestValue, ExternVectorArrayTestValue);
	});
}
#endif // WITH_DEV_AUTOMATION_TESTS
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
