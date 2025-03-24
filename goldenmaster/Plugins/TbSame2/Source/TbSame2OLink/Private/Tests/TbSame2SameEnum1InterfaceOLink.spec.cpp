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
#include "TbSame2SameEnum1InterfaceOLinkFixture.h"
#include "TbSame2/Implementation/TbSame2SameEnum1Interface.h"
#include "TbSame2/Generated/OLink/TbSame2SameEnum1InterfaceOLinkClient.h"
#include "TbSame2/Generated/OLink/TbSame2SameEnum1InterfaceOLinkAdapter.h"

#include "OLinkHost.h"
#include "OLinkClientConnection.h" // for olink factory
#include "TbSame2/Tests/TbSame2TestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame2
{
namespace SameEnum1Interface
{
namespace OLink
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbSame2SameEnum1InterfaceOLinkSpec, "TbSame2.SameEnum1Interface.OLink", TbSame2TestFilterMask);

TUniquePtr<FTbSame2SameEnum1InterfaceOLinkFixture> ImplFixture;

END_DEFINE_SPEC(UTbSame2SameEnum1InterfaceOLinkSpec);

void UTbSame2SameEnum1InterfaceOLinkSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbSame2SameEnum1InterfaceOLinkFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// set up service and adapter
		ImplFixture->GetHost()->Stop();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSame2SameEnum1Interface>();
		ImplFixture->GetAdapter()->setBackendService(service);
		ImplFixture->GetAdapter()->setOLinkHost(ImplFixture->GetHost());
		ImplFixture->GetHost()->Start(8666);

		// setup client
		UTbSame2SameEnum1InterfaceOLinkClient* OLinkClient = Cast<UTbSame2SameEnum1InterfaceOLinkClient>(ImplFixture->GetImplementation().GetObject());
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

	It("Property.Prop1.Default", [this]()
		{
		// Do implement test here
		ETbSame2Enum1 TestValue = ETbSame2Enum1::TS2E1_VALUE1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbSame2Enum1 TestValue = ETbSame2Enum1::TS2E1_VALUE1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		UTbSame2SameEnum1InterfaceSignals* TbSame2SameEnum1InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame2SameEnum1InterfaceSignals->OnProp1Changed.AddLambda([this, TestDone](ETbSame2Enum1 InProp1)
			{
			ETbSame2Enum1 TestValue = ETbSame2Enum1::TS2E1_VALUE1;
			// use different test value
			TestValue = ETbSame2Enum1::TS2E1_VALUE2;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = ETbSame2Enum1::TS2E1_VALUE2;
		ImplFixture->GetImplementation()->SetProp1(TestValue);
	});

	LatentIt("Operation.Func1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func1(ETbSame2Enum1::TS2E1_VALUE1);
			TestDone.Execute();
		});
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSame2SameEnum1InterfaceSignals* TbSame2SameEnum1InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame2SameEnum1InterfaceSignals->OnSig1Signal.AddLambda([this, TestDone](ETbSame2Enum1 InParam1)
			{
			// known test value
			ETbSame2Enum1 Param1TestValue = ETbSame2Enum1::TS2E1_VALUE2;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			TestDone.Execute();
		});

		// use different test value
		ETbSame2Enum1 Param1TestValue = ETbSame2Enum1::TS2E1_VALUE2;
		TbSame2SameEnum1InterfaceSignals->BroadcastSig1Signal(Param1TestValue);
	});
}
} // namespace Tests
} // namespace OLink
} // namespace SameEnum1Interface
} // namespace TbSame2

#endif // WITH_DEV_AUTOMATION_TESTS
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
