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

class UTbSame1SameStruct1InterfaceMQTTSpec;
class ITbSame1SameStruct1InterfaceInterface;
class UTbSame1SameStruct1InterfaceMQTTAdapter;
class IApiGearConnection;
class UApiGearMQTTClient;
class UApiGearMQTTHost;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbSame1
{
namespace SameStruct1Interface
{
namespace MQTT
{
namespace Tests
{
class FTbSame1SameStruct1InterfaceMQTTFixture
{
public:
	FTbSame1SameStruct1InterfaceMQTTFixture();
	~FTbSame1SameStruct1InterfaceMQTTFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame1SameStruct1InterfaceInterface> GetImplementation();
	UApiGearMQTTHost* GetHost();
	UTbSame1SameStruct1InterfaceMQTTAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame1SameStruct1InterfaceInterface> testImplementation;
	TSoftObjectPtr<UApiGearMQTTHost> Host;
};
} // namespace Tests
} // namespace MQTT
} // namespace SameStruct1Interface
} // namespace TbSame1

#endif // WITH_DEV_AUTOMATION_TESTS
