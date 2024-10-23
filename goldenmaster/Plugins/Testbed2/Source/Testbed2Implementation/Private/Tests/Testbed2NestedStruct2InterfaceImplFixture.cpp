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
#include "Testbed2NestedStruct2InterfaceImplFixture.h"
#include "Testbed2NestedStruct2InterfaceImpl.spec.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTestbed2NestedStruct2InterfaceImplHelper::SetSpec(UTestbed2NestedStruct2InterfaceImplSpec* InSpec)
{
	Spec = InSpec;
}

void UTestbed2NestedStruct2InterfaceImplHelper::Prop1PropertyCb(const FTestbed2NestedStruct1& Prop1)
{
	Spec->Prop1PropertyCb(Prop1);
}

void UTestbed2NestedStruct2InterfaceImplHelper::Prop2PropertyCb(const FTestbed2NestedStruct2& Prop2)
{
	Spec->Prop2PropertyCb(Prop2);
}

void UTestbed2NestedStruct2InterfaceImplHelper::Sig1SignalCb(const FTestbed2NestedStruct1& Param1)
{
	Spec->Sig1SignalCb(Param1);
}

void UTestbed2NestedStruct2InterfaceImplHelper::Sig2SignalCb(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	Spec->Sig2SignalCb(Param1, Param2);
}

FTestbed2NestedStruct2InterfaceImplFixture::FTestbed2NestedStruct2InterfaceImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed2NestedStruct2Interface>();
	Helper = NewObject<UTestbed2NestedStruct2InterfaceImplHelper>();
}

FTestbed2NestedStruct2InterfaceImplFixture::~FTestbed2NestedStruct2InterfaceImplFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> FTestbed2NestedStruct2InterfaceImplFixture::GetImplementation()
{
	return testImplementation;
}

TWeakObjectPtr<UTestbed2NestedStruct2InterfaceImplHelper> FTestbed2NestedStruct2InterfaceImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTestbed2NestedStruct2InterfaceImplFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTestbed2NestedStruct2InterfaceImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTestbed2NestedStruct2InterfaceImplHelper::SetSpec(UTestbed2NestedStruct2InterfaceImplSpec* /* InSpec */)
{
}

void UTestbed2NestedStruct2InterfaceImplHelper::Prop1PropertyCb(const FTestbed2NestedStruct1& Prop1)
{
	(void)Prop1;
}

void UTestbed2NestedStruct2InterfaceImplHelper::Prop2PropertyCb(const FTestbed2NestedStruct2& Prop2)
{
	(void)Prop2;
}

void UTestbed2NestedStruct2InterfaceImplHelper::Sig1SignalCb(const FTestbed2NestedStruct1& Param1)
{
	(void)Param1;
}

void UTestbed2NestedStruct2InterfaceImplHelper::Sig2SignalCb(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	(void)Param1;
	(void)Param2;
}
#endif // WITH_DEV_AUTOMATION_TESTS
