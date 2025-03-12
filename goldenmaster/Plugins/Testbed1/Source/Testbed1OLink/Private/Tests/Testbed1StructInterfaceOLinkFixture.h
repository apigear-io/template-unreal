
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"
#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Testbed1/Generated/api/Testbed1_data.h"

class UTestbed1StructInterfaceOLinkSpec;
class ITestbed1StructInterfaceInterface;
class UTestbed1StructInterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed1
{
namespace StructInterface
{
namespace OLink
{
namespace Tests
{
class FTestbed1StructInterfaceOLinkFixture
{
public:
	FTestbed1StructInterfaceOLinkFixture();
	~FTestbed1StructInterfaceOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed1StructInterfaceInterface> GetImplementation();
	UOLinkHost* GetHost();
	UTestbed1StructInterfaceOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed1StructInterfaceInterface> testImplementation;
};
} // namespace Tests
} // namespace OLink
} // namespace StructInterface
} // namespace Testbed1

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
