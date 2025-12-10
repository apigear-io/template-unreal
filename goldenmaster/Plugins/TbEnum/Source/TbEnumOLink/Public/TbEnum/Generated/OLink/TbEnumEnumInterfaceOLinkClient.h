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

#include "TbEnum/Generated/api/AbstractTbEnumEnumInterface.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
THIRD_PARTY_INCLUDES_END
#include "OLinkSink.h"
#include "ApiGearConnection.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Templates/PimplPtr.h"
#include "TbEnumEnumInterfaceOLinkClient.generated.h"

class TbEnumEnumInterfacePropertiesData;
DECLARE_LOG_CATEGORY_EXTERN(LogTbEnumEnumInterfaceOLinkClient, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TBENUMOLINK_API UTbEnumEnumInterfaceOLinkClient : public UAbstractTbEnumEnumInterface
{
	GENERATED_BODY()
public:
	explicit UTbEnumEnumInterfaceOLinkClient();

	// only needed in 4.25 to use TUniquePtr<TbEnumEnumInterfacePropertiesData>
	UTbEnumEnumInterfaceOLinkClient(FVTableHelper& Helper);
	virtual ~UTbEnumEnumInterfaceOLinkClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	ETbEnumEnum0 GetProp0() const override;
	void SetProp0(ETbEnumEnum0 Prop0) override;

	ETbEnumEnum1 GetProp1() const override;
	void SetProp1(ETbEnumEnum1 Prop1) override;

	ETbEnumEnum2 GetProp2() const override;
	void SetProp2(ETbEnumEnum2 Prop2) override;

	ETbEnumEnum3 GetProp3() const override;
	void SetProp3(ETbEnumEnum3 Prop3) override;

	// operations
	ETbEnumEnum0 Func0(ETbEnumEnum0 Param0) override;
	TFuture<ETbEnumEnum0> Func0Async(ETbEnumEnum0 Param0) override;

	ETbEnumEnum1 Func1(ETbEnumEnum1 Param1) override;
	TFuture<ETbEnumEnum1> Func1Async(ETbEnumEnum1 Param1) override;

	ETbEnumEnum2 Func2(ETbEnumEnum2 Param2) override;
	TFuture<ETbEnumEnum2> Func2Async(ETbEnumEnum2 Param2) override;

	ETbEnumEnum3 Func3(ETbEnumEnum3 Param3) override;
	TFuture<ETbEnumEnum3> Func3Async(ETbEnumEnum3 Param3) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface")
	void UseConnection(TScriptInterface<class IApiGearConnection> InConnection);

	/**
	 * Used when the interface client changes subscription status:
	 * either is linked(ready to use) with server side (true) or it is in unlinked state (false).
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbEnum|EnumInterface|Remote", DisplayName = "Subscription Status Changed")
	FApiGearRemoteApiSubscriptionStatusChangedDelegateBP _SubscriptionStatusChangedBP;
	FApiGearRemoteApiSubscriptionStatusChangedDelegate _SubscriptionStatusChanged;

	/**
	 * Informs about the subscription state of the interface client.
	 * @return true if the client is subscribed (plugged in the network) and ready to send and receive messages or false if the server cannot be reached.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbEnum|EnumInterface|Remote")
	bool _IsSubscribed() const;

private:
	void applyState(const nlohmann::json& fields);
	void emitSignal(const std::string& signalName, const nlohmann::json& args);
	std::shared_ptr<FOLinkSink> m_sink;

	// member variable to store the last sent data
	TPimplPtr<TbEnumEnumInterfacePropertiesData> _SentData;
	TScriptInterface<class IApiGearConnection> Connection;
};
