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

FTestbed1StructArrayInterfaceSigBoolDelegate& UTestbed1StructArrayInterfaceLocalService::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
}

FTestbed1StructArrayInterfaceSigIntDelegate& UTestbed1StructArrayInterfaceLocalService::GetSigIntSignalDelegate()
{
	return SigIntSignal;
}

FTestbed1StructArrayInterfaceSigFloatDelegate& UTestbed1StructArrayInterfaceLocalService::GetSigFloatSignalDelegate()
{
	return SigFloatSignal;
}

FTestbed1StructArrayInterfaceSigStringDelegate& UTestbed1StructArrayInterfaceLocalService::GetSigStringSignalDelegate()
{
	return SigStringSignal;
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
		PropBoolChanged.Broadcast(PropBool);
	}
}

FTestbed1StructArrayInterfacePropBoolChangedDelegate& UTestbed1StructArrayInterfaceLocalService::GetPropBoolChangedDelegate()
{
	return PropBoolChanged;
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
		PropIntChanged.Broadcast(PropInt);
	}
}

FTestbed1StructArrayInterfacePropIntChangedDelegate& UTestbed1StructArrayInterfaceLocalService::GetPropIntChangedDelegate()
{
	return PropIntChanged;
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
		PropFloatChanged.Broadcast(PropFloat);
	}
}

FTestbed1StructArrayInterfacePropFloatChangedDelegate& UTestbed1StructArrayInterfaceLocalService::GetPropFloatChangedDelegate()
{
	return PropFloatChanged;
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
		PropStringChanged.Broadcast(PropString);
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
