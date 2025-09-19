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

#include "TbSame2/Implementation/TbSame2SameEnum1Interface.h"

UTbSame2SameEnum1InterfaceImplementation::~UTbSame2SameEnum1InterfaceImplementation() = default;
ETbSame2Enum1 UTbSame2SameEnum1InterfaceImplementation::GetProp1() const
{
	return Prop1;
}

void UTbSame2SameEnum1InterfaceImplementation::SetProp1(ETbSame2Enum1 InProp1)
{
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		_GetPublisher()->BroadcastProp1Changed(Prop1);
	}
}

ETbSame2Enum1 UTbSame2SameEnum1InterfaceImplementation::Func1(ETbSame2Enum1 Param1)
{
	(void)Param1;
	// do business logic here
	return ETbSame2Enum1::TS2E1_Value1;
}

void UTbSame2SameEnum1InterfaceImplementation::_ResetProperties()
{
	if (Prop1 != ETbSame2Enum1::TS2E1_Value1)
	{
		Prop1 = ETbSame2Enum1::TS2E1_Value1;
		_GetPublisher()->BroadcastProp1Changed(Prop1);
	}
}
