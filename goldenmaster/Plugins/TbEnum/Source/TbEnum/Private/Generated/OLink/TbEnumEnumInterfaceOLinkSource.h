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
#include "Subsystems/GameInstanceSubsystem.h"
THIRD_PARTY_INCLUDES_START
#include "olink/iobjectsource.h"
THIRD_PARTY_INCLUDES_END
#include "UnrealOLinkHost.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbEnumEnumInterfaceOLinkSource, Log, All);
/// @brief handles OLink network interactions specific to ITbEnumEnumInterfaceInterface
class TbEnumEnumInterfaceOLinkSource : public ApiGear::ObjectLink::IObjectSource
{
public:
	explicit TbEnumEnumInterfaceOLinkSource();
	virtual ~TbEnumEnumInterfaceOLinkSource() = default;

	/** set the backend service which logic is to be used */
	void setBackendService(TScriptInterface<ITbEnumEnumInterfaceInterface> InService);

	/** set the OLink host to be used */
	void setOLinkHost(TSoftObjectPtr<UUnrealOLinkHost> InHost);

	//
	// IObjectSource interface
	//

	// unique identifier of this module->interface
	std::string olinkObjectName() override;

	nlohmann::json olinkInvoke(const std::string& methodId, const nlohmann::json& args) override;
	void olinkSetProperty(const std::string& propertyId, const nlohmann::json& value) override;
	void olinkLinked(const std::string& objectId, ApiGear::ObjectLink::IRemoteNode* node) override{};
	void olinkUnlinked(const std::string& objectId) override{};
	nlohmann::json olinkCollectProperties() override;

	// signals
	void OnSig0(ETbEnumEnum0 Param0);
	void OnSig1(ETbEnumEnum1 Param1);
	void OnSig2(ETbEnumEnum2 Param2);
	void OnSig3(ETbEnumEnum3 Param3);

	void OnProp0Changed(ETbEnumEnum0 Prop0);
	void OnProp1Changed(ETbEnumEnum1 Prop1);
	void OnProp2Changed(ETbEnumEnum2 Prop2);
	void OnProp3Changed(ETbEnumEnum3 Prop3);

private:
	/** Holds the service backend, can be exchanged with different implementation during runtime */
	TScriptInterface<ITbEnumEnumInterfaceInterface> BackendService;

	/** The host holding the connections and the registry */
	TSoftObjectPtr<UUnrealOLinkHost> Host;
};
