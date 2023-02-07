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

#include "Implementation/TbSimpleSimpleInterface.h"

UTbSimpleSimpleInterface::~UTbSimpleSimpleInterface() = default;

void UTbSimpleSimpleInterface::BroadcastSigBool_Implementation(bool bParamBool)
{
	SigBoolSignal.Broadcast(bParamBool);
}

FTbSimpleSimpleInterfaceSigBoolDelegate& UTbSimpleSimpleInterface::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
}

void UTbSimpleSimpleInterface::BroadcastSigInt_Implementation(int32 ParamInt)
{
	SigIntSignal.Broadcast(ParamInt);
}

FTbSimpleSimpleInterfaceSigIntDelegate& UTbSimpleSimpleInterface::GetSigIntSignalDelegate()
{
	return SigIntSignal;
}

void UTbSimpleSimpleInterface::BroadcastSigFloat_Implementation(float ParamFloat)
{
	SigFloatSignal.Broadcast(ParamFloat);
}

FTbSimpleSimpleInterfaceSigFloatDelegate& UTbSimpleSimpleInterface::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
}

void UTbSimpleSimpleInterface::BroadcastSigString_Implementation(const FString& ParamString)
{
	SigStringSignal.Broadcast(ParamString);
}

FTbSimpleSimpleInterfaceSigStringDelegate& UTbSimpleSimpleInterface::GetSigStringSignalDelegate()
{
	return SigStringSignal;
}

void UTbSimpleSimpleInterface::BroadcastPropBoolChanged_Implementation(bool bInPropBool)
{
	PropBoolChanged.Broadcast(bInPropBool);
}

bool UTbSimpleSimpleInterface::GetPropBool_Implementation() const
{
	return bPropBool;
}

void UTbSimpleSimpleInterface::SetPropBool_Implementation(bool bInPropBool)
{
	if (bPropBool != bInPropBool)
	{
		bPropBool = bInPropBool;
		Execute_BroadcastPropBoolChanged(this, bPropBool);
	}
}

FTbSimpleSimpleInterfacePropBoolChangedDelegate& UTbSimpleSimpleInterface::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
}

void UTbSimpleSimpleInterface::BroadcastPropIntChanged_Implementation(int32 InPropInt)
{
	PropIntChanged.Broadcast(InPropInt);
}

int32 UTbSimpleSimpleInterface::GetPropInt_Implementation() const
{
	return PropInt;
}

void UTbSimpleSimpleInterface::SetPropInt_Implementation(int32 InPropInt)
{
	if (PropInt != InPropInt)
	{
		PropInt = InPropInt;
		Execute_BroadcastPropIntChanged(this, PropInt);
	}
}

FTbSimpleSimpleInterfacePropIntChangedDelegate& UTbSimpleSimpleInterface::GetPropIntChangedDelegate()
{
	return PropIntChanged;
}

void UTbSimpleSimpleInterface::BroadcastPropFloatChanged_Implementation(float InPropFloat)
{
	PropFloatChanged.Broadcast(InPropFloat);
}

float UTbSimpleSimpleInterface::GetPropFloat_Implementation() const
{
	return PropFloat;
}

void UTbSimpleSimpleInterface::SetPropFloat_Implementation(float InPropFloat)
{
	if (PropFloat != InPropFloat)
	{
		PropFloat = InPropFloat;
		Execute_BroadcastPropFloatChanged(this, PropFloat);
	}
}

FTbSimpleSimpleInterfacePropFloatChangedDelegate& UTbSimpleSimpleInterface::GetPropFloatChangedDelegate()
{
	return PropFloatChanged;
}

void UTbSimpleSimpleInterface::BroadcastPropStringChanged_Implementation(const FString& InPropString)
{
	PropStringChanged.Broadcast(InPropString);
}

FString UTbSimpleSimpleInterface::GetPropString_Implementation() const
{
	return PropString;
}

void UTbSimpleSimpleInterface::SetPropString_Implementation(const FString& InPropString)
{
	if (PropString != InPropString)
	{
		PropString = InPropString;
		Execute_BroadcastPropStringChanged(this, PropString);
	}
}

FTbSimpleSimpleInterfacePropStringChangedDelegate& UTbSimpleSimpleInterface::GetPropStringChangedDelegate()
{
	return PropStringChanged;
}

bool UTbSimpleSimpleInterface::FuncBool_Implementation(bool bParamBool)
{
	(void)bParamBool;
	// do business logic here
	return false;
}

int32 UTbSimpleSimpleInterface::FuncInt_Implementation(int32 ParamInt)
{
	(void)ParamInt;
	// do business logic here
	return 0;
}

float UTbSimpleSimpleInterface::FuncFloat_Implementation(float ParamFloat)
{
	(void)ParamFloat;
	// do business logic here
	return 0.0f;
}

FString UTbSimpleSimpleInterface::FuncString_Implementation(const FString& ParamString)
{
	(void)ParamString;
	// do business logic here
	return FString();
}
