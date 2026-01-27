
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbIfaceimport/Generated/api/TbIfaceimport_data.h"

class UTbIfaceimportEmptyIfJniSpec;
class ITbIfaceimportEmptyIfInterface;
class UTbIfaceimportEmptyIfJniAdapter;
class UTbIfaceimportEmptyIfJniClient;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbIfaceimport
{
namespace EmptyIf
{
namespace Jni
{
namespace Tests
{
class FTbIfaceimportEmptyIfJniFixture
{
public:
	FTbIfaceimportEmptyIfJniFixture();
	~FTbIfaceimportEmptyIfJniFixture();

	UGameInstance* GetGameInstance();
	UTbIfaceimportEmptyIfJniClient* GetClient();
	TScriptInterface<ITbIfaceimportEmptyIfInterface> GetLocalImplementation();
	UTbIfaceimportEmptyIfJniAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbIfaceimportEmptyIfInterface> source;
};
} // namespace Tests
} // namespace Jni
} // namespace EmptyIf
} // namespace TbIfaceimport

#endif // WITH_DEV_AUTOMATION_TESTS
