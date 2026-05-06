// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Testbed2/Generated/api/Testbed2_data.h"

class UTestbed2NestedStruct2InterfaceMQTTSpec;
class ITestbed2NestedStruct2InterfaceInterface;
class UTestbed2NestedStruct2InterfaceMQTTAdapter;
class IApiGearConnection;
class UApiGearMQTTClient;
class UApiGearMQTTHost;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed2
{
namespace NestedStruct2Interface
{
namespace MQTT
{
namespace Tests
{
class FTestbed2NestedStruct2InterfaceMQTTFixture
{
public:
	FTestbed2NestedStruct2InterfaceMQTTFixture();
	~FTestbed2NestedStruct2InterfaceMQTTFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> GetImplementation();
	UApiGearMQTTHost* GetHost();
	UTestbed2NestedStruct2InterfaceMQTTAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed2NestedStruct2InterfaceInterface> testImplementation;
	TSoftObjectPtr<UApiGearMQTTHost> Host;
};
} // namespace Tests
} // namespace MQTT
} // namespace NestedStruct2Interface
} // namespace Testbed2

#endif // WITH_DEV_AUTOMATION_TESTS
