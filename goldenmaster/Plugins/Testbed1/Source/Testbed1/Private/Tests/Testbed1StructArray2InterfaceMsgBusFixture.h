
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/Testbed1_data.h"
#include "HAL/Platform.h"
#include "Testbed1StructArray2InterfaceMsgBusFixture.generated.h"

class UTestbed1StructArray2InterfaceMsgBusSpec;
class ITestbed1StructArray2InterfaceInterface;
class UTestbed1StructArray2InterfaceMsgBusAdapter;
class IApiGearConnection;

UCLASS()
class UTestbed1StructArray2InterfaceMsgBusHelper : public UObject
{
	GENERATED_BODY()
public:
	~UTestbed1StructArray2InterfaceMsgBusHelper();

	void SetSpec(UTestbed1StructArray2InterfaceMsgBusSpec* InSpec);

	UFUNCTION()
	void PropBoolPropertyCb(const FTestbed1StructBoolWithArray& PropBool);
	UFUNCTION()
	void PropBoolPropertyChangeLocalCheckRemoteCb(const FTestbed1StructBoolWithArray& PropBool);
	UFUNCTION()
	void PropBoolPropertyChangeLocalChangeRemoteCb(const FTestbed1StructBoolWithArray& PropBool);

	UFUNCTION()
	void PropIntPropertyCb(const FTestbed1StructIntWithArray& PropInt);
	UFUNCTION()
	void PropIntPropertyChangeLocalCheckRemoteCb(const FTestbed1StructIntWithArray& PropInt);
	UFUNCTION()
	void PropIntPropertyChangeLocalChangeRemoteCb(const FTestbed1StructIntWithArray& PropInt);

	UFUNCTION()
	void PropFloatPropertyCb(const FTestbed1StructFloatWithArray& PropFloat);
	UFUNCTION()
	void PropFloatPropertyChangeLocalCheckRemoteCb(const FTestbed1StructFloatWithArray& PropFloat);
	UFUNCTION()
	void PropFloatPropertyChangeLocalChangeRemoteCb(const FTestbed1StructFloatWithArray& PropFloat);

	UFUNCTION()
	void PropStringPropertyCb(const FTestbed1StructStringWithArray& PropString);
	UFUNCTION()
	void PropStringPropertyChangeLocalCheckRemoteCb(const FTestbed1StructStringWithArray& PropString);
	UFUNCTION()
	void PropStringPropertyChangeLocalChangeRemoteCb(const FTestbed1StructStringWithArray& PropString);

	UFUNCTION()
	void PropEnumPropertyCb(const FTestbed1StructEnumWithArray& PropEnum);
	UFUNCTION()
	void PropEnumPropertyChangeLocalCheckRemoteCb(const FTestbed1StructEnumWithArray& PropEnum);
	UFUNCTION()
	void PropEnumPropertyChangeLocalChangeRemoteCb(const FTestbed1StructEnumWithArray& PropEnum);

	UFUNCTION()
	void SigBoolSignalCb(const FTestbed1StructBoolWithArray& ParamBool);

	UFUNCTION()
	void SigIntSignalCb(const FTestbed1StructIntWithArray& ParamInt);

	UFUNCTION()
	void SigFloatSignalCb(const FTestbed1StructFloatWithArray& ParamFloat);

	UFUNCTION()
	void SigStringSignalCb(const FTestbed1StructStringWithArray& ParamString);

	UFUNCTION()
	void _ConnectionStatusChangedCb(bool bConnected);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTestbed1StructArray2InterfaceMsgBusSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTestbed1StructArray2InterfaceMsgBusFixture
{
public:
	FTestbed1StructArray2InterfaceMsgBusFixture();
	~FTestbed1StructArray2InterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed1StructArray2InterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTestbed1StructArray2InterfaceMsgBusHelper> GetHelper();
	UTestbed1StructArray2InterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed1StructArray2InterfaceInterface> testImplementation;
	TSoftObjectPtr<UTestbed1StructArray2InterfaceMsgBusHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
