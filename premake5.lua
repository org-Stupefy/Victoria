include "./thirdparty/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

workspace "Victoria"
	architecture "x86_64"
	startproject "Victor"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "thirdparty/premake"
	include "Victoria/thirdparty/GLFW"
	include "Victoria/thirdparty/Glad"
	include "Victoria/thirdparty/imgui"
	include "Victoria/thirdparty/yaml-cpp"
	--include "Victoria/thirdparty/assimp"
group ""

include "Victoria"
include "Sandbox"
include "Victor"
-- Game Projects
-- include "MineTime"
-- include "BoostRocket"