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
#include "HAL/Platform.h"

#if !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
#include "TbStructArrayStructArrayFieldInterfaceOLinkFixture.h"
#include "TbStructArray/Implementation/TbStructArrayStructArrayFieldInterface.h"
#include "TbStructArray/Generated/OLink/TbStructArrayStructArrayFieldInterfaceOLinkClient.h"
#include "TbStructArray/Generated/OLink/TbStructArrayStructArrayFieldInterfaceOLinkAdapter.h"

#include "OLinkHost.h"
#include "OLinkClientConnection.h" // for olink factory
#include "TbStructArray/Tests/TbStructArrayTestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbStructArray
{
namespace StructArrayFieldInterface
{
namespace OLink
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbStructArrayStructArrayFieldInterfaceOLinkSpec, "TbStructArray.StructArrayFieldInterface.OLink", TbStructArrayTestFilterMask);

TUniquePtr<FTbStructArrayStructArrayFieldInterfaceOLinkFixture> ImplFixture;

END_DEFINE_SPEC(UTbStructArrayStructArrayFieldInterfaceOLinkSpec);

void UTbStructArrayStructArrayFieldInterfaceOLinkSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbStructArrayStructArrayFieldInterfaceOLinkFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// set up service and adapter
		ImplFixture->GetHost()->Stop();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbStructArrayStructArrayFieldInterfaceImplementation>();
		ImplFixture->GetAdapter()->setBackendService(service);
		ImplFixture->GetAdapter()->setOLinkHost(ImplFixture->GetHost());
		ImplFixture->GetHost()->Start(8666);

		// setup client
		UTbStructArrayStructArrayFieldInterfaceOLinkClient* OLinkClient = Cast<UTbStructArrayStructArrayFieldInterfaceOLinkClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid OLink client", OLinkClient != nullptr);

		OLinkClient->_SubscriptionStatusChanged.AddLambda([this, TestDone](bool bSubscribed)
			{
			if (bSubscribed)
			{
				TestDone.Execute();
			}
		});

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

	LatentIt("Property.PropStructArray.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
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
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbStructArrayStructArrayFieldInterfaceImplementation>();
		service->SetPropStructArray(TestValue);
	});

	LatentIt("Property.PropStructArray.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbStructArrayStructWithArrayOfStructs TestValue = FTbStructArrayStructWithArrayOfStructs(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropStructArray(), TestValue);

		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbStructArrayStructArrayFieldInterfacePublisher->OnPropStructArrayChanged.AddLambda([this, TestDone](const FTbStructArrayStructWithArrayOfStructs& InPropStructArray)
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
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropStructArray(), TestValue);

				// now set it to the default value
				TestValue = FTbStructArrayStructWithArrayOfStructs(); // default value
				ImplFixture->GetImplementation()->SetPropStructArray(TestValue);
			}
			else
			{
				FTbStructArrayStructWithArrayOfStructs TestValue = FTbStructArrayStructWithArrayOfStructs(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropStructArray, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropStructArray(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TestValue = createTestFTbStructArrayStructWithArrayOfStructs();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbStructArrayStructArrayFieldInterfaceImplementation>();
		service->SetPropStructArray(TestValue);
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

	LatentIt("Property.PropEnumArray.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
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
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbStructArrayStructArrayFieldInterfaceImplementation>();
		service->SetPropEnumArray(TestValue);
	});

	LatentIt("Property.PropEnumArray.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbStructArrayStructWithArrayOfEnums TestValue = FTbStructArrayStructWithArrayOfEnums(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropEnumArray(), TestValue);

		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbStructArrayStructArrayFieldInterfacePublisher->OnPropEnumArrayChanged.AddLambda([this, TestDone](const FTbStructArrayStructWithArrayOfEnums& InPropEnumArray)
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
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropEnumArray(), TestValue);

				// now set it to the default value
				TestValue = FTbStructArrayStructWithArrayOfEnums(); // default value
				ImplFixture->GetImplementation()->SetPropEnumArray(TestValue);
			}
			else
			{
				FTbStructArrayStructWithArrayOfEnums TestValue = FTbStructArrayStructWithArrayOfEnums(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropEnumArray, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropEnumArray(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TestValue = createTestFTbStructArrayStructWithArrayOfEnums();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbStructArrayStructArrayFieldInterfaceImplementation>();
		service->SetPropEnumArray(TestValue);
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

	LatentIt("Property.PropIntArray.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
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
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbStructArrayStructArrayFieldInterfaceImplementation>();
		service->SetPropIntArray(TestValue);
	});

	LatentIt("Property.PropIntArray.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbStructArrayStructWithArrayOfInts TestValue = FTbStructArrayStructWithArrayOfInts(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropIntArray(), TestValue);

		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbStructArrayStructArrayFieldInterfacePublisher->OnPropIntArrayChanged.AddLambda([this, TestDone](const FTbStructArrayStructWithArrayOfInts& InPropIntArray)
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
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropIntArray(), TestValue);

				// now set it to the default value
				TestValue = FTbStructArrayStructWithArrayOfInts(); // default value
				ImplFixture->GetImplementation()->SetPropIntArray(TestValue);
			}
			else
			{
				FTbStructArrayStructWithArrayOfInts TestValue = FTbStructArrayStructWithArrayOfInts(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropIntArray, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropIntArray(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TestValue = createTestFTbStructArrayStructWithArrayOfInts();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbStructArrayStructArrayFieldInterfaceImplementation>();
		service->SetPropIntArray(TestValue);
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

	LatentIt("Property.PropMixed.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
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
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbStructArrayStructArrayFieldInterfaceImplementation>();
		service->SetPropMixed(TestValue);
	});

	LatentIt("Property.PropMixed.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbStructArrayMixedStruct TestValue = FTbStructArrayMixedStruct(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropMixed(), TestValue);

		UTbStructArrayStructArrayFieldInterfacePublisher* TbStructArrayStructArrayFieldInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbStructArrayStructArrayFieldInterfacePublisher->OnPropMixedChanged.AddLambda([this, TestDone](const FTbStructArrayMixedStruct& InPropMixed)
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
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropMixed(), TestValue);

				// now set it to the default value
				TestValue = FTbStructArrayMixedStruct(); // default value
				ImplFixture->GetImplementation()->SetPropMixed(TestValue);
			}
			else
			{
				FTbStructArrayMixedStruct TestValue = FTbStructArrayMixedStruct(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropMixed, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropMixed(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TestValue = createTestFTbStructArrayMixedStruct();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbStructArrayStructArrayFieldInterfaceImplementation>();
		service->SetPropMixed(TestValue);
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

	LatentIt("Operation.FuncMixedAsync", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		// Test async operation through OLink (client -> network -> server -> network -> client callback)
		TFuture<FTbStructArrayMixedStruct> Future = ImplFixture->GetImplementation()->FuncMixedAsync(FTbStructArrayMixedStruct());

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const FTbStructArrayMixedStruct& Result)
			{
			// Verify values here based on service logic
			Done.Execute();
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

	LatentIt("Operation.FuncStructArrayAsync", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		// Test async operation through OLink (client -> network -> server -> network -> client callback)
		TFuture<FTbStructArrayStructWithArrayOfStructs> Future = ImplFixture->GetImplementation()->FuncStructArrayAsync(FTbStructArrayStructWithArrayOfStructs());

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const FTbStructArrayStructWithArrayOfStructs& Result)
			{
			// Verify values here based on service logic
			Done.Execute();
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
} // namespace OLink
} // namespace StructArrayFieldInterface
} // namespace TbStructArray

#endif // WITH_DEV_AUTOMATION_TESTS
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
