
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSame1_data.h"
#include "TbSame1SameEnum2InterfaceImplFixture.generated.h"

class FTbSame1SameEnum2InterfaceImplFixture;
class ITbSame1SameEnum2InterfaceInterface;

UCLASS()
class UTbSame1SameEnum2InterfaceImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetParentFixture(TWeakPtr<FTbSame1SameEnum2InterfaceImplFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void Prop1PropertyCb(ETbSame1Enum1 Prop1);

	UFUNCTION()
	void Prop2PropertyCb(ETbSame1Enum2 Prop2);

	UFUNCTION()
	void Sig1SignalCb(ETbSame1Enum1 Param1);

	UFUNCTION()
	void Sig2SignalCb(ETbSame1Enum1 Param1, ETbSame1Enum2 Param2);

protected:
	TWeakPtr<FTbSame1SameEnum2InterfaceImplFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSame1SameEnum2InterfaceImplFixture
{
public:
	FTbSame1SameEnum2InterfaceImplFixture();
	~FTbSame1SameEnum2InterfaceImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame1SameEnum2InterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbSame1SameEnum2InterfaceImplHelper> GetHelper();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame1SameEnum2InterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbSame1SameEnum2InterfaceImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
