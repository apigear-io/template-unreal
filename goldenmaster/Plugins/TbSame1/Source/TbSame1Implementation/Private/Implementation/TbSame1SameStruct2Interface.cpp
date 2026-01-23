// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "TbSame1/Implementation/TbSame1SameStruct2Interface.h"
#include "Misc/ScopeRWLock.h"

UTbSame1SameStruct2InterfaceImplementation::~UTbSame1SameStruct2InterfaceImplementation() = default;
FTbSame1Struct2 UTbSame1SameStruct2InterfaceImplementation::GetProp1() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(Prop1RWLock);
#endif
	return Prop1;
}

void UTbSame1SameStruct2InterfaceImplementation::SetProp1(const FTbSame1Struct2& InProp1)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSame1.SameStruct2Interface.Impl.SetProp1");
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
FTbSame1Struct2 UTbSame1SameStruct2InterfaceImplementation::GetProp2() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(Prop2RWLock);
#endif
	return Prop2;
}

void UTbSame1SameStruct2InterfaceImplementation::SetProp2(const FTbSame1Struct2& InProp2)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSame1.SameStruct2Interface.Impl.SetProp2");
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

FTbSame1Struct1 UTbSame1SameStruct2InterfaceImplementation::Func1(const FTbSame1Struct1& Param1)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSame1.SameStruct2Interface.Impl.Func1");
	(void)Param1;
	// do business logic here
	return FTbSame1Struct1();
}

FTbSame1Struct1 UTbSame1SameStruct2InterfaceImplementation::Func2(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSame1.SameStruct2Interface.Impl.Func2");
	(void)Param1;
	(void)Param2;
	// do business logic here
	return FTbSame1Struct1();
}

void UTbSame1SameStruct2InterfaceImplementation::_ResetProperties()
{
	if (Prop1 != FTbSame1Struct2())
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(Prop1RWLock);
			Prop1 = FTbSame1Struct2();
		}
#else
		Prop1 = FTbSame1Struct2();
#endif
		_GetPublisher()->BroadcastProp1Changed(Prop1);
	}
	if (Prop2 != FTbSame1Struct2())
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(Prop2RWLock);
			Prop2 = FTbSame1Struct2();
		}
#else
		Prop2 = FTbSame1Struct2();
#endif
		_GetPublisher()->BroadcastProp2Changed(Prop2);
	}
}
