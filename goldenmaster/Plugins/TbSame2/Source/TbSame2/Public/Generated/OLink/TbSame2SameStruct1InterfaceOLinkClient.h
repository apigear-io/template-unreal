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

#include "TbSame2SameStruct1InterfaceInterface.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
THIRD_PARTY_INCLUDES_END
#include "unrealolinksink.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Runtime/Launch/Resources/Version.h"
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
#include "Templates/UniquePtr.h"
#else
#include "Templates/PimplPtr.h"
#endif
#include "TbSame2SameStruct1InterfaceOLinkClient.generated.h"

struct TbSame2SameStruct1InterfacePropertiesData;

UCLASS(NotBlueprintable, BlueprintType)
class TBSAME2_API UTbSame2SameStruct1InterfaceOLinkClient : public UAbstractTbSame2SameStruct1Interface
{
	GENERATED_BODY()
public:
	explicit UTbSame2SameStruct1InterfaceOLinkClient();

	// only needed in 4.25 to use TUniquePtr<TbSame2SameStruct1InterfacePropertiesData>
	UTbSame2SameStruct1InterfaceOLinkClient(FVTableHelper& Helper);
	virtual ~UTbSame2SameStruct1InterfaceOLinkClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	FTbSame2Struct1 GetProp1_Implementation() const override;
	void SetProp1_Implementation(const FTbSame2Struct1& Prop1) override;

	// operations
	FTbSame2Struct1 Func1_Implementation(const FTbSame2Struct1& Param1) override;

private:
	void applyState(const nlohmann::json& fields);
	void emitSignal(const std::string& signalName, const nlohmann::json& args);
	std::shared_ptr<FUnrealOLinkSink> m_sink;

	// member variable to store the last sent data
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
	TUniquePtr<TbSame2SameStruct1InterfacePropertiesData> _SentData;
#else
	TPimplPtr<TbSame2SameStruct1InterfacePropertiesData> _SentData;
#endif
};
