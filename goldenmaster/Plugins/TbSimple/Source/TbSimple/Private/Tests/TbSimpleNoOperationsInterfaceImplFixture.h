
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSimple_data.h"
#include "TbSimpleNoOperationsInterfaceImplFixture.generated.h"

class FTbSimpleNoOperationsInterfaceImplFixture;
class ITbSimpleNoOperationsInterfaceInterface;

UCLASS()
class UTbSimpleNoOperationsInterfaceImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetParentFixture(TWeakPtr<FTbSimpleNoOperationsInterfaceImplFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void PropBoolPropertyCb(bool bPropBool);

	UFUNCTION()
	void PropIntPropertyCb(int32 PropInt);

	UFUNCTION()
	void SigVoidSignalCb();

	UFUNCTION()
	void SigBoolSignalCb(bool bParamBool);

protected:
	TWeakPtr<FTbSimpleNoOperationsInterfaceImplFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
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
