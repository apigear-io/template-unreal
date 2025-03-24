
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSimple/Generated/api/TbSimple_data.h"

class UTbSimpleSimpleArrayInterfaceMsgBusSpec;
class ITbSimpleSimpleArrayInterfaceInterface;
class UTbSimpleSimpleArrayInterfaceMsgBusAdapter;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace SimpleArrayInterface
{
namespace MsgBus
{
namespace Tests
{
class FTbSimpleSimpleArrayInterfaceMsgBusFixture
{
public:
	FTbSimpleSimpleArrayInterfaceMsgBusFixture();
	~FTbSimpleSimpleArrayInterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> GetImplementation();
	UTbSimpleSimpleArrayInterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> testImplementation;
};
} // namespace Tests
} // namespace MsgBus
} // namespace SimpleArrayInterface
} // namespace TbSimple

#endif // WITH_DEV_AUTOMATION_TESTS
