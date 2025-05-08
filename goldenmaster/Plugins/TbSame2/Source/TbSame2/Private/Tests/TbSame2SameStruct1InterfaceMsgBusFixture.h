
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSame2_data.h"
#include "HAL/Platform.h"
#include "TbSame2SameStruct1InterfaceMsgBusFixture.generated.h"

class FTbSame2SameStruct1InterfaceMsgBusFixture;
class ITbSame2SameStruct1InterfaceInterface;
class UTbSame2SameStruct1InterfaceMsgBusAdapter;
class IApiGearConnection;

UCLASS()
class UTbSame2SameStruct1InterfaceMsgBusHelper : public UObject
{
	GENERATED_BODY()
public:
	~UTbSame2SameStruct1InterfaceMsgBusHelper();

	void SetParentFixture(TWeakPtr<FTbSame2SameStruct1InterfaceMsgBusFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void Prop1PropertyCb(const FTbSame2Struct1& Prop1);
	UFUNCTION()
	void Prop1PropertyChangeLocalCheckRemoteCb(const FTbSame2Struct1& Prop1);
	UFUNCTION()
	void Prop1PropertyChangeLocalChangeRemoteCb(const FTbSame2Struct1& Prop1);

	UFUNCTION()
	void Sig1SignalCb(const FTbSame2Struct1& Param1);

	UFUNCTION()
	void _ConnectionStatusChangedCb(bool bConnected);

protected:
	TWeakPtr<FTbSame2SameStruct1InterfaceMsgBusFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSame2SameStruct1InterfaceMsgBusFixture
{
public:
	FTbSame2SameStruct1InterfaceMsgBusFixture();
	~FTbSame2SameStruct1InterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame2SameStruct1InterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbSame2SameStruct1InterfaceMsgBusHelper> GetHelper();
	UTbSame2SameStruct1InterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame2SameStruct1InterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbSame2SameStruct1InterfaceMsgBusHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
