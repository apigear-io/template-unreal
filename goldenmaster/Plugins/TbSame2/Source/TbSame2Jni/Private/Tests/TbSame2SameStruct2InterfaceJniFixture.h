
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSame2/Generated/api/TbSame2_data.h"

class UTbSame2SameStruct2InterfaceJniSpec;
class ITbSame2SameStruct2InterfaceInterface;
class UTbSame2SameStruct2InterfaceJniAdapter;
class UTbSame2SameStruct2InterfaceJniClient;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame2
{
namespace SameStruct2Interface
{
namespace Jni
{
namespace Tests
{
class FTbSame2SameStruct2InterfaceJniFixture
{
public:
	FTbSame2SameStruct2InterfaceJniFixture();
	~FTbSame2SameStruct2InterfaceJniFixture();

	UGameInstance* GetGameInstance();
	UTbSame2SameStruct2InterfaceJniClient* GetClient();
	TScriptInterface<ITbSame2SameStruct2InterfaceInterface> GetLocalImplementation();
	UTbSame2SameStruct2InterfaceJniAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame2SameStruct2InterfaceInterface> source;
};
} // namespace Tests
} // namespace Jni
} // namespace SameStruct2Interface
} // namespace TbSame2

#endif // WITH_DEV_AUTOMATION_TESTS
