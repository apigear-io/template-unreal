
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"
#include "OLinkCommon.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/Testbed1_data.h"
#include "HAL/Platform.h"
#include "Testbed1StructArray2InterfaceOLinkFixture.generated.h"

class UTestbed1StructArray2InterfaceOLinkSpec;
class ITestbed1StructArray2InterfaceInterface;
class UTestbed1StructArray2InterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

UCLASS()
class UTestbed1StructArray2InterfaceOLinkHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTestbed1StructArray2InterfaceOLinkSpec* InSpec);

	UFUNCTION()
	void PropBoolPropertyCb(const FTestbed1StructBoolWithArray& PropBool);
	UFUNCTION()
	void PropBoolPropertyChangeLocalCheckRemoteCb(const FTestbed1StructBoolWithArray& PropBool);
	UFUNCTION()
	void PropBoolPropertyChangeLocalChangeRemoteCb(const FTestbed1StructBoolWithArray& PropBool);

	UFUNCTION()
	void PropIntPropertyCb(const FTestbed1StructIntWithArray& PropInt);
	UFUNCTION()
	void PropIntPropertyChangeLocalCheckRemoteCb(const FTestbed1StructIntWithArray& PropInt);
	UFUNCTION()
	void PropIntPropertyChangeLocalChangeRemoteCb(const FTestbed1StructIntWithArray& PropInt);

	UFUNCTION()
	void PropFloatPropertyCb(const FTestbed1StructFloatWithArray& PropFloat);
	UFUNCTION()
	void PropFloatPropertyChangeLocalCheckRemoteCb(const FTestbed1StructFloatWithArray& PropFloat);
	UFUNCTION()
	void PropFloatPropertyChangeLocalChangeRemoteCb(const FTestbed1StructFloatWithArray& PropFloat);

	UFUNCTION()
	void PropStringPropertyCb(const FTestbed1StructStringWithArray& PropString);
	UFUNCTION()
	void PropStringPropertyChangeLocalCheckRemoteCb(const FTestbed1StructStringWithArray& PropString);
	UFUNCTION()
	void PropStringPropertyChangeLocalChangeRemoteCb(const FTestbed1StructStringWithArray& PropString);

	UFUNCTION()
	void PropEnumPropertyCb(const FTestbed1StructEnumWithArray& PropEnum);
	UFUNCTION()
	void PropEnumPropertyChangeLocalCheckRemoteCb(const FTestbed1StructEnumWithArray& PropEnum);
	UFUNCTION()
	void PropEnumPropertyChangeLocalChangeRemoteCb(const FTestbed1StructEnumWithArray& PropEnum);

	UFUNCTION()
	void SigBoolSignalCb(const FTestbed1StructBoolWithArray& ParamBool);

	UFUNCTION()
	void SigIntSignalCb(const FTestbed1StructIntWithArray& ParamInt);

	UFUNCTION()
	void SigFloatSignalCb(const FTestbed1StructFloatWithArray& ParamFloat);

	UFUNCTION()
	void SigStringSignalCb(const FTestbed1StructStringWithArray& ParamString);

	UFUNCTION()
	void _SubscriptionStatusChangedCb(bool bSubscribed);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTestbed1StructArray2InterfaceOLinkSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX

class FTestbed1StructArray2InterfaceOLinkFixture
{
public:
	FTestbed1StructArray2InterfaceOLinkFixture();
	~FTestbed1StructArray2InterfaceOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed1StructArray2InterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTestbed1StructArray2InterfaceOLinkHelper> GetHelper();
	UOLinkHost* GetHost();
	UTestbed1StructArray2InterfaceOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed1StructArray2InterfaceInterface> testImplementation;
	TSoftObjectPtr<UTestbed1StructArray2InterfaceOLinkHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
