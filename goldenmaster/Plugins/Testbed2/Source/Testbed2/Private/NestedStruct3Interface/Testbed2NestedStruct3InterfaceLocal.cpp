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

#include "Testbed2NestedStruct3InterfaceLocal.h"

namespace Testbed2 {
namespace NestedStruct3Interface {
namespace Private {
LocalService::LocalService()
    : ITestbed2NestedStruct3InterfaceInterface()
    , Prop1(FTestbed2NestedStruct1())
    , Prop2(FTestbed2NestedStruct2())
    , Prop3(FTestbed2NestedStruct3())
{
}
LocalService::~LocalService()
{
}

FTestbed2NestedStruct3InterfaceSig1Delegate& LocalService::GetSig1SignalDelegate()
{
    return Sig1Signal;
}

FTestbed2NestedStruct3InterfaceSig2Delegate& LocalService::GetSig2SignalDelegate()
{
    return Sig2Signal;
}

FTestbed2NestedStruct3InterfaceSig3Delegate& LocalService::GetSig3SignalDelegate()
{
    return Sig3Signal;
}

FTestbed2NestedStruct1 LocalService::GetProp1() const
{
    return Prop1;
}

void LocalService::SetProp1(const FTestbed2NestedStruct1& InProp1)
{
    if(Prop1 != InProp1)
    {
        Prop1 = InProp1;
        Prop1Changed.Broadcast(Prop1);
    }
}

FTestbed2NestedStruct3InterfaceProp1ChangedDelegate& LocalService::GetProp1ChangedDelegate()
{
    return Prop1Changed;
}
FTestbed2NestedStruct2 LocalService::GetProp2() const
{
    return Prop2;
}

void LocalService::SetProp2(const FTestbed2NestedStruct2& InProp2)
{
    if(Prop2 != InProp2)
    {
        Prop2 = InProp2;
        Prop2Changed.Broadcast(Prop2);
    }
}

FTestbed2NestedStruct3InterfaceProp2ChangedDelegate& LocalService::GetProp2ChangedDelegate()
{
    return Prop2Changed;
}
FTestbed2NestedStruct3 LocalService::GetProp3() const
{
    return Prop3;
}

void LocalService::SetProp3(const FTestbed2NestedStruct3& InProp3)
{
    if(Prop3 != InProp3)
    {
        Prop3 = InProp3;
        Prop3Changed.Broadcast(Prop3);
    }
}

FTestbed2NestedStruct3InterfaceProp3ChangedDelegate& LocalService::GetProp3ChangedDelegate()
{
    return Prop3Changed;
}

FTestbed2NestedStruct1 LocalService::Func1(const FTestbed2NestedStruct1& Param1)
{
    (void) Param1;
    // do business logic here
    return FTestbed2NestedStruct1();
}
FTestbed2NestedStruct1 LocalService::Func2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2)
{
    (void) Param1;
    (void) Param2;
    // do business logic here
    return FTestbed2NestedStruct1();
}
FTestbed2NestedStruct1 LocalService::Func3(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3)
{
    (void) Param1;
    (void) Param2;
    (void) Param3;
    // do business logic here
    return FTestbed2NestedStruct1();
}

} // namespace Private
} // namespace NestedStruct3Interface
} // namespace Testbed2
