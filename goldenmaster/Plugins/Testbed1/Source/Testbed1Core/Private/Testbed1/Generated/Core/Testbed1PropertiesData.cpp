
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
#include "Testbed1/Generated/Core/Testbed1PropertiesData.h"

void Testbed1StructInterfacePropertiesData::SetPropBool(const FTestbed1StructBool& InPropBool)
{
	FWriteScopeLock WriteLock(PropBoolLock);
	PropBool = InPropBool;
}

FTestbed1StructBool Testbed1StructInterfacePropertiesData::GetPropBool() const
{
	FReadScopeLock ReadLock(PropBoolLock);
	return PropBool;
}

void Testbed1StructInterfacePropertiesData::SetPropInt(const FTestbed1StructInt& InPropInt)
{
	FWriteScopeLock WriteLock(PropIntLock);
	PropInt = InPropInt;
}

FTestbed1StructInt Testbed1StructInterfacePropertiesData::GetPropInt() const
{
	FReadScopeLock ReadLock(PropIntLock);
	return PropInt;
}

void Testbed1StructInterfacePropertiesData::SetPropFloat(const FTestbed1StructFloat& InPropFloat)
{
	FWriteScopeLock WriteLock(PropFloatLock);
	PropFloat = InPropFloat;
}

FTestbed1StructFloat Testbed1StructInterfacePropertiesData::GetPropFloat() const
{
	FReadScopeLock ReadLock(PropFloatLock);
	return PropFloat;
}

void Testbed1StructInterfacePropertiesData::SetPropString(const FTestbed1StructString& InPropString)
{
	FWriteScopeLock WriteLock(PropStringLock);
	PropString = InPropString;
}

FTestbed1StructString Testbed1StructInterfacePropertiesData::GetPropString() const
{
	FReadScopeLock ReadLock(PropStringLock);
	return PropString;
}

void Testbed1StructArrayInterfacePropertiesData::SetPropBool(const TArray<FTestbed1StructBool>& InPropBool)
{
	FWriteScopeLock WriteLock(PropBoolLock);
	PropBool = InPropBool;
}

TArray<FTestbed1StructBool> Testbed1StructArrayInterfacePropertiesData::GetPropBool() const
{
	FReadScopeLock ReadLock(PropBoolLock);
	return PropBool;
}

void Testbed1StructArrayInterfacePropertiesData::SetPropInt(const TArray<FTestbed1StructInt>& InPropInt)
{
	FWriteScopeLock WriteLock(PropIntLock);
	PropInt = InPropInt;
}

TArray<FTestbed1StructInt> Testbed1StructArrayInterfacePropertiesData::GetPropInt() const
{
	FReadScopeLock ReadLock(PropIntLock);
	return PropInt;
}

void Testbed1StructArrayInterfacePropertiesData::SetPropFloat(const TArray<FTestbed1StructFloat>& InPropFloat)
{
	FWriteScopeLock WriteLock(PropFloatLock);
	PropFloat = InPropFloat;
}

TArray<FTestbed1StructFloat> Testbed1StructArrayInterfacePropertiesData::GetPropFloat() const
{
	FReadScopeLock ReadLock(PropFloatLock);
	return PropFloat;
}

void Testbed1StructArrayInterfacePropertiesData::SetPropString(const TArray<FTestbed1StructString>& InPropString)
{
	FWriteScopeLock WriteLock(PropStringLock);
	PropString = InPropString;
}

TArray<FTestbed1StructString> Testbed1StructArrayInterfacePropertiesData::GetPropString() const
{
	FReadScopeLock ReadLock(PropStringLock);
	return PropString;
}

void Testbed1StructArrayInterfacePropertiesData::SetPropEnum(const TArray<ETestbed1Enum0>& InPropEnum)
{
	FWriteScopeLock WriteLock(PropEnumLock);
	PropEnum = InPropEnum;
}

TArray<ETestbed1Enum0> Testbed1StructArrayInterfacePropertiesData::GetPropEnum() const
{
	FReadScopeLock ReadLock(PropEnumLock);
	return PropEnum;
}

void Testbed1StructArray2InterfacePropertiesData::SetPropBool(const FTestbed1StructBoolWithArray& InPropBool)
{
	FWriteScopeLock WriteLock(PropBoolLock);
	PropBool = InPropBool;
}

FTestbed1StructBoolWithArray Testbed1StructArray2InterfacePropertiesData::GetPropBool() const
{
	FReadScopeLock ReadLock(PropBoolLock);
	return PropBool;
}

void Testbed1StructArray2InterfacePropertiesData::SetPropInt(const FTestbed1StructIntWithArray& InPropInt)
{
	FWriteScopeLock WriteLock(PropIntLock);
	PropInt = InPropInt;
}

FTestbed1StructIntWithArray Testbed1StructArray2InterfacePropertiesData::GetPropInt() const
{
	FReadScopeLock ReadLock(PropIntLock);
	return PropInt;
}

void Testbed1StructArray2InterfacePropertiesData::SetPropFloat(const FTestbed1StructFloatWithArray& InPropFloat)
{
	FWriteScopeLock WriteLock(PropFloatLock);
	PropFloat = InPropFloat;
}

FTestbed1StructFloatWithArray Testbed1StructArray2InterfacePropertiesData::GetPropFloat() const
{
	FReadScopeLock ReadLock(PropFloatLock);
	return PropFloat;
}

void Testbed1StructArray2InterfacePropertiesData::SetPropString(const FTestbed1StructStringWithArray& InPropString)
{
	FWriteScopeLock WriteLock(PropStringLock);
	PropString = InPropString;
}

FTestbed1StructStringWithArray Testbed1StructArray2InterfacePropertiesData::GetPropString() const
{
	FReadScopeLock ReadLock(PropStringLock);
	return PropString;
}

void Testbed1StructArray2InterfacePropertiesData::SetPropEnum(const FTestbed1StructEnumWithArray& InPropEnum)
{
	FWriteScopeLock WriteLock(PropEnumLock);
	PropEnum = InPropEnum;
}

FTestbed1StructEnumWithArray Testbed1StructArray2InterfacePropertiesData::GetPropEnum() const
{
	FReadScopeLock ReadLock(PropEnumLock);
	return PropEnum;
}
