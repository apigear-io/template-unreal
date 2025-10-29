
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSimple/Generated/api/TbSimple_data.h"

class UTbSimpleVoidInterfaceJniSpec;
class ITbSimpleVoidInterfaceInterface;
class UTbSimpleVoidInterfaceJniAdapter;
class UTbSimpleVoidInterfaceJniClient;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace VoidInterface
{
namespace Jni
{
namespace Tests
{
class FTbSimpleVoidInterfaceJniFixture
{
public:
	FTbSimpleVoidInterfaceJniFixture();
	~FTbSimpleVoidInterfaceJniFixture();

	UGameInstance* GetGameInstance();
	UTbSimpleVoidInterfaceJniClient* GetClient();
	TScriptInterface<ITbSimpleVoidInterfaceInterface> GetLocalImplementation();
	UTbSimpleVoidInterfaceJniAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleVoidInterfaceInterface> source;
};
} // namespace Tests
} // namespace Jni
} // namespace VoidInterface
} // namespace TbSimple

#endif // WITH_DEV_AUTOMATION_TESTS
