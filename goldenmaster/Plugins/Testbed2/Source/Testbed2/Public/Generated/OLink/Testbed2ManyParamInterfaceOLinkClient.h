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

#include "Testbed2ManyParamInterfaceInterface.h"
THIRD_PARTY_INCLUDES_START
#include "olink/clientnode.h"
THIRD_PARTY_INCLUDES_END
#include "unrealolinksink.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "Runtime/Launch/Resources/Version.h"
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
#include "Templates/UniquePtr.h"
#else
#include "Templates/PimplPtr.h"
#endif
#include "Testbed2ManyParamInterfaceOLinkClient.generated.h"

struct Testbed2ManyParamInterfacePropertiesData;
DECLARE_LOG_CATEGORY_EXTERN(LogTestbed2ManyParamInterfaceOLinkClient, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TESTBED2_API UTestbed2ManyParamInterfaceOLinkClient : public UAbstractTestbed2ManyParamInterface
{
	GENERATED_BODY()
public:
	explicit UTestbed2ManyParamInterfaceOLinkClient();

	// only needed in 4.25 to use TUniquePtr<Testbed2ManyParamInterfacePropertiesData>
	UTestbed2ManyParamInterfaceOLinkClient(FVTableHelper& Helper);
	virtual ~UTestbed2ManyParamInterfaceOLinkClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	int32 GetProp1_Implementation() const override;
	void SetProp1_Implementation(int32 Prop1) override;

	int32 GetProp2_Implementation() const override;
	void SetProp2_Implementation(int32 Prop2) override;

	int32 GetProp3_Implementation() const override;
	void SetProp3_Implementation(int32 Prop3) override;

	int32 GetProp4_Implementation() const override;
	void SetProp4_Implementation(int32 Prop4) override;

	// operations
	int32 Func1_Implementation(int32 Param1) override;

	int32 Func2_Implementation(int32 Param1, int32 Param2) override;

	int32 Func3_Implementation(int32 Param1, int32 Param2, int32 Param3) override;

	int32 Func4_Implementation(int32 Param1, int32 Param2, int32 Param3, int32 Param4) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed2|ManyParamInterface")
	void UseConnection(TScriptInterface<class IApiGearConnection> InConnection);

private:
	void applyState(const nlohmann::json& fields);
	void emitSignal(const std::string& signalName, const nlohmann::json& args);
	std::shared_ptr<FUnrealOLinkSink> m_sink;

	// member variable to store the last sent data
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
	TUniquePtr<Testbed2ManyParamInterfacePropertiesData> _SentData;
#else
	TPimplPtr<Testbed2ManyParamInterfacePropertiesData> _SentData;
#endif
	TScriptInterface<class IApiGearConnection> Connection;
};
