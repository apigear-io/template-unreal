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
#include "TbSame2SameStruct1InterfaceImplFixture.h"
#include "TbSame2SameStruct1InterfaceImpl.spec.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSame2SameStruct1InterfaceImplHelper::SetSpec(UTbSame2SameStruct1InterfaceImplSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSame2SameStruct1InterfaceImplHelper::Prop1PropertyCb(const FTbSame2Struct1& Prop1)
{
	Spec->Prop1PropertyCb(Prop1);
}

void UTbSame2SameStruct1InterfaceImplHelper::Sig1SignalCb(const FTbSame2Struct1& Param1)
{
	Spec->Sig1SignalCb(Param1);
}

FTbSame2SameStruct1InterfaceImplFixture::FTbSame2SameStruct1InterfaceImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame2SameStruct1Interface>();
	Helper = NewObject<UTbSame2SameStruct1InterfaceImplHelper>();
}

FTbSame2SameStruct1InterfaceImplFixture::~FTbSame2SameStruct1InterfaceImplFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame2SameStruct1InterfaceInterface> FTbSame2SameStruct1InterfaceImplFixture::GetImplementation()
{
	return testImplementation;
}

TWeakObjectPtr<UTbSame2SameStruct1InterfaceImplHelper> FTbSame2SameStruct1InterfaceImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSame2SameStruct1InterfaceImplFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSame2SameStruct1InterfaceImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTbSame2SameStruct1InterfaceImplHelper::SetSpec(UTbSame2SameStruct1InterfaceImplSpec* /* InSpec */)
{
}

void UTbSame2SameStruct1InterfaceImplHelper::Prop1PropertyCb(const FTbSame2Struct1& Prop1)
{
	(void)Prop1;
}

void UTbSame2SameStruct1InterfaceImplHelper::Sig1SignalCb(const FTbSame2Struct1& Param1)
{
	(void)Param1;
}
#endif // WITH_DEV_AUTOMATION_TESTS
