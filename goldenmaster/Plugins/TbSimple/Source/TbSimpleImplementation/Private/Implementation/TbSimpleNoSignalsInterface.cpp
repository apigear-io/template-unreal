/**
Copyright 2021 ApiGear UG
Copyright 2021 Epic Games, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

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
