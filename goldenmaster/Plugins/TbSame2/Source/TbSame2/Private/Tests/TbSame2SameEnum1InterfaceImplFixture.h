
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSame2_data.h"
#include "TbSame2SameEnum1InterfaceImplFixture.generated.h"

class FTbSame2SameEnum1InterfaceImplFixture;
class ITbSame2SameEnum1InterfaceInterface;

UCLASS()
class UTbSame2SameEnum1InterfaceImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetParentFixture(TWeakPtr<FTbSame2SameEnum1InterfaceImplFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void Prop1PropertyCb(ETbSame2Enum1 Prop1);

	UFUNCTION()
	void Sig1SignalCb(ETbSame2Enum1 Param1);

protected:
	TWeakPtr<FTbSame2SameEnum1InterfaceImplFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSame2SameEnum1InterfaceImplFixture
{
public:
	FTbSame2SameEnum1InterfaceImplFixture();
	~FTbSame2SameEnum1InterfaceImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame2SameEnum1InterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbSame2SameEnum1InterfaceImplHelper> GetHelper();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame2SameEnum1InterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbSame2SameEnum1InterfaceImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
