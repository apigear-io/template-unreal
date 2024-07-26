
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Testbed2NestedStruct2InterfaceImplFixture.generated.h"

class UTestbed2NestedStruct2InterfaceImplSpec;
class ITestbed2NestedStruct2InterfaceInterface;

UCLASS()
class UTestbed2NestedStruct2InterfaceImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTestbed2NestedStruct2InterfaceImplSpec* InSpec);

	UFUNCTION()
	void Prop1PropertyCb(const FTestbed2NestedStruct1& Prop1);

	UFUNCTION()
	void Prop2PropertyCb(const FTestbed2NestedStruct2& Prop2);

	UFUNCTION()
	void Sig1SignalCb(const FTestbed2NestedStruct1& Param1);

	UFUNCTION()
	void Sig2SignalCb(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTestbed2NestedStruct2InterfaceImplSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTestbed2NestedStruct2InterfaceImplFixture
{
public:
	FTestbed2NestedStruct2InterfaceImplFixture();
	~FTestbed2NestedStruct2InterfaceImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> GetImplementation();
	TWeakObjectPtr<UTestbed2NestedStruct2InterfaceImplHelper> GetHelper();

private:
	void CleanUp();

	TWeakObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> testImplementation;
	TWeakObjectPtr<UTestbed2NestedStruct2InterfaceImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
