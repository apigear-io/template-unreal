#pragma once

#include "ApiGearConnection.h"
#include "CoreMinimal.h"
#include "Containers/Ticker.h"
#include "UObject/NoExportTypes.h"
#include "Runtime/Launch/Resources/Version.h"
#include "AbstractApiGearConnection.generated.h"

/**
 * @brief Abstract base for IApiGearConnection implementation
 * Implements state management and handles common reconnection functionality. Exposes delegates.
 * Does not add the actual connection handling - it needs to be implemented by the final connection.
 */
UCLASS(Abstract, NotBlueprintable)
class APIGEAR_API UAbstractApiGearConnection : public UObject, public IApiGearConnection
{
	GENERATED_BODY()

public:
	explicit UAbstractApiGearConnection(const FObjectInitializer& ObjectInitializer);
	FApiGearConnectionIsConnectedDelegate& GetIsConnectedChangedDelegate() override;
	FApiGearConnectionStateChangedDelegate& GetConnectionStateChangedDelegate() override;

	void Configure(FString InServerURL, bool bInAutoReconnectEnabled) PURE_VIRTUAL(UAbstractApiGearConnection::Configure, );
	FString GetServerURL() const PURE_VIRTUAL(UAbstractApiGearConnection::GetServerURL, return "";);

	void OnConnected() override;
	void OnDisconnected(bool bReconnect) override;
	void Connect() override;
	void Disconnect() PURE_VIRTUAL(UAbstractApiGearConnection::Disconnect, );
	bool IsConnected() PURE_VIRTUAL(UAbstractApiGearConnection::IsConnected, return false;);
	void StopReconnecting() override;

	FString GetUniqueEndpointIdentifier() const PURE_VIRTUAL(UAbstractApiGearConnection::GetUniqueEndpointIdentifier, return "";);
	FString GetConnectionProtocolIdentifier() const PURE_VIRTUAL(UAbstractApiGearConnection::GetConnectionProtocolIdentifier, return "";);

	EApiGearConnectionState GetConnectionState() override;

	void SetAutoReconnectEnabled(bool enable) override;
	bool IsAutoReconnectEnabled() const override;

private:
	void SetConnectionState(EApiGearConnectionState State);

	FApiGearConnectionIsConnectedDelegate IsConnectedChanged;
	FApiGearConnectionStateChangedDelegate ConnectionStateChanged;

	bool bIsAutoReconnectEnabled;
	bool bStopReconnectingRequested;

#if (ENGINE_MAJOR_VERSION >= 5)
	FTSTicker::FDelegateHandle RetryTickerHandle;
#else
	FDelegateHandle RetryTickerHandle;
#endif
	FTickerDelegate RetryTickerDelegate;

	EApiGearConnectionState ConnectionState;
};
