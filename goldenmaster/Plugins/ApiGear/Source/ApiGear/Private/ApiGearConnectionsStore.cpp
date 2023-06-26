// Copyright Epic Games, Inc. All Rights Reserved
#include "ApiGearConnectionsStore.h"
#include "ApiGearSettings.h"

TMap<FString, UApiGearConnectionsStore::FConnectionFactoryFunction> UApiGearConnectionsStore::Factories{};

UApiGearConnectionsStore::UApiGearConnectionsStore()
{
}

bool UApiGearConnectionsStore::RegisterConnectionFactory(FString ConnectionTypeIdentifier, FConnectionFactoryFunction FactoryFunction)
{
	if (Factories.Contains(ConnectionTypeIdentifier))
	{
		UE_LOG(LogTemp, Warning, TEXT("UApiGearConnectionsStore register connection factory: %s - already registered"), *ConnectionTypeIdentifier);
		return false;
	}

	Factories.Add(ConnectionTypeIdentifier, FactoryFunction);

	return true;
}

void UApiGearConnectionsStore::Initialize(FSubsystemCollectionBase& Collection)
{
	UApiGearSettings* settings = GetMutableDefault<UApiGearSettings>();

	for (auto& ConnectionSetting : settings->Connections)
	{
		if (!Factories.Contains(ConnectionSetting.Value.ProtocolIdentifier))
		{
			UE_LOG(LogTemp, Warning, TEXT("No factory to create connection type: %s"), *ConnectionSetting.Value.ProtocolIdentifier);
			continue;
		}

		// create connection
		FConnectionFactoryFunction& ConnectionFactory = Factories[ConnectionSetting.Value.ProtocolIdentifier];
		TScriptInterface<IApiGearConnection> Connection = ConnectionFactory(this, *ConnectionSetting.Key);
		Connection->Configure(ConnectionSetting.Value.URL, ConnectionSetting.Value.AutoReconnectEnabled);

		// connection successfully set up, so add it to the storage
		check(AddConnection(Connection));
	}
}

void UApiGearConnectionsStore::Deinitialize()
{
	DisconnectAll();

	UApiGearSettings* settings = GetMutableDefault<UApiGearSettings>();

	if (settings->bSaveRuntimeEdit)
	{
		OverwriteAndSaveConnectionsToSettings();
	}

	Connections.Reset();
}

void UApiGearConnectionsStore::OverwriteAndSaveConnectionsToSettings() const
{
	UApiGearSettings* settings = GetMutableDefault<UApiGearSettings>();

	// remove existing connections in settings
	settings->Connections.Reset();

	for (auto& Connection : Connections)
	{
		FApiGearConnectionSetting Setting;
		IApiGearConnection* ConnectionPointer = static_cast<IApiGearConnection*>(Connection.Value.GetInterface());
		Setting.AutoReconnectEnabled = ConnectionPointer->IsAutoReconnectEnabled();
		Setting.ProtocolIdentifier = ConnectionPointer->GetConnectionProtocolIdentifier();
		Setting.URL = ConnectionPointer->GetServerURL();
		settings->Connections.Add(Connection.Key, Setting);
	}

	settings->SaveConfig();
}

TScriptInterface<IApiGearConnection> UApiGearConnectionsStore::GetConnection(FString UniqueEndpointIdentifier) const
{
	if (DoesConnectionExist(UniqueEndpointIdentifier))
	{
		return Connections[UniqueEndpointIdentifier];
	}

	return nullptr;
}

TMap<FString, TScriptInterface<IApiGearConnection>> UApiGearConnectionsStore::GetConnections() const
{
	return Connections;
}

bool UApiGearConnectionsStore::AddConnection(TScriptInterface<IApiGearConnection> Connection)
{
	if (DoesConnectionExist(Connection->GetUniqueEndpointIdentifier()))
	{
		return false;
	}

	UE_LOG(LogTemp, Log, TEXT("UApiGearConnectionsStore add connection: %s"), *Connection.GetObject()->GetName());
	Connections.Add(Connection->GetUniqueEndpointIdentifier(), Connection);

	return true;
}

bool UApiGearConnectionsStore::AddConnection(FString UniqueEndpointIdentifier, TScriptInterface<IApiGearConnection> Connection)
{
	if (DoesConnectionExist(UniqueEndpointIdentifier))
	{
		UE_LOG(LogTemp, Warning, TEXT("UApiGearConnectionsStore: Cannot add connection, please choose a different name than \"%s\". "), *UniqueEndpointIdentifier);
		return false;
	}

	Connection.GetObject()->Rename(UniqueEndpointIdentifier.GetCharArray().GetData(), Connection.GetObject()->GetOuter());
	AddConnection(Connection);

	return true;
}

bool UApiGearConnectionsStore::RemoveConnection(FString UniqueEndpointIdentifier)
{
	if (!DoesConnectionExist(UniqueEndpointIdentifier))
	{
		return false;
	}

	UE_LOG(LogTemp, Log, TEXT("UApiGearConnectionsStore remove connection: %s"), *Connections[UniqueEndpointIdentifier].GetObject()->GetName());

	Connections.Remove(UniqueEndpointIdentifier);

	return true;
}

bool UApiGearConnectionsStore::DoesConnectionExist(FString UniqueEndpointIdentifier) const
{
	return Connections.Contains(UniqueEndpointIdentifier);
}

void UApiGearConnectionsStore::ConnectAll() const
{
	for (auto& Connection : Connections)
	{
		IApiGearConnection* ConnectionPointer = static_cast<IApiGearConnection*>(Connection.Value.GetInterface());
		ConnectionPointer->Connect();
	}
}

void UApiGearConnectionsStore::DisconnectAll() const
{
	for (auto& Connection : Connections)
	{
		IApiGearConnection* ConnectionPointer = static_cast<IApiGearConnection*>(Connection.Value.GetInterface());
		ConnectionPointer->Disconnect();
	}
}

TArray<FString> UApiGearConnectionsStore::GetAvailableProtocols() const
{
	TArray<FString> AvailableProtocols;

	Factories.GetKeys(AvailableProtocols);

	return AvailableProtocols;
}
