// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "TbRefIfaces/Tests/TbRefIfacesTestsCommon.h"
#include "TbRefIfaces/Implementation/TbRefIfacesSimpleLocalIf.h"
#include "TbRefIfacesSimpleLocalIfMQTTFixture.h"
#include "TbRefIfaces/Generated/MQTT/TbRefIfacesSimpleLocalIfMQTTClient.h"
#include "TbRefIfaces/Generated/MQTT/TbRefIfacesSimpleLocalIfMQTTAdapter.h"
#include "ApiGearMQTTClient.h"
#include "TbIfaceimport/Tests/TbIfaceimportTestsCommon.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbRefIfaces
{
namespace SimpleLocalIf
{
namespace MQTT
{
namespace Tests
{
BEGIN_DEFINE_SPEC(UTbRefIfacesSimpleLocalIfMQTTSpec, "TbRefIfaces.SimpleLocalIf.MQTT", TbRefIfacesTestFilterMask);

TUniquePtr<FTbRefIfacesSimpleLocalIfMQTTFixture> ImplFixture;

END_DEFINE_SPEC(UTbRefIfacesSimpleLocalIfMQTTSpec);

void UTbRefIfacesSimpleLocalIfMQTTSpec::Define()
{
	LatentBeforeEach([this](const FDoneDelegate& TestDone)
		{
		ImplFixture = MakeUnique<FTbRefIfacesSimpleLocalIfMQTTFixture>();
		TestTrue("Check for valid ImplFixture", ImplFixture.IsValid());

		TestTrue("Check for valid testImplementation", ImplFixture->GetImplementation().GetInterface() != nullptr);

		// setup client
		UTbRefIfacesSimpleLocalIfMQTTClient* MQTTClient = Cast<UTbRefIfacesSimpleLocalIfMQTTClient>(ImplFixture->GetImplementation().GetObject());
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

	It("Property.IntProperty.Default", [this]()
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetIntProperty(), TestValue);
	});

	LatentIt("Property.IntProperty.Change", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		int32 TestValue = 0; // default value
		TestEqual(TEXT("Getter should return the default value"), ImplFixture->GetImplementation()->GetIntProperty(), TestValue);

		UTbRefIfacesSimpleLocalIfPublisher* TbRefIfacesSimpleLocalIfPublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbRefIfacesSimpleLocalIfPublisher->OnIntPropertyChanged.AddLambda([this, TestDone](int32 InIntProperty)
			{
			int32 TestValue = 0;
			// use different test value
			TestValue = 1;
			TestEqual(TEXT("Delegate parameter should be the same value as set by the setter"), InIntProperty, TestValue);
			TestEqual(TEXT("Getter should return the same value as set by the setter"), ImplFixture->GetImplementation()->GetIntProperty(), TestValue);
			TestDone.Execute();
		});

		// use different test value
		TestValue = 1;
		ImplFixture->GetImplementation()->SetIntProperty(TestValue);
	});

	LatentIt("Operation.IntMethod", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		// Do implement test here
		AsyncTask(ENamedThreads::AnyThread, [this, TestDone]()
			{
			ImplFixture->GetImplementation()->IntMethod(0);
			// Verify values here based on service logic
			TestDone.Execute();
		});
	});

	LatentIt("Signal.IntSignal", EAsyncExecution::ThreadPool, [this](const FDoneDelegate TestDone)
		{
		UTbRefIfacesSimpleLocalIfPublisher* TbRefIfacesSimpleLocalIfPublisher = ImplFixture->GetImplementation()->_GetPublisher();
		TbRefIfacesSimpleLocalIfPublisher->OnIntSignalSignal.AddLambda([this, TestDone](int32 InParam)
			{
			// known test value
			int32 ParamTestValue = 1;
			TestEqual(TEXT("Parameter should be the same value as sent by the signal"), InParam, ParamTestValue);
			TestDone.Execute();
		});

		// use different test value
		int32 ParamTestValue = 1;
		TbRefIfacesSimpleLocalIfPublisher->BroadcastIntSignalSignal(ParamTestValue);
	});
}
} // namespace Tests
} // namespace MQTT
} // namespace SimpleLocalIf
} // namespace TbRefIfaces

#endif // WITH_DEV_AUTOMATION_TESTS
