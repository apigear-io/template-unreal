
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Testbed2/Generated/api/Testbed2_data.h"
#include "HAL/Platform.h"
#include "Testbed2ManyParamInterfaceMsgBusFixture.generated.h"

class UTestbed2ManyParamInterfaceMsgBusSpec;
class ITestbed2ManyParamInterfaceInterface;
class UTestbed2ManyParamInterfaceMsgBusAdapter;
class IApiGearConnection;

UCLASS()
class UTestbed2ManyParamInterfaceMsgBusHelper : public UObject
{
	GENERATED_BODY()
public:
	~UTestbed2ManyParamInterfaceMsgBusHelper();

	void SetSpec(UTestbed2ManyParamInterfaceMsgBusSpec* InSpec);

	UFUNCTION()
	void Prop1PropertyCb(int32 Prop1);

	UFUNCTION()
	void Prop2PropertyCb(int32 Prop2);

	UFUNCTION()
	void Prop3PropertyCb(int32 Prop3);

	UFUNCTION()
	void Prop4PropertyCb(int32 Prop4);

	UFUNCTION()
	void Sig1SignalCb(int32 Param1);

	UFUNCTION()
	void Sig2SignalCb(int32 Param1, int32 Param2);

	UFUNCTION()
	void Sig3SignalCb(int32 Param1, int32 Param2, int32 Param3);

	UFUNCTION()
	void Sig4SignalCb(int32 Param1, int32 Param2, int32 Param3, int32 Param4);

	UFUNCTION()
	void _ConnectionStatusChangedCb(bool bConnected);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTestbed2ManyParamInterfaceMsgBusSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

class FTestbed2ManyParamInterfaceMsgBusFixture
{
public:
	FTestbed2ManyParamInterfaceMsgBusFixture();
	~FTestbed2ManyParamInterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed2ManyParamInterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTestbed2ManyParamInterfaceMsgBusHelper> GetHelper();
	UTestbed2ManyParamInterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed2ManyParamInterfaceInterface> testImplementation;
	TSoftObjectPtr<UTestbed2ManyParamInterfaceMsgBusHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
