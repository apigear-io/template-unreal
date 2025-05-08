
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSimple/Generated/api/TbSimple_data.h"
#include "TbSimpleNoSignalsInterfaceImplFixture.generated.h"

class UTbSimpleNoSignalsInterfaceImplSpec;
class ITbSimpleNoSignalsInterfaceInterface;

UCLASS()
class UTbSimpleNoSignalsInterfaceImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTbSimpleNoSignalsInterfaceImplSpec* InSpec);

	UFUNCTION()
	void PropBoolPropertyCb(bool bPropBool);

	UFUNCTION()
	void PropIntPropertyCb(int32 PropInt);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSimpleNoSignalsInterfaceImplSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSimpleNoSignalsInterfaceImplFixture
{
public:
	FTbSimpleNoSignalsInterfaceImplFixture();
	~FTbSimpleNoSignalsInterfaceImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbSimpleNoSignalsInterfaceImplHelper> GetHelper();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbSimpleNoSignalsInterfaceImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
