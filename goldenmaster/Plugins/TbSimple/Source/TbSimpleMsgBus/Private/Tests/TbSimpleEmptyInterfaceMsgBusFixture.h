
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSimple/Generated/api/TbSimple_data.h"

class UTbSimpleEmptyInterfaceMsgBusSpec;
class ITbSimpleEmptyInterfaceInterface;
class UTbSimpleEmptyInterfaceMsgBusAdapter;
class IApiGearConnection;

class FTbSimpleEmptyInterfaceMsgBusFixture
{
public:
	FTbSimpleEmptyInterfaceMsgBusFixture();
	~FTbSimpleEmptyInterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleEmptyInterfaceInterface> GetImplementation();
	UTbSimpleEmptyInterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleEmptyInterfaceInterface> testImplementation;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
