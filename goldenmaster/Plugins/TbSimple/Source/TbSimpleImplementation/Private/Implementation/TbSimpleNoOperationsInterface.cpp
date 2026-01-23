// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "TbSimple/Implementation/TbSimpleNoOperationsInterface.h"
#include "Misc/ScopeRWLock.h"

UTbSimpleNoOperationsInterfaceImplementation::~UTbSimpleNoOperationsInterfaceImplementation() = default;
bool UTbSimpleNoOperationsInterfaceImplementation::GetPropBool() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(bPropBoolRWLock);
#endif
	return bPropBool;
}

void UTbSimpleNoOperationsInterfaceImplementation::SetPropBool(bool bInPropBool)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.NoOperationsInterface.Impl.SetPropBool");
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
int32 UTbSimpleNoOperationsInterfaceImplementation::GetPropInt() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(PropIntRWLock);
#endif
	return PropInt;
}

void UTbSimpleNoOperationsInterfaceImplementation::SetPropInt(int32 InPropInt)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.NoOperationsInterface.Impl.SetPropInt");
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

void UTbSimpleNoOperationsInterfaceImplementation::_ResetProperties()
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
