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

/**
 * Implements the connections store for the ApiGear plugin.
 * 
 * Can handle all connections which inherit from the IApiGearConnection interface.
 * To register your own protocol, you need to call RegisterConnectionFactory
 * before this class/module is initialized. The ApiGearOLink module is an example
 * how this can be done.
 */
UCLASS(BlueprintType)
class APIGEAR_API UApiGearConnectionsStore : public UEngineSubsystem
{
	GENERATED_BODY()

public:
	UApiGearConnectionsStore();
	/** A type of function for creating connections*/
	using FConnectionFactoryFunction = TFunction<TScriptInterface<IApiGearConnection>(UObject*, FString)>;

	/** register factories for different types of connections */
	static bool RegisterConnectionFactory(FString ConnectionTypeIdentifier, FConnectionFactoryFunction FactoryFunction);

	// USubssystem functions
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection")
	TScriptInterface<IApiGearConnection> GetConnection(FString UniqueEndpointIdentifier) const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection")
	TMap<FString, TScriptInterface<IApiGearConnection>> GetConnections() const;

	bool AddConnection(TScriptInterface<IApiGearConnection> Connection);
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection")
	bool AddConnection(FString UniqueEndpointIdentifier, TScriptInterface<IApiGearConnection> Connection);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection")
	bool RemoveConnection(FString UniqueEndpointIdentifier);

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection")
	bool DoesConnectionExist(FString UniqueEndpointIdentifier) const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection")
	void ConnectAll() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection")
	void DisconnectAll() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection")
	TArray<FString> GetAvailableProtocols() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection")
	void OverwriteAndSaveConnectionsToSettings() const;

private:
	UPROPERTY()
	TMap<FString, TScriptInterface<IApiGearConnection>> Connections;
	static TMap<FString, FConnectionFactoryFunction> Factories;
};
