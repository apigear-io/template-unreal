
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

class FTbRefIfacesSimpleLocalIfOLinkFixture;
class ITbRefIfacesSimpleLocalIfInterface;
class UTbRefIfacesSimpleLocalIfOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbRefIfaces
{
namespace SimpleLocalIf
{
namespace OLink
{
namespace Tests
{
class FTbRefIfacesSimpleLocalIfOLinkFixture
{
public:
	FTbRefIfacesSimpleLocalIfOLinkFixture();
	~FTbRefIfacesSimpleLocalIfOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> GetImplementation();
	UOLinkHost* GetHost();
	UTbRefIfacesSimpleLocalIfOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> testImplementation;
};
} // namespace Tests
} // namespace OLink
} // namespace SimpleLocalIf
} // namespace TbRefIfaces

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
