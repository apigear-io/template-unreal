// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "TbSame2/Implementation/TbSame2SameStruct1Interface.h"

UTbSame2SameStruct1InterfaceImplementation::~UTbSame2SameStruct1InterfaceImplementation() = default;
FTbSame2Struct1 UTbSame2SameStruct1InterfaceImplementation::GetProp1() const
{
	return Prop1;
}

void UTbSame2SameStruct1InterfaceImplementation::SetProp1(const FTbSame2Struct1& InProp1)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSame2.SameStruct1Interface.Impl.SetProp1");
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		_GetPublisher()->BroadcastProp1Changed(Prop1);
	}
}

FTbSame2Struct1 UTbSame2SameStruct1InterfaceImplementation::Func1(const FTbSame2Struct1& Param1)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSame2.SameStruct1Interface.Impl.Func1");
	(void)Param1;
	// do business logic here
	return FTbSame2Struct1();
}

void UTbSame2SameStruct1InterfaceImplementation::_ResetProperties()
{
	if (Prop1 != FTbSame2Struct1())
	{
		Prop1 = FTbSame2Struct1();
		_GetPublisher()->BroadcastProp1Changed(Prop1);
	}
}
