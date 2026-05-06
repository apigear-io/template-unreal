// SPDX-FileCopyrightText: Copyright ApiGear UG and Epic Games, Inc.
// SPDX-License-Identifier: MIT

using System.IO;
using UnrealBuildTool;

public class ApiGearMQTTPaho : ModuleRules
{
	public ApiGearMQTTPaho(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
#if UE_5_2_OR_LATER
		IWYUSupport = IWYUSupport.Full;
#else
		bEnforceIWYU = true;
#endif

		PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Public"));
		PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "Private"));

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"ApiGear",
				"ApiGearMQTT",
				"PahoMQTTLibrary"
			}
			);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine"
			}
			);
	}
}
