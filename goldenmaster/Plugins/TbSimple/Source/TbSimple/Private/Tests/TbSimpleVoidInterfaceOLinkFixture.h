
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"
#include "OLinkCommon.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSimple_data.h"
#include "HAL/Platform.h"
#include "TbSimpleVoidInterfaceOLinkFixture.generated.h"

class FTbSimpleVoidInterfaceOLinkFixture;
class ITbSimpleVoidInterfaceInterface;
class UTbSimpleVoidInterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

UCLASS()
class UTbSimpleVoidInterfaceOLinkHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetParentFixture(TWeakPtr<FTbSimpleVoidInterfaceOLinkFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void SigVoidSignalCb();

	UFUNCTION()
	void _SubscriptionStatusChangedCb(bool bSubscribed);

protected:
	TWeakPtr<FTbSimpleVoidInterfaceOLinkFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX

class FTbSimpleVoidInterfaceOLinkFixture
{
public:
	FTbSimpleVoidInterfaceOLinkFixture();
	~FTbSimpleVoidInterfaceOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleVoidInterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbSimpleVoidInterfaceOLinkHelper> GetHelper();
	UOLinkHost* GetHost();
	UTbSimpleVoidInterfaceOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleVoidInterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbSimpleVoidInterfaceOLinkHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
