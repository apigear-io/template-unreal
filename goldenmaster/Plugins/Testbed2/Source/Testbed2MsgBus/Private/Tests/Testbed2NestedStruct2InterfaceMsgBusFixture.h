
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Testbed2/Generated/api/Testbed2_data.h"

class UTestbed2NestedStruct2InterfaceMsgBusSpec;
class ITestbed2NestedStruct2InterfaceInterface;
class UTestbed2NestedStruct2InterfaceMsgBusAdapter;
class IApiGearConnection;

class FTestbed2NestedStruct2InterfaceMsgBusFixture
{
public:
	FTestbed2NestedStruct2InterfaceMsgBusFixture();
	~FTestbed2NestedStruct2InterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> GetImplementation();
	UTestbed2NestedStruct2InterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> testImplementation;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
