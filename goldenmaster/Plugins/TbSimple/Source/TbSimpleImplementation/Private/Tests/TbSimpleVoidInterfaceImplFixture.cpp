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
#include "TbSimpleVoidInterfaceImplFixture.h"
#include "TbSimpleVoidInterfaceImpl.spec.h"
#include "TbSimple/Implementation/TbSimpleVoidInterface.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTbSimpleVoidInterfaceImplHelper::SetSpec(UTbSimpleVoidInterfaceImplSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSimpleVoidInterfaceImplHelper::SigVoidSignalCb()
{
	Spec->SigVoidSignalCb();
}

FTbSimpleVoidInterfaceImplFixture::FTbSimpleVoidInterfaceImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleVoidInterface>();
	Helper = NewObject<UTbSimpleVoidInterfaceImplHelper>();
}

FTbSimpleVoidInterfaceImplFixture::~FTbSimpleVoidInterfaceImplFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleVoidInterfaceInterface> FTbSimpleVoidInterfaceImplFixture::GetImplementation()
{
	return testImplementation;
}

TWeakObjectPtr<UTbSimpleVoidInterfaceImplHelper> FTbSimpleVoidInterfaceImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSimpleVoidInterfaceImplFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSimpleVoidInterfaceImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTbSimpleVoidInterfaceImplHelper::SetSpec(UTbSimpleVoidInterfaceImplSpec* /* InSpec */)
{
}

void UTbSimpleVoidInterfaceImplHelper::SigVoidSignalCb()
{
}
#endif // WITH_DEV_AUTOMATION_TESTS
