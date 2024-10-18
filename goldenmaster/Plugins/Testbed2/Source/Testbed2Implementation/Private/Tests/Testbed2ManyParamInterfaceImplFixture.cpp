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
#include "Testbed2/Implementation/Testbed2ManyParamInterface.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

void UTestbed2ManyParamInterfaceImplHelper::SetSpec(UTestbed2ManyParamInterfaceImplSpec* InSpec)
{
	Spec = InSpec;
}

void UTestbed2ManyParamInterfaceImplHelper::Prop1PropertyCb(int32 Prop1)
{
	Spec->Prop1PropertyCb(Prop1);
}

void UTestbed2ManyParamInterfaceImplHelper::Prop2PropertyCb(int32 Prop2)
{
	Spec->Prop2PropertyCb(Prop2);
}

void UTestbed2ManyParamInterfaceImplHelper::Prop3PropertyCb(int32 Prop3)
{
	Spec->Prop3PropertyCb(Prop3);
}

void UTestbed2ManyParamInterfaceImplHelper::Prop4PropertyCb(int32 Prop4)
{
	Spec->Prop4PropertyCb(Prop4);
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
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
void UTestbed2ManyParamInterfaceImplHelper::SetSpec(UTestbed2ManyParamInterfaceImplSpec* /* InSpec */)
{
}

void UTestbed2ManyParamInterfaceImplHelper::Prop1PropertyCb(int32 Prop1)
{
	(void)Prop1;
}

void UTestbed2ManyParamInterfaceImplHelper::Prop2PropertyCb(int32 Prop2)
{
	(void)Prop2;
}

void UTestbed2ManyParamInterfaceImplHelper::Prop3PropertyCb(int32 Prop3)
{
	(void)Prop3;
}

void UTestbed2ManyParamInterfaceImplHelper::Prop4PropertyCb(int32 Prop4)
{
	(void)Prop4;
}

void UTestbed2ManyParamInterfaceImplHelper::Sig1SignalCb(int32 Param1)
{
	(void)Param1;
}

void UTestbed2ManyParamInterfaceImplHelper::Sig2SignalCb(int32 Param1, int32 Param2)
{
	(void)Param1;
	(void)Param2;
}

void UTestbed2ManyParamInterfaceImplHelper::Sig3SignalCb(int32 Param1, int32 Param2, int32 Param3)
{
	(void)Param1;
	(void)Param2;
	(void)Param3;
}

void UTestbed2ManyParamInterfaceImplHelper::Sig4SignalCb(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	(void)Param1;
	(void)Param2;
	(void)Param3;
	(void)Param4;
}
#endif // WITH_DEV_AUTOMATION_TESTS
