// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "TbStructArray/Implementation/TbStructArrayStructArrayFieldInterface.h"
#include "Misc/ScopeRWLock.h"

UTbStructArrayStructArrayFieldInterfaceImplementation::~UTbStructArrayStructArrayFieldInterfaceImplementation() = default;
FTbStructArrayStructWithArrayOfStructs UTbStructArrayStructArrayFieldInterfaceImplementation::GetPropStructArray() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(PropStructArrayRWLock);
#endif
	return PropStructArray;
}

void UTbStructArrayStructArrayFieldInterfaceImplementation::SetPropStructArray(const FTbStructArrayStructWithArrayOfStructs& InPropStructArray)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbStructArray.StructArrayFieldInterface.Impl.SetPropStructArray");
	if (PropStructArray != InPropStructArray)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropStructArrayRWLock);
			PropStructArray = InPropStructArray;
		}
#else
		PropStructArray = InPropStructArray;
#endif
		_GetPublisher()->BroadcastPropStructArrayChanged(PropStructArray);
	}
}
FTbStructArrayStructWithArrayOfEnums UTbStructArrayStructArrayFieldInterfaceImplementation::GetPropEnumArray() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(PropEnumArrayRWLock);
#endif
	return PropEnumArray;
}

void UTbStructArrayStructArrayFieldInterfaceImplementation::SetPropEnumArray(const FTbStructArrayStructWithArrayOfEnums& InPropEnumArray)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbStructArray.StructArrayFieldInterface.Impl.SetPropEnumArray");
	if (PropEnumArray != InPropEnumArray)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropEnumArrayRWLock);
			PropEnumArray = InPropEnumArray;
		}
#else
		PropEnumArray = InPropEnumArray;
#endif
		_GetPublisher()->BroadcastPropEnumArrayChanged(PropEnumArray);
	}
}
FTbStructArrayStructWithArrayOfInts UTbStructArrayStructArrayFieldInterfaceImplementation::GetPropIntArray() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(PropIntArrayRWLock);
#endif
	return PropIntArray;
}

void UTbStructArrayStructArrayFieldInterfaceImplementation::SetPropIntArray(const FTbStructArrayStructWithArrayOfInts& InPropIntArray)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbStructArray.StructArrayFieldInterface.Impl.SetPropIntArray");
	if (PropIntArray != InPropIntArray)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropIntArrayRWLock);
			PropIntArray = InPropIntArray;
		}
#else
		PropIntArray = InPropIntArray;
#endif
		_GetPublisher()->BroadcastPropIntArrayChanged(PropIntArray);
	}
}
FTbStructArrayMixedStruct UTbStructArrayStructArrayFieldInterfaceImplementation::GetPropMixed() const
{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
	FReadScopeLock ReadLock(PropMixedRWLock);
#endif
	return PropMixed;
}

void UTbStructArrayStructArrayFieldInterfaceImplementation::SetPropMixed(const FTbStructArrayMixedStruct& InPropMixed)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbStructArray.StructArrayFieldInterface.Impl.SetPropMixed");
	if (PropMixed != InPropMixed)
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropMixedRWLock);
			PropMixed = InPropMixed;
		}
#else
		PropMixed = InPropMixed;
#endif
		_GetPublisher()->BroadcastPropMixedChanged(PropMixed);
	}
}

FTbStructArrayMixedStruct UTbStructArrayStructArrayFieldInterfaceImplementation::FuncMixed(const FTbStructArrayMixedStruct& ParamMixed)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbStructArray.StructArrayFieldInterface.Impl.FuncMixed");
	(void)ParamMixed;
	// do business logic here
	return FTbStructArrayMixedStruct();
}

FTbStructArrayStructWithArrayOfStructs UTbStructArrayStructArrayFieldInterfaceImplementation::FuncStructArray(const FTbStructArrayStructWithArrayOfStructs& ParamPoints)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbStructArray.StructArrayFieldInterface.Impl.FuncStructArray");
	(void)ParamPoints;
	// do business logic here
	return FTbStructArrayStructWithArrayOfStructs();
}

void UTbStructArrayStructArrayFieldInterfaceImplementation::_ResetProperties()
{
	if (PropStructArray != FTbStructArrayStructWithArrayOfStructs())
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropStructArrayRWLock);
			PropStructArray = FTbStructArrayStructWithArrayOfStructs();
		}
#else
		PropStructArray = FTbStructArrayStructWithArrayOfStructs();
#endif
		_GetPublisher()->BroadcastPropStructArrayChanged(PropStructArray);
	}
	if (PropEnumArray != FTbStructArrayStructWithArrayOfEnums())
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropEnumArrayRWLock);
			PropEnumArray = FTbStructArrayStructWithArrayOfEnums();
		}
#else
		PropEnumArray = FTbStructArrayStructWithArrayOfEnums();
#endif
		_GetPublisher()->BroadcastPropEnumArrayChanged(PropEnumArray);
	}
	if (PropIntArray != FTbStructArrayStructWithArrayOfInts())
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropIntArrayRWLock);
			PropIntArray = FTbStructArrayStructWithArrayOfInts();
		}
#else
		PropIntArray = FTbStructArrayStructWithArrayOfInts();
#endif
		_GetPublisher()->BroadcastPropIntArrayChanged(PropIntArray);
	}
	if (PropMixed != FTbStructArrayMixedStruct())
	{
#if PLATFORM_ANDROID && USE_ANDROID_JNI
		{
			FWriteScopeLock WriteLock(PropMixedRWLock);
			PropMixed = FTbStructArrayMixedStruct();
		}
#else
		PropMixed = FTbStructArrayMixedStruct();
#endif
		_GetPublisher()->BroadcastPropMixedChanged(PropMixed);
	}
}
