#include "ApiGearConnection.h"

DEFINE_LOG_CATEGORY(LogApiGearConnection);

UAbstractApiGearConnection::UAbstractApiGearConnection(const FObjectInitializer& ObjectInitializer)
    : Super(ObjectInitializer)
    , bIsAutoReconnectEnabled(false)
{

}

FApiGearConnectionIsConnectedDelegate& UAbstractApiGearConnection::GetIsConnectedChangedDelegate()
{
    return IsConnectedChanged;
}

void UAbstractApiGearConnection::OnConnected()
{
    IsConnectedChanged.Broadcast(true);

    // disable reconnect timer
    // GEngine->GetWorldFromContextObjectChecked(this)->GetTimerManager().ClearTimer(RetryTimerHandle)
}

void UAbstractApiGearConnection::OnDisconnected()
{
    IsConnectedChanged.Broadcast(false);
    if (bIsAutoReconnectEnabled)
    {
        // RetryTimerDelegate.
        // GEngine->GetWorldFromContextObjectChecked(this)->GetTimerManager().SetTimer(RetryTimerHandle, RetryTimerDelegate, 1.0f, true);
    }
}

void UAbstractApiGearConnection::SetAutoReconnectEnabled(bool enabled)
{
    if (bIsAutoReconnectEnabled == true && enabled == false)
    {
        // disable reconnect timer
        // GEngine->GetWorldFromContextObjectChecked(this)->GetTimerManager().ClearTimer(RetryTimerHandle);
    }
    bIsAutoReconnectEnabled = enabled;
}

bool UAbstractApiGearConnection::IsAutoReconnectEnabled()
{
    return bIsAutoReconnectEnabled;
}
