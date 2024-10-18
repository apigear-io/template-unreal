
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Counter/Generated/api/Counter_data.h"
#include "CounterCounterImplFixture.generated.h"

class UCounterCounterImplSpec;
class ICounterCounterInterface;

UCLASS()
class UCounterCounterImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UCounterCounterImplSpec* InSpec);

	UFUNCTION()
	void VectorPropertyCb(const FCustomTypesVector3D& Vector);

	UFUNCTION()
	void VectorArrayPropertyCb(const TArray<FCustomTypesVector3D>& VectorArray);

	UFUNCTION()
	void ValueChangedSignalCb(const FCustomTypesVector3D& Vector, const FVector& ExternVector, const TArray<FCustomTypesVector3D>& VectorArray, const TArray<FVector>& ExternVectorArray);

protected:
	const FDoneDelegate* testDoneDelegate;
	UCounterCounterImplSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FCounterCounterImplFixture
{
public:
	FCounterCounterImplFixture();
	~FCounterCounterImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ICounterCounterInterface> GetImplementation();
	TWeakObjectPtr<UCounterCounterImplHelper> GetHelper();

private:
	void CleanUp();

	TWeakObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ICounterCounterInterface> testImplementation;
	TWeakObjectPtr<UCounterCounterImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
