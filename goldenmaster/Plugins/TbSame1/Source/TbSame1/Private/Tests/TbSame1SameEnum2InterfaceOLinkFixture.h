
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"
#include "OLinkCommon.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSame1_data.h"
#include "HAL/Platform.h"
#include "TbSame1SameEnum2InterfaceOLinkFixture.generated.h"

class UTbSame1SameEnum2InterfaceOLinkSpec;
class ITbSame1SameEnum2InterfaceInterface;
class UTbSame1SameEnum2InterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

UCLASS()
class UTbSame1SameEnum2InterfaceOLinkHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTbSame1SameEnum2InterfaceOLinkSpec* InSpec);

	UFUNCTION()
	void Prop1PropertyCb(ETbSame1Enum1 Prop1);
	UFUNCTION()
	void Prop1PropertyChangeLocalCheckRemoteCb(ETbSame1Enum1 Prop1);
	UFUNCTION()
	void Prop1PropertyChangeLocalChangeRemoteCb(ETbSame1Enum1 Prop1);

	UFUNCTION()
	void Prop2PropertyCb(ETbSame1Enum2 Prop2);
	UFUNCTION()
	void Prop2PropertyChangeLocalCheckRemoteCb(ETbSame1Enum2 Prop2);
	UFUNCTION()
	void Prop2PropertyChangeLocalChangeRemoteCb(ETbSame1Enum2 Prop2);

	UFUNCTION()
	void Sig1SignalCb(ETbSame1Enum1 Param1);

	UFUNCTION()
	void Sig2SignalCb(ETbSame1Enum1 Param1, ETbSame1Enum2 Param2);

	UFUNCTION()
	void _SubscriptionStatusChangedCb(bool bSubscribed);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSame1SameEnum2InterfaceOLinkSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX

class FTbSame1SameEnum2InterfaceOLinkFixture
{
public:
	FTbSame1SameEnum2InterfaceOLinkFixture();
	~FTbSame1SameEnum2InterfaceOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame1SameEnum2InterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbSame1SameEnum2InterfaceOLinkHelper> GetHelper();
	UOLinkHost* GetHost();
	UTbSame1SameEnum2InterfaceOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame1SameEnum2InterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbSame1SameEnum2InterfaceOLinkHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
