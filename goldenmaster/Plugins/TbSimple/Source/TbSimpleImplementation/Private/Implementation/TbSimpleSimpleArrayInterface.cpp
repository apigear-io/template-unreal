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

#include "TbSimple/Implementation/TbSimpleSimpleArrayInterface.h"
#include "Misc/ScopeRWLock.h"

UTbSimpleSimpleArrayInterfaceImplementation::~UTbSimpleSimpleArrayInterfaceImplementation() = default;
TArray<bool> UTbSimpleSimpleArrayInterfaceImplementation::GetPropBool() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(PropBoolRWLock);
#endif
	return PropBool;
}

void UTbSimpleSimpleArrayInterfaceImplementation::SetPropBool(const TArray<bool>& InPropBool)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.SimpleArrayInterface.Impl.SetPropBool");
	if (PropBool != InPropBool)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropBoolRWLock);
			PropBool = InPropBool;
		}
#else
		PropBool = InPropBool;
#endif
		_GetPublisher()->BroadcastPropBoolChanged(PropBool);
	}
}
TArray<int32> UTbSimpleSimpleArrayInterfaceImplementation::GetPropInt() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(PropIntRWLock);
#endif
	return PropInt;
}

void UTbSimpleSimpleArrayInterfaceImplementation::SetPropInt(const TArray<int32>& InPropInt)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.SimpleArrayInterface.Impl.SetPropInt");
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
TArray<int32> UTbSimpleSimpleArrayInterfaceImplementation::GetPropInt32() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(PropInt32RWLock);
#endif
	return PropInt32;
}

void UTbSimpleSimpleArrayInterfaceImplementation::SetPropInt32(const TArray<int32>& InPropInt32)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.SimpleArrayInterface.Impl.SetPropInt32");
	if (PropInt32 != InPropInt32)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropInt32RWLock);
			PropInt32 = InPropInt32;
		}
#else
		PropInt32 = InPropInt32;
#endif
		_GetPublisher()->BroadcastPropInt32Changed(PropInt32);
	}
}
TArray<int64> UTbSimpleSimpleArrayInterfaceImplementation::GetPropInt64() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(PropInt64RWLock);
#endif
	return PropInt64;
}

void UTbSimpleSimpleArrayInterfaceImplementation::SetPropInt64(const TArray<int64>& InPropInt64)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.SimpleArrayInterface.Impl.SetPropInt64");
	if (PropInt64 != InPropInt64)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropInt64RWLock);
			PropInt64 = InPropInt64;
		}
#else
		PropInt64 = InPropInt64;
#endif
		_GetPublisher()->BroadcastPropInt64Changed(PropInt64);
	}
}
TArray<float> UTbSimpleSimpleArrayInterfaceImplementation::GetPropFloat() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(PropFloatRWLock);
#endif
	return PropFloat;
}

void UTbSimpleSimpleArrayInterfaceImplementation::SetPropFloat(const TArray<float>& InPropFloat)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.SimpleArrayInterface.Impl.SetPropFloat");
	if (PropFloat != InPropFloat)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropFloatRWLock);
			PropFloat = InPropFloat;
		}
#else
		PropFloat = InPropFloat;
#endif
		_GetPublisher()->BroadcastPropFloatChanged(PropFloat);
	}
}
TArray<float> UTbSimpleSimpleArrayInterfaceImplementation::GetPropFloat32() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(PropFloat32RWLock);
#endif
	return PropFloat32;
}

void UTbSimpleSimpleArrayInterfaceImplementation::SetPropFloat32(const TArray<float>& InPropFloat32)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.SimpleArrayInterface.Impl.SetPropFloat32");
	if (PropFloat32 != InPropFloat32)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropFloat32RWLock);
			PropFloat32 = InPropFloat32;
		}
#else
		PropFloat32 = InPropFloat32;
#endif
		_GetPublisher()->BroadcastPropFloat32Changed(PropFloat32);
	}
}
TArray<double> UTbSimpleSimpleArrayInterfaceImplementation::GetPropFloat64() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(PropFloat64RWLock);
#endif
	return PropFloat64;
}

void UTbSimpleSimpleArrayInterfaceImplementation::SetPropFloat64(const TArray<double>& InPropFloat64)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.SimpleArrayInterface.Impl.SetPropFloat64");
	if (PropFloat64 != InPropFloat64)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropFloat64RWLock);
			PropFloat64 = InPropFloat64;
		}
#else
		PropFloat64 = InPropFloat64;
#endif
		_GetPublisher()->BroadcastPropFloat64Changed(PropFloat64);
	}
}
TArray<FString> UTbSimpleSimpleArrayInterfaceImplementation::GetPropString() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(PropStringRWLock);
#endif
	return PropString;
}

void UTbSimpleSimpleArrayInterfaceImplementation::SetPropString(const TArray<FString>& InPropString)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.SimpleArrayInterface.Impl.SetPropString");
	if (PropString != InPropString)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropStringRWLock);
			PropString = InPropString;
		}
#else
		PropString = InPropString;
#endif
		_GetPublisher()->BroadcastPropStringChanged(PropString);
	}
}
FString UTbSimpleSimpleArrayInterfaceImplementation::GetPropReadOnlyString() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(PropReadOnlyStringRWLock);
#endif
	return PropReadOnlyString;
}

TArray<bool> UTbSimpleSimpleArrayInterfaceImplementation::FuncBool(const TArray<bool>& ParamBool)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.SimpleArrayInterface.Impl.FuncBool");
	(void)ParamBool;
	// do business logic here
	return TArray<bool>();
}

TArray<int32> UTbSimpleSimpleArrayInterfaceImplementation::FuncInt(const TArray<int32>& ParamInt)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.SimpleArrayInterface.Impl.FuncInt");
	(void)ParamInt;
	// do business logic here
	return TArray<int32>();
}

TArray<int32> UTbSimpleSimpleArrayInterfaceImplementation::FuncInt32(const TArray<int32>& ParamInt32)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.SimpleArrayInterface.Impl.FuncInt32");
	(void)ParamInt32;
	// do business logic here
	return TArray<int32>();
}

TArray<int64> UTbSimpleSimpleArrayInterfaceImplementation::FuncInt64(const TArray<int64>& ParamInt64)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.SimpleArrayInterface.Impl.FuncInt64");
	(void)ParamInt64;
	// do business logic here
	return TArray<int64>();
}

TArray<float> UTbSimpleSimpleArrayInterfaceImplementation::FuncFloat(const TArray<float>& ParamFloat)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.SimpleArrayInterface.Impl.FuncFloat");
	(void)ParamFloat;
	// do business logic here
	return TArray<float>();
}

TArray<float> UTbSimpleSimpleArrayInterfaceImplementation::FuncFloat32(const TArray<float>& ParamFloat32)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.SimpleArrayInterface.Impl.FuncFloat32");
	(void)ParamFloat32;
	// do business logic here
	return TArray<float>();
}

TArray<double> UTbSimpleSimpleArrayInterfaceImplementation::FuncFloat64(const TArray<double>& ParamFloat)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.SimpleArrayInterface.Impl.FuncFloat64");
	(void)ParamFloat;
	// do business logic here
	return TArray<double>();
}

TArray<FString> UTbSimpleSimpleArrayInterfaceImplementation::FuncString(const TArray<FString>& ParamString)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.SimpleArrayInterface.Impl.FuncString");
	(void)ParamString;
	// do business logic here
	return TArray<FString>();
}

void UTbSimpleSimpleArrayInterfaceImplementation::_ResetProperties()
{
	if (PropBool != TArray<bool>())
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropBoolRWLock);
			PropBool = TArray<bool>();
		}
#else
		PropBool = TArray<bool>();
#endif
		_GetPublisher()->BroadcastPropBoolChanged(PropBool);
	}
	if (PropInt != TArray<int32>())
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropIntRWLock);
			PropInt = TArray<int32>();
		}
#else
		PropInt = TArray<int32>();
#endif
		_GetPublisher()->BroadcastPropIntChanged(PropInt);
	}
	if (PropInt32 != TArray<int32>())
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropInt32RWLock);
			PropInt32 = TArray<int32>();
		}
#else
		PropInt32 = TArray<int32>();
#endif
		_GetPublisher()->BroadcastPropInt32Changed(PropInt32);
	}
	if (PropInt64 != TArray<int64>())
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropInt64RWLock);
			PropInt64 = TArray<int64>();
		}
#else
		PropInt64 = TArray<int64>();
#endif
		_GetPublisher()->BroadcastPropInt64Changed(PropInt64);
	}
	if (PropFloat != TArray<float>())
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropFloatRWLock);
			PropFloat = TArray<float>();
		}
#else
		PropFloat = TArray<float>();
#endif
		_GetPublisher()->BroadcastPropFloatChanged(PropFloat);
	}
	if (PropFloat32 != TArray<float>())
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropFloat32RWLock);
			PropFloat32 = TArray<float>();
		}
#else
		PropFloat32 = TArray<float>();
#endif
		_GetPublisher()->BroadcastPropFloat32Changed(PropFloat32);
	}
	if (PropFloat64 != TArray<double>())
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropFloat64RWLock);
			PropFloat64 = TArray<double>();
		}
#else
		PropFloat64 = TArray<double>();
#endif
		_GetPublisher()->BroadcastPropFloat64Changed(PropFloat64);
	}
	if (PropString != TArray<FString>())
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropStringRWLock);
			PropString = TArray<FString>();
		}
#else
		PropString = TArray<FString>();
#endif
		_GetPublisher()->BroadcastPropStringChanged(PropString);
	}
	if (PropReadOnlyString != FString())
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropReadOnlyStringRWLock);
			PropReadOnlyString = FString();
		}
#else
		PropReadOnlyString = FString();
#endif
		_GetPublisher()->BroadcastPropReadOnlyStringChanged(PropReadOnlyString);
	}
}
