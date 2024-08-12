
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSimple_data.h"
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
	void PropBoolPropertyCb(const TArray<bool>& PropBool);

	UFUNCTION()
	void PropIntPropertyCb(const TArray<int32>& PropInt);

	UFUNCTION()
	void PropInt32PropertyCb(const TArray<int32>& PropInt32);

	UFUNCTION()
	void PropInt64PropertyCb(const TArray<int64>& PropInt64);

	UFUNCTION()
	void PropFloatPropertyCb(const TArray<float>& PropFloat);

	UFUNCTION()
	void PropFloat32PropertyCb(const TArray<float>& PropFloat32);

	UFUNCTION()
	void PropFloat64PropertyCb(const TArray<double>& PropFloat64);

	UFUNCTION()
	void PropStringPropertyCb(const TArray<FString>& PropString);

	UFUNCTION()
	void PropReadOnlyStringPropertyCb(const FString& PropReadOnlyString);

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
