
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSame2/Generated/api/TbSame2_data.h"
#include "HAL/Platform.h"
#include "TbSame2SameStruct2InterfaceMsgBusFixture.generated.h"

class UTbSame2SameStruct2InterfaceMsgBusSpec;
class ITbSame2SameStruct2InterfaceInterface;
class UTbSame2SameStruct2InterfaceMsgBusAdapter;
class IApiGearConnection;

UCLASS()
class UTbSame2SameStruct2InterfaceMsgBusHelper : public UObject
{
	GENERATED_BODY()
public:
	~UTbSame2SameStruct2InterfaceMsgBusHelper();

	void SetSpec(UTbSame2SameStruct2InterfaceMsgBusSpec* InSpec);

	UFUNCTION()
	void Prop1PropertyCb(const FTbSame2Struct2& Prop1);

	UFUNCTION()
	void Prop2PropertyCb(const FTbSame2Struct2& Prop2);

	UFUNCTION()
	void Sig1SignalCb(const FTbSame2Struct1& Param1);

	UFUNCTION()
	void Sig2SignalCb(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2);

	UFUNCTION()
	void _ConnectionStatusChangedCb(bool bConnected);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSame2SameStruct2InterfaceMsgBusSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

class FTbSame2SameStruct2InterfaceMsgBusFixture
{
public:
	FTbSame2SameStruct2InterfaceMsgBusFixture();
	~FTbSame2SameStruct2InterfaceMsgBusFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame2SameStruct2InterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbSame2SameStruct2InterfaceMsgBusHelper> GetHelper();
	UTbSame2SameStruct2InterfaceMsgBusAdapter* GetAdapter();

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame2SameStruct2InterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbSame2SameStruct2InterfaceMsgBusHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
