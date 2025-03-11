
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSame1/Generated/api/TbSame1_data.h"

class UTbSame1SameEnum1InterfaceMsgBusSpec;
class ITbSame1SameEnum1InterfaceInterface;
class UTbSame1SameEnum1InterfaceMsgBusAdapter;
class IApiGearConnection;

class FTbSame1SameEnum1InterfaceMsgBusFixture
{
public:
	FTbSame1SameEnum1InterfaceMsgBusFixture();
	~FTbSame1SameEnum1InterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame1SameEnum1InterfaceInterface> GetImplementation();
	UTbSame1SameEnum1InterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame1SameEnum1InterfaceInterface> testImplementation;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
