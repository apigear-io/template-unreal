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

#include "OrgObjectapiTestbedInterface2Simulation.h"
#include "apig/OrgObjectapiTestbed.json.adapter.h"
#include "unrealsimulation.h"

using namespace ApiGear::JSONRPC;
OrgObjectapiTestbedInterface2SimulationService::OrgObjectapiTestbedInterface2SimulationService()
    : AbstractOrgObjectapiTestbedInterface2Publisher()
    , Prop200(0)
    , Prop201(0)
    , Prop202(0)
    , Prop203(0.0f)
    , Prop204(0.0f)
    , Prop205(FString())
{
    NotifyRequestFunc Interface2StateChangedFunc = [this](NotifyRequestArg arg)
    {
        const json fields = arg.params;
        if(fields.contains("prop200")) {
            if(Prop200 != fields["prop200"].get<int32>())
            {
                Prop200 = fields["prop200"].get<int32>();
                PublishProp200Changed(Prop200);
            }
        }
        if(fields.contains("prop201")) {
            if(Prop201 != fields["prop201"].get<int32>())
            {
                Prop201 = fields["prop201"].get<int32>();
                PublishProp201Changed(Prop201);
            }
        }
        if(fields.contains("prop202")) {
            if(Prop202 != fields["prop202"].get<int32>())
            {
                Prop202 = fields["prop202"].get<int32>();
                PublishProp202Changed(Prop202);
            }
        }
        if(fields.contains("prop203")) {
            if(Prop203 != fields["prop203"].get<float>())
            {
                Prop203 = fields["prop203"].get<float>();
                PublishProp203Changed(Prop203);
            }
        }
        if(fields.contains("prop204")) {
            if(Prop204 != fields["prop204"].get<float>())
            {
                Prop204 = fields["prop204"].get<float>();
                PublishProp204Changed(Prop204);
            }
        }
        if(fields.contains("prop205")) {
            if(Prop205 != fields["prop205"].get<FString>())
            {
                Prop205 = fields["prop205"].get<FString>();
                PublishProp205Changed(Prop205);
            }
        }
    };
    UnrealSimulation::instance()->onNotifyState("org.objectapi.testbed/Interface2", Interface2StateChangedFunc);

    CallResponseFunc GetInterface2StateFunc = [this](CallResponseArg arg)
    {
        if(arg.result.size() != 1) {
          return;
        }
        const json fields = arg.result;
        if(fields.contains("prop200")) {
            if(Prop200 != fields["prop200"].get<int32>())
            {
                Prop200 = fields["prop200"].get<int32>();
                PublishProp200Changed(Prop200);
            }
        }
        if(fields.contains("prop201")) {
            if(Prop201 != fields["prop201"].get<int32>())
            {
                Prop201 = fields["prop201"].get<int32>();
                PublishProp201Changed(Prop201);
            }
        }
        if(fields.contains("prop202")) {
            if(Prop202 != fields["prop202"].get<int32>())
            {
                Prop202 = fields["prop202"].get<int32>();
                PublishProp202Changed(Prop202);
            }
        }
        if(fields.contains("prop203")) {
            if(Prop203 != fields["prop203"].get<float>())
            {
                Prop203 = fields["prop203"].get<float>();
                PublishProp203Changed(Prop203);
            }
        }
        if(fields.contains("prop204")) {
            if(Prop204 != fields["prop204"].get<float>())
            {
                Prop204 = fields["prop204"].get<float>();
                PublishProp204Changed(Prop204);
            }
        }
        if(fields.contains("prop205")) {
            if(Prop205 != fields["prop205"].get<FString>())
            {
                Prop205 = fields["prop205"].get<FString>();
                PublishProp205Changed(Prop205);
            }
        }
    };
    UnrealSimulation::instance()->doFetchState("org.objectapi.testbed/Interface2", GetInterface2StateFunc);

    // register notification callback functions, signal/event -> fcn
}

OrgObjectapiTestbedInterface2SimulationService::~OrgObjectapiTestbedInterface2SimulationService()
{
    UnrealSimulation::instance()->RemoveOnNotifyState("org.objectapi.testbed/Interface2");
    // unregister notification callback functions
}

int32 OrgObjectapiTestbedInterface2SimulationService::GetProp200() const
{
    return Prop200;
}

void OrgObjectapiTestbedInterface2SimulationService::SetProp200(int32 Value)
{
    Params params;
    params["prop200"] = Value;
    UnrealSimulation::instance()->doCall("org.objectapi.testbed/Interface2", "_set", params);
}
int32 OrgObjectapiTestbedInterface2SimulationService::GetProp201() const
{
    return Prop201;
}

void OrgObjectapiTestbedInterface2SimulationService::SetProp201(int32 Value)
{
    Params params;
    params["prop201"] = Value;
    UnrealSimulation::instance()->doCall("org.objectapi.testbed/Interface2", "_set", params);
}
int32 OrgObjectapiTestbedInterface2SimulationService::GetProp202() const
{
    return Prop202;
}

void OrgObjectapiTestbedInterface2SimulationService::SetProp202(int32 Value)
{
    Params params;
    params["prop202"] = Value;
    UnrealSimulation::instance()->doCall("org.objectapi.testbed/Interface2", "_set", params);
}
float OrgObjectapiTestbedInterface2SimulationService::GetProp203() const
{
    return Prop203;
}

void OrgObjectapiTestbedInterface2SimulationService::SetProp203(float Value)
{
    Params params;
    params["prop203"] = Value;
    UnrealSimulation::instance()->doCall("org.objectapi.testbed/Interface2", "_set", params);
}
float OrgObjectapiTestbedInterface2SimulationService::GetProp204() const
{
    return Prop204;
}

void OrgObjectapiTestbedInterface2SimulationService::SetProp204(float Value)
{
    Params params;
    params["prop204"] = Value;
    UnrealSimulation::instance()->doCall("org.objectapi.testbed/Interface2", "_set", params);
}
FString OrgObjectapiTestbedInterface2SimulationService::GetProp205() const
{
    return Prop205;
}

void OrgObjectapiTestbedInterface2SimulationService::SetProp205(FString Value)
{
    Params params;
    params["prop205"] = Value;
    UnrealSimulation::instance()->doCall("org.objectapi.testbed/Interface2", "_set", params);
}