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
#include "TbSimple/Generated/api/AbstractTbSimpleVoidInterface.h"
#include "TbSimpleVoidInterfaceLatentAction.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

UAbstractTbSimpleVoidInterface::UAbstractTbSimpleVoidInterface()
{
	TbSimpleVoidInterfacePublisher = NewObject<UTbSimpleVoidInterfacePublisher>();
}

UTbSimpleVoidInterfacePublisher* UAbstractTbSimpleVoidInterface::_GetPublisher()
{
	if (!TbSimpleVoidInterfacePublisher)
	{
		TbSimpleVoidInterfacePublisher = NewObject<UTbSimpleVoidInterfacePublisher>();
	}
	return TbSimpleVoidInterfacePublisher;
}

void UAbstractTbSimpleVoidInterface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTbSimpleVoidInterface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	if (TbSimpleVoidInterfacePublisher)
	{
		TbSimpleVoidInterfacePublisher->OnSigVoidSignal.RemoveAll(TbSimpleVoidInterfacePublisher);
		TbSimpleVoidInterfacePublisher->OnSigVoidSignalBP.RemoveAll(TbSimpleVoidInterfacePublisher);
	}

	Super::Deinitialize();
}

bool UAbstractTbSimpleVoidInterface::IsInitialized() const
{
	return bInitialized;
}
