
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"
#include "OLinkCommon.h"
#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "Engine/GameInstance.h"
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbRefIfaces/Generated/api/TbRefIfaces_data.h"

class FTbRefIfacesParentIfOLinkFixture;
class ITbRefIfacesParentIfInterface;
class UTbRefIfacesParentIfOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbRefIfaces
{
namespace ParentIf
{
namespace OLink
{
namespace Tests
{
class FTbRefIfacesParentIfOLinkFixture
{
public:
	FTbRefIfacesParentIfOLinkFixture();
	~FTbRefIfacesParentIfOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbRefIfacesParentIfInterface> GetImplementation();
	UOLinkHost* GetHost();
	UTbRefIfacesParentIfOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbRefIfacesParentIfInterface> testImplementation;
};
} // namespace Tests
} // namespace OLink
} // namespace ParentIf
} // namespace TbRefIfaces

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
