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
#include "Testbed1StructInterfaceInterface.h"

UFUNCTION(Category = "ApiGear|Testbed1|StructInterface")
FTestbed1StructInterfaceSigBoolDelegate& UAbstractTestbed1StructInterface::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
};

UFUNCTION(Category = "ApiGear|Testbed1|StructInterface")
FTestbed1StructInterfaceSigIntDelegate& UAbstractTestbed1StructInterface::GetSigIntSignalDelegate()
{
	return SigIntSignal;
};

UFUNCTION(Category = "ApiGear|Testbed1|StructInterface")
FTestbed1StructInterfaceSigFloatDelegate& UAbstractTestbed1StructInterface::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
};

UFUNCTION(Category = "ApiGear|Testbed1|StructInterface")
FTestbed1StructInterfaceSigStringDelegate& UAbstractTestbed1StructInterface::GetSigStringSignalDelegate()
{
	return SigStringSignal;
};

FTestbed1StructInterfacePropBoolChangedDelegate& UAbstractTestbed1StructInterface::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
};

FTestbed1StructInterfacePropIntChangedDelegate& UAbstractTestbed1StructInterface::GetPropIntChangedDelegate()
{
	return PropIntChanged;
};

FTestbed1StructInterfacePropFloatChangedDelegate& UAbstractTestbed1StructInterface::GetPropFloatChangedDelegate()
{
	return PropFloatChanged;
};

FTestbed1StructInterfacePropStringChangedDelegate& UAbstractTestbed1StructInterface::GetPropStringChangedDelegate()
{
	return PropStringChanged;
};
void UAbstractTestbed1StructInterface::BroadcastSigBool_Implementation(const FTestbed1StructBool& ParamBool)
{
	SigBoolSignal.Broadcast(ParamBool);
};

void UAbstractTestbed1StructInterface::BroadcastSigInt_Implementation(const FTestbed1StructInt& ParamInt)
{
	SigIntSignal.Broadcast(ParamInt);
};

void UAbstractTestbed1StructInterface::BroadcastSigFloat_Implementation(const FTestbed1StructFloat& ParamFloat)
{
	SigFloatSignal.Broadcast(ParamFloat);
};

void UAbstractTestbed1StructInterface::BroadcastSigString_Implementation(const FTestbed1StructString& ParamString)
{
	SigStringSignal.Broadcast(ParamString);
};

void UAbstractTestbed1StructInterface::BroadcastPropBoolChanged_Implementation(const FTestbed1StructBool& InPropBool)
{
	PropBoolChanged.Broadcast(InPropBool);
}

void UAbstractTestbed1StructInterface::BroadcastPropIntChanged_Implementation(const FTestbed1StructInt& InPropInt)
{
	PropIntChanged.Broadcast(InPropInt);
}

void UAbstractTestbed1StructInterface::BroadcastPropFloatChanged_Implementation(const FTestbed1StructFloat& InPropFloat)
{
	PropFloatChanged.Broadcast(InPropFloat);
}

void UAbstractTestbed1StructInterface::BroadcastPropStringChanged_Implementation(const FTestbed1StructString& InPropString)
{
	PropStringChanged.Broadcast(InPropString);
}
FTestbed1StructBool UAbstractTestbed1StructInterface::GetPropBool_Private() const
{
	return Execute_GetPropBool(this);
};

void UAbstractTestbed1StructInterface::SetPropBool_Private(const FTestbed1StructBool& InPropBool)
{
	Execute_SetPropBool(this, InPropBool);
};

FTestbed1StructInt UAbstractTestbed1StructInterface::GetPropInt_Private() const
{
	return Execute_GetPropInt(this);
};

void UAbstractTestbed1StructInterface::SetPropInt_Private(const FTestbed1StructInt& InPropInt)
{
	Execute_SetPropInt(this, InPropInt);
};

FTestbed1StructFloat UAbstractTestbed1StructInterface::GetPropFloat_Private() const
{
	return Execute_GetPropFloat(this);
};

void UAbstractTestbed1StructInterface::SetPropFloat_Private(const FTestbed1StructFloat& InPropFloat)
{
	Execute_SetPropFloat(this, InPropFloat);
};

FTestbed1StructString UAbstractTestbed1StructInterface::GetPropString_Private() const
{
	return Execute_GetPropString(this);
};

void UAbstractTestbed1StructInterface::SetPropString_Private(const FTestbed1StructString& InPropString)
{
	Execute_SetPropString(this, InPropString);
};

void UAbstractTestbed1StructInterface::Initialize(FSubsystemCollectionBase& Collection)
{
	check(!bInitialized);
	bInitialized = true;

	Super::Initialize(Collection);
}

void UAbstractTestbed1StructInterface::Deinitialize()
{
	check(bInitialized);
	bInitialized = false;

	Super::Deinitialize();
}

bool UAbstractTestbed1StructInterface::IsInitialized() const
{
	return bInitialized;
}
