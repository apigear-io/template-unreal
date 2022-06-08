
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
    , Prop6(FStruct1())
    , Prop7(0)
    , Prop10(TArray<int32>())
    , Prop11(TArray<FStruct1>())
    , Prop12(TArray<EEnum1>())
    , Prop14(TArray<FStruct1>())
{
    service = FOrgObjectapiTestbedModuleFactory::createIOrgObjectapiTestbedInterface1Interface();
    service->GetbProp1ChangedDelegate().AddDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnbProp1Changed);
    service->GetProp2ChangedDelegate().AddDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnProp2Changed);
    service->GetProp3ChangedDelegate().AddDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnProp3Changed);
    service->GetProp4ChangedDelegate().AddDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnProp4Changed);
    service->GetProp5ChangedDelegate().AddDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnProp5Changed);
    service->GetProp6ChangedDelegate().AddDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnProp6Changed);
    service->GetProp7ChangedDelegate().AddDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnProp7Changed);
    service->GetProp10ChangedDelegate().AddDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnProp10Changed);
    service->GetProp11ChangedDelegate().AddDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnProp11Changed);
    service->GetProp12ChangedDelegate().AddDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnProp12Changed);
    service->GetProp14ChangedDelegate().AddDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnProp14Changed);
    service->GetSig1SignalDelegate().AddDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnSig1);
    service->GetSig2SignalDelegate().AddDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnSig2);
    service->GetSig3SignalDelegate().AddDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnSig3);
}

UOrgObjectapiTestbedInterface1Proxy::~UOrgObjectapiTestbedInterface1Proxy()
{
    service->GetbProp1ChangedDelegate().RemoveDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnbProp1Changed);
    service->GetProp2ChangedDelegate().RemoveDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnProp2Changed);
    service->GetProp3ChangedDelegate().RemoveDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnProp3Changed);
    service->GetProp4ChangedDelegate().RemoveDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnProp4Changed);
    service->GetProp5ChangedDelegate().RemoveDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnProp5Changed);
    service->GetProp6ChangedDelegate().RemoveDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnProp6Changed);
    service->GetProp7ChangedDelegate().RemoveDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnProp7Changed);
    service->GetProp10ChangedDelegate().RemoveDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnProp10Changed);
    service->GetProp11ChangedDelegate().RemoveDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnProp11Changed);
    service->GetProp12ChangedDelegate().RemoveDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnProp12Changed);
    service->GetProp14ChangedDelegate().RemoveDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnProp14Changed);
    service->GetSig1SignalDelegate().RemoveDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnSig1);
    service->GetSig2SignalDelegate().RemoveDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnSig2);
    service->GetSig3SignalDelegate().RemoveDynamic(this, &UOrgObjectapiTestbedInterface1Proxy::OnSig3);
}
void UOrgObjectapiTestbedInterface1Proxy::OnSig1()
{
    OrgObjectapiTestbedInterface1Tracer::trace_signalSig1();
    Sig1Signal.Broadcast();
}

FSig1Delegate& UOrgObjectapiTestbedInterface1Proxy::GetSig1SignalDelegate()
{
    return Sig1Signal;
}

void UOrgObjectapiTestbedInterface1Proxy::OnSig2(int32 Step)
{
    OrgObjectapiTestbedInterface1Tracer::trace_signalSig2(Step);
    Sig2Signal.Broadcast(Step);
}

FSig2Delegate& UOrgObjectapiTestbedInterface1Proxy::GetSig2SignalDelegate()
{
    return Sig2Signal;
}

void UOrgObjectapiTestbedInterface1Proxy::OnSig3()
{
    OrgObjectapiTestbedInterface1Tracer::trace_signalSig3();
    Sig3Signal.Broadcast();
}

FSig3Delegate& UOrgObjectapiTestbedInterface1Proxy::GetSig3SignalDelegate()
{
    return Sig3Signal;
}

void UOrgObjectapiTestbedInterface1Proxy::OnbProp1Changed(bool bInProp1)
{
    OrgObjectapiTestbedInterface1Tracer::capture_state(this);
    bProp1Changed.Broadcast(bInProp1);
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

FbProp1ChangedDelegate& UOrgObjectapiTestbedInterface1Proxy::GetbProp1ChangedDelegate()
{
    return bProp1Changed;
}

void UOrgObjectapiTestbedInterface1Proxy::OnProp2Changed(int32 InProp2)
{
    OrgObjectapiTestbedInterface1Tracer::capture_state(this);
    Prop2Changed.Broadcast(InProp2);
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

FProp2ChangedDelegate& UOrgObjectapiTestbedInterface1Proxy::GetProp2ChangedDelegate()
{
    return Prop2Changed;
}

void UOrgObjectapiTestbedInterface1Proxy::OnProp3Changed(float InProp3)
{
    OrgObjectapiTestbedInterface1Tracer::capture_state(this);
    Prop3Changed.Broadcast(InProp3);
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

FProp3ChangedDelegate& UOrgObjectapiTestbedInterface1Proxy::GetProp3ChangedDelegate()
{
    return Prop3Changed;
}

void UOrgObjectapiTestbedInterface1Proxy::OnProp4Changed(const FString& InProp4)
{
    OrgObjectapiTestbedInterface1Tracer::capture_state(this);
    Prop4Changed.Broadcast(InProp4);
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

FProp4ChangedDelegate& UOrgObjectapiTestbedInterface1Proxy::GetProp4ChangedDelegate()
{
    return Prop4Changed;
}

void UOrgObjectapiTestbedInterface1Proxy::OnProp5Changed(const TArray<int32>& InProp5)
{
    OrgObjectapiTestbedInterface1Tracer::capture_state(this);
    Prop5Changed.Broadcast(InProp5);
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

FProp5ChangedDelegate& UOrgObjectapiTestbedInterface1Proxy::GetProp5ChangedDelegate()
{
    return Prop5Changed;
}

void UOrgObjectapiTestbedInterface1Proxy::OnProp6Changed(const FStruct1& InProp6)
{
    OrgObjectapiTestbedInterface1Tracer::capture_state(this);
    Prop6Changed.Broadcast(InProp6);
}

FStruct1 UOrgObjectapiTestbedInterface1Proxy::GetProp6() const
{
    return service->GetProp6();
}

void UOrgObjectapiTestbedInterface1Proxy::SetProp6(const FStruct1& InProp6)
{
    OrgObjectapiTestbedInterface1Tracer::trace_callSetProp6(InProp6);
    service->SetProp6(InProp6);
}

FProp6ChangedDelegate& UOrgObjectapiTestbedInterface1Proxy::GetProp6ChangedDelegate()
{
    return Prop6Changed;
}

void UOrgObjectapiTestbedInterface1Proxy::OnProp7Changed(int32 InProp7)
{
    OrgObjectapiTestbedInterface1Tracer::capture_state(this);
    Prop7Changed.Broadcast(InProp7);
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

FProp7ChangedDelegate& UOrgObjectapiTestbedInterface1Proxy::GetProp7ChangedDelegate()
{
    return Prop7Changed;
}

void UOrgObjectapiTestbedInterface1Proxy::OnProp10Changed(const TArray<int32>& InProp10)
{
    OrgObjectapiTestbedInterface1Tracer::capture_state(this);
    Prop10Changed.Broadcast(InProp10);
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

FProp10ChangedDelegate& UOrgObjectapiTestbedInterface1Proxy::GetProp10ChangedDelegate()
{
    return Prop10Changed;
}

void UOrgObjectapiTestbedInterface1Proxy::OnProp11Changed(const TArray<FStruct1>& InProp11)
{
    OrgObjectapiTestbedInterface1Tracer::capture_state(this);
    Prop11Changed.Broadcast(InProp11);
}

TArray<FStruct1> UOrgObjectapiTestbedInterface1Proxy::GetProp11() const
{
    return service->GetProp11();
}

void UOrgObjectapiTestbedInterface1Proxy::SetProp11(const TArray<FStruct1>& InProp11)
{
    OrgObjectapiTestbedInterface1Tracer::trace_callSetProp11(InProp11);
    service->SetProp11(InProp11);
}

FProp11ChangedDelegate& UOrgObjectapiTestbedInterface1Proxy::GetProp11ChangedDelegate()
{
    return Prop11Changed;
}

void UOrgObjectapiTestbedInterface1Proxy::OnProp12Changed(const TArray<EEnum1>& InProp12)
{
    OrgObjectapiTestbedInterface1Tracer::capture_state(this);
    Prop12Changed.Broadcast(InProp12);
}

TArray<EEnum1> UOrgObjectapiTestbedInterface1Proxy::GetProp12() const
{
    return service->GetProp12();
}

void UOrgObjectapiTestbedInterface1Proxy::SetProp12(const TArray<EEnum1>& InProp12)
{
    OrgObjectapiTestbedInterface1Tracer::trace_callSetProp12(InProp12);
    service->SetProp12(InProp12);
}

FProp12ChangedDelegate& UOrgObjectapiTestbedInterface1Proxy::GetProp12ChangedDelegate()
{
    return Prop12Changed;
}

void UOrgObjectapiTestbedInterface1Proxy::OnProp14Changed(const TArray<FStruct1>& InProp14)
{
    OrgObjectapiTestbedInterface1Tracer::capture_state(this);
    Prop14Changed.Broadcast(InProp14);
}

TArray<FStruct1> UOrgObjectapiTestbedInterface1Proxy::GetProp14() const
{
    return service->GetProp14();
}

void UOrgObjectapiTestbedInterface1Proxy::SetProp14(const TArray<FStruct1>& InProp14)
{
    OrgObjectapiTestbedInterface1Tracer::trace_callSetProp14(InProp14);
    service->SetProp14(InProp14);
}

FProp14ChangedDelegate& UOrgObjectapiTestbedInterface1Proxy::GetProp14ChangedDelegate()
{
    return Prop14Changed;
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
