#pragma once

#include "UObject/Interface.h"
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ApiGearConnection.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogApiGearConnection, Log, All);

/**
 * Enumeration EApiGearConnectionState
 */
UENUM(BlueprintType)
enum class EApiGearConnectionState : uint8
{
	Disconnected UMETA(Displayname = "Disconnected"),
	Connecting UMETA(Displayname = "Connecting"),
	Connected UMETA(Displayname = "Connected")
};

/**  Used when Network Layer Connection changes its state to connected(true) or any other connection state(false). */
DECLARE_MULTICAST_DELEGATE_OneParam(FApiGearConnectionIsConnectedDelegate, bool);
/** Used when Network Layer Connection changes its state. */
DECLARE_MULTICAST_DELEGATE_OneParam(FApiGearConnectionStateChangedDelegate, EApiGearConnectionState);
/**
 * Used when the interface client changes its subscription status:
 * either is plugged in the network and ready to use with protocol of your choice (true)
 * or it won't be able to properly communicate with server side (false).
 * An established network connection (ConnectionIsConnectedDelegate with true parameter) is often necessary, but not sufficient (depending on your setup and used protocol)
 * for the Api client implementation to be used.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FApiGearRemoteApiSubscriptionStatusChangedDelegate, bool, IsSubscribed);

/** 
 * An interface for all connections meant to be used by ApiGear
 * ensures all connections have:
 * - settings for reconnection
 * - current state
 * - general state and settings accessors
 * @see AbstractApiGearConnection for implementation of common functionality.
 */
UINTERFACE(MinimalAPI, meta = (CannotImplementInterfaceInBlueprint))
class UApiGearConnection : public UInterface
{
	GENERATED_BODY()
};

class APIGEAR_API IApiGearConnection
{
	GENERATED_BODY()

public:
	/** Returns a delegate for notifications informing whether connection is ready to use
	* @see ApiGearConnectionIsConnectedDelegate
	*/
	virtual FApiGearConnectionIsConnectedDelegate& GetIsConnectedChangedDelegate() = 0;
	/** Returns a delegate for notifications informing about the connection state.
	* @see FApiGearConnectionStateChangedDelegate
	*/
	virtual FApiGearConnectionStateChangedDelegate& GetConnectionStateChangedDelegate() = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection")
	virtual void Configure(FString InServerURL, bool bInAutoReconnectEnabled) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection")
	/** Call this function to request connection to be established */
	virtual void Connect() = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection")
	/** A callback for when the network connection is established,
	 * Use to finalize connect related actions in the implemented connection, 
	 * For notifications on when connection is disconnected use GetIsConnectedChangedDelegate or ApiGearConnectionStateChangedDelegate.
	 */
	virtual void OnConnected() = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection")
	/** Call this function to request closing connection. */
	virtual void Disconnect() = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection")
	/** A callback for when the network connection has closed,
	 * use to finalize disconnect-related actions in the implemented connection.
	 * For notifications on when connection is disconnected use GetIsConnectedChangedDelegate or ApiGearConnectionStateChangedDelegate.
	 */
	virtual void OnDisconnected(bool bReconnect) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection")
	virtual bool IsConnected() = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection")
	virtual void StopReconnecting() = 0;

	/** Returns the endpoint identifier for this connection, e.g. simulation or phone_service*/
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection")
	virtual FString GetUniqueEndpointIdentifier() const = 0;

	/** Returns the server URL */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection")
	virtual FString GetServerURL() const = 0;

	/** Returns the identifier of protocol used for this connection, e.g. olink */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection")
	virtual FString GetConnectionProtocolIdentifier() const = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection")
	virtual EApiGearConnectionState GetConnectionState() = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection")
	virtual void SetAutoReconnectEnabled(bool enable) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection")
	virtual bool IsAutoReconnectEnabled() const = 0;
};
