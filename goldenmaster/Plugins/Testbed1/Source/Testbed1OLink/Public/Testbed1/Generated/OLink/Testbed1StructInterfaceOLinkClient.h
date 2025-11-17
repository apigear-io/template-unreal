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

#include "Testbed1/Generated/api/AbstractTestbed1StructInterface.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
THIRD_PARTY_INCLUDES_END
#include "OLinkSink.h"
#include "ApiGearConnection.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Templates/PimplPtr.h"
#include "Testbed1StructInterfaceOLinkClient.generated.h"

struct Testbed1StructInterfacePropertiesData;
DECLARE_LOG_CATEGORY_EXTERN(LogTestbed1StructInterfaceOLinkClient, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TESTBED1OLINK_API UTestbed1StructInterfaceOLinkClient : public UAbstractTestbed1StructInterface
{
	GENERATED_BODY()
public:
	explicit UTestbed1StructInterfaceOLinkClient();

	// only needed in 4.25 to use TUniquePtr<Testbed1StructInterfacePropertiesData>
	UTestbed1StructInterfaceOLinkClient(FVTableHelper& Helper);
	virtual ~UTestbed1StructInterfaceOLinkClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	FTestbed1StructBool GetPropBool() const override;
	void SetPropBool(const FTestbed1StructBool& PropBool) override;

	FTestbed1StructInt GetPropInt() const override;
	void SetPropInt(const FTestbed1StructInt& PropInt) override;

	FTestbed1StructFloat GetPropFloat() const override;
	void SetPropFloat(const FTestbed1StructFloat& PropFloat) override;

	FTestbed1StructString GetPropString() const override;
	void SetPropString(const FTestbed1StructString& PropString) override;

	// operations
	FTestbed1StructBool FuncBool(const FTestbed1StructBool& ParamBool) override;
	TFuture<FTestbed1StructBool> FuncBoolAsync(const FTestbed1StructBool& ParamBool) override;

	FTestbed1StructInt FuncInt(const FTestbed1StructInt& ParamInt) override;
	TFuture<FTestbed1StructInt> FuncIntAsync(const FTestbed1StructInt& ParamInt) override;

	FTestbed1StructFloat FuncFloat(const FTestbed1StructFloat& ParamFloat) override;
	TFuture<FTestbed1StructFloat> FuncFloatAsync(const FTestbed1StructFloat& ParamFloat) override;

	FTestbed1StructString FuncString(const FTestbed1StructString& ParamString) override;
	TFuture<FTestbed1StructString> FuncStringAsync(const FTestbed1StructString& ParamString) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface")
	void UseConnection(TScriptInterface<class IApiGearConnection> InConnection);

	/**
	 * Used when the interface client changes subscription status:
	 * either is linked(ready to use) with server side (true) or it is in unlinked state (false).
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructInterface|Remote", DisplayName = "Subscription Status Changed")
	FApiGearRemoteApiSubscriptionStatusChangedDelegateBP _SubscriptionStatusChangedBP;
	FApiGearRemoteApiSubscriptionStatusChangedDelegate _SubscriptionStatusChanged;

	/**
	 * Informs about the subscription state of the interface client.
	 * @return true if the client is subscribed (plugged in the network) and ready to send and receive messages or false if the server cannot be reached.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface|Remote")
	bool _IsSubscribed() const;

private:
	void applyState(const nlohmann::json& fields);
	void emitSignal(const std::string& signalName, const nlohmann::json& args);
	std::shared_ptr<FOLinkSink> m_sink;

	// member variable to store the last sent data
	TPimplPtr<Testbed1StructInterfacePropertiesData> _SentData;
	TScriptInterface<class IApiGearConnection> Connection;
};
