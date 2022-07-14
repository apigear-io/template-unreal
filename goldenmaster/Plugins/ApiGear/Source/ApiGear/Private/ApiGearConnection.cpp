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

void UAbstractApiGearConnection::OnConnected()
{
    IsConnectedChanged.Broadcast(true);

    // disable reconnect ticker
    FTicker::GetCoreTicker().RemoveTicker(RetryTickerHandle);
}

void UAbstractApiGearConnection::OnDisconnected(bool bReconnect)
{
    IsConnectedChanged.Broadcast(false);
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
