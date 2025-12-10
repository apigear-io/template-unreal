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

class TbSimpleSimpleInterfacePropertiesData;
DECLARE_LOG_CATEGORY_EXTERN(LogTbSimpleSimpleInterfaceOLinkClient, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TBSIMPLEOLINK_API UTbSimpleSimpleInterfaceOLinkClient : public UAbstractTbSimpleSimpleInterface
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
	bool GetPropBool() const override;
	void SetPropBool(bool bPropBool) override;

	int32 GetPropInt() const override;
	void SetPropInt(int32 PropInt) override;

	int32 GetPropInt32() const override;
	void SetPropInt32(int32 PropInt32) override;

	int64 GetPropInt64() const override;
	void SetPropInt64(int64 PropInt64) override;

	float GetPropFloat() const override;
	void SetPropFloat(float PropFloat) override;

	float GetPropFloat32() const override;
	void SetPropFloat32(float PropFloat32) override;

	double GetPropFloat64() const override;
	void SetPropFloat64(double PropFloat64) override;

	FString GetPropString() const override;
	void SetPropString(const FString& PropString) override;

	// operations
	void FuncNoReturnValue(bool bParamBool) override;

	bool FuncNoParams() override;
	TFuture<bool> FuncNoParamsAsync() override;

	bool FuncBool(bool bParamBool) override;
	TFuture<bool> FuncBoolAsync(bool bParamBool) override;

	int32 FuncInt(int32 ParamInt) override;
	TFuture<int32> FuncIntAsync(int32 ParamInt) override;

	int32 FuncInt32(int32 ParamInt32) override;
	TFuture<int32> FuncInt32Async(int32 ParamInt32) override;

	int64 FuncInt64(int64 ParamInt64) override;
	TFuture<int64> FuncInt64Async(int64 ParamInt64) override;

	float FuncFloat(float ParamFloat) override;
	TFuture<float> FuncFloatAsync(float ParamFloat) override;

	float FuncFloat32(float ParamFloat32) override;
	TFuture<float> FuncFloat32Async(float ParamFloat32) override;

	double FuncFloat64(double ParamFloat) override;
	TFuture<double> FuncFloat64Async(double ParamFloat) override;

	FString FuncString(const FString& ParamString) override;
	TFuture<FString> FuncStringAsync(const FString& ParamString) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleInterface")
	void UseConnection(TScriptInterface<class IApiGearConnection> InConnection);

	/**
	 * Used when the interface client changes subscription status:
	 * either is linked(ready to use) with server side (true) or it is in unlinked state (false).
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleInterface|Remote", DisplayName = "Subscription Status Changed")
	FApiGearRemoteApiSubscriptionStatusChangedDelegateBP _SubscriptionStatusChangedBP;
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
