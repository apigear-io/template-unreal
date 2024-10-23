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

#include "Implementation/TbSimpleSimpleArrayInterface.h"

UTbSimpleSimpleArrayInterface::~UTbSimpleSimpleArrayInterface() = default;
TArray<bool> UTbSimpleSimpleArrayInterface::GetPropBool_Implementation() const
{
	return PropBool;
}

void UTbSimpleSimpleArrayInterface::SetPropBool_Implementation(const TArray<bool>& InPropBool)
{
	if (PropBool != InPropBool)
	{
		PropBool = InPropBool;
		Execute__GetSignals(this)->OnPropBoolChanged.Broadcast(PropBool);
	}
}
TArray<int32> UTbSimpleSimpleArrayInterface::GetPropInt_Implementation() const
{
	return PropInt;
}

void UTbSimpleSimpleArrayInterface::SetPropInt_Implementation(const TArray<int32>& InPropInt)
{
	if (PropInt != InPropInt)
	{
		PropInt = InPropInt;
		Execute__GetSignals(this)->OnPropIntChanged.Broadcast(PropInt);
	}
}
TArray<int32> UTbSimpleSimpleArrayInterface::GetPropInt32_Implementation() const
{
	return PropInt32;
}

void UTbSimpleSimpleArrayInterface::SetPropInt32_Implementation(const TArray<int32>& InPropInt32)
{
	if (PropInt32 != InPropInt32)
	{
		PropInt32 = InPropInt32;
		Execute__GetSignals(this)->OnPropInt32Changed.Broadcast(PropInt32);
	}
}
TArray<int64> UTbSimpleSimpleArrayInterface::GetPropInt64_Implementation() const
{
	return PropInt64;
}

void UTbSimpleSimpleArrayInterface::SetPropInt64_Implementation(const TArray<int64>& InPropInt64)
{
	if (PropInt64 != InPropInt64)
	{
		PropInt64 = InPropInt64;
		Execute__GetSignals(this)->OnPropInt64Changed.Broadcast(PropInt64);
	}
}
TArray<float> UTbSimpleSimpleArrayInterface::GetPropFloat_Implementation() const
{
	return PropFloat;
}

void UTbSimpleSimpleArrayInterface::SetPropFloat_Implementation(const TArray<float>& InPropFloat)
{
	if (PropFloat != InPropFloat)
	{
		PropFloat = InPropFloat;
		Execute__GetSignals(this)->OnPropFloatChanged.Broadcast(PropFloat);
	}
}
TArray<float> UTbSimpleSimpleArrayInterface::GetPropFloat32_Implementation() const
{
	return PropFloat32;
}

void UTbSimpleSimpleArrayInterface::SetPropFloat32_Implementation(const TArray<float>& InPropFloat32)
{
	if (PropFloat32 != InPropFloat32)
	{
		PropFloat32 = InPropFloat32;
		Execute__GetSignals(this)->OnPropFloat32Changed.Broadcast(PropFloat32);
	}
}
TArray<double> UTbSimpleSimpleArrayInterface::GetPropFloat64_Implementation() const
{
	return PropFloat64;
}

void UTbSimpleSimpleArrayInterface::SetPropFloat64_Implementation(const TArray<double>& InPropFloat64)
{
	if (PropFloat64 != InPropFloat64)
	{
		PropFloat64 = InPropFloat64;
		Execute__GetSignals(this)->OnPropFloat64Changed.Broadcast(PropFloat64);
	}
}
TArray<FString> UTbSimpleSimpleArrayInterface::GetPropString_Implementation() const
{
	return PropString;
}

void UTbSimpleSimpleArrayInterface::SetPropString_Implementation(const TArray<FString>& InPropString)
{
	if (PropString != InPropString)
	{
		PropString = InPropString;
		Execute__GetSignals(this)->OnPropStringChanged.Broadcast(PropString);
	}
}
FString UTbSimpleSimpleArrayInterface::GetPropReadOnlyString_Implementation() const
{
	return PropReadOnlyString;
}

TArray<bool> UTbSimpleSimpleArrayInterface::FuncBool_Implementation(const TArray<bool>& ParamBool)
{
	(void)ParamBool;
	// do business logic here
	return TArray<bool>();
}

TArray<int32> UTbSimpleSimpleArrayInterface::FuncInt_Implementation(const TArray<int32>& ParamInt)
{
	(void)ParamInt;
	// do business logic here
	return TArray<int32>();
}

TArray<int32> UTbSimpleSimpleArrayInterface::FuncInt32_Implementation(const TArray<int32>& ParamInt32)
{
	(void)ParamInt32;
	// do business logic here
	return TArray<int32>();
}

TArray<int64> UTbSimpleSimpleArrayInterface::FuncInt64_Implementation(const TArray<int64>& ParamInt64)
{
	(void)ParamInt64;
	// do business logic here
	return TArray<int64>();
}

TArray<float> UTbSimpleSimpleArrayInterface::FuncFloat_Implementation(const TArray<float>& ParamFloat)
{
	(void)ParamFloat;
	// do business logic here
	return TArray<float>();
}

TArray<float> UTbSimpleSimpleArrayInterface::FuncFloat32_Implementation(const TArray<float>& ParamFloat32)
{
	(void)ParamFloat32;
	// do business logic here
	return TArray<float>();
}

TArray<double> UTbSimpleSimpleArrayInterface::FuncFloat64_Implementation(const TArray<double>& ParamFloat)
{
	(void)ParamFloat;
	// do business logic here
	return TArray<double>();
}

TArray<FString> UTbSimpleSimpleArrayInterface::FuncString_Implementation(const TArray<FString>& ParamString)
{
	(void)ParamString;
	// do business logic here
	return TArray<FString>();
}
