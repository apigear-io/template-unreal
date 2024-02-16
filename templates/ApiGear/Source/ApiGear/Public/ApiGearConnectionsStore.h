// Copyright Epic Games, Inc. All Rights Reserved
#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Object.h"
#include "Subsystems/EngineSubsystem.h"
#include "Engine/EngineTypes.h"
#include "Templates/SharedPointer.h"
#include "ApiGearConnection.h"
#include "ApiGearConnectionsStore.generated.h"

APIGEAR_API DECLARE_LOG_CATEGORY_EXTERN(LogApiGearConnectionsStore, Log, All);

/**
 * Creates and stores connections based on configured connections in settings.
 *  @see ApiGearSettings
 * 
 * Handles all connections which inherit from the IApiGearConnection interface.
 * @warning For custom protocols make sure you've registered your own protocol factory with a RegisterConnectionFactory.
 * before this class/module is initialized.
 * You may use implemented ApiGearOLink module as an example.
 */
UCLASS(BlueprintType)
class APIGEAR_API UApiGearConnectionsStore : public UEngineSubsystem
{
	GENERATED_BODY()

public:
	UApiGearConnectionsStore();
	/** A type of function for creating connections*/
	using FConnectionFactoryFunction = TFunction<TScriptInterface<IApiGearConnection>(UObject*, FString)>;

	/** 
	 * Register custom factories of connections.
	 * This function must be called before this class or module are initialized.
	 * @see ApiGearOLink.
	 */
	static bool RegisterConnectionFactory(FString ConnectionTypeIdentifier, FConnectionFactoryFunction FactoryFunction);

	// USubssystem functions
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|ConnectionsStore")
	TScriptInterface<IApiGearConnection> GetConnection(FString UniqueEndpointIdentifier) const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|ConnectionsStore")
	TMap<FString, TScriptInterface<IApiGearConnection>> GetConnections() const;

	bool AddConnection(TScriptInterface<IApiGearConnection> Connection);
	UFUNCTION(BlueprintCallable, Category = "ApiGear|ConnectionsStore")
	bool AddConnection(FString UniqueEndpointIdentifier, TScriptInterface<IApiGearConnection> Connection);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|ConnectionsStore")
	bool RemoveConnection(FString UniqueEndpointIdentifier);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|ConnectionsStore")
	bool DoesConnectionExist(FString UniqueEndpointIdentifier) const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|ConnectionsStore")
	void ConnectAll() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|ConnectionsStore")
	void DisconnectAll() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|ConnectionsStore")
	TArray<FString> GetAvailableProtocols() const;

	/** Replaces ApiGear plugin settings configured for the project with all currently added connections. */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|ConnectionsStore")
	void OverwriteAndSaveConnectionsToSettings() const;

private:
	UPROPERTY()
	TMap<FString, TScriptInterface<IApiGearConnection>> Connections;
	static TMap<FString, FConnectionFactoryFunction> Factories;
};
