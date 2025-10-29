/**// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT*/
#include "Testbed1StructArray2InterfaceJniFixture.h"
#include "Misc/AutomationTest.h"


#if WITH_DEV_AUTOMATION_TESTS

#include "Testbed1/Generated/Jni/Testbed1StructArray2InterfaceJniClient.h"
#include "Testbed1/Generated/Jni/Testbed1StructArray2InterfaceJniAdapter.h"
#include "Testbed1/Implementation/Testbed1StructArray2Interface.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed1
{
namespace StructArray2Interface
{
namespace Jni
{
namespace Tests
{
FTestbed1StructArray2InterfaceJniFixture::FTestbed1StructArray2InterfaceJniFixture()
{
	source = GetGameInstance()->GetSubsystem<UTestbed1StructArray2InterfaceImplementation>();
}

FTestbed1StructArray2InterfaceJniFixture::~FTestbed1StructArray2InterfaceJniFixture()
{
	CleanUp();
}

UTestbed1StructArray2InterfaceJniClient* FTestbed1StructArray2InterfaceJniFixture::GetClient()
{
	return GetGameInstance()->GetSubsystem<UTestbed1StructArray2InterfaceJniClient>();
}

TScriptInterface<ITestbed1StructArray2InterfaceInterface> FTestbed1StructArray2InterfaceJniFixture::GetLocalImplementation()
{
	return source;
}

UTestbed1StructArray2InterfaceJniAdapter* FTestbed1StructArray2InterfaceJniFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed1StructArray2InterfaceJniAdapter>();
}

UGameInstance* FTestbed1StructArray2InterfaceJniFixture::GetGameInstance()
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

void FTestbed1StructArray2InterfaceJniFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace Jni
} // namespace StructArray2Interface
} // namespace Testbed1
#endif // WITH_DEV_AUTOMATION_TESTS
