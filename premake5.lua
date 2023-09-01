workspace "Entropy"
    architecture "x64"
    startproject "Sandbox"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Entropy"
    location "Entropy"
    kind "StaticLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "enpch.h"
    pchsource "Entropy/src/enpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
		"%{prj.name}/glad.c",
		"%{prj.name}/stb.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
		"%{SolutionDir}/Dependencies/GLFW/include",
		"%{SolutionDir}/Dependencies/glad",
		"%{SolutionDir}/Dependencies/glm",
		"%{SolutionDir}/Dependencies/stb"
    }

	libdirs
	{
		"%{SolutionDir}/Dependencies/GLFW/lib-vc2022"
	}

    links
    {
        "glfw3.lib",
        "opengl32.lib",
		"User32.lib",
		"Gdi32.lib",
		"Shell32.lib"
    }

	filter { "files:Entropy/glad.c" }
        flags { "NoPCH" }
	filter { "files:Entropy/stb.cpp" }
        flags { "NoPCH" }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "EN_PLATFORM_WINDOWS",
            "EN_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
        }
    
    filter "configurations:Debug"
        defines "EN_DEBUG"
        buildoptions "/MDd"
        symbols "On"
    
    filter "configurations:Release"
        defines "EN_RELEASE"
        buildoptions "/MD"
        optimize "On"
    
    filter "configurations:Dist"
        defines "EN_DIST"
        buildoptions "/MD"
        optimize "On"

project "Sandbox"
        location "Sandbox"
        kind "ConsoleApp"
        language "C++"

        targetdir ("bin/" .. outputdir .. "/%{prj.name}")
        objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

        files
        {
            "%{prj.name}/src/**.h",
            "%{prj.name}/src/**.cpp",
			"%{prj.name}/glad.c",
			"%{prj.name}/stb.cpp"
        }

        includedirs
        {
            "Entropy/src",
			"%{SolutionDir}/Dependencies/GLFW/include",
			"%{SolutionDir}/Dependencies/glad",
			"%{SolutionDir}/Dependencies/glm",
			"%{SolutionDir}/Dependencies/stb"
        }

		libdirs
		{
			"%{SolutionDir}/Dependencies/GLFW/lib-vc2022"
		}

        links
    	{
			"Entropy",
			"glfw3.lib",
			"opengl32.lib",
			"User32.lib",
			"Gdi32.lib",
			"Shell32.lib"
    	}

        filter "system:windows"
            cppdialect "C++20"
            staticruntime "On"
            systemversion "latest"

            defines
            {
                "EN_PLATFORM_WINDOWS"
            }
        
        filter "configurations:Debug"
        defines "EN_DEBUG"
        buildoptions "/MDd"
            symbols "On"
        
        filter "configurations:Release"
            defines "EN_RELEASE"
            buildoptions "/MD"
            optimize "On"
        
        filter "configurations:Dist"
            defines "EN_DIST"
            buildoptions "/MD"
            optimize "On"
