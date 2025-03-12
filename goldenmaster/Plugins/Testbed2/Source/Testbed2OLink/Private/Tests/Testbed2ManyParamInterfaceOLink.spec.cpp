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
#include "Testbed2ManyParamInterfaceOLinkFixture.h"
#include "Testbed2/Implementation/Testbed2ManyParamInterface.h"
#include "Testbed2/Generated/OLink/Testbed2ManyParamInterfaceOLinkClient.h"
#include "Testbed2/Generated/OLink/Testbed2ManyParamInterfaceOLinkAdapter.h"

#include "OLinkHost.h"
#include "OLinkClientConnection.h" // for olink factory
#include "Testbed2/Tests/Testbed2TestsCommon.h"

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
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed2ManyParamInterface>();
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
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);
	});

	LatentIt("Property.Prop1.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetProp1(), TestValue);

		UTestbed2ManyParamInterfaceSignals* Testbed2ManyParamInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed2ManyParamInterfaceSignals->OnProp1Changed.AddLambda([this, TestDone](int32 InProp1){
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

		UTestbed2ManyParamInterfaceSignals* Testbed2ManyParamInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed2ManyParamInterfaceSignals->OnProp2Changed.AddLambda([this, TestDone](int32 InProp2){
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

		UTestbed2ManyParamInterfaceSignals* Testbed2ManyParamInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed2ManyParamInterfaceSignals->OnProp3Changed.AddLambda([this, TestDone](int32 InProp3){
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

		UTestbed2ManyParamInterfaceSignals* Testbed2ManyParamInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed2ManyParamInterfaceSignals->OnProp4Changed.AddLambda([this, TestDone](int32 InProp4){
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

	LatentIt("Operation.Func1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func1(0);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func2(0, 0);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func3", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func3(0, 0, 0);
			TestDone.Execute();
		});
	});

	LatentIt("Operation.Func4", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Func4(0, 0, 0, 0);
			TestDone.Execute();
		});
	});

	LatentIt("Signal.Sig1", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed2ManyParamInterfaceSignals* Testbed2ManyParamInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed2ManyParamInterfaceSignals->OnSig1Signal.AddLambda([this, TestDone](int32 InParam1){
			// known test value
			int32 Param1TestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam1, Param1TestValue);
			TestDone.Execute();
		});

		// use different test value
		int32 Param1TestValue = 1;
		Testbed2ManyParamInterfaceSignals->BroadcastSig1Signal(Param1TestValue);
	});

	LatentIt("Signal.Sig2", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed2ManyParamInterfaceSignals* Testbed2ManyParamInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed2ManyParamInterfaceSignals->OnSig2Signal.AddLambda([this, TestDone](int32 InParam1, int32 InParam2){
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
		Testbed2ManyParamInterfaceSignals->BroadcastSig2Signal(Param1TestValue, Param2TestValue);
	});

	LatentIt("Signal.Sig3", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed2ManyParamInterfaceSignals* Testbed2ManyParamInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed2ManyParamInterfaceSignals->OnSig3Signal.AddLambda([this, TestDone](int32 InParam1, int32 InParam2, int32 InParam3){
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
		Testbed2ManyParamInterfaceSignals->BroadcastSig3Signal(Param1TestValue, Param2TestValue, Param3TestValue);
	});

	LatentIt("Signal.Sig4", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed2ManyParamInterfaceSignals* Testbed2ManyParamInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed2ManyParamInterfaceSignals->OnSig4Signal.AddLambda([this, TestDone](int32 InParam1, int32 InParam2, int32 InParam3, int32 InParam4){
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
		Testbed2ManyParamInterfaceSignals->BroadcastSig4Signal(Param1TestValue, Param2TestValue, Param3TestValue, Param4TestValue);
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
