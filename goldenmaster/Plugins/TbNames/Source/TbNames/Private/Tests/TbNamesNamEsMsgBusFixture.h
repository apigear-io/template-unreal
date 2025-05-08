
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbNames_data.h"
#include "HAL/Platform.h"
#include "TbNamesNamEsMsgBusFixture.generated.h"

class FTbNamesNamEsMsgBusFixture;
class ITbNamesNamEsInterface;
class UTbNamesNamEsMsgBusAdapter;
class IApiGearConnection;

UCLASS()
class UTbNamesNamEsMsgBusHelper : public UObject
{
	GENERATED_BODY()
public:
	~UTbNamesNamEsMsgBusHelper();

	void SetParentFixture(TWeakPtr<FTbNamesNamEsMsgBusFixture> InFixture);
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
	void _ConnectionStatusChangedCb(bool bConnected);

protected:
	TWeakPtr<FTbNamesNamEsMsgBusFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

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

#endif // WITH_DEV_AUTOMATION_TESTS
