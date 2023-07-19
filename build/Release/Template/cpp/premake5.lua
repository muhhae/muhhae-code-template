-- premake5.lua
-- generated by muhhae

workspace "CPPTemplate"
    configurations { "Debug", "Release" }

SRCDIR = "src" --Source Code Directory
BUILDDIR = "bin" --Build Directory
OBJDIR = "obj" --Obj Directory
RESFILE = "resource" --Resource Directory


project "App"
    kind "ConsoleApp" --App Type
    language "C++" --Languange

    cppdialect "C++latest"
    link {} --link library

    targetdir "%{BUILDDIR}/%{cfg.buildcfg}" 
    objdir "%{OBJDIR}/%{cfg.buildcfg}"

    files {
        "%{SRCDIR}/**.h",
        "%{SRCDIR}/**.hpp", 
        "%{SRCDIR}/**.cpp",

        "%include/**.cpp",
        "%include/**.hpp",
        "%include/**.h"
    }

    prebuildcommands { 
        "rm -rf %{BUILDDIR}/%{cfg.buildcfg}/resource",
        "{COPYDIR} %{RESFILE} %{BUILDDIR}/%{cfg.buildcfg}/resource" 
    }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "RELEASE" }
        optimize "On"