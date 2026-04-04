// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "TbSimple/Tests/TbSimpleTestsCommon.h"
#include "TbSimple/Implementation/TbSimpleVoidInterface.h"
#include "TbSimpleVoidInterfaceMsgBusFixture.h"
#include "TbSimple/Generated/MsgBus/TbSimpleVoidInterfaceMsgBusClient.h"
#include "TbSimple/Generated/MsgBus/TbSimpleVoidInterfaceMsgBusAdapter.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace VoidInterface
{
namespace MsgBus
{
namespace Tests
{
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
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbSimpleVoidInterfaceImplementation>();
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
		UTbSimpleVoidInterfacePublisher* TbSimpleVoidInterfacePublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbSimpleVoidInterfacePublisher->OnSigVoidSignal.AddLambda([this, TestDone]()
			{
			// known test value
			TestDone.Execute();
		});

		// use different test value
		TbSimpleVoidInterfacePublisher->BroadcastSigVoidSignal();
	});
}
} // namespace Tests
} // namespace MsgBus
} // namespace VoidInterface
} // namespace TbSimple

#endif // WITH_DEV_AUTOMATION_TESTS
