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

namespace OrgObjectapiTestbed {
namespace Interface2 {
namespace Private {

class WAMPService : public IOrgObjectapiTestbedInterface2Interface
{
public:

    explicit WAMPService();
    virtual ~WAMPService();

    // signals
    FOrgObjectapiTestbedInterface2Prop200ChangedDelegate Prop200Changed;
    FOrgObjectapiTestbedInterface2Prop200ChangedDelegate& GetProp200ChangedDelegate() override;

    FOrgObjectapiTestbedInterface2Prop201ChangedDelegate Prop201Changed;
    FOrgObjectapiTestbedInterface2Prop201ChangedDelegate& GetProp201ChangedDelegate() override;

    FOrgObjectapiTestbedInterface2Prop202ChangedDelegate Prop202Changed;
    FOrgObjectapiTestbedInterface2Prop202ChangedDelegate& GetProp202ChangedDelegate() override;

    FOrgObjectapiTestbedInterface2Prop203ChangedDelegate Prop203Changed;
    FOrgObjectapiTestbedInterface2Prop203ChangedDelegate& GetProp203ChangedDelegate() override;

    FOrgObjectapiTestbedInterface2Prop204ChangedDelegate Prop204Changed;
    FOrgObjectapiTestbedInterface2Prop204ChangedDelegate& GetProp204ChangedDelegate() override;

    FOrgObjectapiTestbedInterface2Prop205ChangedDelegate Prop205Changed;
    FOrgObjectapiTestbedInterface2Prop205ChangedDelegate& GetProp205ChangedDelegate() override;


    // properties
    int32 GetProp200() const override;
    void SetProp200(int32 Prop200) override;

    int32 GetProp201() const override;
    void SetProp201(int32 Prop201) override;

    int32 GetProp202() const override;
    void SetProp202(int32 Prop202) override;

    float GetProp203() const override;
    void SetProp203(float Prop203) override;

    float GetProp204() const override;
    void SetProp204(float Prop204) override;

    FString GetProp205() const override;
    void SetProp205(const FString& Prop205) override;


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

} // namespace Private
} // namespace Interface2
} // namespace OrgObjectapiTestbed
