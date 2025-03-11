
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSimple/Generated/api/TbSimple_data.h"

class UTbSimpleNoOperationsInterfaceMsgBusSpec;
class ITbSimpleNoOperationsInterfaceInterface;
class UTbSimpleNoOperationsInterfaceMsgBusAdapter;
class IApiGearConnection;

class FTbSimpleNoOperationsInterfaceMsgBusFixture
{
public:
	FTbSimpleNoOperationsInterfaceMsgBusFixture();
	~FTbSimpleNoOperationsInterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> GetImplementation();
	UTbSimpleNoOperationsInterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> testImplementation;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
