
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSimple_data.h"
#include "TbSimpleEmptyInterfaceImplFixture.generated.h"

class FTbSimpleEmptyInterfaceImplFixture;
class ITbSimpleEmptyInterfaceInterface;

UCLASS()
class UTbSimpleEmptyInterfaceImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetParentFixture(TWeakPtr<FTbSimpleEmptyInterfaceImplFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

protected:
	TWeakPtr<FTbSimpleEmptyInterfaceImplFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSimpleEmptyInterfaceImplFixture
{
public:
	FTbSimpleEmptyInterfaceImplFixture();
	~FTbSimpleEmptyInterfaceImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleEmptyInterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbSimpleEmptyInterfaceImplHelper> GetHelper();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleEmptyInterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbSimpleEmptyInterfaceImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
