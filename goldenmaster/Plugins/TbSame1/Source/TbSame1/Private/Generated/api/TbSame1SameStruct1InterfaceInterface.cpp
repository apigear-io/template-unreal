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
#pragma once
#include "TbSame1SameStruct1InterfaceInterface.h"

UFUNCTION(Category = "ApiGear|TbSame1|SameStruct1Interface")
FTbSame1SameStruct1InterfaceSig1Delegate& UAbstractTbSame1SameStruct1Interface::GetSig1SignalDelegate()
{
	return Sig1Signal;
};

FTbSame1SameStruct1InterfaceProp1ChangedDelegate& UAbstractTbSame1SameStruct1Interface::GetProp1ChangedDelegate()
{
	return Prop1Changed;
};
void UAbstractTbSame1SameStruct1Interface::BroadcastSig1_Implementation(const FTbSame1Struct1& Param1)
{
	Sig1Signal.Broadcast(Param1);
};

void UAbstractTbSame1SameStruct1Interface::BroadcastProp1Changed_Implementation(const FTbSame1Struct1& InProp1)
{
	Prop1Changed.Broadcast(InProp1);
}
FTbSame1Struct1 UAbstractTbSame1SameStruct1Interface::GetProp1_Private() const
{
	return Execute_GetProp1(this);
};

void UAbstractTbSame1SameStruct1Interface::SetProp1_Private(const FTbSame1Struct1& InProp1)
{
	Execute_SetProp1(this, InProp1);
};
