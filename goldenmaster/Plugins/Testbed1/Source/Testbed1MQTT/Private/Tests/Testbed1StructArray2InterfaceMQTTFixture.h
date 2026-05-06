// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Testbed1/Generated/api/Testbed1_data.h"

class UTestbed1StructArray2InterfaceMQTTSpec;
class ITestbed1StructArray2InterfaceInterface;
class UTestbed1StructArray2InterfaceMQTTAdapter;
class IApiGearConnection;
class UApiGearMQTTClient;
class UApiGearMQTTHost;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace Testbed1
{
namespace StructArray2Interface
{
namespace MQTT
{
namespace Tests
{
class FTestbed1StructArray2InterfaceMQTTFixture
{
public:
	FTestbed1StructArray2InterfaceMQTTFixture();
	~FTestbed1StructArray2InterfaceMQTTFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed1StructArray2InterfaceInterface> GetImplementation();
	UApiGearMQTTHost* GetHost();
	UTestbed1StructArray2InterfaceMQTTAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed1StructArray2InterfaceInterface> testImplementation;
	TSoftObjectPtr<UApiGearMQTTHost> Host;
};
} // namespace Tests
} // namespace MQTT
} // namespace StructArray2Interface
} // namespace Testbed1

#endif // WITH_DEV_AUTOMATION_TESTS
