
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
	FWriteScopeLock WriteLock(PropStringLock);
	PropString = InPropString;
}

FString TbSimpleSimpleInterfacePropertiesData::GetPropString() const
{
	FReadScopeLock ReadLock(PropStringLock);
	return PropString;
}

void TbSimpleSimpleArrayInterfacePropertiesData::SetPropBool(const TArray<bool>& InPropBool)
{
	FWriteScopeLock WriteLock(PropBoolLock);
	PropBool = InPropBool;
}

TArray<bool> TbSimpleSimpleArrayInterfacePropertiesData::GetPropBool() const
{
	FReadScopeLock ReadLock(PropBoolLock);
	return PropBool;
}

void TbSimpleSimpleArrayInterfacePropertiesData::SetPropInt(const TArray<int32>& InPropInt)
{
	FWriteScopeLock WriteLock(PropIntLock);
	PropInt = InPropInt;
}

TArray<int32> TbSimpleSimpleArrayInterfacePropertiesData::GetPropInt() const
{
	FReadScopeLock ReadLock(PropIntLock);
	return PropInt;
}

void TbSimpleSimpleArrayInterfacePropertiesData::SetPropInt32(const TArray<int32>& InPropInt32)
{
	FWriteScopeLock WriteLock(PropInt32Lock);
	PropInt32 = InPropInt32;
}

TArray<int32> TbSimpleSimpleArrayInterfacePropertiesData::GetPropInt32() const
{
	FReadScopeLock ReadLock(PropInt32Lock);
	return PropInt32;
}

void TbSimpleSimpleArrayInterfacePropertiesData::SetPropInt64(const TArray<int64>& InPropInt64)
{
	FWriteScopeLock WriteLock(PropInt64Lock);
	PropInt64 = InPropInt64;
}

TArray<int64> TbSimpleSimpleArrayInterfacePropertiesData::GetPropInt64() const
{
	FReadScopeLock ReadLock(PropInt64Lock);
	return PropInt64;
}

void TbSimpleSimpleArrayInterfacePropertiesData::SetPropFloat(const TArray<float>& InPropFloat)
{
	FWriteScopeLock WriteLock(PropFloatLock);
	PropFloat = InPropFloat;
}

TArray<float> TbSimpleSimpleArrayInterfacePropertiesData::GetPropFloat() const
{
	FReadScopeLock ReadLock(PropFloatLock);
	return PropFloat;
}

void TbSimpleSimpleArrayInterfacePropertiesData::SetPropFloat32(const TArray<float>& InPropFloat32)
{
	FWriteScopeLock WriteLock(PropFloat32Lock);
	PropFloat32 = InPropFloat32;
}

TArray<float> TbSimpleSimpleArrayInterfacePropertiesData::GetPropFloat32() const
{
	FReadScopeLock ReadLock(PropFloat32Lock);
	return PropFloat32;
}

void TbSimpleSimpleArrayInterfacePropertiesData::SetPropFloat64(const TArray<double>& InPropFloat64)
{
	FWriteScopeLock WriteLock(PropFloat64Lock);
	PropFloat64 = InPropFloat64;
}

TArray<double> TbSimpleSimpleArrayInterfacePropertiesData::GetPropFloat64() const
{
	FReadScopeLock ReadLock(PropFloat64Lock);
	return PropFloat64;
}

void TbSimpleSimpleArrayInterfacePropertiesData::SetPropString(const TArray<FString>& InPropString)
{
	FWriteScopeLock WriteLock(PropStringLock);
	PropString = InPropString;
}

TArray<FString> TbSimpleSimpleArrayInterfacePropertiesData::GetPropString() const
{
	FReadScopeLock ReadLock(PropStringLock);
	return PropString;
}

void TbSimpleSimpleArrayInterfacePropertiesData::SetPropReadOnlyString(const FString& InPropReadOnlyString)
{
	FWriteScopeLock WriteLock(PropReadOnlyStringLock);
	PropReadOnlyString = InPropReadOnlyString;
}

FString TbSimpleSimpleArrayInterfacePropertiesData::GetPropReadOnlyString() const
{
	FReadScopeLock ReadLock(PropReadOnlyStringLock);
	return PropReadOnlyString;
}
