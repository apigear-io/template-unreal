
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSame1/Generated/api/TbSame1_data.h"

class UTbSame1SameEnum2InterfaceMsgBusSpec;
class ITbSame1SameEnum2InterfaceInterface;
class UTbSame1SameEnum2InterfaceMsgBusAdapter;
class IApiGearConnection;

class FTbSame1SameEnum2InterfaceMsgBusFixture
{
public:
	FTbSame1SameEnum2InterfaceMsgBusFixture();
	~FTbSame1SameEnum2InterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame1SameEnum2InterfaceInterface> GetImplementation();
	UTbSame1SameEnum2InterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame1SameEnum2InterfaceInterface> testImplementation;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
