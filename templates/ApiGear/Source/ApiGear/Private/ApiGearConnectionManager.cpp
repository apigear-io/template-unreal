// Copyright Epic Games, Inc. All Rights Reserved
#include "ApiGearConnectionManager.h"

UApiGearConnectionManager::UApiGearConnectionManager()
{
}

void UApiGearConnectionManager::Initialize(FSubsystemCollectionBase& Collection)
{
	OLinkConnection = NewObject<UUnrealOLink>(this, TEXT("OLinkConnection"));
	SimulationConnection = NewObject<UUnrealSimulation>(this, TEXT("SimulationConnection"));

	OLinkConnection->AddToRoot();
	OLinkConnection->GetIsConnectedChangedDelegate().AddUObject(this, &UApiGearConnectionManager::OnIsOLinkConnectedChanged);
	SimulationConnection->AddToRoot();
	SimulationConnection->GetIsConnectedChangedDelegate().AddUObject(this, &UApiGearConnectionManager::OnIsSimulationConnectedChanged);
}

void UApiGearConnectionManager::Deinitialize()
{
	OLinkConnection->Disconnect();
	SimulationConnection->Disconnect();

	OLinkConnection = nullptr;
	SimulationConnection = nullptr;
}

UUnrealOLink* UApiGearConnectionManager::UApiGearConnectionManager::GetOLinkConnection()
{
	return OLinkConnection;
}

bool UApiGearConnectionManager::GetIsOLinkConnected() const
{
	return OLinkConnection->IsConnected();
}

void UApiGearConnectionManager::ConnectOLink() const
{
	OLinkConnection->Connect();
}

void UApiGearConnectionManager::DisconnectOLink() const
{
	OLinkConnection->Disconnect();
}

void UApiGearConnectionManager::OnIsOLinkConnectedChanged(bool bIsConnected)
{
	IsOLinkConnectedChanged.Broadcast(bIsConnected);
}

UUnrealSimulation* UApiGearConnectionManager::UApiGearConnectionManager::GetSimulationConnection()
{
	return SimulationConnection;
}

bool UApiGearConnectionManager::GetIsSimulationConnected() const
{
	return SimulationConnection->IsConnected();
}

void UApiGearConnectionManager::ConnectSimulation() const
{
	SimulationConnection->Connect();
}

void UApiGearConnectionManager::DisconnectSimulation() const
{
	SimulationConnection->Disconnect();
}

void UApiGearConnectionManager::OnIsSimulationConnectedChanged(bool bIsConnected)
{
	IsSimulationConnectedChanged.Broadcast(bIsConnected);
}
