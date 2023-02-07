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

#include "Testbed2NoPropertyInterfaceInterface.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
THIRD_PARTY_INCLUDES_END
#include "unrealolinksink.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Testbed2NoPropertyInterfaceOLinkClient.generated.h"

UCLASS(BlueprintType)
class TESTBED2_API UTestbed2NoPropertyInterfaceOLinkClient : public UGameInstanceSubsystem, public ITestbed2NoPropertyInterfaceInterface
{
	GENERATED_BODY()
public:
	explicit UTestbed2NoPropertyInterfaceOLinkClient();
	virtual ~UTestbed2NoPropertyInterfaceOLinkClient() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// signals
	FTestbed2NoPropertyInterfaceSig1Delegate Sig1Signal;
	FTestbed2NoPropertyInterfaceSig1Delegate& GetSig1SignalDelegate() override;

	// properties
	// operations
	void Func1Async_Implementation(UObject* WorldContextObject, FLatentActionInfo LatentInfo, FTestbed2NestedStruct1& Result, const FTestbed2NestedStruct1& Param1) override{};
	FTestbed2NestedStruct1 Func1_Implementation(const FTestbed2NestedStruct1& Param1) override;

protected:
	// signals
	void BroadcastSig1_Implementation(const FTestbed2NestedStruct1& Param1) override;

private:
	void applyState(const nlohmann::json& fields);
	void emitSignal(const std::string& signalId, const nlohmann::json& args);
	std::shared_ptr<FUnrealOLinkSink> m_sink;

	// properties - local copy
};