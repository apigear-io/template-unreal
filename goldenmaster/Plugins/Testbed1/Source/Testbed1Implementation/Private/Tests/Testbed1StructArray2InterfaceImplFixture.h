
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Testbed1/Generated/api/Testbed1_data.h"
#include "Testbed1StructArray2InterfaceImplFixture.generated.h"

class FTestbed1StructArray2InterfaceImplFixture;
class ITestbed1StructArray2InterfaceInterface;

UCLASS()
class UTestbed1StructArray2InterfaceImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetParentFixture(TWeakPtr<FTestbed1StructArray2InterfaceImplFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void PropBoolPropertyCb(const FTestbed1StructBoolWithArray& PropBool);

	UFUNCTION()
	void PropIntPropertyCb(const FTestbed1StructIntWithArray& PropInt);

	UFUNCTION()
	void PropFloatPropertyCb(const FTestbed1StructFloatWithArray& PropFloat);

	UFUNCTION()
	void PropStringPropertyCb(const FTestbed1StructStringWithArray& PropString);

	UFUNCTION()
	void PropEnumPropertyCb(const FTestbed1StructEnumWithArray& PropEnum);

	UFUNCTION()
	void SigBoolSignalCb(const FTestbed1StructBoolWithArray& ParamBool);

	UFUNCTION()
	void SigIntSignalCb(const FTestbed1StructIntWithArray& ParamInt);

	UFUNCTION()
	void SigFloatSignalCb(const FTestbed1StructFloatWithArray& ParamFloat);

	UFUNCTION()
	void SigStringSignalCb(const FTestbed1StructStringWithArray& ParamString);

protected:
	TWeakPtr<FTestbed1StructArray2InterfaceImplFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTestbed1StructArray2InterfaceImplFixture
{
public:
	FTestbed1StructArray2InterfaceImplFixture();
	~FTestbed1StructArray2InterfaceImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed1StructArray2InterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTestbed1StructArray2InterfaceImplHelper> GetHelper();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed1StructArray2InterfaceInterface> testImplementation;
	TSoftObjectPtr<UTestbed1StructArray2InterfaceImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
