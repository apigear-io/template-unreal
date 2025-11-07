/**// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT*/
#include "TbIfaceimportEmptyIfJniFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "TbIfaceimport/Generated/Jni/TbIfaceimportEmptyIfJniClient.h"
#include "TbIfaceimport/Generated/Jni/TbIfaceimportEmptyIfJniAdapter.h"
#include "TbIfaceimport/Implementation/TbIfaceimportEmptyIf.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbIfaceimport
{
namespace EmptyIf
{
namespace Jni
{
namespace Tests
{
FTbIfaceimportEmptyIfJniFixture::FTbIfaceimportEmptyIfJniFixture()
{
	source = GetGameInstance()->GetSubsystem<UTbIfaceimportEmptyIfImplementation>();
}

FTbIfaceimportEmptyIfJniFixture::~FTbIfaceimportEmptyIfJniFixture()
{
	CleanUp();
}

UTbIfaceimportEmptyIfJniClient* FTbIfaceimportEmptyIfJniFixture::GetClient()
{
	return GetGameInstance()->GetSubsystem<UTbIfaceimportEmptyIfJniClient>();
}

TScriptInterface<ITbIfaceimportEmptyIfInterface> FTbIfaceimportEmptyIfJniFixture::GetLocalImplementation()
{
	return source;
}

UTbIfaceimportEmptyIfJniAdapter* FTbIfaceimportEmptyIfJniFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbIfaceimportEmptyIfJniAdapter>();
}

UGameInstance* FTbIfaceimportEmptyIfJniFixture::GetGameInstance()
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

void FTbIfaceimportEmptyIfJniFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace Jni
} // namespace EmptyIf
} // namespace TbIfaceimport
#endif // WITH_DEV_AUTOMATION_TESTS
