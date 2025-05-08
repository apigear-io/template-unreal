
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Counter/Generated/api/Counter_data.h"
#include "CounterCounterImplFixture.generated.h"

class FCounterCounterImplFixture;
class ICounterCounterInterface;

UCLASS()
class UCounterCounterImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetParentFixture(TWeakPtr<FCounterCounterImplFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void VectorPropertyCb(const FCustomTypesVector3D& Vector);

	UFUNCTION()
	void VectorArrayPropertyCb(const TArray<FCustomTypesVector3D>& VectorArray);

	UFUNCTION()
	void ValueChangedSignalCb(const FCustomTypesVector3D& Vector, const FVector& ExternVector, const TArray<FCustomTypesVector3D>& VectorArray, const TArray<FVector>& ExternVectorArray);

protected:
	TWeakPtr<FCounterCounterImplFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FCounterCounterImplFixture
{
public:
	FCounterCounterImplFixture();
	~FCounterCounterImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ICounterCounterInterface> GetImplementation();
	TSoftObjectPtr<UCounterCounterImplHelper> GetHelper();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ICounterCounterInterface> testImplementation;
	TSoftObjectPtr<UCounterCounterImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
