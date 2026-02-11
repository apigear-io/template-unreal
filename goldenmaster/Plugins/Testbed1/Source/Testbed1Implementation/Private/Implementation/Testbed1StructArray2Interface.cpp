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

#include "Testbed1/Implementation/Testbed1StructArray2Interface.h"
#include "Misc/ScopeRWLock.h"

UTestbed1StructArray2InterfaceImplementation::~UTestbed1StructArray2InterfaceImplementation() = default;
FTestbed1StructBoolWithArray UTestbed1StructArray2InterfaceImplementation::GetPropBool() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(PropBoolRWLock);
#endif
	return PropBool;
}

void UTestbed1StructArray2InterfaceImplementation::SetPropBool(const FTestbed1StructBoolWithArray& InPropBool)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArray2Interface.Impl.SetPropBool");
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
FTestbed1StructIntWithArray UTestbed1StructArray2InterfaceImplementation::GetPropInt() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(PropIntRWLock);
#endif
	return PropInt;
}

void UTestbed1StructArray2InterfaceImplementation::SetPropInt(const FTestbed1StructIntWithArray& InPropInt)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArray2Interface.Impl.SetPropInt");
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
FTestbed1StructFloatWithArray UTestbed1StructArray2InterfaceImplementation::GetPropFloat() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(PropFloatRWLock);
#endif
	return PropFloat;
}

void UTestbed1StructArray2InterfaceImplementation::SetPropFloat(const FTestbed1StructFloatWithArray& InPropFloat)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArray2Interface.Impl.SetPropFloat");
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
FTestbed1StructStringWithArray UTestbed1StructArray2InterfaceImplementation::GetPropString() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(PropStringRWLock);
#endif
	return PropString;
}

void UTestbed1StructArray2InterfaceImplementation::SetPropString(const FTestbed1StructStringWithArray& InPropString)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArray2Interface.Impl.SetPropString");
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
FTestbed1StructEnumWithArray UTestbed1StructArray2InterfaceImplementation::GetPropEnum() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(PropEnumRWLock);
#endif
	return PropEnum;
}

void UTestbed1StructArray2InterfaceImplementation::SetPropEnum(const FTestbed1StructEnumWithArray& InPropEnum)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArray2Interface.Impl.SetPropEnum");
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

TArray<FTestbed1StructBool> UTestbed1StructArray2InterfaceImplementation::FuncBool(const FTestbed1StructBoolWithArray& ParamBool)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArray2Interface.Impl.FuncBool");
	(void)ParamBool;
	// do business logic here
	return TArray<FTestbed1StructBool>();
}

TArray<FTestbed1StructInt> UTestbed1StructArray2InterfaceImplementation::FuncInt(const FTestbed1StructIntWithArray& ParamInt)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArray2Interface.Impl.FuncInt");
	(void)ParamInt;
	// do business logic here
	return TArray<FTestbed1StructInt>();
}

TArray<FTestbed1StructFloat> UTestbed1StructArray2InterfaceImplementation::FuncFloat(const FTestbed1StructFloatWithArray& ParamFloat)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArray2Interface.Impl.FuncFloat");
	(void)ParamFloat;
	// do business logic here
	return TArray<FTestbed1StructFloat>();
}

TArray<FTestbed1StructString> UTestbed1StructArray2InterfaceImplementation::FuncString(const FTestbed1StructStringWithArray& ParamString)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArray2Interface.Impl.FuncString");
	(void)ParamString;
	// do business logic here
	return TArray<FTestbed1StructString>();
}

TArray<ETestbed1Enum0> UTestbed1StructArray2InterfaceImplementation::FuncEnum(const FTestbed1StructEnumWithArray& ParamEnum)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed1.StructArray2Interface.Impl.FuncEnum");
	(void)ParamEnum;
	// do business logic here
	return TArray<ETestbed1Enum0>();
}

void UTestbed1StructArray2InterfaceImplementation::_ResetProperties()
{
	if (PropBool != FTestbed1StructBoolWithArray())
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropBoolRWLock);
			PropBool = FTestbed1StructBoolWithArray();
		}
#else
		PropBool = FTestbed1StructBoolWithArray();
#endif
		_GetPublisher()->BroadcastPropBoolChanged(PropBool);
	}
	if (PropInt != FTestbed1StructIntWithArray())
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropIntRWLock);
			PropInt = FTestbed1StructIntWithArray();
		}
#else
		PropInt = FTestbed1StructIntWithArray();
#endif
		_GetPublisher()->BroadcastPropIntChanged(PropInt);
	}
	if (PropFloat != FTestbed1StructFloatWithArray())
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropFloatRWLock);
			PropFloat = FTestbed1StructFloatWithArray();
		}
#else
		PropFloat = FTestbed1StructFloatWithArray();
#endif
		_GetPublisher()->BroadcastPropFloatChanged(PropFloat);
	}
	if (PropString != FTestbed1StructStringWithArray())
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropStringRWLock);
			PropString = FTestbed1StructStringWithArray();
		}
#else
		PropString = FTestbed1StructStringWithArray();
#endif
		_GetPublisher()->BroadcastPropStringChanged(PropString);
	}
	if (PropEnum != FTestbed1StructEnumWithArray())
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropEnumRWLock);
			PropEnum = FTestbed1StructEnumWithArray();
		}
#else
		PropEnum = FTestbed1StructEnumWithArray();
#endif
		_GetPublisher()->BroadcastPropEnumChanged(PropEnum);
	}
}
