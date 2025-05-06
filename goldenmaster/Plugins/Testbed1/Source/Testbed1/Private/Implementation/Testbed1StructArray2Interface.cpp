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

#include "Implementation/Testbed1StructArray2Interface.h"

UTestbed1StructArray2Interface::~UTestbed1StructArray2Interface() = default;
FTestbed1StructBoolWithArray UTestbed1StructArray2Interface::GetPropBool_Implementation() const
{
	return PropBool;
}

void UTestbed1StructArray2Interface::SetPropBool_Implementation(const FTestbed1StructBoolWithArray& InPropBool)
{
	if (PropBool != InPropBool)
	{
		PropBool = InPropBool;
		Execute__GetSignals(this)->OnPropBoolChanged.Broadcast(PropBool);
	}
}
FTestbed1StructIntWithArray UTestbed1StructArray2Interface::GetPropInt_Implementation() const
{
	return PropInt;
}

void UTestbed1StructArray2Interface::SetPropInt_Implementation(const FTestbed1StructIntWithArray& InPropInt)
{
	if (PropInt != InPropInt)
	{
		PropInt = InPropInt;
		Execute__GetSignals(this)->OnPropIntChanged.Broadcast(PropInt);
	}
}
FTestbed1StructFloatWithArray UTestbed1StructArray2Interface::GetPropFloat_Implementation() const
{
	return PropFloat;
}

void UTestbed1StructArray2Interface::SetPropFloat_Implementation(const FTestbed1StructFloatWithArray& InPropFloat)
{
	if (PropFloat != InPropFloat)
	{
		PropFloat = InPropFloat;
		Execute__GetSignals(this)->OnPropFloatChanged.Broadcast(PropFloat);
	}
}
FTestbed1StructStringWithArray UTestbed1StructArray2Interface::GetPropString_Implementation() const
{
	return PropString;
}

void UTestbed1StructArray2Interface::SetPropString_Implementation(const FTestbed1StructStringWithArray& InPropString)
{
	if (PropString != InPropString)
	{
		PropString = InPropString;
		Execute__GetSignals(this)->OnPropStringChanged.Broadcast(PropString);
	}
}
FTestbed1StructEnumWithArray UTestbed1StructArray2Interface::GetPropEnum_Implementation() const
{
	return PropEnum;
}

void UTestbed1StructArray2Interface::SetPropEnum_Implementation(const FTestbed1StructEnumWithArray& InPropEnum)
{
	if (PropEnum != InPropEnum)
	{
		PropEnum = InPropEnum;
		Execute__GetSignals(this)->OnPropEnumChanged.Broadcast(PropEnum);
	}
}

TArray<FTestbed1StructBool> UTestbed1StructArray2Interface::FuncBool_Implementation(const FTestbed1StructBoolWithArray& ParamBool)
{
	(void)ParamBool;
	// do business logic here
	return TArray<FTestbed1StructBool>();
}

TArray<FTestbed1StructInt> UTestbed1StructArray2Interface::FuncInt_Implementation(const FTestbed1StructIntWithArray& ParamInt)
{
	(void)ParamInt;
	// do business logic here
	return TArray<FTestbed1StructInt>();
}

TArray<FTestbed1StructFloat> UTestbed1StructArray2Interface::FuncFloat_Implementation(const FTestbed1StructFloatWithArray& ParamFloat)
{
	(void)ParamFloat;
	// do business logic here
	return TArray<FTestbed1StructFloat>();
}

TArray<FTestbed1StructString> UTestbed1StructArray2Interface::FuncString_Implementation(const FTestbed1StructStringWithArray& ParamString)
{
	(void)ParamString;
	// do business logic here
	return TArray<FTestbed1StructString>();
}

TArray<ETestbed1Enum0> UTestbed1StructArray2Interface::FuncEnum_Implementation(const FTestbed1StructEnumWithArray& ParamEnum)
{
	(void)ParamEnum;
	// do business logic here
	return TArray<ETestbed1Enum0>();
}

void UTestbed1StructArray2Interface::_ResetProperties()
{
	if (PropBool != FTestbed1StructBoolWithArray())
	{
		PropBool = FTestbed1StructBoolWithArray();
		Execute__GetSignals(this)->OnPropBoolChanged.Broadcast(PropBool);
	}
	if (PropInt != FTestbed1StructIntWithArray())
	{
		PropInt = FTestbed1StructIntWithArray();
		Execute__GetSignals(this)->OnPropIntChanged.Broadcast(PropInt);
	}
	if (PropFloat != FTestbed1StructFloatWithArray())
	{
		PropFloat = FTestbed1StructFloatWithArray();
		Execute__GetSignals(this)->OnPropFloatChanged.Broadcast(PropFloat);
	}
	if (PropString != FTestbed1StructStringWithArray())
	{
		PropString = FTestbed1StructStringWithArray();
		Execute__GetSignals(this)->OnPropStringChanged.Broadcast(PropString);
	}
	if (PropEnum != FTestbed1StructEnumWithArray())
	{
		PropEnum = FTestbed1StructEnumWithArray();
		Execute__GetSignals(this)->OnPropEnumChanged.Broadcast(PropEnum);
	}
}
