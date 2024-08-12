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
#include "TbSimpleNoPropertiesInterfaceImplFixture.h"
#include "TbSimpleNoPropertiesInterfaceImpl.spec.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSimpleNoPropertiesInterfaceImplHelper::SetSpec(UTbSimpleNoPropertiesInterfaceImplSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSimpleNoPropertiesInterfaceImplHelper::SigVoidSignalCb()
{
	Spec->SigVoidSignalCb();
}

void UTbSimpleNoPropertiesInterfaceImplHelper::SigBoolSignalCb(bool bParamBool)
{
	Spec->SigBoolSignalCb(bParamBool);
}

FTbSimpleNoPropertiesInterfaceImplFixture::FTbSimpleNoPropertiesInterfaceImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleNoPropertiesInterface>();
	Helper = NewObject<UTbSimpleNoPropertiesInterfaceImplHelper>();
}

FTbSimpleNoPropertiesInterfaceImplFixture::~FTbSimpleNoPropertiesInterfaceImplFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> FTbSimpleNoPropertiesInterfaceImplFixture::GetImplementation()
{
	return testImplementation;
}

TWeakObjectPtr<UTbSimpleNoPropertiesInterfaceImplHelper> FTbSimpleNoPropertiesInterfaceImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSimpleNoPropertiesInterfaceImplFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSimpleNoPropertiesInterfaceImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTbSimpleNoPropertiesInterfaceImplHelper::SetSpec(UTbSimpleNoPropertiesInterfaceImplSpec* /* InSpec */)
{
}

void UTbSimpleNoPropertiesInterfaceImplHelper::SigVoidSignalCb()
{
}

void UTbSimpleNoPropertiesInterfaceImplHelper::SigBoolSignalCb(bool bParamBool)
{
	(void) bParamBool;
}
#endif // WITH_DEV_AUTOMATION_TESTS
