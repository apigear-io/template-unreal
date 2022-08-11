namespace UnrealBuildTool.Rules
{
	public class Testbed1Editor : ModuleRules
	{
		public Testbed1Editor(ReadOnlyTargetRules Target) : base(Target)
		{
			PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
			bEnforceIWYU = true;
			
			PrivateDependencyModuleNames.AddRange(
				new string[] {
					"Core",
					"CoreUObject",
					"UnrealEd",
				});

			PrivateIncludePaths.AddRange(
				new string[] {
					"Testbed1Editor/Private",
				});		
				
			PrivateDependencyModuleNames.AddRange(
				new string[]
				{
					"Testbed1"
				}
				);
			}
	}
}
