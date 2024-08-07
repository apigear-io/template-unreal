
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSame1SameEnum2InterfaceImplFixture.generated.h"

class UTbSame1SameEnum2InterfaceImplSpec;
class ITbSame1SameEnum2InterfaceInterface;

UCLASS()
class UTbSame1SameEnum2InterfaceImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTbSame1SameEnum2InterfaceImplSpec* InSpec);

	UFUNCTION()
	void Prop1PropertyCb(ETbSame1Enum1 Prop1);

	UFUNCTION()
	void Prop2PropertyCb(ETbSame1Enum2 Prop2);

	UFUNCTION()
	void Sig1SignalCb(ETbSame1Enum1 Param1);

	UFUNCTION()
	void Sig2SignalCb(ETbSame1Enum1 Param1, ETbSame1Enum2 Param2);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSame1SameEnum2InterfaceImplSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSame1SameEnum2InterfaceImplFixture
{
public:
	FTbSame1SameEnum2InterfaceImplFixture();
	~FTbSame1SameEnum2InterfaceImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame1SameEnum2InterfaceInterface> GetImplementation();
	TWeakObjectPtr<UTbSame1SameEnum2InterfaceImplHelper> GetHelper();

private:
	void CleanUp();

	TWeakObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame1SameEnum2InterfaceInterface> testImplementation;
	TWeakObjectPtr<UTbSame1SameEnum2InterfaceImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
