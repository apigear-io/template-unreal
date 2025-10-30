
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSimple/Generated/api/TbSimple_data.h"

class UTbSimpleEmptyInterfaceJniSpec;
class ITbSimpleEmptyInterfaceInterface;
class UTbSimpleEmptyInterfaceJniAdapter;
class UTbSimpleEmptyInterfaceJniClient;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace EmptyInterface
{
namespace Jni
{
namespace Tests
{
class FTbSimpleEmptyInterfaceJniFixture
{
public:
	FTbSimpleEmptyInterfaceJniFixture();
	~FTbSimpleEmptyInterfaceJniFixture();

	UGameInstance* GetGameInstance();
	UTbSimpleEmptyInterfaceJniClient* GetClient();
	TScriptInterface<ITbSimpleEmptyInterfaceInterface> GetLocalImplementation();
	UTbSimpleEmptyInterfaceJniAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleEmptyInterfaceInterface> source;
};
} // namespace Tests
} // namespace Jni
} // namespace EmptyInterface
} // namespace TbSimple

#endif // WITH_DEV_AUTOMATION_TESTS
