
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"
#include "OLinkCommon.h"
#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "Engine/GameInstance.h"
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSimple/Generated/api/TbSimple_data.h"

class UTbSimpleEmptyInterfaceOLinkSpec;
class ITbSimpleEmptyInterfaceInterface;
class UTbSimpleEmptyInterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace EmptyInterface
{
namespace OLink
{
namespace Tests
{
class FTbSimpleEmptyInterfaceOLinkFixture
{
public:
	FTbSimpleEmptyInterfaceOLinkFixture();
	~FTbSimpleEmptyInterfaceOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleEmptyInterfaceInterface> GetImplementation();
	UOLinkHost* GetHost();
	UTbSimpleEmptyInterfaceOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleEmptyInterfaceInterface> testImplementation;
};
} // namespace Tests
} // namespace OLink
} // namespace EmptyInterface
} // namespace TbSimple

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
