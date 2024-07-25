
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSimple_data.h"
#include "TbSimpleNoPropertiesInterfaceOLinkFixture.generated.h"

class UTbSimpleNoPropertiesInterfaceOLinkSpec;
class ITbSimpleNoPropertiesInterfaceInterface;
class UTbSimpleNoPropertiesInterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

UCLASS()
class UTbSimpleNoPropertiesInterfaceOLinkHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTbSimpleNoPropertiesInterfaceOLinkSpec* InSpec);

	UFUNCTION()
	void SigVoidSignalCb();

	UFUNCTION()
	void SigBoolSignalCb(bool bParamBool);

	UFUNCTION()
	void _SubscriptionStatusChangedCb(bool bSubscribed);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSimpleNoPropertiesInterfaceOLinkSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSimpleNoPropertiesInterfaceOLinkFixture
{
public:
	FTbSimpleNoPropertiesInterfaceOLinkFixture();
	~FTbSimpleNoPropertiesInterfaceOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbSimpleNoPropertiesInterfaceOLinkHelper> GetHelper();
	UOLinkHost* GetHost();
	UTbSimpleNoPropertiesInterfaceOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TWeakObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbSimpleNoPropertiesInterfaceOLinkHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
