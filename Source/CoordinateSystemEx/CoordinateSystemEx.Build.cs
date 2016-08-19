using UnrealBuildTool;

public class CoordinateSystemEx : ModuleRules
{
	public CoordinateSystemEx(TargetInfo Target)
	{
		PublicIncludePaths.AddRange(new string[] {
				"Public"
			});


		PrivateIncludePaths.AddRange(new string[] {
				"Private",
			});


		PublicDependencyModuleNames.AddRange(new string[] {
				"Core",
//				"CoreUObject",
//				"Engine"
			});


		DynamicallyLoadedModuleNames.AddRange(new string[]{});
	}
}
