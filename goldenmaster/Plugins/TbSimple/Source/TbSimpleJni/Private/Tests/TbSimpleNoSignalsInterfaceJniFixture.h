
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSimple/Generated/api/TbSimple_data.h"

class UTbSimpleNoSignalsInterfaceJniSpec;
class ITbSimpleNoSignalsInterfaceInterface;
class UTbSimpleNoSignalsInterfaceJniAdapter;
class UTbSimpleNoSignalsInterfaceJniClient;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace NoSignalsInterface
{
namespace Jni
{
namespace Tests
{
class FTbSimpleNoSignalsInterfaceJniFixture
{
public:
	FTbSimpleNoSignalsInterfaceJniFixture();
	~FTbSimpleNoSignalsInterfaceJniFixture();

	UGameInstance* GetGameInstance();
	UTbSimpleNoSignalsInterfaceJniClient* GetClient();
	TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> GetLocalImplementation();
	UTbSimpleNoSignalsInterfaceJniAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> source;
};
} // namespace Tests
} // namespace Jni
} // namespace NoSignalsInterface
} // namespace TbSimple

#endif // WITH_DEV_AUTOMATION_TESTS
