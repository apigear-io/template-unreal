
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
    service->GetProp200ChangedDelegate().AddDynamic(this, &UOrgObjectapiTestbedInterface2Proxy::OnProp200Changed);
    service->GetProp201ChangedDelegate().AddDynamic(this, &UOrgObjectapiTestbedInterface2Proxy::OnProp201Changed);
    service->GetProp202ChangedDelegate().AddDynamic(this, &UOrgObjectapiTestbedInterface2Proxy::OnProp202Changed);
    service->GetProp203ChangedDelegate().AddDynamic(this, &UOrgObjectapiTestbedInterface2Proxy::OnProp203Changed);
    service->GetProp204ChangedDelegate().AddDynamic(this, &UOrgObjectapiTestbedInterface2Proxy::OnProp204Changed);
    service->GetProp205ChangedDelegate().AddDynamic(this, &UOrgObjectapiTestbedInterface2Proxy::OnProp205Changed);
}

UOrgObjectapiTestbedInterface2Proxy::~UOrgObjectapiTestbedInterface2Proxy()
{
    service->GetProp200ChangedDelegate().RemoveDynamic(this, &UOrgObjectapiTestbedInterface2Proxy::OnProp200Changed);
    service->GetProp201ChangedDelegate().RemoveDynamic(this, &UOrgObjectapiTestbedInterface2Proxy::OnProp201Changed);
    service->GetProp202ChangedDelegate().RemoveDynamic(this, &UOrgObjectapiTestbedInterface2Proxy::OnProp202Changed);
    service->GetProp203ChangedDelegate().RemoveDynamic(this, &UOrgObjectapiTestbedInterface2Proxy::OnProp203Changed);
    service->GetProp204ChangedDelegate().RemoveDynamic(this, &UOrgObjectapiTestbedInterface2Proxy::OnProp204Changed);
    service->GetProp205ChangedDelegate().RemoveDynamic(this, &UOrgObjectapiTestbedInterface2Proxy::OnProp205Changed);
}
void UOrgObjectapiTestbedInterface2Proxy::OnProp200Changed(int32 InProp200)
{
    OrgObjectapiTestbedInterface2Tracer::capture_state(this);
    Prop200Changed.Broadcast(InProp200);
}

int32 UOrgObjectapiTestbedInterface2Proxy::GetProp200() const
{
    return service->GetProp200();
}

void UOrgObjectapiTestbedInterface2Proxy::SetProp200(int32 InProp200)
{
    OrgObjectapiTestbedInterface2Tracer::trace_callSetProp200(InProp200);
    service->SetProp200(InProp200);
}

FProp200ChangedDelegate& UOrgObjectapiTestbedInterface2Proxy::GetProp200ChangedDelegate()
{
    return Prop200Changed;
}

void UOrgObjectapiTestbedInterface2Proxy::OnProp201Changed(int32 InProp201)
{
    OrgObjectapiTestbedInterface2Tracer::capture_state(this);
    Prop201Changed.Broadcast(InProp201);
}

int32 UOrgObjectapiTestbedInterface2Proxy::GetProp201() const
{
    return service->GetProp201();
}

void UOrgObjectapiTestbedInterface2Proxy::SetProp201(int32 InProp201)
{
    OrgObjectapiTestbedInterface2Tracer::trace_callSetProp201(InProp201);
    service->SetProp201(InProp201);
}

FProp201ChangedDelegate& UOrgObjectapiTestbedInterface2Proxy::GetProp201ChangedDelegate()
{
    return Prop201Changed;
}

void UOrgObjectapiTestbedInterface2Proxy::OnProp202Changed(int32 InProp202)
{
    OrgObjectapiTestbedInterface2Tracer::capture_state(this);
    Prop202Changed.Broadcast(InProp202);
}

int32 UOrgObjectapiTestbedInterface2Proxy::GetProp202() const
{
    return service->GetProp202();
}

void UOrgObjectapiTestbedInterface2Proxy::SetProp202(int32 InProp202)
{
    OrgObjectapiTestbedInterface2Tracer::trace_callSetProp202(InProp202);
    service->SetProp202(InProp202);
}

FProp202ChangedDelegate& UOrgObjectapiTestbedInterface2Proxy::GetProp202ChangedDelegate()
{
    return Prop202Changed;
}

void UOrgObjectapiTestbedInterface2Proxy::OnProp203Changed(float InProp203)
{
    OrgObjectapiTestbedInterface2Tracer::capture_state(this);
    Prop203Changed.Broadcast(InProp203);
}

float UOrgObjectapiTestbedInterface2Proxy::GetProp203() const
{
    return service->GetProp203();
}

void UOrgObjectapiTestbedInterface2Proxy::SetProp203(float InProp203)
{
    OrgObjectapiTestbedInterface2Tracer::trace_callSetProp203(InProp203);
    service->SetProp203(InProp203);
}

FProp203ChangedDelegate& UOrgObjectapiTestbedInterface2Proxy::GetProp203ChangedDelegate()
{
    return Prop203Changed;
}

void UOrgObjectapiTestbedInterface2Proxy::OnProp204Changed(float InProp204)
{
    OrgObjectapiTestbedInterface2Tracer::capture_state(this);
    Prop204Changed.Broadcast(InProp204);
}

float UOrgObjectapiTestbedInterface2Proxy::GetProp204() const
{
    return service->GetProp204();
}

void UOrgObjectapiTestbedInterface2Proxy::SetProp204(float InProp204)
{
    OrgObjectapiTestbedInterface2Tracer::trace_callSetProp204(InProp204);
    service->SetProp204(InProp204);
}

FProp204ChangedDelegate& UOrgObjectapiTestbedInterface2Proxy::GetProp204ChangedDelegate()
{
    return Prop204Changed;
}

void UOrgObjectapiTestbedInterface2Proxy::OnProp205Changed(const FString& InProp205)
{
    OrgObjectapiTestbedInterface2Tracer::capture_state(this);
    Prop205Changed.Broadcast(InProp205);
}

FString UOrgObjectapiTestbedInterface2Proxy::GetProp205() const
{
    return service->GetProp205();
}

void UOrgObjectapiTestbedInterface2Proxy::SetProp205(const FString& InProp205)
{
    OrgObjectapiTestbedInterface2Tracer::trace_callSetProp205(InProp205);
    service->SetProp205(InProp205);
}

FProp205ChangedDelegate& UOrgObjectapiTestbedInterface2Proxy::GetProp205ChangedDelegate()
{
    return Prop205Changed;
}

