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

#include "Generated/api/AbstractTestbed1StructArray2Interface.h"
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
#include "Testbed1StructArray2InterfaceOLinkClient.generated.h"

struct Testbed1StructArray2InterfacePropertiesData;
DECLARE_LOG_CATEGORY_EXTERN(LogTestbed1StructArray2InterfaceOLinkClient, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TESTBED1_API UTestbed1StructArray2InterfaceOLinkClient : public UAbstractTestbed1StructArray2Interface
{
	GENERATED_BODY()
public:
	explicit UTestbed1StructArray2InterfaceOLinkClient();

	// only needed in 4.25 to use TUniquePtr<Testbed1StructArray2InterfacePropertiesData>
	UTestbed1StructArray2InterfaceOLinkClient(FVTableHelper& Helper);
	virtual ~UTestbed1StructArray2InterfaceOLinkClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	FTestbed1StructBoolWithArray GetPropBool_Implementation() const override;
	void SetPropBool_Implementation(const FTestbed1StructBoolWithArray& PropBool) override;

	FTestbed1StructIntWithArray GetPropInt_Implementation() const override;
	void SetPropInt_Implementation(const FTestbed1StructIntWithArray& PropInt) override;

	FTestbed1StructFloatWithArray GetPropFloat_Implementation() const override;
	void SetPropFloat_Implementation(const FTestbed1StructFloatWithArray& PropFloat) override;

	FTestbed1StructStringWithArray GetPropString_Implementation() const override;
	void SetPropString_Implementation(const FTestbed1StructStringWithArray& PropString) override;

	FTestbed1StructEnumWithArray GetPropEnum_Implementation() const override;
	void SetPropEnum_Implementation(const FTestbed1StructEnumWithArray& PropEnum) override;

	// operations
	TArray<FTestbed1StructBool> FuncBool_Implementation(const FTestbed1StructBoolWithArray& ParamBool) override;

	TArray<FTestbed1StructInt> FuncInt_Implementation(const FTestbed1StructIntWithArray& ParamInt) override;

	TArray<FTestbed1StructFloat> FuncFloat_Implementation(const FTestbed1StructFloatWithArray& ParamFloat) override;

	TArray<FTestbed1StructString> FuncString_Implementation(const FTestbed1StructStringWithArray& ParamString) override;

	TArray<ETestbed1Enum0> FuncEnum_Implementation(const FTestbed1StructEnumWithArray& ParamEnum) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface")
	void UseConnection(TScriptInterface<class IApiGearConnection> InConnection);

	/**
	 * Used when the interface client changes subscription status:
	 * either is linked(ready to use) with server side (true) or it is in unlinked state (false).
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Testbed1|StructArray2Interface|Remote", DisplayName = "Subscription Status Changed")
	FApiGearRemoteApiSubscriptionStatusChangedDelegate _SubscriptionStatusChanged;

	/**
	 * Informs about the subscription state of the interface client.
	 * @return true if the client is subscribed (plugged in the network) and ready to send and receive messages or false if the server cannot be reached.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructArray2Interface|Remote")
	bool _IsSubscribed() const;

private:
	void applyState(const nlohmann::json& fields);
	void emitSignal(const std::string& signalName, const nlohmann::json& args);
	std::shared_ptr<FOLinkSink> m_sink;

	// member variable to store the last sent data
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
	TUniquePtr<Testbed1StructArray2InterfacePropertiesData> _SentData;
#else
	TPimplPtr<Testbed1StructArray2InterfacePropertiesData> _SentData;
#endif
	TScriptInterface<class IApiGearConnection> Connection;
};
