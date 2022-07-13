// Copyright Epic Games, Inc. All Rights Reserved
#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Object.h"
#include "Engine/EngineTypes.h"
#include "ApiGearSettings.generated.h"

/**
* Implements the settings for the ApiGear plugin.
*/
UCLASS(Config = Engine, DefaultConfig)
class APIGEAR_API UApiGearSettings : public UObject
{
	GENERATED_UCLASS_BODY()
	// Choose the server to connect to
	UPROPERTY(EditAnywhere, config, Category = TracerSetup, meta = (ConfigRestartRequired = true))
	FString Tracer_URL;

	// Choose whether to enable tracing
	UPROPERTY(EditAnywhere, config, Category = TracerSetup, meta = (ConfigRestartRequired = true))
	bool Tracer_Enabled;

	// Choose whether to display tracer logs in log view
	UPROPERTY(EditAnywhere, config, Category = TracerSetup, meta = (ConfigRestartRequired = true))
	bool Tracer_EnableDebugLog;

	// Choose the server to connect to
	UPROPERTY(EditAnywhere, config, Category = WampSetup, meta = (ConfigRestartRequired = true))
	FString WAMP_URL;

	// Choose the wamp realm
	UPROPERTY(EditAnywhere, config, Category = WampSetup, meta = (ConfigRestartRequired = true))
	FString WAMP_realm;

	// Choose whether to enable logging
	UPROPERTY(EditAnywhere, config, Category = WampSetup, meta = (ConfigRestartRequired = true))
	bool WAMP_EnableDebugLog;

	// Choose the server to connect to
	UPROPERTY(EditAnywhere, config, Category = OLinkSetup, meta = (ConfigRestartRequired = true))
	FString OLINK_URL;

	// Choose whether to enable logging
	UPROPERTY(EditAnywhere, config, Category = OLinkSetup, meta = (ConfigRestartRequired = true))
	bool OLINK_EnableDebugLog;

	// Choose whether to automatically reconnect
	UPROPERTY(EditAnywhere, config, Category = OLinkSetup, meta = (ConfigRestartRequired = true))
	bool OLINK_AutoReconnectEnabled;

	// Choose the server to connect to
	UPROPERTY(EditAnywhere, config, Category = SimulationSetup, meta = (ConfigRestartRequired = true))
	FString Simulation_URL;

	// Choose whether to enable logging
	UPROPERTY(EditAnywhere, config, Category = SimulationSetup, meta = (ConfigRestartRequired = true))
	bool Simulation_EnableDebugLog;

	// Choose whether to automatically reconnect
	UPROPERTY(EditAnywhere, config, Category = SimulationSetup, meta = (ConfigRestartRequired = true))
	bool Simulation_AutoReconnectEnabled;
};
