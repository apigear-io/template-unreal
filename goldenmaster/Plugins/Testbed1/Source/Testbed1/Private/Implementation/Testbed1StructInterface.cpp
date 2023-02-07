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

#include "Implementation/Testbed1StructInterface.h"

UTestbed1StructInterface::~UTestbed1StructInterface() = default;

void UTestbed1StructInterface::BroadcastSigBool_Implementation(const FTestbed1StructBool& ParamBool)
{
	SigBoolSignal.Broadcast(ParamBool);
}

FTestbed1StructInterfaceSigBoolDelegate& UTestbed1StructInterface::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
}

void UTestbed1StructInterface::BroadcastSigInt_Implementation(const FTestbed1StructInt& ParamInt)
{
	SigIntSignal.Broadcast(ParamInt);
}

FTestbed1StructInterfaceSigIntDelegate& UTestbed1StructInterface::GetSigIntSignalDelegate()
{
	return SigIntSignal;
}

void UTestbed1StructInterface::BroadcastSigFloat_Implementation(const FTestbed1StructFloat& ParamFloat)
{
	SigFloatSignal.Broadcast(ParamFloat);
}

FTestbed1StructInterfaceSigFloatDelegate& UTestbed1StructInterface::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
}

void UTestbed1StructInterface::BroadcastSigString_Implementation(const FTestbed1StructString& ParamString)
{
	SigStringSignal.Broadcast(ParamString);
}

FTestbed1StructInterfaceSigStringDelegate& UTestbed1StructInterface::GetSigStringSignalDelegate()
{
	return SigStringSignal;
}

void UTestbed1StructInterface::BroadcastPropBoolChanged_Implementation(const FTestbed1StructBool& InPropBool)
{
	PropBoolChanged.Broadcast(InPropBool);
}

FTestbed1StructBool UTestbed1StructInterface::GetPropBool_Implementation() const
{
	return PropBool;
}

void UTestbed1StructInterface::SetPropBool_Implementation(const FTestbed1StructBool& InPropBool)
{
	if (PropBool != InPropBool)
	{
		PropBool = InPropBool;
		Execute_BroadcastPropBoolChanged(this, PropBool);
	}
}

FTestbed1StructInterfacePropBoolChangedDelegate& UTestbed1StructInterface::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
}

void UTestbed1StructInterface::BroadcastPropIntChanged_Implementation(const FTestbed1StructInt& InPropInt)
{
	PropIntChanged.Broadcast(InPropInt);
}

FTestbed1StructInt UTestbed1StructInterface::GetPropInt_Implementation() const
{
	return PropInt;
}

void UTestbed1StructInterface::SetPropInt_Implementation(const FTestbed1StructInt& InPropInt)
{
	if (PropInt != InPropInt)
	{
		PropInt = InPropInt;
		Execute_BroadcastPropIntChanged(this, PropInt);
	}
}

FTestbed1StructInterfacePropIntChangedDelegate& UTestbed1StructInterface::GetPropIntChangedDelegate()
{
	return PropIntChanged;
}

void UTestbed1StructInterface::BroadcastPropFloatChanged_Implementation(const FTestbed1StructFloat& InPropFloat)
{
	PropFloatChanged.Broadcast(InPropFloat);
}

FTestbed1StructFloat UTestbed1StructInterface::GetPropFloat_Implementation() const
{
	return PropFloat;
}

void UTestbed1StructInterface::SetPropFloat_Implementation(const FTestbed1StructFloat& InPropFloat)
{
	if (PropFloat != InPropFloat)
	{
		PropFloat = InPropFloat;
		Execute_BroadcastPropFloatChanged(this, PropFloat);
	}
}

FTestbed1StructInterfacePropFloatChangedDelegate& UTestbed1StructInterface::GetPropFloatChangedDelegate()
{
	return PropFloatChanged;
}

void UTestbed1StructInterface::BroadcastPropStringChanged_Implementation(const FTestbed1StructString& InPropString)
{
	PropStringChanged.Broadcast(InPropString);
}

FTestbed1StructString UTestbed1StructInterface::GetPropString_Implementation() const
{
	return PropString;
}

void UTestbed1StructInterface::SetPropString_Implementation(const FTestbed1StructString& InPropString)
{
	if (PropString != InPropString)
	{
		PropString = InPropString;
		Execute_BroadcastPropStringChanged(this, PropString);
	}
}

FTestbed1StructInterfacePropStringChangedDelegate& UTestbed1StructInterface::GetPropStringChangedDelegate()
{
	return PropStringChanged;
}

FTestbed1StructBool UTestbed1StructInterface::FuncBool_Implementation(const FTestbed1StructBool& ParamBool)
{
	(void)ParamBool;
	// do business logic here
	return FTestbed1StructBool();
}

FTestbed1StructBool UTestbed1StructInterface::FuncInt_Implementation(const FTestbed1StructInt& ParamInt)
{
	(void)ParamInt;
	// do business logic here
	return FTestbed1StructBool();
}

FTestbed1StructFloat UTestbed1StructInterface::FuncFloat_Implementation(const FTestbed1StructFloat& ParamFloat)
{
	(void)ParamFloat;
	// do business logic here
	return FTestbed1StructFloat();
}

FTestbed1StructString UTestbed1StructInterface::FuncString_Implementation(const FTestbed1StructString& ParamString)
{
	(void)ParamString;
	// do business logic here
	return FTestbed1StructString();
}
