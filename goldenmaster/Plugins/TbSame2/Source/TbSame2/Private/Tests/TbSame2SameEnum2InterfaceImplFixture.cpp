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
#include "TbSame2SameEnum2InterfaceImplFixture.h"
#include "TbSame2SameEnum2InterfaceImpl.spec.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

void UTbSame2SameEnum2InterfaceImplHelper::SetSpec(UTbSame2SameEnum2InterfaceImplSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSame2SameEnum2InterfaceImplHelper::Prop1PropertyCb(ETbSame2Enum1 Prop1)
{
	Spec->Prop1PropertyCb(Prop1);
}

void UTbSame2SameEnum2InterfaceImplHelper::Prop2PropertyCb(ETbSame2Enum2 Prop2)
{
	Spec->Prop2PropertyCb(Prop2);
}

void UTbSame2SameEnum2InterfaceImplHelper::Sig1SignalCb(ETbSame2Enum1 Param1)
{
	Spec->Sig1SignalCb(Param1);
}

void UTbSame2SameEnum2InterfaceImplHelper::Sig2SignalCb(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2)
{
	Spec->Sig2SignalCb(Param1, Param2);
}

#if WITH_DEV_AUTOMATION_TESTS

FTbSame2SameEnum2InterfaceImplFixture::FTbSame2SameEnum2InterfaceImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame2SameEnum2Interface>();
	Helper = NewObject<UTbSame2SameEnum2InterfaceImplHelper>();
}

FTbSame2SameEnum2InterfaceImplFixture::~FTbSame2SameEnum2InterfaceImplFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame2SameEnum2InterfaceInterface> FTbSame2SameEnum2InterfaceImplFixture::GetImplementation()
{
	return testImplementation;
}

TWeakObjectPtr<UTbSame2SameEnum2InterfaceImplHelper> FTbSame2SameEnum2InterfaceImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSame2SameEnum2InterfaceImplFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSame2SameEnum2InterfaceImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}

#endif // WITH_DEV_AUTOMATION_TESTS