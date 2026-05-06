// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSame1/Generated/api/TbSame1_data.h"

class UTbSame1SameEnum2InterfaceMQTTSpec;
class ITbSame1SameEnum2InterfaceInterface;
class UTbSame1SameEnum2InterfaceMQTTAdapter;
class IApiGearConnection;
class UApiGearMQTTClient;
class UApiGearMQTTHost;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame1
{
namespace SameEnum2Interface
{
namespace MQTT
{
namespace Tests
{
class FTbSame1SameEnum2InterfaceMQTTFixture
{
public:
	FTbSame1SameEnum2InterfaceMQTTFixture();
	~FTbSame1SameEnum2InterfaceMQTTFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame1SameEnum2InterfaceInterface> GetImplementation();
	UApiGearMQTTHost* GetHost();
	UTbSame1SameEnum2InterfaceMQTTAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame1SameEnum2InterfaceInterface> testImplementation;
	TSoftObjectPtr<UApiGearMQTTHost> Host;
};
} // namespace Tests
} // namespace MQTT
} // namespace SameEnum2Interface
} // namespace TbSame1

#endif // WITH_DEV_AUTOMATION_TESTS
