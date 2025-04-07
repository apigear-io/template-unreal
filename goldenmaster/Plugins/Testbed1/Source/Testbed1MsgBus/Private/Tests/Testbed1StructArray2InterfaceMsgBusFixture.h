
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Testbed1/Generated/api/Testbed1_data.h"

class UTestbed1StructArray2InterfaceMsgBusSpec;
class ITestbed1StructArray2InterfaceInterface;
class UTestbed1StructArray2InterfaceMsgBusAdapter;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed1
{
namespace StructArray2Interface
{
namespace MsgBus
{
namespace Tests
{
class FTestbed1StructArray2InterfaceMsgBusFixture
{
public:
	FTestbed1StructArray2InterfaceMsgBusFixture();
	~FTestbed1StructArray2InterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed1StructArray2InterfaceInterface> GetImplementation();
	UTestbed1StructArray2InterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed1StructArray2InterfaceInterface> testImplementation;
};
} // namespace Tests
} // namespace MsgBus
} // namespace StructArray2Interface
} // namespace Testbed1

#endif // WITH_DEV_AUTOMATION_TESTS
