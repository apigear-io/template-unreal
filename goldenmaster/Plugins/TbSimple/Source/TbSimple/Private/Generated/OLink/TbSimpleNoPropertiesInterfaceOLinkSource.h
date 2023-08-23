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
#include "Subsystems/GameInstanceSubsystem.h"
THIRD_PARTY_INCLUDES_START
#include "olink/iobjectsource.h"
THIRD_PARTY_INCLUDES_END
#include "UnrealOLinkHost.h"

/// @brief handles OLink network interactions specific to ITbSimpleNoPropertiesInterfaceInterface
class TbSimpleNoPropertiesInterfaceOLinkSource : public ApiGear::ObjectLink::IObjectSource
{
public:
	explicit TbSimpleNoPropertiesInterfaceOLinkSource();
	virtual ~TbSimpleNoPropertiesInterfaceOLinkSource() = default;

	/** set the backend service which logic is to be used */
	void setBackendService(TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> InService);

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
	void OnSigVoid();
	void OnSigBool(bool bParamBool);

private:
	/** Holds the service backend, can be exchanged with different implementation during runtime */
	TScriptInterface<ITbSimpleNoPropertiesInterfaceInterface> BackendService;

	/** The host holding the connections and the registry */
	TSoftObjectPtr<UUnrealOLinkHost> Host;
};
