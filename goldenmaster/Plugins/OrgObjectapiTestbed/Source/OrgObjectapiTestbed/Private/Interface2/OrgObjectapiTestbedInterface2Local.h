
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

class OrgObjectapiTestbedInterface2LocalService : public IOrgObjectapiTestbedInterface2Interface
{
public:

    explicit OrgObjectapiTestbedInterface2LocalService();
    virtual ~OrgObjectapiTestbedInterface2LocalService();

    // signals
    FOrgObjectapiTestbedInterface2Prop200ChangedDelegate OrgObjectapiTestbedInterface2Prop200Changed;
    FOrgObjectapiTestbedInterface2Prop200ChangedDelegate& GetOrgObjectapiTestbedInterface2Prop200ChangedDelegate() override;

    FOrgObjectapiTestbedInterface2Prop201ChangedDelegate OrgObjectapiTestbedInterface2Prop201Changed;
    FOrgObjectapiTestbedInterface2Prop201ChangedDelegate& GetOrgObjectapiTestbedInterface2Prop201ChangedDelegate() override;

    FOrgObjectapiTestbedInterface2Prop202ChangedDelegate OrgObjectapiTestbedInterface2Prop202Changed;
    FOrgObjectapiTestbedInterface2Prop202ChangedDelegate& GetOrgObjectapiTestbedInterface2Prop202ChangedDelegate() override;

    FOrgObjectapiTestbedInterface2Prop203ChangedDelegate OrgObjectapiTestbedInterface2Prop203Changed;
    FOrgObjectapiTestbedInterface2Prop203ChangedDelegate& GetOrgObjectapiTestbedInterface2Prop203ChangedDelegate() override;

    FOrgObjectapiTestbedInterface2Prop204ChangedDelegate OrgObjectapiTestbedInterface2Prop204Changed;
    FOrgObjectapiTestbedInterface2Prop204ChangedDelegate& GetOrgObjectapiTestbedInterface2Prop204ChangedDelegate() override;

    FOrgObjectapiTestbedInterface2Prop205ChangedDelegate OrgObjectapiTestbedInterface2Prop205Changed;
    FOrgObjectapiTestbedInterface2Prop205ChangedDelegate& GetOrgObjectapiTestbedInterface2Prop205ChangedDelegate() override;


    // properties
    int32 GetProp200() const override;
    void SetProp200(int32 InProp200) override;

    int32 GetProp201() const override;
    void SetProp201(int32 InProp201) override;

    int32 GetProp202() const override;
    void SetProp202(int32 InProp202) override;

    float GetProp203() const override;
    void SetProp203(float InProp203) override;

    float GetProp204() const override;
    void SetProp204(float InProp204) override;

    FString GetProp205() const override;
    void SetProp205(const FString& InProp205) override;


    // operations

private:
    // properties - local copy - use setter functions to emit changed signals
    int32 Prop200;
    int32 Prop201;
    int32 Prop202;
    float Prop203;
    float Prop204;
    FString Prop205;
};
