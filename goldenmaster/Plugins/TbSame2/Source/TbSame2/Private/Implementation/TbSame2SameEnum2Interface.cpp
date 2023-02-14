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

#include "Implementation/TbSame2SameEnum2Interface.h"

UTbSame2SameEnum2Interface::~UTbSame2SameEnum2Interface() = default;

void UTbSame2SameEnum2Interface::BroadcastSig1_Implementation(ETbSame2Enum1 Param1)
{
	Sig1Signal.Broadcast(Param1);
}

FTbSame2SameEnum2InterfaceSig1Delegate& UTbSame2SameEnum2Interface::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

void UTbSame2SameEnum2Interface::BroadcastSig2_Implementation(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2)
{
	Sig2Signal.Broadcast(Param1, Param2);
}

FTbSame2SameEnum2InterfaceSig2Delegate& UTbSame2SameEnum2Interface::GetSig2SignalDelegate()
{
	return Sig2Signal;
}

void UTbSame2SameEnum2Interface::BroadcastProp1Changed_Implementation(ETbSame2Enum1 InProp1)
{
	Prop1Changed.Broadcast(InProp1);
}

ETbSame2Enum1 UTbSame2SameEnum2Interface::GetProp1_Implementation() const
{
	return Prop1;
}

void UTbSame2SameEnum2Interface::SetProp1_Implementation(ETbSame2Enum1 InProp1)
{
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		Execute_BroadcastProp1Changed(this, Prop1);
	}
}

FTbSame2SameEnum2InterfaceProp1ChangedDelegate& UTbSame2SameEnum2Interface::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}

void UTbSame2SameEnum2Interface::BroadcastProp2Changed_Implementation(ETbSame2Enum2 InProp2)
{
	Prop2Changed.Broadcast(InProp2);
}

ETbSame2Enum2 UTbSame2SameEnum2Interface::GetProp2_Implementation() const
{
	return Prop2;
}

void UTbSame2SameEnum2Interface::SetProp2_Implementation(ETbSame2Enum2 InProp2)
{
	if (Prop2 != InProp2)
	{
		Prop2 = InProp2;
		Execute_BroadcastProp2Changed(this, Prop2);
	}
}

FTbSame2SameEnum2InterfaceProp2ChangedDelegate& UTbSame2SameEnum2Interface::GetProp2ChangedDelegate()
{
	return Prop2Changed;
}

ETbSame2Enum1 UTbSame2SameEnum2Interface::Func1_Implementation(ETbSame2Enum1 Param1)
{
	(void)Param1;
	// do business logic here
	return ETbSame2Enum1::TSE_VALUE1;
}

ETbSame2Enum1 UTbSame2SameEnum2Interface::Func2_Implementation(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2)
{
	(void)Param1;
	(void)Param2;
	// do business logic here
	return ETbSame2Enum1::TSE_VALUE1;
}
