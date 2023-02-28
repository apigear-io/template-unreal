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
#pragma once
#include "TbSimpleNoOperationsInterfaceInterface.h"

UFUNCTION(Category = "ApiGear|TbSimple|NoOperationsInterface")
FTbSimpleNoOperationsInterfaceSigVoidDelegate& UAbstractTbSimpleNoOperationsInterface::GetSigVoidSignalDelegate()
{
	return SigVoidSignal;
};

UFUNCTION(Category = "ApiGear|TbSimple|NoOperationsInterface")
FTbSimpleNoOperationsInterfaceSigBoolDelegate& UAbstractTbSimpleNoOperationsInterface::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
};

FTbSimpleNoOperationsInterfacePropBoolChangedDelegate& UAbstractTbSimpleNoOperationsInterface::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
};

FTbSimpleNoOperationsInterfacePropIntChangedDelegate& UAbstractTbSimpleNoOperationsInterface::GetPropIntChangedDelegate()
{
	return PropIntChanged;
};
void UAbstractTbSimpleNoOperationsInterface::BroadcastSigVoid_Implementation()
{
	SigVoidSignal.Broadcast();
};

void UAbstractTbSimpleNoOperationsInterface::BroadcastSigBool_Implementation(bool bParamBool)
{
	SigBoolSignal.Broadcast(bParamBool);
};

void UAbstractTbSimpleNoOperationsInterface::BroadcastPropBoolChanged_Implementation(bool bInPropBool)
{
	PropBoolChanged.Broadcast(bInPropBool);
}

void UAbstractTbSimpleNoOperationsInterface::BroadcastPropIntChanged_Implementation(int32 InPropInt)
{
	PropIntChanged.Broadcast(InPropInt);
}
bool UAbstractTbSimpleNoOperationsInterface::GetPropBool_Private() const
{
	return Execute_GetPropBool(this);
};

void UAbstractTbSimpleNoOperationsInterface::SetPropBool_Private(bool bInPropBool)
{
	Execute_SetPropBool(this, bInPropBool);
};

int32 UAbstractTbSimpleNoOperationsInterface::GetPropInt_Private() const
{
	return Execute_GetPropInt(this);
};

void UAbstractTbSimpleNoOperationsInterface::SetPropInt_Private(int32 InPropInt)
{
	Execute_SetPropInt(this, InPropInt);
};
