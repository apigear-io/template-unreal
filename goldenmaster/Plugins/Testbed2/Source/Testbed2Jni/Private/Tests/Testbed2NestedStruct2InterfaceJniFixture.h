
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Testbed2/Generated/api/Testbed2_data.h"

class UTestbed2NestedStruct2InterfaceJniSpec;
class ITestbed2NestedStruct2InterfaceInterface;
class UTestbed2NestedStruct2InterfaceJniAdapter;
class UTestbed2NestedStruct2InterfaceJniClient;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed2
{
namespace NestedStruct2Interface
{
namespace Jni
{
namespace Tests
{
class FTestbed2NestedStruct2InterfaceJniFixture
{
public:
	FTestbed2NestedStruct2InterfaceJniFixture();
	~FTestbed2NestedStruct2InterfaceJniFixture();

	UGameInstance* GetGameInstance();
	UTestbed2NestedStruct2InterfaceJniClient* GetClient();
	TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> GetLocalImplementation();
	UTestbed2NestedStruct2InterfaceJniAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> source;
};
} // namespace Tests
} // namespace Jni
} // namespace NestedStruct2Interface
} // namespace Testbed2

#endif // WITH_DEV_AUTOMATION_TESTS
