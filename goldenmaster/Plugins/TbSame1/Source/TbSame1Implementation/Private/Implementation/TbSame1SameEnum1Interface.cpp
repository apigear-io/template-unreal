// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "TbSame1/Implementation/TbSame1SameEnum1Interface.h"

UTbSame1SameEnum1InterfaceImplementation::~UTbSame1SameEnum1InterfaceImplementation() = default;
ETbSame1Enum1 UTbSame1SameEnum1InterfaceImplementation::GetProp1() const
{
	return Prop1;
}

void UTbSame1SameEnum1InterfaceImplementation::SetProp1(ETbSame1Enum1 InProp1)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSame1.SameEnum1Interface.Impl.SetProp1");
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		_GetPublisher()->BroadcastProp1Changed(Prop1);
	}
}

ETbSame1Enum1 UTbSame1SameEnum1InterfaceImplementation::Func1(ETbSame1Enum1 Param1)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSame1.SameEnum1Interface.Impl.Func1");
	(void)Param1;
	// do business logic here
	return ETbSame1Enum1::TS1E1_Value1;
}

void UTbSame1SameEnum1InterfaceImplementation::_ResetProperties()
{
	if (Prop1 != ETbSame1Enum1::TS1E1_Value1)
	{
		Prop1 = ETbSame1Enum1::TS1E1_Value1;
		_GetPublisher()->BroadcastProp1Changed(Prop1);
	}
}
