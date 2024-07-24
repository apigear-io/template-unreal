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
#include "TbSimpleSimpleInterfaceImplFixture.h"
#include "TbSimpleSimpleInterfaceImpl.spec.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

void UTbSimpleSimpleInterfaceImplHelper::SetSpec(UTbSimpleSimpleInterfaceImplSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSimpleSimpleInterfaceImplHelper::SigVoidSignalCb()
{
	Spec->SigVoidSignalCb();
}

void UTbSimpleSimpleInterfaceImplHelper::SigBoolSignalCb(bool bParamBool)
{
	Spec->SigBoolSignalCb(bParamBool);
}

void UTbSimpleSimpleInterfaceImplHelper::SigIntSignalCb(int32 ParamInt)
{
	Spec->SigIntSignalCb(ParamInt);
}

void UTbSimpleSimpleInterfaceImplHelper::SigInt32SignalCb(int32 ParamInt32)
{
	Spec->SigInt32SignalCb(ParamInt32);
}

void UTbSimpleSimpleInterfaceImplHelper::SigInt64SignalCb(int64 ParamInt64)
{
	Spec->SigInt64SignalCb(ParamInt64);
}

void UTbSimpleSimpleInterfaceImplHelper::SigFloatSignalCb(float ParamFloat)
{
	Spec->SigFloatSignalCb(ParamFloat);
}

void UTbSimpleSimpleInterfaceImplHelper::SigFloat32SignalCb(float ParamFloa32)
{
	Spec->SigFloat32SignalCb(ParamFloa32);
}

void UTbSimpleSimpleInterfaceImplHelper::SigFloat64SignalCb(double ParamFloat64)
{
	Spec->SigFloat64SignalCb(ParamFloat64);
}

void UTbSimpleSimpleInterfaceImplHelper::SigStringSignalCb(const FString& ParamString)
{
	Spec->SigStringSignalCb(ParamString);
}

#if WITH_DEV_AUTOMATION_TESTS

FTbSimpleSimpleInterfaceImplFixture::FTbSimpleSimpleInterfaceImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleSimpleInterface>();
	Helper = NewObject<UTbSimpleSimpleInterfaceImplHelper>();
}

FTbSimpleSimpleInterfaceImplFixture::~FTbSimpleSimpleInterfaceImplFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleSimpleInterfaceInterface> FTbSimpleSimpleInterfaceImplFixture::GetImplementation()
{
	return testImplementation;
}

TWeakObjectPtr<UTbSimpleSimpleInterfaceImplHelper> FTbSimpleSimpleInterfaceImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSimpleSimpleInterfaceImplFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSimpleSimpleInterfaceImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}

#endif // WITH_DEV_AUTOMATION_TESTS