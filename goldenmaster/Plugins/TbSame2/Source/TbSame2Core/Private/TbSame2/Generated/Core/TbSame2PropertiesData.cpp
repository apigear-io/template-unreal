
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
#include "TbSame2/Generated/Core/TbSame2PropertiesData.h"

void TbSame2SameStruct1InterfacePropertiesData::SetProp1(const FTbSame2Struct1& InProp1)
{
	FScopeLock Lock(&(Prop1CS));
	Prop1 = InProp1;
}

FTbSame2Struct1 TbSame2SameStruct1InterfacePropertiesData::GetProp1() const
{
	FScopeLock Lock(&(Prop1CS));
	return Prop1;
}

void TbSame2SameStruct2InterfacePropertiesData::SetProp1(const FTbSame2Struct2& InProp1)
{
	FScopeLock Lock(&(Prop1CS));
	Prop1 = InProp1;
}

FTbSame2Struct2 TbSame2SameStruct2InterfacePropertiesData::GetProp1() const
{
	FScopeLock Lock(&(Prop1CS));
	return Prop1;
}

void TbSame2SameStruct2InterfacePropertiesData::SetProp2(const FTbSame2Struct2& InProp2)
{
	FScopeLock Lock(&(Prop2CS));
	Prop2 = InProp2;
}

FTbSame2Struct2 TbSame2SameStruct2InterfacePropertiesData::GetProp2() const
{
	FScopeLock Lock(&(Prop2CS));
	return Prop2;
}
