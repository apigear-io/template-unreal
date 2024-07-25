
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSame1_data.h"
#include "TbSame1SameEnum1InterfaceOLinkFixture.generated.h"

class UTbSame1SameEnum1InterfaceOLinkSpec;
class ITbSame1SameEnum1InterfaceInterface;
class UTbSame1SameEnum1InterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

UCLASS()
class UTbSame1SameEnum1InterfaceOLinkHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTbSame1SameEnum1InterfaceOLinkSpec* InSpec);

	UFUNCTION()
	void Prop1PropertyCb(ETbSame1Enum1 Prop1);

	UFUNCTION()
	void Sig1SignalCb(ETbSame1Enum1 Param1);

	UFUNCTION()
	void _SubscriptionStatusChangedCb(bool bSubscribed);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSame1SameEnum1InterfaceOLinkSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

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

	TWeakObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame1SameEnum1InterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbSame1SameEnum1InterfaceOLinkHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
