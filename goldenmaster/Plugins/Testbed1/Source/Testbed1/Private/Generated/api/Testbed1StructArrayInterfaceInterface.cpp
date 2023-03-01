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
#include "Testbed1StructArrayInterfaceInterface.h"

UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface")
FTestbed1StructArrayInterfaceSigBoolDelegate& UAbstractTestbed1StructArrayInterface::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
};

UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface")
FTestbed1StructArrayInterfaceSigIntDelegate& UAbstractTestbed1StructArrayInterface::GetSigIntSignalDelegate()
{
	return SigIntSignal;
};

UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface")
FTestbed1StructArrayInterfaceSigFloatDelegate& UAbstractTestbed1StructArrayInterface::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
};

UFUNCTION(Category = "ApiGear|Testbed1|StructArrayInterface")
FTestbed1StructArrayInterfaceSigStringDelegate& UAbstractTestbed1StructArrayInterface::GetSigStringSignalDelegate()
{
	return SigStringSignal;
};

FTestbed1StructArrayInterfacePropBoolChangedDelegate& UAbstractTestbed1StructArrayInterface::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
};

FTestbed1StructArrayInterfacePropIntChangedDelegate& UAbstractTestbed1StructArrayInterface::GetPropIntChangedDelegate()
{
	return PropIntChanged;
};

FTestbed1StructArrayInterfacePropFloatChangedDelegate& UAbstractTestbed1StructArrayInterface::GetPropFloatChangedDelegate()
{
	return PropFloatChanged;
};

FTestbed1StructArrayInterfacePropStringChangedDelegate& UAbstractTestbed1StructArrayInterface::GetPropStringChangedDelegate()
{
	return PropStringChanged;
};
void UAbstractTestbed1StructArrayInterface::BroadcastSigBool_Implementation(const TArray<FTestbed1StructBool>& ParamBool)
{
	SigBoolSignal.Broadcast(ParamBool);
};

void UAbstractTestbed1StructArrayInterface::BroadcastSigInt_Implementation(const TArray<FTestbed1StructInt>& ParamInt)
{
	SigIntSignal.Broadcast(ParamInt);
};

void UAbstractTestbed1StructArrayInterface::BroadcastSigFloat_Implementation(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	SigFloatSignal.Broadcast(ParamFloat);
};

void UAbstractTestbed1StructArrayInterface::BroadcastSigString_Implementation(const TArray<FTestbed1StructString>& ParamString)
{
	SigStringSignal.Broadcast(ParamString);
};

void UAbstractTestbed1StructArrayInterface::BroadcastPropBoolChanged_Implementation(const TArray<FTestbed1StructBool>& InPropBool)
{
	PropBoolChanged.Broadcast(InPropBool);
}

void UAbstractTestbed1StructArrayInterface::BroadcastPropIntChanged_Implementation(const TArray<FTestbed1StructInt>& InPropInt)
{
	PropIntChanged.Broadcast(InPropInt);
}

void UAbstractTestbed1StructArrayInterface::BroadcastPropFloatChanged_Implementation(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	PropFloatChanged.Broadcast(InPropFloat);
}

void UAbstractTestbed1StructArrayInterface::BroadcastPropStringChanged_Implementation(const TArray<FTestbed1StructString>& InPropString)
{
	PropStringChanged.Broadcast(InPropString);
}
TArray<FTestbed1StructBool> UAbstractTestbed1StructArrayInterface::GetPropBool_Private() const
{
	return Execute_GetPropBool(this);
};

void UAbstractTestbed1StructArrayInterface::SetPropBool_Private(const TArray<FTestbed1StructBool>& InPropBool)
{
	Execute_SetPropBool(this, InPropBool);
};

TArray<FTestbed1StructInt> UAbstractTestbed1StructArrayInterface::GetPropInt_Private() const
{
	return Execute_GetPropInt(this);
};

void UAbstractTestbed1StructArrayInterface::SetPropInt_Private(const TArray<FTestbed1StructInt>& InPropInt)
{
	Execute_SetPropInt(this, InPropInt);
};

TArray<FTestbed1StructFloat> UAbstractTestbed1StructArrayInterface::GetPropFloat_Private() const
{
	return Execute_GetPropFloat(this);
};

void UAbstractTestbed1StructArrayInterface::SetPropFloat_Private(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	Execute_SetPropFloat(this, InPropFloat);
};

TArray<FTestbed1StructString> UAbstractTestbed1StructArrayInterface::GetPropString_Private() const
{
	return Execute_GetPropString(this);
};

void UAbstractTestbed1StructArrayInterface::SetPropString_Private(const TArray<FTestbed1StructString>& InPropString)
{
	Execute_SetPropString(this, InPropString);
};

void UAbstractTestbed1StructArrayInterface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTestbed1StructArrayInterface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	Super::Deinitialize();
}

bool UAbstractTestbed1StructArrayInterface::IsInitialized() const
{
	return bInitialized;
}
