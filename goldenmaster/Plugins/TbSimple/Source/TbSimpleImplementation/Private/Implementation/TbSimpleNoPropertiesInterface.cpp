// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "TbSimple/Implementation/TbSimpleNoPropertiesInterface.h"
#include "Misc/ScopeRWLock.h"

UTbSimpleNoPropertiesInterfaceImplementation::~UTbSimpleNoPropertiesInterfaceImplementation() = default;

void UTbSimpleNoPropertiesInterfaceImplementation::FuncVoid()
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.NoPropertiesInterface.Impl.FuncVoid");
	// do business logic here
}

bool UTbSimpleNoPropertiesInterfaceImplementation::FuncBool(bool bParamBool)
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.NoPropertiesInterface.Impl.FuncBool");
	(void)bParamBool;
	// do business logic here
	return false;
}
