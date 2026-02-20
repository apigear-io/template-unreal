
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSimple/Generated/api/TbSimple_data.h"

class UTbSimpleSimpleArrayInterfaceJniSpec;
class ITbSimpleSimpleArrayInterfaceInterface;
class UTbSimpleSimpleArrayInterfaceJniAdapter;
class UTbSimpleSimpleArrayInterfaceJniClient;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace SimpleArrayInterface
{
namespace Jni
{
namespace Tests
{
class FTbSimpleSimpleArrayInterfaceJniFixture
{
public:
	FTbSimpleSimpleArrayInterfaceJniFixture();
	~FTbSimpleSimpleArrayInterfaceJniFixture();

	UGameInstance* GetGameInstance();
	UTbSimpleSimpleArrayInterfaceJniClient* GetClient();
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> GetLocalImplementation();
	UTbSimpleSimpleArrayInterfaceJniAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> source;
};
} // namespace Tests
} // namespace Jni
} // namespace SimpleArrayInterface
} // namespace TbSimple

#endif // WITH_DEV_AUTOMATION_TESTS
