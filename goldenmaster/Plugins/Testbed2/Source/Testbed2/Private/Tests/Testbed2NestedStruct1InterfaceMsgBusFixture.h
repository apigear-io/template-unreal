
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/Testbed2_data.h"
#include "HAL/Platform.h"
#include "Testbed2NestedStruct1InterfaceMsgBusFixture.generated.h"

class FTestbed2NestedStruct1InterfaceMsgBusFixture;
class ITestbed2NestedStruct1InterfaceInterface;
class UTestbed2NestedStruct1InterfaceMsgBusAdapter;
class IApiGearConnection;

UCLASS()
class UTestbed2NestedStruct1InterfaceMsgBusHelper : public UObject
{
	GENERATED_BODY()
public:
	~UTestbed2NestedStruct1InterfaceMsgBusHelper();

	void SetParentFixture(TWeakPtr<FTestbed2NestedStruct1InterfaceMsgBusFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void Prop1PropertyCb(const FTestbed2NestedStruct1& Prop1);
	UFUNCTION()
	void Prop1PropertyChangeLocalCheckRemoteCb(const FTestbed2NestedStruct1& Prop1);
	UFUNCTION()
	void Prop1PropertyChangeLocalChangeRemoteCb(const FTestbed2NestedStruct1& Prop1);

	UFUNCTION()
	void Sig1SignalCb(const FTestbed2NestedStruct1& Param1);

	UFUNCTION()
	void _ConnectionStatusChangedCb(bool bConnected);

protected:
	TWeakPtr<FTestbed2NestedStruct1InterfaceMsgBusFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTestbed2NestedStruct1InterfaceMsgBusFixture
{
public:
	FTestbed2NestedStruct1InterfaceMsgBusFixture();
	~FTestbed2NestedStruct1InterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTestbed2NestedStruct1InterfaceMsgBusHelper> GetHelper();
	UTestbed2NestedStruct1InterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> testImplementation;
	TSoftObjectPtr<UTestbed2NestedStruct1InterfaceMsgBusHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
