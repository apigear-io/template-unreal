// Copyright Epic Games, Inc. All Rights Reserved
#include "ApiGearConnectionsStore.h"
#include "ApiGearSettings.h"

DEFINE_LOG_CATEGORY(LogApiGearConnectionsStore);

TMap<FString, UApiGearConnectionsStore::FConnectionFactoryFunction> UApiGearConnectionsStore::Factories{};

UApiGearConnectionsStore::UApiGearConnectionsStore()
{
}

bool UApiGearConnectionsStore::RegisterConnectionFactory(FString ConnectionTypeIdentifier, FConnectionFactoryFunction FactoryFunction)
{
	if (Factories.Contains(ConnectionTypeIdentifier))
	{
		UE_LOG(LogApiGearConnectionsStore, Warning, TEXT("Register connection factory: %s - already registered"), *ConnectionTypeIdentifier);
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
			UE_LOG(LogApiGearConnectionsStore, Warning, TEXT("No factory to create connection type: %s"), *ConnectionSetting.Value.ProtocolIdentifier);
			continue;
		}

		// create connection
		FConnectionFactoryFunction& ConnectionFactory = Factories[ConnectionSetting.Value.ProtocolIdentifier];
		TScriptInterface<IApiGearConnection> Connection = ConnectionFactory(this, *ConnectionSetting.Key);
		Connection->Configure(ConnectionSetting.Value.URL, ConnectionSetting.Value.AutoReconnectEnabled);

		// connection successfully set up, so add it to the storage
		bool bAddedSuccessfully = AddConnection(Connection);
		check(bAddedSuccessfully);
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
	Connections.Add(Connection->GetUniqueEndpointIdentifier(), Connection);

	return true;
}

bool UApiGearConnectionsStore::AddConnection(FString UniqueEndpointIdentifier, TScriptInterface<IApiGearConnection> Connection)
{
	if (DoesConnectionExist(UniqueEndpointIdentifier))
	{
		UE_LOG(LogApiGearConnectionsStore, Warning, TEXT("Cannot add connection, connection with the same name as \"%s\" already exists."), *UniqueEndpointIdentifier);
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
		UE_LOG(LogApiGearConnectionsStore, Log, TEXT("Cannot remove connection, no connection with name %s registered."), *UniqueEndpointIdentifier);
		return false;
	}

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
