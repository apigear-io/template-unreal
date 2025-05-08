
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSame2_data.h"
#include "TbSame2SameEnum2InterfaceImplFixture.generated.h"

class FTbSame2SameEnum2InterfaceImplFixture;
class ITbSame2SameEnum2InterfaceInterface;

UCLASS()
class UTbSame2SameEnum2InterfaceImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetParentFixture(TWeakPtr<FTbSame2SameEnum2InterfaceImplFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void Prop1PropertyCb(ETbSame2Enum1 Prop1);

	UFUNCTION()
	void Prop2PropertyCb(ETbSame2Enum2 Prop2);

	UFUNCTION()
	void Sig1SignalCb(ETbSame2Enum1 Param1);

	UFUNCTION()
	void Sig2SignalCb(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2);

protected:
	TWeakPtr<FTbSame2SameEnum2InterfaceImplFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSame2SameEnum2InterfaceImplFixture
{
public:
	FTbSame2SameEnum2InterfaceImplFixture();
	~FTbSame2SameEnum2InterfaceImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame2SameEnum2InterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbSame2SameEnum2InterfaceImplHelper> GetHelper();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame2SameEnum2InterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbSame2SameEnum2InterfaceImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
