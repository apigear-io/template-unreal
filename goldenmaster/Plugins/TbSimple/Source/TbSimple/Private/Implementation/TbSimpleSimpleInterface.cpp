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

#include "Implementation/TbSimpleSimpleInterface.h"

UTbSimpleSimpleInterface::~UTbSimpleSimpleInterface() = default;
bool UTbSimpleSimpleInterface::GetPropBool_Implementation() const
{
	return bPropBool;
}

void UTbSimpleSimpleInterface::SetPropBool_Implementation(bool bInPropBool)
{
	if (bPropBool != bInPropBool)
	{
		bPropBool = bInPropBool;
		Execute_BroadcastPropBoolChanged(this, bPropBool);
	}
}
int32 UTbSimpleSimpleInterface::GetPropInt_Implementation() const
{
	return PropInt;
}

void UTbSimpleSimpleInterface::SetPropInt_Implementation(int32 InPropInt)
{
	if (PropInt != InPropInt)
	{
		PropInt = InPropInt;
		Execute_BroadcastPropIntChanged(this, PropInt);
	}
}
int32 UTbSimpleSimpleInterface::GetPropInt32_Implementation() const
{
	return PropInt32;
}

void UTbSimpleSimpleInterface::SetPropInt32_Implementation(int32 InPropInt32)
{
	if (PropInt32 != InPropInt32)
	{
		PropInt32 = InPropInt32;
		Execute_BroadcastPropInt32Changed(this, PropInt32);
	}
}
int64 UTbSimpleSimpleInterface::GetPropInt64_Implementation() const
{
	return PropInt64;
}

void UTbSimpleSimpleInterface::SetPropInt64_Implementation(int64 InPropInt64)
{
	if (PropInt64 != InPropInt64)
	{
		PropInt64 = InPropInt64;
		Execute_BroadcastPropInt64Changed(this, PropInt64);
	}
}
float UTbSimpleSimpleInterface::GetPropFloat_Implementation() const
{
	return PropFloat;
}

void UTbSimpleSimpleInterface::SetPropFloat_Implementation(float InPropFloat)
{
	if (PropFloat != InPropFloat)
	{
		PropFloat = InPropFloat;
		Execute_BroadcastPropFloatChanged(this, PropFloat);
	}
}
float UTbSimpleSimpleInterface::GetPropFloat32_Implementation() const
{
	return PropFloat32;
}

void UTbSimpleSimpleInterface::SetPropFloat32_Implementation(float InPropFloat32)
{
	if (PropFloat32 != InPropFloat32)
	{
		PropFloat32 = InPropFloat32;
		Execute_BroadcastPropFloat32Changed(this, PropFloat32);
	}
}
double UTbSimpleSimpleInterface::GetPropFloat64_Implementation() const
{
	return PropFloat64;
}

void UTbSimpleSimpleInterface::SetPropFloat64_Implementation(double InPropFloat64)
{
	if (PropFloat64 != InPropFloat64)
	{
		PropFloat64 = InPropFloat64;
		Execute_BroadcastPropFloat64Changed(this, PropFloat64);
	}
}
FString UTbSimpleSimpleInterface::GetPropString_Implementation() const
{
	return PropString;
}

void UTbSimpleSimpleInterface::SetPropString_Implementation(const FString& InPropString)
{
	if (PropString != InPropString)
	{
		PropString = InPropString;
		Execute_BroadcastPropStringChanged(this, PropString);
	}
}

void UTbSimpleSimpleInterface::FuncVoid_Implementation()
{
	// do business logic here
}

bool UTbSimpleSimpleInterface::FuncBool_Implementation(bool bParamBool)
{
	(void)bParamBool;
	// do business logic here
	return false;
}

int32 UTbSimpleSimpleInterface::FuncInt_Implementation(int32 ParamInt)
{
	(void)ParamInt;
	// do business logic here
	return 0;
}

int32 UTbSimpleSimpleInterface::FuncInt32_Implementation(int32 ParamInt32)
{
	(void)ParamInt32;
	// do business logic here
	return 0;
}

int64 UTbSimpleSimpleInterface::FuncInt64_Implementation(int64 ParamInt64)
{
	(void)ParamInt64;
	// do business logic here
	return 0LL;
}

float UTbSimpleSimpleInterface::FuncFloat_Implementation(float ParamFloat)
{
	(void)ParamFloat;
	// do business logic here
	return 0.0f;
}

float UTbSimpleSimpleInterface::FuncFloat32_Implementation(float ParamFloat32)
{
	(void)ParamFloat32;
	// do business logic here
	return 0.0f;
}

double UTbSimpleSimpleInterface::FuncFloat64_Implementation(double ParamFloat)
{
	(void)ParamFloat;
	// do business logic here
	return 0.0;
}

FString UTbSimpleSimpleInterface::FuncString_Implementation(const FString& ParamString)
{
	(void)ParamString;
	// do business logic here
	return FString();
}
