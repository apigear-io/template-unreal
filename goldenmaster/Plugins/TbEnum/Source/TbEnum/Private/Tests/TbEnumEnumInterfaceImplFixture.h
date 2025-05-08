
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbEnum_data.h"
#include "TbEnumEnumInterfaceImplFixture.generated.h"

class FTbEnumEnumInterfaceImplFixture;
class ITbEnumEnumInterfaceInterface;

UCLASS()
class UTbEnumEnumInterfaceImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetParentFixture(TWeakPtr<FTbEnumEnumInterfaceImplFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void Prop0PropertyCb(ETbEnumEnum0 Prop0);

	UFUNCTION()
	void Prop1PropertyCb(ETbEnumEnum1 Prop1);

	UFUNCTION()
	void Prop2PropertyCb(ETbEnumEnum2 Prop2);

	UFUNCTION()
	void Prop3PropertyCb(ETbEnumEnum3 Prop3);

	UFUNCTION()
	void Sig0SignalCb(ETbEnumEnum0 Param0);

	UFUNCTION()
	void Sig1SignalCb(ETbEnumEnum1 Param1);

	UFUNCTION()
	void Sig2SignalCb(ETbEnumEnum2 Param2);

	UFUNCTION()
	void Sig3SignalCb(ETbEnumEnum3 Param3);

protected:
	TWeakPtr<FTbEnumEnumInterfaceImplFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbEnumEnumInterfaceImplFixture
{
public:
	FTbEnumEnumInterfaceImplFixture();
	~FTbEnumEnumInterfaceImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbEnumEnumInterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbEnumEnumInterfaceImplHelper> GetHelper();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbEnumEnumInterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbEnumEnumInterfaceImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
