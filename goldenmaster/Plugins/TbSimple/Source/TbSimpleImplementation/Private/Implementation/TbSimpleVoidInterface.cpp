// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

#include "TbSimple/Implementation/TbSimpleVoidInterface.h"
#include "Misc/ScopeRWLock.h"

UTbSimpleVoidInterfaceImplementation::~UTbSimpleVoidInterfaceImplementation() = default;

void UTbSimpleVoidInterfaceImplementation::FuncVoid()
{
	TRACE_CPUPROFILER_EVENT_SCOPE_STR("ApiGear.TbSimple.VoidInterface.Impl.FuncVoid");
	// do business logic here
}
