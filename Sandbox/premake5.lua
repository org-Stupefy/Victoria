project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Victoria/thirdparty/spdlog/include",
		"%{wks.location}/Victoria/src",
		"%{wks.location}/Victoria/thirdparty",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}"
	}

	links
	{
		"Victoria"
	}

	filter "system:windows"
		systemversion "latest"

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
