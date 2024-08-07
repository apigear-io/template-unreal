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
#include "Testbed2NestedStruct3InterfaceImplFixture.h"
#include "Testbed2NestedStruct3InterfaceImpl.spec.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

void UTestbed2NestedStruct3InterfaceImplHelper::SetSpec(UTestbed2NestedStruct3InterfaceImplSpec* InSpec)
{
	Spec = InSpec;
}

void UTestbed2NestedStruct3InterfaceImplHelper::Prop1PropertyCb(const FTestbed2NestedStruct1& Prop1)
{
	Spec->Prop1PropertyCb(Prop1);
}

void UTestbed2NestedStruct3InterfaceImplHelper::Prop2PropertyCb(const FTestbed2NestedStruct2& Prop2)
{
	Spec->Prop2PropertyCb(Prop2);
}

void UTestbed2NestedStruct3InterfaceImplHelper::Prop3PropertyCb(const FTestbed2NestedStruct3& Prop3)
{
	Spec->Prop3PropertyCb(Prop3);
}

void UTestbed2NestedStruct3InterfaceImplHelper::Sig1SignalCb(const FTestbed2NestedStruct1& Param1)
{
	Spec->Sig1SignalCb(Param1);
}

void UTestbed2NestedStruct3InterfaceImplHelper::Sig2SignalCb(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	Spec->Sig2SignalCb(Param1, Param2);
}

void UTestbed2NestedStruct3InterfaceImplHelper::Sig3SignalCb(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3)
{
	Spec->Sig3SignalCb(Param1, Param2, Param3);
}

#if WITH_DEV_AUTOMATION_TESTS

FTestbed2NestedStruct3InterfaceImplFixture::FTestbed2NestedStruct3InterfaceImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed2NestedStruct3Interface>();
	Helper = NewObject<UTestbed2NestedStruct3InterfaceImplHelper>();
}

FTestbed2NestedStruct3InterfaceImplFixture::~FTestbed2NestedStruct3InterfaceImplFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> FTestbed2NestedStruct3InterfaceImplFixture::GetImplementation()
{
	return testImplementation;
}

TWeakObjectPtr<UTestbed2NestedStruct3InterfaceImplHelper> FTestbed2NestedStruct3InterfaceImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTestbed2NestedStruct3InterfaceImplFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTestbed2NestedStruct3InterfaceImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}

#endif // WITH_DEV_AUTOMATION_TESTS