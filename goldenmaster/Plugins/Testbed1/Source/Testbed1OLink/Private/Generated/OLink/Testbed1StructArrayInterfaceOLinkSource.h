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

#include "Testbed1/Generated/api/Testbed1StructArrayInterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
THIRD_PARTY_INCLUDES_START
#include "olink/iobjectsource.h"
THIRD_PARTY_INCLUDES_END
#include "OLinkCommon.h"
#include "HAL/Platform.h"

#if !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
#include "OLinkHost.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTestbed1StructArrayInterfaceOLinkSource, Log, All);
/** @brief handles OLink network interactions specific to ITestbed1StructArrayInterfaceInterface */
class Testbed1StructArrayInterfaceOLinkSource : public ApiGear::ObjectLink::IObjectSource
{
public:
	explicit Testbed1StructArrayInterfaceOLinkSource();
	virtual ~Testbed1StructArrayInterfaceOLinkSource() = default;

	/** set the backend service which logic is to be used */
	void setBackendService(TScriptInterface<ITestbed1StructArrayInterfaceInterface> InService);

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
	void OnSigBool(const TArray<FTestbed1StructBool>& ParamBool);
	void OnSigInt(const TArray<FTestbed1StructInt>& ParamInt);
	void OnSigFloat(const TArray<FTestbed1StructFloat>& ParamFloat);
	void OnSigString(const TArray<FTestbed1StructString>& ParamString);

	void OnPropBoolChanged(const TArray<FTestbed1StructBool>& PropBool);
	void OnPropIntChanged(const TArray<FTestbed1StructInt>& PropInt);
	void OnPropFloatChanged(const TArray<FTestbed1StructFloat>& PropFloat);
	void OnPropStringChanged(const TArray<FTestbed1StructString>& PropString);

private:
	/** Holds the service backend, can be exchanged with different implementation during runtime */
	TScriptInterface<ITestbed1StructArrayInterfaceInterface> BackendService;

	/** The host holding the connections and the registry */
	TSoftObjectPtr<UOLinkHost> Host;
};
#else  // !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
class Testbed1StructArrayInterfaceOLinkSource
{
};
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID || PLATFORM_QNX)
