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

#include "TbSame2SameEnum2InterfaceInterface.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
THIRD_PARTY_INCLUDES_END
#include "unrealolinksink.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TbSame2SameEnum2InterfaceOLinkClient.generated.h"

UCLASS(BlueprintType)
class TBSAME2_API UTbSame2SameEnum2InterfaceOLinkClient : public UGameInstanceSubsystem, public ITbSame2SameEnum2InterfaceInterface
{
	GENERATED_BODY()
public:
	explicit UTbSame2SameEnum2InterfaceOLinkClient();
	virtual ~UTbSame2SameEnum2InterfaceOLinkClient() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// signals
	FTbSame2SameEnum2InterfaceSig1Delegate Sig1Signal;
	FTbSame2SameEnum2InterfaceSig1Delegate& GetSig1SignalDelegate() override;

	FTbSame2SameEnum2InterfaceSig2Delegate Sig2Signal;
	FTbSame2SameEnum2InterfaceSig2Delegate& GetSig2SignalDelegate() override;

	FTbSame2SameEnum2InterfaceProp1ChangedDelegate Prop1Changed;
	FTbSame2SameEnum2InterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	FTbSame2SameEnum2InterfaceProp2ChangedDelegate Prop2Changed;
	FTbSame2SameEnum2InterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() override;

	// properties
	ETbSame2Enum1 GetProp1_Implementation() const override;
	void SetProp1_Implementation(ETbSame2Enum1 Prop1) override;

	ETbSame2Enum2 GetProp2_Implementation() const override;
	void SetProp2_Implementation(ETbSame2Enum2 Prop2) override;

	// operations
	void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame2Enum1& Result, ETbSame2Enum1 Param1) override{};
	ETbSame2Enum1 Func1_Implementation(ETbSame2Enum1 Param1) override;

	void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbSame2Enum1& Result, ETbSame2Enum1 Param1, ETbSame2Enum2 Param2) override{};
	ETbSame2Enum1 Func2_Implementation(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2) override;

protected:
	// signals
	void BroadcastSig1_Implementation(ETbSame2Enum1 Param1) override;

	void BroadcastSig2_Implementation(ETbSame2Enum1 Param1, ETbSame2Enum2 Param2) override;

	void BroadcastProp1Changed_Implementation(ETbSame2Enum1 Prop1) override;

	void BroadcastProp2Changed_Implementation(ETbSame2Enum2 Prop2) override;

private:
	void applyState(const nlohmann::json& fields);
	void emitSignal(const std::string& signalName, const nlohmann::json& args);
	std::shared_ptr<FUnrealOLinkSink> m_sink;

	// properties - local copy
	ETbSame2Enum1 Prop1{ETbSame2Enum1::VALUE1};
	ETbSame2Enum2 Prop2{ETbSame2Enum2::VALUE1};
};
