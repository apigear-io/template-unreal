// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "Testbed2/Implementation/Testbed2NestedStruct1Interface.h"

UTestbed2NestedStruct1InterfaceImplementation::~UTestbed2NestedStruct1InterfaceImplementation() = default;
FTestbed2NestedStruct1 UTestbed2NestedStruct1InterfaceImplementation::GetProp1() const
{
	return Prop1;
}

void UTestbed2NestedStruct1InterfaceImplementation::SetProp1(const FTestbed2NestedStruct1& InProp1)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed2.NestedStruct1Interface.Impl.SetProp1");
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		_GetPublisher()->BroadcastProp1Changed(Prop1);
	}
}

void UTestbed2NestedStruct1InterfaceImplementation::FuncNoReturnValue(const FTestbed2NestedStruct1& Param1)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed2.NestedStruct1Interface.Impl.FuncNoReturnValue");
	(void)Param1;
	// do business logic here
}

FTestbed2NestedStruct1 UTestbed2NestedStruct1InterfaceImplementation::FuncNoParams()
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed2.NestedStruct1Interface.Impl.FuncNoParams");
	// do business logic here
	return FTestbed2NestedStruct1();
}

FTestbed2NestedStruct1 UTestbed2NestedStruct1InterfaceImplementation::Func1(const FTestbed2NestedStruct1& Param1)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed2.NestedStruct1Interface.Impl.Func1");
	(void)Param1;
	// do business logic here
	return FTestbed2NestedStruct1();
}

void UTestbed2NestedStruct1InterfaceImplementation::_ResetProperties()
{
	if (Prop1 != FTestbed2NestedStruct1())
	{
		Prop1 = FTestbed2NestedStruct1();
		_GetPublisher()->BroadcastProp1Changed(Prop1);
	}
}
