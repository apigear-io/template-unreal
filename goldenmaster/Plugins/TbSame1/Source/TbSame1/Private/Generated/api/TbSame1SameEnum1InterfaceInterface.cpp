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
#include "TbSame1SameEnum1InterfaceInterface.h"

UFUNCTION(Category = "ApiGear|TbSame1|SameEnum1Interface")
FTbSame1SameEnum1InterfaceSig1Delegate& UAbstractTbSame1SameEnum1Interface::GetSig1SignalDelegate()
{
	return Sig1Signal;
};

FTbSame1SameEnum1InterfaceProp1ChangedDelegate& UAbstractTbSame1SameEnum1Interface::GetProp1ChangedDelegate()
{
	return Prop1Changed;
};
void UAbstractTbSame1SameEnum1Interface::BroadcastSig1_Implementation(ETbSame1Enum1 Param1)
{
	Sig1Signal.Broadcast(Param1);
};

void UAbstractTbSame1SameEnum1Interface::BroadcastProp1Changed_Implementation(ETbSame1Enum1 InProp1)
{
	Prop1Changed.Broadcast(InProp1);
}
ETbSame1Enum1 UAbstractTbSame1SameEnum1Interface::GetProp1_Private() const
{
	return Execute_GetProp1(this);
};

void UAbstractTbSame1SameEnum1Interface::SetProp1_Private(ETbSame1Enum1 InProp1)
{
	Execute_SetProp1(this, InProp1);
};
