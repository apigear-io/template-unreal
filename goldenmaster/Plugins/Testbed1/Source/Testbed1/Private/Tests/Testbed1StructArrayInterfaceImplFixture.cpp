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
#include "Testbed1StructArrayInterfaceImplFixture.h"
#include "Testbed1StructArrayInterfaceImpl.spec.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

void UTestbed1StructArrayInterfaceImplHelper::SetSpec(UTestbed1StructArrayInterfaceImplSpec* InSpec)
{
	Spec = InSpec;
}

void UTestbed1StructArrayInterfaceImplHelper::SigBoolSignalCb(const TArray<FTestbed1StructBool>& ParamBool)
{
	Spec->SigBoolSignalCb(ParamBool);
}

void UTestbed1StructArrayInterfaceImplHelper::SigIntSignalCb(const TArray<FTestbed1StructInt>& ParamInt)
{
	Spec->SigIntSignalCb(ParamInt);
}

void UTestbed1StructArrayInterfaceImplHelper::SigFloatSignalCb(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	Spec->SigFloatSignalCb(ParamFloat);
}

void UTestbed1StructArrayInterfaceImplHelper::SigStringSignalCb(const TArray<FTestbed1StructString>& ParamString)
{
	Spec->SigStringSignalCb(ParamString);
}

#if WITH_DEV_AUTOMATION_TESTS

FTestbed1StructArrayInterfaceImplFixture::FTestbed1StructArrayInterfaceImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed1StructArrayInterface>();
	Helper = NewObject<UTestbed1StructArrayInterfaceImplHelper>();
}

FTestbed1StructArrayInterfaceImplFixture::~FTestbed1StructArrayInterfaceImplFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed1StructArrayInterfaceInterface> FTestbed1StructArrayInterfaceImplFixture::GetImplementation()
{
	return testImplementation;
}

TWeakObjectPtr<UTestbed1StructArrayInterfaceImplHelper> FTestbed1StructArrayInterfaceImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTestbed1StructArrayInterfaceImplFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTestbed1StructArrayInterfaceImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}

#endif // WITH_DEV_AUTOMATION_TESTS