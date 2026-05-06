// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbRefIfaces/Generated/api/TbRefIfaces_data.h"

class UTbRefIfacesSimpleLocalIfMQTTSpec;
class ITbRefIfacesSimpleLocalIfInterface;
class UTbRefIfacesSimpleLocalIfMQTTAdapter;
class IApiGearConnection;
class UApiGearMQTTClient;
class UApiGearMQTTHost;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbRefIfaces
{
namespace SimpleLocalIf
{
namespace MQTT
{
namespace Tests
{
class FTbRefIfacesSimpleLocalIfMQTTFixture
{
public:
	FTbRefIfacesSimpleLocalIfMQTTFixture();
	~FTbRefIfacesSimpleLocalIfMQTTFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> GetImplementation();
	UApiGearMQTTHost* GetHost();
	UTbRefIfacesSimpleLocalIfMQTTAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbRefIfacesSimpleLocalIfInterface> testImplementation;
	TSoftObjectPtr<UApiGearMQTTHost> Host;
};
} // namespace Tests
} // namespace MQTT
} // namespace SimpleLocalIf
} // namespace TbRefIfaces

#endif // WITH_DEV_AUTOMATION_TESTS
