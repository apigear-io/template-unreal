
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"
#include "OLinkCommon.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSame1_data.h"
#include "HAL/Platform.h"
#include "TbSame1SameStruct1InterfaceOLinkFixture.generated.h"

class FTbSame1SameStruct1InterfaceOLinkFixture;
class ITbSame1SameStruct1InterfaceInterface;
class UTbSame1SameStruct1InterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

UCLASS()
class UTbSame1SameStruct1InterfaceOLinkHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetParentFixture(TWeakPtr<FTbSame1SameStruct1InterfaceOLinkFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void Prop1PropertyCb(const FTbSame1Struct1& Prop1);
	UFUNCTION()
	void Prop1PropertyChangeLocalCheckRemoteCb(const FTbSame1Struct1& Prop1);
	UFUNCTION()
	void Prop1PropertyChangeLocalChangeRemoteCb(const FTbSame1Struct1& Prop1);

	UFUNCTION()
	void Sig1SignalCb(const FTbSame1Struct1& Param1);

	UFUNCTION()
	void _SubscriptionStatusChangedCb(bool bSubscribed);

protected:
	TWeakPtr<FTbSame1SameStruct1InterfaceOLinkFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX

class FTbSame1SameStruct1InterfaceOLinkFixture
{
public:
	FTbSame1SameStruct1InterfaceOLinkFixture();
	~FTbSame1SameStruct1InterfaceOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame1SameStruct1InterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbSame1SameStruct1InterfaceOLinkHelper> GetHelper();
	UOLinkHost* GetHost();
	UTbSame1SameStruct1InterfaceOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame1SameStruct1InterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbSame1SameStruct1InterfaceOLinkHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
