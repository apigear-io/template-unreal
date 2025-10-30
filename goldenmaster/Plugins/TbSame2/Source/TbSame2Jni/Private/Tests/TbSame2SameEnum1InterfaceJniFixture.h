
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSame2/Generated/api/TbSame2_data.h"

class UTbSame2SameEnum1InterfaceJniSpec;
class ITbSame2SameEnum1InterfaceInterface;
class UTbSame2SameEnum1InterfaceJniAdapter;
class UTbSame2SameEnum1InterfaceJniClient;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame2
{
namespace SameEnum1Interface
{
namespace Jni
{
namespace Tests
{
class FTbSame2SameEnum1InterfaceJniFixture
{
public:
	FTbSame2SameEnum1InterfaceJniFixture();
	~FTbSame2SameEnum1InterfaceJniFixture();

	UGameInstance* GetGameInstance();
	UTbSame2SameEnum1InterfaceJniClient* GetClient();
	TScriptInterface<ITbSame2SameEnum1InterfaceInterface> GetLocalImplementation();
	UTbSame2SameEnum1InterfaceJniAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame2SameEnum1InterfaceInterface> source;
};
} // namespace Tests
} // namespace Jni
} // namespace SameEnum1Interface
} // namespace TbSame2

#endif // WITH_DEV_AUTOMATION_TESTS
