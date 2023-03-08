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

UCLASS(NotBlueprintable, BlueprintType)
class TBENUM_API UTbEnumEnumInterfaceOLinkClient : public UAbstractTbEnumEnumInterface
{
	GENERATED_BODY()
public:
	explicit UTbEnumEnumInterfaceOLinkClient();
	virtual ~UTbEnumEnumInterfaceOLinkClient() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

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
	ETbEnumEnum0 Func0_Implementation(ETbEnumEnum0 Param0) override;

	ETbEnumEnum1 Func1_Implementation(ETbEnumEnum1 Param1) override;

	ETbEnumEnum2 Func2_Implementation(ETbEnumEnum2 Param2) override;

	ETbEnumEnum3 Func3_Implementation(ETbEnumEnum3 Param3) override;

private:
	void applyState(const nlohmann::json& fields);
	void emitSignal(const std::string& signalName, const nlohmann::json& args);
	std::shared_ptr<FUnrealOLinkSink> m_sink;
};
