
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbIfaceimport/Generated/api/TbIfaceimport_data.h"

class UTbIfaceimportEmptyIfMsgBusSpec;
class ITbIfaceimportEmptyIfInterface;
class UTbIfaceimportEmptyIfMsgBusAdapter;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbIfaceimport
{
namespace EmptyIf
{
namespace MsgBus
{
namespace Tests
{
class FTbIfaceimportEmptyIfMsgBusFixture
{
public:
	FTbIfaceimportEmptyIfMsgBusFixture();
	~FTbIfaceimportEmptyIfMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbIfaceimportEmptyIfInterface> GetImplementation();
	UTbIfaceimportEmptyIfMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbIfaceimportEmptyIfInterface> testImplementation;
};
} // namespace Tests
} // namespace MsgBus
} // namespace EmptyIf
} // namespace TbIfaceimport

#endif // WITH_DEV_AUTOMATION_TESTS
