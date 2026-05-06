// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "PahoMqttClientFixture.h"
#include "Misc/AutomationTest.h"
#include "Runtime/Launch/Resources/Version.h"

#if (ENGINE_MAJOR_VERSION >= 5)
#if (ENGINE_MINOR_VERSION >= 5)
inline constexpr EAutomationTestFlags PahoMqttTestFilterMask = EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter;
#else
inline constexpr int PahoMqttTestFilterMask = EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter;
#endif
#else
constexpr int PahoMqttTestFilterMask = EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter;
#endif

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UPahoMqttClientSpec, "ApiGear.MQTT.Paho", PahoMqttTestFilterMask);
TUniquePtr<FPahoMqttClientFixture> Fixture;
END_DEFINE_SPEC(UPahoMqttClientSpec);

void UPahoMqttClientSpec::Define()
{
	BeforeEach([this]()
		{
		Fixture = MakeUnique<FPahoMqttClientFixture>();
		TestTrue("Fixture is valid", Fixture.IsValid());
	});

	AfterEach([this]()
		{
		Fixture.Reset();
	});

	Describe("Construction", [this]()
		{
		It("ClientId is a valid non-empty GUID", [this]()
			{
			FString Id = Fixture->Client->GetClientId();
			TestFalse("ClientId not empty", Id.IsEmpty());
			FGuid Parsed;
			TestTrue("ClientId is valid GUID", FGuid::Parse(Id, Parsed));
		});

		It("IsConnected returns false initially", [this]()
			{
			TestFalse("Not connected", Fixture->Client->IsConnected());
		});
	});

	Describe("Operations before connect", [this]()
		{
		It("Subscribe before connect does not crash", [this]()
			{
			Fixture->Client->Subscribe(
				TEXT("test/topic"),
				[](const IApiGearMqttClient::FReceivedMessage&) {},
				[](bool) {});
			TestFalse("Still not connected", Fixture->Client->IsConnected());
		});

		It("Publish before connect does not crash", [this]()
			{
			TArray<uint8> Payload = {0x41, 0x42};
			Fixture->Client->Publish(TEXT("test/topic"), Payload, {});
			TestFalse("Still not connected", Fixture->Client->IsConnected());
		});

		It("Unsubscribe before connect does not crash", [this]()
			{
			TArray<FString> Topics = {TEXT("test/topic")};
			Fixture->Client->Unsubscribe(Topics);
			TestFalse("Still not connected", Fixture->Client->IsConnected());
		});

		It("Unsubscribe unknown topic does not crash", [this]()
			{
			TArray<FString> Topics = {TEXT("never/subscribed")};
			Fixture->Client->Unsubscribe(Topics);
			TestFalse("Still not connected", Fixture->Client->IsConnected());
		});

		It("Disconnect when not connected does not crash", [this]()
			{
			Fixture->Client->Disconnect();
			TestFalse("Still not connected", Fixture->Client->IsConnected());
		});

		It("Empty topic subscribe does not crash", [this]()
			{
			Fixture->Client->Subscribe(
				TEXT(""),
				[](const IApiGearMqttClient::FReceivedMessage&) {},
				nullptr);
			TestFalse("Still not connected", Fixture->Client->IsConnected());
		});

		It("Empty payload publish does not crash", [this]()
			{
			TArray<uint8> Empty;
			Fixture->Client->Publish(TEXT("test/topic"), Empty, {});
			TestFalse("Still not connected", Fixture->Client->IsConnected());
		});
	});

	Describe("Connect with invalid URL", [this]()
		{
		LatentIt("Fires OnConnectionChanged(false)", EAsyncExecution::ThreadPool,
			FTimespan::FromSeconds(5),
			[this](const FDoneDelegate TestDone)
			{
			AddExpectedError(TEXT("MQTTAsync_createWithOptions failed"), EAutomationExpectedErrorFlags::Contains, 1);

			Fixture->Client->OnConnectionChanged().AddLambda([this, TestDone](bool bConnected)
				{
				TestFalse("Connection should fail", bConnected);
				TestDone.Execute();
			});

			Fixture->Client->Connect(TEXT("invalid://nowhere:9999"));
		});
	});

	Describe("Rapid reconnect", [this]()
		{
		It("Second Connect destroys old handle cleanly", [this]()
			{
			AddExpectedError(TEXT("MQTTAsync_createWithOptions failed"), EAutomationExpectedErrorFlags::Contains, 2);

			Fixture->Client->Connect(TEXT("invalid://first"));
			Fixture->Client->Connect(TEXT("invalid://second"));
			TestFalse("Still not connected", Fixture->Client->IsConnected());
		});
	});

	Describe("Destruction under flight", [this]()
		{
		It("Destroy immediately after Connect does not crash", [this]()
			{
			AddExpectedError(TEXT("MQTTAsync_createWithOptions failed"), EAutomationExpectedErrorFlags::Contains, 1);

			TSharedPtr<FPahoMqttClient> Client = MakeShared<FPahoMqttClient>();
			Client->Connect(TEXT("invalid://nowhere:9999"));
			Client.Reset();
			TestFalse("Client destroyed", Client.IsValid());
		});
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS
