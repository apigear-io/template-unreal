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
#include "Testbed2NestedStruct1InterfaceImplFixture.h"
#include "Testbed2NestedStruct1InterfaceImpl.spec.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

void UTestbed2NestedStruct1InterfaceImplHelper::SetSpec(UTestbed2NestedStruct1InterfaceImplSpec* InSpec)
{
	Spec = InSpec;
}

void UTestbed2NestedStruct1InterfaceImplHelper::Sig1SignalCb(const FTestbed2NestedStruct1& Param1)
{
	Spec->Sig1SignalCb(Param1);
}

#if WITH_DEV_AUTOMATION_TESTS

FTestbed2NestedStruct1InterfaceImplFixture::FTestbed2NestedStruct1InterfaceImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed2NestedStruct1Interface>();
	Helper = NewObject<UTestbed2NestedStruct1InterfaceImplHelper>();
}

FTestbed2NestedStruct1InterfaceImplFixture::~FTestbed2NestedStruct1InterfaceImplFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> FTestbed2NestedStruct1InterfaceImplFixture::GetImplementation()
{
	return testImplementation;
}

TWeakObjectPtr<UTestbed2NestedStruct1InterfaceImplHelper> FTestbed2NestedStruct1InterfaceImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTestbed2NestedStruct1InterfaceImplFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTestbed2NestedStruct1InterfaceImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}

#endif // WITH_DEV_AUTOMATION_TESTS