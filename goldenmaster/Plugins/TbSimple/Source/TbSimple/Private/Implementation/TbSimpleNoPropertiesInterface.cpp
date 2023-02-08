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

#include "Implementation/TbSimpleNoPropertiesInterface.h"

UTbSimpleNoPropertiesInterface::~UTbSimpleNoPropertiesInterface() = default;

void UTbSimpleNoPropertiesInterface::BroadcastSigVoid_Implementation()
{
	SigVoidSignal.Broadcast();
}

FTbSimpleNoPropertiesInterfaceSigVoidDelegate& UTbSimpleNoPropertiesInterface::GetSigVoidSignalDelegate()
{
	return SigVoidSignal;
}

void UTbSimpleNoPropertiesInterface::BroadcastSigBool_Implementation(bool bParamBool)
{
	SigBoolSignal.Broadcast(bParamBool);
}

FTbSimpleNoPropertiesInterfaceSigBoolDelegate& UTbSimpleNoPropertiesInterface::GetSigBoolSignalDelegate()
{
	return SigBoolSignal;
}

void UTbSimpleNoPropertiesInterface::FuncVoid_Implementation()
{
	// do business logic here
}

bool UTbSimpleNoPropertiesInterface::FuncBool_Implementation(bool bParamBool)
{
	(void)bParamBool;
	// do business logic here
	return false;
}
