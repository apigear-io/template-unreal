
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSame2/Generated/api/TbSame2_data.h"

class UTbSame2SameStruct1InterfaceJniSpec;
class ITbSame2SameStruct1InterfaceInterface;
class UTbSame2SameStruct1InterfaceJniAdapter;
class UTbSame2SameStruct1InterfaceJniClient;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame2
{
namespace SameStruct1Interface
{
namespace Jni
{
namespace Tests
{
class FTbSame2SameStruct1InterfaceJniFixture
{
public:
	FTbSame2SameStruct1InterfaceJniFixture();
	~FTbSame2SameStruct1InterfaceJniFixture();

	UGameInstance* GetGameInstance();
	UTbSame2SameStruct1InterfaceJniClient* GetClient();
	TScriptInterface<ITbSame2SameStruct1InterfaceInterface> GetLocalImplementation();
	UTbSame2SameStruct1InterfaceJniAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame2SameStruct1InterfaceInterface> source;
};
} // namespace Tests
} // namespace Jni
} // namespace SameStruct1Interface
} // namespace TbSame2

#endif // WITH_DEV_AUTOMATION_TESTS
