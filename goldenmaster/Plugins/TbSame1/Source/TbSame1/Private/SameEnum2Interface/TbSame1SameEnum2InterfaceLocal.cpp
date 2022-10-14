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

#include "TbSame1SameEnum2InterfaceLocal.h"
UTbSame1SameEnum2InterfaceLocalService::UTbSame1SameEnum2InterfaceLocalService()
	: ITbSame1SameEnum2InterfaceInterface()
	, Prop1(ETbSame1Enum1::VALUE1)
	, Prop2(ETbSame1Enum2::VALUE1)
{
}
UTbSame1SameEnum2InterfaceLocalService::~UTbSame1SameEnum2InterfaceLocalService()
{
}

FTbSame1SameEnum2InterfaceSig1Delegate& UTbSame1SameEnum2InterfaceLocalService::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

FTbSame1SameEnum2InterfaceSig2Delegate& UTbSame1SameEnum2InterfaceLocalService::GetSig2SignalDelegate()
{
	return Sig2Signal;
}

void UTbSame1SameEnum2InterfaceLocalService::GetProp1_Implementation(ETbSame1Enum1& ReturnValue) const
{
	ReturnValue = Prop1;
}

void UTbSame1SameEnum2InterfaceLocalService::SetProp1_Implementation(const ETbSame1Enum1& InProp1)
{
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		Prop1Changed.Broadcast(Prop1);
	}
}

FTbSame1SameEnum2InterfaceProp1ChangedDelegate& UTbSame1SameEnum2InterfaceLocalService::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}
void UTbSame1SameEnum2InterfaceLocalService::GetProp2_Implementation(ETbSame1Enum2& ReturnValue) const
{
	ReturnValue = Prop2;
}

void UTbSame1SameEnum2InterfaceLocalService::SetProp2_Implementation(const ETbSame1Enum2& InProp2)
{
	if (Prop2 != InProp2)
	{
		Prop2 = InProp2;
		Prop2Changed.Broadcast(Prop2);
	}
}

FTbSame1SameEnum2InterfaceProp2ChangedDelegate& UTbSame1SameEnum2InterfaceLocalService::GetProp2ChangedDelegate()
{
	return Prop2Changed;
}

void UTbSame1SameEnum2InterfaceLocalService::Func1_Implementation(ETbSame1Enum1& Result, const ETbSame1Enum1& Param1)
{
	(void)Param1;
	// do business logic here
	Result = ETbSame1Enum1::VALUE1;
}
void UTbSame1SameEnum2InterfaceLocalService::Func2_Implementation(ETbSame1Enum1& Result, const ETbSame1Enum1& Param1, const ETbSame1Enum2& Param2)
{
	(void)Param1;
	(void)Param2;
	// do business logic here
	Result = ETbSame1Enum1::VALUE1;
}
