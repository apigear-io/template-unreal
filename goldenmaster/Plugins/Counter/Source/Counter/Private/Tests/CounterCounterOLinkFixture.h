
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Counter/Generated/api/Counter_data.h"
#include "HAL/Platform.h"
#include "CounterCounterOLinkFixture.generated.h"

class UCounterCounterOLinkSpec;
class ICounterCounterInterface;
class UCounterCounterOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

UCLASS()
class UCounterCounterOLinkHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UCounterCounterOLinkSpec* InSpec);

	UFUNCTION()
	void VectorPropertyCb(const FCustomTypesVector3D& Vector);

	UFUNCTION()
	void VectorArrayPropertyCb(const TArray<FCustomTypesVector3D>& VectorArray);

	UFUNCTION()
	void ValueChangedSignalCb(const FCustomTypesVector3D& Vector, const FVector& ExternVector, const TArray<FCustomTypesVector3D>& VectorArray, const TArray<FVector>& ExternVectorArray);

	UFUNCTION()
	void _SubscriptionStatusChangedCb(bool bSubscribed);

protected:
	const FDoneDelegate* testDoneDelegate;
	UCounterCounterOLinkSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

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

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
