
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Testbed1/Generated/api/Testbed1_data.h"

class UTestbed1StructArrayInterfaceMsgBusSpec;
class ITestbed1StructArrayInterfaceInterface;
class UTestbed1StructArrayInterfaceMsgBusAdapter;
class IApiGearConnection;

class FTestbed1StructArrayInterfaceMsgBusFixture
{
public:
	FTestbed1StructArrayInterfaceMsgBusFixture();
	~FTestbed1StructArrayInterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed1StructArrayInterfaceInterface> GetImplementation();
	UTestbed1StructArrayInterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed1StructArrayInterfaceInterface> testImplementation;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
