workspace "Ornn"
  architecture "x64"

  configurations
  {
    "Debug",
    "Release",
    "Dist"
  }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

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
		symbols "On"

	filter "configurations:Release"
		defines "ORNN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ORNN_DIST"
		optimize "On"

project "Ornn"
	location "Ornn"
	kind "SharedLib"
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
    "%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"ORNN_PLATFORM_WINDOWS",
			"ORNN_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "ORNN_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ORNN_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ORNN_DIST"
		optimize "On"