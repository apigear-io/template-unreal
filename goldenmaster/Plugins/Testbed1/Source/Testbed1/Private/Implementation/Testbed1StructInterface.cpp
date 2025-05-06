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
FTestbed1StructBool UTestbed1StructInterface::GetPropBool_Implementation() const
{
	return PropBool;
}

void UTestbed1StructInterface::SetPropBool_Implementation(const FTestbed1StructBool& InPropBool)
{
	if (PropBool != InPropBool)
	{
		PropBool = InPropBool;
		Execute__GetSignals(this)->OnPropBoolChanged.Broadcast(PropBool);
	}
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
		Execute__GetSignals(this)->OnPropIntChanged.Broadcast(PropInt);
	}
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
		Execute__GetSignals(this)->OnPropFloatChanged.Broadcast(PropFloat);
	}
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
		Execute__GetSignals(this)->OnPropStringChanged.Broadcast(PropString);
	}
}

FTestbed1StructBool UTestbed1StructInterface::FuncBool_Implementation(const FTestbed1StructBool& ParamBool)
{
	(void)ParamBool;
	// do business logic here
	return FTestbed1StructBool();
}

FTestbed1StructInt UTestbed1StructInterface::FuncInt_Implementation(const FTestbed1StructInt& ParamInt)
{
	(void)ParamInt;
	// do business logic here
	return FTestbed1StructInt();
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

void UTestbed1StructInterface::_ResetProperties()
{
	if (PropBool != FTestbed1StructBool())
	{
		PropBool = FTestbed1StructBool();
		Execute__GetSignals(this)->OnPropBoolChanged.Broadcast(PropBool);
	}
	if (PropInt != FTestbed1StructInt())
	{
		PropInt = FTestbed1StructInt();
		Execute__GetSignals(this)->OnPropIntChanged.Broadcast(PropInt);
	}
	if (PropFloat != FTestbed1StructFloat())
	{
		PropFloat = FTestbed1StructFloat();
		Execute__GetSignals(this)->OnPropFloatChanged.Broadcast(PropFloat);
	}
	if (PropString != FTestbed1StructString())
	{
		PropString = FTestbed1StructString();
		Execute__GetSignals(this)->OnPropStringChanged.Broadcast(PropString);
	}
}
