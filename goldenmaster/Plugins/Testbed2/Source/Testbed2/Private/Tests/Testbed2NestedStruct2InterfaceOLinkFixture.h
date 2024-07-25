
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/Testbed2_data.h"
#include "Testbed2NestedStruct2InterfaceOLinkFixture.generated.h"

class UTestbed2NestedStruct2InterfaceOLinkSpec;
class ITestbed2NestedStruct2InterfaceInterface;
class UTestbed2NestedStruct2InterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

UCLASS()
class UTestbed2NestedStruct2InterfaceOLinkHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTestbed2NestedStruct2InterfaceOLinkSpec* InSpec);

	UFUNCTION()
	void Prop1PropertyCb(const FTestbed2NestedStruct1& Prop1);

	UFUNCTION()
	void Prop2PropertyCb(const FTestbed2NestedStruct2& Prop2);

	UFUNCTION()
	void Sig1SignalCb(const FTestbed2NestedStruct1& Param1);

	UFUNCTION()
	void Sig2SignalCb(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2);

	UFUNCTION()
	void _SubscriptionStatusChangedCb(bool bSubscribed);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTestbed2NestedStruct2InterfaceOLinkSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTestbed2NestedStruct2InterfaceOLinkFixture
{
public:
	FTestbed2NestedStruct2InterfaceOLinkFixture();
	~FTestbed2NestedStruct2InterfaceOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTestbed2NestedStruct2InterfaceOLinkHelper> GetHelper();
	UOLinkHost* GetHost();
	UTestbed2NestedStruct2InterfaceOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TWeakObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> testImplementation;
	TSoftObjectPtr<UTestbed2NestedStruct2InterfaceOLinkHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
