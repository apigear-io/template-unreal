
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"
#include "OLinkCommon.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSame1_data.h"
#include "HAL/Platform.h"
#include "TbSame1SameEnum1InterfaceOLinkFixture.generated.h"

class FTbSame1SameEnum1InterfaceOLinkFixture;
class ITbSame1SameEnum1InterfaceInterface;
class UTbSame1SameEnum1InterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

UCLASS()
class UTbSame1SameEnum1InterfaceOLinkHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetParentFixture(TWeakPtr<FTbSame1SameEnum1InterfaceOLinkFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void Prop1PropertyCb(ETbSame1Enum1 Prop1);
	UFUNCTION()
	void Prop1PropertyChangeLocalCheckRemoteCb(ETbSame1Enum1 Prop1);
	UFUNCTION()
	void Prop1PropertyChangeLocalChangeRemoteCb(ETbSame1Enum1 Prop1);

	UFUNCTION()
	void Sig1SignalCb(ETbSame1Enum1 Param1);

	UFUNCTION()
	void _SubscriptionStatusChangedCb(bool bSubscribed);

protected:
	TWeakPtr<FTbSame1SameEnum1InterfaceOLinkFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX

class FTbSame1SameEnum1InterfaceOLinkFixture
{
public:
	FTbSame1SameEnum1InterfaceOLinkFixture();
	~FTbSame1SameEnum1InterfaceOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame1SameEnum1InterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbSame1SameEnum1InterfaceOLinkHelper> GetHelper();
	UOLinkHost* GetHost();
	UTbSame1SameEnum1InterfaceOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame1SameEnum1InterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbSame1SameEnum1InterfaceOLinkHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
