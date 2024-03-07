// Copyright Epic Games, Inc. All Rights Reserved

#pragma once
#include "Runtime/Launch/Resources/Version.h"
#include "Containers/Ticker.h"

namespace ApiGear
{
#if (ENGINE_MAJOR_VERSION >= 5)
using FDelegateHandle = FTSTicker::FDelegateHandle;
#else
using FDelegateHandle = ::FDelegateHandle;
#endif
} // namespace ApiGear

class ApiGearTicker
{
public:
#if (ENGINE_MAJOR_VERSION >= 5)
	static FTSTicker& GetCoreTicker()
	{
		return FTSTicker::GetCoreTicker();
	}
#else
	static FTicker& GetCoreTicker()
	{
		return FTicker::GetCoreTicker();
	}
#endif
};
