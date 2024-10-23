
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Testbed1/Generated/api/Testbed1_data.h"
#include "Testbed1StructArrayInterfaceImplFixture.generated.h"

class UTestbed1StructArrayInterfaceImplSpec;
class ITestbed1StructArrayInterfaceInterface;

UCLASS()
class UTestbed1StructArrayInterfaceImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTestbed1StructArrayInterfaceImplSpec* InSpec);

	UFUNCTION()
	void PropBoolPropertyCb(const TArray<FTestbed1StructBool>& PropBool);

	UFUNCTION()
	void PropIntPropertyCb(const TArray<FTestbed1StructInt>& PropInt);

	UFUNCTION()
	void PropFloatPropertyCb(const TArray<FTestbed1StructFloat>& PropFloat);

	UFUNCTION()
	void PropStringPropertyCb(const TArray<FTestbed1StructString>& PropString);

	UFUNCTION()
	void SigBoolSignalCb(const TArray<FTestbed1StructBool>& ParamBool);

	UFUNCTION()
	void SigIntSignalCb(const TArray<FTestbed1StructInt>& ParamInt);

	UFUNCTION()
	void SigFloatSignalCb(const TArray<FTestbed1StructFloat>& ParamFloat);

	UFUNCTION()
	void SigStringSignalCb(const TArray<FTestbed1StructString>& ParamString);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTestbed1StructArrayInterfaceImplSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTestbed1StructArrayInterfaceImplFixture
{
public:
	FTestbed1StructArrayInterfaceImplFixture();
	~FTestbed1StructArrayInterfaceImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed1StructArrayInterfaceInterface> GetImplementation();
	TWeakObjectPtr<UTestbed1StructArrayInterfaceImplHelper> GetHelper();

private:
	void CleanUp();

	TWeakObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed1StructArrayInterfaceInterface> testImplementation;
	TWeakObjectPtr<UTestbed1StructArrayInterfaceImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
