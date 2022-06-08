
/**
Copyright 2021 ApiGear UG
Copyright 2021 Epic Games, Inc.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/
#include "OrgObjectapiTestbedInterface1Proxy.h"
#include "Interface1/OrgObjectapiTestbedInterface1Local.h"
#include "apig/OrgObjectapiTestbed.trace.h"
#include "OrgObjectapiTestbedFactory.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

class FOrgObjectapiTestbedInterface1LatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FOrgObjectapiTestbedInterface1LatentAction(const FLatentActionInfo& LatentInfo)
		: ExecutionFunction(LatentInfo.ExecutionFunction)
		, OutputLink(LatentInfo.Linkage)
		, CallbackTarget(LatentInfo.CallbackTarget)
		, bInProgress(true)
	{
	}

    void Cancel() {
        bInProgress = false;
    }

	virtual void UpdateOperation(FLatentResponse& Response) override
	{
		if (bInProgress == false)
		{
			Response.FinishAndTriggerIf(true, ExecutionFunction, OutputLink, CallbackTarget);
		}
	}

	virtual void NotifyObjectDestroyed()
	{
		Cancel();
	}

	virtual void NotifyActionAborted()
	{
		Cancel();
	}
};
UOrgObjectapiTestbedInterface1Proxy::UOrgObjectapiTestbedInterface1Proxy()
    : IOrgObjectapiTestbedInterface1Interface()
    , bProp1(false)
    , Prop2(0)
    , Prop3(0.0f)
    , Prop4(FString())
    , Prop5(TArray<int32>())
    , Prop6(FOrgObjectapiTestbedStruct1())
    , Prop7(0)
    , Prop10(TArray<int32>())
    , Prop11(TArray<FOrgObjectapiTestbedStruct1>())
    , Prop12(TArray<EOrgObjectapiTestbedEnum1>())
    , Prop14(TArray<FOrgObjectapiTestbedStruct1>())
{
    service = FOrgObjectapiTestbedModuleFactory::createIOrgObjectapiTestbedInterface1Interface();
    service->GetOrgObjectapiTestbedInterface1Prop1ChangedDelegate().AddDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Prop1Changed);
    service->GetOrgObjectapiTestbedInterface1Prop2ChangedDelegate().AddDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Prop2Changed);
    service->GetOrgObjectapiTestbedInterface1Prop3ChangedDelegate().AddDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Prop3Changed);
    service->GetOrgObjectapiTestbedInterface1Prop4ChangedDelegate().AddDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Prop4Changed);
    service->GetOrgObjectapiTestbedInterface1Prop5ChangedDelegate().AddDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Prop5Changed);
    service->GetOrgObjectapiTestbedInterface1Prop6ChangedDelegate().AddDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Prop6Changed);
    service->GetOrgObjectapiTestbedInterface1Prop7ChangedDelegate().AddDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Prop7Changed);
    service->GetOrgObjectapiTestbedInterface1Prop10ChangedDelegate().AddDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Prop10Changed);
    service->GetOrgObjectapiTestbedInterface1Prop11ChangedDelegate().AddDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Prop11Changed);
    service->GetOrgObjectapiTestbedInterface1Prop12ChangedDelegate().AddDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Prop12Changed);
    service->GetOrgObjectapiTestbedInterface1Prop14ChangedDelegate().AddDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Prop14Changed);
    service->GetOrgObjectapiTestbedInterface1Sig1SignalDelegate().AddDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Sig1);
    service->GetOrgObjectapiTestbedInterface1Sig2SignalDelegate().AddDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Sig2);
    service->GetOrgObjectapiTestbedInterface1Sig3SignalDelegate().AddDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Sig3);
}

UOrgObjectapiTestbedInterface1Proxy::~UOrgObjectapiTestbedInterface1Proxy()
{
    service->GetOrgObjectapiTestbedInterface1Prop1ChangedDelegate().RemoveDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Prop1Changed);
    service->GetOrgObjectapiTestbedInterface1Prop2ChangedDelegate().RemoveDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Prop2Changed);
    service->GetOrgObjectapiTestbedInterface1Prop3ChangedDelegate().RemoveDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Prop3Changed);
    service->GetOrgObjectapiTestbedInterface1Prop4ChangedDelegate().RemoveDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Prop4Changed);
    service->GetOrgObjectapiTestbedInterface1Prop5ChangedDelegate().RemoveDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Prop5Changed);
    service->GetOrgObjectapiTestbedInterface1Prop6ChangedDelegate().RemoveDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Prop6Changed);
    service->GetOrgObjectapiTestbedInterface1Prop7ChangedDelegate().RemoveDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Prop7Changed);
    service->GetOrgObjectapiTestbedInterface1Prop10ChangedDelegate().RemoveDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Prop10Changed);
    service->GetOrgObjectapiTestbedInterface1Prop11ChangedDelegate().RemoveDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Prop11Changed);
    service->GetOrgObjectapiTestbedInterface1Prop12ChangedDelegate().RemoveDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Prop12Changed);
    service->GetOrgObjectapiTestbedInterface1Prop14ChangedDelegate().RemoveDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Prop14Changed);
    service->GetOrgObjectapiTestbedInterface1Sig1SignalDelegate().RemoveDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Sig1);
    service->GetOrgObjectapiTestbedInterface1Sig2SignalDelegate().RemoveDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Sig2);
    service->GetOrgObjectapiTestbedInterface1Sig3SignalDelegate().RemoveDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Sig3);
}
void UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Sig1()
{
    OrgObjectapiTestbedInterface1Tracer::trace_signalSig1();
    OrgObjectapiTestbedInterface1Sig1Signal.Broadcast();
}

FOrgObjectapiTestbedInterface1Sig1Delegate& UOrgObjectapiTestbedInterface1Proxy::GetOrgObjectapiTestbedInterface1Sig1SignalDelegate()
{
    return OrgObjectapiTestbedInterface1Sig1Signal;
}

void UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Sig2(int32 Step, const FString& Step2)
{
    OrgObjectapiTestbedInterface1Tracer::trace_signalSig2(Step,Step2);
    OrgObjectapiTestbedInterface1Sig2Signal.Broadcast(Step,Step2);
}

FOrgObjectapiTestbedInterface1Sig2Delegate& UOrgObjectapiTestbedInterface1Proxy::GetOrgObjectapiTestbedInterface1Sig2SignalDelegate()
{
    return OrgObjectapiTestbedInterface1Sig2Signal;
}

void UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Sig3(float Step)
{
    OrgObjectapiTestbedInterface1Tracer::trace_signalSig3(Step);
    OrgObjectapiTestbedInterface1Sig3Signal.Broadcast(Step);
}

FOrgObjectapiTestbedInterface1Sig3Delegate& UOrgObjectapiTestbedInterface1Proxy::GetOrgObjectapiTestbedInterface1Sig3SignalDelegate()
{
    return OrgObjectapiTestbedInterface1Sig3Signal;
}

void UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Prop1Changed(bool bInProp1)
{
    OrgObjectapiTestbedInterface1Tracer::capture_state(this);
    OrgObjectapiTestbedInterface1Prop1Changed.Broadcast(bInProp1);
}

bool UOrgObjectapiTestbedInterface1Proxy::GetProp1() const
{
    return service->GetProp1();
}

void UOrgObjectapiTestbedInterface1Proxy::SetProp1(bool bInProp1)
{
    OrgObjectapiTestbedInterface1Tracer::trace_callSetProp1(bInProp1);
    service->SetProp1(bInProp1);
}

FOrgObjectapiTestbedInterface1Prop1ChangedDelegate& UOrgObjectapiTestbedInterface1Proxy::GetOrgObjectapiTestbedInterface1Prop1ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop1Changed;
}

void UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Prop2Changed(int32 InProp2)
{
    OrgObjectapiTestbedInterface1Tracer::capture_state(this);
    OrgObjectapiTestbedInterface1Prop2Changed.Broadcast(InProp2);
}

int32 UOrgObjectapiTestbedInterface1Proxy::GetProp2() const
{
    return service->GetProp2();
}

void UOrgObjectapiTestbedInterface1Proxy::SetProp2(int32 InProp2)
{
    OrgObjectapiTestbedInterface1Tracer::trace_callSetProp2(InProp2);
    service->SetProp2(InProp2);
}

FOrgObjectapiTestbedInterface1Prop2ChangedDelegate& UOrgObjectapiTestbedInterface1Proxy::GetOrgObjectapiTestbedInterface1Prop2ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop2Changed;
}

void UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Prop3Changed(float InProp3)
{
    OrgObjectapiTestbedInterface1Tracer::capture_state(this);
    OrgObjectapiTestbedInterface1Prop3Changed.Broadcast(InProp3);
}

float UOrgObjectapiTestbedInterface1Proxy::GetProp3() const
{
    return service->GetProp3();
}

void UOrgObjectapiTestbedInterface1Proxy::SetProp3(float InProp3)
{
    OrgObjectapiTestbedInterface1Tracer::trace_callSetProp3(InProp3);
    service->SetProp3(InProp3);
}

FOrgObjectapiTestbedInterface1Prop3ChangedDelegate& UOrgObjectapiTestbedInterface1Proxy::GetOrgObjectapiTestbedInterface1Prop3ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop3Changed;
}

void UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Prop4Changed(const FString& InProp4)
{
    OrgObjectapiTestbedInterface1Tracer::capture_state(this);
    OrgObjectapiTestbedInterface1Prop4Changed.Broadcast(InProp4);
}

FString UOrgObjectapiTestbedInterface1Proxy::GetProp4() const
{
    return service->GetProp4();
}

void UOrgObjectapiTestbedInterface1Proxy::SetProp4(const FString& InProp4)
{
    OrgObjectapiTestbedInterface1Tracer::trace_callSetProp4(InProp4);
    service->SetProp4(InProp4);
}

FOrgObjectapiTestbedInterface1Prop4ChangedDelegate& UOrgObjectapiTestbedInterface1Proxy::GetOrgObjectapiTestbedInterface1Prop4ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop4Changed;
}

void UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Prop5Changed(const TArray<int32>& InProp5)
{
    OrgObjectapiTestbedInterface1Tracer::capture_state(this);
    OrgObjectapiTestbedInterface1Prop5Changed.Broadcast(InProp5);
}

TArray<int32> UOrgObjectapiTestbedInterface1Proxy::GetProp5() const
{
    return service->GetProp5();
}

void UOrgObjectapiTestbedInterface1Proxy::SetProp5(const TArray<int32>& InProp5)
{
    OrgObjectapiTestbedInterface1Tracer::trace_callSetProp5(InProp5);
    service->SetProp5(InProp5);
}

FOrgObjectapiTestbedInterface1Prop5ChangedDelegate& UOrgObjectapiTestbedInterface1Proxy::GetOrgObjectapiTestbedInterface1Prop5ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop5Changed;
}

void UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Prop6Changed(const FOrgObjectapiTestbedStruct1& InProp6)
{
    OrgObjectapiTestbedInterface1Tracer::capture_state(this);
    OrgObjectapiTestbedInterface1Prop6Changed.Broadcast(InProp6);
}

FOrgObjectapiTestbedStruct1 UOrgObjectapiTestbedInterface1Proxy::GetProp6() const
{
    return service->GetProp6();
}

void UOrgObjectapiTestbedInterface1Proxy::SetProp6(const FOrgObjectapiTestbedStruct1& InProp6)
{
    OrgObjectapiTestbedInterface1Tracer::trace_callSetProp6(InProp6);
    service->SetProp6(InProp6);
}

FOrgObjectapiTestbedInterface1Prop6ChangedDelegate& UOrgObjectapiTestbedInterface1Proxy::GetOrgObjectapiTestbedInterface1Prop6ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop6Changed;
}

void UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Prop7Changed(int32 InProp7)
{
    OrgObjectapiTestbedInterface1Tracer::capture_state(this);
    OrgObjectapiTestbedInterface1Prop7Changed.Broadcast(InProp7);
}

int32 UOrgObjectapiTestbedInterface1Proxy::GetProp7() const
{
    return service->GetProp7();
}

void UOrgObjectapiTestbedInterface1Proxy::SetProp7(int32 InProp7)
{
    OrgObjectapiTestbedInterface1Tracer::trace_callSetProp7(InProp7);
    service->SetProp7(InProp7);
}

FOrgObjectapiTestbedInterface1Prop7ChangedDelegate& UOrgObjectapiTestbedInterface1Proxy::GetOrgObjectapiTestbedInterface1Prop7ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop7Changed;
}

void UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Prop10Changed(const TArray<int32>& InProp10)
{
    OrgObjectapiTestbedInterface1Tracer::capture_state(this);
    OrgObjectapiTestbedInterface1Prop10Changed.Broadcast(InProp10);
}

TArray<int32> UOrgObjectapiTestbedInterface1Proxy::GetProp10() const
{
    return service->GetProp10();
}

void UOrgObjectapiTestbedInterface1Proxy::SetProp10(const TArray<int32>& InProp10)
{
    OrgObjectapiTestbedInterface1Tracer::trace_callSetProp10(InProp10);
    service->SetProp10(InProp10);
}

FOrgObjectapiTestbedInterface1Prop10ChangedDelegate& UOrgObjectapiTestbedInterface1Proxy::GetOrgObjectapiTestbedInterface1Prop10ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop10Changed;
}

void UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Prop11Changed(const TArray<FOrgObjectapiTestbedStruct1>& InProp11)
{
    OrgObjectapiTestbedInterface1Tracer::capture_state(this);
    OrgObjectapiTestbedInterface1Prop11Changed.Broadcast(InProp11);
}

TArray<FOrgObjectapiTestbedStruct1> UOrgObjectapiTestbedInterface1Proxy::GetProp11() const
{
    return service->GetProp11();
}

void UOrgObjectapiTestbedInterface1Proxy::SetProp11(const TArray<FOrgObjectapiTestbedStruct1>& InProp11)
{
    OrgObjectapiTestbedInterface1Tracer::trace_callSetProp11(InProp11);
    service->SetProp11(InProp11);
}

FOrgObjectapiTestbedInterface1Prop11ChangedDelegate& UOrgObjectapiTestbedInterface1Proxy::GetOrgObjectapiTestbedInterface1Prop11ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop11Changed;
}

void UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Prop12Changed(const TArray<EOrgObjectapiTestbedEnum1>& InProp12)
{
    OrgObjectapiTestbedInterface1Tracer::capture_state(this);
    OrgObjectapiTestbedInterface1Prop12Changed.Broadcast(InProp12);
}

TArray<EOrgObjectapiTestbedEnum1> UOrgObjectapiTestbedInterface1Proxy::GetProp12() const
{
    return service->GetProp12();
}

void UOrgObjectapiTestbedInterface1Proxy::SetProp12(const TArray<EOrgObjectapiTestbedEnum1>& InProp12)
{
    OrgObjectapiTestbedInterface1Tracer::trace_callSetProp12(InProp12);
    service->SetProp12(InProp12);
}

FOrgObjectapiTestbedInterface1Prop12ChangedDelegate& UOrgObjectapiTestbedInterface1Proxy::GetOrgObjectapiTestbedInterface1Prop12ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop12Changed;
}

void UOrgObjectapiTestbedInterface1Proxy::OnOrgObjectapiTestbedInterface1Prop14Changed(const TArray<FOrgObjectapiTestbedStruct1>& InProp14)
{
    OrgObjectapiTestbedInterface1Tracer::capture_state(this);
    OrgObjectapiTestbedInterface1Prop14Changed.Broadcast(InProp14);
}

TArray<FOrgObjectapiTestbedStruct1> UOrgObjectapiTestbedInterface1Proxy::GetProp14() const
{
    return service->GetProp14();
}

void UOrgObjectapiTestbedInterface1Proxy::SetProp14(const TArray<FOrgObjectapiTestbedStruct1>& InProp14)
{
    OrgObjectapiTestbedInterface1Tracer::trace_callSetProp14(InProp14);
    service->SetProp14(InProp14);
}

FOrgObjectapiTestbedInterface1Prop14ChangedDelegate& UOrgObjectapiTestbedInterface1Proxy::GetOrgObjectapiTestbedInterface1Prop14ChangedDelegate()
{
    return OrgObjectapiTestbedInterface1Prop14Changed;
}

void UOrgObjectapiTestbedInterface1Proxy::Op1()
{
    OrgObjectapiTestbedInterface1Tracer::trace_callOp1();
    service->Op1();
}
void UOrgObjectapiTestbedInterface1Proxy::Op2(int32 Step)
{
    OrgObjectapiTestbedInterface1Tracer::trace_callOp2(Step);
    service->Op2(Step);
}
void UOrgObjectapiTestbedInterface1Proxy::Op3(UObject* WorldContextObject, FLatentActionInfo LatentInfo, int32& Result)
{
    OrgObjectapiTestbedInterface1Tracer::trace_callOp3();

	if (UWorld* World = GEngine->GetWorldFromContextObjectChecked(WorldContextObject))
	{
		FLatentActionManager& LatentActionManager = World->GetLatentActionManager();
        FOrgObjectapiTestbedInterface1LatentAction* oldRequest = LatentActionManager.FindExistingAction<FOrgObjectapiTestbedInterface1LatentAction>(LatentInfo.CallbackTarget, LatentInfo.UUID);
		
        if (oldRequest != nullptr)
		{
            // cancel old request
            oldRequest->Cancel();
            LatentActionManager.RemoveActionsForObject(LatentInfo.CallbackTarget);
        }

		FOrgObjectapiTestbedInterface1LatentAction* CompletionAction = new FOrgObjectapiTestbedInterface1LatentAction(LatentInfo);
		LatentActionManager.AddNewAction(LatentInfo.CallbackTarget, LatentInfo.UUID, CompletionAction);
        Async(EAsyncExecution::Thread, [this, &Result, CompletionAction]()
        {
            Result = service->Op3();
            CompletionAction->Cancel();
        });
	}
}
int32 UOrgObjectapiTestbedInterface1Proxy::Op3()
{
    OrgObjectapiTestbedInterface1Tracer::trace_callOp3();
    return service->Op3();
}
