
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbNames/Generated/api/TbNames_data.h"

class UTbNamesNamEsMsgBusSpec;
class ITbNamesNamEsInterface;
class UTbNamesNamEsMsgBusAdapter;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbNames
{
namespace NamEs
{
namespace MsgBus
{
namespace Tests
{
class FTbNamesNamEsMsgBusFixture
{
public:
	FTbNamesNamEsMsgBusFixture();
	~FTbNamesNamEsMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbNamesNamEsInterface> GetImplementation();
	UTbNamesNamEsMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbNamesNamEsInterface> testImplementation;
};
} // namespace Tests
} // namespace MsgBus
} // namespace NamEs
} // namespace TbNames

#endif // WITH_DEV_AUTOMATION_TESTS
