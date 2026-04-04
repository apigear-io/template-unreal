// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "TbSame2/Implementation/TbSame2SameEnum1Interface.h"

UTbSame2SameEnum1InterfaceImplementation::~UTbSame2SameEnum1InterfaceImplementation() = default;
ETbSame2Enum1 UTbSame2SameEnum1InterfaceImplementation::GetProp1() const
{
	return Prop1;
}

void UTbSame2SameEnum1InterfaceImplementation::SetProp1(ETbSame2Enum1 InProp1)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSame2.SameEnum1Interface.Impl.SetProp1");
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		_GetPublisher()->BroadcastProp1Changed(Prop1);
	}
}

ETbSame2Enum1 UTbSame2SameEnum1InterfaceImplementation::Func1(ETbSame2Enum1 Param1)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSame2.SameEnum1Interface.Impl.Func1");
	(void)Param1;
	// do business logic here
	return ETbSame2Enum1::TS2E1_Value1;
}

void UTbSame2SameEnum1InterfaceImplementation::_ResetProperties()
{
	if (Prop1 != ETbSame2Enum1::TS2E1_Value1)
	{
		Prop1 = ETbSame2Enum1::TS2E1_Value1;
		_GetPublisher()->BroadcastProp1Changed(Prop1);
	}
}
