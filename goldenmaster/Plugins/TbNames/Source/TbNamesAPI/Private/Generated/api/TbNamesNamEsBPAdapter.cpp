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
#include "TbNames/Generated/api/TbNamesNamEsBPAdapter.h"
#include "TbNamesNamEsLatentAction.h"
#include "Async/Async.h"
#include "Engine/Engine.h"

void UTbNamesNamEsBPAdapter::Initialize(TScriptInterface<ITbNamesNamEsBPInterface> InTarget)
{
	Target = InTarget;
}

UTbNamesNamEsPublisher* UTbNamesNamEsBPAdapter::_GetPublisher()
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbNamesNamEsBPInterface::Execute__GetPublisher(Obj);
	}
	return nullptr;
}

void UTbNamesNamEsBPAdapter::SomeFunction(bool bSomeParam)
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbNamesNamEsBPInterface::Execute_SomeFunction(Obj, bSomeParam);
	}
}

void UTbNamesNamEsBPAdapter::SomeFunction2(bool bSomeParam)
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbNamesNamEsBPInterface::Execute_SomeFunction2(Obj, bSomeParam);
	}
}

bool UTbNamesNamEsBPAdapter::GetSwitch() const
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbNamesNamEsBPInterface::Execute_GetSwitch(Obj);
	}
	return false;
}
void UTbNamesNamEsBPAdapter::SetSwitch(bool bInSwitch)
{
	if (UObject* Obj = Target.GetObject())
	{
		ITbNamesNamEsBPInterface::Execute_SetSwitch(Obj, bInSwitch);
	}
}

int32 UTbNamesNamEsBPAdapter::GetSomeProperty() const
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbNamesNamEsBPInterface::Execute_GetSomeProperty(Obj);
	}
	return 0;
}
void UTbNamesNamEsBPAdapter::SetSomeProperty(int32 InSomeProperty)
{
	if (UObject* Obj = Target.GetObject())
	{
		ITbNamesNamEsBPInterface::Execute_SetSomeProperty(Obj, InSomeProperty);
	}
}

int32 UTbNamesNamEsBPAdapter::GetSomePoperty2() const
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbNamesNamEsBPInterface::Execute_GetSomePoperty2(Obj);
	}
	return 0;
}
void UTbNamesNamEsBPAdapter::SetSomePoperty2(int32 InSomePoperty2)
{
	if (UObject* Obj = Target.GetObject())
	{
		ITbNamesNamEsBPInterface::Execute_SetSomePoperty2(Obj, InSomePoperty2);
	}
}

ETbNamesEnum_With_Under_scores UTbNamesNamEsBPAdapter::GetEnumProperty() const
{
	if (UObject* Obj = Target.GetObject())
	{
		return ITbNamesNamEsBPInterface::Execute_GetEnumProperty(Obj);
	}
	return ETbNamesEnum_With_Under_scores::TNEWUS_FirstValue;
}
void UTbNamesNamEsBPAdapter::SetEnumProperty(ETbNamesEnum_With_Under_scores InEnumProperty)
{
	if (UObject* Obj = Target.GetObject())
	{
		ITbNamesNamEsBPInterface::Execute_SetEnumProperty(Obj, InEnumProperty);
	}
}
