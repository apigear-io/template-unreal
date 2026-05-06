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

class UTestbed2NestedStruct1InterfaceMQTTSpec;
class ITestbed2NestedStruct1InterfaceInterface;
class UTestbed2NestedStruct1InterfaceMQTTAdapter;
class IApiGearConnection;
class UApiGearMQTTClient;
class UApiGearMQTTHost;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed2
{
namespace NestedStruct1Interface
{
namespace MQTT
{
namespace Tests
{
class FTestbed2NestedStruct1InterfaceMQTTFixture
{
public:
	FTestbed2NestedStruct1InterfaceMQTTFixture();
	~FTestbed2NestedStruct1InterfaceMQTTFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> GetImplementation();
	UApiGearMQTTHost* GetHost();
	UTestbed2NestedStruct1InterfaceMQTTAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed2NestedStruct1InterfaceInterface> testImplementation;
	TSoftObjectPtr<UApiGearMQTTHost> Host;
};
} // namespace Tests
} // namespace MQTT
} // namespace NestedStruct1Interface
} // namespace Testbed2

#endif // WITH_DEV_AUTOMATION_TESTS
