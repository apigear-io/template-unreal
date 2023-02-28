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
#include "TbSimpleSimpleArrayInterfaceInterface.h"

UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
FTbSimpleSimpleArrayInterfaceSigBoolDelegate& UAbstractTbSimpleSimpleArrayInterface::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
};

UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
FTbSimpleSimpleArrayInterfaceSigIntDelegate& UAbstractTbSimpleSimpleArrayInterface::GetSigIntSignalDelegate()
{
	return SigIntSignal;
};

UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
FTbSimpleSimpleArrayInterfaceSigInt32Delegate& UAbstractTbSimpleSimpleArrayInterface::GetSigInt32SignalDelegate()
{
	return SigInt32Signal;
};

UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
FTbSimpleSimpleArrayInterfaceSigInt64Delegate& UAbstractTbSimpleSimpleArrayInterface::GetSigInt64SignalDelegate()
{
	return SigInt64Signal;
};

UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
FTbSimpleSimpleArrayInterfaceSigFloatDelegate& UAbstractTbSimpleSimpleArrayInterface::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
};

UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
FTbSimpleSimpleArrayInterfaceSigFloat32Delegate& UAbstractTbSimpleSimpleArrayInterface::GetSigFloat32SignalDelegate()
{
	return SigFloat32Signal;
};

UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
FTbSimpleSimpleArrayInterfaceSigFloat64Delegate& UAbstractTbSimpleSimpleArrayInterface::GetSigFloat64SignalDelegate()
{
	return SigFloat64Signal;
};

UFUNCTION(Category = "ApiGear|TbSimple|SimpleArrayInterface")
FTbSimpleSimpleArrayInterfaceSigStringDelegate& UAbstractTbSimpleSimpleArrayInterface::GetSigStringSignalDelegate()
{
	return SigStringSignal;
};

FTbSimpleSimpleArrayInterfacePropBoolChangedDelegate& UAbstractTbSimpleSimpleArrayInterface::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
};

FTbSimpleSimpleArrayInterfacePropIntChangedDelegate& UAbstractTbSimpleSimpleArrayInterface::GetPropIntChangedDelegate()
{
	return PropIntChanged;
};

FTbSimpleSimpleArrayInterfacePropInt32ChangedDelegate& UAbstractTbSimpleSimpleArrayInterface::GetPropInt32ChangedDelegate()
{
	return PropInt32Changed;
};

FTbSimpleSimpleArrayInterfacePropInt64ChangedDelegate& UAbstractTbSimpleSimpleArrayInterface::GetPropInt64ChangedDelegate()
{
	return PropInt64Changed;
};

FTbSimpleSimpleArrayInterfacePropFloatChangedDelegate& UAbstractTbSimpleSimpleArrayInterface::GetPropFloatChangedDelegate()
{
	return PropFloatChanged;
};

FTbSimpleSimpleArrayInterfacePropFloat32ChangedDelegate& UAbstractTbSimpleSimpleArrayInterface::GetPropFloat32ChangedDelegate()
{
	return PropFloat32Changed;
};

FTbSimpleSimpleArrayInterfacePropFloat64ChangedDelegate& UAbstractTbSimpleSimpleArrayInterface::GetPropFloat64ChangedDelegate()
{
	return PropFloat64Changed;
};

FTbSimpleSimpleArrayInterfacePropStringChangedDelegate& UAbstractTbSimpleSimpleArrayInterface::GetPropStringChangedDelegate()
{
	return PropStringChanged;
};
void UAbstractTbSimpleSimpleArrayInterface::BroadcastSigBool_Implementation(const TArray<bool>& ParamBool)
{
	SigBoolSignal.Broadcast(ParamBool);
};

void UAbstractTbSimpleSimpleArrayInterface::BroadcastSigInt_Implementation(const TArray<int32>& ParamInt)
{
	SigIntSignal.Broadcast(ParamInt);
};

void UAbstractTbSimpleSimpleArrayInterface::BroadcastSigInt32_Implementation(const TArray<int32>& ParamInt32)
{
	SigInt32Signal.Broadcast(ParamInt32);
};

void UAbstractTbSimpleSimpleArrayInterface::BroadcastSigInt64_Implementation(const TArray<int64>& ParamInt64)
{
	SigInt64Signal.Broadcast(ParamInt64);
};

void UAbstractTbSimpleSimpleArrayInterface::BroadcastSigFloat_Implementation(const TArray<float>& ParamFloat)
{
	SigFloatSignal.Broadcast(ParamFloat);
};

void UAbstractTbSimpleSimpleArrayInterface::BroadcastSigFloat32_Implementation(const TArray<float>& ParamFloa32)
{
	SigFloat32Signal.Broadcast(ParamFloa32);
};

void UAbstractTbSimpleSimpleArrayInterface::BroadcastSigFloat64_Implementation(const TArray<double>& ParamFloat64)
{
	SigFloat64Signal.Broadcast(ParamFloat64);
};

void UAbstractTbSimpleSimpleArrayInterface::BroadcastSigString_Implementation(const TArray<FString>& ParamString)
{
	SigStringSignal.Broadcast(ParamString);
};

void UAbstractTbSimpleSimpleArrayInterface::BroadcastPropBoolChanged_Implementation(const TArray<bool>& InPropBool)
{
	PropBoolChanged.Broadcast(InPropBool);
}

void UAbstractTbSimpleSimpleArrayInterface::BroadcastPropIntChanged_Implementation(const TArray<int32>& InPropInt)
{
	PropIntChanged.Broadcast(InPropInt);
}

void UAbstractTbSimpleSimpleArrayInterface::BroadcastPropInt32Changed_Implementation(const TArray<int32>& InPropInt32)
{
	PropInt32Changed.Broadcast(InPropInt32);
}

void UAbstractTbSimpleSimpleArrayInterface::BroadcastPropInt64Changed_Implementation(const TArray<int64>& InPropInt64)
{
	PropInt64Changed.Broadcast(InPropInt64);
}

void UAbstractTbSimpleSimpleArrayInterface::BroadcastPropFloatChanged_Implementation(const TArray<float>& InPropFloat)
{
	PropFloatChanged.Broadcast(InPropFloat);
}

void UAbstractTbSimpleSimpleArrayInterface::BroadcastPropFloat32Changed_Implementation(const TArray<float>& InPropFloat32)
{
	PropFloat32Changed.Broadcast(InPropFloat32);
}

void UAbstractTbSimpleSimpleArrayInterface::BroadcastPropFloat64Changed_Implementation(const TArray<double>& InPropFloat64)
{
	PropFloat64Changed.Broadcast(InPropFloat64);
}

void UAbstractTbSimpleSimpleArrayInterface::BroadcastPropStringChanged_Implementation(const TArray<FString>& InPropString)
{
	PropStringChanged.Broadcast(InPropString);
}
TArray<bool> UAbstractTbSimpleSimpleArrayInterface::GetPropBool_Private() const
{
	return Execute_GetPropBool(this);
};

void UAbstractTbSimpleSimpleArrayInterface::SetPropBool_Private(const TArray<bool>& InPropBool)
{
	Execute_SetPropBool(this, InPropBool);
};

TArray<int32> UAbstractTbSimpleSimpleArrayInterface::GetPropInt_Private() const
{
	return Execute_GetPropInt(this);
};

void UAbstractTbSimpleSimpleArrayInterface::SetPropInt_Private(const TArray<int32>& InPropInt)
{
	Execute_SetPropInt(this, InPropInt);
};

TArray<int32> UAbstractTbSimpleSimpleArrayInterface::GetPropInt32_Private() const
{
	return Execute_GetPropInt32(this);
};

void UAbstractTbSimpleSimpleArrayInterface::SetPropInt32_Private(const TArray<int32>& InPropInt32)
{
	Execute_SetPropInt32(this, InPropInt32);
};

TArray<int64> UAbstractTbSimpleSimpleArrayInterface::GetPropInt64_Private() const
{
	return Execute_GetPropInt64(this);
};

void UAbstractTbSimpleSimpleArrayInterface::SetPropInt64_Private(const TArray<int64>& InPropInt64)
{
	Execute_SetPropInt64(this, InPropInt64);
};

TArray<float> UAbstractTbSimpleSimpleArrayInterface::GetPropFloat_Private() const
{
	return Execute_GetPropFloat(this);
};

void UAbstractTbSimpleSimpleArrayInterface::SetPropFloat_Private(const TArray<float>& InPropFloat)
{
	Execute_SetPropFloat(this, InPropFloat);
};

TArray<float> UAbstractTbSimpleSimpleArrayInterface::GetPropFloat32_Private() const
{
	return Execute_GetPropFloat32(this);
};

void UAbstractTbSimpleSimpleArrayInterface::SetPropFloat32_Private(const TArray<float>& InPropFloat32)
{
	Execute_SetPropFloat32(this, InPropFloat32);
};

TArray<double> UAbstractTbSimpleSimpleArrayInterface::GetPropFloat64_Private() const
{
	return Execute_GetPropFloat64(this);
};

void UAbstractTbSimpleSimpleArrayInterface::SetPropFloat64_Private(const TArray<double>& InPropFloat64)
{
	Execute_SetPropFloat64(this, InPropFloat64);
};

TArray<FString> UAbstractTbSimpleSimpleArrayInterface::GetPropString_Private() const
{
	return Execute_GetPropString(this);
};

void UAbstractTbSimpleSimpleArrayInterface::SetPropString_Private(const TArray<FString>& InPropString)
{
	Execute_SetPropString(this, InPropString);
};
