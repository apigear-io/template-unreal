
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSimple/Generated/api/TbSimple_data.h"
#include "TbSimpleNoOperationsInterfaceImplFixture.generated.h"

class UTbSimpleNoOperationsInterfaceImplSpec;
class ITbSimpleNoOperationsInterfaceInterface;

UCLASS()
class UTbSimpleNoOperationsInterfaceImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTbSimpleNoOperationsInterfaceImplSpec* InSpec);

	UFUNCTION()
	void PropBoolPropertyCb(bool bPropBool);

	UFUNCTION()
	void PropIntPropertyCb(int32 PropInt);

	UFUNCTION()
	void SigVoidSignalCb();

	UFUNCTION()
	void SigBoolSignalCb(bool bParamBool);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSimpleNoOperationsInterfaceImplSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSimpleNoOperationsInterfaceImplFixture
{
public:
	FTbSimpleNoOperationsInterfaceImplFixture();
	~FTbSimpleNoOperationsInterfaceImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbSimpleNoOperationsInterfaceImplHelper> GetHelper();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbSimpleNoOperationsInterfaceImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
