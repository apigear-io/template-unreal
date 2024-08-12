
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSimpleVoidInterfaceImplFixture.generated.h"

class UTbSimpleVoidInterfaceImplSpec;
class ITbSimpleVoidInterfaceInterface;

UCLASS()
class UTbSimpleVoidInterfaceImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTbSimpleVoidInterfaceImplSpec* InSpec);

	UFUNCTION()
	void SigVoidSignalCb();

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSimpleVoidInterfaceImplSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSimpleVoidInterfaceImplFixture
{
public:
	FTbSimpleVoidInterfaceImplFixture();
	~FTbSimpleVoidInterfaceImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleVoidInterfaceInterface> GetImplementation();
	TWeakObjectPtr<UTbSimpleVoidInterfaceImplHelper> GetHelper();

private:
	void CleanUp();

	TWeakObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleVoidInterfaceInterface> testImplementation;
	TWeakObjectPtr<UTbSimpleVoidInterfaceImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
