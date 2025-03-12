
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"
#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Testbed2/Generated/api/Testbed2_data.h"

class UTestbed2NestedStruct2InterfaceOLinkSpec;
class ITestbed2NestedStruct2InterfaceInterface;
class UTestbed2NestedStruct2InterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed2
{
namespace NestedStruct2Interface
{
namespace OLink
{
namespace Tests
{
class FTestbed2NestedStruct2InterfaceOLinkFixture
{
public:
	FTestbed2NestedStruct2InterfaceOLinkFixture();
	~FTestbed2NestedStruct2InterfaceOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> GetImplementation();
	UOLinkHost* GetHost();
	UTestbed2NestedStruct2InterfaceOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> testImplementation;
};
} // namespace Tests
} // namespace OLink
} // namespace NestedStruct2Interface
} // namespace Testbed2

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
