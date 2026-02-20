
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSame1/Generated/api/TbSame1_data.h"

class UTbSame1SameEnum1InterfaceJniSpec;
class ITbSame1SameEnum1InterfaceInterface;
class UTbSame1SameEnum1InterfaceJniAdapter;
class UTbSame1SameEnum1InterfaceJniClient;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame1
{
namespace SameEnum1Interface
{
namespace Jni
{
namespace Tests
{
class FTbSame1SameEnum1InterfaceJniFixture
{
public:
	FTbSame1SameEnum1InterfaceJniFixture();
	~FTbSame1SameEnum1InterfaceJniFixture();

	UGameInstance* GetGameInstance();
	UTbSame1SameEnum1InterfaceJniClient* GetClient();
	TScriptInterface<ITbSame1SameEnum1InterfaceInterface> GetLocalImplementation();
	UTbSame1SameEnum1InterfaceJniAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame1SameEnum1InterfaceInterface> source;
};
} // namespace Tests
} // namespace Jni
} // namespace SameEnum1Interface
} // namespace TbSame1

#endif // WITH_DEV_AUTOMATION_TESTS
