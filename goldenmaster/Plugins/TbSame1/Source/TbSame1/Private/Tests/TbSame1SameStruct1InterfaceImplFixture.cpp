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
#include "TbSame1SameStruct1InterfaceImplFixture.h"
#include "TbSame1SameStruct1InterfaceImpl.spec.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

void UTbSame1SameStruct1InterfaceImplHelper::SetSpec(UTbSame1SameStruct1InterfaceImplSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSame1SameStruct1InterfaceImplHelper::Sig1SignalCb(const FTbSame1Struct1& Param1)
{
	Spec->Sig1SignalCb(Param1);
}

#if WITH_DEV_AUTOMATION_TESTS

FTbSame1SameStruct1InterfaceImplFixture::FTbSame1SameStruct1InterfaceImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSame1SameStruct1Interface>();
	Helper = NewObject<UTbSame1SameStruct1InterfaceImplHelper>();
}

FTbSame1SameStruct1InterfaceImplFixture::~FTbSame1SameStruct1InterfaceImplFixture()
{
	CleanUp();
}

TScriptInterface<ITbSame1SameStruct1InterfaceInterface> FTbSame1SameStruct1InterfaceImplFixture::GetImplementation()
{
	return testImplementation;
}

TWeakObjectPtr<UTbSame1SameStruct1InterfaceImplHelper> FTbSame1SameStruct1InterfaceImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSame1SameStruct1InterfaceImplFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSame1SameStruct1InterfaceImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}

#endif // WITH_DEV_AUTOMATION_TESTS