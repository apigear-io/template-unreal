
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSimple_data.h"
#include "TbSimpleSimpleInterfaceOLinkFixture.generated.h"

class UTbSimpleSimpleInterfaceOLinkSpec;
class ITbSimpleSimpleInterfaceInterface;
class UTbSimpleSimpleInterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

UCLASS()
class UTbSimpleSimpleInterfaceOLinkHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTbSimpleSimpleInterfaceOLinkSpec* InSpec);

	UFUNCTION()
	void PropBoolPropertyCb(bool bPropBool);

	UFUNCTION()
	void PropIntPropertyCb(int32 PropInt);

	UFUNCTION()
	void PropInt32PropertyCb(int32 PropInt32);

	UFUNCTION()
	void PropInt64PropertyCb(int64 PropInt64);

	UFUNCTION()
	void PropFloatPropertyCb(float PropFloat);

	UFUNCTION()
	void PropFloat32PropertyCb(float PropFloat32);

	UFUNCTION()
	void PropFloat64PropertyCb(double PropFloat64);

	UFUNCTION()
	void PropStringPropertyCb(const FString& PropString);

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
	void SigFloat32SignalCb(float ParamFloat32);

	UFUNCTION()
	void SigFloat64SignalCb(double ParamFloat64);

	UFUNCTION()
	void SigStringSignalCb(const FString& ParamString);

	UFUNCTION()
	void _SubscriptionStatusChangedCb(bool bSubscribed);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSimpleSimpleInterfaceOLinkSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSimpleSimpleInterfaceOLinkFixture
{
public:
	FTbSimpleSimpleInterfaceOLinkFixture();
	~FTbSimpleSimpleInterfaceOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbSimpleSimpleInterfaceOLinkHelper> GetHelper();
	UOLinkHost* GetHost();
	UTbSimpleSimpleInterfaceOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbSimpleSimpleInterfaceOLinkHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
