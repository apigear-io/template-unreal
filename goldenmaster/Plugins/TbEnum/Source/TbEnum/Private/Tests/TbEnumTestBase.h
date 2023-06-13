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

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

class FTbEnumTestBase : public FAutomationTestBase
{
public:
	FTbEnumTestBase(const FString& InName, const bool bInComplexTask)
		: FAutomationTestBase(InName, bInComplexTask)
	{
	}

	~FTbEnumTestBase()
	{
		if (GameInstance.IsValid())
		{
			GameInstance->Shutdown();
		}

		// Unregister the automation test from the automation testing framework
		FAutomationTestFramework::Get().UnregisterAutomationTest(TestName);
	}

protected:
	UGameInstance* GetGameInstance()
	{
		if (!GameInstance.IsValid())
		{
			GameInstance = NewObject<UGameInstance>();
			GameInstance->Init();
		}

		return GameInstance.Get();
	}

	void CleanUp()
	{
		if (GameInstance.IsValid())
		{
			GameInstance->Shutdown();
		}
	}

private:
	TWeakObjectPtr<UGameInstance> GameInstance;
};

#endif // WITH_DEV_AUTOMATION_TESTS
