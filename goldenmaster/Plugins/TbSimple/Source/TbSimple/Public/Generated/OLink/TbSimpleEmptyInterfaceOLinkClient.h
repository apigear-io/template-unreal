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

#include "AbstractTbSimpleEmptyInterface.h"
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
#include "TbSimpleEmptyInterfaceOLinkClient.generated.h"
DECLARE_LOG_CATEGORY_EXTERN(LogTbSimpleEmptyInterfaceOLinkClient, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TBSIMPLE_API UTbSimpleEmptyInterfaceOLinkClient : public UAbstractTbSimpleEmptyInterface
{
	GENERATED_BODY()
public:
	explicit UTbSimpleEmptyInterfaceOLinkClient();

	// only needed in 4.25 to use TUniquePtr<TbSimpleEmptyInterfacePropertiesData>
	UTbSimpleEmptyInterfaceOLinkClient(FVTableHelper& Helper);
	virtual ~UTbSimpleEmptyInterfaceOLinkClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	// operations

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|EmptyInterface")
	void UseConnection(TScriptInterface<class IApiGearConnection> InConnection);

private:
	void applyState(const nlohmann::json& fields);
	void emitSignal(const std::string& signalName, const nlohmann::json& args);
	std::shared_ptr<FUnrealOLinkSink> m_sink;
	TScriptInterface<class IApiGearConnection> Connection;
};
