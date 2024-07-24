
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
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
	TWeakObjectPtr<UTbSimpleNoOperationsInterfaceImplHelper> GetHelper();

private:
	void CleanUp();

	TWeakObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> testImplementation;
	TWeakObjectPtr<UTbSimpleNoOperationsInterfaceImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
