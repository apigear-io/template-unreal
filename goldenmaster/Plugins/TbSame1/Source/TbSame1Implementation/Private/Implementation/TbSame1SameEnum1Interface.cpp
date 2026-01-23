// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "TbSame1/Implementation/TbSame1SameEnum1Interface.h"
#include "Misc/ScopeRWLock.h"

UTbSame1SameEnum1InterfaceImplementation::~UTbSame1SameEnum1InterfaceImplementation() = default;
ETbSame1Enum1 UTbSame1SameEnum1InterfaceImplementation::GetProp1() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(Prop1RWLock);
#endif
	return Prop1;
}

void UTbSame1SameEnum1InterfaceImplementation::SetProp1(ETbSame1Enum1 InProp1)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSame1.SameEnum1Interface.Impl.SetProp1");
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

ETbSame1Enum1 UTbSame1SameEnum1InterfaceImplementation::Func1(ETbSame1Enum1 Param1)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSame1.SameEnum1Interface.Impl.Func1");
	(void)Param1;
	// do business logic here
	return ETbSame1Enum1::TS1E1_Value1;
}

void UTbSame1SameEnum1InterfaceImplementation::_ResetProperties()
{
	if (Prop1 != ETbSame1Enum1::TS1E1_Value1)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(Prop1RWLock);
			Prop1 = ETbSame1Enum1::TS1E1_Value1;
		}
#else
		Prop1 = ETbSame1Enum1::TS1E1_Value1;
#endif
		_GetPublisher()->BroadcastProp1Changed(Prop1);
	}
}
