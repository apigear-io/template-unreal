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

#include "TbSame2SameEnum1InterfaceLocal.h"
UTbSame2SameEnum1InterfaceLocalService::UTbSame2SameEnum1InterfaceLocalService()
	: ITbSame2SameEnum1InterfaceInterface()
	, Prop1(ETbSame2Enum1::VALUE1)
{
}
UTbSame2SameEnum1InterfaceLocalService::~UTbSame2SameEnum1InterfaceLocalService()
{
}

void UTbSame2SameEnum1InterfaceLocalService::BroadcastSig1_Implementation(const ETbSame2Enum1& Param1)
{
	Sig1Signal.Broadcast(Param1);
}

FTbSame2SameEnum1InterfaceSig1Delegate& UTbSame2SameEnum1InterfaceLocalService::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

void UTbSame2SameEnum1InterfaceLocalService::BroadcastProp1Changed_Implementation(const ETbSame2Enum1& InProp1)
{
	Prop1Changed.Broadcast(InProp1);
}

ETbSame2Enum1 UTbSame2SameEnum1InterfaceLocalService::GetProp1_Implementation() const
{
	return Prop1;
}

void UTbSame2SameEnum1InterfaceLocalService::SetProp1_Implementation(const ETbSame2Enum1& InProp1)
{
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		Execute_BroadcastProp1Changed(this, Prop1);
	}
}

FTbSame2SameEnum1InterfaceProp1ChangedDelegate& UTbSame2SameEnum1InterfaceLocalService::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}

ETbSame2Enum1 UTbSame2SameEnum1InterfaceLocalService::Func1_Implementation(const ETbSame2Enum1& Param1)
{
	(void)Param1;
	// do business logic here
	return ETbSame2Enum1::VALUE1;
}
