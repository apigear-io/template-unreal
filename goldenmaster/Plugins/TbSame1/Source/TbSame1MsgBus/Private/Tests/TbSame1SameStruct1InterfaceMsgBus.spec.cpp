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
#include "HAL/Platform.h"

#if !(PLATFORM_IOS || PLATFORM_ANDROID)
#if WITH_DEV_AUTOMATION_TESTS

#include "TbSame1/Tests/TbSame1TestsCommon.h"
#include "TbSame1/Implementation/TbSame1SameStruct1Interface.h"
#include "TbSame1SameStruct1InterfaceMsgBusFixture.h"
#include "TbSame1/Generated/MsgBus/TbSame1SameStruct1InterfaceMsgBusClient.h"
#include "TbSame1/Generated/MsgBus/TbSame1SameStruct1InterfaceMsgBusAdapter.h"

BEGIN_DEFINE_SPEC(UTbSame1SameStruct1InterfaceMsgBusSpec, "TbSame1.SameStruct1Interface.MsgBus", TbSame1TestFilterMask);

TUniquePtr<FTbSame1SameStruct1InterfaceMsgBusFixture> ImplFixture;

END_DEFINE_SPEC(UTbSame1SameStruct1InterfaceMsgBusSpec);

void UTbSame1SameStruct1InterfaceMsgBusSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbSame1SameStruct1InterfaceMsgBusFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// set up service and adapter
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSame1SameStruct1Interface>();
		ImplFixture->GetAdapter()->_setBackendService(service);
		ImplFixture->GetAdapter()->_StartListening();

		// setup client
		UTbSame1SameStruct1InterfaceMsgBusClient* MsgBusClient = Cast<UTbSame1SameStruct1InterfaceMsgBusClient>(ImplFixture->GetImplementation().GetObject());
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
		FTbSame1Struct1 TestValue = FTbSame1Struct1(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbSame1Struct1 TestValue = FTbSame1Struct1(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		UTbSame1SameStruct1InterfaceSignals* TbSame1SameStruct1InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame1SameStruct1InterfaceSignals->OnProp1Changed.AddLambda([this, TestDone](const FTbSame1Struct1& InProp1)
			{
			FTbSame1Struct1 TestValue = FTbSame1Struct1();
			// use different test value
			TestValue = createTestFTbSame1Struct1();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTbSame1Struct1();
		ImplFixture->GetImplementation()->SetProp1(TestValue);
	});

	LatentIt("Operation.Func1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func1(FTbSame1Struct1());
			TestDone.Execute();
		});
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSame1SameStruct1InterfaceSignals* TbSame1SameStruct1InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame1SameStruct1InterfaceSignals->OnSig1Signal.AddLambda([this, TestDone](const FTbSame1Struct1& InParam1)
			{
			// known test value
			FTbSame1Struct1 Param1TestValue = createTestFTbSame1Struct1();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			TestDone.Execute();
		});

		// use different test value
		FTbSame1Struct1 Param1TestValue = createTestFTbSame1Struct1();
		TbSame1SameStruct1InterfaceSignals->BroadcastSig1Signal(Param1TestValue);
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID)
