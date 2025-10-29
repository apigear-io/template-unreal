
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbNames/Generated/api/TbNames_data.h"

class UTbNamesNamEsJniSpec;
class ITbNamesNamEsInterface;
class UTbNamesNamEsJniAdapter;
class UTbNamesNamEsJniClient;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbNames
{
namespace NamEs
{
namespace Jni
{
namespace Tests
{
class FTbNamesNamEsJniFixture
{
public:
	FTbNamesNamEsJniFixture();
	~FTbNamesNamEsJniFixture();

	UGameInstance* GetGameInstance();
	UTbNamesNamEsJniClient* GetClient();
	TScriptInterface<ITbNamesNamEsInterface> GetLocalImplementation();
	UTbNamesNamEsJniAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbNamesNamEsInterface> source;
};
} // namespace Tests
} // namespace Jni
} // namespace NamEs
} // namespace TbNames

#endif // WITH_DEV_AUTOMATION_TESTS
