// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "TbRefIfaces/Implementation/TbRefIfacesSimpleLocalIf.h"
#include "Misc/ScopeRWLock.h"

UTbRefIfacesSimpleLocalIfImplementation::~UTbRefIfacesSimpleLocalIfImplementation() = default;
int32 UTbRefIfacesSimpleLocalIfImplementation::GetIntProperty() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(IntPropertyRWLock);
#endif
	return IntProperty;
}

void UTbRefIfacesSimpleLocalIfImplementation::SetIntProperty(int32 InIntProperty)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbRefIfaces.SimpleLocalIf.Impl.SetIntProperty");
	if (IntProperty != InIntProperty)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(IntPropertyRWLock);
			IntProperty = InIntProperty;
		}
#else
		IntProperty = InIntProperty;
#endif
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
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(IntPropertyRWLock);
			IntProperty = 0;
		}
#else
		IntProperty = 0;
#endif
		_GetPublisher()->BroadcastIntPropertyChanged(IntProperty);
	}
}
