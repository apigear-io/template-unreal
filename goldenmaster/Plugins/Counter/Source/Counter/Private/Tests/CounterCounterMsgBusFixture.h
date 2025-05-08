
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/Counter_data.h"
#include "HAL/Platform.h"
#include "CounterCounterMsgBusFixture.generated.h"

class FCounterCounterMsgBusFixture;
class ICounterCounterInterface;
class UCounterCounterMsgBusAdapter;
class IApiGearConnection;

UCLASS()
class UCounterCounterMsgBusHelper : public UObject
{
	GENERATED_BODY()
public:
	~UCounterCounterMsgBusHelper();

	void SetParentFixture(TWeakPtr<FCounterCounterMsgBusFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void VectorPropertyCb(const FCustomTypesVector3D& Vector);
	UFUNCTION()
	void VectorPropertyChangeLocalCheckRemoteCb(const FCustomTypesVector3D& Vector);
	UFUNCTION()
	void VectorPropertyChangeLocalChangeRemoteCb(const FCustomTypesVector3D& Vector);

	UFUNCTION()
	void VectorArrayPropertyCb(const TArray<FCustomTypesVector3D>& VectorArray);
	UFUNCTION()
	void VectorArrayPropertyChangeLocalCheckRemoteCb(const TArray<FCustomTypesVector3D>& VectorArray);
	UFUNCTION()
	void VectorArrayPropertyChangeLocalChangeRemoteCb(const TArray<FCustomTypesVector3D>& VectorArray);

	UFUNCTION()
	void ValueChangedSignalCb(const FCustomTypesVector3D& Vector, const FVector& ExternVector, const TArray<FCustomTypesVector3D>& VectorArray, const TArray<FVector>& ExternVectorArray);

	UFUNCTION()
	void _ConnectionStatusChangedCb(bool bConnected);

protected:
	TWeakPtr<FCounterCounterMsgBusFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FCounterCounterMsgBusFixture
{
public:
	FCounterCounterMsgBusFixture();
	~FCounterCounterMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ICounterCounterInterface> GetImplementation();
	TSoftObjectPtr<UCounterCounterMsgBusHelper> GetHelper();
	UCounterCounterMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ICounterCounterInterface> testImplementation;
	TSoftObjectPtr<UCounterCounterMsgBusHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
