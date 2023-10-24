workspace "Ornn"
  architecture "x64"

  configurations
  {
    "Debug",
    "Release",
    "Dist"
  }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Ornn/vendor/GLFW/include"
IncludeDir["Glad"] = "Ornn/vendor/Glad/include"
IncludeDir["ImGui"] = "Ornn/vendor/imgui"

include "Ornn/vendor/GLFW" --copy the premake5.lua in GLFW/ to here
include "Ornn/vendor/Glad"
include "Ornn/vendor/imgui"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Ornn/vendor/spdlog/include",
		"Ornn/src"
	}

	links
	{
		"Ornn"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ORNN_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "ORNN_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "ORNN_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "ORNN_DIST"
		buildoptions "/MD"
		optimize "On"

project "Ornn"
	location "Ornn"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "pch.h"
	pchsource "Ornn/src/pch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
    "%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ORNN_PLATFORM_WINDOWS",
			"ORNN_BUILD_DLL",
			"GLFW_INCLUDE_NONE",

			"ORNN_ENABLE_ASSERTS"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "ORNN_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "ORNN_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "ORNN_DIST"
		buildoptions "/MD"
		optimize "On"