workspace "Ornn"
  architecture "x64"
	startproject "Sandbox"

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
IncludeDir["glm"] = "Ornn/vendor/glm"

include "Ornn/vendor/GLFW" --copy the premake5.lua in GLFW/ to here
include "Ornn/vendor/Glad"
include "Ornn/vendor/imgui"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

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
		"Ornn/src",
		"Ornn/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Ornn"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines
		{
			"ORNN_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "ORNN_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "ORNN_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "ORNN_DIST"
		runtime "Release"
		optimize "On"

project "Ornn"
	location "Ornn"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "pch.h"
	pchsource "Ornn/src/pch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl",
	}

	includedirs
	{
    "%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
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
		systemversion "latest"

		defines
		{
			"ORNN_PLATFORM_WINDOWS",
			"ORNN_BUILD_DLL",
			"GLFW_INCLUDE_NONE",
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "ORNN_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "ORNN_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "ORNN_DIST"
		runtime "Release"
		optimize "On"