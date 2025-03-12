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
#include "TbSimpleVoidInterfaceOLinkFixture.h"
#include "TbSimple/Implementation/TbSimpleVoidInterface.h"
#include "TbSimple/Generated/OLink/TbSimpleVoidInterfaceOLinkClient.h"
#include "TbSimple/Generated/OLink/TbSimpleVoidInterfaceOLinkAdapter.h"

#include "OLinkHost.h"
#include "OLinkClientConnection.h" // for olink factory
#include "TbSimple/Tests/TbSimpleTestsCommon.h"

BEGIN_DEFINE_SPEC(UTbSimpleVoidInterfaceOLinkSpec, "TbSimple.VoidInterface.OLink", TbSimpleTestFilterMask);

TUniquePtr<FTbSimpleVoidInterfaceOLinkFixture> ImplFixture;

END_DEFINE_SPEC(UTbSimpleVoidInterfaceOLinkSpec);

void UTbSimpleVoidInterfaceOLinkSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbSimpleVoidInterfaceOLinkFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// set up service and adapter
		ImplFixture->GetHost()->Stop();
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSimpleVoidInterface>();
		ImplFixture->GetAdapter()->setBackendService(service);
		ImplFixture->GetAdapter()->setOLinkHost(ImplFixture->GetHost());
		ImplFixture->GetHost()->Start(8666);

		// setup client
		UTbSimpleVoidInterfaceOLinkClient* OLinkClient = Cast<UTbSimpleVoidInterfaceOLinkClient>(ImplFixture->GetImplementation().GetObject());
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

	LatentIt("Operation.FuncVoid", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncVoid();
			TestDone.Execute();
		});
	});

	LatentIt("Signal.SigVoid", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleVoidInterfaceSignals* TbSimpleVoidInterfaceSignals = ImplFixture->GetImplementation()->_GetSignals();
		TbSimpleVoidInterfaceSignals->OnSigVoidSignal.AddLambda([this, TestDone]()
			{
			// known test value
			TestDone.Execute();
		});

		// use different test value
		TbSimpleVoidInterfaceSignals->BroadcastSigVoidSignal();
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
