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

#include "TbEnum/Implementation/TbEnumEnumInterface.h"

UTbEnumEnumInterface::~UTbEnumEnumInterface() = default;
ETbEnumEnum0 UTbEnumEnumInterface::GetProp0() const
{
	return Prop0;
}

void UTbEnumEnumInterface::SetProp0(ETbEnumEnum0 InProp0)
{
	if (Prop0 != InProp0)
	{
		Prop0 = InProp0;
		_GetSignals()->BroadcastProp0Changed(Prop0);
	}
}
ETbEnumEnum1 UTbEnumEnumInterface::GetProp1() const
{
	return Prop1;
}

void UTbEnumEnumInterface::SetProp1(ETbEnumEnum1 InProp1)
{
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		_GetSignals()->BroadcastProp1Changed(Prop1);
	}
}
ETbEnumEnum2 UTbEnumEnumInterface::GetProp2() const
{
	return Prop2;
}

void UTbEnumEnumInterface::SetProp2(ETbEnumEnum2 InProp2)
{
	if (Prop2 != InProp2)
	{
		Prop2 = InProp2;
		_GetSignals()->BroadcastProp2Changed(Prop2);
	}
}
ETbEnumEnum3 UTbEnumEnumInterface::GetProp3() const
{
	return Prop3;
}

void UTbEnumEnumInterface::SetProp3(ETbEnumEnum3 InProp3)
{
	if (Prop3 != InProp3)
	{
		Prop3 = InProp3;
		_GetSignals()->BroadcastProp3Changed(Prop3);
	}
}

ETbEnumEnum0 UTbEnumEnumInterface::Func0(ETbEnumEnum0 Param0)
{
	(void)Param0;
	// do business logic here
	return ETbEnumEnum0::TEE0_VALUE0;
}

ETbEnumEnum1 UTbEnumEnumInterface::Func1(ETbEnumEnum1 Param1)
{
	(void)Param1;
	// do business logic here
	return ETbEnumEnum1::TEE1_VALUE1;
}

ETbEnumEnum2 UTbEnumEnumInterface::Func2(ETbEnumEnum2 Param2)
{
	(void)Param2;
	// do business logic here
	return ETbEnumEnum2::TEE2_VALUE2;
}

ETbEnumEnum3 UTbEnumEnumInterface::Func3(ETbEnumEnum3 Param3)
{
	(void)Param3;
	// do business logic here
	return ETbEnumEnum3::TEE3_VALUE3;
}
