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

#include "TbSame2/Implementation/TbSame2SameStruct2Interface.h"

UTbSame2SameStruct2InterfaceImplementation::~UTbSame2SameStruct2InterfaceImplementation() = default;
FTbSame2Struct2 UTbSame2SameStruct2InterfaceImplementation::GetProp1() const
{
	return Prop1;
}

void UTbSame2SameStruct2InterfaceImplementation::SetProp1(const FTbSame2Struct2& InProp1)
{
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		_GetSignals()->BroadcastProp1Changed(Prop1);
	}
}
FTbSame2Struct2 UTbSame2SameStruct2InterfaceImplementation::GetProp2() const
{
	return Prop2;
}

void UTbSame2SameStruct2InterfaceImplementation::SetProp2(const FTbSame2Struct2& InProp2)
{
	if (Prop2 != InProp2)
	{
		Prop2 = InProp2;
		_GetSignals()->BroadcastProp2Changed(Prop2);
	}
}

FTbSame2Struct1 UTbSame2SameStruct2InterfaceImplementation::Func1(const FTbSame2Struct1& Param1)
{
	(void)Param1;
	// do business logic here
	return FTbSame2Struct1();
}

FTbSame2Struct1 UTbSame2SameStruct2InterfaceImplementation::Func2(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2)
{
	(void)Param1;
	(void)Param2;
	// do business logic here
	return FTbSame2Struct1();
}

void UTbSame2SameStruct2InterfaceImplementation::_ResetProperties()
{
	if (Prop1 != FTbSame2Struct2())
	{
		Prop1 = FTbSame2Struct2();
		_GetSignals()->BroadcastProp1Changed(Prop1);
	}
	if (Prop2 != FTbSame2Struct2())
	{
		Prop2 = FTbSame2Struct2();
		_GetSignals()->BroadcastProp2Changed(Prop2);
	}
}
