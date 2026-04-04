// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "TbSimple/Implementation/TbSimpleNoSignalsInterface.h"

UTbSimpleNoSignalsInterfaceImplementation::~UTbSimpleNoSignalsInterfaceImplementation() = default;
bool UTbSimpleNoSignalsInterfaceImplementation::GetPropBool() const
{
	return bPropBool;
}

void UTbSimpleNoSignalsInterfaceImplementation::SetPropBool(bool bInPropBool)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.NoSignalsInterface.Impl.SetPropBool");
	if (bPropBool != bInPropBool)
	{
		bPropBool = bInPropBool;
		_GetPublisher()->BroadcastPropBoolChanged(bPropBool);
	}
}
int32 UTbSimpleNoSignalsInterfaceImplementation::GetPropInt() const
{
	return PropInt;
}

void UTbSimpleNoSignalsInterfaceImplementation::SetPropInt(int32 InPropInt)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.NoSignalsInterface.Impl.SetPropInt");
	if (PropInt != InPropInt)
	{
		PropInt = InPropInt;
		_GetPublisher()->BroadcastPropIntChanged(PropInt);
	}
}

void UTbSimpleNoSignalsInterfaceImplementation::FuncVoid()
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.NoSignalsInterface.Impl.FuncVoid");
	// do business logic here
}

bool UTbSimpleNoSignalsInterfaceImplementation::FuncBool(bool bParamBool)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.NoSignalsInterface.Impl.FuncBool");
	(void)bParamBool;
	// do business logic here
	return false;
}

void UTbSimpleNoSignalsInterfaceImplementation::_ResetProperties()
{
	if (bPropBool != false)
	{
		bPropBool = false;
		_GetPublisher()->BroadcastPropBoolChanged(bPropBool);
	}
	if (PropInt != 0)
	{
		PropInt = 0;
		_GetPublisher()->BroadcastPropIntChanged(PropInt);
	}
}
