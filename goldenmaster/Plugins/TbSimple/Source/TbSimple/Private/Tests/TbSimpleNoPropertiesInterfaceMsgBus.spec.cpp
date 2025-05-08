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

#include "TbSimpleTestsCommon.h"
#include "Implementation/TbSimpleNoPropertiesInterface.h"
#include "TbSimpleNoPropertiesInterfaceMsgBusFixture.h"
#include "Generated/MsgBus/TbSimpleNoPropertiesInterfaceMsgBusClient.h"
#include "Generated/MsgBus/TbSimpleNoPropertiesInterfaceMsgBusAdapter.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UTbSimpleNoPropertiesInterfaceMsgBusSpec, "TbSimple.NoPropertiesInterface.MsgBus", TbSimpleTestFilterMask);

TSharedPtr<FTbSimpleNoPropertiesInterfaceMsgBusFixture> ImplFixture;

END_DEFINE_SPEC(UTbSimpleNoPropertiesInterfaceMsgBusSpec);

void UTbSimpleNoPropertiesInterfaceMsgBusSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeShared<FTbSimpleNoPropertiesInterfaceMsgBusFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		TestTrue("Check for valid Helper", ImplFixture->GetHelper().IsValid());
		// needed for callbacks
		ImplFixture->GetHelper()->SetSpec(this);
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		ImplFixture->GetHelper()->SetParentFixture(ImplFixture);

		// set up service and adapter
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSimpleNoPropertiesInterface>();
		ImplFixture->GetAdapter()->_setBackendService(service);
		ImplFixture->GetAdapter()->_StartListening();

		// setup client
		UTbSimpleNoPropertiesInterfaceMsgBusClient* MsgBusClient = Cast<UTbSimpleNoPropertiesInterfaceMsgBusClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid MsgBus client", MsgBusClient != nullptr);

		MsgBusClient->_ConnectionStatusChanged.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleNoPropertiesInterfaceMsgBusHelper::_ConnectionStatusChangedCb);

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
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSimpleNoPropertiesInterfaceSignals* TbSimpleNoPropertiesInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleNoPropertiesInterfaceSignals->OnSigVoidSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleNoPropertiesInterfaceMsgBusHelper::SigVoidSignalCb);

		// use different test value
		TbSimpleNoPropertiesInterfaceSignals->BroadcastSigVoidSignal();
	});

	LatentIt("Signal.SigBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		ImplFixture->GetHelper()->SetTestDone(TestDone);
		UTbSimpleNoPropertiesInterfaceSignals* TbSimpleNoPropertiesInterfaceSignals = ImplFixture->GetImplementation()->Execute__GetSignals(ImplFixture->GetImplementation().GetObject());
		TbSimpleNoPropertiesInterfaceSignals->OnSigBoolSignal.AddDynamic(ImplFixture->GetHelper().Get(), &UTbSimpleNoPropertiesInterfaceMsgBusHelper::SigBoolSignalCb);

		// use different test value
		bool bParamBoolTestValue = true;
		TbSimpleNoPropertiesInterfaceSignals->BroadcastSigBoolSignal(bParamBoolTestValue);
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS
