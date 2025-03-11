
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbNames/Generated/api/TbNames_data.h"

class UTbNamesNamEsMsgBusSpec;
class ITbNamesNamEsInterface;
class UTbNamesNamEsMsgBusAdapter;
class IApiGearConnection;

class FTbNamesNamEsMsgBusFixture
{
public:
	FTbNamesNamEsMsgBusFixture();
	~FTbNamesNamEsMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbNamesNamEsInterface> GetImplementation();
	UTbNamesNamEsMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbNamesNamEsInterface> testImplementation;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
