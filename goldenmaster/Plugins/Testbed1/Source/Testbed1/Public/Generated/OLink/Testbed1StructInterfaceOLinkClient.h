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

#include "Testbed1StructInterfaceInterface.h"
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
#include "Testbed1StructInterfaceOLinkClient.generated.h"

struct Testbed1StructInterfacePropertiesData;
DECLARE_LOG_CATEGORY_EXTERN(LogTestbed1StructInterfaceOLinkClient, Log, All);

UCLASS(NotBlueprintable, BlueprintType)
class TESTBED1_API UTestbed1StructInterfaceOLinkClient : public UAbstractTestbed1StructInterface
{
	GENERATED_BODY()
public:
	explicit UTestbed1StructInterfaceOLinkClient();

	// only needed in 4.25 to use TUniquePtr<Testbed1StructInterfacePropertiesData>
	UTestbed1StructInterfaceOLinkClient(FVTableHelper& Helper);
	virtual ~UTestbed1StructInterfaceOLinkClient();

	// subsystem
	void Initialize(FSubsystemCollectionBase& Collection) override;
	void Deinitialize() override;

	// properties
	FTestbed1StructBool GetPropBool_Implementation() const override;
	void SetPropBool_Implementation(const FTestbed1StructBool& PropBool) override;

	FTestbed1StructInt GetPropInt_Implementation() const override;
	void SetPropInt_Implementation(const FTestbed1StructInt& PropInt) override;

	FTestbed1StructFloat GetPropFloat_Implementation() const override;
	void SetPropFloat_Implementation(const FTestbed1StructFloat& PropFloat) override;

	FTestbed1StructString GetPropString_Implementation() const override;
	void SetPropString_Implementation(const FTestbed1StructString& PropString) override;

	// operations
	FTestbed1StructBool FuncBool_Implementation(const FTestbed1StructBool& ParamBool) override;

	FTestbed1StructBool FuncInt_Implementation(const FTestbed1StructInt& ParamInt) override;

	FTestbed1StructFloat FuncFloat_Implementation(const FTestbed1StructFloat& ParamFloat) override;

	FTestbed1StructString FuncString_Implementation(const FTestbed1StructString& ParamString) override;

	UFUNCTION(BlueprintCallable, Category = "ApiGear|Testbed1|StructInterface")
	void UseConnection(TScriptInterface<class IApiGearConnection> InConnection);

private:
	void applyState(const nlohmann::json& fields);
	void emitSignal(const std::string& signalName, const nlohmann::json& args);
	std::shared_ptr<FUnrealOLinkSink> m_sink;

	// member variable to store the last sent data
#if (ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION < 27)
	TUniquePtr<Testbed1StructInterfacePropertiesData> _SentData;
#else
	TPimplPtr<Testbed1StructInterfacePropertiesData> _SentData;
#endif
	TScriptInterface<class IApiGearConnection> Connection;
};
