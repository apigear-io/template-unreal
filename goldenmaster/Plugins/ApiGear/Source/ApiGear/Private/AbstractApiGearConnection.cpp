#include "AbstractApiGearConnection.h"

DEFINE_LOG_CATEGORY(LogApiGearConnection);

UAbstractApiGearConnection::UAbstractApiGearConnection(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	, bIsAutoReconnectEnabled(true)
	, bStopReconnectingRequested(false)
{
	RetryTickerDelegate.BindUFunction(this, "Connect");
	ConnectionTimeoutDelegate.BindUObject(this, &UAbstractApiGearConnection::OnConnectionTimeout);
}

bool UAbstractApiGearConnection::OnConnectionTimeout(float DeltaTime)
{
	if (GetConnectionState() == EApiGearConnectionState::Connecting)
	{
		UE_LOG(LogApiGearConnection, Warning, TEXT("Connection timeout"));
		Disconnect();
	}
	return false;
}

FApiGearConnectionIsConnectedDelegate& UAbstractApiGearConnection::GetIsConnectedChangedDelegate()
{
	return IsConnectedChanged;
}

FApiGearConnectionStateChangedDelegate& UAbstractApiGearConnection::GetConnectionStateChangedDelegate()
{
	return ConnectionStateChanged;
}

void UAbstractApiGearConnection::OnConnected()
{
	SetConnectionState(EApiGearConnectionState::Connected);

	ApiGearTicker::GetCoreTicker().RemoveTicker(RetryTickerHandle);
	ApiGearTicker::GetCoreTicker().RemoveTicker(ConnectionTimeoutHandle);

	OnConnected_Implementation();
}

void UAbstractApiGearConnection::OnDisconnected(bool bReconnect)
{
	OnDisconnected_Implementation(bReconnect);

	SetConnectionState(EApiGearConnectionState::Disconnected);

	ApiGearTicker::GetCoreTicker().RemoveTicker(ConnectionTimeoutHandle);

	if (bIsAutoReconnectEnabled && bReconnect && !bStopReconnectingRequested)
	{
		RetryTickerHandle = ApiGearTicker::GetCoreTicker().AddTicker(RetryTickerDelegate, 1.0f);
	}

	if (bStopReconnectingRequested)
	{
		bStopReconnectingRequested = false;
	}
}

void UAbstractApiGearConnection::Connect()
{
	if (IsConnected() || GetConnectionState() == EApiGearConnectionState::Connecting)
	{
		return;
	}
	SetConnectionState(EApiGearConnectionState::Connecting);

	ConnectionTimeoutHandle = ApiGearTicker::GetCoreTicker().AddTicker(ConnectionTimeoutDelegate, 300.0f);

	Connect_Implementation();
}

void UAbstractApiGearConnection::Disconnect()
{
	EApiGearConnectionState CurrentState = GetConnectionState();

	if (CurrentState == EApiGearConnectionState::Disconnected || CurrentState == EApiGearConnectionState::Disconnecting)
	{
		return;
	}

	UAbstractApiGearConnection::StopReconnecting();
	ApiGearTicker::GetCoreTicker().RemoveTicker(ConnectionTimeoutHandle);
	SetConnectionState(EApiGearConnectionState::Disconnecting);
	Disconnect_Implementation();
}

void UAbstractApiGearConnection::StopReconnecting()
{
	bStopReconnectingRequested = true;
	// disable reconnect ticker
	ApiGearTicker::GetCoreTicker().RemoveTicker(RetryTickerHandle);
}

void UAbstractApiGearConnection::SetAutoReconnectEnabled(bool enabled)
{
	if (bIsAutoReconnectEnabled == true && enabled == false)
	{
		// disable reconnect ticker
		ApiGearTicker::GetCoreTicker().RemoveTicker(RetryTickerHandle);
	}
	bIsAutoReconnectEnabled = enabled;
}

bool UAbstractApiGearConnection::IsAutoReconnectEnabled() const
{
	return bIsAutoReconnectEnabled;
}

EApiGearConnectionState UAbstractApiGearConnection::GetConnectionState()
{
	return ConnectionState;
}

void UAbstractApiGearConnection::SetConnectionState(EApiGearConnectionState State)
{
	ConnectionState = State;
	ConnectionStateChanged.Broadcast(ConnectionState);
	IsConnectedChanged.Broadcast(ConnectionState == EApiGearConnectionState::Connected);
}
