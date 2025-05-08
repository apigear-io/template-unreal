
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Testbed2/Generated/api/Testbed2_data.h"
#include "Testbed2NestedStruct1InterfaceImplFixture.generated.h"

class FTestbed2NestedStruct1InterfaceImplFixture;
class ITestbed2NestedStruct1InterfaceInterface;

UCLASS()
class UTestbed2NestedStruct1InterfaceImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetParentFixture(TWeakPtr<FTestbed2NestedStruct1InterfaceImplFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void Prop1PropertyCb(const FTestbed2NestedStruct1& Prop1);

	UFUNCTION()
	void Sig1SignalCb(const FTestbed2NestedStruct1& Param1);

protected:
	TWeakPtr<FTestbed2NestedStruct1InterfaceImplFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTestbed2NestedStruct1InterfaceImplFixture
{
public:
	FTestbed2NestedStruct1InterfaceImplFixture();
	~FTestbed2NestedStruct1InterfaceImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTestbed2NestedStruct1InterfaceImplHelper> GetHelper();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> testImplementation;
	TSoftObjectPtr<UTestbed2NestedStruct1InterfaceImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
