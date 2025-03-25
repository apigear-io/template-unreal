
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbRefIfaces/Generated/api/TbRefIfaces_data.h"
#include "TbRefIfacesSimpleLocalIfImplFixture.generated.h"

class FTbRefIfacesSimpleLocalIfImplFixture;
class ITbRefIfacesSimpleLocalIfInterface;

UCLASS()
class UTbRefIfacesSimpleLocalIfImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetParentFixture(TWeakPtr<FTbRefIfacesSimpleLocalIfImplFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void IntPropertyPropertyCb(int32 IntProperty);

	UFUNCTION()
	void IntSignalSignalCb(int32 Param);

protected:
	TWeakPtr<FTbRefIfacesSimpleLocalIfImplFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbRefIfacesSimpleLocalIfImplFixture
{
public:
	FTbRefIfacesSimpleLocalIfImplFixture();
	~FTbRefIfacesSimpleLocalIfImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> GetImplementation();
	TSoftObjectPtr<UTbRefIfacesSimpleLocalIfImplHelper> GetHelper();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> testImplementation;
	TSoftObjectPtr<UTbRefIfacesSimpleLocalIfImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
