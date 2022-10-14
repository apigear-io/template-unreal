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

#include "apig/TbSame1_apig.h"
#include "olink/clientnode.h"
#include "TbSame1SameStruct2InterfaceOLink.generated.h"

UCLASS(BlueprintType)
class TBSAME1_API UTbSame1SameStruct2InterfaceOLinkService : public UObject, public ITbSame1SameStruct2InterfaceInterface, public ApiGear::ObjectLink::IObjectSink
{
	GENERATED_BODY()
public:
	explicit UTbSame1SameStruct2InterfaceOLinkService();
	virtual ~UTbSame1SameStruct2InterfaceOLinkService();

	// signals
	FTbSame1SameStruct2InterfaceSig1Delegate Sig1Signal;
	FTbSame1SameStruct2InterfaceSig1Delegate& GetSig1SignalDelegate() override;

	FTbSame1SameStruct2InterfaceSig2Delegate Sig2Signal;
	FTbSame1SameStruct2InterfaceSig2Delegate& GetSig2SignalDelegate() override;

	FTbSame1SameStruct2InterfaceProp1ChangedDelegate Prop1Changed;
	FTbSame1SameStruct2InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	FTbSame1SameStruct2InterfaceProp2ChangedDelegate Prop2Changed;
	FTbSame1SameStruct2InterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() override;

	// properties
	void GetProp1_Implementation(FTbSame1Struct2& ReturnValue) const override;
	void SetProp1_Implementation(const FTbSame1Struct2& Prop1) override;

	void GetProp2_Implementation(FTbSame1Struct2& ReturnValue) const override;
	void SetProp2_Implementation(const FTbSame1Struct2& Prop2) override;

	// operations
	void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame1Struct1& Result, const FTbSame1Struct1& Param1) override{};
	void Func1_Implementation(FTbSame1Struct1& Result, const FTbSame1Struct1& Param1) override;

	void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTbSame1Struct1& Result, const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2) override{};
	void Func2_Implementation(FTbSame1Struct1& Result, const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2) override;

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
	FTbSame1Struct2 Prop1;
	FTbSame1Struct2 Prop2;
};
