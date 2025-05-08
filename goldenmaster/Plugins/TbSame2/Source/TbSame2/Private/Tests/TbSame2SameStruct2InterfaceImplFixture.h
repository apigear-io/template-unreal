
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSame2_data.h"
#include "TbSame2SameStruct2InterfaceImplFixture.generated.h"

class FTbSame2SameStruct2InterfaceImplFixture;
class ITbSame2SameStruct2InterfaceInterface;

UCLASS()
class UTbSame2SameStruct2InterfaceImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetParentFixture(TWeakPtr<FTbSame2SameStruct2InterfaceImplFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void Prop1PropertyCb(const FTbSame2Struct2& Prop1);

	UFUNCTION()
	void Prop2PropertyCb(const FTbSame2Struct2& Prop2);

	UFUNCTION()
	void Sig1SignalCb(const FTbSame2Struct1& Param1);

	UFUNCTION()
	void Sig2SignalCb(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2);

protected:
	TWeakPtr<FTbSame2SameStruct2InterfaceImplFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSame2SameStruct2InterfaceImplFixture
{
public:
	FTbSame2SameStruct2InterfaceImplFixture();
	~FTbSame2SameStruct2InterfaceImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame2SameStruct2InterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbSame2SameStruct2InterfaceImplHelper> GetHelper();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame2SameStruct2InterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbSame2SameStruct2InterfaceImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
