/**// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT*/
#include "TbSimpleSimpleArrayInterfaceJniFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "TbSimple/Generated/Jni/TbSimpleSimpleArrayInterfaceJniClient.h"
#include "TbSimple/Generated/Jni/TbSimpleSimpleArrayInterfaceJniAdapter.h"
#include "TbSimple/Implementation/TbSimpleSimpleArrayInterface.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace SimpleArrayInterface
{
namespace Jni
{
namespace Tests
{
FTbSimpleSimpleArrayInterfaceJniFixture::FTbSimpleSimpleArrayInterfaceJniFixture()
{
	source = GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterfaceImplementation>();
}

FTbSimpleSimpleArrayInterfaceJniFixture::~FTbSimpleSimpleArrayInterfaceJniFixture()
{
	CleanUp();
}

UTbSimpleSimpleArrayInterfaceJniClient* FTbSimpleSimpleArrayInterfaceJniFixture::GetClient()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterfaceJniClient>();
}

TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> FTbSimpleSimpleArrayInterfaceJniFixture::GetLocalImplementation()
{
	return source;
}

UTbSimpleSimpleArrayInterfaceJniAdapter* FTbSimpleSimpleArrayInterfaceJniFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterfaceJniAdapter>();
}

UGameInstance* FTbSimpleSimpleArrayInterfaceJniFixture::GetGameInstance()
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

void FTbSimpleSimpleArrayInterfaceJniFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace Jni
} // namespace SimpleArrayInterface
} // namespace TbSimple
#endif // WITH_DEV_AUTOMATION_TESTS
