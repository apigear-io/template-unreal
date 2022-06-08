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

#include "OrgObjectapiTestbedInterface2Local.h"
OrgObjectapiTestbedInterface2LocalService::OrgObjectapiTestbedInterface2LocalService()
    : IOrgObjectapiTestbedInterface2Interface()
    , Prop200(0)
    , Prop201(0)
    , Prop202(0)
    , Prop203(0.0f)
    , Prop204(0.0f)
    , Prop205(FString())
{
}
OrgObjectapiTestbedInterface2LocalService::~OrgObjectapiTestbedInterface2LocalService()
{
}

int32 OrgObjectapiTestbedInterface2LocalService::GetProp200() const
{
    return Prop200;
}

void OrgObjectapiTestbedInterface2LocalService::SetProp200(int32 InProp200)
{
    if(Prop200 != InProp200)
    {
        Prop200 = InProp200;
        Prop200Changed.Broadcast(Prop200);
    }
}

FOrgObjectapiTestbedInterface2Prop200ChangedDelegate& OrgObjectapiTestbedInterface2LocalService::GetProp200ChangedDelegate()
{
    return Prop200Changed;
}
int32 OrgObjectapiTestbedInterface2LocalService::GetProp201() const
{
    return Prop201;
}

void OrgObjectapiTestbedInterface2LocalService::SetProp201(int32 InProp201)
{
    if(Prop201 != InProp201)
    {
        Prop201 = InProp201;
        Prop201Changed.Broadcast(Prop201);
    }
}

FOrgObjectapiTestbedInterface2Prop201ChangedDelegate& OrgObjectapiTestbedInterface2LocalService::GetProp201ChangedDelegate()
{
    return Prop201Changed;
}
int32 OrgObjectapiTestbedInterface2LocalService::GetProp202() const
{
    return Prop202;
}

void OrgObjectapiTestbedInterface2LocalService::SetProp202(int32 InProp202)
{
    if(Prop202 != InProp202)
    {
        Prop202 = InProp202;
        Prop202Changed.Broadcast(Prop202);
    }
}

FOrgObjectapiTestbedInterface2Prop202ChangedDelegate& OrgObjectapiTestbedInterface2LocalService::GetProp202ChangedDelegate()
{
    return Prop202Changed;
}
float OrgObjectapiTestbedInterface2LocalService::GetProp203() const
{
    return Prop203;
}

void OrgObjectapiTestbedInterface2LocalService::SetProp203(float InProp203)
{
    if(Prop203 != InProp203)
    {
        Prop203 = InProp203;
        Prop203Changed.Broadcast(Prop203);
    }
}

FOrgObjectapiTestbedInterface2Prop203ChangedDelegate& OrgObjectapiTestbedInterface2LocalService::GetProp203ChangedDelegate()
{
    return Prop203Changed;
}
float OrgObjectapiTestbedInterface2LocalService::GetProp204() const
{
    return Prop204;
}

void OrgObjectapiTestbedInterface2LocalService::SetProp204(float InProp204)
{
    if(Prop204 != InProp204)
    {
        Prop204 = InProp204;
        Prop204Changed.Broadcast(Prop204);
    }
}

FOrgObjectapiTestbedInterface2Prop204ChangedDelegate& OrgObjectapiTestbedInterface2LocalService::GetProp204ChangedDelegate()
{
    return Prop204Changed;
}
FString OrgObjectapiTestbedInterface2LocalService::GetProp205() const
{
    return Prop205;
}

void OrgObjectapiTestbedInterface2LocalService::SetProp205(const FString& InProp205)
{
    if(Prop205 != InProp205)
    {
        Prop205 = InProp205;
        Prop205Changed.Broadcast(Prop205);
    }
}

FOrgObjectapiTestbedInterface2Prop205ChangedDelegate& OrgObjectapiTestbedInterface2LocalService::GetProp205ChangedDelegate()
{
    return Prop205Changed;
}

