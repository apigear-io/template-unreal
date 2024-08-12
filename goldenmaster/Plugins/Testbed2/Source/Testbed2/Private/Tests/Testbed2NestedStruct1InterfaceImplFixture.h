
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/Testbed2_data.h"
#include "Testbed2NestedStruct1InterfaceImplFixture.generated.h"

class UTestbed2NestedStruct1InterfaceImplSpec;
class ITestbed2NestedStruct1InterfaceInterface;

UCLASS()
class UTestbed2NestedStruct1InterfaceImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTestbed2NestedStruct1InterfaceImplSpec* InSpec);

	UFUNCTION()
	void Prop1PropertyCb(const FTestbed2NestedStruct1& Prop1);

	UFUNCTION()
	void Sig1SignalCb(const FTestbed2NestedStruct1& Param1);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTestbed2NestedStruct1InterfaceImplSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTestbed2NestedStruct1InterfaceImplFixture
{
public:
	FTestbed2NestedStruct1InterfaceImplFixture();
	~FTestbed2NestedStruct1InterfaceImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> GetImplementation();
	TWeakObjectPtr<UTestbed2NestedStruct1InterfaceImplHelper> GetHelper();

private:
	void CleanUp();

	TWeakObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> testImplementation;
	TWeakObjectPtr<UTestbed2NestedStruct1InterfaceImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
