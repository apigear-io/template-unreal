
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
#include "Generated/Monitor/Testbed2EmptyInterfaceLoggingDecorator.h"
#include "Implementation/Testbed2EmptyInterface.h"
#include "Generated/api/Testbed2.trace.h"
#include "Testbed2Factory.h"
#include "Async/Async.h"
#include "LatentActions.h"
#include "Engine/LatentActionManager.h"
#include "Engine/Engine.h"

DEFINE_LOG_CATEGORY(LogTestbed2EmptyInterfaceLoggingDecorator);

class FTestbed2EmptyInterfaceLatentAction : public FPendingLatentAction
{
private:
	FName ExecutionFunction;
	int32 OutputLink;
	FWeakObjectPtr CallbackTarget;
	bool bInProgress;

public:
	FTestbed2EmptyInterfaceLatentAction(const FLatentActionInfo& LatentInfo)
		: ExecutionFunction(LatentInfo.ExecutionFunction)
		, OutputLink(LatentInfo.Linkage)
		, CallbackTarget(LatentInfo.CallbackTarget)
		, bInProgress(true)
	{
	}

	void Cancel()
	{
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
UTestbed2EmptyInterfaceLoggingDecorator::UTestbed2EmptyInterfaceLoggingDecorator()
	: ITestbed2EmptyInterfaceInterface()
{
}

UTestbed2EmptyInterfaceLoggingDecorator::~UTestbed2EmptyInterfaceLoggingDecorator() = default;

void UTestbed2EmptyInterfaceLoggingDecorator::Initialize(FSubsystemCollectionBase&)
{
	BackendService = FTestbed2ModuleFactory::createITestbed2EmptyInterfaceInterface();
}

void UTestbed2EmptyInterfaceLoggingDecorator::Deinitialize()
{
	BackendService = nullptr;
}

void UTestbed2EmptyInterfaceLoggingDecorator::setBackendService(TScriptInterface<ITestbed2EmptyInterfaceInterface> InService)
{
	// unsubscribe from old backend
	if (BackendService != nullptr)
	{
	}

	// only set if interface is implemented
	if (InService.GetInterface() == nullptr)
	{
		UE_LOG(LogTestbed2EmptyInterfaceLoggingDecorator, Error, TEXT("Cannot set backend service to %s - interface Testbed2EmptyInterface is not fully implemented"), *InService.GetObject()->GetName());
		return;
	}

	// subscribe to new backend
	BackendService = InService;
	// connect property changed signals or simple events
	// populate service state to proxy
}
