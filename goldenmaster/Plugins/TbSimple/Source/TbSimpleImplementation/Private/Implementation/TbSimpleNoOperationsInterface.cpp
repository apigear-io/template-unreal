// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "TbSimple/Implementation/TbSimpleNoOperationsInterface.h"

UTbSimpleNoOperationsInterfaceImplementation::~UTbSimpleNoOperationsInterfaceImplementation() = default;
bool UTbSimpleNoOperationsInterfaceImplementation::GetPropBool() const
{
	return bPropBool;
}

void UTbSimpleNoOperationsInterfaceImplementation::SetPropBool(bool bInPropBool)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.NoOperationsInterface.Impl.SetPropBool");
	if (bPropBool != bInPropBool)
	{
		bPropBool = bInPropBool;
		_GetPublisher()->BroadcastPropBoolChanged(bPropBool);
	}
}
int32 UTbSimpleNoOperationsInterfaceImplementation::GetPropInt() const
{
	return PropInt;
}

void UTbSimpleNoOperationsInterfaceImplementation::SetPropInt(int32 InPropInt)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.NoOperationsInterface.Impl.SetPropInt");
	if (PropInt != InPropInt)
	{
		PropInt = InPropInt;
		_GetPublisher()->BroadcastPropIntChanged(PropInt);
	}
}

void UTbSimpleNoOperationsInterfaceImplementation::_ResetProperties()
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
