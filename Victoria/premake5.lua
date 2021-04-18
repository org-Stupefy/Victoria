project "Victoria"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "vcpch.h"
	pchsource "src/vcpch.cpp"

	files
	{
		"src/**.h",
		"src/**.cpp",
		"thirdparty/stb_image/**.h",
		"thirdparty/stb_image/**.cpp",
		"thirdparty/glm/glm/**.hpp",
		"thirdparty/glm/glm/**.inl",
		"thirdparty/assimp/include/**.h",
		"thirdparty/assimp/include/**.cpp",

		"thirdparty/ImGuizmo/ImGuizmo.h",
		"thirdparty/ImGuizmo/ImGuizmo.cpp"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"GLFW_INCLUDE_NONE"
	}

	includedirs
	{
		"src",
		"thirdparty/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.entt}",
		"%{IncludeDir.yaml_cpp}",
		"%{IncludeDir.ImGuizmo}",
		"%{IncludeDir.assimp}",
		--"$(VULKAN_SDK)/include"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"yaml-cpp",
		"opengl32.lib",
		-- "assimp",
		"../Victoria/thirdparty/assimp/lib/assimp-vc142-mt.lib",
		--"$(VULKAN_SDK)/lib/vulkan-1.lib"
	}

	filter {}
		files {	"thirdparty/ImGuizmo/**.cpp",
				-- "thirdparty/assimp/include/**.cpp"
			}	
		flags { "NoPCH" }

	filter "system:windows"
		systemversion "latest"

		defines
		{
		}

	filter "configurations:Debug"
		defines "VC_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "VC_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "VC_DIST"
		runtime "Release"
		optimize "on"
