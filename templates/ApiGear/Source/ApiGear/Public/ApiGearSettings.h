// Copyright Epic Games, Inc. All Rights Reserved
#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Object.h"
#include "Engine/EngineTypes.h"
#include "ApiGearSettings.generated.h"

/** Settings per connection for ApiGear plugins */
USTRUCT()
struct FApiGearConnectionSetting
{
	GENERATED_BODY()

	/** 
	 * Unique protocol identifier, based on which connection type can be recognized and created.
	 * You can have more than one connection of the same protocol type with different urls
	 */
	FString ProtocolIdentifier{TEXT("olink")};

	/** Choose the server to connect to */
	UPROPERTY(EditAnywhere, config, Category = ApiGearConnectionSetting)
	FString URL{TEXT("ws://127.0.0.1:8000/ws")};

	/** Choose whether to automatically reconnect */
	UPROPERTY(EditAnywhere, config, Category = ApiGearConnectionSetting)
	bool AutoReconnectEnabled{false};
};

/**
 * Implements the settings for the ApiGear plugin.
 */
UCLASS(Config = Engine, DefaultConfig)
class APIGEAR_API UApiGearSettings : public UObject
{
	GENERATED_UCLASS_BODY()
	/** Choose the server to connect to */
	UPROPERTY(EditAnywhere, config, Category = TracerSetup, meta = (ConfigRestartRequired = true))
	FString Tracer_URL;

	/** Choose whether to enable tracing */
	UPROPERTY(EditAnywhere, config, Category = TracerSetup, meta = (ConfigRestartRequired = true))
	bool Tracer_Enabled;

	/** Choose whether to display tracer logs in log view */
	UPROPERTY(EditAnywhere, config, Category = TracerSetup, meta = (ConfigRestartRequired = true))
	bool Tracer_EnableDebugLog;

	/** Save and overwrite runtime modifications to the connections on exit */
	UPROPERTY(EditAnywhere, config, Category = ConnectionSetup, meta = (ConfigRestartRequired = true, Display = "Use runtime changes instead of settings"))
	bool bSaveRuntimeEdit;

	/** Modify connections */
	UPROPERTY(EditAnywhere, config, Category = ConnectionSetup, meta = (ConfigRestartRequired = true))
	TMap<FString, FApiGearConnectionSetting> Connections;
};
