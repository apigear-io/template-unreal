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

#include "TbSame2SameStruct1InterfaceLocal.h"

namespace TbSame2
{
namespace SameStruct1Interface
{
namespace Private
{
LocalService::LocalService()
	: ITbSame2SameStruct1InterfaceInterface()
	, Prop1(FTbSame2Struct1())
{
}
LocalService::~LocalService()
{
}

FTbSame2SameStruct1InterfaceSig1Delegate& LocalService::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

FTbSame2Struct1 LocalService::GetProp1_Implementation() const
{
	return Prop1;
}

void LocalService::SetProp1_Implementation(const FTbSame2Struct1& InProp1)
{
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		Prop1Changed.Broadcast(Prop1);
	}
}

FTbSame2SameStruct1InterfaceProp1ChangedDelegate& LocalService::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}

FTbSame2Struct1 LocalService::Func1_Implementation(const FTbSame2Struct1& Param1)
{
	(void)Param1;
	// do business logic here
	return FTbSame2Struct1();
}

} // namespace Private
} // namespace SameStruct1Interface
} // namespace TbSame2
