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

#include "TbSimple/Generated/api/AbstractTbSimpleSimpleArrayInterface.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
THIRD_PARTY_INCLUDES_END
#include "OLinkSink.h"
#include "ApiGearConnection.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Runtime/Launch/Resources/Version.h"
#include "Templates/PimplPtr.h"
#include "TbSimpleSimpleArrayInterfaceOLinkClient.generated.h"

struct TbSimpleSimpleArrayInterfacePropertiesData;
DECLARE_LOG_CATEGORY_EXTERN(LogTbSimpleSimpleArrayInterfaceOLinkClient, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TBSIMPLEOLINK_API UTbSimpleSimpleArrayInterfaceOLinkClient : public UAbstractTbSimpleSimpleArrayInterface
{
	GENERATED_BODY()
public:
	explicit UTbSimpleSimpleArrayInterfaceOLinkClient();

	// only needed in 4.25 to use TUniquePtr<TbSimpleSimpleArrayInterfacePropertiesData>
	UTbSimpleSimpleArrayInterfaceOLinkClient(FVTableHelper& Helper);
	virtual ~UTbSimpleSimpleArrayInterfaceOLinkClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	TArray<bool> GetPropBool() const override;
	void SetPropBool(const TArray<bool>& PropBool) override;

	TArray<int32> GetPropInt() const override;
	void SetPropInt(const TArray<int32>& PropInt) override;

	TArray<int32> GetPropInt32() const override;
	void SetPropInt32(const TArray<int32>& PropInt32) override;

	TArray<int64> GetPropInt64() const override;
	void SetPropInt64(const TArray<int64>& PropInt64) override;

	TArray<float> GetPropFloat() const override;
	void SetPropFloat(const TArray<float>& PropFloat) override;

	TArray<float> GetPropFloat32() const override;
	void SetPropFloat32(const TArray<float>& PropFloat32) override;

	TArray<double> GetPropFloat64() const override;
	void SetPropFloat64(const TArray<double>& PropFloat64) override;

	TArray<FString> GetPropString() const override;
	void SetPropString(const TArray<FString>& PropString) override;

	FString GetPropReadOnlyString() const override;

	// operations
	TArray<bool> FuncBool(const TArray<bool>& ParamBool) override;
	TFuture<TArray<bool>> FuncBoolAsync(const TArray<bool>& ParamBool) override;

	TArray<int32> FuncInt(const TArray<int32>& ParamInt) override;
	TFuture<TArray<int32>> FuncIntAsync(const TArray<int32>& ParamInt) override;

	TArray<int32> FuncInt32(const TArray<int32>& ParamInt32) override;
	TFuture<TArray<int32>> FuncInt32Async(const TArray<int32>& ParamInt32) override;

	TArray<int64> FuncInt64(const TArray<int64>& ParamInt64) override;
	TFuture<TArray<int64>> FuncInt64Async(const TArray<int64>& ParamInt64) override;

	TArray<float> FuncFloat(const TArray<float>& ParamFloat) override;
	TFuture<TArray<float>> FuncFloatAsync(const TArray<float>& ParamFloat) override;

	TArray<float> FuncFloat32(const TArray<float>& ParamFloat32) override;
	TFuture<TArray<float>> FuncFloat32Async(const TArray<float>& ParamFloat32) override;

	TArray<double> FuncFloat64(const TArray<double>& ParamFloat) override;
	TFuture<TArray<double>> FuncFloat64Async(const TArray<double>& ParamFloat) override;

	TArray<FString> FuncString(const TArray<FString>& ParamString) override;
	TFuture<TArray<FString>> FuncStringAsync(const TArray<FString>& ParamString) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface")
	void UseConnection(TScriptInterface<class IApiGearConnection> InConnection);

	/**
	 * Used when the interface client changes subscription status:
	 * either is linked(ready to use) with server side (true) or it is in unlinked state (false).
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Remote", DisplayName = "Subscription Status Changed")
	FApiGearRemoteApiSubscriptionStatusChangedDelegateBP _SubscriptionStatusChangedBP;
	FApiGearRemoteApiSubscriptionStatusChangedDelegate _SubscriptionStatusChanged;

	/**
	 * Informs about the subscription state of the interface client.
	 * @return true if the client is subscribed (plugged in the network) and ready to send and receive messages or false if the server cannot be reached.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSimple|SimpleArrayInterface|Remote")
	bool _IsSubscribed() const;

private:
	void applyState(const nlohmann::json& fields);
	void emitSignal(const std::string& signalName, const nlohmann::json& args);
	std::shared_ptr<FOLinkSink> m_sink;

	// member variable to store the last sent data
	TPimplPtr<TbSimpleSimpleArrayInterfacePropertiesData> _SentData;
	TScriptInterface<class IApiGearConnection> Connection;
};
