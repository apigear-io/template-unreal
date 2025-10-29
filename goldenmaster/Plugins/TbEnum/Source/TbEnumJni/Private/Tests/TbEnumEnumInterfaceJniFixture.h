
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbEnum/Generated/api/TbEnum_data.h"

class UTbEnumEnumInterfaceJniSpec;
class ITbEnumEnumInterfaceInterface;
class UTbEnumEnumInterfaceJniAdapter;
class UTbEnumEnumInterfaceJniClient;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbEnum
{
namespace EnumInterface
{
namespace Jni
{
namespace Tests
{
class FTbEnumEnumInterfaceJniFixture
{
public:
	FTbEnumEnumInterfaceJniFixture();
	~FTbEnumEnumInterfaceJniFixture();

	UGameInstance* GetGameInstance();
	UTbEnumEnumInterfaceJniClient* GetClient();
	TScriptInterface<ITbEnumEnumInterfaceInterface> GetLocalImplementation();
	UTbEnumEnumInterfaceJniAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbEnumEnumInterfaceInterface> source;
};
} // namespace Tests
} // namespace Jni
} // namespace EnumInterface
} // namespace TbEnum

#endif // WITH_DEV_AUTOMATION_TESTS
