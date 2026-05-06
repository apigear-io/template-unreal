// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "TbIfaceimport/Tests/TbIfaceimportTestsCommon.h"
#include "TbIfaceimport/Implementation/TbIfaceimportEmptyIf.h"
#include "TbIfaceimportEmptyIfMQTTFixture.h"
#include "TbIfaceimport/Generated/MQTT/TbIfaceimportEmptyIfMQTTClient.h"
#include "TbIfaceimport/Generated/MQTT/TbIfaceimportEmptyIfMQTTAdapter.h"
#include "ApiGearMQTTClient.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbIfaceimport
{
namespace EmptyIf
{
namespace MQTT
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbIfaceimportEmptyIfMQTTSpec, "TbIfaceimport.EmptyIf.MQTT", TbIfaceimportTestFilterMask);

TUniquePtr<FTbIfaceimportEmptyIfMQTTFixture> ImplFixture;

END_DEFINE_SPEC(UTbIfaceimportEmptyIfMQTTSpec);

void UTbIfaceimportEmptyIfMQTTSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbIfaceimportEmptyIfMQTTFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// setup client
		UTbIfaceimportEmptyIfMQTTClient* MQTTClient = Cast<UTbIfaceimportEmptyIfMQTTClient>(ImplFixture->GetImplementation().GetObject());
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
}
} // namespace Tests
} // namespace MQTT
} // namespace EmptyIf
} // namespace TbIfaceimport

#endif // WITH_DEV_AUTOMATION_TESTS
