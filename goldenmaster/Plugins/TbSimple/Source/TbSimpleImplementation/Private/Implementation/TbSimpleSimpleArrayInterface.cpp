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

UTbSimpleSimpleArrayInterfaceImplementation::~UTbSimpleSimpleArrayInterfaceImplementation() = default;
TArray<bool> UTbSimpleSimpleArrayInterfaceImplementation::GetPropBool() const
{
	return PropBool;
}

void UTbSimpleSimpleArrayInterfaceImplementation::SetPropBool(const TArray<bool>& InPropBool)
{
	if (PropBool != InPropBool)
	{
		PropBool = InPropBool;
		_GetSignals()->BroadcastPropBoolChanged(PropBool);
	}
}
TArray<int32> UTbSimpleSimpleArrayInterfaceImplementation::GetPropInt() const
{
	return PropInt;
}

void UTbSimpleSimpleArrayInterfaceImplementation::SetPropInt(const TArray<int32>& InPropInt)
{
	if (PropInt != InPropInt)
	{
		PropInt = InPropInt;
		_GetSignals()->BroadcastPropIntChanged(PropInt);
	}
}
TArray<int32> UTbSimpleSimpleArrayInterfaceImplementation::GetPropInt32() const
{
	return PropInt32;
}

void UTbSimpleSimpleArrayInterfaceImplementation::SetPropInt32(const TArray<int32>& InPropInt32)
{
	if (PropInt32 != InPropInt32)
	{
		PropInt32 = InPropInt32;
		_GetSignals()->BroadcastPropInt32Changed(PropInt32);
	}
}
TArray<int64> UTbSimpleSimpleArrayInterfaceImplementation::GetPropInt64() const
{
	return PropInt64;
}

void UTbSimpleSimpleArrayInterfaceImplementation::SetPropInt64(const TArray<int64>& InPropInt64)
{
	if (PropInt64 != InPropInt64)
	{
		PropInt64 = InPropInt64;
		_GetSignals()->BroadcastPropInt64Changed(PropInt64);
	}
}
TArray<float> UTbSimpleSimpleArrayInterfaceImplementation::GetPropFloat() const
{
	return PropFloat;
}

void UTbSimpleSimpleArrayInterfaceImplementation::SetPropFloat(const TArray<float>& InPropFloat)
{
	if (PropFloat != InPropFloat)
	{
		PropFloat = InPropFloat;
		_GetSignals()->BroadcastPropFloatChanged(PropFloat);
	}
}
TArray<float> UTbSimpleSimpleArrayInterfaceImplementation::GetPropFloat32() const
{
	return PropFloat32;
}

void UTbSimpleSimpleArrayInterfaceImplementation::SetPropFloat32(const TArray<float>& InPropFloat32)
{
	if (PropFloat32 != InPropFloat32)
	{
		PropFloat32 = InPropFloat32;
		_GetSignals()->BroadcastPropFloat32Changed(PropFloat32);
	}
}
TArray<double> UTbSimpleSimpleArrayInterfaceImplementation::GetPropFloat64() const
{
	return PropFloat64;
}

void UTbSimpleSimpleArrayInterfaceImplementation::SetPropFloat64(const TArray<double>& InPropFloat64)
{
	if (PropFloat64 != InPropFloat64)
	{
		PropFloat64 = InPropFloat64;
		_GetSignals()->BroadcastPropFloat64Changed(PropFloat64);
	}
}
TArray<FString> UTbSimpleSimpleArrayInterfaceImplementation::GetPropString() const
{
	return PropString;
}

void UTbSimpleSimpleArrayInterfaceImplementation::SetPropString(const TArray<FString>& InPropString)
{
	if (PropString != InPropString)
	{
		PropString = InPropString;
		_GetSignals()->BroadcastPropStringChanged(PropString);
	}
}
FString UTbSimpleSimpleArrayInterfaceImplementation::GetPropReadOnlyString() const
{
	return PropReadOnlyString;
}

TArray<bool> UTbSimpleSimpleArrayInterfaceImplementation::FuncBool(const TArray<bool>& ParamBool)
{
	(void)ParamBool;
	// do business logic here
	return TArray<bool>();
}

TArray<int32> UTbSimpleSimpleArrayInterfaceImplementation::FuncInt(const TArray<int32>& ParamInt)
{
	(void)ParamInt;
	// do business logic here
	return TArray<int32>();
}

TArray<int32> UTbSimpleSimpleArrayInterfaceImplementation::FuncInt32(const TArray<int32>& ParamInt32)
{
	(void)ParamInt32;
	// do business logic here
	return TArray<int32>();
}

TArray<int64> UTbSimpleSimpleArrayInterfaceImplementation::FuncInt64(const TArray<int64>& ParamInt64)
{
	(void)ParamInt64;
	// do business logic here
	return TArray<int64>();
}

TArray<float> UTbSimpleSimpleArrayInterfaceImplementation::FuncFloat(const TArray<float>& ParamFloat)
{
	(void)ParamFloat;
	// do business logic here
	return TArray<float>();
}

TArray<float> UTbSimpleSimpleArrayInterfaceImplementation::FuncFloat32(const TArray<float>& ParamFloat32)
{
	(void)ParamFloat32;
	// do business logic here
	return TArray<float>();
}

TArray<double> UTbSimpleSimpleArrayInterfaceImplementation::FuncFloat64(const TArray<double>& ParamFloat)
{
	(void)ParamFloat;
	// do business logic here
	return TArray<double>();
}

TArray<FString> UTbSimpleSimpleArrayInterfaceImplementation::FuncString(const TArray<FString>& ParamString)
{
	(void)ParamString;
	// do business logic here
	return TArray<FString>();
}

void UTbSimpleSimpleArrayInterfaceImplementation::_ResetProperties()
{
	if (PropBool != TArray<bool>())
	{
		PropBool = TArray<bool>();
		_GetSignals()->BroadcastPropBoolChanged(PropBool);
	}
	if (PropInt != TArray<int32>())
	{
		PropInt = TArray<int32>();
		_GetSignals()->BroadcastPropIntChanged(PropInt);
	}
	if (PropInt32 != TArray<int32>())
	{
		PropInt32 = TArray<int32>();
		_GetSignals()->BroadcastPropInt32Changed(PropInt32);
	}
	if (PropInt64 != TArray<int64>())
	{
		PropInt64 = TArray<int64>();
		_GetSignals()->BroadcastPropInt64Changed(PropInt64);
	}
	if (PropFloat != TArray<float>())
	{
		PropFloat = TArray<float>();
		_GetSignals()->BroadcastPropFloatChanged(PropFloat);
	}
	if (PropFloat32 != TArray<float>())
	{
		PropFloat32 = TArray<float>();
		_GetSignals()->BroadcastPropFloat32Changed(PropFloat32);
	}
	if (PropFloat64 != TArray<double>())
	{
		PropFloat64 = TArray<double>();
		_GetSignals()->BroadcastPropFloat64Changed(PropFloat64);
	}
	if (PropString != TArray<FString>())
	{
		PropString = TArray<FString>();
		_GetSignals()->BroadcastPropStringChanged(PropString);
	}
	if (PropReadOnlyString != FString())
	{
		PropReadOnlyString = FString();
		_GetSignals()->BroadcastPropReadOnlyStringChanged(PropReadOnlyString);
	}
}
