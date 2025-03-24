
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"
#include "OLinkCommon.h"
#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "Engine/GameInstance.h"
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSame1/Generated/api/TbSame1_data.h"

class UTbSame1SameEnum2InterfaceOLinkSpec;
class ITbSame1SameEnum2InterfaceInterface;
class UTbSame1SameEnum2InterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame1
{
namespace SameEnum2Interface
{
namespace OLink
{
namespace Tests
{
class FTbSame1SameEnum2InterfaceOLinkFixture
{
public:
	FTbSame1SameEnum2InterfaceOLinkFixture();
	~FTbSame1SameEnum2InterfaceOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame1SameEnum2InterfaceInterface> GetImplementation();
	UOLinkHost* GetHost();
	UTbSame1SameEnum2InterfaceOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame1SameEnum2InterfaceInterface> testImplementation;
};
} // namespace Tests
} // namespace OLink
} // namespace SameEnum2Interface
} // namespace TbSame1

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
