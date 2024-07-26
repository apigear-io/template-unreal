
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSame2SameStruct2InterfaceImplFixture.generated.h"

class UTbSame2SameStruct2InterfaceImplSpec;
class ITbSame2SameStruct2InterfaceInterface;

UCLASS()
class UTbSame2SameStruct2InterfaceImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTbSame2SameStruct2InterfaceImplSpec* InSpec);

	UFUNCTION()
	void Prop1PropertyCb(const FTbSame2Struct2& Prop1);

	UFUNCTION()
	void Prop2PropertyCb(const FTbSame2Struct2& Prop2);

	UFUNCTION()
	void Sig1SignalCb(const FTbSame2Struct1& Param1);

	UFUNCTION()
	void Sig2SignalCb(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSame2SameStruct2InterfaceImplSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSame2SameStruct2InterfaceImplFixture
{
public:
	FTbSame2SameStruct2InterfaceImplFixture();
	~FTbSame2SameStruct2InterfaceImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame2SameStruct2InterfaceInterface> GetImplementation();
	TWeakObjectPtr<UTbSame2SameStruct2InterfaceImplHelper> GetHelper();

private:
	void CleanUp();

	TWeakObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame2SameStruct2InterfaceInterface> testImplementation;
	TWeakObjectPtr<UTbSame2SameStruct2InterfaceImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
