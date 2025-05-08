
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSame2_data.h"
#include "TbSame2SameStruct1InterfaceImplFixture.generated.h"

class FTbSame2SameStruct1InterfaceImplFixture;
class ITbSame2SameStruct1InterfaceInterface;

UCLASS()
class UTbSame2SameStruct1InterfaceImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetParentFixture(TWeakPtr<FTbSame2SameStruct1InterfaceImplFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void Prop1PropertyCb(const FTbSame2Struct1& Prop1);

	UFUNCTION()
	void Sig1SignalCb(const FTbSame2Struct1& Param1);

protected:
	TWeakPtr<FTbSame2SameStruct1InterfaceImplFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSame2SameStruct1InterfaceImplFixture
{
public:
	FTbSame2SameStruct1InterfaceImplFixture();
	~FTbSame2SameStruct1InterfaceImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame2SameStruct1InterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbSame2SameStruct1InterfaceImplHelper> GetHelper();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame2SameStruct1InterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbSame2SameStruct1InterfaceImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
