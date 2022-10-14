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
#include "Testbed2ManyParamInterfaceOLink.generated.h"

UCLASS(BlueprintType)
class TESTBED2_API UTestbed2ManyParamInterfaceOLinkService : public UObject, public ITestbed2ManyParamInterfaceInterface, public ApiGear::ObjectLink::IObjectSink
{
	GENERATED_BODY()
public:
	explicit UTestbed2ManyParamInterfaceOLinkService();
	virtual ~UTestbed2ManyParamInterfaceOLinkService();

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
	void GetProp1_Implementation(int32& ReturnValue) const override;
	void SetProp1_Implementation(int32 Prop1) override;

	void GetProp2_Implementation(int32& ReturnValue) const override;
	void SetProp2_Implementation(int32 Prop2) override;

	void GetProp3_Implementation(int32& ReturnValue) const override;
	void SetProp3_Implementation(int32 Prop3) override;

	void GetProp4_Implementation(int32& ReturnValue) const override;
	void SetProp4_Implementation(int32 Prop4) override;

	// operations
	void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1) override{};
	void Func1_Implementation(int32& Result, int32 Param1) override;

	void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2) override{};
	void Func2_Implementation(int32& Result, int32 Param1, int32 Param2) override;

	void Func3Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2, int32 Param3) override{};
	void Func3_Implementation(int32& Result, int32 Param1, int32 Param2, int32 Param3) override;

	void Func4Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result, int32 Param1, int32 Param2, int32 Param3, int32 Param4) override{};
	void Func4_Implementation(int32& Result, int32 Param1, int32 Param2, int32 Param3, int32 Param4) override;

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
	int32 Prop1;
	int32 Prop2;
	int32 Prop3;
	int32 Prop4;
};
