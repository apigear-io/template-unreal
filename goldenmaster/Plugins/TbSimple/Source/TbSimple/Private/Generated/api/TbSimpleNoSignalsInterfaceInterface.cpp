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
#include "TbSimpleNoSignalsInterfaceInterface.h"

FTbSimpleNoSignalsInterfacePropBoolChangedDelegate& UAbstractTbSimpleNoSignalsInterface::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
};

FTbSimpleNoSignalsInterfacePropIntChangedDelegate& UAbstractTbSimpleNoSignalsInterface::GetPropIntChangedDelegate()
{
	return PropIntChanged;
};

void UAbstractTbSimpleNoSignalsInterface::BroadcastPropBoolChanged_Implementation(bool bInPropBool)
{
	PropBoolChanged.Broadcast(bInPropBool);
}

void UAbstractTbSimpleNoSignalsInterface::BroadcastPropIntChanged_Implementation(int32 InPropInt)
{
	PropIntChanged.Broadcast(InPropInt);
}
bool UAbstractTbSimpleNoSignalsInterface::GetPropBool_Private() const
{
	return Execute_GetPropBool(this);
};

void UAbstractTbSimpleNoSignalsInterface::SetPropBool_Private(bool bInPropBool)
{
	Execute_SetPropBool(this, bInPropBool);
};

int32 UAbstractTbSimpleNoSignalsInterface::GetPropInt_Private() const
{
	return Execute_GetPropInt(this);
};

void UAbstractTbSimpleNoSignalsInterface::SetPropInt_Private(int32 InPropInt)
{
	Execute_SetPropInt(this, InPropInt);
};
