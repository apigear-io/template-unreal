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

////////////////////////////////
// WARNING AUTOGENERATED
// DO NOT MODIFY
///////////////////////////////

#include "Testbed2EmptyInterfaceSimulationClient.h"
#include "Generated/api/Testbed2.json.adapter.h"
#include "ApiGear/Public/ApiGearConnectionManager.h"
#include "unrealsimulation.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

using namespace ApiGear::JSONRPC;
UTestbed2EmptyInterfaceSimulationClient::UTestbed2EmptyInterfaceSimulationClient()
	: ITestbed2EmptyInterfaceInterface()
{
}

void UTestbed2EmptyInterfaceSimulationClient::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	UApiGearConnectionManager* AGCM = nullptr;
	if (GEngine != nullptr)
	{
		AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
	}
	NotifyRequestFunc EmptyInterfaceStateChangedFunc = [this](NotifyRequestArg arg)
	{
		const json fields = arg.params;
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->Connect();
		AGCM->GetSimulationConnection()->onNotifyState("testbed2/EmptyInterface", EmptyInterfaceStateChangedFunc);
	}

	CallResponseFunc GetEmptyInterfaceStateFunc = [this](CallResponseArg arg)
	{
		if (arg.result.size() != 1)
		{
			return;
		}
		const json fields = arg.result;
	};
	if (AGCM != nullptr)
	{
		AGCM->GetSimulationConnection()->doFetchState("testbed2/EmptyInterface", GetEmptyInterfaceStateFunc);
	}

	// register notification callback functions, signal/event -> fcn
}

void UTestbed2EmptyInterfaceSimulationClient::Deinitialize()
{
	Super::Deinitialize();

	if (GEngine != nullptr)
	{
		UApiGearConnectionManager* AGCM = GEngine->GetEngineSubsystem<UApiGearConnectionManager>();
		AGCM->GetSimulationConnection()->RemoveOnNotifyState("testbed2/EmptyInterface");
		// unregister notification callback functions
	}
}
