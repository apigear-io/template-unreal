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
#include "olink/clientnode.h"

namespace Testbed2
{
namespace NestedStruct3Interface
{
namespace Private
{

class OLinkService : public ITestbed2NestedStruct3InterfaceInterface, public ApiGear::ObjectLink::IObjectSink
{
public:
	explicit OLinkService();
	virtual ~OLinkService();

	// signals
	FTestbed2NestedStruct3InterfaceSig1Delegate Sig1Signal;
	FTestbed2NestedStruct3InterfaceSig1Delegate& GetSig1SignalDelegate() override;

	FTestbed2NestedStruct3InterfaceSig2Delegate Sig2Signal;
	FTestbed2NestedStruct3InterfaceSig2Delegate& GetSig2SignalDelegate() override;

	FTestbed2NestedStruct3InterfaceSig3Delegate Sig3Signal;
	FTestbed2NestedStruct3InterfaceSig3Delegate& GetSig3SignalDelegate() override;

	FTestbed2NestedStruct3InterfaceProp1ChangedDelegate Prop1Changed;
	FTestbed2NestedStruct3InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	FTestbed2NestedStruct3InterfaceProp2ChangedDelegate Prop2Changed;
	FTestbed2NestedStruct3InterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() override;

	FTestbed2NestedStruct3InterfaceProp3ChangedDelegate Prop3Changed;
	FTestbed2NestedStruct3InterfaceProp3ChangedDelegate& GetProp3ChangedDelegate() override;

	// properties
	FTestbed2NestedStruct1 GetProp1() const override;
	void SetProp1(const FTestbed2NestedStruct1& Prop1) override;

	FTestbed2NestedStruct2 GetProp2() const override;
	void SetProp2(const FTestbed2NestedStruct2& Prop2) override;

	FTestbed2NestedStruct3 GetProp3() const override;
	void SetProp3(const FTestbed2NestedStruct3& Prop3) override;

	// operations
	void Func1Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1) override{};
	FTestbed2NestedStruct1 Func1(const FTestbed2NestedStruct1& Param1) override;

	void Func2Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) override{};
	FTestbed2NestedStruct1 Func2(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2) override;

	void Func3Async(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3) override{};
	FTestbed2NestedStruct1 Func3(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3) override;

	// olink sink interface
	std::string olinkObjectName() override;
	void olinkOnSignal(std::string name, nlohmann::json args) override;
	void olinkOnPropertyChanged(std::string name, nlohmann::json value) override;
	void olinkOnInit(std::string name, nlohmann::json props, ApiGear::ObjectLink::IClientNode* node) override;
	void olinkOnRelease() override;

private:
	void applyState(const nlohmann::json& fields);
	ApiGear::ObjectLink::IClientNode* m_node;
	bool m_isReady;
	// properties - local copy
	FTestbed2NestedStruct1 Prop1;
	FTestbed2NestedStruct2 Prop2;
	FTestbed2NestedStruct3 Prop3;
};

} // namespace Private
} // namespace NestedStruct3Interface
} // namespace Testbed2
