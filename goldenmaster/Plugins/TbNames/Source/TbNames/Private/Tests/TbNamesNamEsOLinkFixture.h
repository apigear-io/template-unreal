
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"
#include "OLinkCommon.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbNames_data.h"
#include "HAL/Platform.h"
#include "TbNamesNamEsOLinkFixture.generated.h"

class FTbNamesNamEsOLinkFixture;
class ITbNamesNamEsInterface;
class UTbNamesNamEsOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

UCLASS()
class UTbNamesNamEsOLinkHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetParentFixture(TWeakPtr<FTbNamesNamEsOLinkFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void SwitchPropertyCb(bool bSwitch);
	UFUNCTION()
	void SwitchPropertyChangeLocalCheckRemoteCb(bool bSwitch);
	UFUNCTION()
	void SwitchPropertyChangeLocalChangeRemoteCb(bool bSwitch);

	UFUNCTION()
	void SomePropertyPropertyCb(int32 SomeProperty);
	UFUNCTION()
	void SomePropertyPropertyChangeLocalCheckRemoteCb(int32 SomeProperty);
	UFUNCTION()
	void SomePropertyPropertyChangeLocalChangeRemoteCb(int32 SomeProperty);

	UFUNCTION()
	void SomePoperty2PropertyCb(int32 SomePoperty2);
	UFUNCTION()
	void SomePoperty2PropertyChangeLocalCheckRemoteCb(int32 SomePoperty2);
	UFUNCTION()
	void SomePoperty2PropertyChangeLocalChangeRemoteCb(int32 SomePoperty2);

	UFUNCTION()
	void EnumPropertyPropertyCb(ETbNamesEnum_With_Under_scores EnumProperty);
	UFUNCTION()
	void EnumPropertyPropertyChangeLocalCheckRemoteCb(ETbNamesEnum_With_Under_scores EnumProperty);
	UFUNCTION()
	void EnumPropertyPropertyChangeLocalChangeRemoteCb(ETbNamesEnum_With_Under_scores EnumProperty);

	UFUNCTION()
	void SomeSignalSignalCb(bool bSomeParam);

	UFUNCTION()
	void SomeSignal2SignalCb(bool bSomeParam);

	UFUNCTION()
	void _SubscriptionStatusChangedCb(bool bSubscribed);

protected:
	TWeakPtr<FTbNamesNamEsOLinkFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX

class FTbNamesNamEsOLinkFixture
{
public:
	FTbNamesNamEsOLinkFixture();
	~FTbNamesNamEsOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbNamesNamEsInterface> GetImplementation();
	TSoftObjectPtr<UTbNamesNamEsOLinkHelper> GetHelper();
	UOLinkHost* GetHost();
	UTbNamesNamEsOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbNamesNamEsInterface> testImplementation;
	TSoftObjectPtr<UTbNamesNamEsOLinkHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
