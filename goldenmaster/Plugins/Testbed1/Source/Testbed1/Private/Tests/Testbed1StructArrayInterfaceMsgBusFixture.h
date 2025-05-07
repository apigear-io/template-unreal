
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/Testbed1_data.h"
#include "HAL/Platform.h"
#include "Testbed1StructArrayInterfaceMsgBusFixture.generated.h"

class UTestbed1StructArrayInterfaceMsgBusSpec;
class ITestbed1StructArrayInterfaceInterface;
class UTestbed1StructArrayInterfaceMsgBusAdapter;
class IApiGearConnection;

UCLASS()
class UTestbed1StructArrayInterfaceMsgBusHelper : public UObject
{
	GENERATED_BODY()
public:
	~UTestbed1StructArrayInterfaceMsgBusHelper();

	void SetSpec(UTestbed1StructArrayInterfaceMsgBusSpec* InSpec);

	UFUNCTION()
	void PropBoolPropertyCb(const TArray<FTestbed1StructBool>& PropBool);
	UFUNCTION()
	void PropBoolPropertyChangeLocalCheckRemoteCb(const TArray<FTestbed1StructBool>& PropBool);
	UFUNCTION()
	void PropBoolPropertyChangeLocalChangeRemoteCb(const TArray<FTestbed1StructBool>& PropBool);

	UFUNCTION()
	void PropIntPropertyCb(const TArray<FTestbed1StructInt>& PropInt);
	UFUNCTION()
	void PropIntPropertyChangeLocalCheckRemoteCb(const TArray<FTestbed1StructInt>& PropInt);
	UFUNCTION()
	void PropIntPropertyChangeLocalChangeRemoteCb(const TArray<FTestbed1StructInt>& PropInt);

	UFUNCTION()
	void PropFloatPropertyCb(const TArray<FTestbed1StructFloat>& PropFloat);
	UFUNCTION()
	void PropFloatPropertyChangeLocalCheckRemoteCb(const TArray<FTestbed1StructFloat>& PropFloat);
	UFUNCTION()
	void PropFloatPropertyChangeLocalChangeRemoteCb(const TArray<FTestbed1StructFloat>& PropFloat);

	UFUNCTION()
	void PropStringPropertyCb(const TArray<FTestbed1StructString>& PropString);
	UFUNCTION()
	void PropStringPropertyChangeLocalCheckRemoteCb(const TArray<FTestbed1StructString>& PropString);
	UFUNCTION()
	void PropStringPropertyChangeLocalChangeRemoteCb(const TArray<FTestbed1StructString>& PropString);

	UFUNCTION()
	void PropEnumPropertyCb(const TArray<ETestbed1Enum0>& PropEnum);
	UFUNCTION()
	void PropEnumPropertyChangeLocalCheckRemoteCb(const TArray<ETestbed1Enum0>& PropEnum);
	UFUNCTION()
	void PropEnumPropertyChangeLocalChangeRemoteCb(const TArray<ETestbed1Enum0>& PropEnum);

	UFUNCTION()
	void SigBoolSignalCb(const TArray<FTestbed1StructBool>& ParamBool);

	UFUNCTION()
	void SigIntSignalCb(const TArray<FTestbed1StructInt>& ParamInt);

	UFUNCTION()
	void SigFloatSignalCb(const TArray<FTestbed1StructFloat>& ParamFloat);

	UFUNCTION()
	void SigStringSignalCb(const TArray<FTestbed1StructString>& ParamString);

	UFUNCTION()
	void SigEnumSignalCb(const TArray<ETestbed1Enum0>& ParamEnum);

	UFUNCTION()
	void _ConnectionStatusChangedCb(bool bConnected);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTestbed1StructArrayInterfaceMsgBusSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTestbed1StructArrayInterfaceMsgBusFixture
{
public:
	FTestbed1StructArrayInterfaceMsgBusFixture();
	~FTestbed1StructArrayInterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed1StructArrayInterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTestbed1StructArrayInterfaceMsgBusHelper> GetHelper();
	UTestbed1StructArrayInterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed1StructArrayInterfaceInterface> testImplementation;
	TSoftObjectPtr<UTestbed1StructArrayInterfaceMsgBusHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
