#pragma once

#include "UObject/Interface.h"
#include "CoreMinimal.h"
#include "Containers/Ticker.h"
#include "UObject/NoExportTypes.h"
#include "Runtime/Launch/Resources/Version.h"
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

DECLARE_MULTICAST_DELEGATE_OneParam(FApiGearConnectionIsConnectedDelegate, bool);
DECLARE_MULTICAST_DELEGATE_OneParam(FApiGearConnectionStateChangedDelegate, EApiGearConnectionState);

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
