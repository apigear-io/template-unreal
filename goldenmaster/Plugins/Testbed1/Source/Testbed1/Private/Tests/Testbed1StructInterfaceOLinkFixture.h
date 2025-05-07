
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"
#include "OLinkCommon.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/Testbed1_data.h"
#include "HAL/Platform.h"
#include "Testbed1StructInterfaceOLinkFixture.generated.h"

class UTestbed1StructInterfaceOLinkSpec;
class ITestbed1StructInterfaceInterface;
class UTestbed1StructInterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

UCLASS()
class UTestbed1StructInterfaceOLinkHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTestbed1StructInterfaceOLinkSpec* InSpec);

	UFUNCTION()
	void PropBoolPropertyCb(const FTestbed1StructBool& PropBool);
	UFUNCTION()
	void PropBoolPropertyChangeLocalCheckRemoteCb(const FTestbed1StructBool& PropBool);
	UFUNCTION()
	void PropBoolPropertyChangeLocalChangeRemoteCb(const FTestbed1StructBool& PropBool);

	UFUNCTION()
	void PropIntPropertyCb(const FTestbed1StructInt& PropInt);
	UFUNCTION()
	void PropIntPropertyChangeLocalCheckRemoteCb(const FTestbed1StructInt& PropInt);
	UFUNCTION()
	void PropIntPropertyChangeLocalChangeRemoteCb(const FTestbed1StructInt& PropInt);

	UFUNCTION()
	void PropFloatPropertyCb(const FTestbed1StructFloat& PropFloat);
	UFUNCTION()
	void PropFloatPropertyChangeLocalCheckRemoteCb(const FTestbed1StructFloat& PropFloat);
	UFUNCTION()
	void PropFloatPropertyChangeLocalChangeRemoteCb(const FTestbed1StructFloat& PropFloat);

	UFUNCTION()
	void PropStringPropertyCb(const FTestbed1StructString& PropString);
	UFUNCTION()
	void PropStringPropertyChangeLocalCheckRemoteCb(const FTestbed1StructString& PropString);
	UFUNCTION()
	void PropStringPropertyChangeLocalChangeRemoteCb(const FTestbed1StructString& PropString);

	UFUNCTION()
	void SigBoolSignalCb(const FTestbed1StructBool& ParamBool);

	UFUNCTION()
	void SigIntSignalCb(const FTestbed1StructInt& ParamInt);

	UFUNCTION()
	void SigFloatSignalCb(const FTestbed1StructFloat& ParamFloat);

	UFUNCTION()
	void SigStringSignalCb(const FTestbed1StructString& ParamString);

	UFUNCTION()
	void _SubscriptionStatusChangedCb(bool bSubscribed);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTestbed1StructInterfaceOLinkSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX

class FTestbed1StructInterfaceOLinkFixture
{
public:
	FTestbed1StructInterfaceOLinkFixture();
	~FTestbed1StructInterfaceOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed1StructInterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTestbed1StructInterfaceOLinkHelper> GetHelper();
	UOLinkHost* GetHost();
	UTestbed1StructInterfaceOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed1StructInterfaceInterface> testImplementation;
	TSoftObjectPtr<UTestbed1StructInterfaceOLinkHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
