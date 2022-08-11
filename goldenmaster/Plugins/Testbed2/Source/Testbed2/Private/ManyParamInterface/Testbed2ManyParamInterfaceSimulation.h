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

#include "apig/Testbed2_apig.h"

namespace Testbed2 {
namespace ManyParamInterface {
namespace Private {
    
class SimulationService : public ITestbed2ManyParamInterfaceInterface
{
public:

    explicit SimulationService();
    virtual ~SimulationService();

    // signals
    FTestbed2ManyParamInterfaceSig1Delegate Sig1Signal;
    FTestbed2ManyParamInterfaceSig1Delegate& GetSig1SignalDelegate() override;
    
    FTestbed2ManyParamInterfaceSig2Delegate Sig2Signal;
    FTestbed2ManyParamInterfaceSig2Delegate& GetSig2SignalDelegate() override;
    
    FTestbed2ManyParamInterfaceSig3Delegate Sig3Signal;
    FTestbed2ManyParamInterfaceSig3Delegate& GetSig3SignalDelegate() override;
    
    FTestbed2ManyParamInterfaceSig4Delegate Sig4Signal;
    FTestbed2ManyParamInterfaceSig4Delegate& GetSig4SignalDelegate() override;
    
    FTestbed2ManyParamInterfaceProp1ChangedDelegate Prop1Changed;
    FTestbed2ManyParamInterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

    FTestbed2ManyParamInterfaceProp2ChangedDelegate Prop2Changed;
    FTestbed2ManyParamInterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() override;

    FTestbed2ManyParamInterfaceProp3ChangedDelegate Prop3Changed;
    FTestbed2ManyParamInterfaceProp3ChangedDelegate& GetProp3ChangedDelegate() override;

    FTestbed2ManyParamInterfaceProp4ChangedDelegate Prop4Changed;
    FTestbed2ManyParamInterfaceProp4ChangedDelegate& GetProp4ChangedDelegate() override;


    // properties
    int32 GetProp1() const override;
    void SetProp1(int32 Prop1) override;

    int32 GetProp2() const override;
    void SetProp2(int32 Prop2) override;

    int32 GetProp3() const override;
    void SetProp3(int32 Prop3) override;

    int32 GetProp4() const override;
    void SetProp4(int32 Prop4) override;


    // operations
    int32 Func1(int32 Param1) override;
    
    int32 Func2(int32 Param1, int32 Param2) override;
    
    int32 Func3(int32 Param1, int32 Param2, int32 Param3) override;
    
    int32 Func4(int32 Param1, int32 Param2, int32 Param3, int32 Param4) override;
    

private:
    // properties - local copy
    int32 Prop1;
    int32 Prop2;
    int32 Prop3;
    int32 Prop4;
};

} // namespace Private
} // namespace ManyParamInterface
} // namespace Testbed2
