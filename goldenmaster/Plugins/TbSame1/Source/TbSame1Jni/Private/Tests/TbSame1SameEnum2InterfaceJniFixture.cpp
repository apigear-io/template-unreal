/**// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT*/
#include "TbSame1SameEnum2InterfaceJniFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "TbSame1/Generated/Jni/TbSame1SameEnum2InterfaceJniClient.h"
#include "TbSame1/Generated/Jni/TbSame1SameEnum2InterfaceJniAdapter.h"
#include "TbSame1/Implementation/TbSame1SameEnum2Interface.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame1
{
namespace SameEnum2Interface
{
namespace Jni
{
namespace Tests
{
FTbSame1SameEnum2InterfaceJniFixture::FTbSame1SameEnum2InterfaceJniFixture()
{
	source = GetGameInstance()->GetSubsystem<UTbSame1SameEnum2InterfaceImplementation>();
}

FTbSame1SameEnum2InterfaceJniFixture::~FTbSame1SameEnum2InterfaceJniFixture()
{
	CleanUp();
}

UTbSame1SameEnum2InterfaceJniClient* FTbSame1SameEnum2InterfaceJniFixture::GetClient()
{
	return GetGameInstance()->GetSubsystem<UTbSame1SameEnum2InterfaceJniClient>();
}

TScriptInterface<ITbSame1SameEnum2InterfaceInterface> FTbSame1SameEnum2InterfaceJniFixture::GetLocalImplementation()
{
	return source;
}

UTbSame1SameEnum2InterfaceJniAdapter* FTbSame1SameEnum2InterfaceJniFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame1SameEnum2InterfaceJniAdapter>();
}

UGameInstance* FTbSame1SameEnum2InterfaceJniFixture::GetGameInstance()
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

void FTbSame1SameEnum2InterfaceJniFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace Jni
} // namespace SameEnum2Interface
} // namespace TbSame1
#endif // WITH_DEV_AUTOMATION_TESTS
