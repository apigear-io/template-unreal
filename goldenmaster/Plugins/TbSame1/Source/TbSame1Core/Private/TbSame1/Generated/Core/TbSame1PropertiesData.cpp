
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
#include "TbSame1/Generated/Core/TbSame1PropertiesData.h"

void TbSame1SameStruct1InterfacePropertiesData::SetProp1(const FTbSame1Struct1& InProp1)
{
	FWriteScopeLock WriteLock(Prop1Lock);
	Prop1 = InProp1;
}

FTbSame1Struct1 TbSame1SameStruct1InterfacePropertiesData::GetProp1() const
{
	FReadScopeLock ReadLock(Prop1Lock);
	return Prop1;
}

void TbSame1SameStruct2InterfacePropertiesData::SetProp1(const FTbSame1Struct2& InProp1)
{
	FWriteScopeLock WriteLock(Prop1Lock);
	Prop1 = InProp1;
}

FTbSame1Struct2 TbSame1SameStruct2InterfacePropertiesData::GetProp1() const
{
	FReadScopeLock ReadLock(Prop1Lock);
	return Prop1;
}

void TbSame1SameStruct2InterfacePropertiesData::SetProp2(const FTbSame1Struct2& InProp2)
{
	FWriteScopeLock WriteLock(Prop2Lock);
	Prop2 = InProp2;
}

FTbSame1Struct2 TbSame1SameStruct2InterfacePropertiesData::GetProp2() const
{
	FReadScopeLock ReadLock(Prop2Lock);
	return Prop2;
}
