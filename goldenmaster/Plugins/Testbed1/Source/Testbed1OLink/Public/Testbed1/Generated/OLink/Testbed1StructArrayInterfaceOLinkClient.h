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

#include "Testbed1/Generated/api/AbstractTestbed1StructArrayInterface.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
THIRD_PARTY_INCLUDES_END
#include "OLinkSink.h"
#include "ApiGearConnection.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Templates/PimplPtr.h"
#include "Testbed1StructArrayInterfaceOLinkClient.generated.h"

class Testbed1StructArrayInterfacePropertiesData;
DECLARE_LOG_CATEGORY_EXTERN(LogTestbed1StructArrayInterfaceOLinkClient, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TESTBED1OLINK_API UTestbed1StructArrayInterfaceOLinkClient : public UAbstractTestbed1StructArrayInterface
{
	GENERATED_BODY()
public:
	explicit UTestbed1StructArrayInterfaceOLinkClient();

	// only needed in 4.25 to use TUniquePtr<Testbed1StructArrayInterfacePropertiesData>
	UTestbed1StructArrayInterfaceOLinkClient(FVTableHelper& Helper);
	virtual ~UTestbed1StructArrayInterfaceOLinkClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	TArray<FTestbed1StructBool> GetPropBool() const override;
	void SetPropBool(const TArray<FTestbed1StructBool>& PropBool) override;

	TArray<FTestbed1StructInt> GetPropInt() const override;
	void SetPropInt(const TArray<FTestbed1StructInt>& PropInt) override;

	TArray<FTestbed1StructFloat> GetPropFloat() const override;
	void SetPropFloat(const TArray<FTestbed1StructFloat>& PropFloat) override;

	TArray<FTestbed1StructString> GetPropString() const override;
	void SetPropString(const TArray<FTestbed1StructString>& PropString) override;

	TArray<ETestbed1Enum0> GetPropEnum() const override;
	void SetPropEnum(const TArray<ETestbed1Enum0>& PropEnum) override;

	// operations
	TArray<FTestbed1StructBool> FuncBool(const TArray<FTestbed1StructBool>& ParamBool) override;
	TFuture<TArray<FTestbed1StructBool>> FuncBoolAsync(const TArray<FTestbed1StructBool>& ParamBool) override;

	TArray<FTestbed1StructInt> FuncInt(const TArray<FTestbed1StructInt>& ParamInt) override;
	TFuture<TArray<FTestbed1StructInt>> FuncIntAsync(const TArray<FTestbed1StructInt>& ParamInt) override;

	TArray<FTestbed1StructFloat> FuncFloat(const TArray<FTestbed1StructFloat>& ParamFloat) override;
	TFuture<TArray<FTestbed1StructFloat>> FuncFloatAsync(const TArray<FTestbed1StructFloat>& ParamFloat) override;

	TArray<FTestbed1StructString> FuncString(const TArray<FTestbed1StructString>& ParamString) override;
	TFuture<TArray<FTestbed1StructString>> FuncStringAsync(const TArray<FTestbed1StructString>& ParamString) override;

	TArray<ETestbed1Enum0> FuncEnum(const TArray<ETestbed1Enum0>& ParamEnum) override;
	TFuture<TArray<ETestbed1Enum0>> FuncEnumAsync(const TArray<ETestbed1Enum0>& ParamEnum) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface")
	void UseConnection(TScriptInterface<class IApiGearConnection> InConnection);

	/**
	 * Used when the interface client changes subscription status:
	 * either is linked(ready to use) with server side (true) or it is in unlinked state (false).
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArrayInterface|Remote", DisplayName = "Subscription Status Changed")
	FApiGearRemoteApiSubscriptionStatusChangedDelegateBP _SubscriptionStatusChangedBP;
	FApiGearRemoteApiSubscriptionStatusChangedDelegate _SubscriptionStatusChanged;

	/**
	 * Informs about the subscription state of the interface client.
	 * @return true if the client is subscribed (plugged in the network) and ready to send and receive messages or false if the server cannot be reached.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArrayInterface|Remote")
	bool _IsSubscribed() const;

private:
	void applyState(const nlohmann::json& fields);
	void emitSignal(const std::string& signalName, const nlohmann::json& args);
	std::shared_ptr<FOLinkSink> m_sink;

	// member variable to store the last sent data
	TPimplPtr<Testbed1StructArrayInterfacePropertiesData> _SentData;
	TScriptInterface<class IApiGearConnection> Connection;
};
