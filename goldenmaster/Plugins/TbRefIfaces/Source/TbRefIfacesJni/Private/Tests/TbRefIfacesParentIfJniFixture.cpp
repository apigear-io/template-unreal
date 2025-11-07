/**// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT*/
#include "TbRefIfacesParentIfJniFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "TbRefIfaces/Generated/Jni/TbRefIfacesParentIfJniClient.h"
#include "TbRefIfaces/Generated/Jni/TbRefIfacesParentIfJniAdapter.h"
#include "TbRefIfaces/Implementation/TbRefIfacesParentIf.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbRefIfaces
{
namespace ParentIf
{
namespace Jni
{
namespace Tests
{
FTbRefIfacesParentIfJniFixture::FTbRefIfacesParentIfJniFixture()
{
	source = GetGameInstance()->GetSubsystem<UTbRefIfacesParentIfImplementation>();
}

FTbRefIfacesParentIfJniFixture::~FTbRefIfacesParentIfJniFixture()
{
	CleanUp();
}

UTbRefIfacesParentIfJniClient* FTbRefIfacesParentIfJniFixture::GetClient()
{
	return GetGameInstance()->GetSubsystem<UTbRefIfacesParentIfJniClient>();
}

TScriptInterface<ITbRefIfacesParentIfInterface> FTbRefIfacesParentIfJniFixture::GetLocalImplementation()
{
	return source;
}

UTbRefIfacesParentIfJniAdapter* FTbRefIfacesParentIfJniFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbRefIfacesParentIfJniAdapter>();
}

UGameInstance* FTbRefIfacesParentIfJniFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>(GetTransientPackage());
		GameInstance->Init();
		// needed to prevent garbage collection and we can't use UPROPERTY on raw c++ objects
		GameInstance->AddToRoot();
	}

	return GameInstance.Get();
}

void FTbRefIfacesParentIfJniFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace Jni
} // namespace ParentIf
} // namespace TbRefIfaces
#endif // WITH_DEV_AUTOMATION_TESTS
