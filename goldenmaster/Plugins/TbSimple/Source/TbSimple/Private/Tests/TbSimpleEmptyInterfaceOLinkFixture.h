
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSimple_data.h"
#include "TbSimpleEmptyInterfaceOLinkFixture.generated.h"

class UTbSimpleEmptyInterfaceOLinkSpec;
class ITbSimpleEmptyInterfaceInterface;
class UTbSimpleEmptyInterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

UCLASS()
class UTbSimpleEmptyInterfaceOLinkHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTbSimpleEmptyInterfaceOLinkSpec* InSpec);

	UFUNCTION()
	void _SubscriptionStatusChangedCb(bool bSubscribed);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSimpleEmptyInterfaceOLinkSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSimpleEmptyInterfaceOLinkFixture
{
public:
	FTbSimpleEmptyInterfaceOLinkFixture();
	~FTbSimpleEmptyInterfaceOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleEmptyInterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbSimpleEmptyInterfaceOLinkHelper> GetHelper();
	UOLinkHost* GetHost();
	UTbSimpleEmptyInterfaceOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TWeakObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleEmptyInterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbSimpleEmptyInterfaceOLinkHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
