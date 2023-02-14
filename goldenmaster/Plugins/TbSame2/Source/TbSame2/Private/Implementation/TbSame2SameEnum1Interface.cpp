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

#include "Implementation/TbSame2SameEnum1Interface.h"

UTbSame2SameEnum1Interface::~UTbSame2SameEnum1Interface() = default;

void UTbSame2SameEnum1Interface::BroadcastSig1_Implementation(ETbSame2Enum1 Param1)
{
	Sig1Signal.Broadcast(Param1);
}

FTbSame2SameEnum1InterfaceSig1Delegate& UTbSame2SameEnum1Interface::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

void UTbSame2SameEnum1Interface::BroadcastProp1Changed_Implementation(ETbSame2Enum1 InProp1)
{
	Prop1Changed.Broadcast(InProp1);
}

ETbSame2Enum1 UTbSame2SameEnum1Interface::GetProp1_Implementation() const
{
	return Prop1;
}

void UTbSame2SameEnum1Interface::SetProp1_Implementation(ETbSame2Enum1 InProp1)
{
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		Execute_BroadcastProp1Changed(this, Prop1);
	}
}

FTbSame2SameEnum1InterfaceProp1ChangedDelegate& UTbSame2SameEnum1Interface::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}

ETbSame2Enum1 UTbSame2SameEnum1Interface::Func1_Implementation(ETbSame2Enum1 Param1)
{
	(void)Param1;
	// do business logic here
	return ETbSame2Enum1::TSE_VALUE1;
}
