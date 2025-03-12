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

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "TbSame2SameStruct2InterfaceOLinkFixture.h"
#include "TbSame2/Implementation/TbSame2SameStruct2Interface.h"
#include "TbSame2/Generated/OLink/TbSame2SameStruct2InterfaceOLinkClient.h"
#include "TbSame2/Generated/OLink/TbSame2SameStruct2InterfaceOLinkAdapter.h"

#include "OLinkHost.h"
#include "OLinkClientConnection.h" // for olink factory
#include "TbSame2/Tests/TbSame2TestsCommon.h"

BEGIN_DEFINE_SPEC(UTbSame2SameStruct2InterfaceOLinkSpec, "TbSame2.SameStruct2Interface.OLink", TbSame2TestFilterMask);

TUniquePtr<FTbSame2SameStruct2InterfaceOLinkFixture> ImplFixture;

END_DEFINE_SPEC(UTbSame2SameStruct2InterfaceOLinkSpec);

void UTbSame2SameStruct2InterfaceOLinkSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbSame2SameStruct2InterfaceOLinkFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// set up service and adapter
		ImplFixture->GetHost()->Stop();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSame2SameStruct2Interface>();
		ImplFixture->GetAdapter()->setBackendService(service);
		ImplFixture->GetAdapter()->setOLinkHost(ImplFixture->GetHost());
		ImplFixture->GetHost()->Start(8666);

		// setup client
		UTbSame2SameStruct2InterfaceOLinkClient* OLinkClient = Cast<UTbSame2SameStruct2InterfaceOLinkClient>(ImplFixture->GetImplementation().GetObject());
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
		FTbSame2Struct2 TestValue = FTbSame2Struct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbSame2Struct2 TestValue = FTbSame2Struct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		UTbSame2SameStruct2InterfaceSignals* TbSame2SameStruct2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame2SameStruct2InterfaceSignals->OnProp1Changed.AddLambda([this, TestDone](const FTbSame2Struct2& InProp1){
			FTbSame2Struct2 TestValue = FTbSame2Struct2();
			// use different test value
			TestValue = createTestFTbSame2Struct2();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp1, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTbSame2Struct2();
		ImplFixture->GetImplementation()->SetProp1(TestValue);
	});

	It("Property.Prop2.Default", [this]()
		{
		// Do implement test here
		FTbSame2Struct2 TestValue = FTbSame2Struct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
	});

	LatentIt("Property.Prop2.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTbSame2Struct2 TestValue = FTbSame2Struct2(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp2(), TestValue);

		UTbSame2SameStruct2InterfaceSignals* TbSame2SameStruct2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame2SameStruct2InterfaceSignals->OnProp2Changed.AddLambda([this, TestDone](const FTbSame2Struct2& InProp2){
			FTbSame2Struct2 TestValue = FTbSame2Struct2();
			// use different test value
			TestValue = createTestFTbSame2Struct2();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InProp2, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetProp2(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTbSame2Struct2();
		ImplFixture->GetImplementation()->SetProp2(TestValue);
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

	LatentIt("Operation.Func2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func2(FTbSame2Struct1(), FTbSame2Struct2());
			TestDone.Execute();
		});
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSame2SameStruct2InterfaceSignals* TbSame2SameStruct2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame2SameStruct2InterfaceSignals->OnSig1Signal.AddLambda([this, TestDone](const FTbSame2Struct1& InParam1){
			// known test value
			FTbSame2Struct1 Param1TestValue = createTestFTbSame2Struct1();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			TestDone.Execute();
		});

		// use different test value
		FTbSame2Struct1 Param1TestValue = createTestFTbSame2Struct1();
		TbSame2SameStruct2InterfaceSignals->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSame2SameStruct2InterfaceSignals* TbSame2SameStruct2InterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSame2SameStruct2InterfaceSignals->OnSig2Signal.AddLambda([this, TestDone](const FTbSame2Struct1& InParam1, const FTbSame2Struct2& InParam2){
			// known test value
			FTbSame2Struct1 Param1TestValue = createTestFTbSame2Struct1();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			FTbSame2Struct2 Param2TestValue = createTestFTbSame2Struct2();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam2, Param2TestValue);
			TestDone.Execute();
		});

		// use different test value
		FTbSame2Struct1 Param1TestValue = createTestFTbSame2Struct1();
		FTbSame2Struct2 Param2TestValue = createTestFTbSame2Struct2();
		TbSame2SameStruct2InterfaceSignals->BroadcastSig2Signal(Param1TestValue, Param2TestValue);
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
