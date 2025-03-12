
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"
#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbEnum/Generated/api/TbEnum_data.h"

class UTbEnumEnumInterfaceOLinkSpec;
class ITbEnumEnumInterfaceInterface;
class UTbEnumEnumInterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

class FTbEnumEnumInterfaceOLinkFixture
{
public:
	FTbEnumEnumInterfaceOLinkFixture();
	~FTbEnumEnumInterfaceOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbEnumEnumInterfaceInterface> GetImplementation();
	UOLinkHost* GetHost();
	UTbEnumEnumInterfaceOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbEnumEnumInterfaceInterface> testImplementation;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
