
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSimple/Generated/api/TbSimple_data.h"

class UTbSimpleSimpleArrayInterfaceMsgBusSpec;
class ITbSimpleSimpleArrayInterfaceInterface;
class UTbSimpleSimpleArrayInterfaceMsgBusAdapter;
class IApiGearConnection;

class FTbSimpleSimpleArrayInterfaceMsgBusFixture
{
public:
	FTbSimpleSimpleArrayInterfaceMsgBusFixture();
	~FTbSimpleSimpleArrayInterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> GetImplementation();
	UTbSimpleSimpleArrayInterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> testImplementation;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
