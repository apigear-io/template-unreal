
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbRefIfaces/Generated/api/TbRefIfaces_data.h"

class UTbRefIfacesSimpleLocalIfMsgBusSpec;
class ITbRefIfacesSimpleLocalIfInterface;
class UTbRefIfacesSimpleLocalIfMsgBusAdapter;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbRefIfaces
{
namespace SimpleLocalIf
{
namespace MsgBus
{
namespace Tests
{
class FTbRefIfacesSimpleLocalIfMsgBusFixture
{
public:
	FTbRefIfacesSimpleLocalIfMsgBusFixture();
	~FTbRefIfacesSimpleLocalIfMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> GetImplementation();
	UTbRefIfacesSimpleLocalIfMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> testImplementation;
};
} // namespace Tests
} // namespace MsgBus
} // namespace SimpleLocalIf
} // namespace TbRefIfaces

#endif // WITH_DEV_AUTOMATION_TESTS
