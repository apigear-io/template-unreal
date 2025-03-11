
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSame1/Generated/api/TbSame1_data.h"

class UTbSame1SameStruct1InterfaceMsgBusSpec;
class ITbSame1SameStruct1InterfaceInterface;
class UTbSame1SameStruct1InterfaceMsgBusAdapter;
class IApiGearConnection;

class FTbSame1SameStruct1InterfaceMsgBusFixture
{
public:
	FTbSame1SameStruct1InterfaceMsgBusFixture();
	~FTbSame1SameStruct1InterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame1SameStruct1InterfaceInterface> GetImplementation();
	UTbSame1SameStruct1InterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame1SameStruct1InterfaceInterface> testImplementation;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
