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
#include "TbSimpleSimpleInterfaceInterface.h"

UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface")
FTbSimpleSimpleInterfaceSigVoidDelegate& UAbstractTbSimpleSimpleInterface::GetSigVoidSignalDelegate()
{
	return SigVoidSignal;
};

UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface")
FTbSimpleSimpleInterfaceSigBoolDelegate& UAbstractTbSimpleSimpleInterface::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
};

UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface")
FTbSimpleSimpleInterfaceSigIntDelegate& UAbstractTbSimpleSimpleInterface::GetSigIntSignalDelegate()
{
	return SigIntSignal;
};

UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface")
FTbSimpleSimpleInterfaceSigInt32Delegate& UAbstractTbSimpleSimpleInterface::GetSigInt32SignalDelegate()
{
	return SigInt32Signal;
};

UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface")
FTbSimpleSimpleInterfaceSigInt64Delegate& UAbstractTbSimpleSimpleInterface::GetSigInt64SignalDelegate()
{
	return SigInt64Signal;
};

UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface")
FTbSimpleSimpleInterfaceSigFloatDelegate& UAbstractTbSimpleSimpleInterface::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
};

UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface")
FTbSimpleSimpleInterfaceSigFloat32Delegate& UAbstractTbSimpleSimpleInterface::GetSigFloat32SignalDelegate()
{
	return SigFloat32Signal;
};

UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface")
FTbSimpleSimpleInterfaceSigFloat64Delegate& UAbstractTbSimpleSimpleInterface::GetSigFloat64SignalDelegate()
{
	return SigFloat64Signal;
};

UFUNCTION(Category = "ApiGear|TbSimple|SimpleInterface")
FTbSimpleSimpleInterfaceSigStringDelegate& UAbstractTbSimpleSimpleInterface::GetSigStringSignalDelegate()
{
	return SigStringSignal;
};

FTbSimpleSimpleInterfacePropBoolChangedDelegate& UAbstractTbSimpleSimpleInterface::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
};

FTbSimpleSimpleInterfacePropIntChangedDelegate& UAbstractTbSimpleSimpleInterface::GetPropIntChangedDelegate()
{
	return PropIntChanged;
};

FTbSimpleSimpleInterfacePropInt32ChangedDelegate& UAbstractTbSimpleSimpleInterface::GetPropInt32ChangedDelegate()
{
	return PropInt32Changed;
};

FTbSimpleSimpleInterfacePropInt64ChangedDelegate& UAbstractTbSimpleSimpleInterface::GetPropInt64ChangedDelegate()
{
	return PropInt64Changed;
};

FTbSimpleSimpleInterfacePropFloatChangedDelegate& UAbstractTbSimpleSimpleInterface::GetPropFloatChangedDelegate()
{
	return PropFloatChanged;
};

FTbSimpleSimpleInterfacePropFloat32ChangedDelegate& UAbstractTbSimpleSimpleInterface::GetPropFloat32ChangedDelegate()
{
	return PropFloat32Changed;
};

FTbSimpleSimpleInterfacePropFloat64ChangedDelegate& UAbstractTbSimpleSimpleInterface::GetPropFloat64ChangedDelegate()
{
	return PropFloat64Changed;
};

FTbSimpleSimpleInterfacePropStringChangedDelegate& UAbstractTbSimpleSimpleInterface::GetPropStringChangedDelegate()
{
	return PropStringChanged;
};
void UAbstractTbSimpleSimpleInterface::BroadcastSigVoid_Implementation()
{
	SigVoidSignal.Broadcast();
};

void UAbstractTbSimpleSimpleInterface::BroadcastSigBool_Implementation(bool bParamBool)
{
	SigBoolSignal.Broadcast(bParamBool);
};

void UAbstractTbSimpleSimpleInterface::BroadcastSigInt_Implementation(int32 ParamInt)
{
	SigIntSignal.Broadcast(ParamInt);
};

void UAbstractTbSimpleSimpleInterface::BroadcastSigInt32_Implementation(int32 ParamInt32)
{
	SigInt32Signal.Broadcast(ParamInt32);
};

void UAbstractTbSimpleSimpleInterface::BroadcastSigInt64_Implementation(int64 ParamInt64)
{
	SigInt64Signal.Broadcast(ParamInt64);
};

void UAbstractTbSimpleSimpleInterface::BroadcastSigFloat_Implementation(float ParamFloat)
{
	SigFloatSignal.Broadcast(ParamFloat);
};

void UAbstractTbSimpleSimpleInterface::BroadcastSigFloat32_Implementation(float ParamFloa32)
{
	SigFloat32Signal.Broadcast(ParamFloa32);
};

void UAbstractTbSimpleSimpleInterface::BroadcastSigFloat64_Implementation(double ParamFloat64)
{
	SigFloat64Signal.Broadcast(ParamFloat64);
};

void UAbstractTbSimpleSimpleInterface::BroadcastSigString_Implementation(const FString& ParamString)
{
	SigStringSignal.Broadcast(ParamString);
};

void UAbstractTbSimpleSimpleInterface::BroadcastPropBoolChanged_Implementation(bool bInPropBool)
{
	PropBoolChanged.Broadcast(bInPropBool);
}

void UAbstractTbSimpleSimpleInterface::BroadcastPropIntChanged_Implementation(int32 InPropInt)
{
	PropIntChanged.Broadcast(InPropInt);
}

void UAbstractTbSimpleSimpleInterface::BroadcastPropInt32Changed_Implementation(int32 InPropInt32)
{
	PropInt32Changed.Broadcast(InPropInt32);
}

void UAbstractTbSimpleSimpleInterface::BroadcastPropInt64Changed_Implementation(int64 InPropInt64)
{
	PropInt64Changed.Broadcast(InPropInt64);
}

void UAbstractTbSimpleSimpleInterface::BroadcastPropFloatChanged_Implementation(float InPropFloat)
{
	PropFloatChanged.Broadcast(InPropFloat);
}

void UAbstractTbSimpleSimpleInterface::BroadcastPropFloat32Changed_Implementation(float InPropFloat32)
{
	PropFloat32Changed.Broadcast(InPropFloat32);
}

void UAbstractTbSimpleSimpleInterface::BroadcastPropFloat64Changed_Implementation(double InPropFloat64)
{
	PropFloat64Changed.Broadcast(InPropFloat64);
}

void UAbstractTbSimpleSimpleInterface::BroadcastPropStringChanged_Implementation(const FString& InPropString)
{
	PropStringChanged.Broadcast(InPropString);
}
bool UAbstractTbSimpleSimpleInterface::GetPropBool_Private() const
{
	return Execute_GetPropBool(this);
};

void UAbstractTbSimpleSimpleInterface::SetPropBool_Private(bool bInPropBool)
{
	Execute_SetPropBool(this, bInPropBool);
};

int32 UAbstractTbSimpleSimpleInterface::GetPropInt_Private() const
{
	return Execute_GetPropInt(this);
};

void UAbstractTbSimpleSimpleInterface::SetPropInt_Private(int32 InPropInt)
{
	Execute_SetPropInt(this, InPropInt);
};

int32 UAbstractTbSimpleSimpleInterface::GetPropInt32_Private() const
{
	return Execute_GetPropInt32(this);
};

void UAbstractTbSimpleSimpleInterface::SetPropInt32_Private(int32 InPropInt32)
{
	Execute_SetPropInt32(this, InPropInt32);
};

int64 UAbstractTbSimpleSimpleInterface::GetPropInt64_Private() const
{
	return Execute_GetPropInt64(this);
};

void UAbstractTbSimpleSimpleInterface::SetPropInt64_Private(int64 InPropInt64)
{
	Execute_SetPropInt64(this, InPropInt64);
};

float UAbstractTbSimpleSimpleInterface::GetPropFloat_Private() const
{
	return Execute_GetPropFloat(this);
};

void UAbstractTbSimpleSimpleInterface::SetPropFloat_Private(float InPropFloat)
{
	Execute_SetPropFloat(this, InPropFloat);
};

float UAbstractTbSimpleSimpleInterface::GetPropFloat32_Private() const
{
	return Execute_GetPropFloat32(this);
};

void UAbstractTbSimpleSimpleInterface::SetPropFloat32_Private(float InPropFloat32)
{
	Execute_SetPropFloat32(this, InPropFloat32);
};

double UAbstractTbSimpleSimpleInterface::GetPropFloat64_Private() const
{
	return Execute_GetPropFloat64(this);
};

void UAbstractTbSimpleSimpleInterface::SetPropFloat64_Private(double InPropFloat64)
{
	Execute_SetPropFloat64(this, InPropFloat64);
};

FString UAbstractTbSimpleSimpleInterface::GetPropString_Private() const
{
	return Execute_GetPropString(this);
};

void UAbstractTbSimpleSimpleInterface::SetPropString_Private(const FString& InPropString)
{
	Execute_SetPropString(this, InPropString);
};

void UAbstractTbSimpleSimpleInterface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTbSimpleSimpleInterface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	Super::Deinitialize();
}

bool UAbstractTbSimpleSimpleInterface::IsInitialized() const
{
	return bInitialized;
}
