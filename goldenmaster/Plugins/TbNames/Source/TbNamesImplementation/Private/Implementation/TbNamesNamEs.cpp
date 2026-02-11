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

#include "TbNames/Implementation/TbNamesNamEs.h"
#include "Misc/ScopeRWLock.h"

UTbNamesNamEsImplementation::~UTbNamesNamEsImplementation() = default;
bool UTbNamesNamEsImplementation::GetSwitch() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(bSwitchRWLock);
#endif
	return bSwitch;
}

void UTbNamesNamEsImplementation::SetSwitch(bool bInSwitch)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbNames.NamEs.Impl.SetSwitch");
	if (bSwitch != bInSwitch)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(bSwitchRWLock);
			bSwitch = bInSwitch;
		}
#else
		bSwitch = bInSwitch;
#endif
		_GetPublisher()->BroadcastSwitchChanged(bSwitch);
	}
}
int32 UTbNamesNamEsImplementation::GetSomeProperty() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(SomePropertyRWLock);
#endif
	return SomeProperty;
}

void UTbNamesNamEsImplementation::SetSomeProperty(int32 InSomeProperty)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbNames.NamEs.Impl.SetSomeProperty");
	if (SomeProperty != InSomeProperty)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(SomePropertyRWLock);
			SomeProperty = InSomeProperty;
		}
#else
		SomeProperty = InSomeProperty;
#endif
		_GetPublisher()->BroadcastSomePropertyChanged(SomeProperty);
	}
}
int32 UTbNamesNamEsImplementation::GetSomePoperty2() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(SomePoperty2RWLock);
#endif
	return SomePoperty2;
}

void UTbNamesNamEsImplementation::SetSomePoperty2(int32 InSomePoperty2)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbNames.NamEs.Impl.SetSomePoperty2");
	if (SomePoperty2 != InSomePoperty2)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(SomePoperty2RWLock);
			SomePoperty2 = InSomePoperty2;
		}
#else
		SomePoperty2 = InSomePoperty2;
#endif
		_GetPublisher()->BroadcastSomePoperty2Changed(SomePoperty2);
	}
}
ETbNamesEnum_With_Under_scores UTbNamesNamEsImplementation::GetEnumProperty() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(EnumPropertyRWLock);
#endif
	return EnumProperty;
}

void UTbNamesNamEsImplementation::SetEnumProperty(ETbNamesEnum_With_Under_scores InEnumProperty)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbNames.NamEs.Impl.SetEnumProperty");
	if (EnumProperty != InEnumProperty)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(EnumPropertyRWLock);
			EnumProperty = InEnumProperty;
		}
#else
		EnumProperty = InEnumProperty;
#endif
		_GetPublisher()->BroadcastEnumPropertyChanged(EnumProperty);
	}
}

void UTbNamesNamEsImplementation::SomeFunction(bool bSomeParam)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbNames.NamEs.Impl.SomeFunction");
	(void)bSomeParam;
	// do business logic here
}

void UTbNamesNamEsImplementation::SomeFunction2(bool bSomeParam)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbNames.NamEs.Impl.SomeFunction2");
	(void)bSomeParam;
	// do business logic here
}

void UTbNamesNamEsImplementation::_ResetProperties()
{
	if (bSwitch != false)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(bSwitchRWLock);
			bSwitch = false;
		}
#else
		bSwitch = false;
#endif
		_GetPublisher()->BroadcastSwitchChanged(bSwitch);
	}
	if (SomeProperty != 0)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(SomePropertyRWLock);
			SomeProperty = 0;
		}
#else
		SomeProperty = 0;
#endif
		_GetPublisher()->BroadcastSomePropertyChanged(SomeProperty);
	}
	if (SomePoperty2 != 0)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(SomePoperty2RWLock);
			SomePoperty2 = 0;
		}
#else
		SomePoperty2 = 0;
#endif
		_GetPublisher()->BroadcastSomePoperty2Changed(SomePoperty2);
	}
	if (EnumProperty != ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(EnumPropertyRWLock);
			EnumProperty = ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue;
		}
#else
		EnumProperty = ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue;
#endif
		_GetPublisher()->BroadcastEnumPropertyChanged(EnumProperty);
	}
}
