
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Testbed2/Generated/api/Testbed2_data.h"
#include "Testbed2NestedStruct3InterfaceImplFixture.generated.h"

class FTestbed2NestedStruct3InterfaceImplFixture;
class ITestbed2NestedStruct3InterfaceInterface;

UCLASS()
class UTestbed2NestedStruct3InterfaceImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetParentFixture(TWeakPtr<FTestbed2NestedStruct3InterfaceImplFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void Prop1PropertyCb(const FTestbed2NestedStruct1& Prop1);

	UFUNCTION()
	void Prop2PropertyCb(const FTestbed2NestedStruct2& Prop2);

	UFUNCTION()
	void Prop3PropertyCb(const FTestbed2NestedStruct3& Prop3);

	UFUNCTION()
	void Sig1SignalCb(const FTestbed2NestedStruct1& Param1);

	UFUNCTION()
	void Sig2SignalCb(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2);

	UFUNCTION()
	void Sig3SignalCb(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3);

protected:
	TWeakPtr<FTestbed2NestedStruct3InterfaceImplFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTestbed2NestedStruct3InterfaceImplFixture
{
public:
	FTestbed2NestedStruct3InterfaceImplFixture();
	~FTestbed2NestedStruct3InterfaceImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTestbed2NestedStruct3InterfaceImplHelper> GetHelper();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> testImplementation;
	TSoftObjectPtr<UTestbed2NestedStruct3InterfaceImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
