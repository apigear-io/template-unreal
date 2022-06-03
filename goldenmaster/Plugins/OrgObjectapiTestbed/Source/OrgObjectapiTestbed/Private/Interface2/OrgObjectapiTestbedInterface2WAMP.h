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

class OrgObjectapiTestbedInterface2WAMPService : public IOrgObjectapiTestbedInterface2Interface
{
public:

    explicit OrgObjectapiTestbedInterface2WAMPService();
    virtual ~OrgObjectapiTestbedInterface2WAMPService();

    // signals
    FProp200ChangedDelegate Prop200Changed;
    FProp200ChangedDelegate& GetProp200ChangedDelegate() override;

    FProp201ChangedDelegate Prop201Changed;
    FProp201ChangedDelegate& GetProp201ChangedDelegate() override;

    FProp202ChangedDelegate Prop202Changed;
    FProp202ChangedDelegate& GetProp202ChangedDelegate() override;

    FProp203ChangedDelegate Prop203Changed;
    FProp203ChangedDelegate& GetProp203ChangedDelegate() override;

    FProp204ChangedDelegate Prop204Changed;
    FProp204ChangedDelegate& GetProp204ChangedDelegate() override;

    FProp205ChangedDelegate Prop205Changed;
    FProp205ChangedDelegate& GetProp205ChangedDelegate() override;


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

private:
    // properties - local copy
    int32 Prop200;
    int32 Prop201;
    int32 Prop202;
    float Prop203;
    float Prop204;
    FString Prop205;
};
