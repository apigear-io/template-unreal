
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSame2/Generated/api/TbSame2_data.h"

class UTbSame2SameEnum1InterfaceMsgBusSpec;
class ITbSame2SameEnum1InterfaceInterface;
class UTbSame2SameEnum1InterfaceMsgBusAdapter;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame2
{
namespace SameEnum1Interface
{
namespace MsgBus
{
namespace Tests
{
class FTbSame2SameEnum1InterfaceMsgBusFixture
{
public:
	FTbSame2SameEnum1InterfaceMsgBusFixture();
	~FTbSame2SameEnum1InterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame2SameEnum1InterfaceInterface> GetImplementation();
	UTbSame2SameEnum1InterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame2SameEnum1InterfaceInterface> testImplementation;
};
} // namespace Tests
} // namespace MsgBus
} // namespace SameEnum1Interface
} // namespace TbSame2

#endif // WITH_DEV_AUTOMATION_TESTS
