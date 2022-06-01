
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
#include "OrgObjectapiTestbedInterface2Proxy.h"
#include "Interface2/OrgObjectapiTestbedInterface2Local.h"
#include "apig/OrgObjectapiTestbed.trace.h"
#include "OrgObjectapiTestbedFactory.h"
#include "Engine/LatentActionManager.h"
#include "LatentActions.h"

class FOrgObjectapiTestbedInterface2LatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FOrgObjectapiTestbedInterface2LatentAction(const FLatentActionInfo& LatentInfo)
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
UOrgObjectapiTestbedInterface2Proxy::UOrgObjectapiTestbedInterface2Proxy()
    : IOrgObjectapiTestbedInterface2Interface()
    , Prop200(0)
    , Prop201(0)
    , Prop202(0)
    , Prop203(0.0f)
    , Prop204(0.0f)
    , Prop205(FString())
{
    service = FOrgObjectapiTestbedModuleFactory::createIOrgObjectapiTestbedInterface2Interface();

    service->SubscribeToOrgObjectapiTestbedInterface2StateChanged(*this);
}

UOrgObjectapiTestbedInterface2Proxy::~UOrgObjectapiTestbedInterface2Proxy()
{
    service->UnsubscribeFromOrgObjectapiTestbedInterface2StateChanged(*this);
}
void UOrgObjectapiTestbedInterface2Proxy::OnProp200Changed(int32 Value)
{
    OrgObjectapiTestbedInterface2Tracer::capture_state(this);
    Prop200Changed.Broadcast(Value);
}

int32 UOrgObjectapiTestbedInterface2Proxy::GetProp200() const
{
    return service->GetProp200();
}

void UOrgObjectapiTestbedInterface2Proxy::SetProp200(int32 Value)
{
    OrgObjectapiTestbedInterface2Tracer::trace_callSetProp200(Value);
    service->SetProp200(Value);
}

void UOrgObjectapiTestbedInterface2Proxy::OnProp201Changed(int32 Value)
{
    OrgObjectapiTestbedInterface2Tracer::capture_state(this);
    Prop201Changed.Broadcast(Value);
}

int32 UOrgObjectapiTestbedInterface2Proxy::GetProp201() const
{
    return service->GetProp201();
}

void UOrgObjectapiTestbedInterface2Proxy::SetProp201(int32 Value)
{
    OrgObjectapiTestbedInterface2Tracer::trace_callSetProp201(Value);
    service->SetProp201(Value);
}

void UOrgObjectapiTestbedInterface2Proxy::OnProp202Changed(int32 Value)
{
    OrgObjectapiTestbedInterface2Tracer::capture_state(this);
    Prop202Changed.Broadcast(Value);
}

int32 UOrgObjectapiTestbedInterface2Proxy::GetProp202() const
{
    return service->GetProp202();
}

void UOrgObjectapiTestbedInterface2Proxy::SetProp202(int32 Value)
{
    OrgObjectapiTestbedInterface2Tracer::trace_callSetProp202(Value);
    service->SetProp202(Value);
}

void UOrgObjectapiTestbedInterface2Proxy::OnProp203Changed(float Value)
{
    OrgObjectapiTestbedInterface2Tracer::capture_state(this);
    Prop203Changed.Broadcast(Value);
}

float UOrgObjectapiTestbedInterface2Proxy::GetProp203() const
{
    return service->GetProp203();
}

void UOrgObjectapiTestbedInterface2Proxy::SetProp203(float Value)
{
    OrgObjectapiTestbedInterface2Tracer::trace_callSetProp203(Value);
    service->SetProp203(Value);
}

void UOrgObjectapiTestbedInterface2Proxy::OnProp204Changed(float Value)
{
    OrgObjectapiTestbedInterface2Tracer::capture_state(this);
    Prop204Changed.Broadcast(Value);
}

float UOrgObjectapiTestbedInterface2Proxy::GetProp204() const
{
    return service->GetProp204();
}

void UOrgObjectapiTestbedInterface2Proxy::SetProp204(float Value)
{
    OrgObjectapiTestbedInterface2Tracer::trace_callSetProp204(Value);
    service->SetProp204(Value);
}

void UOrgObjectapiTestbedInterface2Proxy::OnProp205Changed(FString Value)
{
    OrgObjectapiTestbedInterface2Tracer::capture_state(this);
    Prop205Changed.Broadcast(Value);
}

FString UOrgObjectapiTestbedInterface2Proxy::GetProp205() const
{
    return service->GetProp205();
}

void UOrgObjectapiTestbedInterface2Proxy::SetProp205(FString Value)
{
    OrgObjectapiTestbedInterface2Tracer::trace_callSetProp205(Value);
    service->SetProp205(Value);
}

