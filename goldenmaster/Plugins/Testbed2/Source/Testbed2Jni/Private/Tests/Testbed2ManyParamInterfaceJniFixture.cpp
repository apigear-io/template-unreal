/**// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT*/
#include "Testbed2ManyParamInterfaceJniFixture.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

#include "Testbed2/Generated/Jni/Testbed2ManyParamInterfaceJniClient.h"
#include "Testbed2/Generated/Jni/Testbed2ManyParamInterfaceJniAdapter.h"
#include "Testbed2/Implementation/Testbed2ManyParamInterface.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed2
{
namespace ManyParamInterface
{
namespace Jni
{
namespace Tests
{
FTestbed2ManyParamInterfaceJniFixture::FTestbed2ManyParamInterfaceJniFixture()
{
	source = GetGameInstance()->GetSubsystem<UTestbed2ManyParamInterfaceImplementation>();
}

FTestbed2ManyParamInterfaceJniFixture::~FTestbed2ManyParamInterfaceJniFixture()
{
	CleanUp();
}

UTestbed2ManyParamInterfaceJniClient* FTestbed2ManyParamInterfaceJniFixture::GetClient()
{
	return GetGameInstance()->GetSubsystem<UTestbed2ManyParamInterfaceJniClient>();
}

TScriptInterface<ITestbed2ManyParamInterfaceInterface> FTestbed2ManyParamInterfaceJniFixture::GetLocalImplementation()
{
	return source;
}

UTestbed2ManyParamInterfaceJniAdapter* FTestbed2ManyParamInterfaceJniFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed2ManyParamInterfaceJniAdapter>();
}

UGameInstance* FTestbed2ManyParamInterfaceJniFixture::GetGameInstance()
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

void FTestbed2ManyParamInterfaceJniFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace Jni
} // namespace ManyParamInterface
} // namespace Testbed2
#endif // WITH_DEV_AUTOMATION_TESTS
