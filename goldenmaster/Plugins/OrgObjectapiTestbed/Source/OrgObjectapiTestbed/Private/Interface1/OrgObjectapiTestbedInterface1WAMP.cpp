
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

#include "OrgObjectapiTestbedInterface1WAMP.h"
#include "apig/OrgObjectapiTestbed.json.adapter.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "unrealwamp.h"

using namespace ApiGear::WAMP;
OrgObjectapiTestbedInterface1WAMPService::OrgObjectapiTestbedInterface1WAMPService()
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
    EventFunc Interface1StateChangedFunc = [this](EventArg arg)
    {
        const json fields = arg.kwargs;
        if(fields.contains("prop1")) {
            if(bProp1 != fields["prop1"].get<bool>())
            {
                bProp1 = fields["prop1"].get<bool>();
                OrgObjectapiTestbedInterface1Prop1Changed.Broadcast(bProp1);
            }
        }
        if(fields.contains("prop2")) {
            if(Prop2 != fields["prop2"].get<int32>())
            {
                Prop2 = fields["prop2"].get<int32>();
                OrgObjectapiTestbedInterface1Prop2Changed.Broadcast(Prop2);
            }
        }
        if(fields.contains("prop3")) {
            if(Prop3 != fields["prop3"].get<float>())
            {
                Prop3 = fields["prop3"].get<float>();
                OrgObjectapiTestbedInterface1Prop3Changed.Broadcast(Prop3);
            }
        }
        if(fields.contains("prop4")) {
            if(Prop4 != fields["prop4"].get<FString>())
            {
                Prop4 = fields["prop4"].get<FString>();
                OrgObjectapiTestbedInterface1Prop4Changed.Broadcast(Prop4);
            }
        }
        if(fields.contains("prop5")) {
            if(Prop5 != fields["prop5"].get<TArray<int32>>())
            {
                Prop5 = fields["prop5"].get<TArray<int32>>();
                OrgObjectapiTestbedInterface1Prop5Changed.Broadcast(Prop5);
            }
        }
        if(fields.contains("prop6")) {
            if(Prop6 != fields["prop6"].get<FOrgObjectapiTestbedStruct1>())
            {
                Prop6 = fields["prop6"].get<FOrgObjectapiTestbedStruct1>();
                OrgObjectapiTestbedInterface1Prop6Changed.Broadcast(Prop6);
            }
        }
        if(fields.contains("prop7")) {
            if(Prop7 != fields["prop7"].get<int32>())
            {
                Prop7 = fields["prop7"].get<int32>();
                OrgObjectapiTestbedInterface1Prop7Changed.Broadcast(Prop7);
            }
        }
        if(fields.contains("prop10")) {
            if(Prop10 != fields["prop10"].get<TArray<int32>>())
            {
                Prop10 = fields["prop10"].get<TArray<int32>>();
                OrgObjectapiTestbedInterface1Prop10Changed.Broadcast(Prop10);
            }
        }
        if(fields.contains("prop11")) {
            if(Prop11 != fields["prop11"].get<TArray<FOrgObjectapiTestbedStruct1>>())
            {
                Prop11 = fields["prop11"].get<TArray<FOrgObjectapiTestbedStruct1>>();
                OrgObjectapiTestbedInterface1Prop11Changed.Broadcast(Prop11);
            }
        }
        if(fields.contains("prop12")) {
            if(Prop12 != fields["prop12"].get<TArray<EOrgObjectapiTestbedEnum1>>())
            {
                Prop12 = fields["prop12"].get<TArray<EOrgObjectapiTestbedEnum1>>();
                OrgObjectapiTestbedInterface1Prop12Changed.Broadcast(Prop12);
            }
        }
        if(fields.contains("prop14")) {
            if(Prop14 != fields["prop14"].get<TArray<FOrgObjectapiTestbedStruct1>>())
            {
                Prop14 = fields["prop14"].get<TArray<FOrgObjectapiTestbedStruct1>>();
                OrgObjectapiTestbedInterface1Prop14Changed.Broadcast(Prop14);
            }
        }
    };
    UnrealWamp::instance()->doSubscribe("org.objectapi.testbed.Interface1", Interface1StateChangedFunc);

    ResponseFunc GetInterface1StateFunc = [this](ResponseArg arg)
    {
        if(arg.args.size() != 1) {
          return;
        }
        const json fields = arg.args[0];
        if(fields.contains("prop1")) {
            if(bProp1 != fields["prop1"].get<bool>())
            {
                bProp1 = fields["prop1"].get<bool>();
                OrgObjectapiTestbedInterface1Prop1Changed.Broadcast(bProp1);
            }
        }
        if(fields.contains("prop2")) {
            if(Prop2 != fields["prop2"].get<int32>())
            {
                Prop2 = fields["prop2"].get<int32>();
                OrgObjectapiTestbedInterface1Prop2Changed.Broadcast(Prop2);
            }
        }
        if(fields.contains("prop3")) {
            if(Prop3 != fields["prop3"].get<float>())
            {
                Prop3 = fields["prop3"].get<float>();
                OrgObjectapiTestbedInterface1Prop3Changed.Broadcast(Prop3);
            }
        }
        if(fields.contains("prop4")) {
            if(Prop4 != fields["prop4"].get<FString>())
            {
                Prop4 = fields["prop4"].get<FString>();
                OrgObjectapiTestbedInterface1Prop4Changed.Broadcast(Prop4);
            }
        }
        if(fields.contains("prop5")) {
            if(Prop5 != fields["prop5"].get<TArray<int32>>())
            {
                Prop5 = fields["prop5"].get<TArray<int32>>();
                OrgObjectapiTestbedInterface1Prop5Changed.Broadcast(Prop5);
            }
        }
        if(fields.contains("prop6")) {
            if(Prop6 != fields["prop6"].get<FOrgObjectapiTestbedStruct1>())
            {
                Prop6 = fields["prop6"].get<FOrgObjectapiTestbedStruct1>();
                OrgObjectapiTestbedInterface1Prop6Changed.Broadcast(Prop6);
            }
        }
        if(fields.contains("prop7")) {
            if(Prop7 != fields["prop7"].get<int32>())
            {
                Prop7 = fields["prop7"].get<int32>();
                OrgObjectapiTestbedInterface1Prop7Changed.Broadcast(Prop7);
            }
        }
        if(fields.contains("prop10")) {
            if(Prop10 != fields["prop10"].get<TArray<int32>>())
            {
                Prop10 = fields["prop10"].get<TArray<int32>>();
                OrgObjectapiTestbedInterface1Prop10Changed.Broadcast(Prop10);
            }
        }
        if(fields.contains("prop11")) {
            if(Prop11 != fields["prop11"].get<TArray<FOrgObjectapiTestbedStruct1>>())
            {
                Prop11 = fields["prop11"].get<TArray<FOrgObjectapiTestbedStruct1>>();
                OrgObjectapiTestbedInterface1Prop11Changed.Broadcast(Prop11);
            }
        }
        if(fields.contains("prop12")) {
            if(Prop12 != fields["prop12"].get<TArray<EOrgObjectapiTestbedEnum1>>())
            {
                Prop12 = fields["prop12"].get<TArray<EOrgObjectapiTestbedEnum1>>();
                OrgObjectapiTestbedInterface1Prop12Changed.Broadcast(Prop12);
            }
        }
        if(fields.contains("prop14")) {
            if(Prop14 != fields["prop14"].get<TArray<FOrgObjectapiTestbedStruct1>>())
            {
                Prop14 = fields["prop14"].get<TArray<FOrgObjectapiTestbedStruct1>>();
                OrgObjectapiTestbedInterface1Prop14Changed.Broadcast(Prop14);
            }
        }
    };
    UnrealWamp::instance()->doCall("org.objectapi.testbed.Interface1._get", Arguments(), ArgumentsKw(), GetInterface1StateFunc);

    EventFunc sig1Func = [this](EventArg arg)
    {
        OrgObjectapiTestbedInterface1Sig1Signal.Broadcast();
    };
    UnrealWamp::instance()->doSubscribe("org.objectapi.testbed.Interface1.sig1", sig1Func);
    
    EventFunc sig2Func = [this](EventArg arg)
    {
        if(arg.args.size() == 2)
        {
            OrgObjectapiTestbedInterface1Sig2Signal.Broadcast(arg.args[0].get<int32>(),arg.args[1].get<FString>());
        }
    };
    UnrealWamp::instance()->doSubscribe("org.objectapi.testbed.Interface1.sig2", sig2Func);
    
    EventFunc sig3Func = [this](EventArg arg)
    {
        if(arg.args.size() == 1)
        {
            OrgObjectapiTestbedInterface1Sig3Signal.Broadcast(arg.args[0].get<float>());
        }
    };
    UnrealWamp::instance()->doSubscribe("org.objectapi.testbed.Interface1.sig3", sig3Func);
    
}

OrgObjectapiTestbedInterface1WAMPService::~OrgObjectapiTestbedInterface1WAMPService()
{
    UnrealWamp::instance()->doUnSubscribe("org.objectapi.testbed.Interface1");
    UnrealWamp::instance()->doUnSubscribe("org.objectapi.testbed.Interface1.sig1");
    UnrealWamp::instance()->doUnSubscribe("org.objectapi.testbed.Interface1.sig2");
    UnrealWamp::instance()->doUnSubscribe("org.objectapi.testbed.Interface1.sig3");
}

FOrgObjectapiTestbedInterface1Sig1Delegate& OrgObjectapiTestbedInterface1WAMPService::GetOrgObjectapiTestbedInterface1Sig1SignalDelegate()
{
    return OrgObjectapiTestbedInterface1Sig1Signal;
}

FOrgObjectapiTestbedInterface1Sig2Delegate& OrgObjectapiTestbedInterface1WAMPService::GetOrgObjectapiTestbedInterface1Sig2SignalDelegate()
{
    return OrgObjectapiTestbedInterface1Sig2Signal;
}

FOrgObjectapiTestbedInterface1Sig3Delegate& OrgObjectapiTestbedInterface1WAMPService::GetOrgObjectapiTestbedInterface1Sig3SignalDelegate()
{
    return OrgObjectapiTestbedInterface1Sig3Signal;
}

bool OrgObjectapiTestbedInterface1WAMPService::GetProp1() const
{
    return bProp1;
}

void OrgObjectapiTestbedInterface1WAMPService::SetProp1(bool bInProp1)
{
    ArgumentsKw fields_;
    fields_["prop1"] = bInProp1;
    UnrealWamp::instance()->doCall("org.objectapi.testbed.Interface1._set", Arguments(), fields_);
}

FOrgObjectapiTestbedInterface1Prop1ChangedDelegate& OrgObjectapiTestbedInterface1WAMPService::GetOrgObjectapiTestbedInterface1Prop1ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop1Changed;
}

int32 OrgObjectapiTestbedInterface1WAMPService::GetProp2() const
{
    return Prop2;
}

void OrgObjectapiTestbedInterface1WAMPService::SetProp2(int32 InProp2)
{
    ArgumentsKw fields_;
    fields_["prop2"] = InProp2;
    UnrealWamp::instance()->doCall("org.objectapi.testbed.Interface1._set", Arguments(), fields_);
}

FOrgObjectapiTestbedInterface1Prop2ChangedDelegate& OrgObjectapiTestbedInterface1WAMPService::GetOrgObjectapiTestbedInterface1Prop2ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop2Changed;
}

float OrgObjectapiTestbedInterface1WAMPService::GetProp3() const
{
    return Prop3;
}

void OrgObjectapiTestbedInterface1WAMPService::SetProp3(float InProp3)
{
    ArgumentsKw fields_;
    fields_["prop3"] = InProp3;
    UnrealWamp::instance()->doCall("org.objectapi.testbed.Interface1._set", Arguments(), fields_);
}

FOrgObjectapiTestbedInterface1Prop3ChangedDelegate& OrgObjectapiTestbedInterface1WAMPService::GetOrgObjectapiTestbedInterface1Prop3ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop3Changed;
}

FString OrgObjectapiTestbedInterface1WAMPService::GetProp4() const
{
    return Prop4;
}

void OrgObjectapiTestbedInterface1WAMPService::SetProp4(const FString& InProp4)
{
    ArgumentsKw fields_;
    fields_["prop4"] = InProp4;
    UnrealWamp::instance()->doCall("org.objectapi.testbed.Interface1._set", Arguments(), fields_);
}

FOrgObjectapiTestbedInterface1Prop4ChangedDelegate& OrgObjectapiTestbedInterface1WAMPService::GetOrgObjectapiTestbedInterface1Prop4ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop4Changed;
}

TArray<int32> OrgObjectapiTestbedInterface1WAMPService::GetProp5() const
{
    return Prop5;
}

void OrgObjectapiTestbedInterface1WAMPService::SetProp5(const TArray<int32>& InProp5)
{
    ArgumentsKw fields_;
    fields_["prop5"] = InProp5;
    UnrealWamp::instance()->doCall("org.objectapi.testbed.Interface1._set", Arguments(), fields_);
}

FOrgObjectapiTestbedInterface1Prop5ChangedDelegate& OrgObjectapiTestbedInterface1WAMPService::GetOrgObjectapiTestbedInterface1Prop5ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop5Changed;
}

FOrgObjectapiTestbedStruct1 OrgObjectapiTestbedInterface1WAMPService::GetProp6() const
{
    return Prop6;
}

void OrgObjectapiTestbedInterface1WAMPService::SetProp6(const FOrgObjectapiTestbedStruct1& InProp6)
{
    ArgumentsKw fields_;
    fields_["prop6"] = InProp6;
    UnrealWamp::instance()->doCall("org.objectapi.testbed.Interface1._set", Arguments(), fields_);
}

FOrgObjectapiTestbedInterface1Prop6ChangedDelegate& OrgObjectapiTestbedInterface1WAMPService::GetOrgObjectapiTestbedInterface1Prop6ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop6Changed;
}

int32 OrgObjectapiTestbedInterface1WAMPService::GetProp7() const
{
    return Prop7;
}

void OrgObjectapiTestbedInterface1WAMPService::SetProp7(int32 InProp7)
{
    ArgumentsKw fields_;
    fields_["prop7"] = InProp7;
    UnrealWamp::instance()->doCall("org.objectapi.testbed.Interface1._set", Arguments(), fields_);
}

FOrgObjectapiTestbedInterface1Prop7ChangedDelegate& OrgObjectapiTestbedInterface1WAMPService::GetOrgObjectapiTestbedInterface1Prop7ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop7Changed;
}

TArray<int32> OrgObjectapiTestbedInterface1WAMPService::GetProp10() const
{
    return Prop10;
}

void OrgObjectapiTestbedInterface1WAMPService::SetProp10(const TArray<int32>& InProp10)
{
    ArgumentsKw fields_;
    fields_["prop10"] = InProp10;
    UnrealWamp::instance()->doCall("org.objectapi.testbed.Interface1._set", Arguments(), fields_);
}

FOrgObjectapiTestbedInterface1Prop10ChangedDelegate& OrgObjectapiTestbedInterface1WAMPService::GetOrgObjectapiTestbedInterface1Prop10ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop10Changed;
}

TArray<FOrgObjectapiTestbedStruct1> OrgObjectapiTestbedInterface1WAMPService::GetProp11() const
{
    return Prop11;
}

void OrgObjectapiTestbedInterface1WAMPService::SetProp11(const TArray<FOrgObjectapiTestbedStruct1>& InProp11)
{
    ArgumentsKw fields_;
    fields_["prop11"] = InProp11;
    UnrealWamp::instance()->doCall("org.objectapi.testbed.Interface1._set", Arguments(), fields_);
}

FOrgObjectapiTestbedInterface1Prop11ChangedDelegate& OrgObjectapiTestbedInterface1WAMPService::GetOrgObjectapiTestbedInterface1Prop11ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop11Changed;
}

TArray<EOrgObjectapiTestbedEnum1> OrgObjectapiTestbedInterface1WAMPService::GetProp12() const
{
    return Prop12;
}

void OrgObjectapiTestbedInterface1WAMPService::SetProp12(const TArray<EOrgObjectapiTestbedEnum1>& InProp12)
{
    ArgumentsKw fields_;
    fields_["prop12"] = InProp12;
    UnrealWamp::instance()->doCall("org.objectapi.testbed.Interface1._set", Arguments(), fields_);
}

FOrgObjectapiTestbedInterface1Prop12ChangedDelegate& OrgObjectapiTestbedInterface1WAMPService::GetOrgObjectapiTestbedInterface1Prop12ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop12Changed;
}

TArray<FOrgObjectapiTestbedStruct1> OrgObjectapiTestbedInterface1WAMPService::GetProp14() const
{
    return Prop14;
}

void OrgObjectapiTestbedInterface1WAMPService::SetProp14(const TArray<FOrgObjectapiTestbedStruct1>& InProp14)
{
    ArgumentsKw fields_;
    fields_["prop14"] = InProp14;
    UnrealWamp::instance()->doCall("org.objectapi.testbed.Interface1._set", Arguments(), fields_);
}

FOrgObjectapiTestbedInterface1Prop14ChangedDelegate& OrgObjectapiTestbedInterface1WAMPService::GetOrgObjectapiTestbedInterface1Prop14ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop14Changed;
}


void OrgObjectapiTestbedInterface1WAMPService::Op1()
{
    UnrealWamp::instance()->doCall("org.objectapi.testbed.Interface1.op1", {}, ArgumentsKw());
}

void OrgObjectapiTestbedInterface1WAMPService::Op2(int32 Step)
{
    UnrealWamp::instance()->doCall("org.objectapi.testbed.Interface1.op2", {Step}, ArgumentsKw());
}

int32 OrgObjectapiTestbedInterface1WAMPService::Op3()
{
    TPromise<int32> Promise;
    Async(EAsyncExecution::Thread, [&Promise]()
    {
        ResponseFunc GetInterface1StateFunc = [&Promise](ResponseArg arg)
        {
            if(arg.args.size() != 1) {
              return;
            }
            Promise.SetValue(arg.args[0].get<int32>());
        };
        UnrealWamp::instance()->doCall("org.objectapi.testbed.Interface1.op3", {}, ArgumentsKw(), GetInterface1StateFunc);
    });

    return Promise.GetFuture().Get();
}

