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
#include "TbEnumEnumInterfaceImplFixture.h"
#include "TbEnumEnumInterfaceImpl.spec.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

void UTbEnumEnumInterfaceImplHelper::SetSpec(UTbEnumEnumInterfaceImplSpec* InSpec)
{
	Spec = InSpec;
}

void UTbEnumEnumInterfaceImplHelper::Sig0SignalCb(ETbEnumEnum0 Param0)
{
	Spec->Sig0SignalCb(Param0);
}

void UTbEnumEnumInterfaceImplHelper::Sig1SignalCb(ETbEnumEnum1 Param1)
{
	Spec->Sig1SignalCb(Param1);
}

void UTbEnumEnumInterfaceImplHelper::Sig2SignalCb(ETbEnumEnum2 Param2)
{
	Spec->Sig2SignalCb(Param2);
}

void UTbEnumEnumInterfaceImplHelper::Sig3SignalCb(ETbEnumEnum3 Param3)
{
	Spec->Sig3SignalCb(Param3);
}

#if WITH_DEV_AUTOMATION_TESTS

FTbEnumEnumInterfaceImplFixture::FTbEnumEnumInterfaceImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbEnumEnumInterface>();
	Helper = NewObject<UTbEnumEnumInterfaceImplHelper>();
}

FTbEnumEnumInterfaceImplFixture::~FTbEnumEnumInterfaceImplFixture()
{
	CleanUp();
}

TScriptInterface<ITbEnumEnumInterfaceInterface> FTbEnumEnumInterfaceImplFixture::GetImplementation()
{
	return testImplementation;
}

TWeakObjectPtr<UTbEnumEnumInterfaceImplHelper> FTbEnumEnumInterfaceImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbEnumEnumInterfaceImplFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbEnumEnumInterfaceImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}

#endif // WITH_DEV_AUTOMATION_TESTS