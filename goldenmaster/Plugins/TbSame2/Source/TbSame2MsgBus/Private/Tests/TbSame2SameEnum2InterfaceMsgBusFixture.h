
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSame2/Generated/api/TbSame2_data.h"

class UTbSame2SameEnum2InterfaceMsgBusSpec;
class ITbSame2SameEnum2InterfaceInterface;
class UTbSame2SameEnum2InterfaceMsgBusAdapter;
class IApiGearConnection;

class FTbSame2SameEnum2InterfaceMsgBusFixture
{
public:
	FTbSame2SameEnum2InterfaceMsgBusFixture();
	~FTbSame2SameEnum2InterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame2SameEnum2InterfaceInterface> GetImplementation();
	UTbSame2SameEnum2InterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame2SameEnum2InterfaceInterface> testImplementation;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
