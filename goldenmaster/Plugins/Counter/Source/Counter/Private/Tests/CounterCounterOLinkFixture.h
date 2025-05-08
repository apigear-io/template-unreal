
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"
#include "OLinkCommon.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/Counter_data.h"
#include "HAL/Platform.h"
#include "CounterCounterOLinkFixture.generated.h"

class FCounterCounterOLinkFixture;
class ICounterCounterInterface;
class UCounterCounterOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

UCLASS()
class UCounterCounterOLinkHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetParentFixture(TWeakPtr<FCounterCounterOLinkFixture> InFixture);
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
	void _SubscriptionStatusChangedCb(bool bSubscribed);

protected:
	TWeakPtr<FCounterCounterOLinkFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX

class FCounterCounterOLinkFixture
{
public:
	FCounterCounterOLinkFixture();
	~FCounterCounterOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ICounterCounterInterface> GetImplementation();
	TSoftObjectPtr<UCounterCounterOLinkHelper> GetHelper();
	UOLinkHost* GetHost();
	UCounterCounterOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ICounterCounterInterface> testImplementation;
	TSoftObjectPtr<UCounterCounterOLinkHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
