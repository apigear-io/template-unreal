/**
Copyright 2024 ApiGear UG
Copyright 2024 Epic Games, Inc.

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
#include "TbSimple/Generated/api/AbstractTbSimpleNoOperationsInterface.h"
#include "TbSimpleNoOperationsInterfaceLatentAction.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

UAbstractTbSimpleNoOperationsInterface::UAbstractTbSimpleNoOperationsInterface()
{
	TbSimpleNoOperationsInterfacePublisher = NewObject<UTbSimpleNoOperationsInterfacePublisher>();
}

UTbSimpleNoOperationsInterfacePublisher* UAbstractTbSimpleNoOperationsInterface::_GetPublisher()
{
	if (!TbSimpleNoOperationsInterfacePublisher)
	{
		TbSimpleNoOperationsInterfacePublisher = NewObject<UTbSimpleNoOperationsInterfacePublisher>();
	}
	return TbSimpleNoOperationsInterfacePublisher;
}

bool UAbstractTbSimpleNoOperationsInterface::GetPropBool_Private() const
{
	return GetPropBool();
};

void UAbstractTbSimpleNoOperationsInterface::SetPropBool_Private(bool bInPropBool)
{
	SetPropBool(bInPropBool);
};

int32 UAbstractTbSimpleNoOperationsInterface::GetPropInt_Private() const
{
	return GetPropInt();
};

void UAbstractTbSimpleNoOperationsInterface::SetPropInt_Private(int32 InPropInt)
{
	SetPropInt(InPropInt);
};

void UAbstractTbSimpleNoOperationsInterface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTbSimpleNoOperationsInterface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (TbSimpleNoOperationsInterfacePublisher)
	{
		TbSimpleNoOperationsInterfacePublisher->OnSigVoidSignal.RemoveAll(TbSimpleNoOperationsInterfacePublisher);
		TbSimpleNoOperationsInterfacePublisher->OnSigVoidSignalBP.RemoveAll(TbSimpleNoOperationsInterfacePublisher);
		TbSimpleNoOperationsInterfacePublisher->OnSigBoolSignal.RemoveAll(TbSimpleNoOperationsInterfacePublisher);
		TbSimpleNoOperationsInterfacePublisher->OnSigBoolSignalBP.RemoveAll(TbSimpleNoOperationsInterfacePublisher);

		TbSimpleNoOperationsInterfacePublisher->OnPropBoolChanged.RemoveAll(TbSimpleNoOperationsInterfacePublisher);
		TbSimpleNoOperationsInterfacePublisher->OnPropBoolChangedBP.RemoveAll(TbSimpleNoOperationsInterfacePublisher);
		TbSimpleNoOperationsInterfacePublisher->OnPropIntChanged.RemoveAll(TbSimpleNoOperationsInterfacePublisher);
		TbSimpleNoOperationsInterfacePublisher->OnPropIntChangedBP.RemoveAll(TbSimpleNoOperationsInterfacePublisher);
	}

	Super::Deinitialize();
}

bool UAbstractTbSimpleNoOperationsInterface::IsInitialized() const
{
	return bInitialized;
}
