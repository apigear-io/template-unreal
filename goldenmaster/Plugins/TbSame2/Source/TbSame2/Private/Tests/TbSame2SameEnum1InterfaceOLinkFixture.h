
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"
#include "OLinkCommon.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSame2_data.h"
#include "HAL/Platform.h"
#include "TbSame2SameEnum1InterfaceOLinkFixture.generated.h"

class FTbSame2SameEnum1InterfaceOLinkFixture;
class ITbSame2SameEnum1InterfaceInterface;
class UTbSame2SameEnum1InterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

UCLASS()
class UTbSame2SameEnum1InterfaceOLinkHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetParentFixture(TWeakPtr<FTbSame2SameEnum1InterfaceOLinkFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void Prop1PropertyCb(ETbSame2Enum1 Prop1);
	UFUNCTION()
	void Prop1PropertyChangeLocalCheckRemoteCb(ETbSame2Enum1 Prop1);
	UFUNCTION()
	void Prop1PropertyChangeLocalChangeRemoteCb(ETbSame2Enum1 Prop1);

	UFUNCTION()
	void Sig1SignalCb(ETbSame2Enum1 Param1);

	UFUNCTION()
	void _SubscriptionStatusChangedCb(bool bSubscribed);

protected:
	TWeakPtr<FTbSame2SameEnum1InterfaceOLinkFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX

class FTbSame2SameEnum1InterfaceOLinkFixture
{
public:
	FTbSame2SameEnum1InterfaceOLinkFixture();
	~FTbSame2SameEnum1InterfaceOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame2SameEnum1InterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbSame2SameEnum1InterfaceOLinkHelper> GetHelper();
	UOLinkHost* GetHost();
	UTbSame2SameEnum1InterfaceOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame2SameEnum1InterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbSame2SameEnum1InterfaceOLinkHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
