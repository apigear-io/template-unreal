// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#include "TbSimpleNoSignalsInterfaceJniFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "TbSimple/Generated/Jni/TbSimpleNoSignalsInterfaceJniClient.h"
#include "TbSimple/Generated/Jni/TbSimpleNoSignalsInterfaceJniAdapter.h"
#include "TbSimple/Implementation/TbSimpleNoSignalsInterface.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace NoSignalsInterface
{
namespace Jni
{
namespace Tests
{
FTbSimpleNoSignalsInterfaceJniFixture::FTbSimpleNoSignalsInterfaceJniFixture()
{
	source = GetGameInstance()->GetSubsystem<UTbSimpleNoSignalsInterfaceImplementation>();
}

FTbSimpleNoSignalsInterfaceJniFixture::~FTbSimpleNoSignalsInterfaceJniFixture()
{
	CleanUp();
}

UTbSimpleNoSignalsInterfaceJniClient* FTbSimpleNoSignalsInterfaceJniFixture::GetClient()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleNoSignalsInterfaceJniClient>();
}

TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> FTbSimpleNoSignalsInterfaceJniFixture::GetLocalImplementation()
{
	return source;
}

UTbSimpleNoSignalsInterfaceJniAdapter* FTbSimpleNoSignalsInterfaceJniFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleNoSignalsInterfaceJniAdapter>();
}

UGameInstance* FTbSimpleNoSignalsInterfaceJniFixture::GetGameInstance()
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

void FTbSimpleNoSignalsInterfaceJniFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace Jni
} // namespace NoSignalsInterface
} // namespace TbSimple
#endif // WITH_DEV_AUTOMATION_TESTS
