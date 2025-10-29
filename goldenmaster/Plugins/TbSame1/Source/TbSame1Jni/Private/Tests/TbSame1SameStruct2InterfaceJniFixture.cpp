/**// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT*/
#include "TbSame1SameStruct2InterfaceJniFixture.h"
#include "Misc/AutomationTest.h"


#if WITH_DEV_AUTOMATION_TESTS

#include "TbSame1/Generated/Jni/TbSame1SameStruct2InterfaceJniClient.h"
#include "TbSame1/Generated/Jni/TbSame1SameStruct2InterfaceJniAdapter.h"
#include "TbSame1/Implementation/TbSame1SameStruct2Interface.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame1
{
namespace SameStruct2Interface
{
namespace Jni
{
namespace Tests
{
FTbSame1SameStruct2InterfaceJniFixture::FTbSame1SameStruct2InterfaceJniFixture()
{
	source = GetGameInstance()->GetSubsystem<UTbSame1SameStruct2InterfaceImplementation>();
}

FTbSame1SameStruct2InterfaceJniFixture::~FTbSame1SameStruct2InterfaceJniFixture()
{
	CleanUp();
}

UTbSame1SameStruct2InterfaceJniClient* FTbSame1SameStruct2InterfaceJniFixture::GetClient()
{
	return GetGameInstance()->GetSubsystem<UTbSame1SameStruct2InterfaceJniClient>();
}

TScriptInterface<ITbSame1SameStruct2InterfaceInterface> FTbSame1SameStruct2InterfaceJniFixture::GetLocalImplementation()
{
	return source;
}

UTbSame1SameStruct2InterfaceJniAdapter* FTbSame1SameStruct2InterfaceJniFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTbSame1SameStruct2InterfaceJniAdapter>();
}

UGameInstance* FTbSame1SameStruct2InterfaceJniFixture::GetGameInstance()
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

void FTbSame1SameStruct2InterfaceJniFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace Jni
} // namespace SameStruct2Interface
} // namespace TbSame1
#endif // WITH_DEV_AUTOMATION_TESTS
