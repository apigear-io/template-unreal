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

#include "TbSimpleSimpleInterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
THIRD_PARTY_INCLUDES_START
#include "olink/iobjectsource.h"
THIRD_PARTY_INCLUDES_END
#include "OLinkHost.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbSimpleSimpleInterfaceOLinkSource, Log, All);
/// @brief handles OLink network interactions specific to ITbSimpleSimpleInterfaceInterface
class TbSimpleSimpleInterfaceOLinkSource : public ApiGear::ObjectLink::IObjectSource
{
public:
	explicit TbSimpleSimpleInterfaceOLinkSource();
	virtual ~TbSimpleSimpleInterfaceOLinkSource() = default;

	/** set the backend service which logic is to be used */
	void setBackendService(TScriptInterface<ITbSimpleSimpleInterfaceInterface> InService);

	/** set the OLink host to be used */
	void setOLinkHost(TSoftObjectPtr<UOLinkHost> InHost);

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
	void OnSigInt(int32 ParamInt);
	void OnSigInt32(int32 ParamInt32);
	void OnSigInt64(int64 ParamInt64);
	void OnSigFloat(float ParamFloat);
	void OnSigFloat32(float ParamFloa32);
	void OnSigFloat64(double ParamFloat64);
	void OnSigString(const FString& ParamString);

	void OnPropBoolChanged(bool bPropBool);
	void OnPropIntChanged(int32 PropInt);
	void OnPropInt32Changed(int32 PropInt32);
	void OnPropInt64Changed(int64 PropInt64);
	void OnPropFloatChanged(float PropFloat);
	void OnPropFloat32Changed(float PropFloat32);
	void OnPropFloat64Changed(double PropFloat64);
	void OnPropStringChanged(const FString& PropString);
	void OnPropReadOnlyStringChanged(const FString& PropReadOnlyString);

private:
	/** Holds the service backend, can be exchanged with different implementation during runtime */
	TScriptInterface<ITbSimpleSimpleInterfaceInterface> BackendService;

	/** The host holding the connections and the registry */
	TSoftObjectPtr<UOLinkHost> Host;
};
