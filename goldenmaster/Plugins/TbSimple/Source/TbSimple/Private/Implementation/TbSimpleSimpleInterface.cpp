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

void UTbSimpleSimpleInterface::BroadcastSigVoid_Implementation()
{
	SigVoidSignal.Broadcast();
}

FTbSimpleSimpleInterfaceSigVoidDelegate& UTbSimpleSimpleInterface::GetSigVoidSignalDelegate()
{
	return SigVoidSignal;
}

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

void UTbSimpleSimpleInterface::BroadcastSigInt32_Implementation(int32 ParamInt32)
{
	SigInt32Signal.Broadcast(ParamInt32);
}

FTbSimpleSimpleInterfaceSigInt32Delegate& UTbSimpleSimpleInterface::GetSigInt32SignalDelegate()
{
	return SigInt32Signal;
}

void UTbSimpleSimpleInterface::BroadcastSigInt64_Implementation(int64 ParamInt64)
{
	SigInt64Signal.Broadcast(ParamInt64);
}

FTbSimpleSimpleInterfaceSigInt64Delegate& UTbSimpleSimpleInterface::GetSigInt64SignalDelegate()
{
	return SigInt64Signal;
}

void UTbSimpleSimpleInterface::BroadcastSigFloat_Implementation(float ParamFloat)
{
	SigFloatSignal.Broadcast(ParamFloat);
}

FTbSimpleSimpleInterfaceSigFloatDelegate& UTbSimpleSimpleInterface::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
}

void UTbSimpleSimpleInterface::BroadcastSigFloat32_Implementation(float ParamFloa32)
{
	SigFloat32Signal.Broadcast(ParamFloa32);
}

FTbSimpleSimpleInterfaceSigFloat32Delegate& UTbSimpleSimpleInterface::GetSigFloat32SignalDelegate()
{
	return SigFloat32Signal;
}

void UTbSimpleSimpleInterface::BroadcastSigFloat64_Implementation(double ParamFloat64)
{
	SigFloat64Signal.Broadcast(ParamFloat64);
}

FTbSimpleSimpleInterfaceSigFloat64Delegate& UTbSimpleSimpleInterface::GetSigFloat64SignalDelegate()
{
	return SigFloat64Signal;
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

void UTbSimpleSimpleInterface::BroadcastPropInt32Changed_Implementation(int32 InPropInt32)
{
	PropInt32Changed.Broadcast(InPropInt32);
}

int32 UTbSimpleSimpleInterface::GetPropInt32_Implementation() const
{
	return PropInt32;
}

void UTbSimpleSimpleInterface::SetPropInt32_Implementation(int32 InPropInt32)
{
	if (PropInt32 != InPropInt32)
	{
		PropInt32 = InPropInt32;
		Execute_BroadcastPropInt32Changed(this, PropInt32);
	}
}

FTbSimpleSimpleInterfacePropInt32ChangedDelegate& UTbSimpleSimpleInterface::GetPropInt32ChangedDelegate()
{
	return PropInt32Changed;
}

void UTbSimpleSimpleInterface::BroadcastPropInt64Changed_Implementation(int64 InPropInt64)
{
	PropInt64Changed.Broadcast(InPropInt64);
}

int64 UTbSimpleSimpleInterface::GetPropInt64_Implementation() const
{
	return PropInt64;
}

void UTbSimpleSimpleInterface::SetPropInt64_Implementation(int64 InPropInt64)
{
	if (PropInt64 != InPropInt64)
	{
		PropInt64 = InPropInt64;
		Execute_BroadcastPropInt64Changed(this, PropInt64);
	}
}

FTbSimpleSimpleInterfacePropInt64ChangedDelegate& UTbSimpleSimpleInterface::GetPropInt64ChangedDelegate()
{
	return PropInt64Changed;
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

void UTbSimpleSimpleInterface::BroadcastPropFloat32Changed_Implementation(float InPropFloat32)
{
	PropFloat32Changed.Broadcast(InPropFloat32);
}

float UTbSimpleSimpleInterface::GetPropFloat32_Implementation() const
{
	return PropFloat32;
}

void UTbSimpleSimpleInterface::SetPropFloat32_Implementation(float InPropFloat32)
{
	if (PropFloat32 != InPropFloat32)
	{
		PropFloat32 = InPropFloat32;
		Execute_BroadcastPropFloat32Changed(this, PropFloat32);
	}
}

FTbSimpleSimpleInterfacePropFloat32ChangedDelegate& UTbSimpleSimpleInterface::GetPropFloat32ChangedDelegate()
{
	return PropFloat32Changed;
}

void UTbSimpleSimpleInterface::BroadcastPropFloat64Changed_Implementation(double InPropFloat64)
{
	PropFloat64Changed.Broadcast(InPropFloat64);
}

double UTbSimpleSimpleInterface::GetPropFloat64_Implementation() const
{
	return PropFloat64;
}

void UTbSimpleSimpleInterface::SetPropFloat64_Implementation(double InPropFloat64)
{
	if (PropFloat64 != InPropFloat64)
	{
		PropFloat64 = InPropFloat64;
		Execute_BroadcastPropFloat64Changed(this, PropFloat64);
	}
}

FTbSimpleSimpleInterfacePropFloat64ChangedDelegate& UTbSimpleSimpleInterface::GetPropFloat64ChangedDelegate()
{
	return PropFloat64Changed;
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

void UTbSimpleSimpleInterface::FuncVoid_Implementation()
{
	// do business logic here
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

int32 UTbSimpleSimpleInterface::FuncInt32_Implementation(int32 ParamInt32)
{
	(void)ParamInt32;
	// do business logic here
	return 0;
}

int64 UTbSimpleSimpleInterface::FuncInt64_Implementation(int64 ParamInt64)
{
	(void)ParamInt64;
	// do business logic here
	return 0LL;
}

float UTbSimpleSimpleInterface::FuncFloat_Implementation(float ParamFloat)
{
	(void)ParamFloat;
	// do business logic here
	return 0.0f;
}

float UTbSimpleSimpleInterface::FuncFloat32_Implementation(float ParamFloat32)
{
	(void)ParamFloat32;
	// do business logic here
	return 0.0f;
}

double UTbSimpleSimpleInterface::FuncFloat64_Implementation(double ParamFloat)
{
	(void)ParamFloat;
	// do business logic here
	return 0.0;
}

FString UTbSimpleSimpleInterface::FuncString_Implementation(const FString& ParamString)
{
	(void)ParamString;
	// do business logic here
	return FString();
}
