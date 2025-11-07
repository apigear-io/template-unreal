/**// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT*/
#include "TbSimpleNoPropertiesInterfaceJniFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "TbSimple/Generated/Jni/TbSimpleNoPropertiesInterfaceJniClient.h"
#include "TbSimple/Generated/Jni/TbSimpleNoPropertiesInterfaceJniAdapter.h"
#include "TbSimple/Implementation/TbSimpleNoPropertiesInterface.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace NoPropertiesInterface
{
namespace Jni
{
namespace Tests
{
FTbSimpleNoPropertiesInterfaceJniFixture::FTbSimpleNoPropertiesInterfaceJniFixture()
{
	source = GetGameInstance()->GetSubsystem<UTbSimpleNoPropertiesInterfaceImplementation>();
}

FTbSimpleNoPropertiesInterfaceJniFixture::~FTbSimpleNoPropertiesInterfaceJniFixture()
{
	CleanUp();
}

UTbSimpleNoPropertiesInterfaceJniClient* FTbSimpleNoPropertiesInterfaceJniFixture::GetClient()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleNoPropertiesInterfaceJniClient>();
}

TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> FTbSimpleNoPropertiesInterfaceJniFixture::GetLocalImplementation()
{
	return source;
}

UTbSimpleNoPropertiesInterfaceJniAdapter* FTbSimpleNoPropertiesInterfaceJniFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSimpleNoPropertiesInterfaceJniAdapter>();
}

UGameInstance* FTbSimpleNoPropertiesInterfaceJniFixture::GetGameInstance()
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

void FTbSimpleNoPropertiesInterfaceJniFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace Jni
} // namespace NoPropertiesInterface
} // namespace TbSimple
#endif // WITH_DEV_AUTOMATION_TESTS
