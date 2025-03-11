
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSame2/Generated/api/TbSame2_data.h"

class UTbSame2SameStruct2InterfaceMsgBusSpec;
class ITbSame2SameStruct2InterfaceInterface;
class UTbSame2SameStruct2InterfaceMsgBusAdapter;
class IApiGearConnection;

class FTbSame2SameStruct2InterfaceMsgBusFixture
{
public:
	FTbSame2SameStruct2InterfaceMsgBusFixture();
	~FTbSame2SameStruct2InterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame2SameStruct2InterfaceInterface> GetImplementation();
	UTbSame2SameStruct2InterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame2SameStruct2InterfaceInterface> testImplementation;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
