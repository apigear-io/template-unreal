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

#include "Testbed1StructArrayInterfaceLocal.h"
UTestbed1StructArrayInterfaceLocalService::UTestbed1StructArrayInterfaceLocalService()
	: ITestbed1StructArrayInterfaceInterface()
	, PropBool(TArray<FTestbed1StructBool>())
	, PropInt(TArray<FTestbed1StructInt>())
	, PropFloat(TArray<FTestbed1StructFloat>())
	, PropString(TArray<FTestbed1StructString>())
{
}
UTestbed1StructArrayInterfaceLocalService::~UTestbed1StructArrayInterfaceLocalService()
{
}

void UTestbed1StructArrayInterfaceLocalService::BroadcastSigBool_Implementation(const TArray<FTestbed1StructBool>& ParamBool)
{
	SigBoolSignal.Broadcast(ParamBool);
}

FTestbed1StructArrayInterfaceSigBoolDelegate& UTestbed1StructArrayInterfaceLocalService::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
}

void UTestbed1StructArrayInterfaceLocalService::BroadcastSigInt_Implementation(const TArray<FTestbed1StructInt>& ParamInt)
{
	SigIntSignal.Broadcast(ParamInt);
}

FTestbed1StructArrayInterfaceSigIntDelegate& UTestbed1StructArrayInterfaceLocalService::GetSigIntSignalDelegate()
{
	return SigIntSignal;
}

void UTestbed1StructArrayInterfaceLocalService::BroadcastSigFloat_Implementation(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	SigFloatSignal.Broadcast(ParamFloat);
}

FTestbed1StructArrayInterfaceSigFloatDelegate& UTestbed1StructArrayInterfaceLocalService::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
}

void UTestbed1StructArrayInterfaceLocalService::BroadcastSigString_Implementation(const TArray<FTestbed1StructString>& ParamString)
{
	SigStringSignal.Broadcast(ParamString);
}

FTestbed1StructArrayInterfaceSigStringDelegate& UTestbed1StructArrayInterfaceLocalService::GetSigStringSignalDelegate()
{
	return SigStringSignal;
}

void UTestbed1StructArrayInterfaceLocalService::BroadcastPropBoolChanged_Implementation(const TArray<FTestbed1StructBool>& InPropBool)
{
	PropBoolChanged.Broadcast(InPropBool);
}

TArray<FTestbed1StructBool> UTestbed1StructArrayInterfaceLocalService::GetPropBool_Implementation() const
{
	return PropBool;
}

void UTestbed1StructArrayInterfaceLocalService::SetPropBool_Implementation(const TArray<FTestbed1StructBool>& InPropBool)
{
	if (PropBool != InPropBool)
	{
		PropBool = InPropBool;
		Execute_BroadcastPropBoolChanged(this, PropBool);
	}
}

FTestbed1StructArrayInterfacePropBoolChangedDelegate& UTestbed1StructArrayInterfaceLocalService::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
}

void UTestbed1StructArrayInterfaceLocalService::BroadcastPropIntChanged_Implementation(const TArray<FTestbed1StructInt>& InPropInt)
{
	PropIntChanged.Broadcast(InPropInt);
}

TArray<FTestbed1StructInt> UTestbed1StructArrayInterfaceLocalService::GetPropInt_Implementation() const
{
	return PropInt;
}

void UTestbed1StructArrayInterfaceLocalService::SetPropInt_Implementation(const TArray<FTestbed1StructInt>& InPropInt)
{
	if (PropInt != InPropInt)
	{
		PropInt = InPropInt;
		Execute_BroadcastPropIntChanged(this, PropInt);
	}
}

FTestbed1StructArrayInterfacePropIntChangedDelegate& UTestbed1StructArrayInterfaceLocalService::GetPropIntChangedDelegate()
{
	return PropIntChanged;
}

void UTestbed1StructArrayInterfaceLocalService::BroadcastPropFloatChanged_Implementation(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	PropFloatChanged.Broadcast(InPropFloat);
}

TArray<FTestbed1StructFloat> UTestbed1StructArrayInterfaceLocalService::GetPropFloat_Implementation() const
{
	return PropFloat;
}

void UTestbed1StructArrayInterfaceLocalService::SetPropFloat_Implementation(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	if (PropFloat != InPropFloat)
	{
		PropFloat = InPropFloat;
		Execute_BroadcastPropFloatChanged(this, PropFloat);
	}
}

FTestbed1StructArrayInterfacePropFloatChangedDelegate& UTestbed1StructArrayInterfaceLocalService::GetPropFloatChangedDelegate()
{
	return PropFloatChanged;
}

void UTestbed1StructArrayInterfaceLocalService::BroadcastPropStringChanged_Implementation(const TArray<FTestbed1StructString>& InPropString)
{
	PropStringChanged.Broadcast(InPropString);
}

TArray<FTestbed1StructString> UTestbed1StructArrayInterfaceLocalService::GetPropString_Implementation() const
{
	return PropString;
}

void UTestbed1StructArrayInterfaceLocalService::SetPropString_Implementation(const TArray<FTestbed1StructString>& InPropString)
{
	if (PropString != InPropString)
	{
		PropString = InPropString;
		Execute_BroadcastPropStringChanged(this, PropString);
	}
}

FTestbed1StructArrayInterfacePropStringChangedDelegate& UTestbed1StructArrayInterfaceLocalService::GetPropStringChangedDelegate()
{
	return PropStringChanged;
}

FTestbed1StructBool UTestbed1StructArrayInterfaceLocalService::FuncBool_Implementation(const TArray<FTestbed1StructBool>& ParamBool)
{
	(void)ParamBool;
	// do business logic here
	return FTestbed1StructBool();
}

FTestbed1StructBool UTestbed1StructArrayInterfaceLocalService::FuncInt_Implementation(const TArray<FTestbed1StructInt>& ParamInt)
{
	(void)ParamInt;
	// do business logic here
	return FTestbed1StructBool();
}

FTestbed1StructBool UTestbed1StructArrayInterfaceLocalService::FuncFloat_Implementation(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	(void)ParamFloat;
	// do business logic here
	return FTestbed1StructBool();
}

FTestbed1StructBool UTestbed1StructArrayInterfaceLocalService::FuncString_Implementation(const TArray<FTestbed1StructString>& ParamString)
{
	(void)ParamString;
	// do business logic here
	return FTestbed1StructBool();
}
