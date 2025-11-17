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

#include "TbSimple/Implementation/TbSimpleSimpleInterface.h"

UTbSimpleSimpleInterfaceImplementation::~UTbSimpleSimpleInterfaceImplementation() = default;
bool UTbSimpleSimpleInterfaceImplementation::GetPropBool() const
{
	return bPropBool;
}

void UTbSimpleSimpleInterfaceImplementation::SetPropBool(bool bInPropBool)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.SimpleInterface.Impl.SetPropBool");
	if (bPropBool != bInPropBool)
	{
		bPropBool = bInPropBool;
		_GetPublisher()->BroadcastPropBoolChanged(bPropBool);
	}
}
int32 UTbSimpleSimpleInterfaceImplementation::GetPropInt() const
{
	return PropInt;
}

void UTbSimpleSimpleInterfaceImplementation::SetPropInt(int32 InPropInt)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.SimpleInterface.Impl.SetPropInt");
	if (PropInt != InPropInt)
	{
		PropInt = InPropInt;
		_GetPublisher()->BroadcastPropIntChanged(PropInt);
	}
}
int32 UTbSimpleSimpleInterfaceImplementation::GetPropInt32() const
{
	return PropInt32;
}

void UTbSimpleSimpleInterfaceImplementation::SetPropInt32(int32 InPropInt32)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.SimpleInterface.Impl.SetPropInt32");
	if (PropInt32 != InPropInt32)
	{
		PropInt32 = InPropInt32;
		_GetPublisher()->BroadcastPropInt32Changed(PropInt32);
	}
}
int64 UTbSimpleSimpleInterfaceImplementation::GetPropInt64() const
{
	return PropInt64;
}

void UTbSimpleSimpleInterfaceImplementation::SetPropInt64(int64 InPropInt64)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.SimpleInterface.Impl.SetPropInt64");
	if (PropInt64 != InPropInt64)
	{
		PropInt64 = InPropInt64;
		_GetPublisher()->BroadcastPropInt64Changed(PropInt64);
	}
}
float UTbSimpleSimpleInterfaceImplementation::GetPropFloat() const
{
	return PropFloat;
}

void UTbSimpleSimpleInterfaceImplementation::SetPropFloat(float InPropFloat)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.SimpleInterface.Impl.SetPropFloat");
	if (PropFloat != InPropFloat)
	{
		PropFloat = InPropFloat;
		_GetPublisher()->BroadcastPropFloatChanged(PropFloat);
	}
}
float UTbSimpleSimpleInterfaceImplementation::GetPropFloat32() const
{
	return PropFloat32;
}

void UTbSimpleSimpleInterfaceImplementation::SetPropFloat32(float InPropFloat32)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.SimpleInterface.Impl.SetPropFloat32");
	if (PropFloat32 != InPropFloat32)
	{
		PropFloat32 = InPropFloat32;
		_GetPublisher()->BroadcastPropFloat32Changed(PropFloat32);
	}
}
double UTbSimpleSimpleInterfaceImplementation::GetPropFloat64() const
{
	return PropFloat64;
}

void UTbSimpleSimpleInterfaceImplementation::SetPropFloat64(double InPropFloat64)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.SimpleInterface.Impl.SetPropFloat64");
	if (PropFloat64 != InPropFloat64)
	{
		PropFloat64 = InPropFloat64;
		_GetPublisher()->BroadcastPropFloat64Changed(PropFloat64);
	}
}
FString UTbSimpleSimpleInterfaceImplementation::GetPropString() const
{
	return PropString;
}

void UTbSimpleSimpleInterfaceImplementation::SetPropString(const FString& InPropString)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.SimpleInterface.Impl.SetPropString");
	if (PropString != InPropString)
	{
		PropString = InPropString;
		_GetPublisher()->BroadcastPropStringChanged(PropString);
	}
}

void UTbSimpleSimpleInterfaceImplementation::FuncNoReturnValue(bool bParamBool)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.SimpleInterface.Impl.FuncNoReturnValue");
	(void)bParamBool;
	// do business logic here
}

bool UTbSimpleSimpleInterfaceImplementation::FuncNoParams()
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.SimpleInterface.Impl.FuncNoParams");
	// do business logic here
	return false;
}

bool UTbSimpleSimpleInterfaceImplementation::FuncBool(bool bParamBool)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.SimpleInterface.Impl.FuncBool");
	(void)bParamBool;
	// do business logic here
	return false;
}

int32 UTbSimpleSimpleInterfaceImplementation::FuncInt(int32 ParamInt)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.SimpleInterface.Impl.FuncInt");
	(void)ParamInt;
	// do business logic here
	return 0;
}

int32 UTbSimpleSimpleInterfaceImplementation::FuncInt32(int32 ParamInt32)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.SimpleInterface.Impl.FuncInt32");
	(void)ParamInt32;
	// do business logic here
	return 0;
}

int64 UTbSimpleSimpleInterfaceImplementation::FuncInt64(int64 ParamInt64)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.SimpleInterface.Impl.FuncInt64");
	(void)ParamInt64;
	// do business logic here
	return 0LL;
}

float UTbSimpleSimpleInterfaceImplementation::FuncFloat(float ParamFloat)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.SimpleInterface.Impl.FuncFloat");
	(void)ParamFloat;
	// do business logic here
	return 0.0f;
}

float UTbSimpleSimpleInterfaceImplementation::FuncFloat32(float ParamFloat32)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.SimpleInterface.Impl.FuncFloat32");
	(void)ParamFloat32;
	// do business logic here
	return 0.0f;
}

double UTbSimpleSimpleInterfaceImplementation::FuncFloat64(double ParamFloat)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.SimpleInterface.Impl.FuncFloat64");
	(void)ParamFloat;
	// do business logic here
	return 0.0;
}

FString UTbSimpleSimpleInterfaceImplementation::FuncString(const FString& ParamString)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.SimpleInterface.Impl.FuncString");
	(void)ParamString;
	// do business logic here
	return FString();
}

void UTbSimpleSimpleInterfaceImplementation::_ResetProperties()
{
	if (bPropBool != false)
	{
		bPropBool = false;
		_GetPublisher()->BroadcastPropBoolChanged(bPropBool);
	}
	if (PropInt != 0)
	{
		PropInt = 0;
		_GetPublisher()->BroadcastPropIntChanged(PropInt);
	}
	if (PropInt32 != 0)
	{
		PropInt32 = 0;
		_GetPublisher()->BroadcastPropInt32Changed(PropInt32);
	}
	if (PropInt64 != 0LL)
	{
		PropInt64 = 0LL;
		_GetPublisher()->BroadcastPropInt64Changed(PropInt64);
	}
	if (PropFloat != 0.0f)
	{
		PropFloat = 0.0f;
		_GetPublisher()->BroadcastPropFloatChanged(PropFloat);
	}
	if (PropFloat32 != 0.0f)
	{
		PropFloat32 = 0.0f;
		_GetPublisher()->BroadcastPropFloat32Changed(PropFloat32);
	}
	if (PropFloat64 != 0.0)
	{
		PropFloat64 = 0.0;
		_GetPublisher()->BroadcastPropFloat64Changed(PropFloat64);
	}
	if (PropString != FString())
	{
		PropString = FString();
		_GetPublisher()->BroadcastPropStringChanged(PropString);
	}
}
