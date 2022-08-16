// Copyright Epic Games, Inc. All Rights Reserved
#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "UObject/Object.h"
#include "Subsystems/EngineSubsystem.h"
#include "Engine/EngineTypes.h"
#include "Templates/SharedPointer.h"
#include "unrealolink.h"
#include "unrealsimulation.h"
#include "unrealwamp.h"
#include "ApiGearConnectionManager.generated.h"

/**
 * Implements the connection manager for the ApiGear plugin.
 */
UCLASS(BlueprintType)
class APIGEAR_API UApiGearConnectionManager : public UEngineSubsystem
{
	GENERATED_BODY()

	// OLink
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FApiGearConnectionOLinkIsConnectedDelegate, bool, bIsConnected);
	// Simulation
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FApiGearConnectionSimulationIsConnectedDelegate, bool, bIsConnected);

  public:
	UApiGearConnectionManager();

	// USubssystem functions
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Deinitialize() override;

	// OLink
	UUnrealOLink* GetOLinkConnection();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection|OLink")
	bool GetIsOLinkConnected() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection|OLink")
	void ConnectOLink() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection|OLink")
	void DisconnectOLink() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Connection|OLink", DisplayName = "OLink Connection Status Changed")
	FApiGearConnectionOLinkIsConnectedDelegate IsOLinkConnectedChanged;

	// Simulation
	UUnrealSimulation* GetSimulationConnection();

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection|Simulation")
	bool GetIsSimulationConnected() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection|Simulation")
	void ConnectSimulation() const;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection|Simulation")
	void DisconnectSimulation() const;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Connection|Simulation", DisplayName = "Simulation Connection Status Changed")
	FApiGearConnectionSimulationIsConnectedDelegate IsSimulationConnectedChanged;

  private:
	// OLink
	UUnrealOLink* OLinkConnection;

	UPROPERTY(EditAnywhere, BlueprintGetter = GetIsOLinkConnected, Category = "ApiGear|Connection|OLink")
	bool IsOLinkConnected;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection|OLink", BlueprintInternalUseOnly)
	void OnIsOLinkConnectedChanged(bool bIsConnected);

	// Simulation
	UUnrealSimulation* SimulationConnection;

	UPROPERTY(EditAnywhere, BlueprintGetter = GetIsSimulationConnected, Category = "ApiGear|Connection|Simulation")
	bool IsSimulationConnected;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection|Simulation", BlueprintInternalUseOnly)
	void OnIsSimulationConnectedChanged(bool bIsConnected);
};
