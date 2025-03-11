
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSimple/Generated/api/TbSimple_data.h"

class UTbSimpleSimpleInterfaceMsgBusSpec;
class ITbSimpleSimpleInterfaceInterface;
class UTbSimpleSimpleInterfaceMsgBusAdapter;
class IApiGearConnection;

class FTbSimpleSimpleInterfaceMsgBusFixture
{
public:
	FTbSimpleSimpleInterfaceMsgBusFixture();
	~FTbSimpleSimpleInterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> GetImplementation();
	UTbSimpleSimpleInterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> testImplementation;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
