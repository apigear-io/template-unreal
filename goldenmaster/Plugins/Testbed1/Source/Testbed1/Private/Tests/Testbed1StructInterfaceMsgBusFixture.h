
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/Testbed1_data.h"
#include "HAL/Platform.h"
#include "Testbed1StructInterfaceMsgBusFixture.generated.h"

class UTestbed1StructInterfaceMsgBusSpec;
class ITestbed1StructInterfaceInterface;
class UTestbed1StructInterfaceMsgBusAdapter;
class IApiGearConnection;

UCLASS()
class UTestbed1StructInterfaceMsgBusHelper : public UObject
{
	GENERATED_BODY()
public:
	~UTestbed1StructInterfaceMsgBusHelper();

	void SetSpec(UTestbed1StructInterfaceMsgBusSpec* InSpec);

	UFUNCTION()
	void PropBoolPropertyCb(const FTestbed1StructBool& PropBool);

	UFUNCTION()
	void PropIntPropertyCb(const FTestbed1StructInt& PropInt);

	UFUNCTION()
	void PropFloatPropertyCb(const FTestbed1StructFloat& PropFloat);

	UFUNCTION()
	void PropStringPropertyCb(const FTestbed1StructString& PropString);

	UFUNCTION()
	void SigBoolSignalCb(const FTestbed1StructBool& ParamBool);

	UFUNCTION()
	void SigIntSignalCb(const FTestbed1StructInt& ParamInt);

	UFUNCTION()
	void SigFloatSignalCb(const FTestbed1StructFloat& ParamFloat);

	UFUNCTION()
	void SigStringSignalCb(const FTestbed1StructString& ParamString);

	UFUNCTION()
	void _ConnectionStatusChangedCb(bool bConnected);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTestbed1StructInterfaceMsgBusSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTestbed1StructInterfaceMsgBusFixture
{
public:
	FTestbed1StructInterfaceMsgBusFixture();
	~FTestbed1StructInterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed1StructInterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTestbed1StructInterfaceMsgBusHelper> GetHelper();
	UTestbed1StructInterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed1StructInterfaceInterface> testImplementation;
	TSoftObjectPtr<UTestbed1StructInterfaceMsgBusHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
