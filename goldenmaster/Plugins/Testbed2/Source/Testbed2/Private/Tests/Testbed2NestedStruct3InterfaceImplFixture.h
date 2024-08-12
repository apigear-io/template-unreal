
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/Testbed2_data.h"
#include "Testbed2NestedStruct3InterfaceImplFixture.generated.h"

class UTestbed2NestedStruct3InterfaceImplSpec;
class ITestbed2NestedStruct3InterfaceInterface;

UCLASS()
class UTestbed2NestedStruct3InterfaceImplHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTestbed2NestedStruct3InterfaceImplSpec* InSpec);

	UFUNCTION()
	void Prop1PropertyCb(const FTestbed2NestedStruct1& Prop1);

	UFUNCTION()
	void Prop2PropertyCb(const FTestbed2NestedStruct2& Prop2);

	UFUNCTION()
	void Prop3PropertyCb(const FTestbed2NestedStruct3& Prop3);

	UFUNCTION()
	void Sig1SignalCb(const FTestbed2NestedStruct1& Param1);

	UFUNCTION()
	void Sig2SignalCb(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2);

	UFUNCTION()
	void Sig3SignalCb(const FTestbed2NestedStruct1& Param1, const FTestbed2NestedStruct2& Param2, const FTestbed2NestedStruct3& Param3);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTestbed2NestedStruct3InterfaceImplSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTestbed2NestedStruct3InterfaceImplFixture
{
public:
	FTestbed2NestedStruct3InterfaceImplFixture();
	~FTestbed2NestedStruct3InterfaceImplFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> GetImplementation();
	TWeakObjectPtr<UTestbed2NestedStruct3InterfaceImplHelper> GetHelper();

private:
	void CleanUp();

	TWeakObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITestbed2NestedStruct3InterfaceInterface> testImplementation;
	TWeakObjectPtr<UTestbed2NestedStruct3InterfaceImplHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
