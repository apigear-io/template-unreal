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

#include "TbSimpleNoOperationsInterfaceInterface.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
THIRD_PARTY_INCLUDES_END
#include "unrealolinksink.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TbSimpleNoOperationsInterfaceOLinkClient.generated.h"

UCLASS(BlueprintType)
class TBSIMPLE_API UTbSimpleNoOperationsInterfaceOLinkClient : public UGameInstanceSubsystem, public ITbSimpleNoOperationsInterfaceInterface
{
	GENERATED_BODY()
public:
	explicit UTbSimpleNoOperationsInterfaceOLinkClient();
	virtual ~UTbSimpleNoOperationsInterfaceOLinkClient() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoOperationsInterface", DisplayName = "SigVoid Signal")
	FTbSimpleNoOperationsInterfaceSigVoidDelegate SigVoidSignal;
	FTbSimpleNoOperationsInterfaceSigVoidDelegate& GetSigVoidSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoOperationsInterface", DisplayName = "SigBool Signal")
	FTbSimpleNoOperationsInterfaceSigBoolDelegate SigBoolSignal;
	FTbSimpleNoOperationsInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoOperationsInterface", DisplayName = "PropBool Changed")
	FTbSimpleNoOperationsInterfacePropBoolChangedDelegate PropBoolChanged;
	FTbSimpleNoOperationsInterfacePropBoolChangedDelegate& GetPropBoolChangedDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoOperationsInterface", DisplayName = "PropInt Changed")
	FTbSimpleNoOperationsInterfacePropIntChangedDelegate PropIntChanged;
	FTbSimpleNoOperationsInterfacePropIntChangedDelegate& GetPropIntChangedDelegate() override;

	// properties
	bool GetPropBool_Implementation() const override;
	void SetPropBool_Implementation(bool bPropBool) override;

	int32 GetPropInt_Implementation() const override;
	void SetPropInt_Implementation(int32 PropInt) override;

	// operations

protected:
	// signals
	void BroadcastSigVoid_Implementation() override;

	void BroadcastSigBool_Implementation(bool bParamBool) override;

	void BroadcastPropBoolChanged_Implementation(bool bPropBool) override;

	void BroadcastPropIntChanged_Implementation(int32 PropInt) override;

private:
	void applyState(const nlohmann::json& fields);
	void emitSignal(const std::string& signalName, const nlohmann::json& args);
	std::shared_ptr<FUnrealOLinkSink> m_sink;

	// properties - local copy
	bool bPropBool{false};
	int32 PropInt{0};
};
