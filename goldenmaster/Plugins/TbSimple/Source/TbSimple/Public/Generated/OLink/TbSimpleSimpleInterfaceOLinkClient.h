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

#include "TbSimple/Generated/api/AbstractTbSimpleSimpleInterface.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
THIRD_PARTY_INCLUDES_END
#include "OLinkSink.h"
#include "ApiGearConnection.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Templates/PimplPtr.h"
#include "TbSimpleSimpleInterfaceOLinkClient.generated.h"

struct TbSimpleSimpleInterfacePropertiesData;
DECLARE_LOG_CATEGORY_EXTERN(LogTbSimpleSimpleInterfaceOLinkClient, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TBSIMPLE_API UTbSimpleSimpleInterfaceOLinkClient : public UAbstractTbSimpleSimpleInterface
{
	GENERATED_BODY()
public:
	explicit UTbSimpleSimpleInterfaceOLinkClient();

	// only needed in 4.25 to use TUniquePtr<TbSimpleSimpleInterfacePropertiesData>
	UTbSimpleSimpleInterfaceOLinkClient(FVTableHelper& Helper);
	virtual ~UTbSimpleSimpleInterfaceOLinkClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	bool GetPropBool_Implementation() const override;
	void SetPropBool_Implementation(bool bPropBool) override;

	int32 GetPropInt_Implementation() const override;
	void SetPropInt_Implementation(int32 PropInt) override;

	int32 GetPropInt32_Implementation() const override;
	void SetPropInt32_Implementation(int32 PropInt32) override;

	int64 GetPropInt64_Implementation() const override;
	void SetPropInt64_Implementation(int64 PropInt64) override;

	float GetPropFloat_Implementation() const override;
	void SetPropFloat_Implementation(float PropFloat) override;

	float GetPropFloat32_Implementation() const override;
	void SetPropFloat32_Implementation(float PropFloat32) override;

	double GetPropFloat64_Implementation() const override;
	void SetPropFloat64_Implementation(double PropFloat64) override;

	FString GetPropString_Implementation() const override;
	void SetPropString_Implementation(const FString& PropString) override;

	// operations
	void FuncNoReturnValue_Implementation(bool bParamBool) override;

	bool FuncBool_Implementation(bool bParamBool) override;

	int32 FuncInt_Implementation(int32 ParamInt) override;

	int32 FuncInt32_Implementation(int32 ParamInt32) override;

	int64 FuncInt64_Implementation(int64 ParamInt64) override;

	float FuncFloat_Implementation(float ParamFloat) override;

	float FuncFloat32_Implementation(float ParamFloat32) override;

	double FuncFloat64_Implementation(double ParamFloat) override;

	FString FuncString_Implementation(const FString& ParamString) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	void UseConnection(TScriptInterface<class IApiGearConnection> InConnection);

	/**
	 * Used when the interface client changes subscription status:
	 * either is linked(ready to use) with server side (true) or it is in unlinked state (false).
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface|Remote", DisplayName = "Subscription Status Changed")
	FApiGearRemoteApiSubscriptionStatusChangedDelegate _SubscriptionStatusChanged;

	/**
	 * Informs about the subscription state of the interface client.
	 * @return true if the client is subscribed (plugged in the network) and ready to send and receive messages or false if the server cannot be reached.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface|Remote")
	bool _IsSubscribed() const;

private:
	void applyState(const nlohmann::json& fields);
	void emitSignal(const std::string& signalName, const nlohmann::json& args);
	std::shared_ptr<FOLinkSink> m_sink;

	// member variable to store the last sent data
	TPimplPtr<TbSimpleSimpleInterfacePropertiesData> _SentData;
	TScriptInterface<class IApiGearConnection> Connection;
};
