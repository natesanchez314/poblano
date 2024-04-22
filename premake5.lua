workspace "Poblano"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Poblano"
    location "Poblano"
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
            "PB_PLATFORM_WINDOWS",
            "PB_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "PB_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "PB_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "PB_DIST"
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
        "%{prj.name}/src/**.cpp"
    }

    includedirs 
    {
        "Poblano/vendor/spdlog/include",
        "Poblano/src"
    }

    links
    {
        "Poblano"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "PB_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "PB_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "PB_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "PB_DIST"
        optimize "On"