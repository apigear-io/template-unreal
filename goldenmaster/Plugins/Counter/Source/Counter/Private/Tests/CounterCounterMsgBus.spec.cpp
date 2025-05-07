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
#include "Implementation/CounterCounter.h"
#include "CounterCounterMsgBusFixture.h"
#include "Generated/MsgBus/CounterCounterMsgBusClient.h"
#include "Generated/MsgBus/CounterCounterMsgBusAdapter.h"
#include "CustomTypes/Private/Tests/CustomTypesTestsCommon.h"
#include "ExternTypes/Private/Tests/ExternTypesTestsCommon.h"
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
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetVector(ImplFixture->GetImplementation().GetObject()), TestValue);
	});

	LatentIt("Property.Vector.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FCustomTypesVector3D TestValue = FCustomTypesVector3D(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetVector(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UCounterCounterSignals* CounterCounterSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		CounterCounterSignals->OnVectorChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UCounterCounterMsgBusHelper::VectorPropertyCb);
		// use different test value
		TestValue = createTestFCustomTypesVector3D();
		ImplFixture->GetImplementation()->Execute_SetVector(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Property.Vector.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FCustomTypesVector3D TestValue = FCustomTypesVector3D(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetVector(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UCounterCounterSignals* CounterCounterSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		CounterCounterSignals->OnVectorChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UCounterCounterMsgBusHelper::VectorPropertyChangeLocalCheckRemoteCb);
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

		testDoneDelegate = TestDone;
		UCounterCounterSignals* CounterCounterSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		CounterCounterSignals->OnVectorChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UCounterCounterMsgBusHelper::VectorPropertyChangeLocalChangeRemoteCb);
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

		testDoneDelegate = TestDone;
		UCounterCounterSignals* CounterCounterSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		CounterCounterSignals->OnVectorArrayChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UCounterCounterMsgBusHelper::VectorArrayPropertyCb);
		// use different test value
		TestValue = createTestFCustomTypesVector3DArray();
		ImplFixture->GetImplementation()->Execute_SetVectorArray(ImplFixture->GetImplementation().GetObject(), TestValue);
	});

	LatentIt("Property.VectorArray.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FCustomTypesVector3D> TestValue = TArray<FCustomTypesVector3D>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->Execute_GetVectorArray(ImplFixture->GetImplementation().GetObject()), TestValue);

		testDoneDelegate = TestDone;
		UCounterCounterSignals* CounterCounterSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		CounterCounterSignals->OnVectorArrayChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UCounterCounterMsgBusHelper::VectorArrayPropertyChangeLocalCheckRemoteCb);
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

		testDoneDelegate = TestDone;
		UCounterCounterSignals* CounterCounterSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		CounterCounterSignals->OnVectorArrayChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UCounterCounterMsgBusHelper::VectorArrayPropertyChangeLocalChangeRemoteCb);
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
		testDoneDelegate = TestDone;
		UCounterCounterSignals* CounterCounterSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
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
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetVector(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UCounterCounterMsgBusSpec::VectorPropertyChangeLocalCheckRemoteCb(const FCustomTypesVector3D& InVector)
{
	FCustomTypesVector3D TestValue = FCustomTypesVector3D();
	// use different test value
	TestValue = createTestFCustomTypesVector3D();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InVector, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetVector(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UCounterCounterMsgBusSpec::VectorPropertyChangeLocalChangeRemoteCb(const FCustomTypesVector3D& InVector)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		FCustomTypesVector3D TestValue = FCustomTypesVector3D();
		// use different test value
		TestValue = createTestFCustomTypesVector3D();
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InVector, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetVector(ImplFixture->GetImplementation().GetObject()), TestValue);

		// now set it to the default value
		TestValue = FCustomTypesVector3D(); // default value
		ImplFixture->GetImplementation()->Execute_SetVector(ImplFixture->GetImplementation().GetObject(), TestValue);
	}
	else
	{
		FCustomTypesVector3D TestValue = FCustomTypesVector3D(); // default value
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InVector, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetVector(ImplFixture->GetImplementation().GetObject()), TestValue);
		testDoneDelegate.Execute();
	}
}

void UCounterCounterMsgBusSpec::VectorArrayPropertyCb(const TArray<FCustomTypesVector3D>& InVectorArray)
{
	TArray<FCustomTypesVector3D> TestValue = TArray<FCustomTypesVector3D>();
	// use different test value
	TestValue = createTestFCustomTypesVector3DArray();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InVectorArray, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetVectorArray(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UCounterCounterMsgBusSpec::VectorArrayPropertyChangeLocalCheckRemoteCb(const TArray<FCustomTypesVector3D>& InVectorArray)
{
	TArray<FCustomTypesVector3D> TestValue = TArray<FCustomTypesVector3D>();
	// use different test value
	TestValue = createTestFCustomTypesVector3DArray();
	TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InVectorArray, TestValue);
	TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetVectorArray(ImplFixture->GetImplementation().GetObject()), TestValue);
	testDoneDelegate.Execute();
}

void UCounterCounterMsgBusSpec::VectorArrayPropertyChangeLocalChangeRemoteCb(const TArray<FCustomTypesVector3D>& InVectorArray)
{
	// this function must be called twice before we can successfully pass this test.
	// first call it should have the test value of the parameter
	// second call it should have the default value of the parameter again
	static int count = 0;
	count++;

	if (count % 2 != 0)
	{
		TArray<FCustomTypesVector3D> TestValue = TArray<FCustomTypesVector3D>();
		// use different test value
		TestValue = createTestFCustomTypesVector3DArray();
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InVectorArray, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetVectorArray(ImplFixture->GetImplementation().GetObject()), TestValue);

		// now set it to the default value
		TestValue = TArray<FCustomTypesVector3D>(); // default value
		ImplFixture->GetImplementation()->Execute_SetVectorArray(ImplFixture->GetImplementation().GetObject(), TestValue);
	}
	else
	{
		TArray<FCustomTypesVector3D> TestValue = TArray<FCustomTypesVector3D>(); // default value
		TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InVectorArray, TestValue);
		TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->Execute_GetVectorArray(ImplFixture->GetImplementation().GetObject()), TestValue);
		testDoneDelegate.Execute();
	}
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
