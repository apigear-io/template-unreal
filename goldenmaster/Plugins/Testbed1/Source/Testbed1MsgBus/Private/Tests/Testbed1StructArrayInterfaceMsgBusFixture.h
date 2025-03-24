
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Testbed1/Generated/api/Testbed1_data.h"

class UTestbed1StructArrayInterfaceMsgBusSpec;
class ITestbed1StructArrayInterfaceInterface;
class UTestbed1StructArrayInterfaceMsgBusAdapter;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed1
{
namespace StructArrayInterface
{
namespace MsgBus
{
namespace Tests
{
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
} // namespace Tests
} // namespace MsgBus
} // namespace StructArrayInterface
} // namespace Testbed1

#endif // WITH_DEV_AUTOMATION_TESTS
