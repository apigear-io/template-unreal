// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "Testbed2/Implementation/Testbed2ManyParamInterface.h"
#include "Misc/ScopeRWLock.h"

UTestbed2ManyParamInterfaceImplementation::~UTestbed2ManyParamInterfaceImplementation() = default;
int32 UTestbed2ManyParamInterfaceImplementation::GetProp1() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(Prop1RWLock);
#endif
	return Prop1;
}

void UTestbed2ManyParamInterfaceImplementation::SetProp1(int32 InProp1)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed2.ManyParamInterface.Impl.SetProp1");
	if (Prop1 != InProp1)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(Prop1RWLock);
			Prop1 = InProp1;
		}
#else
		Prop1 = InProp1;
#endif
		_GetPublisher()->BroadcastProp1Changed(Prop1);
	}
}
int32 UTestbed2ManyParamInterfaceImplementation::GetProp2() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(Prop2RWLock);
#endif
	return Prop2;
}

void UTestbed2ManyParamInterfaceImplementation::SetProp2(int32 InProp2)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed2.ManyParamInterface.Impl.SetProp2");
	if (Prop2 != InProp2)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(Prop2RWLock);
			Prop2 = InProp2;
		}
#else
		Prop2 = InProp2;
#endif
		_GetPublisher()->BroadcastProp2Changed(Prop2);
	}
}
int32 UTestbed2ManyParamInterfaceImplementation::GetProp3() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(Prop3RWLock);
#endif
	return Prop3;
}

void UTestbed2ManyParamInterfaceImplementation::SetProp3(int32 InProp3)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed2.ManyParamInterface.Impl.SetProp3");
	if (Prop3 != InProp3)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(Prop3RWLock);
			Prop3 = InProp3;
		}
#else
		Prop3 = InProp3;
#endif
		_GetPublisher()->BroadcastProp3Changed(Prop3);
	}
}
int32 UTestbed2ManyParamInterfaceImplementation::GetProp4() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(Prop4RWLock);
#endif
	return Prop4;
}

void UTestbed2ManyParamInterfaceImplementation::SetProp4(int32 InProp4)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed2.ManyParamInterface.Impl.SetProp4");
	if (Prop4 != InProp4)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(Prop4RWLock);
			Prop4 = InProp4;
		}
#else
		Prop4 = InProp4;
#endif
		_GetPublisher()->BroadcastProp4Changed(Prop4);
	}
}

int32 UTestbed2ManyParamInterfaceImplementation::Func1(int32 Param1)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed2.ManyParamInterface.Impl.Func1");
	(void)Param1;
	// do business logic here
	return 0;
}

int32 UTestbed2ManyParamInterfaceImplementation::Func2(int32 Param1, int32 Param2)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed2.ManyParamInterface.Impl.Func2");
	(void)Param1;
	(void)Param2;
	// do business logic here
	return 0;
}

int32 UTestbed2ManyParamInterfaceImplementation::Func3(int32 Param1, int32 Param2, int32 Param3)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed2.ManyParamInterface.Impl.Func3");
	(void)Param1;
	(void)Param2;
	(void)Param3;
	// do business logic here
	return 0;
}

int32 UTestbed2ManyParamInterfaceImplementation::Func4(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.Testbed2.ManyParamInterface.Impl.Func4");
	(void)Param1;
	(void)Param2;
	(void)Param3;
	(void)Param4;
	// do business logic here
	return 0;
}

void UTestbed2ManyParamInterfaceImplementation::_ResetProperties()
{
	if (Prop1 != 0)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(Prop1RWLock);
			Prop1 = 0;
		}
#else
		Prop1 = 0;
#endif
		_GetPublisher()->BroadcastProp1Changed(Prop1);
	}
	if (Prop2 != 0)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(Prop2RWLock);
			Prop2 = 0;
		}
#else
		Prop2 = 0;
#endif
		_GetPublisher()->BroadcastProp2Changed(Prop2);
	}
	if (Prop3 != 0)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(Prop3RWLock);
			Prop3 = 0;
		}
#else
		Prop3 = 0;
#endif
		_GetPublisher()->BroadcastProp3Changed(Prop3);
	}
	if (Prop4 != 0)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(Prop4RWLock);
			Prop4 = 0;
		}
#else
		Prop4 = 0;
#endif
		_GetPublisher()->BroadcastProp4Changed(Prop4);
	}
}
