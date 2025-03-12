
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"
#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSimple/Generated/api/TbSimple_data.h"

class UTbSimpleEmptyInterfaceOLinkSpec;
class ITbSimpleEmptyInterfaceInterface;
class UTbSimpleEmptyInterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

class FTbSimpleEmptyInterfaceOLinkFixture
{
public:
	FTbSimpleEmptyInterfaceOLinkFixture();
	~FTbSimpleEmptyInterfaceOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleEmptyInterfaceInterface> GetImplementation();
	UOLinkHost* GetHost();
	UTbSimpleEmptyInterfaceOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleEmptyInterfaceInterface> testImplementation;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
