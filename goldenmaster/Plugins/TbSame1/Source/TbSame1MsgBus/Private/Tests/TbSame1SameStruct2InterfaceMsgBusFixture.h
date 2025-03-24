
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSame1/Generated/api/TbSame1_data.h"

class UTbSame1SameStruct2InterfaceMsgBusSpec;
class ITbSame1SameStruct2InterfaceInterface;
class UTbSame1SameStruct2InterfaceMsgBusAdapter;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame1
{
namespace SameStruct2Interface
{
namespace MsgBus
{
namespace Tests
{
class FTbSame1SameStruct2InterfaceMsgBusFixture
{
public:
	FTbSame1SameStruct2InterfaceMsgBusFixture();
	~FTbSame1SameStruct2InterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame1SameStruct2InterfaceInterface> GetImplementation();
	UTbSame1SameStruct2InterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame1SameStruct2InterfaceInterface> testImplementation;
};
} // namespace Tests
} // namespace MsgBus
} // namespace SameStruct2Interface
} // namespace TbSame1

#endif // WITH_DEV_AUTOMATION_TESTS
