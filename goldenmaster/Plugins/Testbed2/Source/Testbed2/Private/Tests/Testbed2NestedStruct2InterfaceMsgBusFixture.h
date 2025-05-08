
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/Testbed2_data.h"
#include "HAL/Platform.h"
#include "Testbed2NestedStruct2InterfaceMsgBusFixture.generated.h"

class FTestbed2NestedStruct2InterfaceMsgBusFixture;
class ITestbed2NestedStruct2InterfaceInterface;
class UTestbed2NestedStruct2InterfaceMsgBusAdapter;
class IApiGearConnection;

UCLASS()
class UTestbed2NestedStruct2InterfaceMsgBusHelper : public UObject
{
	GENERATED_BODY()
public:
	~UTestbed2NestedStruct2InterfaceMsgBusHelper();

	void SetParentFixture(TWeakPtr<FTestbed2NestedStruct2InterfaceMsgBusFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void Prop1PropertyCb(const FTestbed2NestedStruct1& Prop1);
	UFUNCTION()
	void Prop1PropertyChangeLocalCheckRemoteCb(const FTestbed2NestedStruct1& Prop1);
	UFUNCTION()
	void Prop1PropertyChangeLocalChangeRemoteCb(const FTestbed2NestedStruct1& Prop1);

	UFUNCTION()
	void Prop2PropertyCb(const FTestbed2NestedStruct2& Prop2);
	UFUNCTION()
	void Prop2PropertyChangeLocalCheckRemoteCb(const FTestbed2NestedStruct2& Prop2);
	UFUNCTION()
	void Prop2PropertyChangeLocalChangeRemoteCb(const FTestbed2NestedStruct2& Prop2);

	UFUNCTION()
	void Sig1SignalCb(const FTestbed2NestedStruct1& Param1);

	UFUNCTION()
	void Sig2SignalCb(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2);

	UFUNCTION()
	void _ConnectionStatusChangedCb(bool bConnected);

protected:
	TWeakPtr<FTestbed2NestedStruct2InterfaceMsgBusFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTestbed2NestedStruct2InterfaceMsgBusFixture
{
public:
	FTestbed2NestedStruct2InterfaceMsgBusFixture();
	~FTestbed2NestedStruct2InterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTestbed2NestedStruct2InterfaceMsgBusHelper> GetHelper();
	UTestbed2NestedStruct2InterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> testImplementation;
	TSoftObjectPtr<UTestbed2NestedStruct2InterfaceMsgBusHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
