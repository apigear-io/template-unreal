
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"
#include "OLinkCommon.h"
#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "Engine/GameInstance.h"
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbIfaceimport/Generated/api/TbIfaceimport_data.h"

class FTbIfaceimportEmptyIfOLinkFixture;
class ITbIfaceimportEmptyIfInterface;
class UTbIfaceimportEmptyIfOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbIfaceimport
{
namespace EmptyIf
{
namespace OLink
{
namespace Tests
{
class FTbIfaceimportEmptyIfOLinkFixture
{
public:
	FTbIfaceimportEmptyIfOLinkFixture();
	~FTbIfaceimportEmptyIfOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbIfaceimportEmptyIfInterface> GetImplementation();
	UOLinkHost* GetHost();
	UTbIfaceimportEmptyIfOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbIfaceimportEmptyIfInterface> testImplementation;
};
} // namespace Tests
} // namespace OLink
} // namespace EmptyIf
} // namespace TbIfaceimport

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
