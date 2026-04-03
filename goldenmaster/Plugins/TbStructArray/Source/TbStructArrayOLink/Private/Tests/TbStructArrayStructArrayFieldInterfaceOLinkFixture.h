
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"
#include "OLinkCommon.h"
#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "Engine/GameInstance.h"
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbStructArray/Generated/api/TbStructArray_data.h"

class FTbStructArrayStructArrayFieldInterfaceOLinkFixture;
class ITbStructArrayStructArrayFieldInterfaceInterface;
class UTbStructArrayStructArrayFieldInterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbStructArray
{
namespace StructArrayFieldInterface
{
namespace OLink
{
namespace Tests
{
class FTbStructArrayStructArrayFieldInterfaceOLinkFixture
{
public:
	FTbStructArrayStructArrayFieldInterfaceOLinkFixture();
	~FTbStructArrayStructArrayFieldInterfaceOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface> GetImplementation();
	UOLinkHost* GetHost();
	UTbStructArrayStructArrayFieldInterfaceOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface> testImplementation;
};
} // namespace Tests
} // namespace OLink
} // namespace StructArrayFieldInterface
} // namespace TbStructArray

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
