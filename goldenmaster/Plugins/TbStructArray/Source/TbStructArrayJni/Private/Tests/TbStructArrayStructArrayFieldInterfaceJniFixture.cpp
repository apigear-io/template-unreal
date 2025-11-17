/**// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT*/
#include "TbStructArrayStructArrayFieldInterfaceJniFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "TbStructArray/Generated/Jni/TbStructArrayStructArrayFieldInterfaceJniClient.h"
#include "TbStructArray/Generated/Jni/TbStructArrayStructArrayFieldInterfaceJniAdapter.h"
#include "TbStructArray/Implementation/TbStructArrayStructArrayFieldInterface.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbStructArray
{
namespace StructArrayFieldInterface
{
namespace Jni
{
namespace Tests
{
FTbStructArrayStructArrayFieldInterfaceJniFixture::FTbStructArrayStructArrayFieldInterfaceJniFixture()
{
	source = GetGameInstance()->GetSubsystem<UTbStructArrayStructArrayFieldInterfaceImplementation>();
}

FTbStructArrayStructArrayFieldInterfaceJniFixture::~FTbStructArrayStructArrayFieldInterfaceJniFixture()
{
	CleanUp();
}

UTbStructArrayStructArrayFieldInterfaceJniClient* FTbStructArrayStructArrayFieldInterfaceJniFixture::GetClient()
{
	return GetGameInstance()->GetSubsystem<UTbStructArrayStructArrayFieldInterfaceJniClient>();
}

TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface> FTbStructArrayStructArrayFieldInterfaceJniFixture::GetLocalImplementation()
{
	return source;
}

UTbStructArrayStructArrayFieldInterfaceJniAdapter* FTbStructArrayStructArrayFieldInterfaceJniFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbStructArrayStructArrayFieldInterfaceJniAdapter>();
}

UGameInstance* FTbStructArrayStructArrayFieldInterfaceJniFixture::GetGameInstance()
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

void FTbStructArrayStructArrayFieldInterfaceJniFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace Jni
} // namespace StructArrayFieldInterface
} // namespace TbStructArray
#endif // WITH_DEV_AUTOMATION_TESTS
