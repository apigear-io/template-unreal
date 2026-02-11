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

#include "Testbed1/Implementation/Testbed1StructInterface.h"
#include "Misc/ScopeRWLock.h"

UTestbed1StructInterfaceImplementation::~UTestbed1StructInterfaceImplementation() = default;
FTestbed1StructBool UTestbed1StructInterfaceImplementation::GetPropBool() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(PropBoolRWLock);
#endif
	return PropBool;
}

void UTestbed1StructInterfaceImplementation::SetPropBool(const FTestbed1StructBool& InPropBool)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructInterface.Impl.SetPropBool");
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
FTestbed1StructInt UTestbed1StructInterfaceImplementation::GetPropInt() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(PropIntRWLock);
#endif
	return PropInt;
}

void UTestbed1StructInterfaceImplementation::SetPropInt(const FTestbed1StructInt& InPropInt)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructInterface.Impl.SetPropInt");
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
FTestbed1StructFloat UTestbed1StructInterfaceImplementation::GetPropFloat() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(PropFloatRWLock);
#endif
	return PropFloat;
}

void UTestbed1StructInterfaceImplementation::SetPropFloat(const FTestbed1StructFloat& InPropFloat)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructInterface.Impl.SetPropFloat");
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
FTestbed1StructString UTestbed1StructInterfaceImplementation::GetPropString() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(PropStringRWLock);
#endif
	return PropString;
}

void UTestbed1StructInterfaceImplementation::SetPropString(const FTestbed1StructString& InPropString)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructInterface.Impl.SetPropString");
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

FTestbed1StructBool UTestbed1StructInterfaceImplementation::FuncBool(const FTestbed1StructBool& ParamBool)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructInterface.Impl.FuncBool");
	(void)ParamBool;
	// do business logic here
	return FTestbed1StructBool();
}

FTestbed1StructInt UTestbed1StructInterfaceImplementation::FuncInt(const FTestbed1StructInt& ParamInt)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructInterface.Impl.FuncInt");
	(void)ParamInt;
	// do business logic here
	return FTestbed1StructInt();
}

FTestbed1StructFloat UTestbed1StructInterfaceImplementation::FuncFloat(const FTestbed1StructFloat& ParamFloat)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructInterface.Impl.FuncFloat");
	(void)ParamFloat;
	// do business logic here
	return FTestbed1StructFloat();
}

FTestbed1StructString UTestbed1StructInterfaceImplementation::FuncString(const FTestbed1StructString& ParamString)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructInterface.Impl.FuncString");
	(void)ParamString;
	// do business logic here
	return FTestbed1StructString();
}

void UTestbed1StructInterfaceImplementation::_ResetProperties()
{
	if (PropBool != FTestbed1StructBool())
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropBoolRWLock);
			PropBool = FTestbed1StructBool();
		}
#else
		PropBool = FTestbed1StructBool();
#endif
		_GetPublisher()->BroadcastPropBoolChanged(PropBool);
	}
	if (PropInt != FTestbed1StructInt())
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropIntRWLock);
			PropInt = FTestbed1StructInt();
		}
#else
		PropInt = FTestbed1StructInt();
#endif
		_GetPublisher()->BroadcastPropIntChanged(PropInt);
	}
	if (PropFloat != FTestbed1StructFloat())
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropFloatRWLock);
			PropFloat = FTestbed1StructFloat();
		}
#else
		PropFloat = FTestbed1StructFloat();
#endif
		_GetPublisher()->BroadcastPropFloatChanged(PropFloat);
	}
	if (PropString != FTestbed1StructString())
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropStringRWLock);
			PropString = FTestbed1StructString();
		}
#else
		PropString = FTestbed1StructString();
#endif
		_GetPublisher()->BroadcastPropStringChanged(PropString);
	}
}
