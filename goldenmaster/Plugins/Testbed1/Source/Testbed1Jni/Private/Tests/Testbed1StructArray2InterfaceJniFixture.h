
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Testbed1/Generated/api/Testbed1_data.h"

class UTestbed1StructArray2InterfaceJniSpec;
class ITestbed1StructArray2InterfaceInterface;
class UTestbed1StructArray2InterfaceJniAdapter;
class UTestbed1StructArray2InterfaceJniClient;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed1
{
namespace StructArray2Interface
{
namespace Jni
{
namespace Tests
{
class FTestbed1StructArray2InterfaceJniFixture
{
public:
	FTestbed1StructArray2InterfaceJniFixture();
	~FTestbed1StructArray2InterfaceJniFixture();

	UGameInstance* GetGameInstance();
	UTestbed1StructArray2InterfaceJniClient* GetClient();
	TScriptInterface<ITestbed1StructArray2InterfaceInterface> GetLocalImplementation();
	UTestbed1StructArray2InterfaceJniAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed1StructArray2InterfaceInterface> source;
};
} // namespace Tests
} // namespace Jni
} // namespace StructArray2Interface
} // namespace Testbed1

#endif // WITH_DEV_AUTOMATION_TESTS
