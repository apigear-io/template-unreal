{{- /* Copyright Epic Games, Inc. All Rights Reserved */ -}}
/**{{ template "copyright" }}*/
{{- $ModuleName := Camel .Module.Name}}

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#if WITH_DEV_AUTOMATION_TESTS

class F{{ $ModuleName }}TestBase : public FAutomationTestBase
{
public:
	F{{ $ModuleName }}TestBase(const FString& InName, const bool bInComplexTask)
		: FAutomationTestBase(InName, bInComplexTask)
	{
	}

	~F{{ $ModuleName }}TestBase()
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
