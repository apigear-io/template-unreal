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

#include "TbSimpleNoPropertiesInterfaceInterface.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
THIRD_PARTY_INCLUDES_END
#include "unrealolinksink.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TbSimpleNoPropertiesInterfaceOLinkClient.generated.h"

UCLASS(BlueprintType)
class TBSIMPLE_API UTbSimpleNoPropertiesInterfaceOLinkClient : public UGameInstanceSubsystem, public ITbSimpleNoPropertiesInterfaceInterface
{
	GENERATED_BODY()
public:
	explicit UTbSimpleNoPropertiesInterfaceOLinkClient();
	virtual ~UTbSimpleNoPropertiesInterfaceOLinkClient() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// signals
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoPropertiesInterface", DisplayName = "SigVoid Signal")
	FTbSimpleNoPropertiesInterfaceSigVoidDelegate SigVoidSignal;
	FTbSimpleNoPropertiesInterfaceSigVoidDelegate& GetSigVoidSignalDelegate() override;

	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|NoPropertiesInterface", DisplayName = "SigBool Signal")
	FTbSimpleNoPropertiesInterfaceSigBoolDelegate SigBoolSignal;
	FTbSimpleNoPropertiesInterfaceSigBoolDelegate& GetSigBoolSignalDelegate() override;

	// properties
	// operations
	void FuncVoid_Implementation() override;

	void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool) override{};
	bool FuncBool_Implementation(bool bParamBool) override;

protected:
	// signals
	void BroadcastSigVoid_Implementation() override;

	void BroadcastSigBool_Implementation(bool bParamBool) override;

private:
	void applyState(const nlohmann::json& fields);
	void emitSignal(const std::string& signalName, const nlohmann::json& args);
	std::shared_ptr<FUnrealOLinkSink> m_sink;

	// properties - local copy
};
