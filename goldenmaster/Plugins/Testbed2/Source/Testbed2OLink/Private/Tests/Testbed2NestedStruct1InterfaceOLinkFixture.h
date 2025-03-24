
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"
#include "OLinkCommon.h"
#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "Engine/GameInstance.h"
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Testbed2/Generated/api/Testbed2_data.h"

class UTestbed2NestedStruct1InterfaceOLinkSpec;
class ITestbed2NestedStruct1InterfaceInterface;
class UTestbed2NestedStruct1InterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed2
{
namespace NestedStruct1Interface
{
namespace OLink
{
namespace Tests
{
class FTestbed2NestedStruct1InterfaceOLinkFixture
{
public:
	FTestbed2NestedStruct1InterfaceOLinkFixture();
	~FTestbed2NestedStruct1InterfaceOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> GetImplementation();
	UOLinkHost* GetHost();
	UTestbed2NestedStruct1InterfaceOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> testImplementation;
};
} // namespace Tests
} // namespace OLink
} // namespace NestedStruct1Interface
} // namespace Testbed2

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
