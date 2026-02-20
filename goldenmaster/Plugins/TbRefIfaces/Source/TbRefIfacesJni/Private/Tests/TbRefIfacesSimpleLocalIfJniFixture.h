
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbRefIfaces/Generated/api/TbRefIfaces_data.h"

class UTbRefIfacesSimpleLocalIfJniSpec;
class ITbRefIfacesSimpleLocalIfInterface;
class UTbRefIfacesSimpleLocalIfJniAdapter;
class UTbRefIfacesSimpleLocalIfJniClient;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbRefIfaces
{
namespace SimpleLocalIf
{
namespace Jni
{
namespace Tests
{
class FTbRefIfacesSimpleLocalIfJniFixture
{
public:
	FTbRefIfacesSimpleLocalIfJniFixture();
	~FTbRefIfacesSimpleLocalIfJniFixture();

	UGameInstance* GetGameInstance();
	UTbRefIfacesSimpleLocalIfJniClient* GetClient();
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> GetLocalImplementation();
	UTbRefIfacesSimpleLocalIfJniAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> source;
};
} // namespace Tests
} // namespace Jni
} // namespace SimpleLocalIf
} // namespace TbRefIfaces

#endif // WITH_DEV_AUTOMATION_TESTS
