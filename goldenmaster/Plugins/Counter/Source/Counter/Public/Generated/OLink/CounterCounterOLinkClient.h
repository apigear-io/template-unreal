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

#include "Counter/Generated/api/AbstractCounterCounter.h"
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
#include "CounterCounterOLinkClient.generated.h"

struct CounterCounterPropertiesData;
DECLARE_LOG_CATEGORY_EXTERN(LogCounterCounterOLinkClient, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class COUNTER_API UCounterCounterOLinkClient : public UAbstractCounterCounter
{
	GENERATED_BODY()
public:
	explicit UCounterCounterOLinkClient();

	// only needed in 4.25 to use TUniquePtr<CounterCounterPropertiesData>
	UCounterCounterOLinkClient(FVTableHelper& Helper);
	virtual ~UCounterCounterOLinkClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	FCustomTypesVector3D GetVector_Implementation() const override;
	void SetVector_Implementation(const FCustomTypesVector3D& Vector) override;

	FVector GetExternVector_Implementation() const override;
	void SetExternVector_Implementation(const FVector& ExternVector) override;

	TArray<FCustomTypesVector3D> GetVectorArray_Implementation() const override;
	void SetVectorArray_Implementation(const TArray<FCustomTypesVector3D>& VectorArray) override;

	TArray<FVector> GetExternVectorArray_Implementation() const override;
	void SetExternVectorArray_Implementation(const TArray<FVector>& ExternVectorArray) override;

	// operations
	FVector Increment_Implementation(const FVector& Vec) override;

	TArray<FVector> IncrementArray_Implementation(const TArray<FVector>& Vec) override;

	FCustomTypesVector3D Decrement_Implementation(const FCustomTypesVector3D& Vec) override;

	TArray<FCustomTypesVector3D> DecrementArray_Implementation(const TArray<FCustomTypesVector3D>& Vec) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter")
	void UseConnection(TScriptInterface<class IApiGearConnection> InConnection);

	/**
	 * Used when the interface client changes subscription status:
	 * either is linked(ready to use) with server side (true) or it is in unlinked state (false).
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|Counter|Counter|Remote", DisplayName = "Subscription Status Changed")
	FApiGearRemoteApiSubscriptionStatusChangedDelegate _SubscriptionStatusChanged;

	/**
	 * Informs about the subscription state of the interface client.
	 * @return true if the client is subscribed (plugged in the network) and ready to send and receive messages or false if the server cannot be reached.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|Counter|Counter|Remote")
	bool _IsSubscribed() const;

private:
	void applyState(const nlohmann::json& fields);
	void emitSignal(const std::string& signalName, const nlohmann::json& args);
	std::shared_ptr<FOLinkSink> m_sink;

	// member variable to store the last sent data
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
	TUniquePtr<CounterCounterPropertiesData> _SentData;
#else
	TPimplPtr<CounterCounterPropertiesData> _SentData;
#endif
	TScriptInterface<class IApiGearConnection> Connection;
};
