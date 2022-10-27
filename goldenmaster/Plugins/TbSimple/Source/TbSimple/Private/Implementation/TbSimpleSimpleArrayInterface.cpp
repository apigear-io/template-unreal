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

#include "TbSimpleSimpleArrayInterface.h"

UTbSimpleSimpleArrayInterface::~UTbSimpleSimpleArrayInterface() = default;

void UTbSimpleSimpleArrayInterface::BroadcastSigBool_Implementation(const TArray<bool>& ParamBool)
{
	SigBoolSignal.Broadcast(ParamBool);
}

FTbSimpleSimpleArrayInterfaceSigBoolDelegate& UTbSimpleSimpleArrayInterface::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
}

void UTbSimpleSimpleArrayInterface::BroadcastSigInt_Implementation(const TArray<int32>& ParamInt)
{
	SigIntSignal.Broadcast(ParamInt);
}

FTbSimpleSimpleArrayInterfaceSigIntDelegate& UTbSimpleSimpleArrayInterface::GetSigIntSignalDelegate()
{
	return SigIntSignal;
}

void UTbSimpleSimpleArrayInterface::BroadcastSigFloat_Implementation(const TArray<float>& ParamFloat)
{
	SigFloatSignal.Broadcast(ParamFloat);
}

FTbSimpleSimpleArrayInterfaceSigFloatDelegate& UTbSimpleSimpleArrayInterface::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
}

void UTbSimpleSimpleArrayInterface::BroadcastSigString_Implementation(const TArray<FString>& ParamString)
{
	SigStringSignal.Broadcast(ParamString);
}

FTbSimpleSimpleArrayInterfaceSigStringDelegate& UTbSimpleSimpleArrayInterface::GetSigStringSignalDelegate()
{
	return SigStringSignal;
}

void UTbSimpleSimpleArrayInterface::BroadcastPropBoolChanged_Implementation(const TArray<bool>& InPropBool)
{
	PropBoolChanged.Broadcast(InPropBool);
}

TArray<bool> UTbSimpleSimpleArrayInterface::GetPropBool_Implementation() const
{
	return PropBool;
}

void UTbSimpleSimpleArrayInterface::SetPropBool_Implementation(const TArray<bool>& InPropBool)
{
	if (PropBool != InPropBool)
	{
		PropBool = InPropBool;
		Execute_BroadcastPropBoolChanged(this, PropBool);
	}
}

FTbSimpleSimpleArrayInterfacePropBoolChangedDelegate& UTbSimpleSimpleArrayInterface::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
}

void UTbSimpleSimpleArrayInterface::BroadcastPropIntChanged_Implementation(const TArray<int32>& InPropInt)
{
	PropIntChanged.Broadcast(InPropInt);
}

TArray<int32> UTbSimpleSimpleArrayInterface::GetPropInt_Implementation() const
{
	return PropInt;
}

void UTbSimpleSimpleArrayInterface::SetPropInt_Implementation(const TArray<int32>& InPropInt)
{
	if (PropInt != InPropInt)
	{
		PropInt = InPropInt;
		Execute_BroadcastPropIntChanged(this, PropInt);
	}
}

FTbSimpleSimpleArrayInterfacePropIntChangedDelegate& UTbSimpleSimpleArrayInterface::GetPropIntChangedDelegate()
{
	return PropIntChanged;
}

void UTbSimpleSimpleArrayInterface::BroadcastPropFloatChanged_Implementation(const TArray<float>& InPropFloat)
{
	PropFloatChanged.Broadcast(InPropFloat);
}

TArray<float> UTbSimpleSimpleArrayInterface::GetPropFloat_Implementation() const
{
	return PropFloat;
}

void UTbSimpleSimpleArrayInterface::SetPropFloat_Implementation(const TArray<float>& InPropFloat)
{
	if (PropFloat != InPropFloat)
	{
		PropFloat = InPropFloat;
		Execute_BroadcastPropFloatChanged(this, PropFloat);
	}
}

FTbSimpleSimpleArrayInterfacePropFloatChangedDelegate& UTbSimpleSimpleArrayInterface::GetPropFloatChangedDelegate()
{
	return PropFloatChanged;
}

void UTbSimpleSimpleArrayInterface::BroadcastPropStringChanged_Implementation(const TArray<FString>& InPropString)
{
	PropStringChanged.Broadcast(InPropString);
}

TArray<FString> UTbSimpleSimpleArrayInterface::GetPropString_Implementation() const
{
	return PropString;
}

void UTbSimpleSimpleArrayInterface::SetPropString_Implementation(const TArray<FString>& InPropString)
{
	if (PropString != InPropString)
	{
		PropString = InPropString;
		Execute_BroadcastPropStringChanged(this, PropString);
	}
}

FTbSimpleSimpleArrayInterfacePropStringChangedDelegate& UTbSimpleSimpleArrayInterface::GetPropStringChangedDelegate()
{
	return PropStringChanged;
}

TArray<bool> UTbSimpleSimpleArrayInterface::FuncBool_Implementation(const TArray<bool>& ParamBool)
{
	(void)ParamBool;
	// do business logic here
	return TArray<bool>();
}

TArray<int32> UTbSimpleSimpleArrayInterface::FuncInt_Implementation(const TArray<int32>& ParamInt)
{
	(void)ParamInt;
	// do business logic here
	return TArray<int32>();
}

TArray<float> UTbSimpleSimpleArrayInterface::FuncFloat_Implementation(const TArray<float>& ParamFloat)
{
	(void)ParamFloat;
	// do business logic here
	return TArray<float>();
}

TArray<FString> UTbSimpleSimpleArrayInterface::FuncString_Implementation(const TArray<FString>& ParamString)
{
	(void)ParamString;
	// do business logic here
	return TArray<FString>();
}
