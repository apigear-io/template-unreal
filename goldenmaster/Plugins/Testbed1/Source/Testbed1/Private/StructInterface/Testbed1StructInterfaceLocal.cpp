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

#include "Testbed1StructInterfaceLocal.h"
UTestbed1StructInterfaceLocalService::UTestbed1StructInterfaceLocalService()
	: ITestbed1StructInterfaceInterface()
	, PropBool(FTestbed1StructBool())
	, PropInt(FTestbed1StructInt())
	, PropFloat(FTestbed1StructFloat())
	, PropString(FTestbed1StructString())
{
}
UTestbed1StructInterfaceLocalService::~UTestbed1StructInterfaceLocalService()
{
}

void UTestbed1StructInterfaceLocalService::BroadcastSigBool_Implementation(const FTestbed1StructBool& ParamBool)
{
	SigBoolSignal.Broadcast(ParamBool);
}

FTestbed1StructInterfaceSigBoolDelegate& UTestbed1StructInterfaceLocalService::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
}

void UTestbed1StructInterfaceLocalService::BroadcastSigInt_Implementation(const FTestbed1StructInt& ParamInt)
{
	SigIntSignal.Broadcast(ParamInt);
}

FTestbed1StructInterfaceSigIntDelegate& UTestbed1StructInterfaceLocalService::GetSigIntSignalDelegate()
{
	return SigIntSignal;
}

void UTestbed1StructInterfaceLocalService::BroadcastSigFloat_Implementation(const FTestbed1StructFloat& ParamFloat)
{
	SigFloatSignal.Broadcast(ParamFloat);
}

FTestbed1StructInterfaceSigFloatDelegate& UTestbed1StructInterfaceLocalService::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
}

void UTestbed1StructInterfaceLocalService::BroadcastSigString_Implementation(const FTestbed1StructString& ParamString)
{
	SigStringSignal.Broadcast(ParamString);
}

FTestbed1StructInterfaceSigStringDelegate& UTestbed1StructInterfaceLocalService::GetSigStringSignalDelegate()
{
	return SigStringSignal;
}

void UTestbed1StructInterfaceLocalService::BroadcastPropBoolChanged_Implementation(const FTestbed1StructBool& InPropBool)
{
	PropBoolChanged.Broadcast(InPropBool);
}

FTestbed1StructBool UTestbed1StructInterfaceLocalService::GetPropBool_Implementation() const
{
	return PropBool;
}

void UTestbed1StructInterfaceLocalService::SetPropBool_Implementation(const FTestbed1StructBool& InPropBool)
{
	if (PropBool != InPropBool)
	{
		PropBool = InPropBool;
		Execute_BroadcastPropBoolChanged(this, PropBool);
	}
}

FTestbed1StructInterfacePropBoolChangedDelegate& UTestbed1StructInterfaceLocalService::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
}

void UTestbed1StructInterfaceLocalService::BroadcastPropIntChanged_Implementation(const FTestbed1StructInt& InPropInt)
{
	PropIntChanged.Broadcast(InPropInt);
}

FTestbed1StructInt UTestbed1StructInterfaceLocalService::GetPropInt_Implementation() const
{
	return PropInt;
}

void UTestbed1StructInterfaceLocalService::SetPropInt_Implementation(const FTestbed1StructInt& InPropInt)
{
	if (PropInt != InPropInt)
	{
		PropInt = InPropInt;
		Execute_BroadcastPropIntChanged(this, PropInt);
	}
}

FTestbed1StructInterfacePropIntChangedDelegate& UTestbed1StructInterfaceLocalService::GetPropIntChangedDelegate()
{
	return PropIntChanged;
}

void UTestbed1StructInterfaceLocalService::BroadcastPropFloatChanged_Implementation(const FTestbed1StructFloat& InPropFloat)
{
	PropFloatChanged.Broadcast(InPropFloat);
}

FTestbed1StructFloat UTestbed1StructInterfaceLocalService::GetPropFloat_Implementation() const
{
	return PropFloat;
}

void UTestbed1StructInterfaceLocalService::SetPropFloat_Implementation(const FTestbed1StructFloat& InPropFloat)
{
	if (PropFloat != InPropFloat)
	{
		PropFloat = InPropFloat;
		Execute_BroadcastPropFloatChanged(this, PropFloat);
	}
}

FTestbed1StructInterfacePropFloatChangedDelegate& UTestbed1StructInterfaceLocalService::GetPropFloatChangedDelegate()
{
	return PropFloatChanged;
}

void UTestbed1StructInterfaceLocalService::BroadcastPropStringChanged_Implementation(const FTestbed1StructString& InPropString)
{
	PropStringChanged.Broadcast(InPropString);
}

FTestbed1StructString UTestbed1StructInterfaceLocalService::GetPropString_Implementation() const
{
	return PropString;
}

void UTestbed1StructInterfaceLocalService::SetPropString_Implementation(const FTestbed1StructString& InPropString)
{
	if (PropString != InPropString)
	{
		PropString = InPropString;
		Execute_BroadcastPropStringChanged(this, PropString);
	}
}

FTestbed1StructInterfacePropStringChangedDelegate& UTestbed1StructInterfaceLocalService::GetPropStringChangedDelegate()
{
	return PropStringChanged;
}

FTestbed1StructBool UTestbed1StructInterfaceLocalService::FuncBool_Implementation(const FTestbed1StructBool& ParamBool)
{
	(void)ParamBool;
	// do business logic here
	return FTestbed1StructBool();
}

FTestbed1StructBool UTestbed1StructInterfaceLocalService::FuncInt_Implementation(const FTestbed1StructInt& ParamInt)
{
	(void)ParamInt;
	// do business logic here
	return FTestbed1StructBool();
}

FTestbed1StructFloat UTestbed1StructInterfaceLocalService::FuncFloat_Implementation(const FTestbed1StructFloat& ParamFloat)
{
	(void)ParamFloat;
	// do business logic here
	return FTestbed1StructFloat();
}

FTestbed1StructString UTestbed1StructInterfaceLocalService::FuncString_Implementation(const FTestbed1StructString& ParamString)
{
	(void)ParamString;
	// do business logic here
	return FTestbed1StructString();
}
