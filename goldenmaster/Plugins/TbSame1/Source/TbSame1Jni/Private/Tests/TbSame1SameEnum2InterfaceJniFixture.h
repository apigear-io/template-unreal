
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSame1/Generated/api/TbSame1_data.h"

class UTbSame1SameEnum2InterfaceJniSpec;
class ITbSame1SameEnum2InterfaceInterface;
class UTbSame1SameEnum2InterfaceJniAdapter;
class UTbSame1SameEnum2InterfaceJniClient;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame1
{
namespace SameEnum2Interface
{
namespace Jni
{
namespace Tests
{
class FTbSame1SameEnum2InterfaceJniFixture
{
public:
	FTbSame1SameEnum2InterfaceJniFixture();
	~FTbSame1SameEnum2InterfaceJniFixture();

	UGameInstance* GetGameInstance();
	UTbSame1SameEnum2InterfaceJniClient* GetClient();
	TScriptInterface<ITbSame1SameEnum2InterfaceInterface> GetLocalImplementation();
	UTbSame1SameEnum2InterfaceJniAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame1SameEnum2InterfaceInterface> source;
};
} // namespace Tests
} // namespace Jni
} // namespace SameEnum2Interface
} // namespace TbSame1

#endif // WITH_DEV_AUTOMATION_TESTS
