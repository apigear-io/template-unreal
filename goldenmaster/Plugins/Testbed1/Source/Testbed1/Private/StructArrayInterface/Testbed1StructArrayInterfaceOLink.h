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

#include "apig/Testbed1_apig.h"
#include "olink/clientnode.h"
#include "Testbed1StructArrayInterfaceOLink.generated.h"

UCLASS(BlueprintType)
class TESTBED1_API UTestbed1StructArrayInterfaceOLinkService : public UObject, public ITestbed1StructArrayInterfaceInterface, public ApiGear::ObjectLink::IObjectSink
{
	GENERATED_BODY()
public:
	explicit UTestbed1StructArrayInterfaceOLinkService();
	virtual ~UTestbed1StructArrayInterfaceOLinkService();

	// signals
	FTestbed1StructArrayInterfaceSigBoolDelegate SigBoolSignal;
	FTestbed1StructArrayInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() override;

	FTestbed1StructArrayInterfaceSigIntDelegate SigIntSignal;
	FTestbed1StructArrayInterfaceSigIntDelegate& GetSigIntSignalDelegate() override;

	FTestbed1StructArrayInterfaceSigFloatDelegate SigFloatSignal;
	FTestbed1StructArrayInterfaceSigFloatDelegate& GetSigFloatSignalDelegate() override;

	FTestbed1StructArrayInterfaceSigStringDelegate SigStringSignal;
	FTestbed1StructArrayInterfaceSigStringDelegate& GetSigStringSignalDelegate() override;

	FTestbed1StructArrayInterfacePropBoolChangedDelegate PropBoolChanged;
	FTestbed1StructArrayInterfacePropBoolChangedDelegate& GetPropBoolChangedDelegate() override;

	FTestbed1StructArrayInterfacePropIntChangedDelegate PropIntChanged;
	FTestbed1StructArrayInterfacePropIntChangedDelegate& GetPropIntChangedDelegate() override;

	FTestbed1StructArrayInterfacePropFloatChangedDelegate PropFloatChanged;
	FTestbed1StructArrayInterfacePropFloatChangedDelegate& GetPropFloatChangedDelegate() override;

	FTestbed1StructArrayInterfacePropStringChangedDelegate PropStringChanged;
	FTestbed1StructArrayInterfacePropStringChangedDelegate& GetPropStringChangedDelegate() override;

	// properties
	void GetPropBool_Implementation(TArray<FTestbed1StructBool>& ReturnValue) const override;
	void SetPropBool_Implementation(const TArray<FTestbed1StructBool>& PropBool) override;

	void GetPropInt_Implementation(TArray<FTestbed1StructInt>& ReturnValue) const override;
	void SetPropInt_Implementation(const TArray<FTestbed1StructInt>& PropInt) override;

	void GetPropFloat_Implementation(TArray<FTestbed1StructFloat>& ReturnValue) const override;
	void SetPropFloat_Implementation(const TArray<FTestbed1StructFloat>& PropFloat) override;

	void GetPropString_Implementation(TArray<FTestbed1StructString>& ReturnValue) const override;
	void SetPropString_Implementation(const TArray<FTestbed1StructString>& PropString) override;

	// operations
	void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructBool>& ParamBool) override{};
	void FuncBool_Implementation(FTestbed1StructBool& Result, const TArray<FTestbed1StructBool>& ParamBool) override;

	void FuncIntAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructInt>& ParamInt) override{};
	void FuncInt_Implementation(FTestbed1StructBool& Result, const TArray<FTestbed1StructInt>& ParamInt) override;

	void FuncFloatAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructFloat>& ParamFloat) override{};
	void FuncFloat_Implementation(FTestbed1StructBool& Result, const TArray<FTestbed1StructFloat>& ParamFloat) override;

	void FuncStringAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed1StructBool& Result, const TArray<FTestbed1StructString>& ParamString) override{};
	void FuncString_Implementation(FTestbed1StructBool& Result, const TArray<FTestbed1StructString>& ParamString) override;

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
	TArray<FTestbed1StructBool> PropBool;
	TArray<FTestbed1StructInt> PropInt;
	TArray<FTestbed1StructFloat> PropFloat;
	TArray<FTestbed1StructString> PropString;
};
