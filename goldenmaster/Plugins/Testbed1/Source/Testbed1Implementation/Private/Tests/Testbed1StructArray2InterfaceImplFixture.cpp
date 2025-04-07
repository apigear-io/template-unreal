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
#include "Testbed1StructArray2InterfaceImplFixture.h"
#include "Testbed1StructArray2InterfaceImpl.spec.h"
#include "Testbed1/Implementation/Testbed1StructArray2Interface.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTestbed1StructArray2InterfaceImplHelper::SetSpec(UTestbed1StructArray2InterfaceImplSpec* InSpec)
{
	Spec = InSpec;
}

void UTestbed1StructArray2InterfaceImplHelper::PropBoolPropertyCb(const FTestbed1StructBoolWithArray& PropBool)
{
	Spec->PropBoolPropertyCb(PropBool);
}

void UTestbed1StructArray2InterfaceImplHelper::PropIntPropertyCb(const FTestbed1StructIntWithArray& PropInt)
{
	Spec->PropIntPropertyCb(PropInt);
}

void UTestbed1StructArray2InterfaceImplHelper::PropFloatPropertyCb(const FTestbed1StructFloatWithArray& PropFloat)
{
	Spec->PropFloatPropertyCb(PropFloat);
}

void UTestbed1StructArray2InterfaceImplHelper::PropStringPropertyCb(const FTestbed1StructStringWithArray& PropString)
{
	Spec->PropStringPropertyCb(PropString);
}

void UTestbed1StructArray2InterfaceImplHelper::PropEnumPropertyCb(const FTestbed1StructEnumWithArray& PropEnum)
{
	Spec->PropEnumPropertyCb(PropEnum);
}

void UTestbed1StructArray2InterfaceImplHelper::SigBoolSignalCb(const FTestbed1StructBoolWithArray& ParamBool)
{
	Spec->SigBoolSignalCb(ParamBool);
}

void UTestbed1StructArray2InterfaceImplHelper::SigIntSignalCb(const FTestbed1StructIntWithArray& ParamInt)
{
	Spec->SigIntSignalCb(ParamInt);
}

void UTestbed1StructArray2InterfaceImplHelper::SigFloatSignalCb(const FTestbed1StructFloatWithArray& ParamFloat)
{
	Spec->SigFloatSignalCb(ParamFloat);
}

void UTestbed1StructArray2InterfaceImplHelper::SigStringSignalCb(const FTestbed1StructStringWithArray& ParamString)
{
	Spec->SigStringSignalCb(ParamString);
}

FTestbed1StructArray2InterfaceImplFixture::FTestbed1StructArray2InterfaceImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed1StructArray2Interface>();
	Helper = NewObject<UTestbed1StructArray2InterfaceImplHelper>();
}

FTestbed1StructArray2InterfaceImplFixture::~FTestbed1StructArray2InterfaceImplFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed1StructArray2InterfaceInterface> FTestbed1StructArray2InterfaceImplFixture::GetImplementation()
{
	return testImplementation;
}

TWeakObjectPtr<UTestbed1StructArray2InterfaceImplHelper> FTestbed1StructArray2InterfaceImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTestbed1StructArray2InterfaceImplFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTestbed1StructArray2InterfaceImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTestbed1StructArray2InterfaceImplHelper::SetSpec(UTestbed1StructArray2InterfaceImplSpec* /* InSpec */)
{
}

void UTestbed1StructArray2InterfaceImplHelper::PropBoolPropertyCb(const FTestbed1StructBoolWithArray& PropBool)
{
	(void)PropBool;
}

void UTestbed1StructArray2InterfaceImplHelper::PropIntPropertyCb(const FTestbed1StructIntWithArray& PropInt)
{
	(void)PropInt;
}

void UTestbed1StructArray2InterfaceImplHelper::PropFloatPropertyCb(const FTestbed1StructFloatWithArray& PropFloat)
{
	(void)PropFloat;
}

void UTestbed1StructArray2InterfaceImplHelper::PropStringPropertyCb(const FTestbed1StructStringWithArray& PropString)
{
	(void)PropString;
}

void UTestbed1StructArray2InterfaceImplHelper::PropEnumPropertyCb(const FTestbed1StructEnumWithArray& PropEnum)
{
	(void)PropEnum;
}

void UTestbed1StructArray2InterfaceImplHelper::SigBoolSignalCb(const FTestbed1StructBoolWithArray& ParamBool)
{
	(void)ParamBool;
}

void UTestbed1StructArray2InterfaceImplHelper::SigIntSignalCb(const FTestbed1StructIntWithArray& ParamInt)
{
	(void)ParamInt;
}

void UTestbed1StructArray2InterfaceImplHelper::SigFloatSignalCb(const FTestbed1StructFloatWithArray& ParamFloat)
{
	(void)ParamFloat;
}

void UTestbed1StructArray2InterfaceImplHelper::SigStringSignalCb(const FTestbed1StructStringWithArray& ParamString)
{
	(void)ParamString;
}
#endif // WITH_DEV_AUTOMATION_TESTS
