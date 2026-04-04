// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "TbIfaceimport/Tests/TbIfaceimportTestsCommon.h"
#include "TbIfaceimport/Implementation/TbIfaceimportEmptyIf.h"
#include "TbIfaceimportEmptyIfMsgBusFixture.h"
#include "TbIfaceimport/Generated/MsgBus/TbIfaceimportEmptyIfMsgBusClient.h"
#include "TbIfaceimport/Generated/MsgBus/TbIfaceimportEmptyIfMsgBusAdapter.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbIfaceimport
{
namespace EmptyIf
{
namespace MsgBus
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbIfaceimportEmptyIfMsgBusSpec, "TbIfaceimport.EmptyIf.MsgBus", TbIfaceimportTestFilterMask);

TUniquePtr<FTbIfaceimportEmptyIfMsgBusFixture> ImplFixture;

END_DEFINE_SPEC(UTbIfaceimportEmptyIfMsgBusSpec);

void UTbIfaceimportEmptyIfMsgBusSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbIfaceimportEmptyIfMsgBusFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// set up service and adapter
		auto service = ImplFixture->GetGameInstance()->GetSubsystem<UTbIfaceimportEmptyIfImplementation>();
		ImplFixture->GetAdapter()->_setBackendService(service);
		ImplFixture->GetAdapter()->_StartListening();

		// setup client
		UTbIfaceimportEmptyIfMsgBusClient* MsgBusClient = Cast<UTbIfaceimportEmptyIfMsgBusClient>(ImplFixture->GetImplementation().GetObject());
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
}
} // namespace Tests
} // namespace MsgBus
} // namespace EmptyIf
} // namespace TbIfaceimport

#endif // WITH_DEV_AUTOMATION_TESTS
