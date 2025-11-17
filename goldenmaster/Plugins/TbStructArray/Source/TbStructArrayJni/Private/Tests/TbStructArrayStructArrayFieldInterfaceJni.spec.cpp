/**// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT*/

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "TbStructArray/Tests/TbStructArrayTestsCommon.h"
#include "TbStructArray/Implementation/TbStructArrayStructArrayFieldInterface.h"
#include "TbStructArrayStructArrayFieldInterfaceJniFixture.h"
#include "TbStructArray/Generated/Jni/TbStructArrayStructArrayFieldInterfaceJniClient.h"
#include "TbStructArray/Generated/Jni/TbStructArrayStructArrayFieldInterfaceJniAdapter.h"

#if PLATFORM_ANDROID

#include "Engine/Engine.h"
#include "Android/AndroidJNI.h"
#include "Android/AndroidApplication.h"

#if USE_ANDROID_JNI
#include <jni.h>
#endif
#endif

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbStructArray
{
namespace StructArrayFieldInterface
{
namespace Jni
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbStructArrayStructArrayFieldInterfaceJniSpec, "TbStructArray.StructArrayFieldInterface.Jni", TbStructArrayTestFilterMask);

TUniquePtr<FTbStructArrayStructArrayFieldInterfaceJniFixture> ImplFixture;

END_DEFINE_SPEC(UTbStructArrayStructArrayFieldInterfaceJniSpec);

void UTbStructArrayStructArrayFieldInterfaceJniSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbStructArrayStructArrayFieldInterfaceJniFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetClient() != nullptr);

		// set up service and adapter
		auto service = ImplFixture->GetLocalImplementation();
		ImplFixture->GetAdapter()->setBackendService(service);

		// setup client
		UTbStructArrayStructArrayFieldInterfaceJniClient* JniClient = ImplFixture->GetClient();
		TestTrue("Check for valid Jni client", JniClient != nullptr);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		JniClient->_ConnectionStatusChanged.AddLambda([this, TestDone](bool bConnected)
			{
			if (bConnected)
			{
				TestDone.Execute();
			}
		});
		// Test packge name should start with name of the  pacakge declared by the test application in e.g. defaultEngine.ini in [/Script/AndroidRuntimeSettings.AndroidRuntimeSettings] section.
		FString servicePackage = "com.goldenmaster";
		JniClient->_bindToService(servicePackage, "TestConnectionId");
#else
		TestDone.Execute();
#endif
	});

	AfterEach([this]()
		{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbStructArrayStructArrayFieldInterfaceJniClient* JniClient = ImplFixture->GetClient();
#endif
		ImplFixture.Reset();
	});

	It("Property.PropStructArray.Default", [this]()
		{
		// Do implement test here
		FTbStructArrayStructWithArrayOfStructs TestValue = FTbStructArrayStructWithArrayOfStructs(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropStructArray(), TestValue);
	});

	LatentIt("Property.PropStructArray.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbStructArrayStructWithArrayOfStructs TestValue = FTbStructArrayStructWithArrayOfStructs(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropStructArray(), TestValue);

		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbStructArrayStructArrayFieldInterfacePublisher->OnPropStructArrayChanged.AddLambda([this, TestDone](const FTbStructArrayStructWithArrayOfStructs& InPropStructArray)
			{
			FTbStructArrayStructWithArrayOfStructs TestValue = FTbStructArrayStructWithArrayOfStructs();
			// use different test value
			TestValue = createTestFTbStructArrayStructWithArrayOfStructs();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropStructArray, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropStructArray(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTbStructArrayStructWithArrayOfStructs();
		ImplFixture->GetClient()->SetPropStructArray(TestValue);
#if !(PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
#endif
	});

	LatentIt("Property.PropStructArray.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbStructArrayStructWithArrayOfStructs DefaultValue = FTbStructArrayStructWithArrayOfStructs(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropStructArray(), DefaultValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbStructArrayStructArrayFieldInterfacePublisher->OnPropStructArrayChanged.AddLambda([this, DefaultValue, TestDone](const FTbStructArrayStructWithArrayOfStructs& InPropStructArray)
			{
			FTbStructArrayStructWithArrayOfStructs TestValue = FTbStructArrayStructWithArrayOfStructs();
			// use different test value
			TestValue = createTestFTbStructArrayStructWithArrayOfStructs();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropStructArray, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropStructArray(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropStructArray(), TestValue);
#else
			TestEqual(TEXT("No connection, client has same value as at the start"), ImplFixture->GetClient()->GetPropStructArray(), DefaultValue);
#endif
			TestDone.Execute();
		});
		// use different test value, but init it first.
		FTbStructArrayStructWithArrayOfStructs TestValue = DefaultValue;
		TestValue = createTestFTbStructArrayStructWithArrayOfStructs();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropStructArray(TestValue);
	});

	LatentIt("Property.PropStructArray.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbStructArrayStructWithArrayOfStructs StartValue = ImplFixture->GetLocalImplementation()->GetPropStructArray();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropStructArray(), StartValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbStructArrayStructArrayFieldInterfacePublisher->OnPropStructArrayChanged.AddLambda([this, TestDone](const FTbStructArrayStructWithArrayOfStructs& InPropStructArray)
#else
		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		TbStructArrayStructArrayFieldInterfacePublisher->OnPropStructArrayChanged.AddLambda([this, TestDone, StartValue](const FTbStructArrayStructWithArrayOfStructs& InPropStructArray)
#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				FTbStructArrayStructWithArrayOfStructs TestValue = FTbStructArrayStructWithArrayOfStructs();
				// use different test value
				TestValue = createTestFTbStructArrayStructWithArrayOfStructs();
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropStructArray, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropStructArray(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropStructArray(), TestValue);
#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropStructArray(), StartValue);
#endif
				// now set it to the default value
				TestValue = FTbStructArrayStructWithArrayOfStructs(); // default value
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetPropStructArray(TestValue);
#else
				ImplFixture->GetLocalImplementation()->SetPropStructArray(TestValue);
#endif
			}
			else
			{
				FTbStructArrayStructWithArrayOfStructs TestValue = FTbStructArrayStructWithArrayOfStructs(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropStructArray, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropStructArray(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropStructArray(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		FTbStructArrayStructWithArrayOfStructs TestValue = StartValue;
		TestValue = createTestFTbStructArrayStructWithArrayOfStructs();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropStructArray(TestValue);
	});

	It("Property.PropEnumArray.Default", [this]()
		{
		// Do implement test here
		FTbStructArrayStructWithArrayOfEnums TestValue = FTbStructArrayStructWithArrayOfEnums(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropEnumArray(), TestValue);
	});

	LatentIt("Property.PropEnumArray.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbStructArrayStructWithArrayOfEnums TestValue = FTbStructArrayStructWithArrayOfEnums(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropEnumArray(), TestValue);

		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbStructArrayStructArrayFieldInterfacePublisher->OnPropEnumArrayChanged.AddLambda([this, TestDone](const FTbStructArrayStructWithArrayOfEnums& InPropEnumArray)
			{
			FTbStructArrayStructWithArrayOfEnums TestValue = FTbStructArrayStructWithArrayOfEnums();
			// use different test value
			TestValue = createTestFTbStructArrayStructWithArrayOfEnums();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnumArray, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropEnumArray(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTbStructArrayStructWithArrayOfEnums();
		ImplFixture->GetClient()->SetPropEnumArray(TestValue);
#if !(PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
#endif
	});

	LatentIt("Property.PropEnumArray.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbStructArrayStructWithArrayOfEnums DefaultValue = FTbStructArrayStructWithArrayOfEnums(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropEnumArray(), DefaultValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbStructArrayStructArrayFieldInterfacePublisher->OnPropEnumArrayChanged.AddLambda([this, DefaultValue, TestDone](const FTbStructArrayStructWithArrayOfEnums& InPropEnumArray)
			{
			FTbStructArrayStructWithArrayOfEnums TestValue = FTbStructArrayStructWithArrayOfEnums();
			// use different test value
			TestValue = createTestFTbStructArrayStructWithArrayOfEnums();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnumArray, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropEnumArray(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropEnumArray(), TestValue);
#else
			TestEqual(TEXT("No connection, client has same value as at the start"), ImplFixture->GetClient()->GetPropEnumArray(), DefaultValue);
#endif
			TestDone.Execute();
		});
		// use different test value, but init it first.
		FTbStructArrayStructWithArrayOfEnums TestValue = DefaultValue;
		TestValue = createTestFTbStructArrayStructWithArrayOfEnums();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropEnumArray(TestValue);
	});

	LatentIt("Property.PropEnumArray.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbStructArrayStructWithArrayOfEnums StartValue = ImplFixture->GetLocalImplementation()->GetPropEnumArray();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropEnumArray(), StartValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbStructArrayStructArrayFieldInterfacePublisher->OnPropEnumArrayChanged.AddLambda([this, TestDone](const FTbStructArrayStructWithArrayOfEnums& InPropEnumArray)
#else
		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		TbStructArrayStructArrayFieldInterfacePublisher->OnPropEnumArrayChanged.AddLambda([this, TestDone, StartValue](const FTbStructArrayStructWithArrayOfEnums& InPropEnumArray)
#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				FTbStructArrayStructWithArrayOfEnums TestValue = FTbStructArrayStructWithArrayOfEnums();
				// use different test value
				TestValue = createTestFTbStructArrayStructWithArrayOfEnums();
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnumArray, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropEnumArray(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropEnumArray(), TestValue);
#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropEnumArray(), StartValue);
#endif
				// now set it to the default value
				TestValue = FTbStructArrayStructWithArrayOfEnums(); // default value
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetPropEnumArray(TestValue);
#else
				ImplFixture->GetLocalImplementation()->SetPropEnumArray(TestValue);
#endif
			}
			else
			{
				FTbStructArrayStructWithArrayOfEnums TestValue = FTbStructArrayStructWithArrayOfEnums(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnumArray, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropEnumArray(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropEnumArray(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		FTbStructArrayStructWithArrayOfEnums TestValue = StartValue;
		TestValue = createTestFTbStructArrayStructWithArrayOfEnums();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropEnumArray(TestValue);
	});

	It("Property.PropIntArray.Default", [this]()
		{
		// Do implement test here
		FTbStructArrayStructWithArrayOfInts TestValue = FTbStructArrayStructWithArrayOfInts(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropIntArray(), TestValue);
	});

	LatentIt("Property.PropIntArray.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbStructArrayStructWithArrayOfInts TestValue = FTbStructArrayStructWithArrayOfInts(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropIntArray(), TestValue);

		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbStructArrayStructArrayFieldInterfacePublisher->OnPropIntArrayChanged.AddLambda([this, TestDone](const FTbStructArrayStructWithArrayOfInts& InPropIntArray)
			{
			FTbStructArrayStructWithArrayOfInts TestValue = FTbStructArrayStructWithArrayOfInts();
			// use different test value
			TestValue = createTestFTbStructArrayStructWithArrayOfInts();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropIntArray, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropIntArray(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTbStructArrayStructWithArrayOfInts();
		ImplFixture->GetClient()->SetPropIntArray(TestValue);
#if !(PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
#endif
	});

	LatentIt("Property.PropIntArray.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbStructArrayStructWithArrayOfInts DefaultValue = FTbStructArrayStructWithArrayOfInts(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropIntArray(), DefaultValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbStructArrayStructArrayFieldInterfacePublisher->OnPropIntArrayChanged.AddLambda([this, DefaultValue, TestDone](const FTbStructArrayStructWithArrayOfInts& InPropIntArray)
			{
			FTbStructArrayStructWithArrayOfInts TestValue = FTbStructArrayStructWithArrayOfInts();
			// use different test value
			TestValue = createTestFTbStructArrayStructWithArrayOfInts();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropIntArray, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropIntArray(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropIntArray(), TestValue);
#else
			TestEqual(TEXT("No connection, client has same value as at the start"), ImplFixture->GetClient()->GetPropIntArray(), DefaultValue);
#endif
			TestDone.Execute();
		});
		// use different test value, but init it first.
		FTbStructArrayStructWithArrayOfInts TestValue = DefaultValue;
		TestValue = createTestFTbStructArrayStructWithArrayOfInts();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropIntArray(TestValue);
	});

	LatentIt("Property.PropIntArray.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbStructArrayStructWithArrayOfInts StartValue = ImplFixture->GetLocalImplementation()->GetPropIntArray();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropIntArray(), StartValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbStructArrayStructArrayFieldInterfacePublisher->OnPropIntArrayChanged.AddLambda([this, TestDone](const FTbStructArrayStructWithArrayOfInts& InPropIntArray)
#else
		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		TbStructArrayStructArrayFieldInterfacePublisher->OnPropIntArrayChanged.AddLambda([this, TestDone, StartValue](const FTbStructArrayStructWithArrayOfInts& InPropIntArray)
#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				FTbStructArrayStructWithArrayOfInts TestValue = FTbStructArrayStructWithArrayOfInts();
				// use different test value
				TestValue = createTestFTbStructArrayStructWithArrayOfInts();
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropIntArray, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropIntArray(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropIntArray(), TestValue);
#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropIntArray(), StartValue);
#endif
				// now set it to the default value
				TestValue = FTbStructArrayStructWithArrayOfInts(); // default value
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetPropIntArray(TestValue);
#else
				ImplFixture->GetLocalImplementation()->SetPropIntArray(TestValue);
#endif
			}
			else
			{
				FTbStructArrayStructWithArrayOfInts TestValue = FTbStructArrayStructWithArrayOfInts(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropIntArray, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropIntArray(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropIntArray(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		FTbStructArrayStructWithArrayOfInts TestValue = StartValue;
		TestValue = createTestFTbStructArrayStructWithArrayOfInts();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropIntArray(TestValue);
	});

	It("Property.PropMixed.Default", [this]()
		{
		// Do implement test here
		FTbStructArrayMixedStruct TestValue = FTbStructArrayMixedStruct(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropMixed(), TestValue);
	});

	LatentIt("Property.PropMixed.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbStructArrayMixedStruct TestValue = FTbStructArrayMixedStruct(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropMixed(), TestValue);

		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbStructArrayStructArrayFieldInterfacePublisher->OnPropMixedChanged.AddLambda([this, TestDone](const FTbStructArrayMixedStruct& InPropMixed)
			{
			FTbStructArrayMixedStruct TestValue = FTbStructArrayMixedStruct();
			// use different test value
			TestValue = createTestFTbStructArrayMixedStruct();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropMixed, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropMixed(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTbStructArrayMixedStruct();
		ImplFixture->GetClient()->SetPropMixed(TestValue);
#if !(PLATFORM_ANDROID && USE_ANDROID_JNI)
		TestDone.Execute();
#endif
	});

	LatentIt("Property.PropMixed.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbStructArrayMixedStruct DefaultValue = FTbStructArrayMixedStruct(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropMixed(), DefaultValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbStructArrayStructArrayFieldInterfacePublisher->OnPropMixedChanged.AddLambda([this, DefaultValue, TestDone](const FTbStructArrayMixedStruct& InPropMixed)
			{
			FTbStructArrayMixedStruct TestValue = FTbStructArrayMixedStruct();
			// use different test value
			TestValue = createTestFTbStructArrayMixedStruct();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropMixed, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropMixed(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropMixed(), TestValue);
#else
			TestEqual(TEXT("No connection, client has same value as at the start"), ImplFixture->GetClient()->GetPropMixed(), DefaultValue);
#endif
			TestDone.Execute();
		});
		// use different test value, but init it first.
		FTbStructArrayMixedStruct TestValue = DefaultValue;
		TestValue = createTestFTbStructArrayMixedStruct();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropMixed(TestValue);
	});

	LatentIt("Property.PropMixed.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbStructArrayMixedStruct StartValue = ImplFixture->GetLocalImplementation()->GetPropMixed();
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetClient()->GetPropMixed(), StartValue);

#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
		TbStructArrayStructArrayFieldInterfacePublisher->OnPropMixedChanged.AddLambda([this, TestDone](const FTbStructArrayMixedStruct& InPropMixed)
#else
		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
		TbStructArrayStructArrayFieldInterfacePublisher->OnPropMixedChanged.AddLambda([this, TestDone, StartValue](const FTbStructArrayMixedStruct& InPropMixed)
#endif
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				FTbStructArrayMixedStruct TestValue = FTbStructArrayMixedStruct();
				// use different test value
				TestValue = createTestFTbStructArrayMixedStruct();
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropMixed, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropMixed(), TestValue);
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropMixed(), TestValue);
#else
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropMixed(), StartValue);
#endif
				// now set it to the default value
				TestValue = FTbStructArrayMixedStruct(); // default value
#if PLATFORM_ANDROID && USE_ANDROID_JNI
				ImplFixture->GetClient()->SetPropMixed(TestValue);
#else
				ImplFixture->GetLocalImplementation()->SetPropMixed(TestValue);
#endif
			}
			else
			{
				FTbStructArrayMixedStruct TestValue = FTbStructArrayMixedStruct(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropMixed, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetLocalImplementation()->GetPropMixed(), TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetClient()->GetPropMixed(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		FTbStructArrayMixedStruct TestValue = StartValue;
		TestValue = createTestFTbStructArrayMixedStruct();
		auto service = ImplFixture->GetLocalImplementation();
		service->SetPropMixed(TestValue);
	});

	LatentIt("Operation.FuncMixed", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->FuncMixed(FTbStructArrayMixedStruct());
			// Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncStructArray", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetClient()->FuncStructArray(FTbStructArrayStructWithArrayOfStructs());
			// Test will work also without connection, we always return default value. real check should test for custom, which is not possible for generated tests.
			TestDone.Execute();
		});
	});

	LatentIt("Signal.SigMixed", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbStructArrayStructArrayFieldInterfacePublisher* SourceTbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbStructArrayStructArrayFieldInterfacePublisher->OnSigMixedSignal.AddLambda([this, TestDone](const FTbStructArrayMixedStruct& InParamMixed)
			{
			// known test value
			FTbStructArrayMixedStruct ParamMixedTestValue = createTestFTbStructArrayMixedStruct();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamMixed, ParamMixedTestValue);
			TestDone.Execute();
		});

		// use different test value
		FTbStructArrayMixedStruct ParamMixedTestValue = createTestFTbStructArrayMixedStruct();
		SourceTbStructArrayStructArrayFieldInterfacePublisher->BroadcastSigMixedSignal(ParamMixedTestValue);
	});

	LatentIt("Signal.SigStructArray", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbStructArrayStructArrayFieldInterfacePublisher* SourceTbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetClient()->_GetPublisher();
#else
		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetLocalImplementation()->_GetPublisher();
#endif
		TbStructArrayStructArrayFieldInterfacePublisher->OnSigStructArraySignal.AddLambda([this, TestDone](const FTbStructArrayStructWithArrayOfStructs& InParamPoints)
			{
			// known test value
			FTbStructArrayStructWithArrayOfStructs ParamPointsTestValue = createTestFTbStructArrayStructWithArrayOfStructs();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamPoints, ParamPointsTestValue);
			TestDone.Execute();
		});

		// use different test value
		FTbStructArrayStructWithArrayOfStructs ParamPointsTestValue = createTestFTbStructArrayStructWithArrayOfStructs();
		SourceTbStructArrayStructArrayFieldInterfacePublisher->BroadcastSigStructArraySignal(ParamPointsTestValue);
	});
}
} // namespace Tests
} // namespace Jni
} // namespace StructArrayFieldInterface
} // namespace TbStructArray

#endif // WITH_DEV_AUTOMATION_TESTS
