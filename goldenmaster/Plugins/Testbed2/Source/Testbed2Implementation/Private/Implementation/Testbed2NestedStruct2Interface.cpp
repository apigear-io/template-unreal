// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "Testbed2/Implementation/Testbed2NestedStruct2Interface.h"

UTestbed2NestedStruct2InterfaceImplementation::~UTestbed2NestedStruct2InterfaceImplementation() = default;
FTestbed2NestedStruct1 UTestbed2NestedStruct2InterfaceImplementation::GetProp1() const
{
	return Prop1;
}

void UTestbed2NestedStruct2InterfaceImplementation::SetProp1(const FTestbed2NestedStruct1& InProp1)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed2.NestedStruct2Interface.Impl.SetProp1");
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		_GetPublisher()->BroadcastProp1Changed(Prop1);
	}
}
FTestbed2NestedStruct2 UTestbed2NestedStruct2InterfaceImplementation::GetProp2() const
{
	return Prop2;
}

void UTestbed2NestedStruct2InterfaceImplementation::SetProp2(const FTestbed2NestedStruct2& InProp2)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed2.NestedStruct2Interface.Impl.SetProp2");
	if (Prop2 != InProp2)
	{
		Prop2 = InProp2;
		_GetPublisher()->BroadcastProp2Changed(Prop2);
	}
}

FTestbed2NestedStruct1 UTestbed2NestedStruct2InterfaceImplementation::Func1(const FTestbed2NestedStruct1& Param1)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed2.NestedStruct2Interface.Impl.Func1");
	(void)Param1;
	// do business logic here
	return FTestbed2NestedStruct1();
}

FTestbed2NestedStruct1 UTestbed2NestedStruct2InterfaceImplementation::Func2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed2.NestedStruct2Interface.Impl.Func2");
	(void)Param1;
	(void)Param2;
	// do business logic here
	return FTestbed2NestedStruct1();
}

void UTestbed2NestedStruct2InterfaceImplementation::_ResetProperties()
{
	if (Prop1 != FTestbed2NestedStruct1())
	{
		Prop1 = FTestbed2NestedStruct1();
		_GetPublisher()->BroadcastProp1Changed(Prop1);
	}
	if (Prop2 != FTestbed2NestedStruct2())
	{
		Prop2 = FTestbed2NestedStruct2();
		_GetPublisher()->BroadcastProp2Changed(Prop2);
	}
}
