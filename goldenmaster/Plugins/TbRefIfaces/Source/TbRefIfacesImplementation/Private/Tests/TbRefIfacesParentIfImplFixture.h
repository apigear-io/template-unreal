
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbRefIfaces/Generated/api/TbRefIfaces_data.h"
#include "TbRefIfacesParentIfImplFixture.generated.h"

class FTbRefIfacesParentIfImplFixture;
class ITbRefIfacesParentIfInterface;

UCLASS()
class UTbRefIfacesParentIfImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetParentFixture(TWeakPtr<FTbRefIfacesParentIfImplFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void LocalIfPropertyCb(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& LocalIf);

	UFUNCTION()
	void ImportedIfPropertyCb(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& ImportedIf);

	UFUNCTION()
	void LocalIfSignalSignalCb(const TScriptInterface<ITbRefIfacesSimpleLocalIfInterface>& Param);

	UFUNCTION()
	void ImportedIfSignalSignalCb(const TScriptInterface<ITbIfaceimportEmptyIfInterface>& Param);

protected:
	TWeakPtr<FTbRefIfacesParentIfImplFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbRefIfacesParentIfImplFixture
{
public:
	FTbRefIfacesParentIfImplFixture();
	~FTbRefIfacesParentIfImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbRefIfacesParentIfInterface> GetImplementation();
	TSoftObjectPtr<UTbRefIfacesParentIfImplHelper> GetHelper();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbRefIfacesParentIfInterface> testImplementation;
	TSoftObjectPtr<UTbRefIfacesParentIfImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
