
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbNames/Generated/api/TbNames_data.h"
#include "TbNamesNamEsImplFixture.generated.h"

class FTbNamesNamEsImplFixture;
class ITbNamesNamEsInterface;

UCLASS()
class UTbNamesNamEsImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetParentFixture(TWeakPtr<FTbNamesNamEsImplFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void SwitchPropertyCb(bool bSwitch);

	UFUNCTION()
	void SomePropertyPropertyCb(int32 SomeProperty);

	UFUNCTION()
	void SomePoperty2PropertyCb(int32 SomePoperty2);

	UFUNCTION()
	void EnumPropertyPropertyCb(ETbNamesEnum_With_Under_scores EnumProperty);

	UFUNCTION()
	void SomeSignalSignalCb(bool bSomeParam);

	UFUNCTION()
	void SomeSignal2SignalCb(bool bSomeParam);

protected:
	TWeakPtr<FTbNamesNamEsImplFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbNamesNamEsImplFixture
{
public:
	FTbNamesNamEsImplFixture();
	~FTbNamesNamEsImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbNamesNamEsInterface> GetImplementation();
	TSoftObjectPtr<UTbNamesNamEsImplHelper> GetHelper();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbNamesNamEsInterface> testImplementation;
	TSoftObjectPtr<UTbNamesNamEsImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
