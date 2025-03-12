
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"
#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSimple/Generated/api/TbSimple_data.h"

class UTbSimpleSimpleArrayInterfaceOLinkSpec;
class ITbSimpleSimpleArrayInterfaceInterface;
class UTbSimpleSimpleArrayInterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

class FTbSimpleSimpleArrayInterfaceOLinkFixture
{
public:
	FTbSimpleSimpleArrayInterfaceOLinkFixture();
	~FTbSimpleSimpleArrayInterfaceOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> GetImplementation();
	UOLinkHost* GetHost();
	UTbSimpleSimpleArrayInterfaceOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> testImplementation;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
