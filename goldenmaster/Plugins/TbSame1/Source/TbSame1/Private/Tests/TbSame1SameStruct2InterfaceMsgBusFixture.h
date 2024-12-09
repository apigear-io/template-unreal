
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSame1_data.h"
#include "HAL/Platform.h"
#include "TbSame1SameStruct2InterfaceMsgBusFixture.generated.h"

class UTbSame1SameStruct2InterfaceMsgBusSpec;
class ITbSame1SameStruct2InterfaceInterface;
class UTbSame1SameStruct2InterfaceMsgBusAdapter;
class IApiGearConnection;

UCLASS()
class UTbSame1SameStruct2InterfaceMsgBusHelper : public UObject
{
	GENERATED_BODY()
public:
	~UTbSame1SameStruct2InterfaceMsgBusHelper();

	void SetSpec(UTbSame1SameStruct2InterfaceMsgBusSpec* InSpec);

	UFUNCTION()
	void Prop1PropertyCb(const FTbSame1Struct2& Prop1);

	UFUNCTION()
	void Prop2PropertyCb(const FTbSame1Struct2& Prop2);

	UFUNCTION()
	void Sig1SignalCb(const FTbSame1Struct1& Param1);

	UFUNCTION()
	void Sig2SignalCb(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2);

	UFUNCTION()
	void _ConnectionStatusChangedCb(bool bConnected);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSame1SameStruct2InterfaceMsgBusSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

class FTbSame1SameStruct2InterfaceMsgBusFixture
{
public:
	FTbSame1SameStruct2InterfaceMsgBusFixture();
	~FTbSame1SameStruct2InterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame1SameStruct2InterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbSame1SameStruct2InterfaceMsgBusHelper> GetHelper();
	UTbSame1SameStruct2InterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame1SameStruct2InterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbSame1SameStruct2InterfaceMsgBusHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
