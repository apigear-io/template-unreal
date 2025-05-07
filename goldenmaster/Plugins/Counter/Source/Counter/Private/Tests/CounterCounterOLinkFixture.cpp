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
#include "CounterCounterOLinkFixture.h"
#include "CounterCounterOLink.spec.h"
#include "OLinkCommon.h"
#include "Generated/OLink/CounterCounterOLinkClient.h"
#include "Generated/OLink/CounterCounterOLinkAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
#include "OLinkHost.h"

void UCounterCounterOLinkHelper::SetSpec(UCounterCounterOLinkSpec* InSpec)
{
	Spec = InSpec;
}

void UCounterCounterOLinkHelper::VectorPropertyCb(const FCustomTypesVector3D& Vector)
{
	Spec->VectorPropertyCb(Vector);
}

void UCounterCounterOLinkHelper::VectorPropertyChangeLocalCheckRemoteCb(const FCustomTypesVector3D& Vector)
{
	if (Spec)
	{
		Spec->VectorPropertyChangeLocalCheckRemoteCb(Vector);
	}
}

void UCounterCounterOLinkHelper::VectorPropertyChangeLocalChangeRemoteCb(const FCustomTypesVector3D& Vector)
{
	if (Spec)
	{
		Spec->VectorPropertyChangeLocalChangeRemoteCb(Vector);
	}
}

void UCounterCounterOLinkHelper::VectorArrayPropertyCb(const TArray<FCustomTypesVector3D>& VectorArray)
{
	Spec->VectorArrayPropertyCb(VectorArray);
}

void UCounterCounterOLinkHelper::VectorArrayPropertyChangeLocalCheckRemoteCb(const TArray<FCustomTypesVector3D>& VectorArray)
{
	if (Spec)
	{
		Spec->VectorArrayPropertyChangeLocalCheckRemoteCb(VectorArray);
	}
}

void UCounterCounterOLinkHelper::VectorArrayPropertyChangeLocalChangeRemoteCb(const TArray<FCustomTypesVector3D>& VectorArray)
{
	if (Spec)
	{
		Spec->VectorArrayPropertyChangeLocalChangeRemoteCb(VectorArray);
	}
}

void UCounterCounterOLinkHelper::ValueChangedSignalCb(const FCustomTypesVector3D& Vector, const FVector& ExternVector, const TArray<FCustomTypesVector3D>& VectorArray, const TArray<FVector>& ExternVectorArray)
{
	Spec->ValueChangedSignalCb(Vector, ExternVector, VectorArray, ExternVectorArray);
}

void UCounterCounterOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	Spec->_SubscriptionStatusChangedCb(bSubscribed);
}

FCounterCounterOLinkFixture::FCounterCounterOLinkFixture()
{
	Helper = NewObject<UCounterCounterOLinkHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UCounterCounterOLinkClient>();
}

FCounterCounterOLinkFixture::~FCounterCounterOLinkFixture()
{
	CleanUp();
}

TScriptInterface<ICounterCounterInterface> FCounterCounterOLinkFixture::GetImplementation()
{
	return testImplementation;
}

UOLinkHost* FCounterCounterOLinkFixture::GetHost()
{
	return GetGameInstance()->GetSubsystem<UOLinkHost>();
}

UCounterCounterOLinkAdapter* FCounterCounterOLinkFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UCounterCounterOLinkAdapter>();
}

TSoftObjectPtr<UCounterCounterOLinkHelper> FCounterCounterOLinkFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FCounterCounterOLinkFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FCounterCounterOLinkFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
// create empty implementation in case we do not want to do automated testing
void UCounterCounterOLinkHelper::SetSpec(UCounterCounterOLinkSpec* /* InSpec */)
{
}

void UCounterCounterOLinkHelper::VectorPropertyCb(const FCustomTypesVector3D& Vector)
{
	(void)Vector;
}

void UCounterCounterOLinkHelper::VectorArrayPropertyCb(const TArray<FCustomTypesVector3D>& VectorArray)
{
	(void)VectorArray;
}

void UCounterCounterOLinkHelper::ValueChangedSignalCb(const FCustomTypesVector3D& Vector, const FVector& ExternVector, const TArray<FCustomTypesVector3D>& VectorArray, const TArray<FVector>& ExternVectorArray)
{
	(void)Vector;
	(void)ExternVector;
	(void)VectorArray;
	(void)ExternVectorArray;
}

void UCounterCounterOLinkHelper::_SubscriptionStatusChangedCb(bool bSubscribed)
{
	(void)bSubscribed;
}
#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID && !PLATFORM_QNX
