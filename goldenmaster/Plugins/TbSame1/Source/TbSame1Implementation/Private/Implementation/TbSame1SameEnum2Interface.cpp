// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "TbSame1/Implementation/TbSame1SameEnum2Interface.h"

UTbSame1SameEnum2InterfaceImplementation::~UTbSame1SameEnum2InterfaceImplementation() = default;
ETbSame1Enum1 UTbSame1SameEnum2InterfaceImplementation::GetProp1() const
{
	return Prop1;
}

void UTbSame1SameEnum2InterfaceImplementation::SetProp1(ETbSame1Enum1 InProp1)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSame1.SameEnum2Interface.Impl.SetProp1");
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		_GetPublisher()->BroadcastProp1Changed(Prop1);
	}
}
ETbSame1Enum2 UTbSame1SameEnum2InterfaceImplementation::GetProp2() const
{
	return Prop2;
}

void UTbSame1SameEnum2InterfaceImplementation::SetProp2(ETbSame1Enum2 InProp2)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSame1.SameEnum2Interface.Impl.SetProp2");
	if (Prop2 != InProp2)
	{
		Prop2 = InProp2;
		_GetPublisher()->BroadcastProp2Changed(Prop2);
	}
}

ETbSame1Enum1 UTbSame1SameEnum2InterfaceImplementation::Func1(ETbSame1Enum1 Param1)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSame1.SameEnum2Interface.Impl.Func1");
	(void)Param1;
	// do business logic here
	return ETbSame1Enum1::TS1E1_Value1;
}

ETbSame1Enum1 UTbSame1SameEnum2InterfaceImplementation::Func2(ETbSame1Enum1 Param1, ETbSame1Enum2 Param2)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSame1.SameEnum2Interface.Impl.Func2");
	(void)Param1;
	(void)Param2;
	// do business logic here
	return ETbSame1Enum1::TS1E1_Value1;
}

void UTbSame1SameEnum2InterfaceImplementation::_ResetProperties()
{
	if (Prop1 != ETbSame1Enum1::TS1E1_Value1)
	{
		Prop1 = ETbSame1Enum1::TS1E1_Value1;
		_GetPublisher()->BroadcastProp1Changed(Prop1);
	}
	if (Prop2 != ETbSame1Enum2::TS1E2_Value1)
	{
		Prop2 = ETbSame1Enum2::TS1E2_Value1;
		_GetPublisher()->BroadcastProp2Changed(Prop2);
	}
}
