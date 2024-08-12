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

void UTbSimpleSimpleInterfaceImplHelper::PropBoolPropertyCb(bool bPropBool)
{
	Spec->PropBoolPropertyCb(bPropBool);
}

void UTbSimpleSimpleInterfaceImplHelper::PropIntPropertyCb(int32 PropInt)
{
	Spec->PropIntPropertyCb(PropInt);
}

void UTbSimpleSimpleInterfaceImplHelper::PropInt32PropertyCb(int32 PropInt32)
{
	Spec->PropInt32PropertyCb(PropInt32);
}

void UTbSimpleSimpleInterfaceImplHelper::PropInt64PropertyCb(int64 PropInt64)
{
	Spec->PropInt64PropertyCb(PropInt64);
}

void UTbSimpleSimpleInterfaceImplHelper::PropFloatPropertyCb(float PropFloat)
{
	Spec->PropFloatPropertyCb(PropFloat);
}

void UTbSimpleSimpleInterfaceImplHelper::PropFloat32PropertyCb(float PropFloat32)
{
	Spec->PropFloat32PropertyCb(PropFloat32);
}

void UTbSimpleSimpleInterfaceImplHelper::PropFloat64PropertyCb(double PropFloat64)
{
	Spec->PropFloat64PropertyCb(PropFloat64);
}

void UTbSimpleSimpleInterfaceImplHelper::PropStringPropertyCb(const FString& PropString)
{
	Spec->PropStringPropertyCb(PropString);
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

void UTbSimpleSimpleInterfaceImplHelper::SigFloat32SignalCb(float ParamFloat32)
{
	Spec->SigFloat32SignalCb(ParamFloat32);
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