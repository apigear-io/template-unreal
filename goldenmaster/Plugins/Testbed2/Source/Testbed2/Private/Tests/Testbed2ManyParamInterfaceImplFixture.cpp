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
#include "Testbed2ManyParamInterfaceImplFixture.h"
#include "Testbed2ManyParamInterfaceImpl.spec.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

void UTestbed2ManyParamInterfaceImplHelper::SetSpec(UTestbed2ManyParamInterfaceImplSpec* InSpec)
{
	Spec = InSpec;
}

void UTestbed2ManyParamInterfaceImplHelper::Sig1SignalCb(int32 Param1)
{
	Spec->Sig1SignalCb(Param1);
}

void UTestbed2ManyParamInterfaceImplHelper::Sig2SignalCb(int32 Param1, int32 Param2)
{
	Spec->Sig2SignalCb(Param1, Param2);
}

void UTestbed2ManyParamInterfaceImplHelper::Sig3SignalCb(int32 Param1, int32 Param2, int32 Param3)
{
	Spec->Sig3SignalCb(Param1, Param2, Param3);
}

void UTestbed2ManyParamInterfaceImplHelper::Sig4SignalCb(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	Spec->Sig4SignalCb(Param1, Param2, Param3, Param4);
}

#if WITH_DEV_AUTOMATION_TESTS

FTestbed2ManyParamInterfaceImplFixture::FTestbed2ManyParamInterfaceImplFixture()
{
	testImplementation = GetGameInstance()->GetSubsystem<UTestbed2ManyParamInterface>();
	Helper = NewObject<UTestbed2ManyParamInterfaceImplHelper>();
}

FTestbed2ManyParamInterfaceImplFixture::~FTestbed2ManyParamInterfaceImplFixture()
{
	CleanUp();
}

TScriptInterface<ITestbed2ManyParamInterfaceInterface> FTestbed2ManyParamInterfaceImplFixture::GetImplementation()
{
	return testImplementation;
}

TWeakObjectPtr<UTestbed2ManyParamInterfaceImplHelper> FTestbed2ManyParamInterfaceImplFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FTestbed2ManyParamInterfaceImplFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FTestbed2ManyParamInterfaceImplFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}

#endif // WITH_DEV_AUTOMATION_TESTS