
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbNames_data.h"
#include "HAL/Platform.h"
#include "TbNamesNamEsMsgBusFixture.generated.h"

class UTbNamesNamEsMsgBusSpec;
class ITbNamesNamEsInterface;
class UTbNamesNamEsMsgBusAdapter;
class IApiGearConnection;

UCLASS()
class UTbNamesNamEsMsgBusHelper : public UObject
{
	GENERATED_BODY()
public:
	~UTbNamesNamEsMsgBusHelper();

	void SetSpec(UTbNamesNamEsMsgBusSpec* InSpec);

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
	void _ConnectionStatusChangedCb(bool bConnected);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbNamesNamEsMsgBusSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

class FTbNamesNamEsMsgBusFixture
{
public:
	FTbNamesNamEsMsgBusFixture();
	~FTbNamesNamEsMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbNamesNamEsInterface> GetImplementation();
	TSoftObjectPtr<UTbNamesNamEsMsgBusHelper> GetHelper();
	UTbNamesNamEsMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbNamesNamEsInterface> testImplementation;
	TSoftObjectPtr<UTbNamesNamEsMsgBusHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
