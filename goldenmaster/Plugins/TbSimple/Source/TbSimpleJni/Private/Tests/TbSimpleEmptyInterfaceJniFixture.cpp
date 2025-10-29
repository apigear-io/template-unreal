/**// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT*/
#include "TbSimpleEmptyInterfaceJniFixture.h"
#include "Misc/AutomationTest.h"


#if WITH_DEV_AUTOMATION_TESTS

#include "TbSimple/Generated/Jni/TbSimpleEmptyInterfaceJniClient.h"
#include "TbSimple/Generated/Jni/TbSimpleEmptyInterfaceJniAdapter.h"
#include "TbSimple/Implementation/TbSimpleEmptyInterface.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace EmptyInterface
{
namespace Jni
{
namespace Tests
{
FTbSimpleEmptyInterfaceJniFixture::FTbSimpleEmptyInterfaceJniFixture()
{
	source = GetGameInstance()->GetSubsystem<UTbSimpleEmptyInterfaceImplementation>();
}

FTbSimpleEmptyInterfaceJniFixture::~FTbSimpleEmptyInterfaceJniFixture()
{
	CleanUp();
}

UTbSimpleEmptyInterfaceJniClient* FTbSimpleEmptyInterfaceJniFixture::GetClient()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleEmptyInterfaceJniClient>();
}

TScriptInterface<ITbSimpleEmptyInterfaceInterface> FTbSimpleEmptyInterfaceJniFixture::GetLocalImplementation()
{
	return source;
}

UTbSimpleEmptyInterfaceJniAdapter* FTbSimpleEmptyInterfaceJniFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleEmptyInterfaceJniAdapter>();
}

UGameInstance* FTbSimpleEmptyInterfaceJniFixture::GetGameInstance()
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

void FTbSimpleEmptyInterfaceJniFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace Jni
} // namespace EmptyInterface
} // namespace TbSimple
#endif // WITH_DEV_AUTOMATION_TESTS
