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
#include "TbEnumEnumInterfaceInterface.h"

UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface")
FTbEnumEnumInterfaceSig0Delegate& UAbstractTbEnumEnumInterface::GetSig0SignalDelegate()
{
	return Sig0Signal;
};

UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface")
FTbEnumEnumInterfaceSig1Delegate& UAbstractTbEnumEnumInterface::GetSig1SignalDelegate()
{
	return Sig1Signal;
};

UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface")
FTbEnumEnumInterfaceSig2Delegate& UAbstractTbEnumEnumInterface::GetSig2SignalDelegate()
{
	return Sig2Signal;
};

UFUNCTION(Category = "ApiGear|TbEnum|EnumInterface")
FTbEnumEnumInterfaceSig3Delegate& UAbstractTbEnumEnumInterface::GetSig3SignalDelegate()
{
	return Sig3Signal;
};

FTbEnumEnumInterfaceProp0ChangedDelegate& UAbstractTbEnumEnumInterface::GetProp0ChangedDelegate()
{
	return Prop0Changed;
};

FTbEnumEnumInterfaceProp1ChangedDelegate& UAbstractTbEnumEnumInterface::GetProp1ChangedDelegate()
{
	return Prop1Changed;
};

FTbEnumEnumInterfaceProp2ChangedDelegate& UAbstractTbEnumEnumInterface::GetProp2ChangedDelegate()
{
	return Prop2Changed;
};

FTbEnumEnumInterfaceProp3ChangedDelegate& UAbstractTbEnumEnumInterface::GetProp3ChangedDelegate()
{
	return Prop3Changed;
};
void UAbstractTbEnumEnumInterface::BroadcastSig0_Implementation(ETbEnumEnum0 Param0)
{
	Sig0Signal.Broadcast(Param0);
};

void UAbstractTbEnumEnumInterface::BroadcastSig1_Implementation(ETbEnumEnum1 Param1)
{
	Sig1Signal.Broadcast(Param1);
};

void UAbstractTbEnumEnumInterface::BroadcastSig2_Implementation(ETbEnumEnum2 Param2)
{
	Sig2Signal.Broadcast(Param2);
};

void UAbstractTbEnumEnumInterface::BroadcastSig3_Implementation(ETbEnumEnum3 Param3)
{
	Sig3Signal.Broadcast(Param3);
};

void UAbstractTbEnumEnumInterface::BroadcastProp0Changed_Implementation(ETbEnumEnum0 InProp0)
{
	Prop0Changed.Broadcast(InProp0);
}

void UAbstractTbEnumEnumInterface::BroadcastProp1Changed_Implementation(ETbEnumEnum1 InProp1)
{
	Prop1Changed.Broadcast(InProp1);
}

void UAbstractTbEnumEnumInterface::BroadcastProp2Changed_Implementation(ETbEnumEnum2 InProp2)
{
	Prop2Changed.Broadcast(InProp2);
}

void UAbstractTbEnumEnumInterface::BroadcastProp3Changed_Implementation(ETbEnumEnum3 InProp3)
{
	Prop3Changed.Broadcast(InProp3);
}
ETbEnumEnum0 UAbstractTbEnumEnumInterface::GetProp0_Private() const
{
	return Execute_GetProp0(this);
};

void UAbstractTbEnumEnumInterface::SetProp0_Private(ETbEnumEnum0 InProp0)
{
	Execute_SetProp0(this, InProp0);
};

ETbEnumEnum1 UAbstractTbEnumEnumInterface::GetProp1_Private() const
{
	return Execute_GetProp1(this);
};

void UAbstractTbEnumEnumInterface::SetProp1_Private(ETbEnumEnum1 InProp1)
{
	Execute_SetProp1(this, InProp1);
};

ETbEnumEnum2 UAbstractTbEnumEnumInterface::GetProp2_Private() const
{
	return Execute_GetProp2(this);
};

void UAbstractTbEnumEnumInterface::SetProp2_Private(ETbEnumEnum2 InProp2)
{
	Execute_SetProp2(this, InProp2);
};

ETbEnumEnum3 UAbstractTbEnumEnumInterface::GetProp3_Private() const
{
	return Execute_GetProp3(this);
};

void UAbstractTbEnumEnumInterface::SetProp3_Private(ETbEnumEnum3 InProp3)
{
	Execute_SetProp3(this, InProp3);
};
