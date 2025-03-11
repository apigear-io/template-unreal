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

#include "TbSimple/Tests/TbSimpleTestsCommon.h"
#include "TbSimple/Implementation/TbSimpleVoidInterface.h"
#include "TbSimpleVoidInterfaceMsgBusFixture.h"
#include "TbSimple/Generated/MsgBus/TbSimpleVoidInterfaceMsgBusClient.h"
#include "TbSimple/Generated/MsgBus/TbSimpleVoidInterfaceMsgBusAdapter.h"

BEGIN_DEFINE_SPEC(UTbSimpleVoidInterfaceMsgBusSpec, "TbSimple.VoidInterface.MsgBus", TbSimpleTestFilterMask);

TUniquePtr<FTbSimpleVoidInterfaceMsgBusFixture> ImplFixture;

END_DEFINE_SPEC(UTbSimpleVoidInterfaceMsgBusSpec);

void UTbSimpleVoidInterfaceMsgBusSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbSimpleVoidInterfaceMsgBusFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// set up service and adapter
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSimpleVoidInterface>();
		ImplFixture->GetAdapter()->_setBackendService(service);
		ImplFixture->GetAdapter()->_StartListening();

		// setup client
		UTbSimpleVoidInterfaceMsgBusClient* MsgBusClient = Cast<UTbSimpleVoidInterfaceMsgBusClient>(ImplFixture->GetImplementation().GetObject());
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

#endif // WITH_DEV_AUTOMATION_TESTS
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID)
