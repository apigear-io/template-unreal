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

	void OnConnected() final;
	void OnDisconnected(bool bReconnect) final;
	void Connect() final;
	void Disconnect() final;
	void StopReconnecting() override;
	bool IsConnected() PURE_VIRTUAL(UAbstractApiGearConnection::IsConnected, return false;);

	FString GetUniqueEndpointIdentifier() const PURE_VIRTUAL(UAbstractApiGearConnection::GetUniqueEndpointIdentifier, return "";);
	FString GetConnectionProtocolIdentifier() const PURE_VIRTUAL(UAbstractApiGearConnection::GetConnectionProtocolIdentifier, return "";);

	EApiGearConnectionState GetConnectionState() override;

	void SetAutoReconnectEnabled(bool enable) override;
	bool IsAutoReconnectEnabled() const override;

private:
	void SetConnectionState(EApiGearConnectionState State);

	virtual void OnConnected_Implementation() PURE_VIRTUAL(UAbstractApiGearConnection::OnConnected_Implementation, );
	virtual void OnDisconnected_Implementation(bool bReconnect) PURE_VIRTUAL(UAbstractApiGearConnection::OnDisconnected_Implementation, );
	virtual void Connect_Implementation() PURE_VIRTUAL(UAbstractApiGearConnection::Connect_Implementation, );
	virtual void Disconnect_Implementation() PURE_VIRTUAL(UAbstractApiGearConnection::Disconnect_Implementation, );

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
