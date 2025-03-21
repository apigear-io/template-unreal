
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSame1/Generated/api/TbSame1_data.h"
#include "TbSame1SameStruct1InterfaceImplFixture.generated.h"

class UTbSame1SameStruct1InterfaceImplSpec;
class ITbSame1SameStruct1InterfaceInterface;

UCLASS()
class UTbSame1SameStruct1InterfaceImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTbSame1SameStruct1InterfaceImplSpec* InSpec);

	UFUNCTION()
	void Prop1PropertyCb(const FTbSame1Struct1& Prop1);

	UFUNCTION()
	void Sig1SignalCb(const FTbSame1Struct1& Param1);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSame1SameStruct1InterfaceImplSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSame1SameStruct1InterfaceImplFixture
{
public:
	FTbSame1SameStruct1InterfaceImplFixture();
	~FTbSame1SameStruct1InterfaceImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame1SameStruct1InterfaceInterface> GetImplementation();
	TWeakObjectPtr<UTbSame1SameStruct1InterfaceImplHelper> GetHelper();

private:
	void CleanUp();

	TWeakObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame1SameStruct1InterfaceInterface> testImplementation;
	TWeakObjectPtr<UTbSame1SameStruct1InterfaceImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
