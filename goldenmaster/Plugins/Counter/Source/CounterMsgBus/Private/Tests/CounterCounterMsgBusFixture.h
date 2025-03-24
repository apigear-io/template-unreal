
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Counter/Generated/api/Counter_data.h"

class UCounterCounterMsgBusSpec;
class ICounterCounterInterface;
class UCounterCounterMsgBusAdapter;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Counter
{
namespace Counter
{
namespace MsgBus
{
namespace Tests
{
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
} // namespace Tests
} // namespace MsgBus
} // namespace Counter
} // namespace Counter

#endif // WITH_DEV_AUTOMATION_TESTS
