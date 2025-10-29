
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSame1/Generated/api/TbSame1_data.h"

class UTbSame1SameStruct1InterfaceJniSpec;
class ITbSame1SameStruct1InterfaceInterface;
class UTbSame1SameStruct1InterfaceJniAdapter;
class UTbSame1SameStruct1InterfaceJniClient;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame1
{
namespace SameStruct1Interface
{
namespace Jni
{
namespace Tests
{
class FTbSame1SameStruct1InterfaceJniFixture
{
public:
	FTbSame1SameStruct1InterfaceJniFixture();
	~FTbSame1SameStruct1InterfaceJniFixture();

	UGameInstance* GetGameInstance();
	UTbSame1SameStruct1InterfaceJniClient* GetClient();
	TScriptInterface<ITbSame1SameStruct1InterfaceInterface> GetLocalImplementation();
	UTbSame1SameStruct1InterfaceJniAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame1SameStruct1InterfaceInterface> source;
};
} // namespace Tests
} // namespace Jni
} // namespace SameStruct1Interface
} // namespace TbSame1

#endif // WITH_DEV_AUTOMATION_TESTS
