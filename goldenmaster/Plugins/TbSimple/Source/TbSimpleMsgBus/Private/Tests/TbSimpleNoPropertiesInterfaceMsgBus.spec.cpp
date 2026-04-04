// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "TbSimple/Tests/TbSimpleTestsCommon.h"
#include "TbSimple/Implementation/TbSimpleNoPropertiesInterface.h"
#include "TbSimpleNoPropertiesInterfaceMsgBusFixture.h"
#include "TbSimple/Generated/MsgBus/TbSimpleNoPropertiesInterfaceMsgBusClient.h"
#include "TbSimple/Generated/MsgBus/TbSimpleNoPropertiesInterfaceMsgBusAdapter.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace NoPropertiesInterface
{
namespace MsgBus
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbSimpleNoPropertiesInterfaceMsgBusSpec, "TbSimple.NoPropertiesInterface.MsgBus", TbSimpleTestFilterMask);

TUniquePtr<FTbSimpleNoPropertiesInterfaceMsgBusFixture> ImplFixture;

END_DEFINE_SPEC(UTbSimpleNoPropertiesInterfaceMsgBusSpec);

void UTbSimpleNoPropertiesInterfaceMsgBusSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbSimpleNoPropertiesInterfaceMsgBusFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// set up service and adapter
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSimpleNoPropertiesInterfaceImplementation>();
		ImplFixture->GetAdapter()->_setBackendService(service);
		ImplFixture->GetAdapter()->_StartListening();

		// setup client
		UTbSimpleNoPropertiesInterfaceMsgBusClient* MsgBusClient = Cast<UTbSimpleNoPropertiesInterfaceMsgBusClient>(ImplFixture->GetImplementation().GetObject());
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

	LatentIt("Operation.FuncBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncBool(false);
			TestDone.Execute();
		});
	});

	LatentIt("Signal.SigVoid", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleNoPropertiesInterfacePublisher* TbSimpleNoPropertiesInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleNoPropertiesInterfacePublisher->OnSigVoidSignal.AddLambda([this, TestDone]()
			{
			// known test value
			TestDone.Execute();
		});

		// use different test value
		TbSimpleNoPropertiesInterfacePublisher->BroadcastSigVoidSignal();
	});

	LatentIt("Signal.SigBool", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbSimpleNoPropertiesInterfacePublisher* TbSimpleNoPropertiesInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleNoPropertiesInterfacePublisher->OnSigBoolSignal.AddLambda([this, TestDone](bool bInParamBool)
			{
			// known test value
			bool bParamBoolTestValue = true;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), bInParamBool, bParamBoolTestValue);
			TestDone.Execute();
		});

		// use different test value
		bool bParamBoolTestValue = true;
		TbSimpleNoPropertiesInterfacePublisher->BroadcastSigBoolSignal(bParamBoolTestValue);
	});
}
} // namespace Tests
} // namespace MsgBus
} // namespace NoPropertiesInterface
} // namespace TbSimple

#endif // WITH_DEV_AUTOMATION_TESTS
