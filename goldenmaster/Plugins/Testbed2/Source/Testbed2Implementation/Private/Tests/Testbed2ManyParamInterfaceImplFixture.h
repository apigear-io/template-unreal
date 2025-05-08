
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Testbed2/Generated/api/Testbed2_data.h"
#include "Testbed2ManyParamInterfaceImplFixture.generated.h"

class FTestbed2ManyParamInterfaceImplFixture;
class ITestbed2ManyParamInterfaceInterface;

UCLASS()
class UTestbed2ManyParamInterfaceImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetParentFixture(TWeakPtr<FTestbed2ManyParamInterfaceImplFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void Prop1PropertyCb(int32 Prop1);

	UFUNCTION()
	void Prop2PropertyCb(int32 Prop2);

	UFUNCTION()
	void Prop3PropertyCb(int32 Prop3);

	UFUNCTION()
	void Prop4PropertyCb(int32 Prop4);

	UFUNCTION()
	void Sig1SignalCb(int32 Param1);

	UFUNCTION()
	void Sig2SignalCb(int32 Param1, int32 Param2);

	UFUNCTION()
	void Sig3SignalCb(int32 Param1, int32 Param2, int32 Param3);

	UFUNCTION()
	void Sig4SignalCb(int32 Param1, int32 Param2, int32 Param3, int32 Param4);

protected:
	TWeakPtr<FTestbed2ManyParamInterfaceImplFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTestbed2ManyParamInterfaceImplFixture
{
public:
	FTestbed2ManyParamInterfaceImplFixture();
	~FTestbed2ManyParamInterfaceImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed2ManyParamInterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTestbed2ManyParamInterfaceImplHelper> GetHelper();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed2ManyParamInterfaceInterface> testImplementation;
	TSoftObjectPtr<UTestbed2ManyParamInterfaceImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
