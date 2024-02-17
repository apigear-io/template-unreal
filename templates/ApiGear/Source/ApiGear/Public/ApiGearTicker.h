// Copyright Epic Games, Inc. All Rights Reserved

#pragma once
#include "Runtime/Launch/Resources/Version.h"
#include "Containers/Ticker.h"

/** This is a a helper file to provide version independent ticker functionality */
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
	static FTicker& ApiGearTicker::GetCoreTicker()
	{
		return GetCoreTicker();
	}
#endif
};
