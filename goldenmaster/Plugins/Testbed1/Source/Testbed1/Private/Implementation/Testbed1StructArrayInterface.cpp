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

#include "Implementation/Testbed1StructArrayInterface.h"

UTestbed1StructArrayInterface::~UTestbed1StructArrayInterface() = default;
TArray<FTestbed1StructBool> UTestbed1StructArrayInterface::GetPropBool_Implementation() const
{
	return PropBool;
}

void UTestbed1StructArrayInterface::SetPropBool_Implementation(const TArray<FTestbed1StructBool>& InPropBool)
{
	if (PropBool != InPropBool)
	{
		PropBool = InPropBool;
		Execute__GetSignals(this)->OnPropBoolChanged.Broadcast(PropBool);
	}
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
		Execute__GetSignals(this)->OnPropIntChanged.Broadcast(PropInt);
	}
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
		Execute__GetSignals(this)->OnPropFloatChanged.Broadcast(PropFloat);
	}
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
		Execute__GetSignals(this)->OnPropStringChanged.Broadcast(PropString);
	}
}
TArray<ETestbed1Enum0> UTestbed1StructArrayInterface::GetPropEnum_Implementation() const
{
	return PropEnum;
}

void UTestbed1StructArrayInterface::SetPropEnum_Implementation(const TArray<ETestbed1Enum0>& InPropEnum)
{
	if (PropEnum != InPropEnum)
	{
		PropEnum = InPropEnum;
		Execute__GetSignals(this)->OnPropEnumChanged.Broadcast(PropEnum);
	}
}

TArray<FTestbed1StructBool> UTestbed1StructArrayInterface::FuncBool_Implementation(const TArray<FTestbed1StructBool>& ParamBool)
{
	(void)ParamBool;
	// do business logic here
	return TArray<FTestbed1StructBool>();
}

TArray<FTestbed1StructInt> UTestbed1StructArrayInterface::FuncInt_Implementation(const TArray<FTestbed1StructInt>& ParamInt)
{
	(void)ParamInt;
	// do business logic here
	return TArray<FTestbed1StructInt>();
}

TArray<FTestbed1StructFloat> UTestbed1StructArrayInterface::FuncFloat_Implementation(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	(void)ParamFloat;
	// do business logic here
	return TArray<FTestbed1StructFloat>();
}

TArray<FTestbed1StructString> UTestbed1StructArrayInterface::FuncString_Implementation(const TArray<FTestbed1StructString>& ParamString)
{
	(void)ParamString;
	// do business logic here
	return TArray<FTestbed1StructString>();
}

TArray<ETestbed1Enum0> UTestbed1StructArrayInterface::FuncEnum_Implementation(const TArray<ETestbed1Enum0>& ParamEnum)
{
	(void)ParamEnum;
	// do business logic here
	return TArray<ETestbed1Enum0>();
}
