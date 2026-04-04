// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "TbStructArray/Implementation/TbStructArrayStructArrayFieldInterface.h"

UTbStructArrayStructArrayFieldInterfaceImplementation::~UTbStructArrayStructArrayFieldInterfaceImplementation() = default;
FTbStructArrayStructWithArrayOfStructs UTbStructArrayStructArrayFieldInterfaceImplementation::GetPropStructArray() const
{
	return PropStructArray;
}

void UTbStructArrayStructArrayFieldInterfaceImplementation::SetPropStructArray(const FTbStructArrayStructWithArrayOfStructs& InPropStructArray)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbStructArray.StructArrayFieldInterface.Impl.SetPropStructArray");
	if (PropStructArray != InPropStructArray)
	{
		PropStructArray = InPropStructArray;
		_GetPublisher()->BroadcastPropStructArrayChanged(PropStructArray);
	}
}
FTbStructArrayStructWithArrayOfEnums UTbStructArrayStructArrayFieldInterfaceImplementation::GetPropEnumArray() const
{
	return PropEnumArray;
}

void UTbStructArrayStructArrayFieldInterfaceImplementation::SetPropEnumArray(const FTbStructArrayStructWithArrayOfEnums& InPropEnumArray)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbStructArray.StructArrayFieldInterface.Impl.SetPropEnumArray");
	if (PropEnumArray != InPropEnumArray)
	{
		PropEnumArray = InPropEnumArray;
		_GetPublisher()->BroadcastPropEnumArrayChanged(PropEnumArray);
	}
}
FTbStructArrayStructWithArrayOfInts UTbStructArrayStructArrayFieldInterfaceImplementation::GetPropIntArray() const
{
	return PropIntArray;
}

void UTbStructArrayStructArrayFieldInterfaceImplementation::SetPropIntArray(const FTbStructArrayStructWithArrayOfInts& InPropIntArray)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbStructArray.StructArrayFieldInterface.Impl.SetPropIntArray");
	if (PropIntArray != InPropIntArray)
	{
		PropIntArray = InPropIntArray;
		_GetPublisher()->BroadcastPropIntArrayChanged(PropIntArray);
	}
}
FTbStructArrayMixedStruct UTbStructArrayStructArrayFieldInterfaceImplementation::GetPropMixed() const
{
	return PropMixed;
}

void UTbStructArrayStructArrayFieldInterfaceImplementation::SetPropMixed(const FTbStructArrayMixedStruct& InPropMixed)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbStructArray.StructArrayFieldInterface.Impl.SetPropMixed");
	if (PropMixed != InPropMixed)
	{
		PropMixed = InPropMixed;
		_GetPublisher()->BroadcastPropMixedChanged(PropMixed);
	}
}

FTbStructArrayMixedStruct UTbStructArrayStructArrayFieldInterfaceImplementation::FuncMixed(const FTbStructArrayMixedStruct& ParamMixed)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbStructArray.StructArrayFieldInterface.Impl.FuncMixed");
	(void)ParamMixed;
	// do business logic here
	return FTbStructArrayMixedStruct();
}

FTbStructArrayStructWithArrayOfStructs UTbStructArrayStructArrayFieldInterfaceImplementation::FuncStructArray(const FTbStructArrayStructWithArrayOfStructs& ParamPoints)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbStructArray.StructArrayFieldInterface.Impl.FuncStructArray");
	(void)ParamPoints;
	// do business logic here
	return FTbStructArrayStructWithArrayOfStructs();
}

void UTbStructArrayStructArrayFieldInterfaceImplementation::_ResetProperties()
{
	if (PropStructArray != FTbStructArrayStructWithArrayOfStructs())
	{
		PropStructArray = FTbStructArrayStructWithArrayOfStructs();
		_GetPublisher()->BroadcastPropStructArrayChanged(PropStructArray);
	}
	if (PropEnumArray != FTbStructArrayStructWithArrayOfEnums())
	{
		PropEnumArray = FTbStructArrayStructWithArrayOfEnums();
		_GetPublisher()->BroadcastPropEnumArrayChanged(PropEnumArray);
	}
	if (PropIntArray != FTbStructArrayStructWithArrayOfInts())
	{
		PropIntArray = FTbStructArrayStructWithArrayOfInts();
		_GetPublisher()->BroadcastPropIntArrayChanged(PropIntArray);
	}
	if (PropMixed != FTbStructArrayMixedStruct())
	{
		PropMixed = FTbStructArrayMixedStruct();
		_GetPublisher()->BroadcastPropMixedChanged(PropMixed);
	}
}
