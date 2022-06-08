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

#include "OrgObjectapiTestbedInterface1Simulation.h"
#include "apig/OrgObjectapiTestbed.json.adapter.h"
#include "unrealsimulation.h"

using namespace ApiGear::JSONRPC;
OrgObjectapiTestbedInterface1SimulationService::OrgObjectapiTestbedInterface1SimulationService()
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
    NotifyRequestFunc Interface1StateChangedFunc = [this](NotifyRequestArg arg)
    {
        const json fields = arg.params;
        if(fields.contains("prop1")) {
            if(bProp1 != fields["prop1"].get<bool>())
            {
                bProp1 = fields["prop1"].get<bool>();
                bOrgObjectapiTestbedInterface1Prop1Changed.Broadcast(bProp1);
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
    UnrealSimulation::instance()->onNotifyState("org.objectapi.testbed/Interface1", Interface1StateChangedFunc);

    CallResponseFunc GetInterface1StateFunc = [this](CallResponseArg arg)
    {
        if(arg.result.size() != 1) {
          return;
        }
        const json fields = arg.result;
        if(fields.contains("prop1")) {
            if(bProp1 != fields["prop1"].get<bool>())
            {
                bProp1 = fields["prop1"].get<bool>();
                bOrgObjectapiTestbedInterface1Prop1Changed.Broadcast(bProp1);
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
    UnrealSimulation::instance()->doFetchState("org.objectapi.testbed/Interface1", GetInterface1StateFunc);

    // register notification callback functions, signal/event -> fcn
    NotifyRequestFunc sig1Func = [this](NotifyRequestArg arg)
    {
        OrgObjectapiTestbedInterface1Sig1Signal.Broadcast();
    };
    UnrealSimulation::instance()->onNotify("org.objectapi.testbed/Interface1#sig1", sig1Func);

    NotifyRequestFunc sig2Func = [this](NotifyRequestArg arg)
    {
        const json fields = arg.params;
        if(fields.contains("step") &&fields.contains("step2"))
        {
            OrgObjectapiTestbedInterface1Sig2Signal.Broadcast(fields["step"].get<int32>(),fields["step2"].get<FString>());
        }
    };
    UnrealSimulation::instance()->onNotify("org.objectapi.testbed/Interface1#sig2", sig2Func);

    NotifyRequestFunc sig3Func = [this](NotifyRequestArg arg)
    {
        const json fields = arg.params;
        if(fields.contains("step"))
        {
            OrgObjectapiTestbedInterface1Sig3Signal.Broadcast(fields["step"].get<float>());
        }
    };
    UnrealSimulation::instance()->onNotify("org.objectapi.testbed/Interface1#sig3", sig3Func);

}

OrgObjectapiTestbedInterface1SimulationService::~OrgObjectapiTestbedInterface1SimulationService()
{
    UnrealSimulation::instance()->RemoveOnNotifyState("org.objectapi.testbed/Interface1");
    // unregister notification callback functions
    UnrealSimulation::instance()->RemoveOnNotify("org.objectapi.testbed/Interface1#sig1");
    UnrealSimulation::instance()->RemoveOnNotify("org.objectapi.testbed/Interface1#sig2");
    UnrealSimulation::instance()->RemoveOnNotify("org.objectapi.testbed/Interface1#sig3");
}

FOrgObjectapiTestbedInterface1Sig1Delegate& OrgObjectapiTestbedInterface1SimulationService::GetOrgObjectapiTestbedInterface1Sig1SignalDelegate()
{
    return OrgObjectapiTestbedInterface1Sig1Signal;
}

FOrgObjectapiTestbedInterface1Sig2Delegate& OrgObjectapiTestbedInterface1SimulationService::GetOrgObjectapiTestbedInterface1Sig2SignalDelegate()
{
    return OrgObjectapiTestbedInterface1Sig2Signal;
}

FOrgObjectapiTestbedInterface1Sig3Delegate& OrgObjectapiTestbedInterface1SimulationService::GetOrgObjectapiTestbedInterface1Sig3SignalDelegate()
{
    return OrgObjectapiTestbedInterface1Sig3Signal;
}

bool OrgObjectapiTestbedInterface1SimulationService::GetProp1() const
{
    return bProp1;
}

void OrgObjectapiTestbedInterface1SimulationService::SetProp1(bool bInProp1)
{
    Params params;
    params["prop1"] = bInProp1;
    UnrealSimulation::instance()->doCall("org.objectapi.testbed/Interface1", "_set", params);
}

FbOrgObjectapiTestbedInterface1Prop1ChangedDelegate& OrgObjectapiTestbedInterface1SimulationService::GetbOrgObjectapiTestbedInterface1Prop1ChangedDelegate()
{
    return bOrgObjectapiTestbedInterface1Prop1Changed;
}

int32 OrgObjectapiTestbedInterface1SimulationService::GetProp2() const
{
    return Prop2;
}

void OrgObjectapiTestbedInterface1SimulationService::SetProp2(int32 InProp2)
{
    Params params;
    params["prop2"] = InProp2;
    UnrealSimulation::instance()->doCall("org.objectapi.testbed/Interface1", "_set", params);
}

FOrgObjectapiTestbedInterface1Prop2ChangedDelegate& OrgObjectapiTestbedInterface1SimulationService::GetOrgObjectapiTestbedInterface1Prop2ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop2Changed;
}

float OrgObjectapiTestbedInterface1SimulationService::GetProp3() const
{
    return Prop3;
}

void OrgObjectapiTestbedInterface1SimulationService::SetProp3(float InProp3)
{
    Params params;
    params["prop3"] = InProp3;
    UnrealSimulation::instance()->doCall("org.objectapi.testbed/Interface1", "_set", params);
}

FOrgObjectapiTestbedInterface1Prop3ChangedDelegate& OrgObjectapiTestbedInterface1SimulationService::GetOrgObjectapiTestbedInterface1Prop3ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop3Changed;
}

FString OrgObjectapiTestbedInterface1SimulationService::GetProp4() const
{
    return Prop4;
}

void OrgObjectapiTestbedInterface1SimulationService::SetProp4(const FString& InProp4)
{
    Params params;
    params["prop4"] = InProp4;
    UnrealSimulation::instance()->doCall("org.objectapi.testbed/Interface1", "_set", params);
}

FOrgObjectapiTestbedInterface1Prop4ChangedDelegate& OrgObjectapiTestbedInterface1SimulationService::GetOrgObjectapiTestbedInterface1Prop4ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop4Changed;
}

TArray<int32> OrgObjectapiTestbedInterface1SimulationService::GetProp5() const
{
    return Prop5;
}

void OrgObjectapiTestbedInterface1SimulationService::SetProp5(const TArray<int32>& InProp5)
{
    Params params;
    params["prop5"] = InProp5;
    UnrealSimulation::instance()->doCall("org.objectapi.testbed/Interface1", "_set", params);
}

FOrgObjectapiTestbedInterface1Prop5ChangedDelegate& OrgObjectapiTestbedInterface1SimulationService::GetOrgObjectapiTestbedInterface1Prop5ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop5Changed;
}

FOrgObjectapiTestbedStruct1 OrgObjectapiTestbedInterface1SimulationService::GetProp6() const
{
    return Prop6;
}

void OrgObjectapiTestbedInterface1SimulationService::SetProp6(const FOrgObjectapiTestbedStruct1& InProp6)
{
    Params params;
    params["prop6"] = InProp6;
    UnrealSimulation::instance()->doCall("org.objectapi.testbed/Interface1", "_set", params);
}

FOrgObjectapiTestbedInterface1Prop6ChangedDelegate& OrgObjectapiTestbedInterface1SimulationService::GetOrgObjectapiTestbedInterface1Prop6ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop6Changed;
}

int32 OrgObjectapiTestbedInterface1SimulationService::GetProp7() const
{
    return Prop7;
}

void OrgObjectapiTestbedInterface1SimulationService::SetProp7(int32 InProp7)
{
    Params params;
    params["prop7"] = InProp7;
    UnrealSimulation::instance()->doCall("org.objectapi.testbed/Interface1", "_set", params);
}

FOrgObjectapiTestbedInterface1Prop7ChangedDelegate& OrgObjectapiTestbedInterface1SimulationService::GetOrgObjectapiTestbedInterface1Prop7ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop7Changed;
}

TArray<int32> OrgObjectapiTestbedInterface1SimulationService::GetProp10() const
{
    return Prop10;
}

void OrgObjectapiTestbedInterface1SimulationService::SetProp10(const TArray<int32>& InProp10)
{
    Params params;
    params["prop10"] = InProp10;
    UnrealSimulation::instance()->doCall("org.objectapi.testbed/Interface1", "_set", params);
}

FOrgObjectapiTestbedInterface1Prop10ChangedDelegate& OrgObjectapiTestbedInterface1SimulationService::GetOrgObjectapiTestbedInterface1Prop10ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop10Changed;
}

TArray<FOrgObjectapiTestbedStruct1> OrgObjectapiTestbedInterface1SimulationService::GetProp11() const
{
    return Prop11;
}

void OrgObjectapiTestbedInterface1SimulationService::SetProp11(const TArray<FOrgObjectapiTestbedStruct1>& InProp11)
{
    Params params;
    params["prop11"] = InProp11;
    UnrealSimulation::instance()->doCall("org.objectapi.testbed/Interface1", "_set", params);
}

FOrgObjectapiTestbedInterface1Prop11ChangedDelegate& OrgObjectapiTestbedInterface1SimulationService::GetOrgObjectapiTestbedInterface1Prop11ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop11Changed;
}

TArray<EOrgObjectapiTestbedEnum1> OrgObjectapiTestbedInterface1SimulationService::GetProp12() const
{
    return Prop12;
}

void OrgObjectapiTestbedInterface1SimulationService::SetProp12(const TArray<EOrgObjectapiTestbedEnum1>& InProp12)
{
    Params params;
    params["prop12"] = InProp12;
    UnrealSimulation::instance()->doCall("org.objectapi.testbed/Interface1", "_set", params);
}

FOrgObjectapiTestbedInterface1Prop12ChangedDelegate& OrgObjectapiTestbedInterface1SimulationService::GetOrgObjectapiTestbedInterface1Prop12ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop12Changed;
}

TArray<FOrgObjectapiTestbedStruct1> OrgObjectapiTestbedInterface1SimulationService::GetProp14() const
{
    return Prop14;
}

void OrgObjectapiTestbedInterface1SimulationService::SetProp14(const TArray<FOrgObjectapiTestbedStruct1>& InProp14)
{
    Params params;
    params["prop14"] = InProp14;
    UnrealSimulation::instance()->doCall("org.objectapi.testbed/Interface1", "_set", params);
}

FOrgObjectapiTestbedInterface1Prop14ChangedDelegate& OrgObjectapiTestbedInterface1SimulationService::GetOrgObjectapiTestbedInterface1Prop14ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop14Changed;
}

void OrgObjectapiTestbedInterface1SimulationService::Op1()
{
    Params params;
    UnrealSimulation::instance()->doCall("org.objectapi.testbed/Interface1", "op1", params);
}

void OrgObjectapiTestbedInterface1SimulationService::Op2(int32 Step)
{
    Params params;
    params["step"] = Step;
    UnrealSimulation::instance()->doCall("org.objectapi.testbed/Interface1", "op2", params);
}

int32 OrgObjectapiTestbedInterface1SimulationService::Op3()
{
    Params params;
    TPromise<int32> Promise;
    Async(EAsyncExecution::Thread, [params, &Promise]()
    {
        CallResponseFunc GetInterface1StateFunc = [&Promise](CallResponseArg arg)
        {
            Promise.SetValue(arg.result.get<int32>());
        };
        UnrealSimulation::instance()->doCall("org.objectapi.testbed/Interface1", "op3", params, GetInterface1StateFunc);
    });

    return Promise.GetFuture().Get();
}

