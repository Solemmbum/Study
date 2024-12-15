// Copyright (c) 2024 @ Solemmbum Games - @All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class StudyEditorTarget : TargetRules
{
	public StudyEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V4;

		ExtraModuleNames.AddRange( new string[] { "Study" } );
	}
}
