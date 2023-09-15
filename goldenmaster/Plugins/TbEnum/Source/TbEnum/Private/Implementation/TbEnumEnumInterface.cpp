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

#include "Implementation/TbEnumEnumInterface.h"

UTbEnumEnumInterface::~UTbEnumEnumInterface() = default;
ETbEnumEnum0 UTbEnumEnumInterface::GetProp0_Implementation() const
{
	return Prop0;
}

void UTbEnumEnumInterface::SetProp0_Implementation(ETbEnumEnum0 InProp0)
{
	if (Prop0 != InProp0)
	{
		Prop0 = InProp0;
		Execute__GetSignals(this)->OnProp0Changed.Broadcast(Prop0);
	}
}
ETbEnumEnum1 UTbEnumEnumInterface::GetProp1_Implementation() const
{
	return Prop1;
}

void UTbEnumEnumInterface::SetProp1_Implementation(ETbEnumEnum1 InProp1)
{
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		Execute__GetSignals(this)->OnProp1Changed.Broadcast(Prop1);
	}
}
ETbEnumEnum2 UTbEnumEnumInterface::GetProp2_Implementation() const
{
	return Prop2;
}

void UTbEnumEnumInterface::SetProp2_Implementation(ETbEnumEnum2 InProp2)
{
	if (Prop2 != InProp2)
	{
		Prop2 = InProp2;
		Execute__GetSignals(this)->OnProp2Changed.Broadcast(Prop2);
	}
}
ETbEnumEnum3 UTbEnumEnumInterface::GetProp3_Implementation() const
{
	return Prop3;
}

void UTbEnumEnumInterface::SetProp3_Implementation(ETbEnumEnum3 InProp3)
{
	if (Prop3 != InProp3)
	{
		Prop3 = InProp3;
		Execute__GetSignals(this)->OnProp3Changed.Broadcast(Prop3);
	}
}

ETbEnumEnum0 UTbEnumEnumInterface::Func0_Implementation(ETbEnumEnum0 Param0)
{
	(void)Param0;
	// do business logic here
	return ETbEnumEnum0::TEE_VALUE0;
}

ETbEnumEnum1 UTbEnumEnumInterface::Func1_Implementation(ETbEnumEnum1 Param1)
{
	(void)Param1;
	// do business logic here
	return ETbEnumEnum1::TEE_VALUE1;
}

ETbEnumEnum2 UTbEnumEnumInterface::Func2_Implementation(ETbEnumEnum2 Param2)
{
	(void)Param2;
	// do business logic here
	return ETbEnumEnum2::TEE_VALUE2;
}

ETbEnumEnum3 UTbEnumEnumInterface::Func3_Implementation(ETbEnumEnum3 Param3)
{
	(void)Param3;
	// do business logic here
	return ETbEnumEnum3::TEE_VALUE3;
}
