
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "TbSame2/Generated/api/TbSame2_data.h"
#include "HAL/Platform.h"
#include "TbSame2SameStruct2InterfaceOLinkFixture.generated.h"

class UTbSame2SameStruct2InterfaceOLinkSpec;
class ITbSame2SameStruct2InterfaceInterface;
class UTbSame2SameStruct2InterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

UCLASS()
class UTbSame2SameStruct2InterfaceOLinkHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTbSame2SameStruct2InterfaceOLinkSpec* InSpec);

	UFUNCTION()
	void Prop1PropertyCb(const FTbSame2Struct2& Prop1);

	UFUNCTION()
	void Prop2PropertyCb(const FTbSame2Struct2& Prop2);

	UFUNCTION()
	void Sig1SignalCb(const FTbSame2Struct1& Param1);

	UFUNCTION()
	void Sig2SignalCb(const FTbSame2Struct1& Param1, const FTbSame2Struct2& Param2);

	UFUNCTION()
	void _SubscriptionStatusChangedCb(bool bSubscribed);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSame2SameStruct2InterfaceOLinkSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID

class FTbSame2SameStruct2InterfaceOLinkFixture
{
public:
	FTbSame2SameStruct2InterfaceOLinkFixture();
	~FTbSame2SameStruct2InterfaceOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame2SameStruct2InterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbSame2SameStruct2InterfaceOLinkHelper> GetHelper();
	UOLinkHost* GetHost();
	UTbSame2SameStruct2InterfaceOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame2SameStruct2InterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbSame2SameStruct2InterfaceOLinkHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS && !PLATFORM_IOS && !PLATFORM_ANDROID
