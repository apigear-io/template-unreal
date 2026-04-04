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

class UTbStructArrayStructArrayFieldInterfaceJniSpec;
class ITbStructArrayStructArrayFieldInterfaceInterface;
class UTbStructArrayStructArrayFieldInterfaceJniAdapter;
class UTbStructArrayStructArrayFieldInterfaceJniClient;
class IApiGearConnection;

// nested namespaces do not work with UE4.27 MSVC due to old C++ standard
namespace TbStructArray
{
namespace StructArrayFieldInterface
{
namespace Jni
{
namespace Tests
{
class FTbStructArrayStructArrayFieldInterfaceJniFixture
{
public:
	FTbStructArrayStructArrayFieldInterfaceJniFixture();
	~FTbStructArrayStructArrayFieldInterfaceJniFixture();

	UGameInstance* GetGameInstance();
	UTbStructArrayStructArrayFieldInterfaceJniClient* GetClient();
	TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface> GetLocalImplementation();
	UTbStructArrayStructArrayFieldInterfaceJniAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbStructArrayStructArrayFieldInterfaceInterface> source;
};
} // namespace Tests
} // namespace Jni
} // namespace StructArrayFieldInterface
} // namespace TbStructArray

#endif // WITH_DEV_AUTOMATION_TESTS
