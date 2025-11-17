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
#include "TbSame1SameEnum2InterfaceOLinkFixture.h"
#include "TbSame1/Implementation/TbSame1SameEnum2Interface.h"
#include "TbSame1/Generated/OLink/TbSame1SameEnum2InterfaceOLinkClient.h"
#include "TbSame1/Generated/OLink/TbSame1SameEnum2InterfaceOLinkAdapter.h"

#include "OLinkHost.h"
#include "OLinkClientConnection.h" // for olink factory
#include "TbSame1/Tests/TbSame1TestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame1
{
namespace SameEnum2Interface
{
namespace OLink
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbSame1SameEnum2InterfaceOLinkSpec, "TbSame1.SameEnum2Interface.OLink", TbSame1TestFilterMask);

TUniquePtr<FTbSame1SameEnum2InterfaceOLinkFixture> ImplFixture;

END_DEFINE_SPEC(UTbSame1SameEnum2InterfaceOLinkSpec);

void UTbSame1SameEnum2InterfaceOLinkSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbSame1SameEnum2InterfaceOLinkFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// set up service and adapter
		ImplFixture->GetHost()->Stop();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSame1SameEnum2InterfaceImplementation>();
		ImplFixture->GetAdapter()->setBackendService(service);
		ImplFixture->GetAdapter()->setOLinkHost(ImplFixture->GetHost());
		ImplFixture->GetHost()->Start(8666);

		// setup client
		UTbSame1SameEnum2InterfaceOLinkClient* OLinkClient = Cast<UTbSame1SameEnum2InterfaceOLinkClient>(ImplFixture->GetImplementation().GetObject());
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
		ETbSame1Enum1 TestValue = ETbSame1Enum1::TS1E1_Value1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbSame1Enum1 TestValue = ETbSame1Enum1::TS1E1_Value1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		UTbSame1SameEnum2InterfacePublisher* TbSame1SameEnum2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSame1SameEnum2InterfacePublisher->OnProp1Changed.AddLambda([this, TestDone](ETbSame1Enum1 InProp1)
			{
			ETbSame1Enum1 TestValue = ETbSame1Enum1::TS1E1_Value1;
			// use different test value
			TestValue = ETbSame1Enum1::TS1E1_Value2;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = ETbSame1Enum1::TS1E1_Value2;
		ImplFixture->GetImplementation()->SetProp1(TestValue);
	});

	LatentIt("Property.Prop1.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbSame1Enum1 TestValue = ETbSame1Enum1::TS1E1_Value1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		UTbSame1SameEnum2InterfacePublisher* TbSame1SameEnum2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSame1SameEnum2InterfacePublisher->OnProp1Changed.AddLambda([this, TestDone](ETbSame1Enum1 InProp1)
			{
			ETbSame1Enum1 TestValue = ETbSame1Enum1::TS1E1_Value1;
			// use different test value
			TestValue = ETbSame1Enum1::TS1E1_Value2;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
			TestDone.Execute();
		});
		// use different test value
		TestValue = ETbSame1Enum1::TS1E1_Value2;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSame1SameEnum2InterfaceImplementation>();
		service->SetProp1(TestValue);
	});

	LatentIt("Property.Prop1.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbSame1Enum1 TestValue = ETbSame1Enum1::TS1E1_Value1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		UTbSame1SameEnum2InterfacePublisher* TbSame1SameEnum2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSame1SameEnum2InterfacePublisher->OnProp1Changed.AddLambda([this, TestDone](ETbSame1Enum1 InProp1)
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				ETbSame1Enum1 TestValue = ETbSame1Enum1::TS1E1_Value1;
				// use different test value
				TestValue = ETbSame1Enum1::TS1E1_Value2;
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

				// now set it to the default value
				TestValue = ETbSame1Enum1::TS1E1_Value1; // default value
				ImplFixture->GetImplementation()->SetProp1(TestValue);
			}
			else
			{
				ETbSame1Enum1 TestValue = ETbSame1Enum1::TS1E1_Value1; // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TestValue = ETbSame1Enum1::TS1E1_Value2;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSame1SameEnum2InterfaceImplementation>();
		service->SetProp1(TestValue);
	});

	It("Property.Prop2.Default", [this]()
		{
		// Do implement test here
		ETbSame1Enum2 TestValue = ETbSame1Enum2::TS1E2_Value1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
	});

	LatentIt("Property.Prop2.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbSame1Enum2 TestValue = ETbSame1Enum2::TS1E2_Value1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);

		UTbSame1SameEnum2InterfacePublisher* TbSame1SameEnum2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSame1SameEnum2InterfacePublisher->OnProp2Changed.AddLambda([this, TestDone](ETbSame1Enum2 InProp2)
			{
			ETbSame1Enum2 TestValue = ETbSame1Enum2::TS1E2_Value1;
			// use different test value
			TestValue = ETbSame1Enum2::TS1E2_Value2;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = ETbSame1Enum2::TS1E2_Value2;
		ImplFixture->GetImplementation()->SetProp2(TestValue);
	});

	LatentIt("Property.Prop2.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbSame1Enum2 TestValue = ETbSame1Enum2::TS1E2_Value1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);

		UTbSame1SameEnum2InterfacePublisher* TbSame1SameEnum2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSame1SameEnum2InterfacePublisher->OnProp2Changed.AddLambda([this, TestDone](ETbSame1Enum2 InProp2)
			{
			ETbSame1Enum2 TestValue = ETbSame1Enum2::TS1E2_Value1;
			// use different test value
			TestValue = ETbSame1Enum2::TS1E2_Value2;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
			TestDone.Execute();
		});
		// use different test value
		TestValue = ETbSame1Enum2::TS1E2_Value2;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSame1SameEnum2InterfaceImplementation>();
		service->SetProp2(TestValue);
	});

	LatentIt("Property.Prop2.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbSame1Enum2 TestValue = ETbSame1Enum2::TS1E2_Value1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);

		UTbSame1SameEnum2InterfacePublisher* TbSame1SameEnum2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSame1SameEnum2InterfacePublisher->OnProp2Changed.AddLambda([this, TestDone](ETbSame1Enum2 InProp2)
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				ETbSame1Enum2 TestValue = ETbSame1Enum2::TS1E2_Value1;
				// use different test value
				TestValue = ETbSame1Enum2::TS1E2_Value2;
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp2(), TestValue);

				// now set it to the default value
				TestValue = ETbSame1Enum2::TS1E2_Value1; // default value
				ImplFixture->GetImplementation()->SetProp2(TestValue);
			}
			else
			{
				ETbSame1Enum2 TestValue = ETbSame1Enum2::TS1E2_Value1; // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TestValue = ETbSame1Enum2::TS1E2_Value2;
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSame1SameEnum2InterfaceImplementation>();
		service->SetProp2(TestValue);
	});

	LatentIt("Operation.Func1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func1(ETbSame1Enum1::TS1E1_Value1);
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func1Async", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		// Test async operation through OLink (client -> network -> server -> network -> client callback)
		TFuture<ETbSame1Enum1> Future = ImplFixture->GetImplementation()->Func1Async(ETbSame1Enum1::TS1E1_Value1);

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const ETbSame1Enum1& Result)
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
			ImplFixture->GetImplementation()->Func2(ETbSame1Enum1::TS1E1_Value1, ETbSame1Enum2::TS1E2_Value1);
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func2Async", EAsyncExecution::ThreadPool, [this](const FDoneDelegate& TestDone)
		{
		// Test async operation through OLink (client -> network -> server -> network -> client callback)
		TFuture<ETbSame1Enum1> Future = ImplFixture->GetImplementation()->Func2Async(ETbSame1Enum1::TS1E1_Value1, ETbSame1Enum2::TS1E2_Value1);

		const FDoneDelegate Done = TestDone;
		Future.Next([this, Done](const ETbSame1Enum1& Result)
			{
			// Verify values here based on service logic
			Done.Execute();
		});
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSame1SameEnum2InterfacePublisher* TbSame1SameEnum2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSame1SameEnum2InterfacePublisher->OnSig1Signal.AddLambda([this, TestDone](ETbSame1Enum1 InParam1)
			{
			// known test value
			ETbSame1Enum1 Param1TestValue = ETbSame1Enum1::TS1E1_Value2;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			TestDone.Execute();
		});

		// use different test value
		ETbSame1Enum1 Param1TestValue = ETbSame1Enum1::TS1E1_Value2;
		TbSame1SameEnum2InterfacePublisher->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSame1SameEnum2InterfacePublisher* TbSame1SameEnum2InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSame1SameEnum2InterfacePublisher->OnSig2Signal.AddLambda([this, TestDone](ETbSame1Enum1 InParam1, ETbSame1Enum2 InParam2)
			{
			// known test value
			ETbSame1Enum1 Param1TestValue = ETbSame1Enum1::TS1E1_Value2;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			ETbSame1Enum2 Param2TestValue = ETbSame1Enum2::TS1E2_Value2;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
			TestDone.Execute();
		});

		// use different test value
		ETbSame1Enum1 Param1TestValue = ETbSame1Enum1::TS1E1_Value2;
		ETbSame1Enum2 Param2TestValue = ETbSame1Enum2::TS1E2_Value2;
		TbSame1SameEnum2InterfacePublisher->BroadcastSig2Signal(Param1TestValue, Param2TestValue);
	});
}
} // namespace Tests
} // namespace OLink
} // namespace SameEnum2Interface
} // namespace TbSame1

#endif // WITH_DEV_AUTOMATION_TESTS
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
