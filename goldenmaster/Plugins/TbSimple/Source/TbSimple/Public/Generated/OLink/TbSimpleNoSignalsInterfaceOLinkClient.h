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
#include "Templates/PimplPtr.h"
#include "TbSimpleNoSignalsInterfaceOLinkClient.generated.h"

struct TbSimpleNoSignalsInterfacePropertiesData;

UCLASS(NotBlueprintable, BlueprintType)
class TBSIMPLE_API UTbSimpleNoSignalsInterfaceOLinkClient : public UAbstractTbSimpleNoSignalsInterface
{
	GENERATED_BODY()
public:
	explicit UTbSimpleNoSignalsInterfaceOLinkClient();
	virtual ~UTbSimpleNoSignalsInterfaceOLinkClient() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	bool GetPropBool_Implementation() const override;
	void SetPropBool_Implementation(bool bPropBool) override;

	int32 GetPropInt_Implementation() const override;
	void SetPropInt_Implementation(int32 PropInt) override;

	// operations
	void FuncVoid_Implementation() override;

	bool FuncBool_Implementation(bool bParamBool) override;

private:
	void applyState(const nlohmann::json& fields);
	void emitSignal(const std::string& signalName, const nlohmann::json& args);
	std::shared_ptr<FUnrealOLinkSink> m_sink;

	// member variable to store the last sent data
	TPimplPtr<TbSimpleNoSignalsInterfacePropertiesData> _SentData;
};
