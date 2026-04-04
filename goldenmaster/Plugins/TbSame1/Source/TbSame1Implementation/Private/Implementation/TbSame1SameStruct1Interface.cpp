// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "TbSame1/Implementation/TbSame1SameStruct1Interface.h"

UTbSame1SameStruct1InterfaceImplementation::~UTbSame1SameStruct1InterfaceImplementation() = default;
FTbSame1Struct1 UTbSame1SameStruct1InterfaceImplementation::GetProp1() const
{
	return Prop1;
}

void UTbSame1SameStruct1InterfaceImplementation::SetProp1(const FTbSame1Struct1& InProp1)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSame1.SameStruct1Interface.Impl.SetProp1");
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		_GetPublisher()->BroadcastProp1Changed(Prop1);
	}
}

FTbSame1Struct1 UTbSame1SameStruct1InterfaceImplementation::Func1(const FTbSame1Struct1& Param1)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSame1.SameStruct1Interface.Impl.Func1");
	(void)Param1;
	// do business logic here
	return FTbSame1Struct1();
}

void UTbSame1SameStruct1InterfaceImplementation::_ResetProperties()
{
	if (Prop1 != FTbSame1Struct1())
	{
		Prop1 = FTbSame1Struct1();
		_GetPublisher()->BroadcastProp1Changed(Prop1);
	}
}
