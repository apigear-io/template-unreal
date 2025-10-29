
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Counter/Generated/api/Counter_data.h"

class UCounterCounterJniSpec;
class ICounterCounterInterface;
class UCounterCounterJniAdapter;
class UCounterCounterJniClient;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Counter
{
namespace Counter
{
namespace Jni
{
namespace Tests
{
class FCounterCounterJniFixture
{
public:
	FCounterCounterJniFixture();
	~FCounterCounterJniFixture();

	UGameInstance* GetGameInstance();
	UCounterCounterJniClient* GetClient();
	TScriptInterface<ICounterCounterInterface> GetLocalImplementation();
	UCounterCounterJniAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ICounterCounterInterface> source;
};
} // namespace Tests
} // namespace Jni
} // namespace Counter
} // namespace Counter

#endif // WITH_DEV_AUTOMATION_TESTS
