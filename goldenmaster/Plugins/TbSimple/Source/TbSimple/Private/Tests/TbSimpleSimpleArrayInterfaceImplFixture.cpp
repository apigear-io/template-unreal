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
#include "TbSimpleSimpleArrayInterfaceImplFixture.h"
#include "TbSimpleSimpleArrayInterfaceImpl.spec.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

void UTbSimpleSimpleArrayInterfaceImplHelper::SetSpec(UTbSimpleSimpleArrayInterfaceImplSpec* InSpec)
{
	Spec = InSpec;
}

void UTbSimpleSimpleArrayInterfaceImplHelper::SigBoolSignalCb(const TArray<bool>& ParamBool)
{
	Spec->SigBoolSignalCb(ParamBool);
}

void UTbSimpleSimpleArrayInterfaceImplHelper::SigIntSignalCb(const TArray<int32>& ParamInt)
{
	Spec->SigIntSignalCb(ParamInt);
}

void UTbSimpleSimpleArrayInterfaceImplHelper::SigInt32SignalCb(const TArray<int32>& ParamInt32)
{
	Spec->SigInt32SignalCb(ParamInt32);
}

void UTbSimpleSimpleArrayInterfaceImplHelper::SigInt64SignalCb(const TArray<int64>& ParamInt64)
{
	Spec->SigInt64SignalCb(ParamInt64);
}

void UTbSimpleSimpleArrayInterfaceImplHelper::SigFloatSignalCb(const TArray<float>& ParamFloat)
{
	Spec->SigFloatSignalCb(ParamFloat);
}

void UTbSimpleSimpleArrayInterfaceImplHelper::SigFloat32SignalCb(const TArray<float>& ParamFloa32)
{
	Spec->SigFloat32SignalCb(ParamFloa32);
}

void UTbSimpleSimpleArrayInterfaceImplHelper::SigFloat64SignalCb(const TArray<double>& ParamFloat64)
{
	Spec->SigFloat64SignalCb(ParamFloat64);
}

void UTbSimpleSimpleArrayInterfaceImplHelper::SigStringSignalCb(const TArray<FString>& ParamString)
{
	Spec->SigStringSignalCb(ParamString);
}

#if WITH_DEV_AUTOMATION_TESTS

FTbSimpleSimpleArrayInterfaceImplFixture::FTbSimpleSimpleArrayInterfaceImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTbSimpleSimpleArrayInterface>();
	Helper = NewObject<UTbSimpleSimpleArrayInterfaceImplHelper>();
}

FTbSimpleSimpleArrayInterfaceImplFixture::~FTbSimpleSimpleArrayInterfaceImplFixture()
{
	CleanUp();
}

TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> FTbSimpleSimpleArrayInterfaceImplFixture::GetImplementation()
{
	return testImplementation;
}

TWeakObjectPtr<UTbSimpleSimpleArrayInterfaceImplHelper> FTbSimpleSimpleArrayInterfaceImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTbSimpleSimpleArrayInterfaceImplFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTbSimpleSimpleArrayInterfaceImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}

#endif // WITH_DEV_AUTOMATION_TESTS