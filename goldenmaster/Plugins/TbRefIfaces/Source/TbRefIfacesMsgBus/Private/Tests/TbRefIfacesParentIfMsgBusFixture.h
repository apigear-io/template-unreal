
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbRefIfaces/Generated/api/TbRefIfaces_data.h"

class UTbRefIfacesParentIfMsgBusSpec;
class ITbRefIfacesParentIfInterface;
class UTbRefIfacesParentIfMsgBusAdapter;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbRefIfaces
{
namespace ParentIf
{
namespace MsgBus
{
namespace Tests
{
class FTbRefIfacesParentIfMsgBusFixture
{
public:
	FTbRefIfacesParentIfMsgBusFixture();
	~FTbRefIfacesParentIfMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbRefIfacesParentIfInterface> GetImplementation();
	UTbRefIfacesParentIfMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbRefIfacesParentIfInterface> testImplementation;
};
} // namespace Tests
} // namespace MsgBus
} // namespace ParentIf
} // namespace TbRefIfaces

#endif // WITH_DEV_AUTOMATION_TESTS
