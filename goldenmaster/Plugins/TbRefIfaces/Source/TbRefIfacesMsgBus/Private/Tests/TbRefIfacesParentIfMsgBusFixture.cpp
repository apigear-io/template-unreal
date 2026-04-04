// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "TbRefIfacesParentIfMsgBusFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "TbRefIfaces/Generated/MsgBus/TbRefIfacesParentIfMsgBusClient.h"
#include "TbRefIfaces/Generated/MsgBus/TbRefIfacesParentIfMsgBusAdapter.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbRefIfaces
{
namespace ParentIf
{
namespace MsgBus
{
namespace Tests
{
FTbRefIfacesParentIfMsgBusFixture::FTbRefIfacesParentIfMsgBusFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbRefIfacesParentIfMsgBusClient>();
}

FTbRefIfacesParentIfMsgBusFixture::~FTbRefIfacesParentIfMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ITbRefIfacesParentIfInterface> FTbRefIfacesParentIfMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UTbRefIfacesParentIfMsgBusAdapter* FTbRefIfacesParentIfMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbRefIfacesParentIfMsgBusAdapter>();
}

UGameInstance* FTbRefIfacesParentIfMsgBusFixture::GetGameInstance()
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

void FTbRefIfacesParentIfMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace MsgBus
} // namespace ParentIf
} // namespace TbRefIfaces
#endif // WITH_DEV_AUTOMATION_TESTS
