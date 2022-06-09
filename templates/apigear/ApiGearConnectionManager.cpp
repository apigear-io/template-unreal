// Copyright Epic Games, Inc. All Rights Reserved
#include "ApiGearConnectionManager.h"

UApiGearConnectionManager::UApiGearConnectionManager()
	: OLinkConnection(MakeShared<UnrealOLink, ESPMode::ThreadSafe>())
{
	OLinkConnection->IsConnectedChanged.AddUObject(this, &UApiGearConnectionManager::OnIsOLinkConnectedChanged);
}

void UApiGearConnectionManager::Initialize(FSubsystemCollectionBase& Collection)
{
	OLinkConnection->connect();
}

void UApiGearConnectionManager::Deinitialize()
{
	OLinkConnection->disconnect();
}

TSharedPtr<UnrealOLink, ESPMode::ThreadSafe> UApiGearConnectionManager::UApiGearConnectionManager::GetOLinkConnection()
{
	return OLinkConnection;
}

bool UApiGearConnectionManager::GetIsOLinkConnected() const
{
	return OLinkConnection->isConnected();
}

void UApiGearConnectionManager::ConnectOLink() const
{
	OLinkConnection->connect();
}

void UApiGearConnectionManager::DisconnectOLink() const
{
	OLinkConnection->disconnect();
}

void UApiGearConnectionManager::OnIsOLinkConnectedChanged(bool bIsConnected)
{
	IsOLinkConnectedChanged.Broadcast(bIsConnected);
}
