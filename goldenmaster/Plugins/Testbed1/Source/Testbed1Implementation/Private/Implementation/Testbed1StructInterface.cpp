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

#include "Testbed1/Implementation/Testbed1StructInterface.h"

UTestbed1StructInterface::~UTestbed1StructInterface() = default;
FTestbed1StructBool UTestbed1StructInterface::GetPropBool() const
{
	return PropBool;
}

void UTestbed1StructInterface::SetPropBool(const FTestbed1StructBool& InPropBool)
{
	if (PropBool != InPropBool)
	{
		PropBool = InPropBool;
		_GetSignals()->BroadcastPropBoolChanged(PropBool);
	}
}
FTestbed1StructInt UTestbed1StructInterface::GetPropInt() const
{
	return PropInt;
}

void UTestbed1StructInterface::SetPropInt(const FTestbed1StructInt& InPropInt)
{
	if (PropInt != InPropInt)
	{
		PropInt = InPropInt;
		_GetSignals()->BroadcastPropIntChanged(PropInt);
	}
}
FTestbed1StructFloat UTestbed1StructInterface::GetPropFloat() const
{
	return PropFloat;
}

void UTestbed1StructInterface::SetPropFloat(const FTestbed1StructFloat& InPropFloat)
{
	if (PropFloat != InPropFloat)
	{
		PropFloat = InPropFloat;
		_GetSignals()->BroadcastPropFloatChanged(PropFloat);
	}
}
FTestbed1StructString UTestbed1StructInterface::GetPropString() const
{
	return PropString;
}

void UTestbed1StructInterface::SetPropString(const FTestbed1StructString& InPropString)
{
	if (PropString != InPropString)
	{
		PropString = InPropString;
		_GetSignals()->BroadcastPropStringChanged(PropString);
	}
}

FTestbed1StructBool UTestbed1StructInterface::FuncBool(const FTestbed1StructBool& ParamBool)
{
	(void)ParamBool;
	// do business logic here
	return FTestbed1StructBool();
}

FTestbed1StructInt UTestbed1StructInterface::FuncInt(const FTestbed1StructInt& ParamInt)
{
	(void)ParamInt;
	// do business logic here
	return FTestbed1StructInt();
}

FTestbed1StructFloat UTestbed1StructInterface::FuncFloat(const FTestbed1StructFloat& ParamFloat)
{
	(void)ParamFloat;
	// do business logic here
	return FTestbed1StructFloat();
}

FTestbed1StructString UTestbed1StructInterface::FuncString(const FTestbed1StructString& ParamString)
{
	(void)ParamString;
	// do business logic here
	return FTestbed1StructString();
}

void UTestbed1StructInterface::_ResetProperties()
{
	if (PropBool != FTestbed1StructBool())
	{
		PropBool = FTestbed1StructBool();
		_GetSignals()->BroadcastPropBoolChanged(PropBool);
	}
	if (PropInt != FTestbed1StructInt())
	{
		PropInt = FTestbed1StructInt();
		_GetSignals()->BroadcastPropIntChanged(PropInt);
	}
	if (PropFloat != FTestbed1StructFloat())
	{
		PropFloat = FTestbed1StructFloat();
		_GetSignals()->BroadcastPropFloatChanged(PropFloat);
	}
	if (PropString != FTestbed1StructString())
	{
		PropString = FTestbed1StructString();
		_GetSignals()->BroadcastPropStringChanged(PropString);
	}
}
