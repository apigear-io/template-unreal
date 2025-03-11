
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbEnum/Generated/api/TbEnum_data.h"

class UTbEnumEnumInterfaceMsgBusSpec;
class ITbEnumEnumInterfaceInterface;
class UTbEnumEnumInterfaceMsgBusAdapter;
class IApiGearConnection;

class FTbEnumEnumInterfaceMsgBusFixture
{
public:
	FTbEnumEnumInterfaceMsgBusFixture();
	~FTbEnumEnumInterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbEnumEnumInterfaceInterface> GetImplementation();
	UTbEnumEnumInterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbEnumEnumInterfaceInterface> testImplementation;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
