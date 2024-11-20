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

#include "Testbed2NestedStruct1InterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
THIRD_PARTY_INCLUDES_START
#include "olink/iobjectsource.h"
THIRD_PARTY_INCLUDES_END
#include "HAL/Platform.h"

#if !(PLATFORM_IOS || PLATFORM_ANDROID)
#include "OLinkHost.h"

DECLARE_LOG_CATEGORY_EXTERN(LogTestbed2NestedStruct1InterfaceOLinkSource, Log, All);
/// @brief handles OLink network interactions specific to ITestbed2NestedStruct1InterfaceInterface
class Testbed2NestedStruct1InterfaceOLinkSource : public ApiGear::ObjectLink::IObjectSource
{
public:
	explicit Testbed2NestedStruct1InterfaceOLinkSource();
	virtual ~Testbed2NestedStruct1InterfaceOLinkSource() = default;

	/** set the backend service which logic is to be used */
	void setBackendService(TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> InService);

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
	void OnSig1(const FTestbed2NestedStruct1& Param1);

	void OnProp1Changed(const FTestbed2NestedStruct1& Prop1);

private:
	/** Holds the service backend, can be exchanged with different implementation during runtime */
	TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> BackendService;

	/** The host holding the connections and the registry */
	TSoftObjectPtr<UOLinkHost> Host;
};
#else  // !(PLATFORM_IOS || PLATFORM_ANDROID)
class Testbed2NestedStruct1InterfaceOLinkSource
{
};
#endif // !(PLATFORM_IOS || PLATFORM_ANDROID)
