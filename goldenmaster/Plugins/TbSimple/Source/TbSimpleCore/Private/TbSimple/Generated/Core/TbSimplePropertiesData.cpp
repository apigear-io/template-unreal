
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
#include "TbSimple/Generated/Core/TbSimplePropertiesData.h"

void TbSimpleSimpleInterfacePropertiesData::SetPropString(const FString& InPropString)
{
	FScopeLock Lock(&(PropStringCS));
	PropString = InPropString;
}

FString TbSimpleSimpleInterfacePropertiesData::GetPropString() const
{
	FScopeLock Lock(&(PropStringCS));
	return PropString;
}

void TbSimpleSimpleArrayInterfacePropertiesData::SetPropBool(const TArray<bool>& InPropBool)
{
	FScopeLock Lock(&(PropBoolCS));
	PropBool = InPropBool;
}

TArray<bool> TbSimpleSimpleArrayInterfacePropertiesData::GetPropBool() const
{
	FScopeLock Lock(&(PropBoolCS));
	return PropBool;
}

void TbSimpleSimpleArrayInterfacePropertiesData::SetPropInt(const TArray<int32>& InPropInt)
{
	FScopeLock Lock(&(PropIntCS));
	PropInt = InPropInt;
}

TArray<int32> TbSimpleSimpleArrayInterfacePropertiesData::GetPropInt() const
{
	FScopeLock Lock(&(PropIntCS));
	return PropInt;
}

void TbSimpleSimpleArrayInterfacePropertiesData::SetPropInt32(const TArray<int32>& InPropInt32)
{
	FScopeLock Lock(&(PropInt32CS));
	PropInt32 = InPropInt32;
}

TArray<int32> TbSimpleSimpleArrayInterfacePropertiesData::GetPropInt32() const
{
	FScopeLock Lock(&(PropInt32CS));
	return PropInt32;
}

void TbSimpleSimpleArrayInterfacePropertiesData::SetPropInt64(const TArray<int64>& InPropInt64)
{
	FScopeLock Lock(&(PropInt64CS));
	PropInt64 = InPropInt64;
}

TArray<int64> TbSimpleSimpleArrayInterfacePropertiesData::GetPropInt64() const
{
	FScopeLock Lock(&(PropInt64CS));
	return PropInt64;
}

void TbSimpleSimpleArrayInterfacePropertiesData::SetPropFloat(const TArray<float>& InPropFloat)
{
	FScopeLock Lock(&(PropFloatCS));
	PropFloat = InPropFloat;
}

TArray<float> TbSimpleSimpleArrayInterfacePropertiesData::GetPropFloat() const
{
	FScopeLock Lock(&(PropFloatCS));
	return PropFloat;
}

void TbSimpleSimpleArrayInterfacePropertiesData::SetPropFloat32(const TArray<float>& InPropFloat32)
{
	FScopeLock Lock(&(PropFloat32CS));
	PropFloat32 = InPropFloat32;
}

TArray<float> TbSimpleSimpleArrayInterfacePropertiesData::GetPropFloat32() const
{
	FScopeLock Lock(&(PropFloat32CS));
	return PropFloat32;
}

void TbSimpleSimpleArrayInterfacePropertiesData::SetPropFloat64(const TArray<double>& InPropFloat64)
{
	FScopeLock Lock(&(PropFloat64CS));
	PropFloat64 = InPropFloat64;
}

TArray<double> TbSimpleSimpleArrayInterfacePropertiesData::GetPropFloat64() const
{
	FScopeLock Lock(&(PropFloat64CS));
	return PropFloat64;
}

void TbSimpleSimpleArrayInterfacePropertiesData::SetPropString(const TArray<FString>& InPropString)
{
	FScopeLock Lock(&(PropStringCS));
	PropString = InPropString;
}

TArray<FString> TbSimpleSimpleArrayInterfacePropertiesData::GetPropString() const
{
	FScopeLock Lock(&(PropStringCS));
	return PropString;
}

void TbSimpleSimpleArrayInterfacePropertiesData::SetPropReadOnlyString(const FString& InPropReadOnlyString)
{
	FScopeLock Lock(&(PropReadOnlyStringCS));
	PropReadOnlyString = InPropReadOnlyString;
}

FString TbSimpleSimpleArrayInterfacePropertiesData::GetPropReadOnlyString() const
{
	FScopeLock Lock(&(PropReadOnlyStringCS));
	return PropReadOnlyString;
}
