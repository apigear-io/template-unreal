
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSame2SameEnum1InterfaceImplFixture.generated.h"

class UTbSame2SameEnum1InterfaceImplSpec;
class ITbSame2SameEnum1InterfaceInterface;

UCLASS()
class UTbSame2SameEnum1InterfaceImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTbSame2SameEnum1InterfaceImplSpec* InSpec);

	UFUNCTION()
	void Sig1SignalCb(ETbSame2Enum1 Param1);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSame2SameEnum1InterfaceImplSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSame2SameEnum1InterfaceImplFixture
{
public:
	FTbSame2SameEnum1InterfaceImplFixture();
	~FTbSame2SameEnum1InterfaceImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame2SameEnum1InterfaceInterface> GetImplementation();
	TWeakObjectPtr<UTbSame2SameEnum1InterfaceImplHelper> GetHelper();

private:
	void CleanUp();

	TWeakObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame2SameEnum1InterfaceInterface> testImplementation;
	TWeakObjectPtr<UTbSame2SameEnum1InterfaceImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
