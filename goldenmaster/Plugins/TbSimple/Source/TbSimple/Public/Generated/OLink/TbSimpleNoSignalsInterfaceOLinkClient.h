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

#include "TbSimpleNoSignalsInterfaceInterface.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
THIRD_PARTY_INCLUDES_END
#include "unrealolinksink.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "TbSimpleNoSignalsInterfaceOLinkClient.generated.h"

UCLASS(BlueprintType)
class TBSIMPLE_API UTbSimpleNoSignalsInterfaceOLinkClient : public UGameInstanceSubsystem, public ITbSimpleNoSignalsInterfaceInterface
{
	GENERATED_BODY()
public:
	explicit UTbSimpleNoSignalsInterfaceOLinkClient();
	virtual ~UTbSimpleNoSignalsInterfaceOLinkClient() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// signals
	FTbSimpleNoSignalsInterfacePropBoolChangedDelegate PropBoolChanged;
	FTbSimpleNoSignalsInterfacePropBoolChangedDelegate& GetPropBoolChangedDelegate() override;

	FTbSimpleNoSignalsInterfacePropIntChangedDelegate PropIntChanged;
	FTbSimpleNoSignalsInterfacePropIntChangedDelegate& GetPropIntChangedDelegate() override;

	// properties
	bool GetPropBool_Implementation() const override;
	void SetPropBool_Implementation(bool bPropBool) override;

	int32 GetPropInt_Implementation() const override;
	void SetPropInt_Implementation(int32 PropInt) override;

	// operations
	void FuncVoid_Implementation() override;

	void FuncBoolAsync_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, bool& Result, bool bParamBool) override{};
	bool FuncBool_Implementation(bool bParamBool) override;

protected:
	// signals

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
