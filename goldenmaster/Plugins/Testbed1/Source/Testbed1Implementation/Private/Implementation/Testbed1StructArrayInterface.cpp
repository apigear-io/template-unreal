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
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArrayInterface.Impl.SetPropBool");
	if (PropBool != InPropBool)
	{
		PropBool = InPropBool;
		_GetPublisher()->BroadcastPropBoolChanged(PropBool);
	}
}
TArray<FTestbed1StructInt> UTestbed1StructArrayInterfaceImplementation::GetPropInt() const
{
	return PropInt;
}

void UTestbed1StructArrayInterfaceImplementation::SetPropInt(const TArray<FTestbed1StructInt>& InPropInt)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArrayInterface.Impl.SetPropInt");
	if (PropInt != InPropInt)
	{
		PropInt = InPropInt;
		_GetPublisher()->BroadcastPropIntChanged(PropInt);
	}
}
TArray<FTestbed1StructFloat> UTestbed1StructArrayInterfaceImplementation::GetPropFloat() const
{
	return PropFloat;
}

void UTestbed1StructArrayInterfaceImplementation::SetPropFloat(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArrayInterface.Impl.SetPropFloat");
	if (PropFloat != InPropFloat)
	{
		PropFloat = InPropFloat;
		_GetPublisher()->BroadcastPropFloatChanged(PropFloat);
	}
}
TArray<FTestbed1StructString> UTestbed1StructArrayInterfaceImplementation::GetPropString() const
{
	return PropString;
}

void UTestbed1StructArrayInterfaceImplementation::SetPropString(const TArray<FTestbed1StructString>& InPropString)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArrayInterface.Impl.SetPropString");
	if (PropString != InPropString)
	{
		PropString = InPropString;
		_GetPublisher()->BroadcastPropStringChanged(PropString);
	}
}
TArray<ETestbed1Enum0> UTestbed1StructArrayInterfaceImplementation::GetPropEnum() const
{
	return PropEnum;
}

void UTestbed1StructArrayInterfaceImplementation::SetPropEnum(const TArray<ETestbed1Enum0>& InPropEnum)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArrayInterface.Impl.SetPropEnum");
	if (PropEnum != InPropEnum)
	{
		PropEnum = InPropEnum;
		_GetPublisher()->BroadcastPropEnumChanged(PropEnum);
	}
}

TArray<FTestbed1StructBool> UTestbed1StructArrayInterfaceImplementation::FuncBool(const TArray<FTestbed1StructBool>& ParamBool)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArrayInterface.Impl.FuncBool");
	(void)ParamBool;
	// do business logic here
	return TArray<FTestbed1StructBool>();
}

TArray<FTestbed1StructInt> UTestbed1StructArrayInterfaceImplementation::FuncInt(const TArray<FTestbed1StructInt>& ParamInt)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArrayInterface.Impl.FuncInt");
	(void)ParamInt;
	// do business logic here
	return TArray<FTestbed1StructInt>();
}

TArray<FTestbed1StructFloat> UTestbed1StructArrayInterfaceImplementation::FuncFloat(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArrayInterface.Impl.FuncFloat");
	(void)ParamFloat;
	// do business logic here
	return TArray<FTestbed1StructFloat>();
}

TArray<FTestbed1StructString> UTestbed1StructArrayInterfaceImplementation::FuncString(const TArray<FTestbed1StructString>& ParamString)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArrayInterface.Impl.FuncString");
	(void)ParamString;
	// do business logic here
	return TArray<FTestbed1StructString>();
}

TArray<ETestbed1Enum0> UTestbed1StructArrayInterfaceImplementation::FuncEnum(const TArray<ETestbed1Enum0>& ParamEnum)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArrayInterface.Impl.FuncEnum");
	(void)ParamEnum;
	// do business logic here
	return TArray<ETestbed1Enum0>();
}

void UTestbed1StructArrayInterfaceImplementation::_ResetProperties()
{
	if (PropBool != TArray<FTestbed1StructBool>())
	{
		PropBool = TArray<FTestbed1StructBool>();
		_GetPublisher()->BroadcastPropBoolChanged(PropBool);
	}
	if (PropInt != TArray<FTestbed1StructInt>())
	{
		PropInt = TArray<FTestbed1StructInt>();
		_GetPublisher()->BroadcastPropIntChanged(PropInt);
	}
	if (PropFloat != TArray<FTestbed1StructFloat>())
	{
		PropFloat = TArray<FTestbed1StructFloat>();
		_GetPublisher()->BroadcastPropFloatChanged(PropFloat);
	}
	if (PropString != TArray<FTestbed1StructString>())
	{
		PropString = TArray<FTestbed1StructString>();
		_GetPublisher()->BroadcastPropStringChanged(PropString);
	}
	if (PropEnum != TArray<ETestbed1Enum0>())
	{
		PropEnum = TArray<ETestbed1Enum0>();
		_GetPublisher()->BroadcastPropEnumChanged(PropEnum);
	}
}
