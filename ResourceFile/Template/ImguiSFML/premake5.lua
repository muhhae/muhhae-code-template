-- premake5.lua
-- generated by muhhae

workspace "ImguiApp"
    configurations { "Debug", "Release" }

SRCDIR = "src" --Source Code Directory
BUILDDIR = "build" --Build Directory
OBJDIR = "%{BUILDDIR}/obj" --Obj Directory
RESFILE = "resource" --Resource Directory


project "ImguiApp"
    language "C++" 
    cppdialect "C++latest"

    links {
        "opengl32","sfml-audio", "sfml-graphics", "sfml-network", "sfml-system", "sfml-window"
    }

    targetdir "%{BUILDDIR}/%{cfg.buildcfg}" 
    objdir "%{OBJDIR}/%{cfg.buildcfg}"

    includedirs {
        "include/**"
    }

    files {
        "%{SRCDIR}/**.h",
        "%{SRCDIR}/**.hpp", 
        "%{SRCDIR}/**.cpp",
        "include/**.cpp",
        "include/**.h"
    }

    prebuildcommands { 
        "rm -rf %{BUILDDIR}/%{cfg.buildcfg}/",
        "{COPYDIR} %{RESFILE} %{BUILDDIR}/%{cfg.buildcfg}" 
    }

    filter "configurations:Debug"
        kind "ConsoleApp"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        kind "WindowedApp"
        defines { "RELEASE" }
        optimize "On"