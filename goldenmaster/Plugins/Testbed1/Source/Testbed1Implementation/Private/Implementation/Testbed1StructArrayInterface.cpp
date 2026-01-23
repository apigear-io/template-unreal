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

#include "Testbed1/Implementation/Testbed1StructArrayInterface.h"
#include "Misc/ScopeRWLock.h"

UTestbed1StructArrayInterfaceImplementation::~UTestbed1StructArrayInterfaceImplementation() = default;
TArray<FTestbed1StructBool> UTestbed1StructArrayInterfaceImplementation::GetPropBool() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(PropBoolRWLock);
#endif
	return PropBool;
}

void UTestbed1StructArrayInterfaceImplementation::SetPropBool(const TArray<FTestbed1StructBool>& InPropBool)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArrayInterface.Impl.SetPropBool");
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
TArray<FTestbed1StructInt> UTestbed1StructArrayInterfaceImplementation::GetPropInt() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(PropIntRWLock);
#endif
	return PropInt;
}

void UTestbed1StructArrayInterfaceImplementation::SetPropInt(const TArray<FTestbed1StructInt>& InPropInt)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArrayInterface.Impl.SetPropInt");
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
TArray<FTestbed1StructFloat> UTestbed1StructArrayInterfaceImplementation::GetPropFloat() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(PropFloatRWLock);
#endif
	return PropFloat;
}

void UTestbed1StructArrayInterfaceImplementation::SetPropFloat(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArrayInterface.Impl.SetPropFloat");
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
TArray<FTestbed1StructString> UTestbed1StructArrayInterfaceImplementation::GetPropString() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(PropStringRWLock);
#endif
	return PropString;
}

void UTestbed1StructArrayInterfaceImplementation::SetPropString(const TArray<FTestbed1StructString>& InPropString)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArrayInterface.Impl.SetPropString");
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
TArray<ETestbed1Enum0> UTestbed1StructArrayInterfaceImplementation::GetPropEnum() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(PropEnumRWLock);
#endif
	return PropEnum;
}

void UTestbed1StructArrayInterfaceImplementation::SetPropEnum(const TArray<ETestbed1Enum0>& InPropEnum)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArrayInterface.Impl.SetPropEnum");
	if (PropEnum != InPropEnum)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropEnumRWLock);
			PropEnum = InPropEnum;
		}
#else
		PropEnum = InPropEnum;
#endif
		_GetPublisher()->BroadcastPropEnumChanged(PropEnum);
	}
}

TArray<FTestbed1StructBool> UTestbed1StructArrayInterfaceImplementation::FuncBool(const TArray<FTestbed1StructBool>& ParamBool)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArrayInterface.Impl.FuncBool");
	(void)ParamBool;
	// do business logic here
	return TArray<FTestbed1StructBool>();
}

TArray<FTestbed1StructInt> UTestbed1StructArrayInterfaceImplementation::FuncInt(const TArray<FTestbed1StructInt>& ParamInt)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArrayInterface.Impl.FuncInt");
	(void)ParamInt;
	// do business logic here
	return TArray<FTestbed1StructInt>();
}

TArray<FTestbed1StructFloat> UTestbed1StructArrayInterfaceImplementation::FuncFloat(const TArray<FTestbed1StructFloat>& ParamFloat)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArrayInterface.Impl.FuncFloat");
	(void)ParamFloat;
	// do business logic here
	return TArray<FTestbed1StructFloat>();
}

TArray<FTestbed1StructString> UTestbed1StructArrayInterfaceImplementation::FuncString(const TArray<FTestbed1StructString>& ParamString)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArrayInterface.Impl.FuncString");
	(void)ParamString;
	// do business logic here
	return TArray<FTestbed1StructString>();
}

TArray<ETestbed1Enum0> UTestbed1StructArrayInterfaceImplementation::FuncEnum(const TArray<ETestbed1Enum0>& ParamEnum)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArrayInterface.Impl.FuncEnum");
	(void)ParamEnum;
	// do business logic here
	return TArray<ETestbed1Enum0>();
}

void UTestbed1StructArrayInterfaceImplementation::_ResetProperties()
{
	if (PropBool != TArray<FTestbed1StructBool>())
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropBoolRWLock);
			PropBool = TArray<FTestbed1StructBool>();
		}
#else
		PropBool = TArray<FTestbed1StructBool>();
#endif
		_GetPublisher()->BroadcastPropBoolChanged(PropBool);
	}
	if (PropInt != TArray<FTestbed1StructInt>())
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropIntRWLock);
			PropInt = TArray<FTestbed1StructInt>();
		}
#else
		PropInt = TArray<FTestbed1StructInt>();
#endif
		_GetPublisher()->BroadcastPropIntChanged(PropInt);
	}
	if (PropFloat != TArray<FTestbed1StructFloat>())
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropFloatRWLock);
			PropFloat = TArray<FTestbed1StructFloat>();
		}
#else
		PropFloat = TArray<FTestbed1StructFloat>();
#endif
		_GetPublisher()->BroadcastPropFloatChanged(PropFloat);
	}
	if (PropString != TArray<FTestbed1StructString>())
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropStringRWLock);
			PropString = TArray<FTestbed1StructString>();
		}
#else
		PropString = TArray<FTestbed1StructString>();
#endif
		_GetPublisher()->BroadcastPropStringChanged(PropString);
	}
	if (PropEnum != TArray<ETestbed1Enum0>())
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropEnumRWLock);
			PropEnum = TArray<ETestbed1Enum0>();
		}
#else
		PropEnum = TArray<ETestbed1Enum0>();
#endif
		_GetPublisher()->BroadcastPropEnumChanged(PropEnum);
	}
}
