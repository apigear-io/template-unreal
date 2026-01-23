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

#include "TbEnum/Implementation/TbEnumEnumInterface.h"
#include "Misc/ScopeRWLock.h"

UTbEnumEnumInterfaceImplementation::~UTbEnumEnumInterfaceImplementation() = default;
ETbEnumEnum0 UTbEnumEnumInterfaceImplementation::GetProp0() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(Prop0RWLock);
#endif
	return Prop0;
}

void UTbEnumEnumInterfaceImplementation::SetProp0(ETbEnumEnum0 InProp0)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbEnum.EnumInterface.Impl.SetProp0");
	if (Prop0 != InProp0)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(Prop0RWLock);
			Prop0 = InProp0;
		}
#else
		Prop0 = InProp0;
#endif
		_GetPublisher()->BroadcastProp0Changed(Prop0);
	}
}
ETbEnumEnum1 UTbEnumEnumInterfaceImplementation::GetProp1() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(Prop1RWLock);
#endif
	return Prop1;
}

void UTbEnumEnumInterfaceImplementation::SetProp1(ETbEnumEnum1 InProp1)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbEnum.EnumInterface.Impl.SetProp1");
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
ETbEnumEnum2 UTbEnumEnumInterfaceImplementation::GetProp2() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(Prop2RWLock);
#endif
	return Prop2;
}

void UTbEnumEnumInterfaceImplementation::SetProp2(ETbEnumEnum2 InProp2)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbEnum.EnumInterface.Impl.SetProp2");
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
ETbEnumEnum3 UTbEnumEnumInterfaceImplementation::GetProp3() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(Prop3RWLock);
#endif
	return Prop3;
}

void UTbEnumEnumInterfaceImplementation::SetProp3(ETbEnumEnum3 InProp3)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbEnum.EnumInterface.Impl.SetProp3");
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

ETbEnumEnum0 UTbEnumEnumInterfaceImplementation::Func0(ETbEnumEnum0 Param0)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbEnum.EnumInterface.Impl.Func0");
	(void)Param0;
	// do business logic here
	return ETbEnumEnum0::TEE0_Value0;
}

ETbEnumEnum1 UTbEnumEnumInterfaceImplementation::Func1(ETbEnumEnum1 Param1)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbEnum.EnumInterface.Impl.Func1");
	(void)Param1;
	// do business logic here
	return ETbEnumEnum1::TEE1_Value1;
}

ETbEnumEnum2 UTbEnumEnumInterfaceImplementation::Func2(ETbEnumEnum2 Param2)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbEnum.EnumInterface.Impl.Func2");
	(void)Param2;
	// do business logic here
	return ETbEnumEnum2::TEE2_Value2;
}

ETbEnumEnum3 UTbEnumEnumInterfaceImplementation::Func3(ETbEnumEnum3 Param3)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbEnum.EnumInterface.Impl.Func3");
	(void)Param3;
	// do business logic here
	return ETbEnumEnum3::TEE3_Value3;
}

void UTbEnumEnumInterfaceImplementation::_ResetProperties()
{
	if (Prop0 != ETbEnumEnum0::TEE0_Value0)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(Prop0RWLock);
			Prop0 = ETbEnumEnum0::TEE0_Value0;
		}
#else
		Prop0 = ETbEnumEnum0::TEE0_Value0;
#endif
		_GetPublisher()->BroadcastProp0Changed(Prop0);
	}
	if (Prop1 != ETbEnumEnum1::TEE1_Value1)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(Prop1RWLock);
			Prop1 = ETbEnumEnum1::TEE1_Value1;
		}
#else
		Prop1 = ETbEnumEnum1::TEE1_Value1;
#endif
		_GetPublisher()->BroadcastProp1Changed(Prop1);
	}
	if (Prop2 != ETbEnumEnum2::TEE2_Value2)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(Prop2RWLock);
			Prop2 = ETbEnumEnum2::TEE2_Value2;
		}
#else
		Prop2 = ETbEnumEnum2::TEE2_Value2;
#endif
		_GetPublisher()->BroadcastProp2Changed(Prop2);
	}
	if (Prop3 != ETbEnumEnum3::TEE3_Value3)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(Prop3RWLock);
			Prop3 = ETbEnumEnum3::TEE3_Value3;
		}
#else
		Prop3 = ETbEnumEnum3::TEE3_Value3;
#endif
		_GetPublisher()->BroadcastProp3Changed(Prop3);
	}
}
