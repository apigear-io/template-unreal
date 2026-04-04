// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "TbEnum/Implementation/TbEnumEnumInterface.h"

UTbEnumEnumInterfaceImplementation::~UTbEnumEnumInterfaceImplementation() = default;
ETbEnumEnum0 UTbEnumEnumInterfaceImplementation::GetProp0() const
{
	return Prop0;
}

void UTbEnumEnumInterfaceImplementation::SetProp0(ETbEnumEnum0 InProp0)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbEnum.EnumInterface.Impl.SetProp0");
	if (Prop0 != InProp0)
	{
		Prop0 = InProp0;
		_GetPublisher()->BroadcastProp0Changed(Prop0);
	}
}
ETbEnumEnum1 UTbEnumEnumInterfaceImplementation::GetProp1() const
{
	return Prop1;
}

void UTbEnumEnumInterfaceImplementation::SetProp1(ETbEnumEnum1 InProp1)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbEnum.EnumInterface.Impl.SetProp1");
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		_GetPublisher()->BroadcastProp1Changed(Prop1);
	}
}
ETbEnumEnum2 UTbEnumEnumInterfaceImplementation::GetProp2() const
{
	return Prop2;
}

void UTbEnumEnumInterfaceImplementation::SetProp2(ETbEnumEnum2 InProp2)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbEnum.EnumInterface.Impl.SetProp2");
	if (Prop2 != InProp2)
	{
		Prop2 = InProp2;
		_GetPublisher()->BroadcastProp2Changed(Prop2);
	}
}
ETbEnumEnum3 UTbEnumEnumInterfaceImplementation::GetProp3() const
{
	return Prop3;
}

void UTbEnumEnumInterfaceImplementation::SetProp3(ETbEnumEnum3 InProp3)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbEnum.EnumInterface.Impl.SetProp3");
	if (Prop3 != InProp3)
	{
		Prop3 = InProp3;
		_GetPublisher()->BroadcastProp3Changed(Prop3);
	}
}

ETbEnumEnum0 UTbEnumEnumInterfaceImplementation::Func0(ETbEnumEnum0 Param0)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbEnum.EnumInterface.Impl.Func0");
	(void)Param0;
	// do business logic here
	return ETbEnumEnum0::TEE0_Value0;
}

ETbEnumEnum1 UTbEnumEnumInterfaceImplementation::Func1(ETbEnumEnum1 Param1)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbEnum.EnumInterface.Impl.Func1");
	(void)Param1;
	// do business logic here
	return ETbEnumEnum1::TEE1_Value1;
}

ETbEnumEnum2 UTbEnumEnumInterfaceImplementation::Func2(ETbEnumEnum2 Param2)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbEnum.EnumInterface.Impl.Func2");
	(void)Param2;
	// do business logic here
	return ETbEnumEnum2::TEE2_Value2;
}

ETbEnumEnum3 UTbEnumEnumInterfaceImplementation::Func3(ETbEnumEnum3 Param3)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbEnum.EnumInterface.Impl.Func3");
	(void)Param3;
	// do business logic here
	return ETbEnumEnum3::TEE3_Value3;
}

void UTbEnumEnumInterfaceImplementation::_ResetProperties()
{
	if (Prop0 != ETbEnumEnum0::TEE0_Value0)
	{
		Prop0 = ETbEnumEnum0::TEE0_Value0;
		_GetPublisher()->BroadcastProp0Changed(Prop0);
	}
	if (Prop1 != ETbEnumEnum1::TEE1_Value1)
	{
		Prop1 = ETbEnumEnum1::TEE1_Value1;
		_GetPublisher()->BroadcastProp1Changed(Prop1);
	}
	if (Prop2 != ETbEnumEnum2::TEE2_Value2)
	{
		Prop2 = ETbEnumEnum2::TEE2_Value2;
		_GetPublisher()->BroadcastProp2Changed(Prop2);
	}
	if (Prop3 != ETbEnumEnum3::TEE3_Value3)
	{
		Prop3 = ETbEnumEnum3::TEE3_Value3;
		_GetPublisher()->BroadcastProp3Changed(Prop3);
	}
}
