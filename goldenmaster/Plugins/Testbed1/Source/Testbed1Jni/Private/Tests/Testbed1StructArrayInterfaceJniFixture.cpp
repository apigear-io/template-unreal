/**// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT*/
#include "Testbed1StructArrayInterfaceJniFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "Testbed1/Generated/Jni/Testbed1StructArrayInterfaceJniClient.h"
#include "Testbed1/Generated/Jni/Testbed1StructArrayInterfaceJniAdapter.h"
#include "Testbed1/Implementation/Testbed1StructArrayInterface.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed1
{
namespace StructArrayInterface
{
namespace Jni
{
namespace Tests
{
FTestbed1StructArrayInterfaceJniFixture::FTestbed1StructArrayInterfaceJniFixture()
{
	source = GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceImplementation>();
}

FTestbed1StructArrayInterfaceJniFixture::~FTestbed1StructArrayInterfaceJniFixture()
{
	CleanUp();
}

UTestbed1StructArrayInterfaceJniClient* FTestbed1StructArrayInterfaceJniFixture::GetClient()
{
	return GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceJniClient>();
}

TScriptInterface<ITestbed1StructArrayInterfaceInterface> FTestbed1StructArrayInterfaceJniFixture::GetLocalImplementation()
{
	return source;
}

UTestbed1StructArrayInterfaceJniAdapter* FTestbed1StructArrayInterfaceJniFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterfaceJniAdapter>();
}

UGameInstance* FTestbed1StructArrayInterfaceJniFixture::GetGameInstance()
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

void FTestbed1StructArrayInterfaceJniFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace Jni
} // namespace StructArrayInterface
} // namespace Testbed1
#endif // WITH_DEV_AUTOMATION_TESTS
