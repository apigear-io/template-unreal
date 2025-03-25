
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbIfaceimport/Generated/api/TbIfaceimport_data.h"
#include "TbIfaceimportEmptyIfImplFixture.generated.h"

class FTbIfaceimportEmptyIfImplFixture;
class ITbIfaceimportEmptyIfInterface;

UCLASS()
class UTbIfaceimportEmptyIfImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetParentFixture(TWeakPtr<FTbIfaceimportEmptyIfImplFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

protected:
	TWeakPtr<FTbIfaceimportEmptyIfImplFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbIfaceimportEmptyIfImplFixture
{
public:
	FTbIfaceimportEmptyIfImplFixture();
	~FTbIfaceimportEmptyIfImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbIfaceimportEmptyIfInterface> GetImplementation();
	TSoftObjectPtr<UTbIfaceimportEmptyIfImplHelper> GetHelper();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbIfaceimportEmptyIfInterface> testImplementation;
	TSoftObjectPtr<UTbIfaceimportEmptyIfImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
