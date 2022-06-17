#pragma once

#include "UObject/Interface.h"
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ApiGearConnection.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogApiGearConnection, Log, All);

DECLARE_MULTICAST_DELEGATE_OneParam(FApiGearConnectionIsConnectedDelegate, bool);

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

	UFUNCTION()
    virtual void Connect() = 0;
	UFUNCTION()
    virtual void OnConnected() = 0;
	UFUNCTION()
    virtual void Disconnect() = 0;
	UFUNCTION()
    virtual void OnDisconnected() = 0;
	UFUNCTION()
    virtual bool IsConnected() = 0;

    UFUNCTION()
    virtual void SetAutoReconnectEnabled(bool enable) = 0;
    UFUNCTION()
    virtual bool IsAutoReconnectEnabled() = 0;
};

UCLASS(Abstract, NotBlueprintType)
class APIGEAR_API UAbstractApiGearConnection:  public UObject, public IApiGearConnection
{
    GENERATED_BODY()

public:
    explicit UAbstractApiGearConnection(const FObjectInitializer& ObjectInitializer);
    FApiGearConnectionIsConnectedDelegate& GetIsConnectedChangedDelegate() override;

	UFUNCTION()
    virtual void OnConnected() override;
	UFUNCTION()
    virtual void OnDisconnected() override;
	UFUNCTION()
    virtual void Connect() PURE_VIRTUAL(UAbstractApiGearConnection::Connect,);
	UFUNCTION()
    virtual void Disconnect() PURE_VIRTUAL(UAbstractApiGearConnection::Disconnect,);
	UFUNCTION()
    virtual bool IsConnected() PURE_VIRTUAL(UAbstractApiGearConnection::IsConnected, return false;);

    UFUNCTION()
    virtual void SetAutoReconnectEnabled(bool enable);
    UFUNCTION()
    virtual bool IsAutoReconnectEnabled();

private:
    FApiGearConnectionIsConnectedDelegate IsConnectedChanged;

    bool bIsAutoReconnectEnabled;

	FTimerHandle RetryTimerHandle;
	FTimerDelegate RetryTimerDelegate;
};
