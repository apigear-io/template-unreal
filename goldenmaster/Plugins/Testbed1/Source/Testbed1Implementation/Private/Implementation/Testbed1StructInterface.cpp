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

UTestbed1StructInterfaceImplementation::~UTestbed1StructInterfaceImplementation() = default;
FTestbed1StructBool UTestbed1StructInterfaceImplementation::GetPropBool() const
{
	return PropBool;
}

void UTestbed1StructInterfaceImplementation::SetPropBool(const FTestbed1StructBool& InPropBool)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructInterface.Impl.SetPropBool");
	if (PropBool != InPropBool)
	{
		PropBool = InPropBool;
		_GetPublisher()->BroadcastPropBoolChanged(PropBool);
	}
}
FTestbed1StructInt UTestbed1StructInterfaceImplementation::GetPropInt() const
{
	return PropInt;
}

void UTestbed1StructInterfaceImplementation::SetPropInt(const FTestbed1StructInt& InPropInt)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructInterface.Impl.SetPropInt");
	if (PropInt != InPropInt)
	{
		PropInt = InPropInt;
		_GetPublisher()->BroadcastPropIntChanged(PropInt);
	}
}
FTestbed1StructFloat UTestbed1StructInterfaceImplementation::GetPropFloat() const
{
	return PropFloat;
}

void UTestbed1StructInterfaceImplementation::SetPropFloat(const FTestbed1StructFloat& InPropFloat)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructInterface.Impl.SetPropFloat");
	if (PropFloat != InPropFloat)
	{
		PropFloat = InPropFloat;
		_GetPublisher()->BroadcastPropFloatChanged(PropFloat);
	}
}
FTestbed1StructString UTestbed1StructInterfaceImplementation::GetPropString() const
{
	return PropString;
}

void UTestbed1StructInterfaceImplementation::SetPropString(const FTestbed1StructString& InPropString)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructInterface.Impl.SetPropString");
	if (PropString != InPropString)
	{
		PropString = InPropString;
		_GetPublisher()->BroadcastPropStringChanged(PropString);
	}
}

FTestbed1StructBool UTestbed1StructInterfaceImplementation::FuncBool(const FTestbed1StructBool& ParamBool)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructInterface.Impl.FuncBool");
	(void)ParamBool;
	// do business logic here
	return FTestbed1StructBool();
}

FTestbed1StructInt UTestbed1StructInterfaceImplementation::FuncInt(const FTestbed1StructInt& ParamInt)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructInterface.Impl.FuncInt");
	(void)ParamInt;
	// do business logic here
	return FTestbed1StructInt();
}

FTestbed1StructFloat UTestbed1StructInterfaceImplementation::FuncFloat(const FTestbed1StructFloat& ParamFloat)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructInterface.Impl.FuncFloat");
	(void)ParamFloat;
	// do business logic here
	return FTestbed1StructFloat();
}

FTestbed1StructString UTestbed1StructInterfaceImplementation::FuncString(const FTestbed1StructString& ParamString)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructInterface.Impl.FuncString");
	(void)ParamString;
	// do business logic here
	return FTestbed1StructString();
}

void UTestbed1StructInterfaceImplementation::_ResetProperties()
{
	if (PropBool != FTestbed1StructBool())
	{
		PropBool = FTestbed1StructBool();
		_GetPublisher()->BroadcastPropBoolChanged(PropBool);
	}
	if (PropInt != FTestbed1StructInt())
	{
		PropInt = FTestbed1StructInt();
		_GetPublisher()->BroadcastPropIntChanged(PropInt);
	}
	if (PropFloat != FTestbed1StructFloat())
	{
		PropFloat = FTestbed1StructFloat();
		_GetPublisher()->BroadcastPropFloatChanged(PropFloat);
	}
	if (PropString != FTestbed1StructString())
	{
		PropString = FTestbed1StructString();
		_GetPublisher()->BroadcastPropStringChanged(PropString);
	}
}
