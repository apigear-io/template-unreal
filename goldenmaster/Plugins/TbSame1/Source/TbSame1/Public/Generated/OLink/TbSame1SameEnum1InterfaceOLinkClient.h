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

#include "TbSame1SameEnum1InterfaceInterface.h"
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
#include "TbSame1SameEnum1InterfaceOLinkClient.generated.h"

struct TbSame1SameEnum1InterfacePropertiesData;
DECLARE_LOG_CATEGORY_EXTERN(LogTbSame1SameEnum1InterfaceOLinkClient, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TBSAME1_API UTbSame1SameEnum1InterfaceOLinkClient : public UAbstractTbSame1SameEnum1Interface
{
	GENERATED_BODY()
public:
	explicit UTbSame1SameEnum1InterfaceOLinkClient();

	// only needed in 4.25 to use TUniquePtr<TbSame1SameEnum1InterfacePropertiesData>
	UTbSame1SameEnum1InterfaceOLinkClient(FVTableHelper& Helper);
	virtual ~UTbSame1SameEnum1InterfaceOLinkClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	ETbSame1Enum1 GetProp1_Implementation() const override;
	void SetProp1_Implementation(ETbSame1Enum1 Prop1) override;

	// operations
	ETbSame1Enum1 Func1_Implementation(ETbSame1Enum1 Param1) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame1|SameEnum1Interface")
	void UseConnection(TScriptInterface<class IApiGearConnection> InConnection);

private:
	void applyState(const nlohmann::json& fields);
	void emitSignal(const std::string& signalName, const nlohmann::json& args);
	std::shared_ptr<FUnrealOLinkSink> m_sink;

	// member variable to store the last sent data
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
	TUniquePtr<TbSame1SameEnum1InterfacePropertiesData> _SentData;
#else
	TPimplPtr<TbSame1SameEnum1InterfacePropertiesData> _SentData;
#endif
	TScriptInterface<class IApiGearConnection> Connection;
};
