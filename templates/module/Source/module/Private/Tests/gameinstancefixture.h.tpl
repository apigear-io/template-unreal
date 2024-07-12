{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

class F{{ $ModuleName }}GameInstanceFixture
{
public:
	~F{{ $ModuleName }}GameInstanceFixture()
	{
		CleanUp();
	}

	UGameInstance* GetGameInstance()
	{
		if (!GameInstance.IsValid())
		{
			GameInstance = NewObject<UGameInstance>();
			GameInstance->Init();
		}

		return GameInstance.Get();
	}

private:
	void CleanUp()
	{
		if (GameInstance.IsValid())
		{
			GameInstance->Shutdown();
		}
	}

	TWeakObjectPtr<UGameInstance> GameInstance;
};

#endif // WITH_DEV_AUTOMATION_TESTS
