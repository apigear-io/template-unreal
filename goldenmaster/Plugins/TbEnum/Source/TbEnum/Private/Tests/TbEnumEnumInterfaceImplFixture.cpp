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

#if WITH_DEV_AUTOMATION_TESTS

void UTbEnumEnumInterfaceImplHelper::SetSpec(UTbEnumEnumInterfaceImplSpec* InSpec)
{
	Spec = InSpec;
}

void UTbEnumEnumInterfaceImplHelper::Prop0PropertyCb(ETbEnumEnum0 Prop0)
{
	Spec->Prop0PropertyCb(Prop0);
}

void UTbEnumEnumInterfaceImplHelper::Prop1PropertyCb(ETbEnumEnum1 Prop1)
{
	Spec->Prop1PropertyCb(Prop1);
}

void UTbEnumEnumInterfaceImplHelper::Prop2PropertyCb(ETbEnumEnum2 Prop2)
{
	Spec->Prop2PropertyCb(Prop2);
}

void UTbEnumEnumInterfaceImplHelper::Prop3PropertyCb(ETbEnumEnum3 Prop3)
{
	Spec->Prop3PropertyCb(Prop3);
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

TSoftObjectPtr<UTbEnumEnumInterfaceImplHelper> FTbEnumEnumInterfaceImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbEnumEnumInterfaceImplFixture::GetGameInstance()
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

void FTbEnumEnumInterfaceImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
		GameInstance->RemoveFromRoot();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTbEnumEnumInterfaceImplHelper::SetSpec(UTbEnumEnumInterfaceImplSpec* /* InSpec */)
{
}

void UTbEnumEnumInterfaceImplHelper::Prop0PropertyCb(ETbEnumEnum0 Prop0)
{
	(void)Prop0;
}

void UTbEnumEnumInterfaceImplHelper::Prop1PropertyCb(ETbEnumEnum1 Prop1)
{
	(void)Prop1;
}

void UTbEnumEnumInterfaceImplHelper::Prop2PropertyCb(ETbEnumEnum2 Prop2)
{
	(void)Prop2;
}

void UTbEnumEnumInterfaceImplHelper::Prop3PropertyCb(ETbEnumEnum3 Prop3)
{
	(void)Prop3;
}

void UTbEnumEnumInterfaceImplHelper::Sig0SignalCb(ETbEnumEnum0 Param0)
{
	(void)Param0;
}

void UTbEnumEnumInterfaceImplHelper::Sig1SignalCb(ETbEnumEnum1 Param1)
{
	(void)Param1;
}

void UTbEnumEnumInterfaceImplHelper::Sig2SignalCb(ETbEnumEnum2 Param2)
{
	(void)Param2;
}

void UTbEnumEnumInterfaceImplHelper::Sig3SignalCb(ETbEnumEnum3 Param3)
{
	(void)Param3;
}
#endif // WITH_DEV_AUTOMATION_TESTS
