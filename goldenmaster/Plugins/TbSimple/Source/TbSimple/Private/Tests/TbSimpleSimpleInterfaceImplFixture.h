
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSimpleSimpleInterfaceImplFixture.generated.h"

class UTbSimpleSimpleInterfaceImplSpec;
class ITbSimpleSimpleInterfaceInterface;

UCLASS()
class UTbSimpleSimpleInterfaceImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTbSimpleSimpleInterfaceImplSpec* InSpec);

	UFUNCTION()
	void SigVoidSignalCb();

	UFUNCTION()
	void SigBoolSignalCb(bool bParamBool);

	UFUNCTION()
	void SigIntSignalCb(int32 ParamInt);

	UFUNCTION()
	void SigInt32SignalCb(int32 ParamInt32);

	UFUNCTION()
	void SigInt64SignalCb(int64 ParamInt64);

	UFUNCTION()
	void SigFloatSignalCb(float ParamFloat);

	UFUNCTION()
	void SigFloat32SignalCb(float ParamFloa32);

	UFUNCTION()
	void SigFloat64SignalCb(double ParamFloat64);

	UFUNCTION()
	void SigStringSignalCb(const FString& ParamString);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSimpleSimpleInterfaceImplSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSimpleSimpleInterfaceImplFixture
{
public:
	FTbSimpleSimpleInterfaceImplFixture();
	~FTbSimpleSimpleInterfaceImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> GetImplementation();
	TWeakObjectPtr<UTbSimpleSimpleInterfaceImplHelper> GetHelper();

private:
	void CleanUp();

	TWeakObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> testImplementation;
	TWeakObjectPtr<UTbSimpleSimpleInterfaceImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
