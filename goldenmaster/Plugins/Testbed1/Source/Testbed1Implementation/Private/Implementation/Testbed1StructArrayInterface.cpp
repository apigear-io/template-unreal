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

#include "Testbed1/Implementation/Testbed1StructArrayInterface.h"

UTestbed1StructArrayInterfaceImplementation::~UTestbed1StructArrayInterfaceImplementation() = default;
TArray<FTestbed1StructBool> UTestbed1StructArrayInterfaceImplementation::GetPropBool() const
{
	return PropBool;
}

void UTestbed1StructArrayInterfaceImplementation::SetPropBool(const TArray<FTestbed1StructBool>& InPropBool)
{
	if (PropBool != InPropBool)
	{
		PropBool = InPropBool;
		_GetSignals()->BroadcastPropBoolChanged(PropBool);
	}
}
TArray<FTestbed1StructInt> UTestbed1StructArrayInterfaceImplementation::GetPropInt() const
{
	return PropInt;
}

void UTestbed1StructArrayInterfaceImplementation::SetPropInt(const TArray<FTestbed1StructInt>& InPropInt)
{
	if (PropInt != InPropInt)
	{
		PropInt = InPropInt;
		_GetSignals()->BroadcastPropIntChanged(PropInt);
	}
}
TArray<FTestbed1StructFloat> UTestbed1StructArrayInterfaceImplementation::GetPropFloat() const
{
	return PropFloat;
}

void UTestbed1StructArrayInterfaceImplementation::SetPropFloat(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	if (PropFloat != InPropFloat)
	{
		PropFloat = InPropFloat;
		_GetSignals()->BroadcastPropFloatChanged(PropFloat);
	}
}
TArray<FTestbed1StructString> UTestbed1StructArrayInterfaceImplementation::GetPropString() const
{
	return PropString;
}

void UTestbed1StructArrayInterfaceImplementation::SetPropString(const TArray<FTestbed1StructString>& InPropString)
{
	if (PropString != InPropString)
	{
		PropString = InPropString;
		_GetSignals()->BroadcastPropStringChanged(PropString);
	}
}
TArray<ETestbed1Enum0> UTestbed1StructArrayInterfaceImplementation::GetPropEnum() const
{
	return PropEnum;
}

void UTestbed1StructArrayInterfaceImplementation::SetPropEnum(const TArray<ETestbed1Enum0>& InPropEnum)
{
	if (PropEnum != InPropEnum)
	{
		PropEnum = InPropEnum;
		_GetSignals()->BroadcastPropEnumChanged(PropEnum);
	}
}

TArray<FTestbed1StructBool> UTestbed1StructArrayInterfaceImplementation::FuncBool(const TArray<FTestbed1StructBool>& ParamBool)
{
	(void)ParamBool;
	// do business logic here
	return TArray<FTestbed1StructBool>();
}

TArray<FTestbed1StructInt> UTestbed1StructArrayInterfaceImplementation::FuncInt(const TArray<FTestbed1StructInt>& ParamInt)
{
	(void)ParamInt;
	// do business logic here
	return TArray<FTestbed1StructInt>();
}

TArray<FTestbed1StructFloat> UTestbed1StructArrayInterfaceImplementation::FuncFloat(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	(void)ParamFloat;
	// do business logic here
	return TArray<FTestbed1StructFloat>();
}

TArray<FTestbed1StructString> UTestbed1StructArrayInterfaceImplementation::FuncString(const TArray<FTestbed1StructString>& ParamString)
{
	(void)ParamString;
	// do business logic here
	return TArray<FTestbed1StructString>();
}

TArray<ETestbed1Enum0> UTestbed1StructArrayInterfaceImplementation::FuncEnum(const TArray<ETestbed1Enum0>& ParamEnum)
{
	(void)ParamEnum;
	// do business logic here
	return TArray<ETestbed1Enum0>();
}

void UTestbed1StructArrayInterfaceImplementation::_ResetProperties()
{
	if (PropBool != TArray<FTestbed1StructBool>())
	{
		PropBool = TArray<FTestbed1StructBool>();
		_GetSignals()->BroadcastPropBoolChanged(PropBool);
	}
	if (PropInt != TArray<FTestbed1StructInt>())
	{
		PropInt = TArray<FTestbed1StructInt>();
		_GetSignals()->BroadcastPropIntChanged(PropInt);
	}
	if (PropFloat != TArray<FTestbed1StructFloat>())
	{
		PropFloat = TArray<FTestbed1StructFloat>();
		_GetSignals()->BroadcastPropFloatChanged(PropFloat);
	}
	if (PropString != TArray<FTestbed1StructString>())
	{
		PropString = TArray<FTestbed1StructString>();
		_GetSignals()->BroadcastPropStringChanged(PropString);
	}
	if (PropEnum != TArray<ETestbed1Enum0>())
	{
		PropEnum = TArray<ETestbed1Enum0>();
		_GetSignals()->BroadcastPropEnumChanged(PropEnum);
	}
}
