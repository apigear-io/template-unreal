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
#if WITH_DEV_AUTOMATION_TESTS

#include "Counter/Tests/CounterTestsCommon.h"
#include "Counter/Implementation/CounterCounter.h"
#include "CounterCounterJniFixture.h"
#include "Counter/Generated/Jni/CounterCounterJniClient.h"
#include "Counter/Generated/Jni/CounterCounterJniAdapter.h"
#include "CustomTypes/Tests/CustomTypesTestsCommon.h"
#include "ExternTypes/Tests/ExternTypesTestsCommon.h"


#if PLATFORM_ANDROID

#include "Engine/Engine.h"
 #include "Android/AndroidJNI.h"
 #include "Android/AndroidApplication.h"

 #if USE_ANDROID_JNI
 #include <jni.h>
 #endif
#endif

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Counter
{
namespace Counter
{
namespace Jni
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UCounterCounterJniSpec, "Counter.Counter.Jni", CounterTestFilterMask);

TUniquePtr<FCounterCounterJniFixture> ImplFixture;

END_DEFINE_SPEC(UCounterCounterJniSpec);

void UCounterCounterJniSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FCounterCounterJniFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetClient() != nullptr);

		// set up service and adapter
		auto service =ImplFixture->GetLocalImplementation();
		ImplFixture->GetAdapter()->setBackendService(service);

		// setup client
		UCounterCounterJniClient* JniClient = ImplFixture->GetClient();
		TestTrue("Check for valid Jni client", JniClient != nullptr);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		JniClient->_ConnectionStatusChanged.AddLambda([this, TestDone](bool bConnected)
			{
			if (bConnected)
			{
				TestDone.Execute();
			}
		});
		//Test packge name should start with name of the  pacakge declared by the test application in e.g. defaultEngine.ini in [/Script/AndroidRuntimeSettings.AndroidRuntimeSettings] section. 
		FString servicePackage = "com.goldenmaster";
		JniClient->_bindToService(servicePackage, "TestConnectionId");
		#else
		TestDone.Execute();
		#endif
	});

	AfterEach([this]()
		{
			#if PLATFORM_ANDROID && USE_ANDROID_JNI
			UCounterCounterJniClient* JniClient =ImplFixture->GetClient();
			#endif
			ImplFixture.Reset();
	});

	It("Property.Vector.Default", [this]()
		{
		// Do implement test here
		FCustomTypesVector3D TestValue = FCustomTypesVector3D(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetVector(), TestValue);
	});

	LatentIt("Property.Vector.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FCustomTypesVector3D TestValue = FCustomTypesVector3D(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetVector(), TestValue);

		UCounterCounterPublisher* CounterCounterPublisher = ImplFixture->GetClient()->_GetPublisher();
		CounterCounterPublisher->OnVectorChanged.AddLambda([this, TestDone](const FCustomTypesVector3D& InVector)
			{
			FCustomTypesVector3D TestValue = FCustomTypesVector3D();
			// use different test value
			TestValue = createTestFCustomTypesVector3D();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InVector, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetVector(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFCustomTypesVector3D();
		ImplFixture->GetClient()->SetVector(TestValue);
		#if ! (PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
		#endif
	});

	LatentIt("Property.Vector.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FCustomTypesVector3D DefaultValue = FCustomTypesVector3D(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetVector(), DefaultValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UCounterCounterPublisher* CounterCounterPublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UCounterCounterPublisher* CounterCounterPublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		CounterCounterPublisher->OnVectorChanged.AddLambda([this, DefaultValue, TestDone](const FCustomTypesVector3D& InVector)
			{
			FCustomTypesVector3D TestValue = FCustomTypesVector3D();
			// use different test value
			TestValue = createTestFCustomTypesVector3D();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InVector, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetVector(), TestValue);
			#if PLATFORM_ANDROID && USE_ANDROID_JNI
			//TODO CHANGE THE IMPLEMENTATION TO CLIENT this is confusing
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetVector(), TestValue);
			#else
			TestEqual(TEXT("No connection, client has same value as at the start"), ImplFixture->GetClient()->GetVector(), DefaultValue);
			#endif
			TestDone.Execute();
		});
		// use different test value, but init it first.
		FCustomTypesVector3D TestValue = DefaultValue;
		TestValue = createTestFCustomTypesVector3D();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetVector(TestValue);
	});

	LatentIt("Property.Vector.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FCustomTypesVector3D StartValue =  ImplFixture->GetLocalImplementation()->GetVector();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetVector(), StartValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UCounterCounterPublisher* CounterCounterPublisher = ImplFixture->GetClient()->_GetPublisher();
		CounterCounterPublisher->OnVectorChanged.AddLambda([this, TestDone](const FCustomTypesVector3D& InVector)
		#else
		UCounterCounterPublisher* CounterCounterPublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		CounterCounterPublisher->OnVectorChanged.AddLambda([this, TestDone, StartValue](const FCustomTypesVector3D& InVector)
		#endif
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
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetVector(), TestValue);
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetVector(), TestValue);
				#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetVector(), StartValue);
				#endif
				// now set it to the default value
				TestValue = FCustomTypesVector3D(); // default value
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetVector(TestValue);
				#else
				ImplFixture->GetLocalImplementation()->SetVector(TestValue);
				#endif
			}
			else
			{
				FCustomTypesVector3D TestValue = FCustomTypesVector3D(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InVector, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetVector(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetVector(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		FCustomTypesVector3D TestValue = StartValue;
		TestValue = createTestFCustomTypesVector3D();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetVector(TestValue);
	});

	It("Property.ExternVector.Default", [this]()
		{
		// Do implement test here
		FVector TestValue = FVector(0.f, 0.f, 0.f); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetExternVector(), TestValue);
	});

	It("Property.VectorArray.Default", [this]()
		{
		// Do implement test here
		TArray<FCustomTypesVector3D> TestValue = TArray<FCustomTypesVector3D>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetVectorArray(), TestValue);
	});

	LatentIt("Property.VectorArray.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FCustomTypesVector3D> TestValue = TArray<FCustomTypesVector3D>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetVectorArray(), TestValue);

		UCounterCounterPublisher* CounterCounterPublisher = ImplFixture->GetClient()->_GetPublisher();
		CounterCounterPublisher->OnVectorArrayChanged.AddLambda([this, TestDone](const TArray<FCustomTypesVector3D>& InVectorArray)
			{
			TArray<FCustomTypesVector3D> TestValue = TArray<FCustomTypesVector3D>();
			// use different test value
			TestValue = createTestFCustomTypesVector3DArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InVectorArray, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetVectorArray(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFCustomTypesVector3DArray();
		ImplFixture->GetClient()->SetVectorArray(TestValue);
		#if ! (PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
		#endif
	});

	LatentIt("Property.VectorArray.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FCustomTypesVector3D> DefaultValue = TArray<FCustomTypesVector3D>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetVectorArray(), DefaultValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UCounterCounterPublisher* CounterCounterPublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UCounterCounterPublisher* CounterCounterPublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
		CounterCounterPublisher->OnVectorArrayChanged.AddLambda([this, DefaultValue, TestDone](const TArray<FCustomTypesVector3D>& InVectorArray)
			{
			TArray<FCustomTypesVector3D> TestValue = TArray<FCustomTypesVector3D>();
			// use different test value
			TestValue = createTestFCustomTypesVector3DArray();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InVectorArray, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetVectorArray(), TestValue);
			#if PLATFORM_ANDROID && USE_ANDROID_JNI
			//TODO CHANGE THE IMPLEMENTATION TO CLIENT this is confusing
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetVectorArray(), TestValue);
			#else
			TestEqual(TEXT("No connection, client has same value as at the start"), ImplFixture->GetClient()->GetVectorArray(), DefaultValue);
			#endif
			TestDone.Execute();
		});
		// use different test value, but init it first.
		TArray<FCustomTypesVector3D> TestValue = DefaultValue;
		TestValue = createTestFCustomTypesVector3DArray();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetVectorArray(TestValue);
	});

	LatentIt("Property.VectorArray.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		TArray<FCustomTypesVector3D> StartValue =  ImplFixture->GetLocalImplementation()->GetVectorArray();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetVectorArray(), StartValue);

		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UCounterCounterPublisher* CounterCounterPublisher = ImplFixture->GetClient()->_GetPublisher();
		CounterCounterPublisher->OnVectorArrayChanged.AddLambda([this, TestDone](const TArray<FCustomTypesVector3D>& InVectorArray)
		#else
		UCounterCounterPublisher* CounterCounterPublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		CounterCounterPublisher->OnVectorArrayChanged.AddLambda([this, TestDone, StartValue](const TArray<FCustomTypesVector3D>& InVectorArray)
		#endif
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
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetVectorArray(), TestValue);
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetVectorArray(), TestValue);
				#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetVectorArray(), StartValue);
				#endif
				// now set it to the default value
				TestValue = TArray<FCustomTypesVector3D>(); // default value
				#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetVectorArray(TestValue);
				#else
				ImplFixture->GetLocalImplementation()->SetVectorArray(TestValue);
				#endif
			}
			else
			{
				TArray<FCustomTypesVector3D> TestValue = TArray<FCustomTypesVector3D>(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InVectorArray, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetVectorArray(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetVectorArray(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TArray<FCustomTypesVector3D> TestValue = StartValue;
		TestValue = createTestFCustomTypesVector3DArray();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetVectorArray(TestValue);
	});

	It("Property.ExternVectorArray.Default", [this]()
		{
		// Do implement test here
		TArray<FVector> TestValue = TArray<FVector>(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetExternVectorArray(), TestValue);
	});

	// Please implement serialization for FVector before enabling the test.
	xLatentIt("Operation.Increment", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Please implement serialization for FVector before testing.
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->Increment(FVector(0.f, 0.f, 0.f));
			//Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
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
			ImplFixture->GetClient()->IncrementArray(TArray<FVector>());
			//Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Decrement", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->Decrement(FCustomTypesVector3D());
			//Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.DecrementArray", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->DecrementArray(TArray<FCustomTypesVector3D>());
			//Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Signal.ValueChanged", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{

		UCounterCounterPublisher* SourceCounterCounterPublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UCounterCounterPublisher* CounterCounterPublisher = ImplFixture->GetClient()->_GetPublisher();
		#else
		UCounterCounterPublisher* CounterCounterPublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		#endif
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
		SourceCounterCounterPublisher->BroadcastValueChangedSignal(VectorTestValue, ExternVectorTestValue, VectorArrayTestValue, ExternVectorArrayTestValue);
	});
}
} // namespace Tests
} // namespace Jni
} // namespace Counter
} // namespace Counter

#endif // WITH_DEV_AUTOMATION_TESTS
