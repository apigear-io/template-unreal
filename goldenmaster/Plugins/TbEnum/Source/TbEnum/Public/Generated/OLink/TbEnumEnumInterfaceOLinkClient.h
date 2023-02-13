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

#include "TbEnumEnumInterfaceInterface.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
THIRD_PARTY_INCLUDES_END
#include "unrealolinksink.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TbEnumEnumInterfaceOLinkClient.generated.h"

UCLASS(BlueprintType)
class TBENUM_API UTbEnumEnumInterfaceOLinkClient : public UGameInstanceSubsystem, public ITbEnumEnumInterfaceInterface
{
	GENERATED_BODY()
public:
	explicit UTbEnumEnumInterfaceOLinkClient();
	virtual ~UTbEnumEnumInterfaceOLinkClient() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface", DisplayName = "Sig0 Signal")
	FTbEnumEnumInterfaceSig0Delegate Sig0Signal;
	FTbEnumEnumInterfaceSig0Delegate& GetSig0SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface", DisplayName = "Sig1 Signal")
	FTbEnumEnumInterfaceSig1Delegate Sig1Signal;
	FTbEnumEnumInterfaceSig1Delegate& GetSig1SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface", DisplayName = "Sig2 Signal")
	FTbEnumEnumInterfaceSig2Delegate Sig2Signal;
	FTbEnumEnumInterfaceSig2Delegate& GetSig2SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface", DisplayName = "Sig3 Signal")
	FTbEnumEnumInterfaceSig3Delegate Sig3Signal;
	FTbEnumEnumInterfaceSig3Delegate& GetSig3SignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface", DisplayName = "Prop0 Changed")
	FTbEnumEnumInterfaceProp0ChangedDelegate Prop0Changed;
	FTbEnumEnumInterfaceProp0ChangedDelegate& GetProp0ChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface", DisplayName = "Prop1 Changed")
	FTbEnumEnumInterfaceProp1ChangedDelegate Prop1Changed;
	FTbEnumEnumInterfaceProp1ChangedDelegate& GetProp1ChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface", DisplayName = "Prop2 Changed")
	FTbEnumEnumInterfaceProp2ChangedDelegate Prop2Changed;
	FTbEnumEnumInterfaceProp2ChangedDelegate& GetProp2ChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface", DisplayName = "Prop3 Changed")
	FTbEnumEnumInterfaceProp3ChangedDelegate Prop3Changed;
	FTbEnumEnumInterfaceProp3ChangedDelegate& GetProp3ChangedDelegate() override;

	// properties
	ETbEnumEnum0 GetProp0_Implementation() const override;
	void SetProp0_Implementation(ETbEnumEnum0 Prop0) override;

	ETbEnumEnum1 GetProp1_Implementation() const override;
	void SetProp1_Implementation(ETbEnumEnum1 Prop1) override;

	ETbEnumEnum2 GetProp2_Implementation() const override;
	void SetProp2_Implementation(ETbEnumEnum2 Prop2) override;

	ETbEnumEnum3 GetProp3_Implementation() const override;
	void SetProp3_Implementation(ETbEnumEnum3 Prop3) override;

	// operations
	void Func0Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum0& Result, ETbEnumEnum0 Param0) override{};
	ETbEnumEnum0 Func0_Implementation(ETbEnumEnum0 Param0) override;

	void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum1& Result, ETbEnumEnum1 Param1) override{};
	ETbEnumEnum1 Func1_Implementation(ETbEnumEnum1 Param1) override;

	void Func2Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum2& Result, ETbEnumEnum2 Param2) override{};
	ETbEnumEnum2 Func2_Implementation(ETbEnumEnum2 Param2) override;

	void Func3Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, ETbEnumEnum3& Result, ETbEnumEnum3 Param3) override{};
	ETbEnumEnum3 Func3_Implementation(ETbEnumEnum3 Param3) override;

protected:
	// signals
	void BroadcastSig0_Implementation(ETbEnumEnum0 Param0) override;

	void BroadcastSig1_Implementation(ETbEnumEnum1 Param1) override;

	void BroadcastSig2_Implementation(ETbEnumEnum2 Param2) override;

	void BroadcastSig3_Implementation(ETbEnumEnum3 Param3) override;

	void BroadcastProp0Changed_Implementation(ETbEnumEnum0 Prop0) override;

	void BroadcastProp1Changed_Implementation(ETbEnumEnum1 Prop1) override;

	void BroadcastProp2Changed_Implementation(ETbEnumEnum2 Prop2) override;

	void BroadcastProp3Changed_Implementation(ETbEnumEnum3 Prop3) override;

private:
	void applyState(const nlohmann::json& fields);
	void emitSignal(const std::string& signalName, const nlohmann::json& args);
	std::shared_ptr<FUnrealOLinkSink> m_sink;

	// properties - local copy
	ETbEnumEnum0 Prop0{ETbEnumEnum0::TEE_VALUE0};
	ETbEnumEnum1 Prop1{ETbEnumEnum1::TEE_VALUE1};
	ETbEnumEnum2 Prop2{ETbEnumEnum2::TEE_VALUE2};
	ETbEnumEnum3 Prop3{ETbEnumEnum3::TEE_VALUE3};
};
