// Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class StudyTarget : TargetRules
{
	public StudyTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V4;

		ExtraModuleNames.AddRange( new string[] { "Study" } );
	}
}
