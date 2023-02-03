namespace UnrealBuildTool.Rules
{
	public class TbSame2Editor : ModuleRules
	{
		public TbSame2Editor(ReadOnlyTargetRules Target) : base(Target)
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
					"TbSame2Editor/Private",
				});		
				
			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"TbSame2"
				}
				);
			}
	}
}
