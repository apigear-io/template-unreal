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
#include "TbSame2SameStruct2InterfaceImplFixture.h"
#include "TbSame2SameStruct2InterfaceImpl.spec.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

void UTbSame2SameStruct2InterfaceImplHelper::SetSpec(UTbSame2SameStruct2InterfaceImplSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSame2SameStruct2InterfaceImplHelper::Sig1SignalCb(const FTbSame2Struct1& Param1)
{
	Spec->Sig1SignalCb(Param1);
}

void UTbSame2SameStruct2InterfaceImplHelper::Sig2SignalCb(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2)
{
	Spec->Sig2SignalCb(Param1, Param2);
}

#if WITH_DEV_AUTOMATION_TESTS

FTbSame2SameStruct2InterfaceImplFixture::FTbSame2SameStruct2InterfaceImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame2SameStruct2Interface>();
	Helper = NewObject<UTbSame2SameStruct2InterfaceImplHelper>();
}

FTbSame2SameStruct2InterfaceImplFixture::~FTbSame2SameStruct2InterfaceImplFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame2SameStruct2InterfaceInterface> FTbSame2SameStruct2InterfaceImplFixture::GetImplementation()
{
	return testImplementation;
}

TWeakObjectPtr<UTbSame2SameStruct2InterfaceImplHelper> FTbSame2SameStruct2InterfaceImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSame2SameStruct2InterfaceImplFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSame2SameStruct2InterfaceImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}

#endif // WITH_DEV_AUTOMATION_TESTS