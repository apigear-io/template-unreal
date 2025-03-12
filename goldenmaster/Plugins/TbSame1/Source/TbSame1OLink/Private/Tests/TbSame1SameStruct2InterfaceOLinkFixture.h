
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"
#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSame1/Generated/api/TbSame1_data.h"

class UTbSame1SameStruct2InterfaceOLinkSpec;
class ITbSame1SameStruct2InterfaceInterface;
class UTbSame1SameStruct2InterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame1
{
namespace SameStruct2Interface
{
namespace OLink
{
namespace Tests
{
class FTbSame1SameStruct2InterfaceOLinkFixture
{
public:
	FTbSame1SameStruct2InterfaceOLinkFixture();
	~FTbSame1SameStruct2InterfaceOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame1SameStruct2InterfaceInterface> GetImplementation();
	UOLinkHost* GetHost();
	UTbSame1SameStruct2InterfaceOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame1SameStruct2InterfaceInterface> testImplementation;
};
} // namespace Tests
} // namespace OLink
} // namespace SameStruct2Interface
} // namespace TbSame1

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
