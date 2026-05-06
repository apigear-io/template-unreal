// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#pragma once

#if WITH_DEV_AUTOMATION_TESTS

#include "PahoMqttClient.h"

class FPahoMqttClientFixture
{
public:
	FPahoMqttClientFixture()
	{
		Client = MakeShared<FPahoMqttClient>();
	}

	~FPahoMqttClientFixture()
	{
		Client.Reset();
	}

	TSharedPtr<FPahoMqttClient> Client;

	TSharedPtr<FPahoMqttClient> CreateSecondClient()
	{
		return MakeShared<FPahoMqttClient>();
	}

	static FString GetBrokerURL()
	{
		FString URL = FPlatformMisc::GetEnvironmentVariable(TEXT("APIGEAR_MQTT_BROKER_URL"));
		return URL.IsEmpty() ? FString(TEXT("tcp://localhost:1883")) : URL;
	}

	static bool IsBrokerConfigured()
	{
		FString URL = FPlatformMisc::GetEnvironmentVariable(TEXT("APIGEAR_MQTT_BROKER_URL"));
		return !URL.IsEmpty();
	}
};

#endif // WITH_DEV_AUTOMATION_TESTS
