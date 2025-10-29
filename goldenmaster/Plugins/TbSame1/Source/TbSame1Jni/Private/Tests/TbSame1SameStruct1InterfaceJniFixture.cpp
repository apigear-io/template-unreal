/**// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT*/
#include "TbSame1SameStruct1InterfaceJniFixture.h"
#include "Misc/AutomationTest.h"


#if WITH_DEV_AUTOMATION_TESTS

#include "TbSame1/Generated/Jni/TbSame1SameStruct1InterfaceJniClient.h"
#include "TbSame1/Generated/Jni/TbSame1SameStruct1InterfaceJniAdapter.h"
#include "TbSame1/Implementation/TbSame1SameStruct1Interface.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame1
{
namespace SameStruct1Interface
{
namespace Jni
{
namespace Tests
{
FTbSame1SameStruct1InterfaceJniFixture::FTbSame1SameStruct1InterfaceJniFixture()
{
	source = GetGameInstance()->GetSubsystem<UTbSame1SameStruct1InterfaceImplementation>();
}

FTbSame1SameStruct1InterfaceJniFixture::~FTbSame1SameStruct1InterfaceJniFixture()
{
	CleanUp();
}

UTbSame1SameStruct1InterfaceJniClient* FTbSame1SameStruct1InterfaceJniFixture::GetClient()
{
	return GetGameInstance()->GetSubsystem<UTbSame1SameStruct1InterfaceJniClient>();
}

TScriptInterface<ITbSame1SameStruct1InterfaceInterface> FTbSame1SameStruct1InterfaceJniFixture::GetLocalImplementation()
{
	return source;
}

UTbSame1SameStruct1InterfaceJniAdapter* FTbSame1SameStruct1InterfaceJniFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame1SameStruct1InterfaceJniAdapter>();
}

UGameInstance* FTbSame1SameStruct1InterfaceJniFixture::GetGameInstance()
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

void FTbSame1SameStruct1InterfaceJniFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace Jni
} // namespace SameStruct1Interface
} // namespace TbSame1
#endif // WITH_DEV_AUTOMATION_TESTS
