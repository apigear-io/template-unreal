
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Testbed1/Generated/api/Testbed1_data.h"

class UTestbed1StructArrayInterfaceJniSpec;
class ITestbed1StructArrayInterfaceInterface;
class UTestbed1StructArrayInterfaceJniAdapter;
class UTestbed1StructArrayInterfaceJniClient;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed1
{
namespace StructArrayInterface
{
namespace Jni
{
namespace Tests
{
class FTestbed1StructArrayInterfaceJniFixture
{
public:
	FTestbed1StructArrayInterfaceJniFixture();
	~FTestbed1StructArrayInterfaceJniFixture();

	UGameInstance* GetGameInstance();
	UTestbed1StructArrayInterfaceJniClient* GetClient();
	TScriptInterface<ITestbed1StructArrayInterfaceInterface> GetLocalImplementation();
	UTestbed1StructArrayInterfaceJniAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed1StructArrayInterfaceInterface> source;
};
} // namespace Tests
} // namespace Jni
} // namespace StructArrayInterface
} // namespace Testbed1

#endif // WITH_DEV_AUTOMATION_TESTS
