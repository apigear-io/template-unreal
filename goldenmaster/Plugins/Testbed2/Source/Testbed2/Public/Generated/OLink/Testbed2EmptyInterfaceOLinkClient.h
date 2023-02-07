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

#include "Testbed2EmptyInterfaceInterface.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
THIRD_PARTY_INCLUDES_END
#include "unrealolinksink.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Testbed2EmptyInterfaceOLinkClient.generated.h"

UCLASS(BlueprintType)
class TESTBED2_API UTestbed2EmptyInterfaceOLinkClient : public UGameInstanceSubsystem, public ITestbed2EmptyInterfaceInterface
{
	GENERATED_BODY()
public:
	explicit UTestbed2EmptyInterfaceOLinkClient();
	virtual ~UTestbed2EmptyInterfaceOLinkClient() = default;

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// signals
	// properties
	// operations

protected:
	// signals

private:
	void applyState(const nlohmann::json& fields);
	void emitSignal(const std::string& signalId, const nlohmann::json& args);
	std::shared_ptr<FUnrealOLinkSink> m_sink;

	// properties - local copy
};
