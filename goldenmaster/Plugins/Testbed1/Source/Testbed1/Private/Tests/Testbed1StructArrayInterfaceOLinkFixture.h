
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"
#include "OLinkCommon.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/Testbed1_data.h"
#include "HAL/Platform.h"
#include "Testbed1StructArrayInterfaceOLinkFixture.generated.h"

class UTestbed1StructArrayInterfaceOLinkSpec;
class ITestbed1StructArrayInterfaceInterface;
class UTestbed1StructArrayInterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

UCLASS()
class UTestbed1StructArrayInterfaceOLinkHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTestbed1StructArrayInterfaceOLinkSpec* InSpec);

	UFUNCTION()
	void PropBoolPropertyCb(const TArray<FTestbed1StructBool>& PropBool);

	UFUNCTION()
	void PropIntPropertyCb(const TArray<FTestbed1StructInt>& PropInt);

	UFUNCTION()
	void PropFloatPropertyCb(const TArray<FTestbed1StructFloat>& PropFloat);

	UFUNCTION()
	void PropStringPropertyCb(const TArray<FTestbed1StructString>& PropString);

	UFUNCTION()
	void PropEnumPropertyCb(const TArray<ETestbed1Enum0>& PropEnum);

	UFUNCTION()
	void SigBoolSignalCb(const TArray<FTestbed1StructBool>& ParamBool);

	UFUNCTION()
	void SigIntSignalCb(const TArray<FTestbed1StructInt>& ParamInt);

	UFUNCTION()
	void SigFloatSignalCb(const TArray<FTestbed1StructFloat>& ParamFloat);

	UFUNCTION()
	void SigStringSignalCb(const TArray<FTestbed1StructString>& ParamString);

	UFUNCTION()
	void SigEnumSignalCb(const TArray<ETestbed1Enum0>& ParamEnum);

	UFUNCTION()
	void _SubscriptionStatusChangedCb(bool bSubscribed);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTestbed1StructArrayInterfaceOLinkSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX

class FTestbed1StructArrayInterfaceOLinkFixture
{
public:
	FTestbed1StructArrayInterfaceOLinkFixture();
	~FTestbed1StructArrayInterfaceOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed1StructArrayInterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTestbed1StructArrayInterfaceOLinkHelper> GetHelper();
	UOLinkHost* GetHost();
	UTestbed1StructArrayInterfaceOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed1StructArrayInterfaceInterface> testImplementation;
	TSoftObjectPtr<UTestbed1StructArrayInterfaceOLinkHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
