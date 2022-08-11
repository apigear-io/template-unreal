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

#include "Testbed2ManyParamInterfaceLocal.h"

namespace Testbed2 {
namespace ManyParamInterface {
namespace Private {
LocalService::LocalService()
    : ITestbed2ManyParamInterfaceInterface()
    , Prop1(0)
    , Prop2(0)
    , Prop3(0)
    , Prop4(0)
{
}
LocalService::~LocalService()
{
}

FTestbed2ManyParamInterfaceSig1Delegate& LocalService::GetSig1SignalDelegate()
{
    return Sig1Signal;
}

FTestbed2ManyParamInterfaceSig2Delegate& LocalService::GetSig2SignalDelegate()
{
    return Sig2Signal;
}

FTestbed2ManyParamInterfaceSig3Delegate& LocalService::GetSig3SignalDelegate()
{
    return Sig3Signal;
}

FTestbed2ManyParamInterfaceSig4Delegate& LocalService::GetSig4SignalDelegate()
{
    return Sig4Signal;
}

int32 LocalService::GetProp1() const
{
    return Prop1;
}

void LocalService::SetProp1(int32 InProp1)
{
    if(Prop1 != InProp1)
    {
        Prop1 = InProp1;
        Prop1Changed.Broadcast(Prop1);
    }
}

FTestbed2ManyParamInterfaceProp1ChangedDelegate& LocalService::GetProp1ChangedDelegate()
{
    return Prop1Changed;
}
int32 LocalService::GetProp2() const
{
    return Prop2;
}

void LocalService::SetProp2(int32 InProp2)
{
    if(Prop2 != InProp2)
    {
        Prop2 = InProp2;
        Prop2Changed.Broadcast(Prop2);
    }
}

FTestbed2ManyParamInterfaceProp2ChangedDelegate& LocalService::GetProp2ChangedDelegate()
{
    return Prop2Changed;
}
int32 LocalService::GetProp3() const
{
    return Prop3;
}

void LocalService::SetProp3(int32 InProp3)
{
    if(Prop3 != InProp3)
    {
        Prop3 = InProp3;
        Prop3Changed.Broadcast(Prop3);
    }
}

FTestbed2ManyParamInterfaceProp3ChangedDelegate& LocalService::GetProp3ChangedDelegate()
{
    return Prop3Changed;
}
int32 LocalService::GetProp4() const
{
    return Prop4;
}

void LocalService::SetProp4(int32 InProp4)
{
    if(Prop4 != InProp4)
    {
        Prop4 = InProp4;
        Prop4Changed.Broadcast(Prop4);
    }
}

FTestbed2ManyParamInterfaceProp4ChangedDelegate& LocalService::GetProp4ChangedDelegate()
{
    return Prop4Changed;
}

int32 LocalService::Func1(int32 Param1)
{
    (void) Param1;
    // do business logic here
    return 0;
}
int32 LocalService::Func2(int32 Param1, int32 Param2)
{
    (void) Param1;
    (void) Param2;
    // do business logic here
    return 0;
}
int32 LocalService::Func3(int32 Param1, int32 Param2, int32 Param3)
{
    (void) Param1;
    (void) Param2;
    (void) Param3;
    // do business logic here
    return 0;
}
int32 LocalService::Func4(int32 Param1, int32 Param2, int32 Param3, int32 Param4)
{
    (void) Param1;
    (void) Param2;
    (void) Param3;
    (void) Param4;
    // do business logic here
    return 0;
}

} // namespace Private
} // namespace ManyParamInterface
} // namespace Testbed2
