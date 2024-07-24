
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSimpleSimpleArrayInterfaceImplFixture.generated.h"

class UTbSimpleSimpleArrayInterfaceImplSpec;
class ITbSimpleSimpleArrayInterfaceInterface;

UCLASS()
class UTbSimpleSimpleArrayInterfaceImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTbSimpleSimpleArrayInterfaceImplSpec* InSpec);

	UFUNCTION()
	void SigBoolSignalCb(const TArray<bool>& ParamBool);

	UFUNCTION()
	void SigIntSignalCb(const TArray<int32>& ParamInt);

	UFUNCTION()
	void SigInt32SignalCb(const TArray<int32>& ParamInt32);

	UFUNCTION()
	void SigInt64SignalCb(const TArray<int64>& ParamInt64);

	UFUNCTION()
	void SigFloatSignalCb(const TArray<float>& ParamFloat);

	UFUNCTION()
	void SigFloat32SignalCb(const TArray<float>& ParamFloa32);

	UFUNCTION()
	void SigFloat64SignalCb(const TArray<double>& ParamFloat64);

	UFUNCTION()
	void SigStringSignalCb(const TArray<FString>& ParamString);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSimpleSimpleArrayInterfaceImplSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSimpleSimpleArrayInterfaceImplFixture
{
public:
	FTbSimpleSimpleArrayInterfaceImplFixture();
	~FTbSimpleSimpleArrayInterfaceImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> GetImplementation();
	TWeakObjectPtr<UTbSimpleSimpleArrayInterfaceImplHelper> GetHelper();

private:
	void CleanUp();

	TWeakObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> testImplementation;
	TWeakObjectPtr<UTbSimpleSimpleArrayInterfaceImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
