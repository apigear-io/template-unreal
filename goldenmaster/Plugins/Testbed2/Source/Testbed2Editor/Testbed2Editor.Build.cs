namespace UnrealBuildTool.Rules
{
	public class Testbed2Editor : ModuleRules
	{
		public Testbed2Editor(ReadOnlyTargetRules Target) : base(Target)
		{
			PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
			#if UE_5_2_OR_LATER 
				IWYUSupport = IWYUSupport.Full;
			#else
				bEnforceIWYU = true;
			#endif
			
			PrivateDependencyModuleNames.AddRange(
				new string[] {
					"Core",
					"CoreUObject",
					"UnrealEd",
					// modules below are needed for connection settings
					"ApiGear",
					"ApiGearOLink",
					"InputCore",
					"PropertyEditor",
					"Slate",
					"SlateCore"
				});

			PrivateIncludePaths.AddRange(
				new string[] {
					"Testbed2Editor/Private",
				});		
				
			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"Testbed2"
				}
				);
			}
	}
}
