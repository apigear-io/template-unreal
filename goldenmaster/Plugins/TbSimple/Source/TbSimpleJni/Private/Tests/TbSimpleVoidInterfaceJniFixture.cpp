/**// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT*/
#include "TbSimpleVoidInterfaceJniFixture.h"
#include "Misc/AutomationTest.h"


#if WITH_DEV_AUTOMATION_TESTS

#include "TbSimple/Generated/Jni/TbSimpleVoidInterfaceJniClient.h"
#include "TbSimple/Generated/Jni/TbSimpleVoidInterfaceJniAdapter.h"
#include "TbSimple/Implementation/TbSimpleVoidInterface.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace VoidInterface
{
namespace Jni
{
namespace Tests
{
FTbSimpleVoidInterfaceJniFixture::FTbSimpleVoidInterfaceJniFixture()
{
	source = GetGameInstance()->GetSubsystem<UTbSimpleVoidInterfaceImplementation>();
}

FTbSimpleVoidInterfaceJniFixture::~FTbSimpleVoidInterfaceJniFixture()
{
	CleanUp();
}

UTbSimpleVoidInterfaceJniClient* FTbSimpleVoidInterfaceJniFixture::GetClient()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleVoidInterfaceJniClient>();
}

TScriptInterface<ITbSimpleVoidInterfaceInterface> FTbSimpleVoidInterfaceJniFixture::GetLocalImplementation()
{
	return source;
}

UTbSimpleVoidInterfaceJniAdapter* FTbSimpleVoidInterfaceJniFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleVoidInterfaceJniAdapter>();
}

UGameInstance* FTbSimpleVoidInterfaceJniFixture::GetGameInstance()
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

void FTbSimpleVoidInterfaceJniFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace Jni
} // namespace VoidInterface
} // namespace TbSimple
#endif // WITH_DEV_AUTOMATION_TESTS
