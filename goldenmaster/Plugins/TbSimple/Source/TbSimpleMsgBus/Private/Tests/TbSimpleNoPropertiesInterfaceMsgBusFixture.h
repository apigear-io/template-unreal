
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSimple/Generated/api/TbSimple_data.h"

class UTbSimpleNoPropertiesInterfaceMsgBusSpec;
class ITbSimpleNoPropertiesInterfaceInterface;
class UTbSimpleNoPropertiesInterfaceMsgBusAdapter;
class IApiGearConnection;

class FTbSimpleNoPropertiesInterfaceMsgBusFixture
{
public:
	FTbSimpleNoPropertiesInterfaceMsgBusFixture();
	~FTbSimpleNoPropertiesInterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> GetImplementation();
	UTbSimpleNoPropertiesInterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> testImplementation;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
