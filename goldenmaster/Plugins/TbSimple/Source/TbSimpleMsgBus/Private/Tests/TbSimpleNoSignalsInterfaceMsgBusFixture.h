
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSimple/Generated/api/TbSimple_data.h"

class UTbSimpleNoSignalsInterfaceMsgBusSpec;
class ITbSimpleNoSignalsInterfaceInterface;
class UTbSimpleNoSignalsInterfaceMsgBusAdapter;
class IApiGearConnection;

class FTbSimpleNoSignalsInterfaceMsgBusFixture
{
public:
	FTbSimpleNoSignalsInterfaceMsgBusFixture();
	~FTbSimpleNoSignalsInterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> GetImplementation();
	UTbSimpleNoSignalsInterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> testImplementation;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
