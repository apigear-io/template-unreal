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

#include "TbSame1SameEnum1InterfaceLocal.h"
UTbSame1SameEnum1InterfaceLocalService::UTbSame1SameEnum1InterfaceLocalService()
	: ITbSame1SameEnum1InterfaceInterface()
	, Prop1(ETbSame1Enum1::VALUE1)
{
}
UTbSame1SameEnum1InterfaceLocalService::~UTbSame1SameEnum1InterfaceLocalService()
{
}

FTbSame1SameEnum1InterfaceSig1Delegate& UTbSame1SameEnum1InterfaceLocalService::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

ETbSame1Enum1 UTbSame1SameEnum1InterfaceLocalService::GetProp1_Implementation() const
{
	return Prop1;
}

void UTbSame1SameEnum1InterfaceLocalService::SetProp1_Implementation(const ETbSame1Enum1& InProp1)
{
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		Prop1Changed.Broadcast(Prop1);
	}
}

FTbSame1SameEnum1InterfaceProp1ChangedDelegate& UTbSame1SameEnum1InterfaceLocalService::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}

ETbSame1Enum1 UTbSame1SameEnum1InterfaceLocalService::Func1_Implementation(const ETbSame1Enum1& Param1)
{
	(void)Param1;
	// do business logic here
	return ETbSame1Enum1::VALUE1;
}
