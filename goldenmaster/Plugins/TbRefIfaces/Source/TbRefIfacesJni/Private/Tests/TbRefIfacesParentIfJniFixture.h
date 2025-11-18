
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbRefIfaces/Generated/api/TbRefIfaces_data.h"

class UTbRefIfacesParentIfJniSpec;
class ITbRefIfacesParentIfInterface;
class UTbRefIfacesParentIfJniAdapter;
class UTbRefIfacesParentIfJniClient;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbRefIfaces
{
namespace ParentIf
{
namespace Jni
{
namespace Tests
{
class FTbRefIfacesParentIfJniFixture
{
public:
	FTbRefIfacesParentIfJniFixture();
	~FTbRefIfacesParentIfJniFixture();

	UGameInstance* GetGameInstance();
	UTbRefIfacesParentIfJniClient* GetClient();
	TScriptInterface<ITbRefIfacesParentIfInterface> GetLocalImplementation();
	UTbRefIfacesParentIfJniAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbRefIfacesParentIfInterface> source;
};
} // namespace Tests
} // namespace Jni
} // namespace ParentIf
} // namespace TbRefIfaces

#endif // WITH_DEV_AUTOMATION_TESTS
