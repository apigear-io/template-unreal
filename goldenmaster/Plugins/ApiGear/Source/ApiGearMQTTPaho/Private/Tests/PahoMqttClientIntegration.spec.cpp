// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "PahoMqttClientFixture.h"
#include "Misc/AutomationTest.h"
#include "Runtime/Launch/Resources/Version.h"

#if (ENGINE_MAJOR_VERSION >= 5)
#if (ENGINE_MINOR_VERSION >= 5)
inline constexpr EAutomationTestFlags PahoIntegrationTestFilterMask = EAutomationTestFlags_ApplicationContextMask | EAutomationTestFlags::ProductFilter;
#else
inline constexpr int PahoIntegrationTestFilterMask = EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter;
#endif
#else
constexpr int PahoIntegrationTestFilterMask = EAutomationTestFlags::ApplicationContextMask | EAutomationTestFlags::ProductFilter;
#endif

#if WITH_DEV_AUTOMATION_TESTS

BEGIN_DEFINE_SPEC(UPahoMqttClientIntegrationSpec, "ApiGear.MQTT.PahoIntegration", PahoIntegrationTestFilterMask);
TUniquePtr<FPahoMqttClientFixture> Fixture;
FString BrokerURL;
bool bBrokerConfigured;
END_DEFINE_SPEC(UPahoMqttClientIntegrationSpec);

void UPahoMqttClientIntegrationSpec::Define()
{
	BeforeEach([this]()
		{
		bBrokerConfigured = FPahoMqttClientFixture::IsBrokerConfigured();
		BrokerURL = FPahoMqttClientFixture::GetBrokerURL();
		Fixture = MakeUnique<FPahoMqttClientFixture>();
	});

	AfterEach([this]()
		{
		Fixture.Reset();
	});

	Describe("Connect and disconnect", [this]()
		{
		LatentIt("Connects to broker and disconnects cleanly", EAsyncExecution::ThreadPool,
			FTimespan::FromSeconds(5),
			[this](const FDoneDelegate TestDone)
			{
			if (!bBrokerConfigured)
			{
				AddWarning(TEXT("Skipped: APIGEAR_MQTT_BROKER_URL is not set"));
				TestDone.Execute();
				return;
			}

			Fixture->Client->OnConnectionChanged().AddLambda([this, TestDone](bool bConnected)
				{
				if (bConnected)
				{
					TestTrue("Connected", Fixture->Client->IsConnected());
					Fixture->Client->Disconnect();
				}
				else
				{
					TestFalse("Disconnected", Fixture->Client->IsConnected());
					TestDone.Execute();
				}
			});

			Fixture->Client->Connect(BrokerURL);
		});
	});

	Describe("Pub/sub round-trip", [this]()
		{
		LatentIt("Subscriber receives published message", EAsyncExecution::ThreadPool,
			FTimespan::FromSeconds(5),
			[this](const FDoneDelegate TestDone)
			{
			if (!bBrokerConfigured)
			{
				AddWarning(TEXT("Skipped: APIGEAR_MQTT_BROKER_URL is not set"));
				TestDone.Execute();
				return;
			}

			auto Publisher = Fixture->CreateSecondClient();
			FString TestTopic = FString::Printf(TEXT("apigear/test/%s"), *FGuid::NewGuid().ToString());
			TArray<uint8> ExpectedPayload = {0x48, 0x65, 0x6C, 0x6C, 0x6F}; // "Hello"

			Fixture->Client->OnConnectionChanged().AddLambda(
				[this, TestTopic, ExpectedPayload, Publisher, TestDone](bool bConnected)
				{
				if (!bConnected)
				{
					return;
				}

				Fixture->Client->Subscribe(
					TestTopic,
					[this, ExpectedPayload, TestDone](const IApiGearMqttClient::FReceivedMessage& Msg)
					{
					TestEqual("Payload matches", Msg.Payload, ExpectedPayload);
					TestDone.Execute();
					},
					[Publisher, TestTopic, ExpectedPayload](bool bSuccess)
					{
					if (bSuccess)
					{
						Publisher->Publish(TestTopic, ExpectedPayload, {});
					}
				});
			});

			Publisher->OnConnectionChanged().AddLambda([this, Publisher](bool bConnected)
				{
				if (bConnected)
				{
					Fixture->Client->Connect(BrokerURL);
				}
			});

			Publisher->Connect(BrokerURL);
		});
	});

	Describe("Retained messages", [this]()
		{
		LatentIt("New subscriber receives retained message", EAsyncExecution::ThreadPool,
			FTimespan::FromSeconds(5),
			[this](const FDoneDelegate TestDone)
			{
			if (!bBrokerConfigured)
			{
				AddWarning(TEXT("Skipped: APIGEAR_MQTT_BROKER_URL is not set"));
				TestDone.Execute();
				return;
			}

			auto Publisher = Fixture->CreateSecondClient();
			FString TestTopic = FString::Printf(TEXT("apigear/test/retain/%s"), *FGuid::NewGuid().ToString());
			TArray<uint8> RetainedPayload = {0x52, 0x65, 0x74}; // "Ret"

			Publisher->OnConnectionChanged().AddLambda(
				[this, Publisher, TestTopic, RetainedPayload, TestDone](bool bConnected)
				{
				if (!bConnected)
				{
					return;
				}

				IApiGearMqttClient::FPublishOptions Opts;
				Opts.bRetain = true;
				Publisher->Publish(TestTopic, RetainedPayload, Opts);

				FPlatformProcess::Sleep(0.5f);

				Fixture->Client->OnConnectionChanged().AddLambda(
					[this, TestTopic, RetainedPayload, TestDone](bool bClientConnected)
					{
					if (!bClientConnected)
					{
						return;
					}

					Fixture->Client->Subscribe(
						TestTopic,
						[this, RetainedPayload, TestDone](const IApiGearMqttClient::FReceivedMessage& Msg)
						{
						TestEqual("Retained payload matches", Msg.Payload, RetainedPayload);
						TestDone.Execute();
						},
						nullptr);
				});

				Fixture->Client->Connect(BrokerURL);
			});

			Publisher->Connect(BrokerURL);
		});
	});

	Describe("Subscribe acknowledgement", [this]()
		{
		LatentIt("OnSubscribed callback fires with success", EAsyncExecution::ThreadPool,
			FTimespan::FromSeconds(5),
			[this](const FDoneDelegate TestDone)
			{
			if (!bBrokerConfigured)
			{
				AddWarning(TEXT("Skipped: APIGEAR_MQTT_BROKER_URL is not set"));
				TestDone.Execute();
				return;
			}

			Fixture->Client->OnConnectionChanged().AddLambda([this, TestDone](bool bConnected)
				{
				if (!bConnected)
				{
					return;
				}

				Fixture->Client->Subscribe(
					TEXT("apigear/test/suback"),
					[](const IApiGearMqttClient::FReceivedMessage&) {},
					[this, TestDone](bool bSuccess)
					{
					TestTrue("Subscribe acknowledged", bSuccess);
					TestDone.Execute();
					});
			});

			Fixture->Client->Connect(BrokerURL);
		});
	});

	Describe("Subscribe from OnMessage callback", [this]()
		{
		LatentIt("Does not deadlock when subscribing in message callback", EAsyncExecution::ThreadPool,
			FTimespan::FromSeconds(5),
			[this](const FDoneDelegate TestDone)
			{
			if (!bBrokerConfigured)
			{
				AddWarning(TEXT("Skipped: APIGEAR_MQTT_BROKER_URL is not set"));
				TestDone.Execute();
				return;
			}

			auto Publisher = Fixture->CreateSecondClient();
			FString TriggerTopic = FString::Printf(TEXT("apigear/test/trigger/%s"), *FGuid::NewGuid().ToString());
			FString SecondTopic = FString::Printf(TEXT("apigear/test/second/%s"), *FGuid::NewGuid().ToString());
			TArray<uint8> Payload = {0x01};

			Fixture->Client->OnConnectionChanged().AddLambda(
				[this, TriggerTopic, SecondTopic, Publisher, Payload, TestDone](bool bConnected)
				{
				if (!bConnected)
				{
					return;
				}

				Fixture->Client->Subscribe(
					TriggerTopic,
					[this, SecondTopic, TestDone](const IApiGearMqttClient::FReceivedMessage&)
					{
					Fixture->Client->Subscribe(
						SecondTopic,
						[this, TestDone](const IApiGearMqttClient::FReceivedMessage&)
						{
						TestDone.Execute();
						},
						[this, SecondTopic, TestDone](bool bSuccess)
						{
						TestTrue("Second subscribe succeeded", bSuccess);
						TArray<uint8> Msg = {0x02};
						Fixture->Client->Publish(SecondTopic, Msg, {});
					});
					},
					[Publisher, TriggerTopic, Payload](bool bSuccess)
					{
					if (bSuccess)
					{
						Publisher->Publish(TriggerTopic, Payload, {});
					}
				});
			});

			Publisher->OnConnectionChanged().AddLambda([this](bool bConnected)
				{
				if (bConnected)
				{
					Fixture->Client->Connect(BrokerURL);
				}
			});

			Publisher->Connect(BrokerURL);
		});
	});
}

#endif // WITH_DEV_AUTOMATION_TESTS
