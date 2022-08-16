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

DECLARE_MULTICAST_DELEGATE_OneParam(FApiGearConnectionIsConnectedDelegate, bool);
DECLARE_MULTICAST_DELEGATE_OneParam(FApiGearConnectionStateChangedDelegate, EApiGearConnectionState);

UINTERFACE(MinimalAPI)
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

	UFUNCTION()
	virtual void Connect() = 0;
	UFUNCTION()
	virtual void OnConnected() = 0;
	UFUNCTION()
	virtual void Disconnect() = 0;
	UFUNCTION()
	virtual void OnDisconnected(bool bReconnect) = 0;
	UFUNCTION()
	virtual bool IsConnected() = 0;
	UFUNCTION()
	virtual void StopReconnecting() = 0;

	UFUNCTION()
	virtual EApiGearConnectionState GetConnectionState() = 0;

	UFUNCTION()
	virtual void SetAutoReconnectEnabled(bool enable) = 0;
	UFUNCTION()
	virtual bool IsAutoReconnectEnabled() = 0;
};

UCLASS(Abstract, NotBlueprintType)
class APIGEAR_API UAbstractApiGearConnection : public UObject, public IApiGearConnection
{
	GENERATED_BODY()

  public:
	explicit UAbstractApiGearConnection(const FObjectInitializer& ObjectInitializer);
	FApiGearConnectionIsConnectedDelegate& GetIsConnectedChangedDelegate() override;
	FApiGearConnectionStateChangedDelegate& GetConnectionStateChangedDelegate() override;

	UFUNCTION()
	virtual void OnConnected() override;
	UFUNCTION()
	virtual void OnDisconnected(bool bReconnect) override;
	UFUNCTION()
	virtual void Connect() override;
	UFUNCTION()
	virtual void Disconnect() PURE_VIRTUAL(UAbstractApiGearConnection::Disconnect, );
	UFUNCTION()
	virtual bool IsConnected() PURE_VIRTUAL(UAbstractApiGearConnection::IsConnected, return false;);
	UFUNCTION()
	virtual void StopReconnecting() override;

	UFUNCTION()
	virtual EApiGearConnectionState GetConnectionState() override;

	UFUNCTION()
	virtual void SetAutoReconnectEnabled(bool enable);
	UFUNCTION()
	virtual bool IsAutoReconnectEnabled();

  private:
	void SetConnectionState(EApiGearConnectionState State);

	FApiGearConnectionIsConnectedDelegate IsConnectedChanged;
	FApiGearConnectionStateChangedDelegate ConnectionStateChanged;

	bool bIsAutoReconnectEnabled;
	bool bStopReconnectingRequested;

	FDelegateHandle RetryTickerHandle;
	FTickerDelegate RetryTickerDelegate;

	EApiGearConnectionState ConnectionState;
};
