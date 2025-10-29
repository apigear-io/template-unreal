/**// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT*/
#include "Testbed1StructInterfaceJniFixture.h"
#include "Misc/AutomationTest.h"


#if WITH_DEV_AUTOMATION_TESTS

#include "Testbed1/Generated/Jni/Testbed1StructInterfaceJniClient.h"
#include "Testbed1/Generated/Jni/Testbed1StructInterfaceJniAdapter.h"
#include "Testbed1/Implementation/Testbed1StructInterface.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed1
{
namespace StructInterface
{
namespace Jni
{
namespace Tests
{
FTestbed1StructInterfaceJniFixture::FTestbed1StructInterfaceJniFixture()
{
	source = GetGameInstance()->GetSubsystem<UTestbed1StructInterfaceImplementation>();
}

FTestbed1StructInterfaceJniFixture::~FTestbed1StructInterfaceJniFixture()
{
	CleanUp();
}

UTestbed1StructInterfaceJniClient* FTestbed1StructInterfaceJniFixture::GetClient()
{
	return GetGameInstance()->GetSubsystem<UTestbed1StructInterfaceJniClient>();
}

TScriptInterface<ITestbed1StructInterfaceInterface> FTestbed1StructInterfaceJniFixture::GetLocalImplementation()
{
	return source;
}

UTestbed1StructInterfaceJniAdapter* FTestbed1StructInterfaceJniFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed1StructInterfaceJniAdapter>();
}

UGameInstance* FTestbed1StructInterfaceJniFixture::GetGameInstance()
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

void FTestbed1StructInterfaceJniFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace Jni
} // namespace StructInterface
} // namespace Testbed1
#endif // WITH_DEV_AUTOMATION_TESTS
