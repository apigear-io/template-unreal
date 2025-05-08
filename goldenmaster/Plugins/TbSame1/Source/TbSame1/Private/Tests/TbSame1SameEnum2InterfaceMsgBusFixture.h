
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSame1_data.h"
#include "HAL/Platform.h"
#include "TbSame1SameEnum2InterfaceMsgBusFixture.generated.h"

class FTbSame1SameEnum2InterfaceMsgBusFixture;
class ITbSame1SameEnum2InterfaceInterface;
class UTbSame1SameEnum2InterfaceMsgBusAdapter;
class IApiGearConnection;

UCLASS()
class UTbSame1SameEnum2InterfaceMsgBusHelper : public UObject
{
	GENERATED_BODY()
public:
	~UTbSame1SameEnum2InterfaceMsgBusHelper();

	void SetParentFixture(TWeakPtr<FTbSame1SameEnum2InterfaceMsgBusFixture> InFixture);
	void SetSpec(FAutomationTestBase* InSpec);
	void SetTestDone(const FDoneDelegate& InDone);

	UFUNCTION()
	void Prop1PropertyCb(ETbSame1Enum1 Prop1);
	UFUNCTION()
	void Prop1PropertyChangeLocalCheckRemoteCb(ETbSame1Enum1 Prop1);
	UFUNCTION()
	void Prop1PropertyChangeLocalChangeRemoteCb(ETbSame1Enum1 Prop1);

	UFUNCTION()
	void Prop2PropertyCb(ETbSame1Enum2 Prop2);
	UFUNCTION()
	void Prop2PropertyChangeLocalCheckRemoteCb(ETbSame1Enum2 Prop2);
	UFUNCTION()
	void Prop2PropertyChangeLocalChangeRemoteCb(ETbSame1Enum2 Prop2);

	UFUNCTION()
	void Sig1SignalCb(ETbSame1Enum1 Param1);

	UFUNCTION()
	void Sig2SignalCb(ETbSame1Enum1 Param1, ETbSame1Enum2 Param2);

	UFUNCTION()
	void _ConnectionStatusChangedCb(bool bConnected);

protected:
	TWeakPtr<FTbSame1SameEnum2InterfaceMsgBusFixture> ImplFixture;
	FDoneDelegate testDoneDelegate;
	FAutomationTestBase* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSame1SameEnum2InterfaceMsgBusFixture
{
public:
	FTbSame1SameEnum2InterfaceMsgBusFixture();
	~FTbSame1SameEnum2InterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame1SameEnum2InterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbSame1SameEnum2InterfaceMsgBusHelper> GetHelper();
	UTbSame1SameEnum2InterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame1SameEnum2InterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbSame1SameEnum2InterfaceMsgBusHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
