namespace UnrealBuildTool.Rules
{
	public class TbSame1Editor : ModuleRules
	{
		public TbSame1Editor(ReadOnlyTargetRules Target) : base(Target)
		{
			PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
			bEnforceIWYU = true;
			
			PrivateDependencyModuleNames.AddRange(
				new string[] {
					"Core",
					"CoreUObject",
					"UnrealEd",
					// modules below are needed for connection settings
					"ApiGear",
					"InputCore",
					"PropertyEditor",
					"Slate",
					"SlateCore"
				});

			PrivateIncludePaths.AddRange(
				new string[] {
					"TbSame1Editor/Private",
				});		
				
			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"TbSame1"
				}
				);
			}
	}
}
