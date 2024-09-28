
#pragma once

#include "Engine/GameInstance.h"
#include "Misc/AutomationTest.h"

#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Generated/api/TbSame1_data.h"
#include "TbSame1SameStruct2InterfaceOLinkFixture.generated.h"

class UTbSame1SameStruct2InterfaceOLinkSpec;
class ITbSame1SameStruct2InterfaceInterface;
class UTbSame1SameStruct2InterfaceOLinkAdapter;
class IApiGearConnection;
class UOLinkHost;

UCLASS()
class UTbSame1SameStruct2InterfaceOLinkHelper : public UObject
{
	GENERATED_BODY()
public:
	void SetSpec(UTbSame1SameStruct2InterfaceOLinkSpec* InSpec);

	UFUNCTION()
	void Prop1PropertyCb(const FTbSame1Struct2& Prop1);

	UFUNCTION()
	void Prop2PropertyCb(const FTbSame1Struct2& Prop2);

	UFUNCTION()
	void Sig1SignalCb(const FTbSame1Struct1& Param1);

	UFUNCTION()
	void Sig2SignalCb(const FTbSame1Struct1& Param1, const FTbSame1Struct2& Param2);

	UFUNCTION()
	void _SubscriptionStatusChangedCb(bool bSubscribed);

protected:
	const FDoneDelegate* testDoneDelegate;
	UTbSame1SameStruct2InterfaceOLinkSpec* Spec;
};

#if WITH_DEV_AUTOMATION_TESTS

class FTbSame1SameStruct2InterfaceOLinkFixture
{
public:
	FTbSame1SameStruct2InterfaceOLinkFixture();
	~FTbSame1SameStruct2InterfaceOLinkFixture();

	UGameInstance* GetGameInstance();
	TScriptInterface<ITbSame1SameStruct2InterfaceInterface> GetImplementation();
	TSoftObjectPtr<UTbSame1SameStruct2InterfaceOLinkHelper> GetHelper();
	UOLinkHost* GetHost();
	UTbSame1SameStruct2InterfaceOLinkAdapter* GetAdapter();
	TScriptInterface<IApiGearConnection> Connection;

private:
	void CleanUp();

	TSoftObjectPtr<UGameInstance> GameInstance;
	TScriptInterface<ITbSame1SameStruct2InterfaceInterface> testImplementation;
	TSoftObjectPtr<UTbSame1SameStruct2InterfaceOLinkHelper> Helper;
};

#endif // WITH_DEV_AUTOMATION_TESTS
