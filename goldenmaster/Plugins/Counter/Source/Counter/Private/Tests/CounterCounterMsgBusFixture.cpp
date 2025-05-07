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
#include "CounterCounterMsgBusFixture.h"
#include "CounterCounterMsgBus.spec.h"
#include "Generated/MsgBus/CounterCounterMsgBusClient.h"
#include "Generated/MsgBus/CounterCounterMsgBusAdapter.h"
#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

UCounterCounterMsgBusHelper::~UCounterCounterMsgBusHelper()
{
	Spec = nullptr;
}

void UCounterCounterMsgBusHelper::SetSpec(UCounterCounterMsgBusSpec* InSpec)
{
	Spec = InSpec;
}

void UCounterCounterMsgBusHelper::VectorPropertyCb(const FCustomTypesVector3D& Vector)
{
	if (Spec)
	{
		Spec->VectorPropertyCb(Vector);
	}
}

void UCounterCounterMsgBusHelper::VectorPropertyChangeLocalCheckRemoteCb(const FCustomTypesVector3D& Vector)
{
	if (Spec)
	{
		Spec->VectorPropertyChangeLocalCheckRemoteCb(Vector);
	}
}

void UCounterCounterMsgBusHelper::VectorPropertyChangeLocalChangeRemoteCb(const FCustomTypesVector3D& Vector)
{
	if (Spec)
	{
		Spec->VectorPropertyChangeLocalChangeRemoteCb(Vector);
	}
}

void UCounterCounterMsgBusHelper::VectorArrayPropertyCb(const TArray<FCustomTypesVector3D>& VectorArray)
{
	if (Spec)
	{
		Spec->VectorArrayPropertyCb(VectorArray);
	}
}

void UCounterCounterMsgBusHelper::VectorArrayPropertyChangeLocalCheckRemoteCb(const TArray<FCustomTypesVector3D>& VectorArray)
{
	if (Spec)
	{
		Spec->VectorArrayPropertyChangeLocalCheckRemoteCb(VectorArray);
	}
}

void UCounterCounterMsgBusHelper::VectorArrayPropertyChangeLocalChangeRemoteCb(const TArray<FCustomTypesVector3D>& VectorArray)
{
	if (Spec)
	{
		Spec->VectorArrayPropertyChangeLocalChangeRemoteCb(VectorArray);
	}
}

void UCounterCounterMsgBusHelper::ValueChangedSignalCb(const FCustomTypesVector3D& Vector, const FVector& ExternVector, const TArray<FCustomTypesVector3D>& VectorArray, const TArray<FVector>& ExternVectorArray)
{
	if (Spec)
	{
		Spec->ValueChangedSignalCb(Vector, ExternVector, VectorArray, ExternVectorArray);
	}
}

void UCounterCounterMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	if (Spec)
	{
		Spec->_ConnectionStatusChangedCb(bConnected);
	}
}

FCounterCounterMsgBusFixture::FCounterCounterMsgBusFixture()
{
	Helper = NewObject<UCounterCounterMsgBusHelper>();
	testImplementation = GetGameInstance()->GetSubsystem<UCounterCounterMsgBusClient>();
}

FCounterCounterMsgBusFixture::~FCounterCounterMsgBusFixture()
{
	CleanUp();
}

TScriptInterface<ICounterCounterInterface> FCounterCounterMsgBusFixture::GetImplementation()
{
	return testImplementation;
}

UCounterCounterMsgBusAdapter* FCounterCounterMsgBusFixture::GetAdapter()
{
	return GetGameInstance()->GetSubsystem<UCounterCounterMsgBusAdapter>();
}

TSoftObjectPtr<UCounterCounterMsgBusHelper> FCounterCounterMsgBusFixture::GetHelper()
{
	return Helper;
}

UGameInstance* FCounterCounterMsgBusFixture::GetGameInstance()
{
	if (!GameInstance.IsValid())
	{
		GameInstance = NewObject<UGameInstance>();
		GameInstance->Init();
	}

	return GameInstance.Get();
}

void FCounterCounterMsgBusFixture::CleanUp()
{
	if (GameInstance.IsValid())
	{
		GameInstance->Shutdown();
	}
}
#else  // WITH_DEV_AUTOMATION_TESTS
// create empty implementation in case we do not want to do automated testing
UCounterCounterMsgBusHelper::~UCounterCounterMsgBusHelper()
{
}

void UCounterCounterMsgBusHelper::SetSpec(UCounterCounterMsgBusSpec* /* InSpec */)
{
}

void UCounterCounterMsgBusHelper::VectorPropertyCb(const FCustomTypesVector3D& Vector)
{
	(void)Vector;
}

void UCounterCounterMsgBusHelper::VectorArrayPropertyCb(const TArray<FCustomTypesVector3D>& VectorArray)
{
	(void)VectorArray;
}

void UCounterCounterMsgBusHelper::ValueChangedSignalCb(const FCustomTypesVector3D& Vector, const FVector& ExternVector, const TArray<FCustomTypesVector3D>& VectorArray, const TArray<FVector>& ExternVectorArray)
{
	(void)Vector;
	(void)ExternVector;
	(void)VectorArray;
	(void)ExternVectorArray;
}

void UCounterCounterMsgBusHelper::_ConnectionStatusChangedCb(bool bConnected)
{
	(void)bConnected;
}
#endif // WITH_DEV_AUTOMATION_TESTS
