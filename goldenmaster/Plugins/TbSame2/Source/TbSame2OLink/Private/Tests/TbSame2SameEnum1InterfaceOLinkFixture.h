
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"
#include "OLinkCommon.h"
#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "Engine/GameInstance.h"
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSame2/Generated/api/TbSame2_data.h"

class UTbSame2SameEnum1InterfaceOLinkSpec;
class ITbSame2SameEnum1InterfaceInterface;
class UTbSame2SameEnum1InterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame2
{
namespace SameEnum1Interface
{
namespace OLink
{
namespace Tests
{
class FTbSame2SameEnum1InterfaceOLinkFixture
{
public:
	FTbSame2SameEnum1InterfaceOLinkFixture();
	~FTbSame2SameEnum1InterfaceOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame2SameEnum1InterfaceInterface> GetImplementation();
	UOLinkHost* GetHost();
	UTbSame2SameEnum1InterfaceOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame2SameEnum1InterfaceInterface> testImplementation;
};
} // namespace Tests
} // namespace OLink
} // namespace SameEnum1Interface
} // namespace TbSame2

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
