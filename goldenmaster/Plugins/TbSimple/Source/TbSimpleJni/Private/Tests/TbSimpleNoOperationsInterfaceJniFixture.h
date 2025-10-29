
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSimple/Generated/api/TbSimple_data.h"

class UTbSimpleNoOperationsInterfaceJniSpec;
class ITbSimpleNoOperationsInterfaceInterface;
class UTbSimpleNoOperationsInterfaceJniAdapter;
class UTbSimpleNoOperationsInterfaceJniClient;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace NoOperationsInterface
{
namespace Jni
{
namespace Tests
{
class FTbSimpleNoOperationsInterfaceJniFixture
{
public:
	FTbSimpleNoOperationsInterfaceJniFixture();
	~FTbSimpleNoOperationsInterfaceJniFixture();

	UGameInstance* GetGameInstance();
	UTbSimpleNoOperationsInterfaceJniClient* GetClient();
	TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> GetLocalImplementation();
	UTbSimpleNoOperationsInterfaceJniAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> source;
};
} // namespace Tests
} // namespace Jni
} // namespace NoOperationsInterface
} // namespace TbSimple

#endif // WITH_DEV_AUTOMATION_TESTS
