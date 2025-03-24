
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"
#include "OLinkCommon.h"
#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "Engine/GameInstance.h"
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbEnum/Generated/api/TbEnum_data.h"

class UTbEnumEnumInterfaceOLinkSpec;
class ITbEnumEnumInterfaceInterface;
class UTbEnumEnumInterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbEnum
{
namespace EnumInterface
{
namespace OLink
{
namespace Tests
{
class FTbEnumEnumInterfaceOLinkFixture
{
public:
	FTbEnumEnumInterfaceOLinkFixture();
	~FTbEnumEnumInterfaceOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbEnumEnumInterfaceInterface> GetImplementation();
	UOLinkHost* GetHost();
	UTbEnumEnumInterfaceOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbEnumEnumInterfaceInterface> testImplementation;
};
} // namespace Tests
} // namespace OLink
} // namespace EnumInterface
} // namespace TbEnum

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
