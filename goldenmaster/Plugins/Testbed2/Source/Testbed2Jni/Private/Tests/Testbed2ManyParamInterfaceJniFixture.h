
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Testbed2/Generated/api/Testbed2_data.h"

class UTestbed2ManyParamInterfaceJniSpec;
class ITestbed2ManyParamInterfaceInterface;
class UTestbed2ManyParamInterfaceJniAdapter;
class UTestbed2ManyParamInterfaceJniClient;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed2
{
namespace ManyParamInterface
{
namespace Jni
{
namespace Tests
{
class FTestbed2ManyParamInterfaceJniFixture
{
public:
	FTestbed2ManyParamInterfaceJniFixture();
	~FTestbed2ManyParamInterfaceJniFixture();

	UGameInstance* GetGameInstance();
	UTestbed2ManyParamInterfaceJniClient* GetClient();
	TScriptInterface<ITestbed2ManyParamInterfaceInterface> GetLocalImplementation();
	UTestbed2ManyParamInterfaceJniAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed2ManyParamInterfaceInterface> source;
};
} // namespace Tests
} // namespace Jni
} // namespace ManyParamInterface
} // namespace Testbed2

#endif // WITH_DEV_AUTOMATION_TESTS
