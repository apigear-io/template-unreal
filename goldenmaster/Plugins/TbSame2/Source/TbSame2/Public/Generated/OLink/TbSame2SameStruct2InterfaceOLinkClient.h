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

#include "AbstractTbSame2SameStruct2Interface.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
THIRD_PARTY_INCLUDES_END
#include "unrealolinksink.h"
#include "ApiGearConnection.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Runtime/Launch/Resources/Version.h"
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
#include "Templates/UniquePtr.h"
#else
#include "Templates/PimplPtr.h"
#endif
#include "TbSame2SameStruct2InterfaceOLinkClient.generated.h"

struct TbSame2SameStruct2InterfacePropertiesData;
DECLARE_LOG_CATEGORY_EXTERN(LogTbSame2SameStruct2InterfaceOLinkClient, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TBSAME2_API UTbSame2SameStruct2InterfaceOLinkClient : public UAbstractTbSame2SameStruct2Interface
{
	GENERATED_BODY()
public:
	explicit UTbSame2SameStruct2InterfaceOLinkClient();

	// only needed in 4.25 to use TUniquePtr<TbSame2SameStruct2InterfacePropertiesData>
	UTbSame2SameStruct2InterfaceOLinkClient(FVTableHelper& Helper);
	virtual ~UTbSame2SameStruct2InterfaceOLinkClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	FTbSame2Struct2 GetProp1_Implementation() const override;
	void SetProp1_Implementation(const FTbSame2Struct2& Prop1) override;

	FTbSame2Struct2 GetProp2_Implementation() const override;
	void SetProp2_Implementation(const FTbSame2Struct2& Prop2) override;

	// operations
	FTbSame2Struct1 Func1_Implementation(const FTbSame2Struct1& Param1) override;

	FTbSame2Struct1 Func2_Implementation(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface")
	void UseConnection(TScriptInterface<class IApiGearConnection> InConnection);

	/**
	 * Used when the interface client changes subscription status:
	 * either is linked(ready to use) with server side (true) or it is in unlinked state (false).
	 */
	UPROPERTY(BlueprintAssignable, Category = "ApiGear|TbSame2|SameStruct2Interface|Remote", DisplayName = "Subscription Status Changed")
	FApiGearRemoteApiSubscriptionStatusChangedDelegate _SubscriptionStatusChanged;

	/**
	 * Informs about the subscription state of the interface client.
	 * @return true if the client is subscribed (plugged in the network) and ready to send and receive messages or false if the server cannot be reached.
	 */
	UFUNCTION(BlueprintCallable, Category = "ApiGear|TbSame2|SameStruct2Interface|Remote")
	bool _IsSubscribed() const;

private:
	void applyState(const nlohmann::json& fields);
	void emitSignal(const std::string& signalName, const nlohmann::json& args);
	std::shared_ptr<FUnrealOLinkSink> m_sink;

	// member variable to store the last sent data
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
	TUniquePtr<TbSame2SameStruct2InterfacePropertiesData> _SentData;
#else
	TPimplPtr<TbSame2SameStruct2InterfacePropertiesData> _SentData;
#endif
	TScriptInterface<class IApiGearConnection> Connection;
};
