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

#include "TbSame1/Tests/TbSame1TestsCommon.h"
#include "TbSame1/Implementation/TbSame1SameEnum1Interface.h"
#include "TbSame1SameEnum1InterfaceMsgBusFixture.h"
#include "TbSame1/Generated/MsgBus/TbSame1SameEnum1InterfaceMsgBusClient.h"
#include "TbSame1/Generated/MsgBus/TbSame1SameEnum1InterfaceMsgBusAdapter.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame1
{
namespace SameEnum1Interface
{
namespace MsgBus
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbSame1SameEnum1InterfaceMsgBusSpec, "TbSame1.SameEnum1Interface.MsgBus", TbSame1TestFilterMask);

TUniquePtr<FTbSame1SameEnum1InterfaceMsgBusFixture> ImplFixture;

END_DEFINE_SPEC(UTbSame1SameEnum1InterfaceMsgBusSpec);

void UTbSame1SameEnum1InterfaceMsgBusSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbSame1SameEnum1InterfaceMsgBusFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// set up service and adapter
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSame1SameEnum1InterfaceImplementation>();
		ImplFixture->GetAdapter()->_setBackendService(service);
		ImplFixture->GetAdapter()->_StartListening();

		// setup client
		UTbSame1SameEnum1InterfaceMsgBusClient* MsgBusClient = Cast<UTbSame1SameEnum1InterfaceMsgBusClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid MsgBus client", MsgBusClient != nullptr);

		MsgBusClient->_ConnectionStatusChanged.AddLambda([this, TestDone](bool bConnected)
			{
			if (bConnected)
			{
				TestDone.Execute();
			}
		});

		MsgBusClient->_Connect();
	});

	AfterEach([this]()
		{
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

		UTbSame1SameEnum1InterfacePublisher* TbSame1SameEnum1InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSame1SameEnum1InterfacePublisher->OnProp1Changed.AddLambda([this, TestDone](ETbSame1Enum1 InProp1)
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

		UTbSame1SameEnum1InterfacePublisher* TbSame1SameEnum1InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSame1SameEnum1InterfacePublisher->OnProp1Changed.AddLambda([this, TestDone](ETbSame1Enum1 InProp1)
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
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSame1SameEnum1InterfaceImplementation>();
		service->SetProp1(TestValue);
	});

	LatentIt("Property.Prop1.ChangeLocalChangeBackRemote", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		ETbSame1Enum1 TestValue = ETbSame1Enum1::TS1E1_Value1; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		UTbSame1SameEnum1InterfacePublisher* TbSame1SameEnum1InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSame1SameEnum1InterfacePublisher->OnProp1Changed.AddLambda([this, TestDone](ETbSame1Enum1 InProp1)
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
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSame1SameEnum1InterfaceImplementation>();
		service->SetProp1(TestValue);
	});

	LatentIt("Operation.Func1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func1(ETbSame1Enum1::TS1E1_Value1);
			TestDone.Execute();
		});
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSame1SameEnum1InterfacePublisher* TbSame1SameEnum1InterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSame1SameEnum1InterfacePublisher->OnSig1Signal.AddLambda([this, TestDone](ETbSame1Enum1 InParam1)
			{
			// known test value
			ETbSame1Enum1 Param1TestValue = ETbSame1Enum1::TS1E1_Value2;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			TestDone.Execute();
		});

		// use different test value
		ETbSame1Enum1 Param1TestValue = ETbSame1Enum1::TS1E1_Value2;
		TbSame1SameEnum1InterfacePublisher->BroadcastSig1Signal(Param1TestValue);
	});
}
} // namespace Tests
} // namespace MsgBus
} // namespace SameEnum1Interface
} // namespace TbSame1

#endif // WITH_DEV_AUTOMATION_TESTS
