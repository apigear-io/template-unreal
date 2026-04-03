
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbStructArray/Generated/api/TbStructArray_data.h"
#include "TbStructArrayStructArrayFieldInterfaceImplFixture.generated.h"

class FTbStructArrayStructArrayFieldInterfaceImplFixture;
class ITbStructArrayStructArrayFieldInterfaceInterface;

UCLASS()
class UTbStructArrayStructArrayFieldInterfaceImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetParentFixture(TWeakPtr<FTbStructArrayStructArrayFieldInterfaceImplFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void PropStructArrayPropertyCb(const FTbStructArrayStructWithArrayOfStructs& PropStructArray);

	UFUNCTION()
	void PropEnumArrayPropertyCb(const FTbStructArrayStructWithArrayOfEnums& PropEnumArray);

	UFUNCTION()
	void PropIntArrayPropertyCb(const FTbStructArrayStructWithArrayOfInts& PropIntArray);

	UFUNCTION()
	void PropMixedPropertyCb(const FTbStructArrayMixedStruct& PropMixed);

	UFUNCTION()
	void SigMixedSignalCb(const FTbStructArrayMixedStruct& ParamMixed);

	UFUNCTION()
	void SigStructArraySignalCb(const FTbStructArrayStructWithArrayOfStructs& ParamPoints);

protected:
	TWeakPtr<FTbStructArrayStructArrayFieldInterfaceImplFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbStructArrayStructArrayFieldInterfaceImplFixture
{
public:
	FTbStructArrayStructArrayFieldInterfaceImplFixture();
	~FTbStructArrayStructArrayFieldInterfaceImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbStructArrayStructArrayFieldInterfaceImplHelper> GetHelper();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbStructArrayStructArrayFieldInterfaceImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
