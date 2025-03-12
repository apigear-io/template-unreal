
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"
#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSame2/Generated/api/TbSame2_data.h"

class UTbSame2SameEnum2InterfaceOLinkSpec;
class ITbSame2SameEnum2InterfaceInterface;
class UTbSame2SameEnum2InterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

class FTbSame2SameEnum2InterfaceOLinkFixture
{
public:
	FTbSame2SameEnum2InterfaceOLinkFixture();
	~FTbSame2SameEnum2InterfaceOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame2SameEnum2InterfaceInterface> GetImplementation();
	UOLinkHost* GetHost();
	UTbSame2SameEnum2InterfaceOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame2SameEnum2InterfaceInterface> testImplementation;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
