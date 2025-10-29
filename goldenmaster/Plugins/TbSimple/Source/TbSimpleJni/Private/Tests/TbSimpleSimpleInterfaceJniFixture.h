
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSimple/Generated/api/TbSimple_data.h"

class UTbSimpleSimpleInterfaceJniSpec;
class ITbSimpleSimpleInterfaceInterface;
class UTbSimpleSimpleInterfaceJniAdapter;
class UTbSimpleSimpleInterfaceJniClient;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace SimpleInterface
{
namespace Jni
{
namespace Tests
{
class FTbSimpleSimpleInterfaceJniFixture
{
public:
	FTbSimpleSimpleInterfaceJniFixture();
	~FTbSimpleSimpleInterfaceJniFixture();

	UGameInstance* GetGameInstance();
	UTbSimpleSimpleInterfaceJniClient* GetClient();
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> GetLocalImplementation();
	UTbSimpleSimpleInterfaceJniAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> source;
};
} // namespace Tests
} // namespace Jni
} // namespace SimpleInterface
} // namespace TbSimple

#endif // WITH_DEV_AUTOMATION_TESTS
