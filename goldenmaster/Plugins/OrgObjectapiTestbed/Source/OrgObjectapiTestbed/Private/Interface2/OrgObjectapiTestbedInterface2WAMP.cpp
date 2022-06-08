
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

////////////////////////////////
// WARNING AUTOGENERATED
// DO NOT MODIFY
///////////////////////////////

#include "OrgObjectapiTestbedInterface2WAMP.h"
#include "apig/OrgObjectapiTestbed.json.adapter.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "unrealwamp.h"

using namespace ApiGear::WAMP;
OrgObjectapiTestbedInterface2WAMPService::OrgObjectapiTestbedInterface2WAMPService()
: IOrgObjectapiTestbedInterface2Interface()
, Prop200(0)
, Prop201(0)
, Prop202(0)
, Prop203(0.0f)
, Prop204(0.0f)
, Prop205(FString())
{
    EventFunc Interface2StateChangedFunc = [this](EventArg arg)
    {
        const json fields = arg.kwargs;
        if(fields.contains("prop200")) {
            if(Prop200 != fields["prop200"].get<int32>())
            {
                Prop200 = fields["prop200"].get<int32>();
                Prop200Changed.Broadcast(Prop200);
            }
        }
        if(fields.contains("prop201")) {
            if(Prop201 != fields["prop201"].get<int32>())
            {
                Prop201 = fields["prop201"].get<int32>();
                Prop201Changed.Broadcast(Prop201);
            }
        }
        if(fields.contains("prop202")) {
            if(Prop202 != fields["prop202"].get<int32>())
            {
                Prop202 = fields["prop202"].get<int32>();
                Prop202Changed.Broadcast(Prop202);
            }
        }
        if(fields.contains("prop203")) {
            if(Prop203 != fields["prop203"].get<float>())
            {
                Prop203 = fields["prop203"].get<float>();
                Prop203Changed.Broadcast(Prop203);
            }
        }
        if(fields.contains("prop204")) {
            if(Prop204 != fields["prop204"].get<float>())
            {
                Prop204 = fields["prop204"].get<float>();
                Prop204Changed.Broadcast(Prop204);
            }
        }
        if(fields.contains("prop205")) {
            if(Prop205 != fields["prop205"].get<FString>())
            {
                Prop205 = fields["prop205"].get<FString>();
                Prop205Changed.Broadcast(Prop205);
            }
        }
    };
    UnrealWamp::instance()->doSubscribe("org.objectapi.testbed.Interface2", Interface2StateChangedFunc);

    ResponseFunc GetInterface2StateFunc = [this](ResponseArg arg)
    {
        if(arg.args.size() != 1) {
          return;
        }
        const json fields = arg.args[0];
        if(fields.contains("prop200")) {
            if(Prop200 != fields["prop200"].get<int32>())
            {
                Prop200 = fields["prop200"].get<int32>();
                Prop200Changed.Broadcast(Prop200);
            }
        }
        if(fields.contains("prop201")) {
            if(Prop201 != fields["prop201"].get<int32>())
            {
                Prop201 = fields["prop201"].get<int32>();
                Prop201Changed.Broadcast(Prop201);
            }
        }
        if(fields.contains("prop202")) {
            if(Prop202 != fields["prop202"].get<int32>())
            {
                Prop202 = fields["prop202"].get<int32>();
                Prop202Changed.Broadcast(Prop202);
            }
        }
        if(fields.contains("prop203")) {
            if(Prop203 != fields["prop203"].get<float>())
            {
                Prop203 = fields["prop203"].get<float>();
                Prop203Changed.Broadcast(Prop203);
            }
        }
        if(fields.contains("prop204")) {
            if(Prop204 != fields["prop204"].get<float>())
            {
                Prop204 = fields["prop204"].get<float>();
                Prop204Changed.Broadcast(Prop204);
            }
        }
        if(fields.contains("prop205")) {
            if(Prop205 != fields["prop205"].get<FString>())
            {
                Prop205 = fields["prop205"].get<FString>();
                Prop205Changed.Broadcast(Prop205);
            }
        }
    };
    UnrealWamp::instance()->doCall("org.objectapi.testbed.Interface2._get", Arguments(), ArgumentsKw(), GetInterface2StateFunc);

}

OrgObjectapiTestbedInterface2WAMPService::~OrgObjectapiTestbedInterface2WAMPService()
{
    UnrealWamp::instance()->doUnSubscribe("org.objectapi.testbed.Interface2");
}

int32 OrgObjectapiTestbedInterface2WAMPService::GetProp200() const
{
    return Prop200;
}

void OrgObjectapiTestbedInterface2WAMPService::SetProp200(int32 InProp200)
{
    ArgumentsKw fields_;
    fields_["prop200"] = InProp200;
    UnrealWamp::instance()->doCall("org.objectapi.testbed.Interface2._set", Arguments(), fields_);
}

FOrgObjectapiTestbedInterface2Prop200ChangedDelegate& OrgObjectapiTestbedInterface2WAMPService::GetProp200ChangedDelegate()
{
    return Prop200Changed;
}

int32 OrgObjectapiTestbedInterface2WAMPService::GetProp201() const
{
    return Prop201;
}

void OrgObjectapiTestbedInterface2WAMPService::SetProp201(int32 InProp201)
{
    ArgumentsKw fields_;
    fields_["prop201"] = InProp201;
    UnrealWamp::instance()->doCall("org.objectapi.testbed.Interface2._set", Arguments(), fields_);
}

FOrgObjectapiTestbedInterface2Prop201ChangedDelegate& OrgObjectapiTestbedInterface2WAMPService::GetProp201ChangedDelegate()
{
    return Prop201Changed;
}

int32 OrgObjectapiTestbedInterface2WAMPService::GetProp202() const
{
    return Prop202;
}

void OrgObjectapiTestbedInterface2WAMPService::SetProp202(int32 InProp202)
{
    ArgumentsKw fields_;
    fields_["prop202"] = InProp202;
    UnrealWamp::instance()->doCall("org.objectapi.testbed.Interface2._set", Arguments(), fields_);
}

FOrgObjectapiTestbedInterface2Prop202ChangedDelegate& OrgObjectapiTestbedInterface2WAMPService::GetProp202ChangedDelegate()
{
    return Prop202Changed;
}

float OrgObjectapiTestbedInterface2WAMPService::GetProp203() const
{
    return Prop203;
}

void OrgObjectapiTestbedInterface2WAMPService::SetProp203(float InProp203)
{
    ArgumentsKw fields_;
    fields_["prop203"] = InProp203;
    UnrealWamp::instance()->doCall("org.objectapi.testbed.Interface2._set", Arguments(), fields_);
}

FOrgObjectapiTestbedInterface2Prop203ChangedDelegate& OrgObjectapiTestbedInterface2WAMPService::GetProp203ChangedDelegate()
{
    return Prop203Changed;
}

float OrgObjectapiTestbedInterface2WAMPService::GetProp204() const
{
    return Prop204;
}

void OrgObjectapiTestbedInterface2WAMPService::SetProp204(float InProp204)
{
    ArgumentsKw fields_;
    fields_["prop204"] = InProp204;
    UnrealWamp::instance()->doCall("org.objectapi.testbed.Interface2._set", Arguments(), fields_);
}

FOrgObjectapiTestbedInterface2Prop204ChangedDelegate& OrgObjectapiTestbedInterface2WAMPService::GetProp204ChangedDelegate()
{
    return Prop204Changed;
}

FString OrgObjectapiTestbedInterface2WAMPService::GetProp205() const
{
    return Prop205;
}

void OrgObjectapiTestbedInterface2WAMPService::SetProp205(const FString& InProp205)
{
    ArgumentsKw fields_;
    fields_["prop205"] = InProp205;
    UnrealWamp::instance()->doCall("org.objectapi.testbed.Interface2._set", Arguments(), fields_);
}

FOrgObjectapiTestbedInterface2Prop205ChangedDelegate& OrgObjectapiTestbedInterface2WAMPService::GetProp205ChangedDelegate()
{
    return Prop205Changed;
}


