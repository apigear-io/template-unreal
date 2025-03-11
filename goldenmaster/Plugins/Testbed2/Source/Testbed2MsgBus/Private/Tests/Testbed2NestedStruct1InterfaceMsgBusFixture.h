
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Testbed2/Generated/api/Testbed2_data.h"

class UTestbed2NestedStruct1InterfaceMsgBusSpec;
class ITestbed2NestedStruct1InterfaceInterface;
class UTestbed2NestedStruct1InterfaceMsgBusAdapter;
class IApiGearConnection;

class FTestbed2NestedStruct1InterfaceMsgBusFixture
{
public:
	FTestbed2NestedStruct1InterfaceMsgBusFixture();
	~FTestbed2NestedStruct1InterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> GetImplementation();
	UTestbed2NestedStruct1InterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> testImplementation;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
