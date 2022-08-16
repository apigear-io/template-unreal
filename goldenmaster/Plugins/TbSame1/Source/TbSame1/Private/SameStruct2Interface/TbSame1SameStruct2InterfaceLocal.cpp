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

#include "TbSame1SameStruct2InterfaceLocal.h"

namespace TbSame1
{
namespace SameStruct2Interface
{
namespace Private
{
LocalService::LocalService()
	: ITbSame1SameStruct2InterfaceInterface()
	, Prop1(FTbSame1Struct2())
	, Prop2(FTbSame1Struct2())
{
}
LocalService::~LocalService()
{
}

FTbSame1SameStruct2InterfaceSig1Delegate& LocalService::GetSig1SignalDelegate()
{
	return Sig1Signal;
}

FTbSame1SameStruct2InterfaceSig2Delegate& LocalService::GetSig2SignalDelegate()
{
	return Sig2Signal;
}

FTbSame1Struct2 LocalService::GetProp1() const
{
	return Prop1;
}

void LocalService::SetProp1(const FTbSame1Struct2& InProp1)
{
	if (Prop1 != InProp1)
	{
		Prop1 = InProp1;
		Prop1Changed.Broadcast(Prop1);
	}
}

FTbSame1SameStruct2InterfaceProp1ChangedDelegate& LocalService::GetProp1ChangedDelegate()
{
	return Prop1Changed;
}
FTbSame1Struct2 LocalService::GetProp2() const
{
	return Prop2;
}

void LocalService::SetProp2(const FTbSame1Struct2& InProp2)
{
	if (Prop2 != InProp2)
	{
		Prop2 = InProp2;
		Prop2Changed.Broadcast(Prop2);
	}
}

FTbSame1SameStruct2InterfaceProp2ChangedDelegate& LocalService::GetProp2ChangedDelegate()
{
	return Prop2Changed;
}

FTbSame1Struct1 LocalService::Func1(const FTbSame1Struct1& Param1)
{
	(void)Param1;
	// do business logic here
	return FTbSame1Struct1();
}
FTbSame1Struct1 LocalService::Func2(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2)
{
	(void)Param1;
	(void)Param2;
	// do business logic here
	return FTbSame1Struct1();
}

} // namespace Private
} // namespace SameStruct2Interface
} // namespace TbSame1
