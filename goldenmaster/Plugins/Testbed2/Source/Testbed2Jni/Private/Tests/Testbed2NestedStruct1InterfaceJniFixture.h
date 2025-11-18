
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Testbed2/Generated/api/Testbed2_data.h"

class UTestbed2NestedStruct1InterfaceJniSpec;
class ITestbed2NestedStruct1InterfaceInterface;
class UTestbed2NestedStruct1InterfaceJniAdapter;
class UTestbed2NestedStruct1InterfaceJniClient;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed2
{
namespace NestedStruct1Interface
{
namespace Jni
{
namespace Tests
{
class FTestbed2NestedStruct1InterfaceJniFixture
{
public:
	FTestbed2NestedStruct1InterfaceJniFixture();
	~FTestbed2NestedStruct1InterfaceJniFixture();

	UGameInstance* GetGameInstance();
	UTestbed2NestedStruct1InterfaceJniClient* GetClient();
	TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> GetLocalImplementation();
	UTestbed2NestedStruct1InterfaceJniAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> source;
};
} // namespace Tests
} // namespace Jni
} // namespace NestedStruct1Interface
} // namespace Testbed2

#endif // WITH_DEV_AUTOMATION_TESTS
