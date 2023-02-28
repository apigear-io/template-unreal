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
#include "TbSame2SameEnum2InterfaceInterface.h"

UFUNCTION(Category = "ApiGear|TbSame2|SameEnum2Interface")
FTbSame2SameEnum2InterfaceSig1Delegate& UAbstractTbSame2SameEnum2Interface::GetSig1SignalDelegate()
{
	return Sig1Signal;
};

UFUNCTION(Category = "ApiGear|TbSame2|SameEnum2Interface")
FTbSame2SameEnum2InterfaceSig2Delegate& UAbstractTbSame2SameEnum2Interface::GetSig2SignalDelegate()
{
	return Sig2Signal;
};

FTbSame2SameEnum2InterfaceProp1ChangedDelegate& UAbstractTbSame2SameEnum2Interface::GetProp1ChangedDelegate()
{
	return Prop1Changed;
};

FTbSame2SameEnum2InterfaceProp2ChangedDelegate& UAbstractTbSame2SameEnum2Interface::GetProp2ChangedDelegate()
{
	return Prop2Changed;
};
void UAbstractTbSame2SameEnum2Interface::BroadcastSig1_Implementation(ETbSame2Enum1 Param1)
{
	Sig1Signal.Broadcast(Param1);
};

void UAbstractTbSame2SameEnum2Interface::BroadcastSig2_Implementation(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2)
{
	Sig2Signal.Broadcast(Param1, Param2);
};

void UAbstractTbSame2SameEnum2Interface::BroadcastProp1Changed_Implementation(ETbSame2Enum1 InProp1)
{
	Prop1Changed.Broadcast(InProp1);
}

void UAbstractTbSame2SameEnum2Interface::BroadcastProp2Changed_Implementation(ETbSame2Enum2 InProp2)
{
	Prop2Changed.Broadcast(InProp2);
}
ETbSame2Enum1 UAbstractTbSame2SameEnum2Interface::GetProp1_Private() const
{
	return Execute_GetProp1(this);
};

void UAbstractTbSame2SameEnum2Interface::SetProp1_Private(ETbSame2Enum1 InProp1)
{
	Execute_SetProp1(this, InProp1);
};

ETbSame2Enum2 UAbstractTbSame2SameEnum2Interface::GetProp2_Private() const
{
	return Execute_GetProp2(this);
};

void UAbstractTbSame2SameEnum2Interface::SetProp2_Private(ETbSame2Enum2 InProp2)
{
	Execute_SetProp2(this, InProp2);
};
