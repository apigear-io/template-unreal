// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT
#pragma once

#include "Misc/AutomationTest.h"
#if WITH_DEV_AUTOMATION_TESTS

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbStructArray/Generated/api/TbStructArray_data.h"

class UTbStructArrayStructArrayFieldInterfaceMsgBusSpec;
class ITbStructArrayStructArrayFieldInterfaceInterface;
class UTbStructArrayStructArrayFieldInterfaceMsgBusAdapter;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbStructArray
{
namespace StructArrayFieldInterface
{
namespace MsgBus
{
namespace Tests
{
class FTbStructArrayStructArrayFieldInterfaceMsgBusFixture
{
public:
	FTbStructArrayStructArrayFieldInterfaceMsgBusFixture();
	~FTbStructArrayStructArrayFieldInterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface> GetImplementation();
	UTbStructArrayStructArrayFieldInterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface> testImplementation;
};
} // namespace Tests
} // namespace MsgBus
} // namespace StructArrayFieldInterface
} // namespace TbStructArray

#endif // WITH_DEV_AUTOMATION_TESTS
