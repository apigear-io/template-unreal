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

#include "OrgObjectapiTestbedInterface1Local.h"
OrgObjectapiTestbedInterface1LocalService::OrgObjectapiTestbedInterface1LocalService()
    : IOrgObjectapiTestbedInterface1Interface()
    , bProp1(false)
    , Prop2(0)
    , Prop3(0.0f)
    , Prop4(FString())
    , Prop5(TArray<int32>())
    , Prop6(FOrgObjectapiTestbedStruct1())
    , Prop7(0)
    , Prop10(TArray<int32>())
    , Prop11(TArray<FOrgObjectapiTestbedStruct1>())
    , Prop12(TArray<EOrgObjectapiTestbedEnum1>())
    , Prop14(TArray<FOrgObjectapiTestbedStruct1>())
{
}
OrgObjectapiTestbedInterface1LocalService::~OrgObjectapiTestbedInterface1LocalService()
{
}

FOrgObjectapiTestbedInterface1Sig1Delegate& OrgObjectapiTestbedInterface1LocalService::GetOrgObjectapiTestbedInterface1Sig1SignalDelegate()
{
    return OrgObjectapiTestbedInterface1Sig1Signal;
}

FOrgObjectapiTestbedInterface1Sig2Delegate& OrgObjectapiTestbedInterface1LocalService::GetOrgObjectapiTestbedInterface1Sig2SignalDelegate()
{
    return OrgObjectapiTestbedInterface1Sig2Signal;
}

FOrgObjectapiTestbedInterface1Sig3Delegate& OrgObjectapiTestbedInterface1LocalService::GetOrgObjectapiTestbedInterface1Sig3SignalDelegate()
{
    return OrgObjectapiTestbedInterface1Sig3Signal;
}

bool OrgObjectapiTestbedInterface1LocalService::GetProp1() const
{
    return bProp1;
}

void OrgObjectapiTestbedInterface1LocalService::SetProp1(bool bInProp1)
{
    if(bProp1 != bInProp1)
    {
        bProp1 = bInProp1;
        bOrgObjectapiTestbedInterface1Prop1Changed.Broadcast(bProp1);
    }
}

FbOrgObjectapiTestbedInterface1Prop1ChangedDelegate& OrgObjectapiTestbedInterface1LocalService::GetbOrgObjectapiTestbedInterface1Prop1ChangedDelegate()
{
    return bOrgObjectapiTestbedInterface1Prop1Changed;
}
int32 OrgObjectapiTestbedInterface1LocalService::GetProp2() const
{
    return Prop2;
}

void OrgObjectapiTestbedInterface1LocalService::SetProp2(int32 InProp2)
{
    if(Prop2 != InProp2)
    {
        Prop2 = InProp2;
        OrgObjectapiTestbedInterface1Prop2Changed.Broadcast(Prop2);
    }
}

FOrgObjectapiTestbedInterface1Prop2ChangedDelegate& OrgObjectapiTestbedInterface1LocalService::GetOrgObjectapiTestbedInterface1Prop2ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop2Changed;
}
float OrgObjectapiTestbedInterface1LocalService::GetProp3() const
{
    return Prop3;
}

void OrgObjectapiTestbedInterface1LocalService::SetProp3(float InProp3)
{
    if(Prop3 != InProp3)
    {
        Prop3 = InProp3;
        OrgObjectapiTestbedInterface1Prop3Changed.Broadcast(Prop3);
    }
}

FOrgObjectapiTestbedInterface1Prop3ChangedDelegate& OrgObjectapiTestbedInterface1LocalService::GetOrgObjectapiTestbedInterface1Prop3ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop3Changed;
}
FString OrgObjectapiTestbedInterface1LocalService::GetProp4() const
{
    return Prop4;
}

void OrgObjectapiTestbedInterface1LocalService::SetProp4(const FString& InProp4)
{
    if(Prop4 != InProp4)
    {
        Prop4 = InProp4;
        OrgObjectapiTestbedInterface1Prop4Changed.Broadcast(Prop4);
    }
}

FOrgObjectapiTestbedInterface1Prop4ChangedDelegate& OrgObjectapiTestbedInterface1LocalService::GetOrgObjectapiTestbedInterface1Prop4ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop4Changed;
}
TArray<int32> OrgObjectapiTestbedInterface1LocalService::GetProp5() const
{
    return Prop5;
}

void OrgObjectapiTestbedInterface1LocalService::SetProp5(const TArray<int32>& InProp5)
{
    if(Prop5 != InProp5)
    {
        Prop5 = InProp5;
        OrgObjectapiTestbedInterface1Prop5Changed.Broadcast(Prop5);
    }
}

FOrgObjectapiTestbedInterface1Prop5ChangedDelegate& OrgObjectapiTestbedInterface1LocalService::GetOrgObjectapiTestbedInterface1Prop5ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop5Changed;
}
FOrgObjectapiTestbedStruct1 OrgObjectapiTestbedInterface1LocalService::GetProp6() const
{
    return Prop6;
}

void OrgObjectapiTestbedInterface1LocalService::SetProp6(const FOrgObjectapiTestbedStruct1& InProp6)
{
    if(Prop6 != InProp6)
    {
        Prop6 = InProp6;
        OrgObjectapiTestbedInterface1Prop6Changed.Broadcast(Prop6);
    }
}

FOrgObjectapiTestbedInterface1Prop6ChangedDelegate& OrgObjectapiTestbedInterface1LocalService::GetOrgObjectapiTestbedInterface1Prop6ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop6Changed;
}
int32 OrgObjectapiTestbedInterface1LocalService::GetProp7() const
{
    return Prop7;
}

void OrgObjectapiTestbedInterface1LocalService::SetProp7(int32 InProp7)
{
    if(Prop7 != InProp7)
    {
        Prop7 = InProp7;
        OrgObjectapiTestbedInterface1Prop7Changed.Broadcast(Prop7);
    }
}

FOrgObjectapiTestbedInterface1Prop7ChangedDelegate& OrgObjectapiTestbedInterface1LocalService::GetOrgObjectapiTestbedInterface1Prop7ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop7Changed;
}
TArray<int32> OrgObjectapiTestbedInterface1LocalService::GetProp10() const
{
    return Prop10;
}

void OrgObjectapiTestbedInterface1LocalService::SetProp10(const TArray<int32>& InProp10)
{
    if(Prop10 != InProp10)
    {
        Prop10 = InProp10;
        OrgObjectapiTestbedInterface1Prop10Changed.Broadcast(Prop10);
    }
}

FOrgObjectapiTestbedInterface1Prop10ChangedDelegate& OrgObjectapiTestbedInterface1LocalService::GetOrgObjectapiTestbedInterface1Prop10ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop10Changed;
}
TArray<FOrgObjectapiTestbedStruct1> OrgObjectapiTestbedInterface1LocalService::GetProp11() const
{
    return Prop11;
}

void OrgObjectapiTestbedInterface1LocalService::SetProp11(const TArray<FOrgObjectapiTestbedStruct1>& InProp11)
{
    if(Prop11 != InProp11)
    {
        Prop11 = InProp11;
        OrgObjectapiTestbedInterface1Prop11Changed.Broadcast(Prop11);
    }
}

FOrgObjectapiTestbedInterface1Prop11ChangedDelegate& OrgObjectapiTestbedInterface1LocalService::GetOrgObjectapiTestbedInterface1Prop11ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop11Changed;
}
TArray<EOrgObjectapiTestbedEnum1> OrgObjectapiTestbedInterface1LocalService::GetProp12() const
{
    return Prop12;
}

void OrgObjectapiTestbedInterface1LocalService::SetProp12(const TArray<EOrgObjectapiTestbedEnum1>& InProp12)
{
    if(Prop12 != InProp12)
    {
        Prop12 = InProp12;
        OrgObjectapiTestbedInterface1Prop12Changed.Broadcast(Prop12);
    }
}

FOrgObjectapiTestbedInterface1Prop12ChangedDelegate& OrgObjectapiTestbedInterface1LocalService::GetOrgObjectapiTestbedInterface1Prop12ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop12Changed;
}
TArray<FOrgObjectapiTestbedStruct1> OrgObjectapiTestbedInterface1LocalService::GetProp14() const
{
    return Prop14;
}

void OrgObjectapiTestbedInterface1LocalService::SetProp14(const TArray<FOrgObjectapiTestbedStruct1>& InProp14)
{
    if(Prop14 != InProp14)
    {
        Prop14 = InProp14;
        OrgObjectapiTestbedInterface1Prop14Changed.Broadcast(Prop14);
    }
}

FOrgObjectapiTestbedInterface1Prop14ChangedDelegate& OrgObjectapiTestbedInterface1LocalService::GetOrgObjectapiTestbedInterface1Prop14ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop14Changed;
}

void OrgObjectapiTestbedInterface1LocalService::Op1()
{
    // do business logic here
}
void OrgObjectapiTestbedInterface1LocalService::Op2(int32 Step)
{
    (void) Step;
    // do business logic here
}
int32 OrgObjectapiTestbedInterface1LocalService::Op3()
{
    // do business logic here
    return 0;
}
