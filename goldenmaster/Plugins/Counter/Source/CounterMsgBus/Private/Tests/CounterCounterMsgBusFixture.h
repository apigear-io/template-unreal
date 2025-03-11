
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Counter/Generated/api/Counter_data.h"

class UCounterCounterMsgBusSpec;
class ICounterCounterInterface;
class UCounterCounterMsgBusAdapter;
class IApiGearConnection;

class FCounterCounterMsgBusFixture
{
public:
	FCounterCounterMsgBusFixture();
	~FCounterCounterMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ICounterCounterInterface> GetImplementation();
	UCounterCounterMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ICounterCounterInterface> testImplementation;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
