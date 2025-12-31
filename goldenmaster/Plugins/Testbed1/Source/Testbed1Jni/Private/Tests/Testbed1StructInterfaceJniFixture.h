
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Testbed1/Generated/api/Testbed1_data.h"

class UTestbed1StructInterfaceJniSpec;
class ITestbed1StructInterfaceInterface;
class UTestbed1StructInterfaceJniAdapter;
class UTestbed1StructInterfaceJniClient;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed1
{
namespace StructInterface
{
namespace Jni
{
namespace Tests
{
class FTestbed1StructInterfaceJniFixture
{
public:
	FTestbed1StructInterfaceJniFixture();
	~FTestbed1StructInterfaceJniFixture();

	UGameInstance* GetGameInstance();
	UTestbed1StructInterfaceJniClient* GetClient();
	TScriptInterface<ITestbed1StructInterfaceInterface> GetLocalImplementation();
	UTestbed1StructInterfaceJniAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed1StructInterfaceInterface> source;
};
} // namespace Tests
} // namespace Jni
} // namespace StructInterface
} // namespace Testbed1

#endif // WITH_DEV_AUTOMATION_TESTS
