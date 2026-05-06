// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSimple/Generated/api/TbSimple_data.h"

class UTbSimpleVoidInterfaceMQTTSpec;
class ITbSimpleVoidInterfaceInterface;
class UTbSimpleVoidInterfaceMQTTAdapter;
class IApiGearConnection;
class UApiGearMQTTClient;
class UApiGearMQTTHost;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSimple
{
namespace VoidInterface
{
namespace MQTT
{
namespace Tests
{
class FTbSimpleVoidInterfaceMQTTFixture
{
public:
	FTbSimpleVoidInterfaceMQTTFixture();
	~FTbSimpleVoidInterfaceMQTTFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSimpleVoidInterfaceInterface> GetImplementation();
	UApiGearMQTTHost* GetHost();
	UTbSimpleVoidInterfaceMQTTAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSimpleVoidInterfaceInterface> testImplementation;
	TSoftObjectPtr<UApiGearMQTTHost> Host;
};
} // namespace Tests
} // namespace MQTT
} // namespace VoidInterface
} // namespace TbSimple

#endif // WITH_DEV_AUTOMATION_TESTS
