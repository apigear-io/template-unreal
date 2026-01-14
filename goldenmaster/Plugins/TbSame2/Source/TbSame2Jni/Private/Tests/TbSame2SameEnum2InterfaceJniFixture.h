
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSame2/Generated/api/TbSame2_data.h"

class UTbSame2SameEnum2InterfaceJniSpec;
class ITbSame2SameEnum2InterfaceInterface;
class UTbSame2SameEnum2InterfaceJniAdapter;
class UTbSame2SameEnum2InterfaceJniClient;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame2
{
namespace SameEnum2Interface
{
namespace Jni
{
namespace Tests
{
class FTbSame2SameEnum2InterfaceJniFixture
{
public:
	FTbSame2SameEnum2InterfaceJniFixture();
	~FTbSame2SameEnum2InterfaceJniFixture();

	UGameInstance* GetGameInstance();
	UTbSame2SameEnum2InterfaceJniClient* GetClient();
	TScriptInterface<ITbSame2SameEnum2InterfaceInterface> GetLocalImplementation();
	UTbSame2SameEnum2InterfaceJniAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame2SameEnum2InterfaceInterface> source;
};
} // namespace Tests
} // namespace Jni
} // namespace SameEnum2Interface
} // namespace TbSame2

#endif // WITH_DEV_AUTOMATION_TESTS
