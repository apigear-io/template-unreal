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

#include "Testbed2ManyParamInterfaceInterface.h"
#include "Subsystems/GameInstanceSubsystem.h"
THIRD_PARTY_INCLUDES_START
#include "olink/iobjectsource.h"
THIRD_PARTY_INCLUDES_END
#include "UnrealOLinkHost.h"

class Testbed2ManyParamInterfaceOLinkSource : public ApiGear::ObjectLink::IObjectSource
{
public:
	explicit Testbed2ManyParamInterfaceOLinkSource();
	virtual ~Testbed2ManyParamInterfaceOLinkSource() = default;

	/** set the backend service which logic is to be used */
	void setBackendService(TScriptInterface<ITestbed2ManyParamInterfaceInterface> InService);

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
	void OnSig1(int32 Param1);
	void OnSig2(int32 Param1, int32 Param2);
	void OnSig3(int32 Param1, int32 Param2, int32 Param3);
	void OnSig4(int32 Param1, int32 Param2, int32 Param3, int32 Param4);

	void OnProp1Changed(int32 Prop1);
	void OnProp2Changed(int32 Prop2);
	void OnProp3Changed(int32 Prop3);
	void OnProp4Changed(int32 Prop4);

private:
	/** The connection to the service backend. */
	TScriptInterface<ITestbed2ManyParamInterfaceInterface> BackendService;

	/** The host holding the connections and the registry */
	TSoftObjectPtr<UUnrealOLinkHost> Host;
};
