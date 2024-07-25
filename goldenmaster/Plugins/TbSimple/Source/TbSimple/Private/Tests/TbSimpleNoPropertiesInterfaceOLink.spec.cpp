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

#include "TbSimpleNoPropertiesInterfaceOLink.spec.h"
#include "Implementation/TbSimpleNoPropertiesInterface.h"
#include "TbSimpleNoPropertiesInterfaceOLinkFixture.h"
#include "Generated/OLink/TbSimpleNoPropertiesInterfaceOLinkClient.h"
#include "Generated/OLink/TbSimpleNoPropertiesInterfaceOLinkAdapter.h"
#include "OLinkHost.h"
#include "OLinkClientConnection.h" // for olink factory
#include "TbSimpleTestsCommon.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSimpleNoPropertiesInterfaceOLinkSpec::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	// ImplFixture->testDoneDelegate.Execute();
	// InTestDoneDelegate.Execute();
	if (bSubscribed)
	{
		testDoneDelegate.Execute();
	}
}

void UTbSimpleNoPropertiesInterfaceOLinkSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbSimpleNoPropertiesInterfaceOLinkFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		// needed for callbacks
		ImplFixture->GetHelper()->SetSpec(this);

		// set up service and adapter
		ImplFixture->GetHost()->Stop();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSimpleNoPropertiesInterface>();
		ImplFixture->GetAdapter()->setBackendService(service);
		ImplFixture->GetAdapter()->setOLinkHost(ImplFixture->GetHost());
		ImplFixture->GetHost()->Start(8666);

		// setup client
		testDoneDelegate = TestDone;
		UTbSimpleNoPropertiesInterfaceOLinkClient* OLinkClient = Cast<UTbSimpleNoPropertiesInterfaceOLinkClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid OLink client", OLinkClient != nullptr);

		OLinkClient->_SubscriptionStatusChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleNoPropertiesInterfaceOLinkHelper::_SubscriptionStatusChangedCb);

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

	LatentIt("Operation.FuncVoid", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_FuncVoid(ImplFixture->GetImplementation().GetObject());
			TestDone.Execute();
		});
	});

	LatentIt("Operation.FuncBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->Execute_FuncBool(ImplFixture->GetImplementation().GetObject(), false);
			TestDone.Execute();
		});
	});

	LatentIt("Signal.SigVoid", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleNoPropertiesInterfaceSignals* TbSimpleNoPropertiesInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleNoPropertiesInterfaceSignals->OnSigVoidSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleNoPropertiesInterfaceOLinkHelper::SigVoidSignalCb);

		// use different test value
		TbSimpleNoPropertiesInterfaceSignals->BroadcastSigVoidSignal();
	});

	LatentIt("Signal.SigBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		testDoneDelegate = TestDone;
		UTbSimpleNoPropertiesInterfaceSignals* TbSimpleNoPropertiesInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleNoPropertiesInterfaceSignals->OnSigBoolSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleNoPropertiesInterfaceOLinkHelper::SigBoolSignalCb);

		// use different test value
		bool bParamBoolTestValue = true;
		TbSimpleNoPropertiesInterfaceSignals->BroadcastSigBoolSignal(bParamBoolTestValue);
	});
}

void UTbSimpleNoPropertiesInterfaceOLinkSpec::SigVoidSignalCb()
{
	// known test value
	testDoneDelegate.Execute();
}

void UTbSimpleNoPropertiesInterfaceOLinkSpec::SigBoolSignalCb(bool bInParamBool)
{
	// known test value
	bool bParamBoolTestValue = true;
	TestEqual(TEXT("Parameter should be the same value as sent by the signal"), bInParamBool, bParamBoolTestValue);
	testDoneDelegate.Execute();
}
#endif // WITH_DEV_AUTOMATION_TESTS
