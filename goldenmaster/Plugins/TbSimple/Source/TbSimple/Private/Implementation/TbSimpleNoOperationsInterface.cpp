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

#include "Implementation/TbSimpleNoOperationsInterface.h"

UTbSimpleNoOperationsInterface::~UTbSimpleNoOperationsInterface() = default;

void UTbSimpleNoOperationsInterface::BroadcastSigVoid_Implementation()
{
	SigVoidSignal.Broadcast();
}

FTbSimpleNoOperationsInterfaceSigVoidDelegate& UTbSimpleNoOperationsInterface::GetSigVoidSignalDelegate()
{
	return SigVoidSignal;
}

void UTbSimpleNoOperationsInterface::BroadcastSigBool_Implementation(bool bParamBool)
{
	SigBoolSignal.Broadcast(bParamBool);
}

FTbSimpleNoOperationsInterfaceSigBoolDelegate& UTbSimpleNoOperationsInterface::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
}

void UTbSimpleNoOperationsInterface::BroadcastPropBoolChanged_Implementation(bool bInPropBool)
{
	PropBoolChanged.Broadcast(bInPropBool);
}

bool UTbSimpleNoOperationsInterface::GetPropBool_Implementation() const
{
	return bPropBool;
}

void UTbSimpleNoOperationsInterface::SetPropBool_Implementation(bool bInPropBool)
{
	if (bPropBool != bInPropBool)
	{
		bPropBool = bInPropBool;
		Execute_BroadcastPropBoolChanged(this, bPropBool);
	}
}

FTbSimpleNoOperationsInterfacePropBoolChangedDelegate& UTbSimpleNoOperationsInterface::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
}

void UTbSimpleNoOperationsInterface::BroadcastPropIntChanged_Implementation(int32 InPropInt)
{
	PropIntChanged.Broadcast(InPropInt);
}

int32 UTbSimpleNoOperationsInterface::GetPropInt_Implementation() const
{
	return PropInt;
}

void UTbSimpleNoOperationsInterface::SetPropInt_Implementation(int32 InPropInt)
{
	if (PropInt != InPropInt)
	{
		PropInt = InPropInt;
		Execute_BroadcastPropIntChanged(this, PropInt);
	}
}

FTbSimpleNoOperationsInterfacePropIntChangedDelegate& UTbSimpleNoOperationsInterface::GetPropIntChangedDelegate()
{
	return PropIntChanged;
}
