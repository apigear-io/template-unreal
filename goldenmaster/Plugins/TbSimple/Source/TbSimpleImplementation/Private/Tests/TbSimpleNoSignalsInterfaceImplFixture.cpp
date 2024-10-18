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
#include "TbSimpleNoSignalsInterfaceImplFixture.h"
#include "TbSimpleNoSignalsInterfaceImpl.spec.h"
#include "TbSimple/Implementation/TbSimpleNoSignalsInterface.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSimpleNoSignalsInterfaceImplHelper::SetSpec(UTbSimpleNoSignalsInterfaceImplSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSimpleNoSignalsInterfaceImplHelper::PropBoolPropertyCb(bool bPropBool)
{
	Spec->PropBoolPropertyCb(bPropBool);
}

void UTbSimpleNoSignalsInterfaceImplHelper::PropIntPropertyCb(int32 PropInt)
{
	Spec->PropIntPropertyCb(PropInt);
}

FTbSimpleNoSignalsInterfaceImplFixture::FTbSimpleNoSignalsInterfaceImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleNoSignalsInterface>();
	Helper = NewObject<UTbSimpleNoSignalsInterfaceImplHelper>();
}

FTbSimpleNoSignalsInterfaceImplFixture::~FTbSimpleNoSignalsInterfaceImplFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleNoSignalsInterfaceInterface> FTbSimpleNoSignalsInterfaceImplFixture::GetImplementation()
{
	return testImplementation;
}

TWeakObjectPtr<UTbSimpleNoSignalsInterfaceImplHelper> FTbSimpleNoSignalsInterfaceImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSimpleNoSignalsInterfaceImplFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSimpleNoSignalsInterfaceImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTbSimpleNoSignalsInterfaceImplHelper::SetSpec(UTbSimpleNoSignalsInterfaceImplSpec* /* InSpec */)
{
}

void UTbSimpleNoSignalsInterfaceImplHelper::PropBoolPropertyCb(bool bPropBool)
{
	(void)bPropBool;
}

void UTbSimpleNoSignalsInterfaceImplHelper::PropIntPropertyCb(int32 PropInt)
{
	(void)PropInt;
}
#endif // WITH_DEV_AUTOMATION_TESTS
