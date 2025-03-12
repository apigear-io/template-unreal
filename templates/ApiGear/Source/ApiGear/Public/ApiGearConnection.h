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

///  Used when Network Layer Connection changes its state to connected(true) or any other connection state (false).
DECLARE_MULTICAST_DELEGATE_OneParam(FApiGearConnectionIsConnectedDelegate, bool);
///  Used when Network Layer Connection changes its state.
DECLARE_MULTICAST_DELEGATE_OneParam(FApiGearConnectionStateChangedDelegate, EApiGearConnectionState);
/**
 * @brief Used when the interface client changes its subscription status:
 * either is plugged in the network and ready to use with protocol of your choice (true)
 * or it won't be able to properly communicate with server side (false).
 * An established network connection (ConnectionIsConnectedDelegate with true parameter) is often necessary, but not sufficient (depending on your setup and used protocol)
 * for the Api client implementation to be used.
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FApiGearRemoteApiSubscriptionStatusChangedDelegateBP, bool, IsSubscribed);
DECLARE_MULTICAST_DELEGATE_OneParam(FApiGearRemoteApiSubscriptionStatusChangedDelegate, bool /* IsSubscribed */);

/**
 * @brief An interface for all connections meant to be used by ApiGear
 * ensures all connections have:
 * - settings for reconnection
 * - current state
 * - general state and settings accessors
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
	virtual FApiGearConnectionIsConnectedDelegate& GetIsConnectedChangedDelegate() = 0;
	virtual FApiGearConnectionStateChangedDelegate& GetConnectionStateChangedDelegate() = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection")
	virtual void Configure(FString InServerURL, bool bInAutoReconnectEnabled) = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection")
	virtual void Connect() = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection")
	virtual void OnConnected() = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection")
	virtual void Disconnect() = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection")
	virtual void OnDisconnected(bool bReconnect) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection")
	virtual bool IsConnected() = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection")
	virtual void StopReconnecting() = 0;

	/** Returns the endpoint identifier for this connection, e.g. simulation or phone_service */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection")
	virtual FString GetUniqueEndpointIdentifier() const = 0;

	/** Returns the server URL */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection")
	virtual FString GetServerURL() const = 0;

	/** Returns the type identifier for this connection, e.g. olink */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection")
	virtual FString GetConnectionProtocolIdentifier() const = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection")
	virtual EApiGearConnectionState GetConnectionState() = 0;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection")
	virtual void SetAutoReconnectEnabled(bool enable) = 0;
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Connection")
	virtual bool IsAutoReconnectEnabled() const = 0;
};
