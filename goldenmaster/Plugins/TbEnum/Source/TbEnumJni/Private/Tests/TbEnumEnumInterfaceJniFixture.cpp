/**// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT*/
#include "TbEnumEnumInterfaceJniFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "TbEnum/Generated/Jni/TbEnumEnumInterfaceJniClient.h"
#include "TbEnum/Generated/Jni/TbEnumEnumInterfaceJniAdapter.h"
#include "TbEnum/Implementation/TbEnumEnumInterface.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbEnum
{
namespace EnumInterface
{
namespace Jni
{
namespace Tests
{
FTbEnumEnumInterfaceJniFixture::FTbEnumEnumInterfaceJniFixture()
{
	source = GetGameInstance()->GetSubsystem<UTbEnumEnumInterfaceImplementation>();
}

FTbEnumEnumInterfaceJniFixture::~FTbEnumEnumInterfaceJniFixture()
{
	CleanUp();
}

UTbEnumEnumInterfaceJniClient* FTbEnumEnumInterfaceJniFixture::GetClient()
{
	return GetGameInstance()->GetSubsystem<UTbEnumEnumInterfaceJniClient>();
}

TScriptInterface<ITbEnumEnumInterfaceInterface> FTbEnumEnumInterfaceJniFixture::GetLocalImplementation()
{
	return source;
}

UTbEnumEnumInterfaceJniAdapter* FTbEnumEnumInterfaceJniFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbEnumEnumInterfaceJniAdapter>();
}

UGameInstance* FTbEnumEnumInterfaceJniFixture::GetGameInstance()
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

void FTbEnumEnumInterfaceJniFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace Jni
} // namespace EnumInterface
} // namespace TbEnum
#endif // WITH_DEV_AUTOMATION_TESTS
