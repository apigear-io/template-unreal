
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"
#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSimple/Generated/api/TbSimple_data.h"

class UTbSimpleNoOperationsInterfaceOLinkSpec;
class ITbSimpleNoOperationsInterfaceInterface;
class UTbSimpleNoOperationsInterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace NoOperationsInterface
{
namespace OLink
{
namespace Tests
{
class FTbSimpleNoOperationsInterfaceOLinkFixture
{
public:
	FTbSimpleNoOperationsInterfaceOLinkFixture();
	~FTbSimpleNoOperationsInterfaceOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> GetImplementation();
	UOLinkHost* GetHost();
	UTbSimpleNoOperationsInterfaceOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> testImplementation;
};
} // namespace Tests
} // namespace OLink
} // namespace NoOperationsInterface
} // namespace TbSimple

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
