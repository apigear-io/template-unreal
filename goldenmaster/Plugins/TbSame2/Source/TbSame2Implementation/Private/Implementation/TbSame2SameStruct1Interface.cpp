// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "TbSame2/Implementation/TbSame2SameStruct1Interface.h"
#include "Misc/ScopeRWLock.h"

UTbSame2SameStruct1InterfaceImplementation::~UTbSame2SameStruct1InterfaceImplementation() = default;
FTbSame2Struct1 UTbSame2SameStruct1InterfaceImplementation::GetProp1() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(Prop1RWLock);
#endif
	return Prop1;
}

void UTbSame2SameStruct1InterfaceImplementation::SetProp1(const FTbSame2Struct1& InProp1)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSame2.SameStruct1Interface.Impl.SetProp1");
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

FTbSame2Struct1 UTbSame2SameStruct1InterfaceImplementation::Func1(const FTbSame2Struct1& Param1)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSame2.SameStruct1Interface.Impl.Func1");
	(void)Param1;
	// do business logic here
	return FTbSame2Struct1();
}

void UTbSame2SameStruct1InterfaceImplementation::_ResetProperties()
{
	if (Prop1 != FTbSame2Struct1())
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(Prop1RWLock);
			Prop1 = FTbSame2Struct1();
		}
#else
		Prop1 = FTbSame2Struct1();
#endif
		_GetPublisher()->BroadcastProp1Changed(Prop1);
	}
}
