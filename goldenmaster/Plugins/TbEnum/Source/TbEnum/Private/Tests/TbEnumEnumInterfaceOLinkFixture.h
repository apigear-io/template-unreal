
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"
#include "OLinkCommon.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbEnum_data.h"
#include "HAL/Platform.h"
#include "TbEnumEnumInterfaceOLinkFixture.generated.h"

class FTbEnumEnumInterfaceOLinkFixture;
class ITbEnumEnumInterfaceInterface;
class UTbEnumEnumInterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

UCLASS()
class UTbEnumEnumInterfaceOLinkHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetParentFixture(TWeakPtr<FTbEnumEnumInterfaceOLinkFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void Prop0PropertyCb(ETbEnumEnum0 Prop0);
	UFUNCTION()
	void Prop0PropertyChangeLocalCheckRemoteCb(ETbEnumEnum0 Prop0);
	UFUNCTION()
	void Prop0PropertyChangeLocalChangeRemoteCb(ETbEnumEnum0 Prop0);

	UFUNCTION()
	void Prop1PropertyCb(ETbEnumEnum1 Prop1);
	UFUNCTION()
	void Prop1PropertyChangeLocalCheckRemoteCb(ETbEnumEnum1 Prop1);
	UFUNCTION()
	void Prop1PropertyChangeLocalChangeRemoteCb(ETbEnumEnum1 Prop1);

	UFUNCTION()
	void Prop2PropertyCb(ETbEnumEnum2 Prop2);
	UFUNCTION()
	void Prop2PropertyChangeLocalCheckRemoteCb(ETbEnumEnum2 Prop2);
	UFUNCTION()
	void Prop2PropertyChangeLocalChangeRemoteCb(ETbEnumEnum2 Prop2);

	UFUNCTION()
	void Prop3PropertyCb(ETbEnumEnum3 Prop3);
	UFUNCTION()
	void Prop3PropertyChangeLocalCheckRemoteCb(ETbEnumEnum3 Prop3);
	UFUNCTION()
	void Prop3PropertyChangeLocalChangeRemoteCb(ETbEnumEnum3 Prop3);

	UFUNCTION()
	void Sig0SignalCb(ETbEnumEnum0 Param0);

	UFUNCTION()
	void Sig1SignalCb(ETbEnumEnum1 Param1);

	UFUNCTION()
	void Sig2SignalCb(ETbEnumEnum2 Param2);

	UFUNCTION()
	void Sig3SignalCb(ETbEnumEnum3 Param3);

	UFUNCTION()
	void _SubscriptionStatusChangedCb(bool bSubscribed);

protected:
	TWeakPtr<FTbEnumEnumInterfaceOLinkFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX

class FTbEnumEnumInterfaceOLinkFixture
{
public:
	FTbEnumEnumInterfaceOLinkFixture();
	~FTbEnumEnumInterfaceOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbEnumEnumInterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbEnumEnumInterfaceOLinkHelper> GetHelper();
	UOLinkHost* GetHost();
	UTbEnumEnumInterfaceOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbEnumEnumInterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbEnumEnumInterfaceOLinkHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
