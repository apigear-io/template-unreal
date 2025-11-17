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
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArray2Interface.Impl.SetPropBool");
	if (PropBool != InPropBool)
	{
		PropBool = InPropBool;
		_GetPublisher()->BroadcastPropBoolChanged(PropBool);
	}
}
FTestbed1StructIntWithArray UTestbed1StructArray2InterfaceImplementation::GetPropInt() const
{
	return PropInt;
}

void UTestbed1StructArray2InterfaceImplementation::SetPropInt(const FTestbed1StructIntWithArray& InPropInt)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArray2Interface.Impl.SetPropInt");
	if (PropInt != InPropInt)
	{
		PropInt = InPropInt;
		_GetPublisher()->BroadcastPropIntChanged(PropInt);
	}
}
FTestbed1StructFloatWithArray UTestbed1StructArray2InterfaceImplementation::GetPropFloat() const
{
	return PropFloat;
}

void UTestbed1StructArray2InterfaceImplementation::SetPropFloat(const FTestbed1StructFloatWithArray& InPropFloat)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArray2Interface.Impl.SetPropFloat");
	if (PropFloat != InPropFloat)
	{
		PropFloat = InPropFloat;
		_GetPublisher()->BroadcastPropFloatChanged(PropFloat);
	}
}
FTestbed1StructStringWithArray UTestbed1StructArray2InterfaceImplementation::GetPropString() const
{
	return PropString;
}

void UTestbed1StructArray2InterfaceImplementation::SetPropString(const FTestbed1StructStringWithArray& InPropString)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArray2Interface.Impl.SetPropString");
	if (PropString != InPropString)
	{
		PropString = InPropString;
		_GetPublisher()->BroadcastPropStringChanged(PropString);
	}
}
FTestbed1StructEnumWithArray UTestbed1StructArray2InterfaceImplementation::GetPropEnum() const
{
	return PropEnum;
}

void UTestbed1StructArray2InterfaceImplementation::SetPropEnum(const FTestbed1StructEnumWithArray& InPropEnum)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArray2Interface.Impl.SetPropEnum");
	if (PropEnum != InPropEnum)
	{
		PropEnum = InPropEnum;
		_GetPublisher()->BroadcastPropEnumChanged(PropEnum);
	}
}

TArray<FTestbed1StructBool> UTestbed1StructArray2InterfaceImplementation::FuncBool(const FTestbed1StructBoolWithArray& ParamBool)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArray2Interface.Impl.FuncBool");
	(void)ParamBool;
	// do business logic here
	return TArray<FTestbed1StructBool>();
}

TArray<FTestbed1StructInt> UTestbed1StructArray2InterfaceImplementation::FuncInt(const FTestbed1StructIntWithArray& ParamInt)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArray2Interface.Impl.FuncInt");
	(void)ParamInt;
	// do business logic here
	return TArray<FTestbed1StructInt>();
}

TArray<FTestbed1StructFloat> UTestbed1StructArray2InterfaceImplementation::FuncFloat(const FTestbed1StructFloatWithArray& ParamFloat)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArray2Interface.Impl.FuncFloat");
	(void)ParamFloat;
	// do business logic here
	return TArray<FTestbed1StructFloat>();
}

TArray<FTestbed1StructString> UTestbed1StructArray2InterfaceImplementation::FuncString(const FTestbed1StructStringWithArray& ParamString)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArray2Interface.Impl.FuncString");
	(void)ParamString;
	// do business logic here
	return TArray<FTestbed1StructString>();
}

TArray<ETestbed1Enum0> UTestbed1StructArray2InterfaceImplementation::FuncEnum(const FTestbed1StructEnumWithArray& ParamEnum)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArray2Interface.Impl.FuncEnum");
	(void)ParamEnum;
	// do business logic here
	return TArray<ETestbed1Enum0>();
}

void UTestbed1StructArray2InterfaceImplementation::_ResetProperties()
{
	if (PropBool != FTestbed1StructBoolWithArray())
	{
		PropBool = FTestbed1StructBoolWithArray();
		_GetPublisher()->BroadcastPropBoolChanged(PropBool);
	}
	if (PropInt != FTestbed1StructIntWithArray())
	{
		PropInt = FTestbed1StructIntWithArray();
		_GetPublisher()->BroadcastPropIntChanged(PropInt);
	}
	if (PropFloat != FTestbed1StructFloatWithArray())
	{
		PropFloat = FTestbed1StructFloatWithArray();
		_GetPublisher()->BroadcastPropFloatChanged(PropFloat);
	}
	if (PropString != FTestbed1StructStringWithArray())
	{
		PropString = FTestbed1StructStringWithArray();
		_GetPublisher()->BroadcastPropStringChanged(PropString);
	}
	if (PropEnum != FTestbed1StructEnumWithArray())
	{
		PropEnum = FTestbed1StructEnumWithArray();
		_GetPublisher()->BroadcastPropEnumChanged(PropEnum);
	}
}
