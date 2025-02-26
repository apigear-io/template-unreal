
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Testbed2/Generated/api/Testbed2_data.h"
#include "HAL/Platform.h"
#include "Testbed2NestedStruct3InterfaceMsgBusFixture.generated.h"

class UTestbed2NestedStruct3InterfaceMsgBusSpec;
class ITestbed2NestedStruct3InterfaceInterface;
class UTestbed2NestedStruct3InterfaceMsgBusAdapter;
class IApiGearConnection;

UCLASS()
class UTestbed2NestedStruct3InterfaceMsgBusHelper : public UObject
{
	GENERATED_BODY()
public:
	~UTestbed2NestedStruct3InterfaceMsgBusHelper();

	void SetSpec(UTestbed2NestedStruct3InterfaceMsgBusSpec* InSpec);

	UFUNCTION()
	void Prop1PropertyCb(const FTestbed2NestedStruct1& Prop1);

	UFUNCTION()
	void Prop2PropertyCb(const FTestbed2NestedStruct2& Prop2);

	UFUNCTION()
	void Prop3PropertyCb(const FTestbed2NestedStruct3& Prop3);

	UFUNCTION()
	void Sig1SignalCb(const FTestbed2NestedStruct1& Param1);

	UFUNCTION()
	void Sig2SignalCb(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2);

	UFUNCTION()
	void Sig3SignalCb(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3);

	UFUNCTION()
	void _ConnectionStatusChangedCb(bool bConnected);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTestbed2NestedStruct3InterfaceMsgBusSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

class FTestbed2NestedStruct3InterfaceMsgBusFixture
{
public:
	FTestbed2NestedStruct3InterfaceMsgBusFixture();
	~FTestbed2NestedStruct3InterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTestbed2NestedStruct3InterfaceMsgBusHelper> GetHelper();
	UTestbed2NestedStruct3InterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> testImplementation;
	TSoftObjectPtr<UTestbed2NestedStruct3InterfaceMsgBusHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
