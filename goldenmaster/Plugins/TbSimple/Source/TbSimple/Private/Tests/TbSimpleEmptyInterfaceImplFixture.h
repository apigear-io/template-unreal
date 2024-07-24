
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSimpleEmptyInterfaceImplFixture.generated.h"

class UTbSimpleEmptyInterfaceImplSpec;
class ITbSimpleEmptyInterfaceInterface;

UCLASS()
class UTbSimpleEmptyInterfaceImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTbSimpleEmptyInterfaceImplSpec* InSpec);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSimpleEmptyInterfaceImplSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSimpleEmptyInterfaceImplFixture
{
public:
	FTbSimpleEmptyInterfaceImplFixture();
	~FTbSimpleEmptyInterfaceImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleEmptyInterfaceInterface> GetImplementation();
	TWeakObjectPtr<UTbSimpleEmptyInterfaceImplHelper> GetHelper();

private:
	void CleanUp();

	TWeakObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleEmptyInterfaceInterface> testImplementation;
	TWeakObjectPtr<UTbSimpleEmptyInterfaceImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
