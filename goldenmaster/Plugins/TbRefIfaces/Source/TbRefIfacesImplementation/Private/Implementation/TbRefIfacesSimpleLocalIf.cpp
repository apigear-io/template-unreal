// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "TbRefIfaces/Implementation/TbRefIfacesSimpleLocalIf.h"

UTbRefIfacesSimpleLocalIfImplementation::~UTbRefIfacesSimpleLocalIfImplementation() = default;
int32 UTbRefIfacesSimpleLocalIfImplementation::GetIntProperty() const
{
	return IntProperty;
}

void UTbRefIfacesSimpleLocalIfImplementation::SetIntProperty(int32 InIntProperty)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbRefIfaces.SimpleLocalIf.Impl.SetIntProperty");
	if (IntProperty != InIntProperty)
	{
		IntProperty = InIntProperty;
		_GetPublisher()->BroadcastIntPropertyChanged(IntProperty);
	}
}

int32 UTbRefIfacesSimpleLocalIfImplementation::IntMethod(int32 Param)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbRefIfaces.SimpleLocalIf.Impl.IntMethod");
	(void)Param;
	// do business logic here
	return 0;
}

void UTbRefIfacesSimpleLocalIfImplementation::_ResetProperties()
{
	if (IntProperty != 0)
	{
		IntProperty = 0;
		_GetPublisher()->BroadcastIntPropertyChanged(IntProperty);
	}
}
