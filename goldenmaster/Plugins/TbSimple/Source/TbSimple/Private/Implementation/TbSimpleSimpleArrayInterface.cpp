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

#include "Implementation/TbSimpleSimpleArrayInterface.h"

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

void UTbSimpleSimpleArrayInterface::BroadcastSigInt32_Implementation(const TArray<int32>& ParamInt32)
{
	SigInt32Signal.Broadcast(ParamInt32);
}

FTbSimpleSimpleArrayInterfaceSigInt32Delegate& UTbSimpleSimpleArrayInterface::GetSigInt32SignalDelegate()
{
	return SigInt32Signal;
}

void UTbSimpleSimpleArrayInterface::BroadcastSigInt64_Implementation(const TArray<int64>& ParamInt64)
{
	SigInt64Signal.Broadcast(ParamInt64);
}

FTbSimpleSimpleArrayInterfaceSigInt64Delegate& UTbSimpleSimpleArrayInterface::GetSigInt64SignalDelegate()
{
	return SigInt64Signal;
}

void UTbSimpleSimpleArrayInterface::BroadcastSigFloat_Implementation(const TArray<float>& ParamFloat)
{
	SigFloatSignal.Broadcast(ParamFloat);
}

FTbSimpleSimpleArrayInterfaceSigFloatDelegate& UTbSimpleSimpleArrayInterface::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
}

void UTbSimpleSimpleArrayInterface::BroadcastSigFloat32_Implementation(const TArray<float>& ParamFloa32)
{
	SigFloat32Signal.Broadcast(ParamFloa32);
}

FTbSimpleSimpleArrayInterfaceSigFloat32Delegate& UTbSimpleSimpleArrayInterface::GetSigFloat32SignalDelegate()
{
	return SigFloat32Signal;
}

void UTbSimpleSimpleArrayInterface::BroadcastSigFloat64_Implementation(const TArray<double>& ParamFloat64)
{
	SigFloat64Signal.Broadcast(ParamFloat64);
}

FTbSimpleSimpleArrayInterfaceSigFloat64Delegate& UTbSimpleSimpleArrayInterface::GetSigFloat64SignalDelegate()
{
	return SigFloat64Signal;
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

void UTbSimpleSimpleArrayInterface::BroadcastPropInt32Changed_Implementation(const TArray<int32>& InPropInt32)
{
	PropInt32Changed.Broadcast(InPropInt32);
}

TArray<int32> UTbSimpleSimpleArrayInterface::GetPropInt32_Implementation() const
{
	return PropInt32;
}

void UTbSimpleSimpleArrayInterface::SetPropInt32_Implementation(const TArray<int32>& InPropInt32)
{
	if (PropInt32 != InPropInt32)
	{
		PropInt32 = InPropInt32;
		Execute_BroadcastPropInt32Changed(this, PropInt32);
	}
}

FTbSimpleSimpleArrayInterfacePropInt32ChangedDelegate& UTbSimpleSimpleArrayInterface::GetPropInt32ChangedDelegate()
{
	return PropInt32Changed;
}

void UTbSimpleSimpleArrayInterface::BroadcastPropInt64Changed_Implementation(const TArray<int64>& InPropInt64)
{
	PropInt64Changed.Broadcast(InPropInt64);
}

TArray<int64> UTbSimpleSimpleArrayInterface::GetPropInt64_Implementation() const
{
	return PropInt64;
}

void UTbSimpleSimpleArrayInterface::SetPropInt64_Implementation(const TArray<int64>& InPropInt64)
{
	if (PropInt64 != InPropInt64)
	{
		PropInt64 = InPropInt64;
		Execute_BroadcastPropInt64Changed(this, PropInt64);
	}
}

FTbSimpleSimpleArrayInterfacePropInt64ChangedDelegate& UTbSimpleSimpleArrayInterface::GetPropInt64ChangedDelegate()
{
	return PropInt64Changed;
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

void UTbSimpleSimpleArrayInterface::BroadcastPropFloat32Changed_Implementation(const TArray<float>& InPropFloat32)
{
	PropFloat32Changed.Broadcast(InPropFloat32);
}

TArray<float> UTbSimpleSimpleArrayInterface::GetPropFloat32_Implementation() const
{
	return PropFloat32;
}

void UTbSimpleSimpleArrayInterface::SetPropFloat32_Implementation(const TArray<float>& InPropFloat32)
{
	if (PropFloat32 != InPropFloat32)
	{
		PropFloat32 = InPropFloat32;
		Execute_BroadcastPropFloat32Changed(this, PropFloat32);
	}
}

FTbSimpleSimpleArrayInterfacePropFloat32ChangedDelegate& UTbSimpleSimpleArrayInterface::GetPropFloat32ChangedDelegate()
{
	return PropFloat32Changed;
}

void UTbSimpleSimpleArrayInterface::BroadcastPropFloat64Changed_Implementation(const TArray<double>& InPropFloat64)
{
	PropFloat64Changed.Broadcast(InPropFloat64);
}

TArray<double> UTbSimpleSimpleArrayInterface::GetPropFloat64_Implementation() const
{
	return PropFloat64;
}

void UTbSimpleSimpleArrayInterface::SetPropFloat64_Implementation(const TArray<double>& InPropFloat64)
{
	if (PropFloat64 != InPropFloat64)
	{
		PropFloat64 = InPropFloat64;
		Execute_BroadcastPropFloat64Changed(this, PropFloat64);
	}
}

FTbSimpleSimpleArrayInterfacePropFloat64ChangedDelegate& UTbSimpleSimpleArrayInterface::GetPropFloat64ChangedDelegate()
{
	return PropFloat64Changed;
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

TArray<int32> UTbSimpleSimpleArrayInterface::FuncInt32_Implementation(const TArray<int32>& ParamInt32)
{
	(void)ParamInt32;
	// do business logic here
	return TArray<int32>();
}

TArray<int64> UTbSimpleSimpleArrayInterface::FuncInt64_Implementation(const TArray<int64>& ParamInt64)
{
	(void)ParamInt64;
	// do business logic here
	return TArray<int64>();
}

TArray<float> UTbSimpleSimpleArrayInterface::FuncFloat_Implementation(const TArray<float>& ParamFloat)
{
	(void)ParamFloat;
	// do business logic here
	return TArray<float>();
}

TArray<float> UTbSimpleSimpleArrayInterface::FuncFloat32_Implementation(const TArray<float>& ParamFloat32)
{
	(void)ParamFloat32;
	// do business logic here
	return TArray<float>();
}

TArray<double> UTbSimpleSimpleArrayInterface::FuncFloat64_Implementation(const TArray<double>& ParamFloat)
{
	(void)ParamFloat;
	// do business logic here
	return TArray<double>();
}

TArray<FString> UTbSimpleSimpleArrayInterface::FuncString_Implementation(const TArray<FString>& ParamString)
{
	(void)ParamString;
	// do business logic here
	return TArray<FString>();
}
