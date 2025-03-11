
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSame2/Generated/api/TbSame2_data.h"

class UTbSame2SameStruct1InterfaceMsgBusSpec;
class ITbSame2SameStruct1InterfaceInterface;
class UTbSame2SameStruct1InterfaceMsgBusAdapter;
class IApiGearConnection;

class FTbSame2SameStruct1InterfaceMsgBusFixture
{
public:
	FTbSame2SameStruct1InterfaceMsgBusFixture();
	~FTbSame2SameStruct1InterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame2SameStruct1InterfaceInterface> GetImplementation();
	UTbSame2SameStruct1InterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame2SameStruct1InterfaceInterface> testImplementation;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
