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

#include "Generated/api/TbSimpleSimpleArrayInterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
THIRD_PARTY_INCLUDES_START
#include "olink/iobjectsource.h"
THIRD_PARTY_INCLUDES_END
#include "HAL/Platform.h"

#if !(PLATFORM_IOS || PLATFORM_ANDROID)
#include "OLinkHost.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTbSimpleSimpleArrayInterfaceOLinkSource, Log, All);
/** @brief handles OLink network interactions specific to ITbSimpleSimpleArrayInterfaceInterface */
class TbSimpleSimpleArrayInterfaceOLinkSource : public ApiGear::ObjectLink::IObjectSource
{
public:
	explicit TbSimpleSimpleArrayInterfaceOLinkSource();
	virtual ~TbSimpleSimpleArrayInterfaceOLinkSource() = default;

	/** set the backend service which logic is to be used */
	void setBackendService(TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> InService);

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
	void OnSigBool(const TArray<bool>& ParamBool);
	void OnSigInt(const TArray<int32>& ParamInt);
	void OnSigInt32(const TArray<int32>& ParamInt32);
	void OnSigInt64(const TArray<int64>& ParamInt64);
	void OnSigFloat(const TArray<float>& ParamFloat);
	void OnSigFloat32(const TArray<float>& ParamFloa32);
	void OnSigFloat64(const TArray<double>& ParamFloat64);
	void OnSigString(const TArray<FString>& ParamString);

	void OnPropBoolChanged(const TArray<bool>& PropBool);
	void OnPropIntChanged(const TArray<int32>& PropInt);
	void OnPropInt32Changed(const TArray<int32>& PropInt32);
	void OnPropInt64Changed(const TArray<int64>& PropInt64);
	void OnPropFloatChanged(const TArray<float>& PropFloat);
	void OnPropFloat32Changed(const TArray<float>& PropFloat32);
	void OnPropFloat64Changed(const TArray<double>& PropFloat64);
	void OnPropStringChanged(const TArray<FString>& PropString);
	void OnPropReadOnlyStringChanged(const FString& PropReadOnlyString);

private:
	/** Holds the service backend, can be exchanged with different implementation during runtime */
	TScriptInterface<ITbSimpleSimpleArrayInterfaceInterface> BackendService;

	/** The host holding the connections and the registry */
	TSoftObjectPtr<UOLinkHost> Host;
};
#else  // !(PLATFORM_IOS || PLATFORM_ANDROID)
class TbSimpleSimpleArrayInterfaceOLinkSource
{
};
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID)
