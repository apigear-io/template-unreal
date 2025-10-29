
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSame1/Generated/api/TbSame1_data.h"

class UTbSame1SameStruct2InterfaceJniSpec;
class ITbSame1SameStruct2InterfaceInterface;
class UTbSame1SameStruct2InterfaceJniAdapter;
class UTbSame1SameStruct2InterfaceJniClient;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame1
{
namespace SameStruct2Interface
{
namespace Jni
{
namespace Tests
{
class FTbSame1SameStruct2InterfaceJniFixture
{
public:
	FTbSame1SameStruct2InterfaceJniFixture();
	~FTbSame1SameStruct2InterfaceJniFixture();

	UGameInstance* GetGameInstance();
	UTbSame1SameStruct2InterfaceJniClient* GetClient();
	TScriptInterface<ITbSame1SameStruct2InterfaceInterface> GetLocalImplementation();
	UTbSame1SameStruct2InterfaceJniAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame1SameStruct2InterfaceInterface> source;
};
} // namespace Tests
} // namespace Jni
} // namespace SameStruct2Interface
} // namespace TbSame1

#endif // WITH_DEV_AUTOMATION_TESTS
