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
#pragma once

#include "apig/OrgObjectapiTestbed_apig.h"
#include "olink/clientnode.h"
#include "AbstractOrgObjectapiTestbedInterface2Publisher.h"

class OrgObjectapiTestbedInterface2OLinkService : public AbstractOrgObjectapiTestbedInterface2Publisher, public ApiGear::ObjectLink::IObjectSink
{
public:

    explicit OrgObjectapiTestbedInterface2OLinkService();
    virtual ~OrgObjectapiTestbedInterface2OLinkService();

    // properties
    int32 GetProp200() const override;
    void SetProp200(int32 Value) override;

    int32 GetProp201() const override;
    void SetProp201(int32 Value) override;

    int32 GetProp202() const override;
    void SetProp202(int32 Value) override;

    float GetProp203() const override;
    void SetProp203(float Value) override;

    float GetProp204() const override;
    void SetProp204(float Value) override;

    FString GetProp205() const override;
    void SetProp205(FString Value) override;


    // operations

    // olink sink interface
    std::string olinkObjectName() override;
    void olinkOnSignal(std::string name, nlohmann::json args) override;
    void olinkOnPropertyChanged(std::string name, nlohmann::json value) override;
    void olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode *node) override;
    void olinkOnRelease() override;

private:
    void applyState(const nlohmann::json& fields);
    
    ApiGear::ObjectLink::IClientNode *m_node;
    bool m_isReady;
    // properties - local copy
    int32 Prop200;
    int32 Prop201;
    int32 Prop202;
    float Prop203;
    float Prop204;
    FString Prop205;
};
