
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSimple_data.h"
#include "TbSimpleNoSignalsInterfaceOLinkFixture.generated.h"

class UTbSimpleNoSignalsInterfaceOLinkSpec;
class ITbSimpleNoSignalsInterfaceInterface;
class UTbSimpleNoSignalsInterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

UCLASS()
class UTbSimpleNoSignalsInterfaceOLinkHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTbSimpleNoSignalsInterfaceOLinkSpec* InSpec);

	UFUNCTION()
	void PropBoolPropertyCb(bool bPropBool);

	UFUNCTION()
	void PropIntPropertyCb(int32 PropInt);

	UFUNCTION()
	void _SubscriptionStatusChangedCb(bool bSubscribed);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSimpleNoSignalsInterfaceOLinkSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSimpleNoSignalsInterfaceOLinkFixture
{
public:
	FTbSimpleNoSignalsInterfaceOLinkFixture();
	~FTbSimpleNoSignalsInterfaceOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbSimpleNoSignalsInterfaceOLinkHelper> GetHelper();
	UOLinkHost* GetHost();
	UTbSimpleNoSignalsInterfaceOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TWeakObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbSimpleNoSignalsInterfaceOLinkHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
