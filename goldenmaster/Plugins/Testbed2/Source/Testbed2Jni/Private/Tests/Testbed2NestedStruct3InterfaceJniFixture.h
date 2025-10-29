
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Testbed2/Generated/api/Testbed2_data.h"

class UTestbed2NestedStruct3InterfaceJniSpec;
class ITestbed2NestedStruct3InterfaceInterface;
class UTestbed2NestedStruct3InterfaceJniAdapter;
class UTestbed2NestedStruct3InterfaceJniClient;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed2
{
namespace NestedStruct3Interface
{
namespace Jni
{
namespace Tests
{
class FTestbed2NestedStruct3InterfaceJniFixture
{
public:
	FTestbed2NestedStruct3InterfaceJniFixture();
	~FTestbed2NestedStruct3InterfaceJniFixture();

	UGameInstance* GetGameInstance();
	UTestbed2NestedStruct3InterfaceJniClient* GetClient();
	TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> GetLocalImplementation();
	UTestbed2NestedStruct3InterfaceJniAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> source;
};
} // namespace Tests
} // namespace Jni
} // namespace NestedStruct3Interface
} // namespace Testbed2

#endif // WITH_DEV_AUTOMATION_TESTS
