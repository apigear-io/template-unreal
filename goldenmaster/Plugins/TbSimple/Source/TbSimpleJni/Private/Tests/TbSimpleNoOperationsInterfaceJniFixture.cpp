/**// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT*/
#include "TbSimpleNoOperationsInterfaceJniFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "TbSimple/Generated/Jni/TbSimpleNoOperationsInterfaceJniClient.h"
#include "TbSimple/Generated/Jni/TbSimpleNoOperationsInterfaceJniAdapter.h"
#include "TbSimple/Implementation/TbSimpleNoOperationsInterface.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace NoOperationsInterface
{
namespace Jni
{
namespace Tests
{
FTbSimpleNoOperationsInterfaceJniFixture::FTbSimpleNoOperationsInterfaceJniFixture()
{
	source = GetGameInstance()->GetSubsystem<UTbSimpleNoOperationsInterfaceImplementation>();
}

FTbSimpleNoOperationsInterfaceJniFixture::~FTbSimpleNoOperationsInterfaceJniFixture()
{
	CleanUp();
}

UTbSimpleNoOperationsInterfaceJniClient* FTbSimpleNoOperationsInterfaceJniFixture::GetClient()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleNoOperationsInterfaceJniClient>();
}

TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> FTbSimpleNoOperationsInterfaceJniFixture::GetLocalImplementation()
{
	return source;
}

UTbSimpleNoOperationsInterfaceJniAdapter* FTbSimpleNoOperationsInterfaceJniFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleNoOperationsInterfaceJniAdapter>();
}

UGameInstance* FTbSimpleNoOperationsInterfaceJniFixture::GetGameInstance()
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

void FTbSimpleNoOperationsInterfaceJniFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace Jni
} // namespace NoOperationsInterface
} // namespace TbSimple
#endif // WITH_DEV_AUTOMATION_TESTS
