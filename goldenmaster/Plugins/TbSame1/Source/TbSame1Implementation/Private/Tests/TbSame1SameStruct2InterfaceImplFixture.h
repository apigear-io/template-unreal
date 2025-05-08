
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSame1/Generated/api/TbSame1_data.h"
#include "TbSame1SameStruct2InterfaceImplFixture.generated.h"

class FTbSame1SameStruct2InterfaceImplFixture;
class ITbSame1SameStruct2InterfaceInterface;

UCLASS()
class UTbSame1SameStruct2InterfaceImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetParentFixture(TWeakPtr<FTbSame1SameStruct2InterfaceImplFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void Prop1PropertyCb(const FTbSame1Struct2& Prop1);

	UFUNCTION()
	void Prop2PropertyCb(const FTbSame1Struct2& Prop2);

	UFUNCTION()
	void Sig1SignalCb(const FTbSame1Struct1& Param1);

	UFUNCTION()
	void Sig2SignalCb(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2);

protected:
	TWeakPtr<FTbSame1SameStruct2InterfaceImplFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSame1SameStruct2InterfaceImplFixture
{
public:
	FTbSame1SameStruct2InterfaceImplFixture();
	~FTbSame1SameStruct2InterfaceImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame1SameStruct2InterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbSame1SameStruct2InterfaceImplHelper> GetHelper();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame1SameStruct2InterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbSame1SameStruct2InterfaceImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
