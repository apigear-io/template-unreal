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

#include "TbSame2SameEnum1InterfaceInterface.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
THIRD_PARTY_INCLUDES_END
#include "unrealolinksink.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Templates/PimplPtr.h"
#include "TbSame2SameEnum1InterfaceOLinkClient.generated.h"

struct TbSame2SameEnum1InterfacePropertiesData;

UCLASS(NotBlueprintable, BlueprintType)
class TBSAME2_API UTbSame2SameEnum1InterfaceOLinkClient : public UAbstractTbSame2SameEnum1Interface
{
	GENERATED_BODY()
public:
	explicit UTbSame2SameEnum1InterfaceOLinkClient();
	virtual ~UTbSame2SameEnum1InterfaceOLinkClient() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	ETbSame2Enum1 GetProp1_Implementation() const override;
	void SetProp1_Implementation(ETbSame2Enum1 Prop1) override;

	// operations
	ETbSame2Enum1 Func1_Implementation(ETbSame2Enum1 Param1) override;

private:
	void applyState(const nlohmann::json& fields);
	void emitSignal(const std::string& signalName, const nlohmann::json& args);
	std::shared_ptr<FUnrealOLinkSink> m_sink;

	// member variable to store the last sent data
	TPimplPtr<TbSame2SameEnum1InterfacePropertiesData> _SentData;
};
