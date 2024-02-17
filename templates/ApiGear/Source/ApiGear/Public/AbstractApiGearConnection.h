#pragma once

#include "ApiGearConnection.h"
#include "ApiGearTicker.h"
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Runtime/Launch/Resources/Version.h"
#include "AbstractApiGearConnection.generated.h"

/**
 * Abstract base for IApiGearConnection implementation.
 * Handles common reconnection functionality.
 * Keeps the connection state updated.
 * Exposes delegates for getting notifications of the connection state.
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

	/* Use this function to block AutoReconnect behavior temporarily until the connection is disconnected. */
	void StopReconnecting() override;
	bool IsConnected() PURE_VIRTUAL(UAbstractApiGearConnection::IsConnected, return false;);

	FString GetUniqueEndpointIdentifier() const PURE_VIRTUAL(UAbstractApiGearConnection::GetUniqueEndpointIdentifier, return "";);
	FString GetConnectionProtocolIdentifier() const PURE_VIRTUAL(UAbstractApiGearConnection::GetConnectionProtocolIdentifier, return "";);

	EApiGearConnectionState GetConnectionState() override;

	void SetAutoReconnectEnabled(bool enable) override;
	bool IsAutoReconnectEnabled() const override;

private:
	void SetConnectionState(EApiGearConnectionState State);

	/** 
	 * Implement in derived class to provide actual logic specific for your connection for when network connection is established.
	 * Should not be used directly, instead use OnConnected().
	 */
	virtual void OnConnected_Implementation() PURE_VIRTUAL(UAbstractApiGearConnection::OnConnected_Implementation, );
	/**
	 * Implement in derived class to provide actual logic specific for your connection for when the network connection is over
	 * Should not be used directly, instead use OnDisonnected().
	 */
	virtual void OnDisconnected_Implementation(bool bReconnect) PURE_VIRTUAL(UAbstractApiGearConnection::OnDisconnected_Implementation, );
	/**
	 * Implement in derived class to provide actual logic specific for your connection to establish a connection
	 * Should not be used directly, instead use Connect().
	 */
	virtual void Connect_Implementation() PURE_VIRTUAL(UAbstractApiGearConnection::Connect_Implementation, );
	/** 
	 * Implement in derived class to provide actual logic specific for your connection to close connection
	 * Should not be used directly, instead use Disconnect().
	 */
	virtual void Disconnect_Implementation() PURE_VIRTUAL(UAbstractApiGearConnection::Disconnect_Implementation, );

	FApiGearConnectionIsConnectedDelegate IsConnectedChanged;
	FApiGearConnectionStateChangedDelegate ConnectionStateChanged;

	/** If set to true, the connection if not running will try to reconnect with a time interval, until succeeded */
	bool bIsAutoReconnectEnabled;
	/** Used when the bIsAutoReconnectEnabled is on but reconnection functionality needs to be temporarily stop for disconnecting. */
	bool bStopReconnectingRequested;

	/** Reconnection timer*/
	ApiGear::FDelegateHandle RetryTickerHandle;

	/** Reconnection timer delegate*/
	FTickerDelegate RetryTickerDelegate;

	EApiGearConnectionState ConnectionState;
};
