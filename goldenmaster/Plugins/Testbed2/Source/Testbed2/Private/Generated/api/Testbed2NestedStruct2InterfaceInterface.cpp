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
#include "Testbed2NestedStruct2InterfaceInterface.h"

UFUNCTION(Category = "ApiGear|Testbed2|NestedStruct2Interface")
FTestbed2NestedStruct2InterfaceSig1Delegate& UAbstractTestbed2NestedStruct2Interface::GetSig1SignalDelegate()
{
	return Sig1Signal;
};

UFUNCTION(Category = "ApiGear|Testbed2|NestedStruct2Interface")
FTestbed2NestedStruct2InterfaceSig2Delegate& UAbstractTestbed2NestedStruct2Interface::GetSig2SignalDelegate()
{
	return Sig2Signal;
};

FTestbed2NestedStruct2InterfaceProp1ChangedDelegate& UAbstractTestbed2NestedStruct2Interface::GetProp1ChangedDelegate()
{
	return Prop1Changed;
};

FTestbed2NestedStruct2InterfaceProp2ChangedDelegate& UAbstractTestbed2NestedStruct2Interface::GetProp2ChangedDelegate()
{
	return Prop2Changed;
};
void UAbstractTestbed2NestedStruct2Interface::BroadcastSig1_Implementation(const FTestbed2NestedStruct1& Param1)
{
	Sig1Signal.Broadcast(Param1);
};

void UAbstractTestbed2NestedStruct2Interface::BroadcastSig2_Implementation(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
	Sig2Signal.Broadcast(Param1, Param2);
};

void UAbstractTestbed2NestedStruct2Interface::BroadcastProp1Changed_Implementation(const FTestbed2NestedStruct1& InProp1)
{
	Prop1Changed.Broadcast(InProp1);
}

void UAbstractTestbed2NestedStruct2Interface::BroadcastProp2Changed_Implementation(const FTestbed2NestedStruct2& InProp2)
{
	Prop2Changed.Broadcast(InProp2);
}
FTestbed2NestedStruct1 UAbstractTestbed2NestedStruct2Interface::GetProp1_Private() const
{
	return Execute_GetProp1(this);
};

void UAbstractTestbed2NestedStruct2Interface::SetProp1_Private(const FTestbed2NestedStruct1& InProp1)
{
	Execute_SetProp1(this, InProp1);
};

FTestbed2NestedStruct2 UAbstractTestbed2NestedStruct2Interface::GetProp2_Private() const
{
	return Execute_GetProp2(this);
};

void UAbstractTestbed2NestedStruct2Interface::SetProp2_Private(const FTestbed2NestedStruct2& InProp2)
{
	Execute_SetProp2(this, InProp2);
};
