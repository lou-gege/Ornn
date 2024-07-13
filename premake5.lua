workspace "Ornn"
  architecture "x64"
	startproject "Ornn-Editor"

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
IncludeDir["stb_image"] = "Ornn/vendor/stb_image"
IncludeDir["entt"] = "Ornn/vendor/entt/include"

include "Ornn/vendor/GLFW" --copy the premake5.lua in GLFW/ to here
include "Ornn/vendor/Glad"
include "Ornn/vendor/imgui"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

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
		systemversion "latest"

		defines
		{
			"ORNN_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "ORNN_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "ORNN_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "ORNN_DIST"
		runtime "Release"
		optimize "on"

project "Ornn"
	location "Ornn"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "pch.h"
	pchsource "Ornn/src/pch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/stb_image/**.h",
		"%{prj.name}/vendor/stb_image/**.cpp",
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
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.entt}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"ORNN_PLATFORM_WINDOWS",
			"ORNN_BUILD_DLL",
			"GLFW_INCLUDE_NONE",
			"_CRT_SECURE_NO_WARNINGS"
		}

	filter "configurations:Debug"
		defines "ORNN_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "ORNN_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "ORNN_DIST"
		runtime "Release"
		optimize "on"

project "Ornn-Editor"
	location "Ornn-Editor"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

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
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}"
	}

	links
	{
		"Ornn"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"ORNN_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "ORNN_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "ORNN_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "ORNN_DIST"
		runtime "Release"
		optimize "on"