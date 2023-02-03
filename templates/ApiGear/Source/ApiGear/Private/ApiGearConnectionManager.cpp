// Copyright Epic Games, Inc. All Rights Reserved
#include "ApiGearConnectionManager.h"

UApiGearConnectionManager::UApiGearConnectionManager()
{
}

void UApiGearConnectionManager::Initialize(FSubsystemCollectionBase& Collection)
{
	OLinkConnection = NewObject<UUnrealOLink>(this, TEXT("OLinkConnection"));

	OLinkConnection->AddToRoot();
	OLinkConnection->GetIsConnectedChangedDelegate().AddUObject(this, &UApiGearConnectionManager::OnIsOLinkConnectedChanged);
}

void UApiGearConnectionManager::Deinitialize()
{
	OLinkConnection->Disconnect();

	OLinkConnection = nullptr;
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
