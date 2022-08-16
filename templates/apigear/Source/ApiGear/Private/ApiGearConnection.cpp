#include "ApiGearConnection.h"

DEFINE_LOG_CATEGORY(LogApiGearConnection);

UAbstractApiGearConnection::UAbstractApiGearConnection(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , bIsAutoReconnectEnabled(true)
    , bStopReconnectingRequested(false)
{
    RetryTickerDelegate.BindUFunction(this, "Connect");
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

    // disable reconnect ticker
    FTicker::GetCoreTicker().RemoveTicker(RetryTickerHandle);
}

void UAbstractApiGearConnection::OnDisconnected(bool bReconnect)
{
    SetConnectionState(EApiGearConnectionState::Disconnected);

    if (bIsAutoReconnectEnabled && bReconnect && !bStopReconnectingRequested)
    {
        UE_LOG(LogApiGearConnection, Display, TEXT("Setting retry ticker"));
        RetryTickerHandle = FTicker::GetCoreTicker().AddTicker(RetryTickerDelegate, 1.0f);
    }

    if(bStopReconnectingRequested)
    {
        bStopReconnectingRequested = false;
    }
}

void UAbstractApiGearConnection::Connect()
{
    SetConnectionState(EApiGearConnectionState::Connecting);
}

void UAbstractApiGearConnection::StopReconnecting()
{   
    bStopReconnectingRequested = true;
    // disable reconnect ticker
    FTicker::GetCoreTicker().RemoveTicker(RetryTickerHandle);
}

void UAbstractApiGearConnection::SetAutoReconnectEnabled(bool enabled)
{
    if (bIsAutoReconnectEnabled == true && enabled == false)
    {
        // disable reconnect ticker
        FTicker::GetCoreTicker().RemoveTicker(RetryTickerHandle);
    }
    bIsAutoReconnectEnabled = enabled;
}

bool UAbstractApiGearConnection::IsAutoReconnectEnabled()
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
