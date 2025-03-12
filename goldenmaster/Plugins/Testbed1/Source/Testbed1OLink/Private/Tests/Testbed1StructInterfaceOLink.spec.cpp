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
#include "Testbed1StructInterfaceOLinkFixture.h"
#include "Testbed1/Implementation/Testbed1StructInterface.h"
#include "Testbed1/Generated/OLink/Testbed1StructInterfaceOLinkClient.h"
#include "Testbed1/Generated/OLink/Testbed1StructInterfaceOLinkAdapter.h"

#include "OLinkHost.h"
#include "OLinkClientConnection.h" // for olink factory
#include "Testbed1/Tests/Testbed1TestsCommon.h"

BEGIN_DEFINE_SPEC(UTestbed1StructInterfaceOLinkSpec, "Testbed1.StructInterface.OLink", Testbed1TestFilterMask);

TUniquePtr<FTestbed1StructInterfaceOLinkFixture> ImplFixture;

END_DEFINE_SPEC(UTestbed1StructInterfaceOLinkSpec);

void UTestbed1StructInterfaceOLinkSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTestbed1StructInterfaceOLinkFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// set up service and adapter
		ImplFixture->GetHost()->Stop();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTestbed1StructInterface>();
		ImplFixture->GetAdapter()->setBackendService(service);
		ImplFixture->GetAdapter()->setOLinkHost(ImplFixture->GetHost());
		ImplFixture->GetHost()->Start(8666);

		// setup client
		UTestbed1StructInterfaceOLinkClient* OLinkClient = Cast<UTestbed1StructInterfaceOLinkClient>(ImplFixture->GetImplementation().GetObject());
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

	It("Property.PropBool.Default", [this]()
		{
		// Do implement test here
		FTestbed1StructBool TestValue = FTestbed1StructBool(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);
	});

	LatentIt("Property.PropBool.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructBool TestValue = FTestbed1StructBool(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);

		UTestbed1StructInterfaceSignals* Testbed1StructInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructInterfaceSignals->OnPropBoolChanged.AddLambda([this, TestDone](const FTestbed1StructBool& InPropBool)
			{
			FTestbed1StructBool TestValue = FTestbed1StructBool();
			// use different test value
			TestValue = createTestFTestbed1StructBool();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropBool, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropBool(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructBool();
		ImplFixture->GetImplementation()->SetPropBool(TestValue);
	});

	It("Property.PropInt.Default", [this]()
		{
		// Do implement test here
		FTestbed1StructInt TestValue = FTestbed1StructInt(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);
	});

	LatentIt("Property.PropInt.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructInt TestValue = FTestbed1StructInt(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);

		UTestbed1StructInterfaceSignals* Testbed1StructInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructInterfaceSignals->OnPropIntChanged.AddLambda([this, TestDone](const FTestbed1StructInt& InPropInt)
			{
			FTestbed1StructInt TestValue = FTestbed1StructInt();
			// use different test value
			TestValue = createTestFTestbed1StructInt();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropInt, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropInt(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructInt();
		ImplFixture->GetImplementation()->SetPropInt(TestValue);
	});

	It("Property.PropFloat.Default", [this]()
		{
		// Do implement test here
		FTestbed1StructFloat TestValue = FTestbed1StructFloat(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);
	});

	LatentIt("Property.PropFloat.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructFloat TestValue = FTestbed1StructFloat(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);

		UTestbed1StructInterfaceSignals* Testbed1StructInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructInterfaceSignals->OnPropFloatChanged.AddLambda([this, TestDone](const FTestbed1StructFloat& InPropFloat)
			{
			FTestbed1StructFloat TestValue = FTestbed1StructFloat();
			// use different test value
			TestValue = createTestFTestbed1StructFloat();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropFloat, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropFloat(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructFloat();
		ImplFixture->GetImplementation()->SetPropFloat(TestValue);
	});

	It("Property.PropString.Default", [this]()
		{
		// Do implement test here
		FTestbed1StructString TestValue = FTestbed1StructString(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropString(), TestValue);
	});

	LatentIt("Property.PropString.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		FTestbed1StructString TestValue = FTestbed1StructString(); // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetPropString(), TestValue);

		UTestbed1StructInterfaceSignals* Testbed1StructInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructInterfaceSignals->OnPropStringChanged.AddLambda([this, TestDone](const FTestbed1StructString& InPropString)
			{
			FTestbed1StructString TestValue = FTestbed1StructString();
			// use different test value
			TestValue = createTestFTestbed1StructString();
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InPropString, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetPropString(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = createTestFTestbed1StructString();
		ImplFixture->GetImplementation()->SetPropString(TestValue);
	});

	LatentIt("Operation.FuncBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncBool(FTestbed1StructBool());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncInt(FTestbed1StructInt());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncFloat(FTestbed1StructFloat());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncString(FTestbed1StructString());
			TestDone.Execute();
		});
	});

	LatentIt("Signal.SigBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructInterfaceSignals* Testbed1StructInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructInterfaceSignals->OnSigBoolSignal.AddLambda([this, TestDone](const FTestbed1StructBool& InParamBool)
			{
			// known test value
			FTestbed1StructBool ParamBoolTestValue = createTestFTestbed1StructBool();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamBool, ParamBoolTestValue);
			TestDone.Execute();
		});

		// use different test value
		FTestbed1StructBool ParamBoolTestValue = createTestFTestbed1StructBool();
		Testbed1StructInterfaceSignals->BroadcastSigBoolSignal(ParamBoolTestValue);
	});

	LatentIt("Signal.SigInt", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructInterfaceSignals* Testbed1StructInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructInterfaceSignals->OnSigIntSignal.AddLambda([this, TestDone](const FTestbed1StructInt& InParamInt)
			{
			// known test value
			FTestbed1StructInt ParamIntTestValue = createTestFTestbed1StructInt();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamInt, ParamIntTestValue);
			TestDone.Execute();
		});

		// use different test value
		FTestbed1StructInt ParamIntTestValue = createTestFTestbed1StructInt();
		Testbed1StructInterfaceSignals->BroadcastSigIntSignal(ParamIntTestValue);
	});

	LatentIt("Signal.SigFloat", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructInterfaceSignals* Testbed1StructInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructInterfaceSignals->OnSigFloatSignal.AddLambda([this, TestDone](const FTestbed1StructFloat& InParamFloat)
			{
			// known test value
			FTestbed1StructFloat ParamFloatTestValue = createTestFTestbed1StructFloat();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamFloat, ParamFloatTestValue);
			TestDone.Execute();
		});

		// use different test value
		FTestbed1StructFloat ParamFloatTestValue = createTestFTestbed1StructFloat();
		Testbed1StructInterfaceSignals->BroadcastSigFloatSignal(ParamFloatTestValue);
	});

	LatentIt("Signal.SigString", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTestbed1StructInterfaceSignals* Testbed1StructInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		Testbed1StructInterfaceSignals->OnSigStringSignal.AddLambda([this, TestDone](const FTestbed1StructString& InParamString)
			{
			// known test value
			FTestbed1StructString ParamStringTestValue = createTestFTestbed1StructString();
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParamString, ParamStringTestValue);
			TestDone.Execute();
		});

		// use different test value
		FTestbed1StructString ParamStringTestValue = createTestFTestbed1StructString();
		Testbed1StructInterfaceSignals->BroadcastSigStringSignal(ParamStringTestValue);
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
