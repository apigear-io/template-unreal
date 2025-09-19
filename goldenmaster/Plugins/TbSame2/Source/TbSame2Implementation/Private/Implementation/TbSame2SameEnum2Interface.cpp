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

#include "TbSame2/Implementation/TbSame2SameEnum2Interface.h"

UTbSame2SameEnum2InterfaceImplementation::~UTbSame2SameEnum2InterfaceImplementation() = default;
ETbSame2Enum1 UTbSame2SameEnum2InterfaceImplementation::GetProp1() const
{
	return Prop1;
}

void UTbSame2SameEnum2InterfaceImplementation::SetProp1(ETbSame2Enum1 InProp1)
{
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		_GetPublisher()->BroadcastProp1Changed(Prop1);
	}
}
ETbSame2Enum2 UTbSame2SameEnum2InterfaceImplementation::GetProp2() const
{
	return Prop2;
}

void UTbSame2SameEnum2InterfaceImplementation::SetProp2(ETbSame2Enum2 InProp2)
{
	if (Prop2 != InProp2)
	{
		Prop2 = InProp2;
		_GetPublisher()->BroadcastProp2Changed(Prop2);
	}
}

ETbSame2Enum1 UTbSame2SameEnum2InterfaceImplementation::Func1(ETbSame2Enum1 Param1)
{
	(void)Param1;
	// do business logic here
	return ETbSame2Enum1::TS2E1_Value1;
}

ETbSame2Enum1 UTbSame2SameEnum2InterfaceImplementation::Func2(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2)
{
	(void)Param1;
	(void)Param2;
	// do business logic here
	return ETbSame2Enum1::TS2E1_Value1;
}

void UTbSame2SameEnum2InterfaceImplementation::_ResetProperties()
{
	if (Prop1 != ETbSame2Enum1::TS2E1_Value1)
	{
		Prop1 = ETbSame2Enum1::TS2E1_Value1;
		_GetPublisher()->BroadcastProp1Changed(Prop1);
	}
	if (Prop2 != ETbSame2Enum2::TS2E2_Value1)
	{
		Prop2 = ETbSame2Enum2::TS2E2_Value1;
		_GetPublisher()->BroadcastProp2Changed(Prop2);
	}
}
