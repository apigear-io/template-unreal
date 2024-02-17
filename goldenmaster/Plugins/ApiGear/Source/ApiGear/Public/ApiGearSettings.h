// Copyright Epic Games, Inc. All Rights Reserved
#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Object.h"
#include "Engine/EngineTypes.h"
#include "ApiGearSettings.generated.h"

/** Settings for a connection in ApiGear plugins */
USTRUCT()
struct FApiGearConnectionSetting
{
	GENERATED_BODY()

	/** 
	 * Unique protocol identifier, based on which connection type can be recognized and created.
	 * You can have more than one connection of the same protocol type with different urls
	 */
	FString ProtocolIdentifier{"olink"};

	/** 
	 * Choose the server to connect to
	 * this is a full address with a port
	 * It will be used "as is", so if you need any pre or post fixes like
	 * "ws://" make sure the field contains it.
	 */
	UPROPERTY(EditAnywhere, config, Category = ApiGearConnectionSetting)
	FString URL{TEXT("ws://127.0.0.1:8000/ws")};

	/** Enable reconnect functionality for connection, also automatically starts the connection for the first time */
	UPROPERTY(EditAnywhere, config, Category = ApiGearConnectionSetting)
	bool AutoReconnectEnabled{false};
};

/**
 * Stores settings for each connection and other network related settings for ApiGear plugin.
 * For each connection settings a connections is created by ApiGearConnectionsStore on startup,
 * For other custom protocols make sure that a factory for it is added to ApiGearConnectionsStore.
 * @see ApiGearConnectionsStore
 */
UCLASS(Config = Engine, DefaultConfig)
class APIGEAR_API UApiGearSettings : public UObject
{
	GENERATED_UCLASS_BODY()
	/** 
	 * Url of tracer server to connect to.
	 * This is a full address with a port
	 * It will be used "as is", so if you need any pre or post fixes like
	 * "ws://" make sure the field contains it.
	 */
	UPROPERTY(EditAnywhere, config, Category = TracerSetup, meta = (ConfigRestartRequired = true))
	FString Tracer_URL;

	/** Choose whether to enable tracing */
	UPROPERTY(EditAnywhere, config, Category = TracerSetup, meta = (ConfigRestartRequired = true))
	bool Tracer_Enabled;

	/** Choose whether to display tracer logs in log view */
	UPROPERTY(EditAnywhere, config, Category = TracerSetup, meta = (ConfigRestartRequired = true))
	bool Tracer_EnableDebugLog;

	/**
	 * Save and overwrite runtime modifications to the connections on exit.
	 * The property is checked on exit.
	 * If set to false, all the changes (compared with the startup) will be lost, even if it was set to true during application lifetime.
	 * You still can save current settings state during editing regardless of this property with a ApiGearConnectionsStore::OverwriteAndSaveConnectionsToSettings function.
	 */
	UPROPERTY(EditAnywhere, config, Category = ConnectionSetup, meta = (ConfigRestartRequired = true, Display = "Use runtime changes instead of settings"))
	bool bSaveRuntimeEdit;

	/** Automatically starts the Hosted OLink Server. */
	UPROPERTY(EditAnywhere, config, Category = OLinkHostSetup)
	bool OLINK_AutoStart;

	/** Port on which Hosted OLink Server is listening.*/
	UPROPERTY(EditAnywhere, config, Category = OLinkHostSetup)
	uint32 OLINK_Port;

	/** Modify connections */
	UPROPERTY(EditAnywhere, config, Category = ConnectionSetup, meta = (ConfigRestartRequired = true))
	TMap<FString, FApiGearConnectionSetting> Connections;
};
