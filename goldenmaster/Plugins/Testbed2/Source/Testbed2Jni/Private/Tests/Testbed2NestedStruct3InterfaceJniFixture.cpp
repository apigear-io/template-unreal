/**
Copyright 2021 ApiGear UG
Copyright 2021 Epic Games, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#include "Testbed2NestedStruct3InterfaceJniFixture.h"
#include "Misc/AutomationTest.h"


#if WITH_DEV_AUTOMATION_TESTS

#include "Testbed2/Generated/Jni/Testbed2NestedStruct3InterfaceJniClient.h"
#include "Testbed2/Generated/Jni/Testbed2NestedStruct3InterfaceJniAdapter.h"
#include "Testbed2/Implementation/Testbed2NestedStruct3Interface.h"
#include "Engine/GameInstance.h"

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed2
{
namespace NestedStruct3Interface
{
namespace Jni
{
namespace Tests
{
FTestbed2NestedStruct3InterfaceJniFixture::FTestbed2NestedStruct3InterfaceJniFixture()
{
	source = GetGameInstance()->GetSubsystem<UTestbed2NestedStruct3InterfaceImplementation>();
}

FTestbed2NestedStruct3InterfaceJniFixture::~FTestbed2NestedStruct3InterfaceJniFixture()
{
	CleanUp();
}

UTestbed2NestedStruct3InterfaceJniClient* FTestbed2NestedStruct3InterfaceJniFixture::GetClient()
{
	return GetGameInstance()->GetSubsystem<UTestbed2NestedStruct3InterfaceJniClient>();
}

TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> FTestbed2NestedStruct3InterfaceJniFixture::GetLocalImplementation()
{
	return source;
}

UTestbed2NestedStruct3InterfaceJniAdapter* FTestbed2NestedStruct3InterfaceJniFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UTestbed2NestedStruct3InterfaceJniAdapter>();
}

UGameInstance* FTestbed2NestedStruct3InterfaceJniFixture::GetGameInstance()
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

void FTestbed2NestedStruct3InterfaceJniFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
} // namespace Tests
} // namespace Jni
} // namespace NestedStruct3Interface
} // namespace Testbed2
#endif // WITH_DEV_AUTOMATION_TESTS
