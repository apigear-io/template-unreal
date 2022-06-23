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

#include "OrgObjectapiTestbedInterface1OLink.h"
#include "Async/Future.h"
#include "Async/Async.h"
#include "apig/OrgObjectapiTestbed.json.adapter.h"
#include "unrealolink.h"
#include "ApiGear/Public/ApiGearConnectionManager.h"
#include "Misc/DateTime.h"


using namespace ApiGear::ObjectLink;

namespace OrgObjectapiTestbed {
namespace Interface1 {
namespace Private {
OLinkService::OLinkService()
    : IOrgObjectapiTestbedInterface1Interface()
    , m_node(nullptr)
    , m_isReady(false)
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
    if (GEngine != nullptr)
    {
        UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
        AGCM->GetOLinkConnection()->linkObjectSource(olinkObjectName());
    }
    m_node = ClientRegistry::get().addObjectSink(this);
}

OLinkService::~OLinkService()
{
    ClientRegistry::get().removeObjectSink(this);
    if (GEngine != nullptr)
    {
        UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
        AGCM->GetOLinkConnection()->unlinkObjectSource(olinkObjectName());
    }
    m_isReady = false;
    m_node = nullptr;
}

FOrgObjectapiTestbedInterface1Sig1Delegate& OLinkService::GetSig1SignalDelegate()
{
    return Sig1Signal;
}

FOrgObjectapiTestbedInterface1Sig2Delegate& OLinkService::GetSig2SignalDelegate()
{
    return Sig2Signal;
}

FOrgObjectapiTestbedInterface1Sig3Delegate& OLinkService::GetSig3SignalDelegate()
{
    return Sig3Signal;
}

bool OLinkService::GetProp1() const
{
    return bProp1;
}

void OLinkService::SetProp1(bool bInProp1)
{
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface1/prop1", bInProp1);
}

FOrgObjectapiTestbedInterface1Prop1ChangedDelegate& OLinkService::GetProp1ChangedDelegate()
{
    return Prop1Changed;
}
int32 OLinkService::GetProp2() const
{
    return Prop2;
}

void OLinkService::SetProp2(int32 InProp2)
{
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface1/prop2", InProp2);
}

FOrgObjectapiTestbedInterface1Prop2ChangedDelegate& OLinkService::GetProp2ChangedDelegate()
{
    return Prop2Changed;
}
float OLinkService::GetProp3() const
{
    return Prop3;
}

void OLinkService::SetProp3(float InProp3)
{
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface1/prop3", InProp3);
}

FOrgObjectapiTestbedInterface1Prop3ChangedDelegate& OLinkService::GetProp3ChangedDelegate()
{
    return Prop3Changed;
}
FString OLinkService::GetProp4() const
{
    return Prop4;
}

void OLinkService::SetProp4(const FString& InProp4)
{
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface1/prop4", InProp4);
}

FOrgObjectapiTestbedInterface1Prop4ChangedDelegate& OLinkService::GetProp4ChangedDelegate()
{
    return Prop4Changed;
}
TArray<int32> OLinkService::GetProp5() const
{
    return Prop5;
}

void OLinkService::SetProp5(const TArray<int32>& InProp5)
{
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface1/prop5", InProp5);
}

FOrgObjectapiTestbedInterface1Prop5ChangedDelegate& OLinkService::GetProp5ChangedDelegate()
{
    return Prop5Changed;
}
FOrgObjectapiTestbedStruct1 OLinkService::GetProp6() const
{
    return Prop6;
}

void OLinkService::SetProp6(const FOrgObjectapiTestbedStruct1& InProp6)
{
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface1/prop6", InProp6);
}

FOrgObjectapiTestbedInterface1Prop6ChangedDelegate& OLinkService::GetProp6ChangedDelegate()
{
    return Prop6Changed;
}
int32 OLinkService::GetProp7() const
{
    return Prop7;
}

void OLinkService::SetProp7(int32 InProp7)
{
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface1/prop7", InProp7);
}

FOrgObjectapiTestbedInterface1Prop7ChangedDelegate& OLinkService::GetProp7ChangedDelegate()
{
    return Prop7Changed;
}
TArray<int32> OLinkService::GetProp10() const
{
    return Prop10;
}

void OLinkService::SetProp10(const TArray<int32>& InProp10)
{
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface1/prop10", InProp10);
}

FOrgObjectapiTestbedInterface1Prop10ChangedDelegate& OLinkService::GetProp10ChangedDelegate()
{
    return Prop10Changed;
}
TArray<FOrgObjectapiTestbedStruct1> OLinkService::GetProp11() const
{
    return Prop11;
}

void OLinkService::SetProp11(const TArray<FOrgObjectapiTestbedStruct1>& InProp11)
{
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface1/prop11", InProp11);
}

FOrgObjectapiTestbedInterface1Prop11ChangedDelegate& OLinkService::GetProp11ChangedDelegate()
{
    return Prop11Changed;
}
TArray<EOrgObjectapiTestbedEnum1> OLinkService::GetProp12() const
{
    return Prop12;
}

void OLinkService::SetProp12(const TArray<EOrgObjectapiTestbedEnum1>& InProp12)
{
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface1/prop12", InProp12);
}

FOrgObjectapiTestbedInterface1Prop12ChangedDelegate& OLinkService::GetProp12ChangedDelegate()
{
    return Prop12Changed;
}
TArray<FOrgObjectapiTestbedStruct1> OLinkService::GetProp14() const
{
    return Prop14;
}

void OLinkService::SetProp14(const TArray<FOrgObjectapiTestbedStruct1>& InProp14)
{
    if(!m_node) {
        return;
    }
    m_node->setRemoteProperty("org.objectapi.testbed.Interface1/prop14", InProp14);
}

FOrgObjectapiTestbedInterface1Prop14ChangedDelegate& OLinkService::GetProp14ChangedDelegate()
{
    return Prop14Changed;
}

void OLinkService::Op1()
{
    if(!m_node) {
        UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
        return;
    }
    InvokeReplyFunc func = [this](InvokeReplyArg arg) {};
    m_node->invokeRemote("org_objectapi_testbed.Interface1/op1", {}, func);
}

void OLinkService::Op2(int32 Step)
{
    if(!m_node) {
        UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
        return;
    }
    InvokeReplyFunc func = [this](InvokeReplyArg arg) {};
    m_node->invokeRemote("org_objectapi_testbed.Interface1/op2", {Step}, func);
}

int32 OLinkService::Op3()
{
    if(!m_node) {
        UE_LOG(LogTemp, Warning, TEXT("%s has no node"), UTF8_TO_TCHAR(olinkObjectName().c_str()));
        return 0;
    }
    TPromise<int32> Promise;
    Async(EAsyncExecution::Thread, [&Promise, this]()
    {
        InvokeReplyFunc GetInterface1StateFunc = [&Promise](InvokeReplyArg arg)
        {
            Promise.SetValue(arg.value.get<int32>());
        };
        m_node->invokeRemote("org.objectapi.testbed.Interface1/op3", {}, GetInterface1StateFunc);
    });

    return Promise.GetFuture().Get();
}


void OLinkService::applyState(const nlohmann::json& fields) 
{
    if(fields.contains("prop1")) {
        if(bProp1 != fields["prop1"].get<bool>())
        {
            bProp1 = fields["prop1"].get<bool>();
            Prop1Changed.Broadcast(bProp1);
        }
    }
    if(fields.contains("prop2")) {
        if(Prop2 != fields["prop2"].get<int32>())
        {
            Prop2 = fields["prop2"].get<int32>();
            Prop2Changed.Broadcast(Prop2);
        }
    }
    if(fields.contains("prop3")) {
        if(Prop3 != fields["prop3"].get<float>())
        {
            Prop3 = fields["prop3"].get<float>();
            Prop3Changed.Broadcast(Prop3);
        }
    }
    if(fields.contains("prop4")) {
        if(Prop4 != fields["prop4"].get<FString>())
        {
            Prop4 = fields["prop4"].get<FString>();
            Prop4Changed.Broadcast(Prop4);
        }
    }
    if(fields.contains("prop5")) {
        if(Prop5 != fields["prop5"].get<TArray<int32>>())
        {
            Prop5 = fields["prop5"].get<TArray<int32>>();
            Prop5Changed.Broadcast(Prop5);
        }
    }
    if(fields.contains("prop6")) {
        if(Prop6 != fields["prop6"].get<FOrgObjectapiTestbedStruct1>())
        {
            Prop6 = fields["prop6"].get<FOrgObjectapiTestbedStruct1>();
            Prop6Changed.Broadcast(Prop6);
        }
    }
    if(fields.contains("prop7")) {
        if(Prop7 != fields["prop7"].get<int32>())
        {
            Prop7 = fields["prop7"].get<int32>();
            Prop7Changed.Broadcast(Prop7);
        }
    }
    if(fields.contains("prop10")) {
        if(Prop10 != fields["prop10"].get<TArray<int32>>())
        {
            Prop10 = fields["prop10"].get<TArray<int32>>();
            Prop10Changed.Broadcast(Prop10);
        }
    }
    if(fields.contains("prop11")) {
        if(Prop11 != fields["prop11"].get<TArray<FOrgObjectapiTestbedStruct1>>())
        {
            Prop11 = fields["prop11"].get<TArray<FOrgObjectapiTestbedStruct1>>();
            Prop11Changed.Broadcast(Prop11);
        }
    }
    if(fields.contains("prop12")) {
        if(Prop12 != fields["prop12"].get<TArray<EOrgObjectapiTestbedEnum1>>())
        {
            Prop12 = fields["prop12"].get<TArray<EOrgObjectapiTestbedEnum1>>();
            Prop12Changed.Broadcast(Prop12);
        }
    }
    if(fields.contains("prop14")) {
        if(Prop14 != fields["prop14"].get<TArray<FOrgObjectapiTestbedStruct1>>())
        {
            Prop14 = fields["prop14"].get<TArray<FOrgObjectapiTestbedStruct1>>();
            Prop14Changed.Broadcast(Prop14);
        }
    }
}

std::string OLinkService::olinkObjectName()
{
    return "org.objectapi.testbed.Interface1";
}

void OLinkService::olinkOnSignal(std::string name, nlohmann::json args)
{
    std::string path = Name::pathFromName(name);
    if(path == "sig1") {
        Sig1Signal.Broadcast();
        return;
    }
    if(path == "sig2") {
        Sig2Signal.Broadcast(args[0].get<int32>(),args[1].get<FString>());
        return;
    }
    if(path == "sig3") {
        Sig3Signal.Broadcast(args[0].get<float>());
        return;
    }
}

void OLinkService::olinkOnPropertyChanged(std::string name, nlohmann::json value)
{
    std::string path = Name::pathFromName(name);
    applyState({ {path, value} });
}

void OLinkService::olinkOnInit(std::string name, nlohmann::json props, IClientNode *node)
{
    m_isReady = true;
    m_node = node;
    applyState(props);
    //call isReady();
}

void OLinkService::olinkOnRelease()
{
    m_isReady = false;
    m_node = nullptr;
}

} // namespace Private
} // namespace Interface1
} // namespace OrgObjectapiTestbed
