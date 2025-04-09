// Fill out your copyright notice in the Description page of Project Settings.

using System.IO;
using UnrealBuildTool;

public class ApiGearOLink : ModuleRules
{
	public ApiGearOLink(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		#if UE_5_2_OR_LATER 
			IWYUSupport = IWYUSupport.Full;
		#else
			bEnforceIWYU = true;
		#endif

		// Disable nlohmann::json exception handling
		PublicDefinitions.Add("JSON_NOEXCEPTION=1");
		PublicDefinitions.Add("OLINK_EXPORT=DLLIMPORT");

		PublicIncludePaths.Add(Path.Combine(ModuleDirectory, "Public"));
		PrivateIncludePaths.Add(Path.Combine(ModuleDirectory, "Private"));

		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
				"WebSockets",
				"OLinkProtocolLibrary",
				"nlohmannJsonLibrary",
				"ApiGear"
			}
			);

		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine"
			}
			);

		// the WebSocketNetworking lib does not work on mobile
		// QNX is only defined in certain UE versions so we use this workaround
		if (Target.Platform != UnrealTargetPlatform.Android && Target.Platform != UnrealTargetPlatform.IOS && !Target.Platform.ToString().Equals("QNX", System.StringComparison.Ordinal))
		{
			PrivateDependencyModuleNames.Add("WebSocketNetworking");
		}

		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{
				// ... add any modules that your module loads dynamically here ...
			}
			);
	}
}

