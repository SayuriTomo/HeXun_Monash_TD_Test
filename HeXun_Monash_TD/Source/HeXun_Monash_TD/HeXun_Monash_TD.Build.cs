// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class HeXun_Monash_TD : ModuleRules
{
	public HeXun_Monash_TD(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}
