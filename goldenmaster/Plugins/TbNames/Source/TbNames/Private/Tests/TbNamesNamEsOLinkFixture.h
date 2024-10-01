
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbNames_data.h"
#include "TbNamesNamEsOLinkFixture.generated.h"

class UTbNamesNamEsOLinkSpec;
class ITbNamesNamEsInterface;
class UTbNamesNamEsOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

UCLASS()
class UTbNamesNamEsOLinkHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTbNamesNamEsOLinkSpec* InSpec);

	UFUNCTION()
	void SwitchPropertyCb(bool bSwitch);

	UFUNCTION()
	void SomePropertyPropertyCb(int32 SomeProperty);

	UFUNCTION()
	void SomePoperty2PropertyCb(int32 SomePoperty2);

	UFUNCTION()
	void SomeSignalSignalCb(bool bSomeParam);

	UFUNCTION()
	void SomeSignal2SignalCb(bool bSomeParam);

	UFUNCTION()
	void _SubscriptionStatusChangedCb(bool bSubscribed);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbNamesNamEsOLinkSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

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

#endif // WITH_DEV_AUTOMATION_TESTS
