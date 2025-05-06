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

UTbSimpleSimpleInterface::~UTbSimpleSimpleInterface() = default;
bool UTbSimpleSimpleInterface::GetPropBool() const
{
	return bPropBool;
}

void UTbSimpleSimpleInterface::SetPropBool(bool bInPropBool)
{
	if (bPropBool != bInPropBool)
	{
		bPropBool = bInPropBool;
		_GetSignals()->BroadcastPropBoolChanged(bPropBool);
	}
}
int32 UTbSimpleSimpleInterface::GetPropInt() const
{
	return PropInt;
}

void UTbSimpleSimpleInterface::SetPropInt(int32 InPropInt)
{
	if (PropInt != InPropInt)
	{
		PropInt = InPropInt;
		_GetSignals()->BroadcastPropIntChanged(PropInt);
	}
}
int32 UTbSimpleSimpleInterface::GetPropInt32() const
{
	return PropInt32;
}

void UTbSimpleSimpleInterface::SetPropInt32(int32 InPropInt32)
{
	if (PropInt32 != InPropInt32)
	{
		PropInt32 = InPropInt32;
		_GetSignals()->BroadcastPropInt32Changed(PropInt32);
	}
}
int64 UTbSimpleSimpleInterface::GetPropInt64() const
{
	return PropInt64;
}

void UTbSimpleSimpleInterface::SetPropInt64(int64 InPropInt64)
{
	if (PropInt64 != InPropInt64)
	{
		PropInt64 = InPropInt64;
		_GetSignals()->BroadcastPropInt64Changed(PropInt64);
	}
}
float UTbSimpleSimpleInterface::GetPropFloat() const
{
	return PropFloat;
}

void UTbSimpleSimpleInterface::SetPropFloat(float InPropFloat)
{
	if (PropFloat != InPropFloat)
	{
		PropFloat = InPropFloat;
		_GetSignals()->BroadcastPropFloatChanged(PropFloat);
	}
}
float UTbSimpleSimpleInterface::GetPropFloat32() const
{
	return PropFloat32;
}

void UTbSimpleSimpleInterface::SetPropFloat32(float InPropFloat32)
{
	if (PropFloat32 != InPropFloat32)
	{
		PropFloat32 = InPropFloat32;
		_GetSignals()->BroadcastPropFloat32Changed(PropFloat32);
	}
}
double UTbSimpleSimpleInterface::GetPropFloat64() const
{
	return PropFloat64;
}

void UTbSimpleSimpleInterface::SetPropFloat64(double InPropFloat64)
{
	if (PropFloat64 != InPropFloat64)
	{
		PropFloat64 = InPropFloat64;
		_GetSignals()->BroadcastPropFloat64Changed(PropFloat64);
	}
}
FString UTbSimpleSimpleInterface::GetPropString() const
{
	return PropString;
}

void UTbSimpleSimpleInterface::SetPropString(const FString& InPropString)
{
	if (PropString != InPropString)
	{
		PropString = InPropString;
		_GetSignals()->BroadcastPropStringChanged(PropString);
	}
}

void UTbSimpleSimpleInterface::FuncNoReturnValue(bool bParamBool)
{
	(void)bParamBool;
	// do business logic here
}

bool UTbSimpleSimpleInterface::FuncBool(bool bParamBool)
{
	(void)bParamBool;
	// do business logic here
	return false;
}

int32 UTbSimpleSimpleInterface::FuncInt(int32 ParamInt)
{
	(void)ParamInt;
	// do business logic here
	return 0;
}

int32 UTbSimpleSimpleInterface::FuncInt32(int32 ParamInt32)
{
	(void)ParamInt32;
	// do business logic here
	return 0;
}

int64 UTbSimpleSimpleInterface::FuncInt64(int64 ParamInt64)
{
	(void)ParamInt64;
	// do business logic here
	return 0LL;
}

float UTbSimpleSimpleInterface::FuncFloat(float ParamFloat)
{
	(void)ParamFloat;
	// do business logic here
	return 0.0f;
}

float UTbSimpleSimpleInterface::FuncFloat32(float ParamFloat32)
{
	(void)ParamFloat32;
	// do business logic here
	return 0.0f;
}

double UTbSimpleSimpleInterface::FuncFloat64(double ParamFloat)
{
	(void)ParamFloat;
	// do business logic here
	return 0.0;
}

FString UTbSimpleSimpleInterface::FuncString(const FString& ParamString)
{
	(void)ParamString;
	// do business logic here
	return FString();
}

void UTbSimpleSimpleInterface::_ResetProperties()
{
	if (bPropBool != false)
	{
		bPropBool = false;
		_GetSignals()->BroadcastPropBoolChanged(bPropBool);
	}
	if (PropInt != 0)
	{
		PropInt = 0;
		_GetSignals()->BroadcastPropIntChanged(PropInt);
	}
	if (PropInt32 != 0)
	{
		PropInt32 = 0;
		_GetSignals()->BroadcastPropInt32Changed(PropInt32);
	}
	if (PropInt64 != 0LL)
	{
		PropInt64 = 0LL;
		_GetSignals()->BroadcastPropInt64Changed(PropInt64);
	}
	if (PropFloat != 0.0f)
	{
		PropFloat = 0.0f;
		_GetSignals()->BroadcastPropFloatChanged(PropFloat);
	}
	if (PropFloat32 != 0.0f)
	{
		PropFloat32 = 0.0f;
		_GetSignals()->BroadcastPropFloat32Changed(PropFloat32);
	}
	if (PropFloat64 != 0.0)
	{
		PropFloat64 = 0.0;
		_GetSignals()->BroadcastPropFloat64Changed(PropFloat64);
	}
	if (PropString != FString())
	{
		PropString = FString();
		_GetSignals()->BroadcastPropStringChanged(PropString);
	}
}
