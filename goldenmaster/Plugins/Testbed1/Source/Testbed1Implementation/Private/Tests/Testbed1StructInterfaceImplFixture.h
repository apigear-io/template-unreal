
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Testbed1/Generated/api/Testbed1_data.h"
#include "Testbed1StructInterfaceImplFixture.generated.h"

class FTestbed1StructInterfaceImplFixture;
class ITestbed1StructInterfaceInterface;

UCLASS()
class UTestbed1StructInterfaceImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetParentFixture(TWeakPtr<FTestbed1StructInterfaceImplFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void PropBoolPropertyCb(const FTestbed1StructBool& PropBool);

	UFUNCTION()
	void PropIntPropertyCb(const FTestbed1StructInt& PropInt);

	UFUNCTION()
	void PropFloatPropertyCb(const FTestbed1StructFloat& PropFloat);

	UFUNCTION()
	void PropStringPropertyCb(const FTestbed1StructString& PropString);

	UFUNCTION()
	void SigBoolSignalCb(const FTestbed1StructBool& ParamBool);

	UFUNCTION()
	void SigIntSignalCb(const FTestbed1StructInt& ParamInt);

	UFUNCTION()
	void SigFloatSignalCb(const FTestbed1StructFloat& ParamFloat);

	UFUNCTION()
	void SigStringSignalCb(const FTestbed1StructString& ParamString);

protected:
	TWeakPtr<FTestbed1StructInterfaceImplFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTestbed1StructInterfaceImplFixture
{
public:
	FTestbed1StructInterfaceImplFixture();
	~FTestbed1StructInterfaceImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed1StructInterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTestbed1StructInterfaceImplHelper> GetHelper();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed1StructInterfaceInterface> testImplementation;
	TSoftObjectPtr<UTestbed1StructInterfaceImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
