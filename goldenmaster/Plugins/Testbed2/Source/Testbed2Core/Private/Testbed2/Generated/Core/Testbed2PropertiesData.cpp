
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
#include "Testbed2/Generated/Core/Testbed2PropertiesData.h"

void Testbed2NestedStruct1InterfacePropertiesData::SetProp1(const FTestbed2NestedStruct1& InProp1)
{
	FWriteScopeLock WriteLock(Prop1Lock);
	Prop1 = InProp1;
}

FTestbed2NestedStruct1 Testbed2NestedStruct1InterfacePropertiesData::GetProp1() const
{
	FReadScopeLock ReadLock(Prop1Lock);
	return Prop1;
}

void Testbed2NestedStruct2InterfacePropertiesData::SetProp1(const FTestbed2NestedStruct1& InProp1)
{
	FWriteScopeLock WriteLock(Prop1Lock);
	Prop1 = InProp1;
}

FTestbed2NestedStruct1 Testbed2NestedStruct2InterfacePropertiesData::GetProp1() const
{
	FReadScopeLock ReadLock(Prop1Lock);
	return Prop1;
}

void Testbed2NestedStruct2InterfacePropertiesData::SetProp2(const FTestbed2NestedStruct2& InProp2)
{
	FWriteScopeLock WriteLock(Prop2Lock);
	Prop2 = InProp2;
}

FTestbed2NestedStruct2 Testbed2NestedStruct2InterfacePropertiesData::GetProp2() const
{
	FReadScopeLock ReadLock(Prop2Lock);
	return Prop2;
}

void Testbed2NestedStruct3InterfacePropertiesData::SetProp1(const FTestbed2NestedStruct1& InProp1)
{
	FWriteScopeLock WriteLock(Prop1Lock);
	Prop1 = InProp1;
}

FTestbed2NestedStruct1 Testbed2NestedStruct3InterfacePropertiesData::GetProp1() const
{
	FReadScopeLock ReadLock(Prop1Lock);
	return Prop1;
}

void Testbed2NestedStruct3InterfacePropertiesData::SetProp2(const FTestbed2NestedStruct2& InProp2)
{
	FWriteScopeLock WriteLock(Prop2Lock);
	Prop2 = InProp2;
}

FTestbed2NestedStruct2 Testbed2NestedStruct3InterfacePropertiesData::GetProp2() const
{
	FReadScopeLock ReadLock(Prop2Lock);
	return Prop2;
}

void Testbed2NestedStruct3InterfacePropertiesData::SetProp3(const FTestbed2NestedStruct3& InProp3)
{
	FWriteScopeLock WriteLock(Prop3Lock);
	Prop3 = InProp3;
}

FTestbed2NestedStruct3 Testbed2NestedStruct3InterfacePropertiesData::GetProp3() const
{
	FReadScopeLock ReadLock(Prop3Lock);
	return Prop3;
}
