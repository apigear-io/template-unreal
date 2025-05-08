
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbNames_data.h"
#include "TbNamesNamEsImplFixture.generated.h"

class UTbNamesNamEsImplSpec;
class ITbNamesNamEsInterface;

UCLASS()
class UTbNamesNamEsImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTbNamesNamEsImplSpec* InSpec);

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
	const FDoneDelegate* testDoneDelegate;
	UTbNamesNamEsImplSpec* Spec;
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
