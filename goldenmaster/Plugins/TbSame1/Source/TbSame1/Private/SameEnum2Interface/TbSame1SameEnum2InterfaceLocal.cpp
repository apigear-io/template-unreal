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

namespace TbSame1 {
namespace SameEnum2Interface {
namespace Private {
LocalService::LocalService()
    : ITbSame1SameEnum2InterfaceInterface()
    , Prop1(ETbSame1Enum1::VALUE1)
    , Prop2(ETbSame1Enum2::VALUE1)
{
}
LocalService::~LocalService()
{
}

FTbSame1SameEnum2InterfaceSig1Delegate& LocalService::GetSig1SignalDelegate()
{
    return Sig1Signal;
}

FTbSame1SameEnum2InterfaceSig2Delegate& LocalService::GetSig2SignalDelegate()
{
    return Sig2Signal;
}

ETbSame1Enum1 LocalService::GetProp1() const
{
    return Prop1;
}

void LocalService::SetProp1(const ETbSame1Enum1& InProp1)
{
    if(Prop1 != InProp1)
    {
        Prop1 = InProp1;
        Prop1Changed.Broadcast(Prop1);
    }
}

FTbSame1SameEnum2InterfaceProp1ChangedDelegate& LocalService::GetProp1ChangedDelegate()
{
    return Prop1Changed;
}
ETbSame1Enum2 LocalService::GetProp2() const
{
    return Prop2;
}

void LocalService::SetProp2(const ETbSame1Enum2& InProp2)
{
    if(Prop2 != InProp2)
    {
        Prop2 = InProp2;
        Prop2Changed.Broadcast(Prop2);
    }
}

FTbSame1SameEnum2InterfaceProp2ChangedDelegate& LocalService::GetProp2ChangedDelegate()
{
    return Prop2Changed;
}

ETbSame1Enum1 LocalService::Func1(const ETbSame1Enum1& Param1)
{
    (void) Param1;
    // do business logic here
    return ETbSame1Enum1::VALUE1;
}
ETbSame1Enum1 LocalService::Func2(const ETbSame1Enum1& Param1, const ETbSame1Enum2& Param2)
{
    (void) Param1;
    (void) Param2;
    // do business logic here
    return ETbSame1Enum1::VALUE1;
}

} // namespace Private
} // namespace SameEnum2Interface
} // namespace TbSame1
