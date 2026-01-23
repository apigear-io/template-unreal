// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "TbSame2/Implementation/TbSame2SameEnum1Interface.h"
#include "Misc/ScopeRWLock.h"

UTbSame2SameEnum1InterfaceImplementation::~UTbSame2SameEnum1InterfaceImplementation() = default;
ETbSame2Enum1 UTbSame2SameEnum1InterfaceImplementation::GetProp1() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(Prop1RWLock);
#endif
	return Prop1;
}

void UTbSame2SameEnum1InterfaceImplementation::SetProp1(ETbSame2Enum1 InProp1)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSame2.SameEnum1Interface.Impl.SetProp1");
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

ETbSame2Enum1 UTbSame2SameEnum1InterfaceImplementation::Func1(ETbSame2Enum1 Param1)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSame2.SameEnum1Interface.Impl.Func1");
	(void)Param1;
	// do business logic here
	return ETbSame2Enum1::TS2E1_Value1;
}

void UTbSame2SameEnum1InterfaceImplementation::_ResetProperties()
{
	if (Prop1 != ETbSame2Enum1::TS2E1_Value1)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(Prop1RWLock);
			Prop1 = ETbSame2Enum1::TS2E1_Value1;
		}
#else
		Prop1 = ETbSame2Enum1::TS2E1_Value1;
#endif
		_GetPublisher()->BroadcastProp1Changed(Prop1);
	}
}
