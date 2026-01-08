
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSimple/Generated/api/TbSimple_data.h"

class UTbSimpleNoPropertiesInterfaceJniSpec;
class ITbSimpleNoPropertiesInterfaceInterface;
class UTbSimpleNoPropertiesInterfaceJniAdapter;
class UTbSimpleNoPropertiesInterfaceJniClient;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace NoPropertiesInterface
{
namespace Jni
{
namespace Tests
{
class FTbSimpleNoPropertiesInterfaceJniFixture
{
public:
	FTbSimpleNoPropertiesInterfaceJniFixture();
	~FTbSimpleNoPropertiesInterfaceJniFixture();

	UGameInstance* GetGameInstance();
	UTbSimpleNoPropertiesInterfaceJniClient* GetClient();
	TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> GetLocalImplementation();
	UTbSimpleNoPropertiesInterfaceJniAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> source;
};
} // namespace Tests
} // namespace Jni
} // namespace NoPropertiesInterface
} // namespace TbSimple

#endif // WITH_DEV_AUTOMATION_TESTS
