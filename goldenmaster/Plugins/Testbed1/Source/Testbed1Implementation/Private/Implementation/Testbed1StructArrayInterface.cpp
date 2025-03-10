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

UTestbed1StructArrayInterface::~UTestbed1StructArrayInterface() = default;
TArray<FTestbed1StructBool> UTestbed1StructArrayInterface::GetPropBool() const
{
	return PropBool;
}

void UTestbed1StructArrayInterface::SetPropBool(const TArray<FTestbed1StructBool>& InPropBool)
{
	if (PropBool != InPropBool)
	{
		PropBool = InPropBool;
		_GetSignals()->BroadcastPropBoolChanged(PropBool);
	}
}
TArray<FTestbed1StructInt> UTestbed1StructArrayInterface::GetPropInt() const
{
	return PropInt;
}

void UTestbed1StructArrayInterface::SetPropInt(const TArray<FTestbed1StructInt>& InPropInt)
{
	if (PropInt != InPropInt)
	{
		PropInt = InPropInt;
		_GetSignals()->BroadcastPropIntChanged(PropInt);
	}
}
TArray<FTestbed1StructFloat> UTestbed1StructArrayInterface::GetPropFloat() const
{
	return PropFloat;
}

void UTestbed1StructArrayInterface::SetPropFloat(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	if (PropFloat != InPropFloat)
	{
		PropFloat = InPropFloat;
		_GetSignals()->BroadcastPropFloatChanged(PropFloat);
	}
}
TArray<FTestbed1StructString> UTestbed1StructArrayInterface::GetPropString() const
{
	return PropString;
}

void UTestbed1StructArrayInterface::SetPropString(const TArray<FTestbed1StructString>& InPropString)
{
	if (PropString != InPropString)
	{
		PropString = InPropString;
		_GetSignals()->BroadcastPropStringChanged(PropString);
	}
}

TArray<FTestbed1StructBool> UTestbed1StructArrayInterface::FuncBool(const TArray<FTestbed1StructBool>& ParamBool)
{
	(void)ParamBool;
	// do business logic here
	return TArray<FTestbed1StructBool>();
}

TArray<FTestbed1StructInt> UTestbed1StructArrayInterface::FuncInt(const TArray<FTestbed1StructInt>& ParamInt)
{
	(void)ParamInt;
	// do business logic here
	return TArray<FTestbed1StructInt>();
}

TArray<FTestbed1StructFloat> UTestbed1StructArrayInterface::FuncFloat(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	(void)ParamFloat;
	// do business logic here
	return TArray<FTestbed1StructFloat>();
}

TArray<FTestbed1StructString> UTestbed1StructArrayInterface::FuncString(const TArray<FTestbed1StructString>& ParamString)
{
	(void)ParamString;
	// do business logic here
	return TArray<FTestbed1StructString>();
}
