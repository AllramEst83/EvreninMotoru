workspace "EvreninMotoru"
architecture "x64"

configurations {
	"Debug",
	"Release",
	"Dist"
}

outputDir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "EvreninMotoru"
	location "EvreninMotoru"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs {
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22000.0"
		
	defines {
		"EM_PLATFORM_WINDOWS",
		"EM_BUILD_DLL"
	}

	postbuildcommands {
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputDir .. "/Sandbox")
	}

	filter "configurations:Debug"
		defines "EM_Debug"
		symbols "On"

	filter "configurations:Release"
		defines "EM_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "EM_DIST"
		optimize "On"


project "Sandbox" 
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputDir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputDir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs {
		"EvreninMotoru/vendor/spdlog/include",
		"EvreninMotoru/src"
	}

	defines {
		"EM_PLATFORM_WINDOWS"
	}

	links {
		"EvreninMotoru"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22000.0"

	filter "configurations:Debug"
		defines "EM_Debug"
		symbols "On"

	filter "configurations:Release"
		defines "EM_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "EM_DIST"
		optimize "On"
