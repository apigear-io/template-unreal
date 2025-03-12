
#pragma once

#include "Misc/AutomationTest.h"
#include "HAL/Platform.h"
#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
#include "Engine/GameInstance.h"
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Testbed2/Generated/api/Testbed2_data.h"

class UTestbed2ManyParamInterfaceOLinkSpec;
class ITestbed2ManyParamInterfaceInterface;
class UTestbed2ManyParamInterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed2
{
namespace ManyParamInterface
{
namespace OLink
{
namespace Tests
{
class FTestbed2ManyParamInterfaceOLinkFixture
{
public:
	FTestbed2ManyParamInterfaceOLinkFixture();
	~FTestbed2ManyParamInterfaceOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed2ManyParamInterfaceInterface> GetImplementation();
	UOLinkHost* GetHost();
	UTestbed2ManyParamInterfaceOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed2ManyParamInterfaceInterface> testImplementation;
};
} // namespace Tests
} // namespace OLink
} // namespace ManyParamInterface
} // namespace Testbed2

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
