
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSame1_data.h"
#include "HAL/Platform.h"
#include "TbSame1SameStruct1InterfaceMsgBusFixture.generated.h"

class FTbSame1SameStruct1InterfaceMsgBusFixture;
class ITbSame1SameStruct1InterfaceInterface;
class UTbSame1SameStruct1InterfaceMsgBusAdapter;
class IApiGearConnection;

UCLASS()
class UTbSame1SameStruct1InterfaceMsgBusHelper : public UObject
{
	GENERATED_BODY()
public:
	~UTbSame1SameStruct1InterfaceMsgBusHelper();

	void SetParentFixture(TWeakPtr<FTbSame1SameStruct1InterfaceMsgBusFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void Prop1PropertyCb(const FTbSame1Struct1& Prop1);
	UFUNCTION()
	void Prop1PropertyChangeLocalCheckRemoteCb(const FTbSame1Struct1& Prop1);
	UFUNCTION()
	void Prop1PropertyChangeLocalChangeRemoteCb(const FTbSame1Struct1& Prop1);

	UFUNCTION()
	void Sig1SignalCb(const FTbSame1Struct1& Param1);

	UFUNCTION()
	void _ConnectionStatusChangedCb(bool bConnected);

protected:
	TWeakPtr<FTbSame1SameStruct1InterfaceMsgBusFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSame1SameStruct1InterfaceMsgBusFixture
{
public:
	FTbSame1SameStruct1InterfaceMsgBusFixture();
	~FTbSame1SameStruct1InterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame1SameStruct1InterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbSame1SameStruct1InterfaceMsgBusHelper> GetHelper();
	UTbSame1SameStruct1InterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame1SameStruct1InterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbSame1SameStruct1InterfaceMsgBusHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
