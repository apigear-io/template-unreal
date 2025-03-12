
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"
#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSimple/Generated/api/TbSimple_data.h"

class UTbSimpleNoPropertiesInterfaceOLinkSpec;
class ITbSimpleNoPropertiesInterfaceInterface;
class UTbSimpleNoPropertiesInterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace NoPropertiesInterface
{
namespace OLink
{
namespace Tests
{
class FTbSimpleNoPropertiesInterfaceOLinkFixture
{
public:
	FTbSimpleNoPropertiesInterfaceOLinkFixture();
	~FTbSimpleNoPropertiesInterfaceOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> GetImplementation();
	UOLinkHost* GetHost();
	UTbSimpleNoPropertiesInterfaceOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> testImplementation;
};
} // namespace Tests
} // namespace OLink
} // namespace NoPropertiesInterface
} // namespace TbSimple

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
