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
#include "TbSimpleNoOperationsInterfaceImplFixture.h"
#include "TbSimpleNoOperationsInterfaceImpl.spec.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSimpleNoOperationsInterfaceImplHelper::SetSpec(UTbSimpleNoOperationsInterfaceImplSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSimpleNoOperationsInterfaceImplHelper::PropBoolPropertyCb(bool bPropBool)
{
	Spec->PropBoolPropertyCb(bPropBool);
}

void UTbSimpleNoOperationsInterfaceImplHelper::PropIntPropertyCb(int32 PropInt)
{
	Spec->PropIntPropertyCb(PropInt);
}

void UTbSimpleNoOperationsInterfaceImplHelper::SigVoidSignalCb()
{
	Spec->SigVoidSignalCb();
}

void UTbSimpleNoOperationsInterfaceImplHelper::SigBoolSignalCb(bool bParamBool)
{
	Spec->SigBoolSignalCb(bParamBool);
}

FTbSimpleNoOperationsInterfaceImplFixture::FTbSimpleNoOperationsInterfaceImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleNoOperationsInterface>();
	Helper = NewObject<UTbSimpleNoOperationsInterfaceImplHelper>();
}

FTbSimpleNoOperationsInterfaceImplFixture::~FTbSimpleNoOperationsInterfaceImplFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleNoOperationsInterfaceInterface> FTbSimpleNoOperationsInterfaceImplFixture::GetImplementation()
{
	return testImplementation;
}

TWeakObjectPtr<UTbSimpleNoOperationsInterfaceImplHelper> FTbSimpleNoOperationsInterfaceImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSimpleNoOperationsInterfaceImplFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSimpleNoOperationsInterfaceImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTbSimpleNoOperationsInterfaceImplHelper::SetSpec(UTbSimpleNoOperationsInterfaceImplSpec* /* InSpec */)
{
}

void UTbSimpleNoOperationsInterfaceImplHelper::PropBoolPropertyCb(bool bPropBool)
{
	(void) bPropBool;
}

void UTbSimpleNoOperationsInterfaceImplHelper::PropIntPropertyCb(int32 PropInt)
{
	(void) PropInt;
}

void UTbSimpleNoOperationsInterfaceImplHelper::SigVoidSignalCb()
{
}

void UTbSimpleNoOperationsInterfaceImplHelper::SigBoolSignalCb(bool bParamBool)
{
	(void) bParamBool;
}
#endif // WITH_DEV_AUTOMATION_TESTS
