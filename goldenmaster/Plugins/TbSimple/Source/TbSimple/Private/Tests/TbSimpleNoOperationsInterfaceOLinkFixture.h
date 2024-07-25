
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSimple_data.h"
#include "TbSimpleNoOperationsInterfaceOLinkFixture.generated.h"

class UTbSimpleNoOperationsInterfaceOLinkSpec;
class ITbSimpleNoOperationsInterfaceInterface;
class UTbSimpleNoOperationsInterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

UCLASS()
class UTbSimpleNoOperationsInterfaceOLinkHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTbSimpleNoOperationsInterfaceOLinkSpec* InSpec);

	UFUNCTION()
	void PropBoolPropertyCb(bool bPropBool);

	UFUNCTION()
	void PropIntPropertyCb(int32 PropInt);

	UFUNCTION()
	void SigVoidSignalCb();

	UFUNCTION()
	void SigBoolSignalCb(bool bParamBool);

	UFUNCTION()
	void _SubscriptionStatusChangedCb(bool bSubscribed);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSimpleNoOperationsInterfaceOLinkSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSimpleNoOperationsInterfaceOLinkFixture
{
public:
	FTbSimpleNoOperationsInterfaceOLinkFixture();
	~FTbSimpleNoOperationsInterfaceOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbSimpleNoOperationsInterfaceOLinkHelper> GetHelper();
	UOLinkHost* GetHost();
	UTbSimpleNoOperationsInterfaceOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TWeakObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbSimpleNoOperationsInterfaceOLinkHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
