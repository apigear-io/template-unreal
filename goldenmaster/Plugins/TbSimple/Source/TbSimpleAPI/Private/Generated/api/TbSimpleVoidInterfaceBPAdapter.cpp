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
#include "TbSimple/Generated/api/TbSimpleVoidInterfaceBPAdapter.h"
#include "TbSimpleVoidInterfaceLatentAction.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

void UTbSimpleVoidInterfaceBPAdapter::Initialize(TScriptInterface<ITbSimpleVoidInterfaceBPInterface> InTarget)
{
	Target = InTarget;
}

UTbSimpleVoidInterfacePublisher* UTbSimpleVoidInterfaceBPAdapter::_GetPublisher()
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbSimpleVoidInterfaceBPInterface::Execute__GetPublisher(Obj);
	}
	return nullptr;
}

void UTbSimpleVoidInterfaceBPAdapter::FuncVoid()
{
	UObject* Obj = Target.GetObject();
	if (IsValid(Obj))
	{
		return ITbSimpleVoidInterfaceBPInterface::Execute_FuncVoid(Obj);
	}
}
