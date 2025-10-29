/**// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT*/
#include "TbNamesNamEsJniFixture.h"
#include "Misc/AutomationTest.h"


#if WITH_DEV_AUTOMATION_TESTS

#include "TbNames/Generated/Jni/TbNamesNamEsJniClient.h"
#include "TbNames/Generated/Jni/TbNamesNamEsJniAdapter.h"
#include "TbNames/Implementation/TbNamesNamEs.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbNames
{
namespace NamEs
{
namespace Jni
{
namespace Tests
{
FTbNamesNamEsJniFixture::FTbNamesNamEsJniFixture()
{
	source = GetGameInstance()->GetSubsystem<UTbNamesNamEsImplementation>();
}

FTbNamesNamEsJniFixture::~FTbNamesNamEsJniFixture()
{
	CleanUp();
}

UTbNamesNamEsJniClient* FTbNamesNamEsJniFixture::GetClient()
{
	return GetGameInstance()->GetSubsystem<UTbNamesNamEsJniClient>();
}

TScriptInterface<ITbNamesNamEsInterface> FTbNamesNamEsJniFixture::GetLocalImplementation()
{
	return source;
}

UTbNamesNamEsJniAdapter* FTbNamesNamEsJniFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbNamesNamEsJniAdapter>();
}

UGameInstance* FTbNamesNamEsJniFixture::GetGameInstance()
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

void FTbNamesNamEsJniFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace Jni
} // namespace NamEs
} // namespace TbNames
#endif // WITH_DEV_AUTOMATION_TESTS
