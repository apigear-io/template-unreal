
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSimple/Generated/api/TbSimple_data.h"

class UTbSimpleNoSignalsInterfaceMsgBusSpec;
class ITbSimpleNoSignalsInterfaceInterface;
class UTbSimpleNoSignalsInterfaceMsgBusAdapter;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace NoSignalsInterface
{
namespace MsgBus
{
namespace Tests
{
class FTbSimpleNoSignalsInterfaceMsgBusFixture
{
public:
	FTbSimpleNoSignalsInterfaceMsgBusFixture();
	~FTbSimpleNoSignalsInterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> GetImplementation();
	UTbSimpleNoSignalsInterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> testImplementation;
};
} // namespace Tests
} // namespace MsgBus
} // namespace NoSignalsInterface
} // namespace TbSimple

#endif // WITH_DEV_AUTOMATION_TESTS
