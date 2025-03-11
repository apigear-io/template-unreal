
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Testbed2/Generated/api/Testbed2_data.h"

class UTestbed2NestedStruct3InterfaceMsgBusSpec;
class ITestbed2NestedStruct3InterfaceInterface;
class UTestbed2NestedStruct3InterfaceMsgBusAdapter;
class IApiGearConnection;

class FTestbed2NestedStruct3InterfaceMsgBusFixture
{
public:
	FTestbed2NestedStruct3InterfaceMsgBusFixture();
	~FTestbed2NestedStruct3InterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> GetImplementation();
	UTestbed2NestedStruct3InterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> testImplementation;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
