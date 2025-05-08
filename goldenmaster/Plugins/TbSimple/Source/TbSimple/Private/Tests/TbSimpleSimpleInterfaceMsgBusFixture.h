
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSimple_data.h"
#include "HAL/Platform.h"
#include "TbSimpleSimpleInterfaceMsgBusFixture.generated.h"

class FTbSimpleSimpleInterfaceMsgBusFixture;
class ITbSimpleSimpleInterfaceInterface;
class UTbSimpleSimpleInterfaceMsgBusAdapter;
class IApiGearConnection;

UCLASS()
class UTbSimpleSimpleInterfaceMsgBusHelper : public UObject
{
	GENERATED_BODY()
public:
	~UTbSimpleSimpleInterfaceMsgBusHelper();

	void SetParentFixture(TWeakPtr<FTbSimpleSimpleInterfaceMsgBusFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void PropBoolPropertyCb(bool bPropBool);
	UFUNCTION()
	void PropBoolPropertyChangeLocalCheckRemoteCb(bool bPropBool);
	UFUNCTION()
	void PropBoolPropertyChangeLocalChangeRemoteCb(bool bPropBool);

	UFUNCTION()
	void PropIntPropertyCb(int32 PropInt);
	UFUNCTION()
	void PropIntPropertyChangeLocalCheckRemoteCb(int32 PropInt);
	UFUNCTION()
	void PropIntPropertyChangeLocalChangeRemoteCb(int32 PropInt);

	UFUNCTION()
	void PropInt32PropertyCb(int32 PropInt32);
	UFUNCTION()
	void PropInt32PropertyChangeLocalCheckRemoteCb(int32 PropInt32);
	UFUNCTION()
	void PropInt32PropertyChangeLocalChangeRemoteCb(int32 PropInt32);

	UFUNCTION()
	void PropInt64PropertyCb(int64 PropInt64);
	UFUNCTION()
	void PropInt64PropertyChangeLocalCheckRemoteCb(int64 PropInt64);
	UFUNCTION()
	void PropInt64PropertyChangeLocalChangeRemoteCb(int64 PropInt64);

	UFUNCTION()
	void PropFloatPropertyCb(float PropFloat);
	UFUNCTION()
	void PropFloatPropertyChangeLocalCheckRemoteCb(float PropFloat);
	UFUNCTION()
	void PropFloatPropertyChangeLocalChangeRemoteCb(float PropFloat);

	UFUNCTION()
	void PropFloat32PropertyCb(float PropFloat32);
	UFUNCTION()
	void PropFloat32PropertyChangeLocalCheckRemoteCb(float PropFloat32);
	UFUNCTION()
	void PropFloat32PropertyChangeLocalChangeRemoteCb(float PropFloat32);

	UFUNCTION()
	void PropFloat64PropertyCb(double PropFloat64);
	UFUNCTION()
	void PropFloat64PropertyChangeLocalCheckRemoteCb(double PropFloat64);
	UFUNCTION()
	void PropFloat64PropertyChangeLocalChangeRemoteCb(double PropFloat64);

	UFUNCTION()
	void PropStringPropertyCb(const FString& PropString);
	UFUNCTION()
	void PropStringPropertyChangeLocalCheckRemoteCb(const FString& PropString);
	UFUNCTION()
	void PropStringPropertyChangeLocalChangeRemoteCb(const FString& PropString);

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
	void _ConnectionStatusChangedCb(bool bConnected);

protected:
	TWeakPtr<FTbSimpleSimpleInterfaceMsgBusFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSimpleSimpleInterfaceMsgBusFixture
{
public:
	FTbSimpleSimpleInterfaceMsgBusFixture();
	~FTbSimpleSimpleInterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbSimpleSimpleInterfaceMsgBusHelper> GetHelper();
	UTbSimpleSimpleInterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbSimpleSimpleInterfaceMsgBusHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
