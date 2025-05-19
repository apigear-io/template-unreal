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

#include "Testbed1/Implementation/Testbed1StructArray2Interface.h"

UTestbed1StructArray2InterfaceImplementation::~UTestbed1StructArray2InterfaceImplementation() = default;
FTestbed1StructBoolWithArray UTestbed1StructArray2InterfaceImplementation::GetPropBool() const
{
	return PropBool;
}

void UTestbed1StructArray2InterfaceImplementation::SetPropBool(const FTestbed1StructBoolWithArray& InPropBool)
{
	if (PropBool != InPropBool)
	{
		PropBool = InPropBool;
		_GetSignals()->BroadcastPropBoolChanged(PropBool);
	}
}
FTestbed1StructIntWithArray UTestbed1StructArray2InterfaceImplementation::GetPropInt() const
{
	return PropInt;
}

void UTestbed1StructArray2InterfaceImplementation::SetPropInt(const FTestbed1StructIntWithArray& InPropInt)
{
	if (PropInt != InPropInt)
	{
		PropInt = InPropInt;
		_GetSignals()->BroadcastPropIntChanged(PropInt);
	}
}
FTestbed1StructFloatWithArray UTestbed1StructArray2InterfaceImplementation::GetPropFloat() const
{
	return PropFloat;
}

void UTestbed1StructArray2InterfaceImplementation::SetPropFloat(const FTestbed1StructFloatWithArray& InPropFloat)
{
	if (PropFloat != InPropFloat)
	{
		PropFloat = InPropFloat;
		_GetSignals()->BroadcastPropFloatChanged(PropFloat);
	}
}
FTestbed1StructStringWithArray UTestbed1StructArray2InterfaceImplementation::GetPropString() const
{
	return PropString;
}

void UTestbed1StructArray2InterfaceImplementation::SetPropString(const FTestbed1StructStringWithArray& InPropString)
{
	if (PropString != InPropString)
	{
		PropString = InPropString;
		_GetSignals()->BroadcastPropStringChanged(PropString);
	}
}
FTestbed1StructEnumWithArray UTestbed1StructArray2InterfaceImplementation::GetPropEnum() const
{
	return PropEnum;
}

void UTestbed1StructArray2InterfaceImplementation::SetPropEnum(const FTestbed1StructEnumWithArray& InPropEnum)
{
	if (PropEnum != InPropEnum)
	{
		PropEnum = InPropEnum;
		_GetSignals()->BroadcastPropEnumChanged(PropEnum);
	}
}

TArray<FTestbed1StructBool> UTestbed1StructArray2InterfaceImplementation::FuncBool(const FTestbed1StructBoolWithArray& ParamBool)
{
	(void)ParamBool;
	// do business logic here
	return TArray<FTestbed1StructBool>();
}

TArray<FTestbed1StructInt> UTestbed1StructArray2InterfaceImplementation::FuncInt(const FTestbed1StructIntWithArray& ParamInt)
{
	(void)ParamInt;
	// do business logic here
	return TArray<FTestbed1StructInt>();
}

TArray<FTestbed1StructFloat> UTestbed1StructArray2InterfaceImplementation::FuncFloat(const FTestbed1StructFloatWithArray& ParamFloat)
{
	(void)ParamFloat;
	// do business logic here
	return TArray<FTestbed1StructFloat>();
}

TArray<FTestbed1StructString> UTestbed1StructArray2InterfaceImplementation::FuncString(const FTestbed1StructStringWithArray& ParamString)
{
	(void)ParamString;
	// do business logic here
	return TArray<FTestbed1StructString>();
}

TArray<ETestbed1Enum0> UTestbed1StructArray2InterfaceImplementation::FuncEnum(const FTestbed1StructEnumWithArray& ParamEnum)
{
	(void)ParamEnum;
	// do business logic here
	return TArray<ETestbed1Enum0>();
}

void UTestbed1StructArray2InterfaceImplementation::_ResetProperties()
{
	if (PropBool != FTestbed1StructBoolWithArray())
	{
		PropBool = FTestbed1StructBoolWithArray();
		_GetSignals()->BroadcastPropBoolChanged(PropBool);
	}
	if (PropInt != FTestbed1StructIntWithArray())
	{
		PropInt = FTestbed1StructIntWithArray();
		_GetSignals()->BroadcastPropIntChanged(PropInt);
	}
	if (PropFloat != FTestbed1StructFloatWithArray())
	{
		PropFloat = FTestbed1StructFloatWithArray();
		_GetSignals()->BroadcastPropFloatChanged(PropFloat);
	}
	if (PropString != FTestbed1StructStringWithArray())
	{
		PropString = FTestbed1StructStringWithArray();
		_GetSignals()->BroadcastPropStringChanged(PropString);
	}
	if (PropEnum != FTestbed1StructEnumWithArray())
	{
		PropEnum = FTestbed1StructEnumWithArray();
		_GetSignals()->BroadcastPropEnumChanged(PropEnum);
	}
}
