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
#include "TbSame2SameStruct1InterfaceOLinkFixture.h"
#include "TbSame2/Implementation/TbSame2SameStruct1Interface.h"
#include "TbSame2/Generated/OLink/TbSame2SameStruct1InterfaceOLinkClient.h"
#include "TbSame2/Generated/OLink/TbSame2SameStruct1InterfaceOLinkAdapter.h"

#include "OLinkHost.h"
#include "OLinkClientConnection.h" // for olink factory
#include "TbSame2/Tests/TbSame2TestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame2
{
namespace SameStruct1Interface
{
namespace OLink
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbSame2SameStruct1InterfaceOLinkSpec, "TbSame2.SameStruct1Interface.OLink", TbSame2TestFilterMask);

TUniquePtr<FTbSame2SameStruct1InterfaceOLinkFixture> ImplFixture;

END_DEFINE_SPEC(UTbSame2SameStruct1InterfaceOLinkSpec);

void UTbSame2SameStruct1InterfaceOLinkSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbSame2SameStruct1InterfaceOLinkFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// set up service and adapter
		ImplFixture->GetHost()->Stop();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSame2SameStruct1InterfaceImplementation>();
		ImplFixture->GetAdapter()->setBackendService(service);
		ImplFixture->GetAdapter()->setOLinkHost(ImplFixture->GetHost());
		ImplFixture->GetHost()->Start(8666);

		// setup client
		UTbSame2SameStruct1InterfaceOLinkClient* OLinkClient = Cast<UTbSame2SameStruct1InterfaceOLinkClient>(ImplFixture->GetImplementation().GetObject());
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
		FTbSame2Struct1 TestValue = FTbSame2Struct1(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbSame2Struct1 TestValue = FTbSame2Struct1(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		UTbSame2SameStruct1InterfaceSignals* TbSame2SameStruct1InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame2SameStruct1InterfaceSignals->OnProp1Changed.AddLambda([this, TestDone](const FTbSame2Struct1& InProp1)
			{
			FTbSame2Struct1 TestValue = FTbSame2Struct1();
			// use different test value
			TestValue = createTestFTbSame2Struct1();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTbSame2Struct1();
		ImplFixture->GetImplementation()->SetProp1(TestValue);
	});

	LatentIt("Property.Prop1.ChangeLocalCheckRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbSame2Struct1 TestValue = FTbSame2Struct1(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		UTbSame2SameStruct1InterfaceSignals* TbSame2SameStruct1InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame2SameStruct1InterfaceSignals->OnProp1Changed.AddLambda([this, TestDone](const FTbSame2Struct1& InProp1)
			{
			FTbSame2Struct1 TestValue = FTbSame2Struct1();
			// use different test value
			TestValue = createTestFTbSame2Struct1();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
			TestDone.Execute();
		});
		// use different test value
		TestValue = createTestFTbSame2Struct1();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSame2SameStruct1InterfaceImplementation>();
		service->SetProp1(TestValue);
	});

	LatentIt("Property.Prop1.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbSame2Struct1 TestValue = FTbSame2Struct1(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		UTbSame2SameStruct1InterfaceSignals* TbSame2SameStruct1InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame2SameStruct1InterfaceSignals->OnProp1Changed.AddLambda([this, TestDone](const FTbSame2Struct1& InProp1)
			{
			// this function must be called twice before we can successfully pass this test.
			// first call it should have the test value of the parameter
			// second call it should have the default value of the parameter again
			static int count = 0;
			count++;

			if (count % 2 != 0)
			{
				FTbSame2Struct1 TestValue = FTbSame2Struct1();
				// use different test value
				TestValue = createTestFTbSame2Struct1();
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

				// now set it to the default value
				TestValue = FTbSame2Struct1(); // default value
				ImplFixture->GetImplementation()->SetProp1(TestValue);
			}
			else
			{
				FTbSame2Struct1 TestValue = FTbSame2Struct1(); // default value
				TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
				TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
				TestDone.Execute();
			}
		});
		// use different test value
		TestValue = createTestFTbSame2Struct1();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSame2SameStruct1InterfaceImplementation>();
		service->SetProp1(TestValue);
	});

	LatentIt("Operation.Func1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func1(FTbSame2Struct1());
			TestDone.Execute();
		});
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSame2SameStruct1InterfaceSignals* TbSame2SameStruct1InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame2SameStruct1InterfaceSignals->OnSig1Signal.AddLambda([this, TestDone](const FTbSame2Struct1& InParam1)
			{
			// known test value
			FTbSame2Struct1 Param1TestValue = createTestFTbSame2Struct1();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			TestDone.Execute();
		});

		// use different test value
		FTbSame2Struct1 Param1TestValue = createTestFTbSame2Struct1();
		TbSame2SameStruct1InterfaceSignals->BroadcastSig1Signal(Param1TestValue);
	});
}
} // namespace Tests
} // namespace OLink
} // namespace SameStruct1Interface
} // namespace TbSame2

#endif // WITH_DEV_AUTOMATION_TESTS
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
