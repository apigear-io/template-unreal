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

#include "Generated/api/AbstractTbNamesNamEs.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
THIRD_PARTY_INCLUDES_END
#include "OLinkSink.h"
#include "ApiGearConnection.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Runtime/Launch/Resources/Version.h"
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
#include "Templates/UniquePtr.h"
#else
#include "Templates/PimplPtr.h"
#endif
#include "TbNamesNamEsOLinkClient.generated.h"

struct TbNamesNamEsPropertiesData;
DECLARE_LOG_CATEGORY_EXTERN(LogTbNamesNamEsOLinkClient, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TBNAMES_API UTbNamesNamEsOLinkClient : public UAbstractTbNamesNamEs
{
	GENERATED_BODY()
public:
	explicit UTbNamesNamEsOLinkClient();

	// only needed in 4.25 to use TUniquePtr<TbNamesNamEsPropertiesData>
	UTbNamesNamEsOLinkClient(FVTableHelper& Helper);
	virtual ~UTbNamesNamEsOLinkClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	bool GetSwitch_Implementation() const override;
	void SetSwitch_Implementation(bool bSwitch) override;

	int32 GetSomeProperty_Implementation() const override;
	void SetSomeProperty_Implementation(int32 SomeProperty) override;

	int32 GetSomePoperty2_Implementation() const override;
	void SetSomePoperty2_Implementation(int32 SomePoperty2) override;

	// operations
	void SomeFunction_Implementation(bool bSomeParam) override;

	void SomeFunction2_Implementation(bool bSomeParam) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs")
	void UseConnection(TScriptInterface<class IApiGearConnection> InConnection);

	/**
	 * Used when the interface client changes subscription status:
	 * either is linked(ready to use) with server side (true) or it is in unlinked state (false).
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbNames|NamEs|Remote", DisplayName = "Subscription Status Changed")
	FApiGearRemoteApiSubscriptionStatusChangedDelegate _SubscriptionStatusChanged;

	/**
	 * Informs about the subscription state of the interface client.
	 * @return true if the client is subscribed (plugged in the network) and ready to send and receive messages or false if the server cannot be reached.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbNames|NamEs|Remote")
	bool _IsSubscribed() const;

private:
	void applyState(const nlohmann::json& fields);
	void emitSignal(const std::string& signalName, const nlohmann::json& args);
	std::shared_ptr<FOLinkSink> m_sink;

	// member variable to store the last sent data
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
	TUniquePtr<TbNamesNamEsPropertiesData> _SentData;
#else
	TPimplPtr<TbNamesNamEsPropertiesData> _SentData;
#endif
	TScriptInterface<class IApiGearConnection> Connection;
};
