// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "TbSimple/Tests/TbSimpleTestsCommon.h"
#include "TbSimple/Implementation/TbSimpleVoidInterface.h"
#include "TbSimpleVoidInterfaceMQTTFixture.h"
#include "TbSimple/Generated/MQTT/TbSimpleVoidInterfaceMQTTClient.h"
#include "TbSimple/Generated/MQTT/TbSimpleVoidInterfaceMQTTAdapter.h"
#include "ApiGearMQTTClient.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace VoidInterface
{
namespace MQTT
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbSimpleVoidInterfaceMQTTSpec, "TbSimple.VoidInterface.MQTT", TbSimpleTestFilterMask);

TUniquePtr<FTbSimpleVoidInterfaceMQTTFixture> ImplFixture;

END_DEFINE_SPEC(UTbSimpleVoidInterfaceMQTTSpec);

void UTbSimpleVoidInterfaceMQTTSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbSimpleVoidInterfaceMQTTFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// setup client
		UTbSimpleVoidInterfaceMQTTClient* MQTTClient = Cast<UTbSimpleVoidInterfaceMQTTClient>(ImplFixture->GetImplementation().GetObject());
		TestTrue("Check for valid MQTT client", MQTTClient != nullptr);

		MQTTClient->_SubscriptionStatusChanged.AddLambda([this, TestDone](bool bSubscribed)
			{
			if (bSubscribed)
			{
				TestDone.Execute();
			}
		});

		MQTTClient->UseConnection(ImplFixture->Connection);
		ImplFixture->Connection->Connect();
	});

	AfterEach([this]()
		{
		if (ImplFixture->Connection && IsValid(ImplFixture->Connection.GetObject()))
		{
			ImplFixture->Connection->Disconnect();
			ImplFixture->Connection.GetObject()->RemoveFromRoot();
		}
		ImplFixture.Reset();
	});

	LatentIt("Operation.FuncVoid", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->FuncVoid();
			// Verify values here based on service logic
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
} // namespace MQTT
} // namespace VoidInterface
} // namespace TbSimple

#endif // WITH_DEV_AUTOMATION_TESTS
