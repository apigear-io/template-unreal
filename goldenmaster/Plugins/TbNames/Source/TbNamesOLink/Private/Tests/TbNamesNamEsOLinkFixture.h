
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"
#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbNames/Generated/api/TbNames_data.h"

class UTbNamesNamEsOLinkSpec;
class ITbNamesNamEsInterface;
class UTbNamesNamEsOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

class FTbNamesNamEsOLinkFixture
{
public:
	FTbNamesNamEsOLinkFixture();
	~FTbNamesNamEsOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbNamesNamEsInterface> GetImplementation();
	UOLinkHost* GetHost();
	UTbNamesNamEsOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbNamesNamEsInterface> testImplementation;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
