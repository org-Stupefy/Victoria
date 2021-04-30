include "./thirdparty/premake/premake_customization/solution_items.lua"

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

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "%{wks.location}/Victoria/thirdparty/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Victoria/thirdparty/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Victoria/thirdparty/imgui"
IncludeDir["glm"] = "%{wks.location}/Victoria/thirdparty/glm"
IncludeDir["stb_image"] = "%{wks.location}/Victoria/thirdparty/stb_image"
IncludeDir["entt"] = "%{wks.location}/Victoria/thirdparty/entt/include"
IncludeDir["yaml_cpp"] = "%{wks.location}/Victoria/thirdparty/yaml-cpp/include"
IncludeDir["ImGuizmo"] = "%{wks.location}/Victoria/thirdparty/ImGuizmo"
IncludeDir["assimp"] = "%{wks.location}/Victoria/thirdparty/assimp/include"

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
-- include "MineTime"
-- include "BoostRocket"