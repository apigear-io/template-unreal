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

#include "TbSimple/Implementation/TbSimpleSimpleArrayInterface.h"

UTbSimpleSimpleArrayInterface::~UTbSimpleSimpleArrayInterface() = default;
TArray<bool> UTbSimpleSimpleArrayInterface::GetPropBool() const
{
	return PropBool;
}

void UTbSimpleSimpleArrayInterface::SetPropBool(const TArray<bool>& InPropBool)
{
	if (PropBool != InPropBool)
	{
		PropBool = InPropBool;
		_GetSignals()->BroadcastPropBoolChanged(PropBool);
	}
}
TArray<int32> UTbSimpleSimpleArrayInterface::GetPropInt() const
{
	return PropInt;
}

void UTbSimpleSimpleArrayInterface::SetPropInt(const TArray<int32>& InPropInt)
{
	if (PropInt != InPropInt)
	{
		PropInt = InPropInt;
		_GetSignals()->BroadcastPropIntChanged(PropInt);
	}
}
TArray<int32> UTbSimpleSimpleArrayInterface::GetPropInt32() const
{
	return PropInt32;
}

void UTbSimpleSimpleArrayInterface::SetPropInt32(const TArray<int32>& InPropInt32)
{
	if (PropInt32 != InPropInt32)
	{
		PropInt32 = InPropInt32;
		_GetSignals()->BroadcastPropInt32Changed(PropInt32);
	}
}
TArray<int64> UTbSimpleSimpleArrayInterface::GetPropInt64() const
{
	return PropInt64;
}

void UTbSimpleSimpleArrayInterface::SetPropInt64(const TArray<int64>& InPropInt64)
{
	if (PropInt64 != InPropInt64)
	{
		PropInt64 = InPropInt64;
		_GetSignals()->BroadcastPropInt64Changed(PropInt64);
	}
}
TArray<float> UTbSimpleSimpleArrayInterface::GetPropFloat() const
{
	return PropFloat;
}

void UTbSimpleSimpleArrayInterface::SetPropFloat(const TArray<float>& InPropFloat)
{
	if (PropFloat != InPropFloat)
	{
		PropFloat = InPropFloat;
		_GetSignals()->BroadcastPropFloatChanged(PropFloat);
	}
}
TArray<float> UTbSimpleSimpleArrayInterface::GetPropFloat32() const
{
	return PropFloat32;
}

void UTbSimpleSimpleArrayInterface::SetPropFloat32(const TArray<float>& InPropFloat32)
{
	if (PropFloat32 != InPropFloat32)
	{
		PropFloat32 = InPropFloat32;
		_GetSignals()->BroadcastPropFloat32Changed(PropFloat32);
	}
}
TArray<double> UTbSimpleSimpleArrayInterface::GetPropFloat64() const
{
	return PropFloat64;
}

void UTbSimpleSimpleArrayInterface::SetPropFloat64(const TArray<double>& InPropFloat64)
{
	if (PropFloat64 != InPropFloat64)
	{
		PropFloat64 = InPropFloat64;
		_GetSignals()->BroadcastPropFloat64Changed(PropFloat64);
	}
}
TArray<FString> UTbSimpleSimpleArrayInterface::GetPropString() const
{
	return PropString;
}

void UTbSimpleSimpleArrayInterface::SetPropString(const TArray<FString>& InPropString)
{
	if (PropString != InPropString)
	{
		PropString = InPropString;
		_GetSignals()->BroadcastPropStringChanged(PropString);
	}
}
FString UTbSimpleSimpleArrayInterface::GetPropReadOnlyString() const
{
	return PropReadOnlyString;
}

TArray<bool> UTbSimpleSimpleArrayInterface::FuncBool(const TArray<bool>& ParamBool)
{
	(void)ParamBool;
	// do business logic here
	return TArray<bool>();
}

TArray<int32> UTbSimpleSimpleArrayInterface::FuncInt(const TArray<int32>& ParamInt)
{
	(void)ParamInt;
	// do business logic here
	return TArray<int32>();
}

TArray<int32> UTbSimpleSimpleArrayInterface::FuncInt32(const TArray<int32>& ParamInt32)
{
	(void)ParamInt32;
	// do business logic here
	return TArray<int32>();
}

TArray<int64> UTbSimpleSimpleArrayInterface::FuncInt64(const TArray<int64>& ParamInt64)
{
	(void)ParamInt64;
	// do business logic here
	return TArray<int64>();
}

TArray<float> UTbSimpleSimpleArrayInterface::FuncFloat(const TArray<float>& ParamFloat)
{
	(void)ParamFloat;
	// do business logic here
	return TArray<float>();
}

TArray<float> UTbSimpleSimpleArrayInterface::FuncFloat32(const TArray<float>& ParamFloat32)
{
	(void)ParamFloat32;
	// do business logic here
	return TArray<float>();
}

TArray<double> UTbSimpleSimpleArrayInterface::FuncFloat64(const TArray<double>& ParamFloat)
{
	(void)ParamFloat;
	// do business logic here
	return TArray<double>();
}

TArray<FString> UTbSimpleSimpleArrayInterface::FuncString(const TArray<FString>& ParamString)
{
	(void)ParamString;
	// do business logic here
	return TArray<FString>();
}
