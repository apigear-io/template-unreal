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

#include "TbSame1SameStruct1InterfaceLocal.h"
UTbSame1SameStruct1InterfaceLocalService::UTbSame1SameStruct1InterfaceLocalService()
	: ITbSame1SameStruct1InterfaceInterface()
	, Prop1(FTbSame1Struct1())
{
}
UTbSame1SameStruct1InterfaceLocalService::~UTbSame1SameStruct1InterfaceLocalService()
{
}

void UTbSame1SameStruct1InterfaceLocalService::BroadcastSig1_Implementation(const FTbSame1Struct1& Param1)
{
	Sig1Signal.Broadcast(Param1);
}

FTbSame1SameStruct1InterfaceSig1Delegate& UTbSame1SameStruct1InterfaceLocalService::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

void UTbSame1SameStruct1InterfaceLocalService::BroadcastProp1Changed_Implementation(const FTbSame1Struct1& InProp1)
{
	Prop1Changed.Broadcast(InProp1);
}

FTbSame1Struct1 UTbSame1SameStruct1InterfaceLocalService::GetProp1_Implementation() const
{
	return Prop1;
}

void UTbSame1SameStruct1InterfaceLocalService::SetProp1_Implementation(const FTbSame1Struct1& InProp1)
{
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		Execute_BroadcastProp1Changed(this, Prop1);
	}
}

FTbSame1SameStruct1InterfaceProp1ChangedDelegate& UTbSame1SameStruct1InterfaceLocalService::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}

FTbSame1Struct1 UTbSame1SameStruct1InterfaceLocalService::Func1_Implementation(const FTbSame1Struct1& Param1)
{
	(void)Param1;
	// do business logic here
	return FTbSame1Struct1();
}
