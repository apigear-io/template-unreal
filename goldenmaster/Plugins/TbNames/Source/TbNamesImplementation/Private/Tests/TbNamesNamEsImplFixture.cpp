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
#include "TbNamesNamEsImplFixture.h"
#include "TbNamesNamEsImpl.spec.h"
#include "TbNames/Implementation/TbNamesNamEs.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbNamesNamEsImplHelper::SetSpec(UTbNamesNamEsImplSpec* InSpec)
{
	Spec = InSpec;
}

void UTbNamesNamEsImplHelper::SwitchPropertyCb(bool bSwitch)
{
	Spec->SwitchPropertyCb(bSwitch);
}

void UTbNamesNamEsImplHelper::SomePropertyPropertyCb(int32 SomeProperty)
{
	Spec->SomePropertyPropertyCb(SomeProperty);
}

void UTbNamesNamEsImplHelper::SomePoperty2PropertyCb(int32 SomePoperty2)
{
	Spec->SomePoperty2PropertyCb(SomePoperty2);
}

void UTbNamesNamEsImplHelper::EnumPropertyPropertyCb(ETbNamesEnum_With_Under_scores EnumProperty)
{
	Spec->EnumPropertyPropertyCb(EnumProperty);
}

void UTbNamesNamEsImplHelper::SomeSignalSignalCb(bool bSomeParam)
{
	Spec->SomeSignalSignalCb(bSomeParam);
}

void UTbNamesNamEsImplHelper::SomeSignal2SignalCb(bool bSomeParam)
{
	Spec->SomeSignal2SignalCb(bSomeParam);
}

FTbNamesNamEsImplFixture::FTbNamesNamEsImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbNamesNamEs>();
	Helper = NewObject<UTbNamesNamEsImplHelper>();
}

FTbNamesNamEsImplFixture::~FTbNamesNamEsImplFixture()
{
	CleanUp();
}

TScriptInterface<ITbNamesNamEsInterface> FTbNamesNamEsImplFixture::GetImplementation()
{
	return testImplementation;
}

TSoftObjectPtr<UTbNamesNamEsImplHelper> FTbNamesNamEsImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbNamesNamEsImplFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>(GetTransientPackage());
		GameInstance->Init();
		// needed to prevent garbage collection and we can't use UPROPERTY on raw c++ objects
		GameInstance->AddToRoot();
	}

	return GameInstance.Get();
}

void FTbNamesNamEsImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTbNamesNamEsImplHelper::SetSpec(UTbNamesNamEsImplSpec* /* InSpec */)
{
}

void UTbNamesNamEsImplHelper::SwitchPropertyCb(bool bSwitch)
{
	(void)bSwitch;
}

void UTbNamesNamEsImplHelper::SomePropertyPropertyCb(int32 SomeProperty)
{
	(void)SomeProperty;
}

void UTbNamesNamEsImplHelper::SomePoperty2PropertyCb(int32 SomePoperty2)
{
	(void)SomePoperty2;
}

void UTbNamesNamEsImplHelper::EnumPropertyPropertyCb(ETbNamesEnum_With_Under_scores EnumProperty)
{
	(void)EnumProperty;
}

void UTbNamesNamEsImplHelper::SomeSignalSignalCb(bool bSomeParam)
{
	(void)bSomeParam;
}

void UTbNamesNamEsImplHelper::SomeSignal2SignalCb(bool bSomeParam)
{
	(void)bSomeParam;
}
#endif // WITH_DEV_AUTOMATION_TESTS
