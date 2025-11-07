/**// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT*/
#include "TbSimpleSimpleInterfaceJniFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "TbSimple/Generated/Jni/TbSimpleSimpleInterfaceJniClient.h"
#include "TbSimple/Generated/Jni/TbSimpleSimpleInterfaceJniAdapter.h"
#include "TbSimple/Implementation/TbSimpleSimpleInterface.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace SimpleInterface
{
namespace Jni
{
namespace Tests
{
FTbSimpleSimpleInterfaceJniFixture::FTbSimpleSimpleInterfaceJniFixture()
{
	source = GetGameInstance()->GetSubsystem<UTbSimpleSimpleInterfaceImplementation>();
}

FTbSimpleSimpleInterfaceJniFixture::~FTbSimpleSimpleInterfaceJniFixture()
{
	CleanUp();
}

UTbSimpleSimpleInterfaceJniClient* FTbSimpleSimpleInterfaceJniFixture::GetClient()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleSimpleInterfaceJniClient>();
}

TScriptInterface<ITbSimpleSimpleInterfaceInterface> FTbSimpleSimpleInterfaceJniFixture::GetLocalImplementation()
{
	return source;
}

UTbSimpleSimpleInterfaceJniAdapter* FTbSimpleSimpleInterfaceJniFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleSimpleInterfaceJniAdapter>();
}

UGameInstance* FTbSimpleSimpleInterfaceJniFixture::GetGameInstance()
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

void FTbSimpleSimpleInterfaceJniFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace Jni
} // namespace SimpleInterface
} // namespace TbSimple
#endif // WITH_DEV_AUTOMATION_TESTS
