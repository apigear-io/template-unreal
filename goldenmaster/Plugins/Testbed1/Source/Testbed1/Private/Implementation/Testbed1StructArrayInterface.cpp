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

#include "Testbed1StructArrayInterface.h"

UTestbed1StructArrayInterface::~UTestbed1StructArrayInterface() = default;

void UTestbed1StructArrayInterface::BroadcastSigBool_Implementation(const TArray<FTestbed1StructBool>& ParamBool)
{
	SigBoolSignal.Broadcast(ParamBool);
}

FTestbed1StructArrayInterfaceSigBoolDelegate& UTestbed1StructArrayInterface::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
}

void UTestbed1StructArrayInterface::BroadcastSigInt_Implementation(const TArray<FTestbed1StructInt>& ParamInt)
{
	SigIntSignal.Broadcast(ParamInt);
}

FTestbed1StructArrayInterfaceSigIntDelegate& UTestbed1StructArrayInterface::GetSigIntSignalDelegate()
{
	return SigIntSignal;
}

void UTestbed1StructArrayInterface::BroadcastSigFloat_Implementation(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	SigFloatSignal.Broadcast(ParamFloat);
}

FTestbed1StructArrayInterfaceSigFloatDelegate& UTestbed1StructArrayInterface::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
}

void UTestbed1StructArrayInterface::BroadcastSigString_Implementation(const TArray<FTestbed1StructString>& ParamString)
{
	SigStringSignal.Broadcast(ParamString);
}

FTestbed1StructArrayInterfaceSigStringDelegate& UTestbed1StructArrayInterface::GetSigStringSignalDelegate()
{
	return SigStringSignal;
}

void UTestbed1StructArrayInterface::BroadcastPropBoolChanged_Implementation(const TArray<FTestbed1StructBool>& InPropBool)
{
	PropBoolChanged.Broadcast(InPropBool);
}

TArray<FTestbed1StructBool> UTestbed1StructArrayInterface::GetPropBool_Implementation() const
{
	return PropBool;
}

void UTestbed1StructArrayInterface::SetPropBool_Implementation(const TArray<FTestbed1StructBool>& InPropBool)
{
	if (PropBool != InPropBool)
	{
		PropBool = InPropBool;
		Execute_BroadcastPropBoolChanged(this, PropBool);
	}
}

FTestbed1StructArrayInterfacePropBoolChangedDelegate& UTestbed1StructArrayInterface::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
}

void UTestbed1StructArrayInterface::BroadcastPropIntChanged_Implementation(const TArray<FTestbed1StructInt>& InPropInt)
{
	PropIntChanged.Broadcast(InPropInt);
}

TArray<FTestbed1StructInt> UTestbed1StructArrayInterface::GetPropInt_Implementation() const
{
	return PropInt;
}

void UTestbed1StructArrayInterface::SetPropInt_Implementation(const TArray<FTestbed1StructInt>& InPropInt)
{
	if (PropInt != InPropInt)
	{
		PropInt = InPropInt;
		Execute_BroadcastPropIntChanged(this, PropInt);
	}
}

FTestbed1StructArrayInterfacePropIntChangedDelegate& UTestbed1StructArrayInterface::GetPropIntChangedDelegate()
{
	return PropIntChanged;
}

void UTestbed1StructArrayInterface::BroadcastPropFloatChanged_Implementation(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	PropFloatChanged.Broadcast(InPropFloat);
}

TArray<FTestbed1StructFloat> UTestbed1StructArrayInterface::GetPropFloat_Implementation() const
{
	return PropFloat;
}

void UTestbed1StructArrayInterface::SetPropFloat_Implementation(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	if (PropFloat != InPropFloat)
	{
		PropFloat = InPropFloat;
		Execute_BroadcastPropFloatChanged(this, PropFloat);
	}
}

FTestbed1StructArrayInterfacePropFloatChangedDelegate& UTestbed1StructArrayInterface::GetPropFloatChangedDelegate()
{
	return PropFloatChanged;
}

void UTestbed1StructArrayInterface::BroadcastPropStringChanged_Implementation(const TArray<FTestbed1StructString>& InPropString)
{
	PropStringChanged.Broadcast(InPropString);
}

TArray<FTestbed1StructString> UTestbed1StructArrayInterface::GetPropString_Implementation() const
{
	return PropString;
}

void UTestbed1StructArrayInterface::SetPropString_Implementation(const TArray<FTestbed1StructString>& InPropString)
{
	if (PropString != InPropString)
	{
		PropString = InPropString;
		Execute_BroadcastPropStringChanged(this, PropString);
	}
}

FTestbed1StructArrayInterfacePropStringChangedDelegate& UTestbed1StructArrayInterface::GetPropStringChangedDelegate()
{
	return PropStringChanged;
}

FTestbed1StructBool UTestbed1StructArrayInterface::FuncBool_Implementation(const TArray<FTestbed1StructBool>& ParamBool)
{
	(void)ParamBool;
	// do business logic here
	return FTestbed1StructBool();
}

FTestbed1StructBool UTestbed1StructArrayInterface::FuncInt_Implementation(const TArray<FTestbed1StructInt>& ParamInt)
{
	(void)ParamInt;
	// do business logic here
	return FTestbed1StructBool();
}

FTestbed1StructBool UTestbed1StructArrayInterface::FuncFloat_Implementation(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	(void)ParamFloat;
	// do business logic here
	return FTestbed1StructBool();
}

FTestbed1StructBool UTestbed1StructArrayInterface::FuncString_Implementation(const TArray<FTestbed1StructString>& ParamString)
{
	(void)ParamString;
	// do business logic here
	return FTestbed1StructBool();
}
