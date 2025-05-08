
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"
#include "OLinkCommon.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/Testbed2_data.h"
#include "HAL/Platform.h"
#include "Testbed2ManyParamInterfaceOLinkFixture.generated.h"

class FTestbed2ManyParamInterfaceOLinkFixture;
class ITestbed2ManyParamInterfaceInterface;
class UTestbed2ManyParamInterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

UCLASS()
class UTestbed2ManyParamInterfaceOLinkHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetParentFixture(TWeakPtr<FTestbed2ManyParamInterfaceOLinkFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void Prop1PropertyCb(int32 Prop1);
	UFUNCTION()
	void Prop1PropertyChangeLocalCheckRemoteCb(int32 Prop1);
	UFUNCTION()
	void Prop1PropertyChangeLocalChangeRemoteCb(int32 Prop1);

	UFUNCTION()
	void Prop2PropertyCb(int32 Prop2);
	UFUNCTION()
	void Prop2PropertyChangeLocalCheckRemoteCb(int32 Prop2);
	UFUNCTION()
	void Prop2PropertyChangeLocalChangeRemoteCb(int32 Prop2);

	UFUNCTION()
	void Prop3PropertyCb(int32 Prop3);
	UFUNCTION()
	void Prop3PropertyChangeLocalCheckRemoteCb(int32 Prop3);
	UFUNCTION()
	void Prop3PropertyChangeLocalChangeRemoteCb(int32 Prop3);

	UFUNCTION()
	void Prop4PropertyCb(int32 Prop4);
	UFUNCTION()
	void Prop4PropertyChangeLocalCheckRemoteCb(int32 Prop4);
	UFUNCTION()
	void Prop4PropertyChangeLocalChangeRemoteCb(int32 Prop4);

	UFUNCTION()
	void Sig1SignalCb(int32 Param1);

	UFUNCTION()
	void Sig2SignalCb(int32 Param1, int32 Param2);

	UFUNCTION()
	void Sig3SignalCb(int32 Param1, int32 Param2, int32 Param3);

	UFUNCTION()
	void Sig4SignalCb(int32 Param1, int32 Param2, int32 Param3, int32 Param4);

	UFUNCTION()
	void _SubscriptionStatusChangedCb(bool bSubscribed);

protected:
	TWeakPtr<FTestbed2ManyParamInterfaceOLinkFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX

class FTestbed2ManyParamInterfaceOLinkFixture
{
public:
	FTestbed2ManyParamInterfaceOLinkFixture();
	~FTestbed2ManyParamInterfaceOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed2ManyParamInterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTestbed2ManyParamInterfaceOLinkHelper> GetHelper();
	UOLinkHost* GetHost();
	UTestbed2ManyParamInterfaceOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed2ManyParamInterfaceInterface> testImplementation;
	TSoftObjectPtr<UTestbed2ManyParamInterfaceOLinkHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
