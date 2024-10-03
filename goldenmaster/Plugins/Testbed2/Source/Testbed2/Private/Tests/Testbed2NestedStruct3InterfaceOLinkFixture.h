
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Testbed2/Generated/api/Testbed2_data.h"
#include "HAL/Platform.h"
#include "Testbed2NestedStruct3InterfaceOLinkFixture.generated.h"

class UTestbed2NestedStruct3InterfaceOLinkSpec;
class ITestbed2NestedStruct3InterfaceInterface;
class UTestbed2NestedStruct3InterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

UCLASS()
class UTestbed2NestedStruct3InterfaceOLinkHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTestbed2NestedStruct3InterfaceOLinkSpec* InSpec);

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
	void _SubscriptionStatusChangedCb(bool bSubscribed);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTestbed2NestedStruct3InterfaceOLinkSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

class FTestbed2NestedStruct3InterfaceOLinkFixture
{
public:
	FTestbed2NestedStruct3InterfaceOLinkFixture();
	~FTestbed2NestedStruct3InterfaceOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTestbed2NestedStruct3InterfaceOLinkHelper> GetHelper();
	UOLinkHost* GetHost();
	UTestbed2NestedStruct3InterfaceOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> testImplementation;
	TSoftObjectPtr<UTestbed2NestedStruct3InterfaceOLinkHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
