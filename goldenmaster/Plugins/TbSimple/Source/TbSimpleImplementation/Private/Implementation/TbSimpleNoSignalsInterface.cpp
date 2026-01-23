// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "TbSimple/Implementation/TbSimpleNoSignalsInterface.h"
#include "Misc/ScopeRWLock.h"

UTbSimpleNoSignalsInterfaceImplementation::~UTbSimpleNoSignalsInterfaceImplementation() = default;
bool UTbSimpleNoSignalsInterfaceImplementation::GetPropBool() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(bPropBoolRWLock);
#endif
	return bPropBool;
}

void UTbSimpleNoSignalsInterfaceImplementation::SetPropBool(bool bInPropBool)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.NoSignalsInterface.Impl.SetPropBool");
	if (bPropBool != bInPropBool)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(bPropBoolRWLock);
			bPropBool = bInPropBool;
		}
#else
		bPropBool = bInPropBool;
#endif
		_GetPublisher()->BroadcastPropBoolChanged(bPropBool);
	}
}
int32 UTbSimpleNoSignalsInterfaceImplementation::GetPropInt() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(PropIntRWLock);
#endif
	return PropInt;
}

void UTbSimpleNoSignalsInterfaceImplementation::SetPropInt(int32 InPropInt)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.NoSignalsInterface.Impl.SetPropInt");
	if (PropInt != InPropInt)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropIntRWLock);
			PropInt = InPropInt;
		}
#else
		PropInt = InPropInt;
#endif
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
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(bPropBoolRWLock);
			bPropBool = false;
		}
#else
		bPropBool = false;
#endif
		_GetPublisher()->BroadcastPropBoolChanged(bPropBool);
	}
	if (PropInt != 0)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropIntRWLock);
			PropInt = 0;
		}
#else
		PropInt = 0;
#endif
		_GetPublisher()->BroadcastPropIntChanged(PropInt);
	}
}
