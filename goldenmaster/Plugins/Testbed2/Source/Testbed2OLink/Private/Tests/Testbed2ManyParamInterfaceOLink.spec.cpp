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
#include "Testbed2ManyParamInterfaceOLinkFixture.h"
#include "Testbed2/Implementation/Testbed2ManyParamInterface.h"
#include "Testbed2/Generated/OLink/Testbed2ManyParamInterfaceOLinkClient.h"
#include "Testbed2/Generated/OLink/Testbed2ManyParamInterfaceOLinkAdapter.h"

#include "OLinkHost.h"
#include "OLinkClientConnection.h" // for olink factory
#include "Testbed2/Tests/Testbed2TestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed2
{
namespace ManyParamInterface
{
namespace OLink
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTestbed2ManyParamInterfaceOLinkSpec, "Testbed2.ManyParamInterface.OLink", Testbed2TestFilterMask);

TUniquePtr<FTestbed2ManyParamInterfaceOLinkFixture> ImplFixture;

END_DEFINE_SPEC(UTestbed2ManyParamInterfaceOLinkSpec);

void UTestbed2ManyParamInterfaceOLinkSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTestbed2ManyParamInterfaceOLinkFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// set up service and adapter
		ImplFixture->GetHost()->Stop();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed2ManyParamInterfaceImplementation>();
		ImplFixture->GetAdapter()->setBackendService(service);
		ImplFixture->GetAdapter()->setOLinkHost(ImplFixture->GetHost());
		ImplFixture->GetHost()->Start(8666);

		// setup client
		UTestbed2ManyParamInterfaceOLinkClient* OLinkClient = Cast<UTestbed2ManyParamInterfaceOLinkClient>(ImplFixture->GetImplementation().GetObject());
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

	It("Property.Prop1.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnProp1Changed.AddLambda([this, TestDone](int32 InProp1)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->SetProp1(TestValue);
	});

	LatentIt("Property.Prop1.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnProp1Changed.AddLambda([this, TestDone](int32 InProp1)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
			TestDone.Execute();
		});
		// use different test value
		TestValue = 1;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed2ManyParamInterfaceImplementation>();
		service->SetProp1(TestValue);
	});

	LatentIt("Property.Prop1.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnProp1Changed.AddLambda([this, TestDone](int32 InProp1)
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				int32 TestValue = 0;
				// use different test value
				TestValue = 1;
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

				// now set it to the default value
				TestValue = 0; // default value
				ImplFixture->GetImplementation()->SetProp1(TestValue);
			}
			else
			{
				int32 TestValue = 0; // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TestValue = 1;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed2ManyParamInterfaceImplementation>();
		service->SetProp1(TestValue);
	});

	It("Property.Prop2.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
	});

	LatentIt("Property.Prop2.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);

		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnProp2Changed.AddLambda([this, TestDone](int32 InProp2)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->SetProp2(TestValue);
	});

	LatentIt("Property.Prop2.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);

		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnProp2Changed.AddLambda([this, TestDone](int32 InProp2)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
			TestDone.Execute();
		});
		// use different test value
		TestValue = 1;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed2ManyParamInterfaceImplementation>();
		service->SetProp2(TestValue);
	});

	LatentIt("Property.Prop2.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);

		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnProp2Changed.AddLambda([this, TestDone](int32 InProp2)
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				int32 TestValue = 0;
				// use different test value
				TestValue = 1;
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp2(), TestValue);

				// now set it to the default value
				TestValue = 0; // default value
				ImplFixture->GetImplementation()->SetProp2(TestValue);
			}
			else
			{
				int32 TestValue = 0; // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TestValue = 1;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed2ManyParamInterfaceImplementation>();
		service->SetProp2(TestValue);
	});

	It("Property.Prop3.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp3(), TestValue);
	});

	LatentIt("Property.Prop3.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp3(), TestValue);

		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnProp3Changed.AddLambda([this, TestDone](int32 InProp3)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp3(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->SetProp3(TestValue);
	});

	LatentIt("Property.Prop3.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp3(), TestValue);

		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnProp3Changed.AddLambda([this, TestDone](int32 InProp3)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp3(), TestValue);
			TestDone.Execute();
		});
		// use different test value
		TestValue = 1;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed2ManyParamInterfaceImplementation>();
		service->SetProp3(TestValue);
	});

	LatentIt("Property.Prop3.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp3(), TestValue);

		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnProp3Changed.AddLambda([this, TestDone](int32 InProp3)
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				int32 TestValue = 0;
				// use different test value
				TestValue = 1;
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp3(), TestValue);

				// now set it to the default value
				TestValue = 0; // default value
				ImplFixture->GetImplementation()->SetProp3(TestValue);
			}
			else
			{
				int32 TestValue = 0; // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp3, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp3(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TestValue = 1;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed2ManyParamInterfaceImplementation>();
		service->SetProp3(TestValue);
	});

	It("Property.Prop4.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp4(), TestValue);
	});

	LatentIt("Property.Prop4.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp4(), TestValue);

		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnProp4Changed.AddLambda([this, TestDone](int32 InProp4)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp4, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp4(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->SetProp4(TestValue);
	});

	LatentIt("Property.Prop4.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp4(), TestValue);

		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnProp4Changed.AddLambda([this, TestDone](int32 InProp4)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp4, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp4(), TestValue);
			TestDone.Execute();
		});
		// use different test value
		TestValue = 1;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed2ManyParamInterfaceImplementation>();
		service->SetProp4(TestValue);
	});

	LatentIt("Property.Prop4.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp4(), TestValue);

		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnProp4Changed.AddLambda([this, TestDone](int32 InProp4)
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				int32 TestValue = 0;
				// use different test value
				TestValue = 1;
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp4, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp4(), TestValue);

				// now set it to the default value
				TestValue = 0; // default value
				ImplFixture->GetImplementation()->SetProp4(TestValue);
			}
			else
			{
				int32 TestValue = 0; // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp4, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp4(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TestValue = 1;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed2ManyParamInterfaceImplementation>();
		service->SetProp4(TestValue);
	});

	LatentIt("Operation.Func1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func1(0);
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func1Async", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		// Test async operation through OLink (client -> network -> server -> network -> client callback)
		TFuture<int32> Future = ImplFixture->GetImplementation()->Func1Async(0);

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const int32& Result)
			{
			// Verify values here based on service logic
			Done.Execute();
		});
	});

	LatentIt("Operation.Func2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func2(0, 0);
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func2Async", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		// Test async operation through OLink (client -> network -> server -> network -> client callback)
		TFuture<int32> Future = ImplFixture->GetImplementation()->Func2Async(0, 0);

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const int32& Result)
			{
			// Verify values here based on service logic
			Done.Execute();
		});
	});

	LatentIt("Operation.Func3", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func3(0, 0, 0);
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func3Async", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		// Test async operation through OLink (client -> network -> server -> network -> client callback)
		TFuture<int32> Future = ImplFixture->GetImplementation()->Func3Async(0, 0, 0);

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const int32& Result)
			{
			// Verify values here based on service logic
			Done.Execute();
		});
	});

	LatentIt("Operation.Func4", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func4(0, 0, 0, 0);
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func4Async", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		// Test async operation through OLink (client -> network -> server -> network -> client callback)
		TFuture<int32> Future = ImplFixture->GetImplementation()->Func4Async(0, 0, 0, 0);

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const int32& Result)
			{
			// Verify values here based on service logic
			Done.Execute();
		});
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnSig1Signal.AddLambda([this, TestDone](int32 InParam1)
			{
			// known test value
			int32 Param1TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			TestDone.Execute();
		});

		// use different test value
		int32 Param1TestValue = 1;
		Testbed2ManyParamInterfacePublisher->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnSig2Signal.AddLambda([this, TestDone](int32 InParam1, int32 InParam2)
			{
			// known test value
			int32 Param1TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			int32 Param2TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
			TestDone.Execute();
		});

		// use different test value
		int32 Param1TestValue = 1;
		int32 Param2TestValue = 1;
		Testbed2ManyParamInterfacePublisher->BroadcastSig2Signal(Param1TestValue, Param2TestValue);
	});

	LatentIt("Signal.Sig3", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnSig3Signal.AddLambda([this, TestDone](int32 InParam1, int32 InParam2, int32 InParam3)
			{
			// known test value
			int32 Param1TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			int32 Param2TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
			int32 Param3TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam3, Param3TestValue);
			TestDone.Execute();
		});

		// use different test value
		int32 Param1TestValue = 1;
		int32 Param2TestValue = 1;
		int32 Param3TestValue = 1;
		Testbed2ManyParamInterfacePublisher->BroadcastSig3Signal(Param1TestValue, Param2TestValue, Param3TestValue);
	});

	LatentIt("Signal.Sig4", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed2ManyParamInterfacePublisher* Testbed2ManyParamInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		Testbed2ManyParamInterfacePublisher->OnSig4Signal.AddLambda([this, TestDone](int32 InParam1, int32 InParam2, int32 InParam3, int32 InParam4)
			{
			// known test value
			int32 Param1TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			int32 Param2TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
			int32 Param3TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam3, Param3TestValue);
			int32 Param4TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam4, Param4TestValue);
			TestDone.Execute();
		});

		// use different test value
		int32 Param1TestValue = 1;
		int32 Param2TestValue = 1;
		int32 Param3TestValue = 1;
		int32 Param4TestValue = 1;
		Testbed2ManyParamInterfacePublisher->BroadcastSig4Signal(Param1TestValue, Param2TestValue, Param3TestValue, Param4TestValue);
	});
}
} // namespace Tests
} // namespace OLink
} // namespace ManyParamInterface
} // namespace Testbed2

#endif // WITH_DEV_AUTOMATION_TESTS
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
