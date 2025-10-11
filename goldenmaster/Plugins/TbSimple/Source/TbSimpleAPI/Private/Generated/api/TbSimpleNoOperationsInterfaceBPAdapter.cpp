/**
Copyright 2024 ApiGear UG
Copyright 2024 Epic Games, Inc.

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
#include "TbSimple/Generated/api/TbSimpleNoOperationsInterfaceBPAdapter.h"
#include "TbSimpleNoOperationsInterfaceLatentAction.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

void UTbSimpleNoOperationsInterfaceBPAdapter::Initialize(TScriptInterface<ITbSimpleNoOperationsInterfaceBPInterface> InTarget)
{
	Target = InTarget;
}

UTbSimpleNoOperationsInterfacePublisher* UTbSimpleNoOperationsInterfaceBPAdapter::_GetPublisher()
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleNoOperationsInterfaceBPInterface::Execute__GetPublisher(Obj);
	}
	return nullptr;
}

bool UTbSimpleNoOperationsInterfaceBPAdapter::GetPropBool() const
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleNoOperationsInterfaceBPInterface::Execute_GetPropBool(Obj);
	}
	return false;
}
void UTbSimpleNoOperationsInterfaceBPAdapter::SetPropBool(bool bInPropBool)
{
	if (UObject* Obj = Target.GetObject())
	{
		ITbSimpleNoOperationsInterfaceBPInterface::Execute_SetPropBool(Obj, bInPropBool);
	}
}

int32 UTbSimpleNoOperationsInterfaceBPAdapter::GetPropInt() const
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbSimpleNoOperationsInterfaceBPInterface::Execute_GetPropInt(Obj);
	}
	return 0;
}
void UTbSimpleNoOperationsInterfaceBPAdapter::SetPropInt(int32 InPropInt)
{
	if (UObject* Obj = Target.GetObject())
	{
		ITbSimpleNoOperationsInterfaceBPInterface::Execute_SetPropInt(Obj, InPropInt);
	}
}
